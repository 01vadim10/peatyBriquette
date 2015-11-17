/********************************************************************
 * COPYRIGHT -- judenkov
 ********************************************************************
 * Program: Alarm_Reg
 * File: Alarm_Reg.c
 * Author: yudenkov
 * Created: April 26, 2013
 ********************************************************************
 * Implementation of program Alarm_Reg
 ********************************************************************/

#include <bur/plctypes.h>
#include <bur/plc.h>
#include "alarmFunc.h"
#include "alarmMsg.h"
#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT Alarm_RegINIT(void)
{
	alarmBunkerMaxLevel = 0;
	lockRunSet = 3000;
	timerAlarm = 0;
	alarm = 0;
	counter = 0;
}

/*≈сли сработала хоть одна блокировка возвращает - 1, если ни одна из блокировок не сработала возвращает - 0*/
BOOL checkAutoCrushingAlarm(void)
{
	BOOL autoAlarm;
	autoAlarm = 0;
	
	(protElmotElev && protRelCrushOn) ? (alarmElevator = 0) : (alarmElevator = 1);
	(FC_ready_5 && FC_ready_0 && protRelCrushOn) ? (alarmShaftOut = 0) : (alarmShaftOut = 1);
	(protElmotCrushShaftIn && FC_ready_1 && protRelCrushOn) ? (alarmShaftIn = 0) : (alarmShaftIn = 1);
	(protElmotConv && tempProtElmotBeltNorm && protRelCrushOn && irSeparOn && powerIrSeparOn) ? (alarmConveyor = 0) : (alarmConveyor = 1);
	(protElmotShaftFeeder && shaftFeederTempNorm && protRelFeederOn && protRelCrushOn /*&& convForward*/) ? (alarmShaftFeeder = 0) : (alarmShaftFeeder = 1);
	(protElmotBeltFeeder && protTempBeltFeeder && FC_ready_2 && protRelFeederOn && protRelCrushOn/* && beltFeederCoolerOn && shaftFeederElmotOn*/) ? (alarmBeltFeeder = 0) : (alarmBeltFeeder = 1);
	(!alarmElevator && !alarmShaftOut && !alarmShaftIn && !alarmConveyor && !alarmShaftFeeder && !alarmBeltFeeder) ? (autoAlarm = 0) : (autoAlarm = 1);
	
	return autoAlarm;
}

/*≈сли сработала хоть одна блокировка возвращает - 1, если ни одна из блокировок не сработала возвращает - 0*/
BOOL checkAutoMillingAlarm(void)
{
	BOOL autoAlarm;
	autoAlarm = 0;
	
	(FC_ready_4 && powerElcabinetPumpPneumOn && protRelPomolOn) ? (alarmPumpPneum = 0) : (alarmPumpPneum = 1);
	(FC_ready_5 && powerConvMelnOn && tempElmotorMelnNorm && protRelPomolOn) ? (alarmMill = 0) : (alarmMill = 1);
	(protElmotorShluzFeeder && tempProtShluzFeeder && protRelPomolOn) ? (alarmGatewayFeeder = 0) : (alarmGatewayFeeder = 1);
	(powerElmotorDozatorOn && dozatorNeispr && protRelPomolOn) ? (alarmDozator = 0) : (alarmDozator = 1);
	(protElmotorRyhlitel && tempProtRyhlitel && protRelPomolOn) ? (alarmRipper = 0) : (alarmRipper = 1);
	(!alarmPumpPneum && !alarmMill && !alarmGatewayFeeder && !alarmDozator && !alarmRipper) ? (autoAlarm = 0) : (autoAlarm = 1);
	
	return autoAlarm;
}

void _CYCLIC Alarm_RegCYCLIC(void)
{
	if (autoCrushing && (!lineMode[CRUSHING_AREA] || (lineMode[CRUSHING_AREA] == MAN_MODE))){
		if (!checkAutoCrushingAlarm())
			lineMode[CRUSHING_AREA] = AUTO_MODE;
	} else if ((lineMode[CRUSHING_AREA] == AUTO_MODE) && checkAutoCrushingAlarm()){
		autoCrushing = 0;
		orderManStart[0] = 0;
	}
	if (bunkerMaxLevel)
		alarmBunkerMaxLevel = 0;
	if (!alarmBunkerMaxLevel){
		if (!bunkerMaxLevel && (lineMode[CRUSHING_AREA] != ADJ_MODE) && (lineMode[CRUSHING_AREA] != OFF_MODE)){
			if (timerMaxLevelBunkerRun(timerBunkerMaxLevel * 1000)){
				alarmBunkerMaxLevel = 1;
				Alarmstatus[23] = 1;
			} else alarmBunkerMaxLevel = 0;
			if (!countDosingStart)
				countDosingStart = dozator_Z1;
		} else maxLevelBunkerTON.Q = 1;
	}
	if (countDosingStart)
		countDosingMat = dozator_Z1 - countDosingStart;
	if (countDosingMat == countDosingUnload){
		countDosingStart = 0;
		countDosingMat = 0;
		colorDosing = 1;
	} else colorDosing = 0;
	if (T_bunkdrobTF > alarmCaseMill){
		(timerTempMaxBunkerRun(timerTempBunker * 1000)) ? (alarmTempCaseBunker = 0) : (alarmTempCaseBunker = 1);
		Alarmstatus[86] = 1;
	} else {
		alarmTempCaseBunker = 0;
		tempMaxBunkerTON.Q = 1;
	}
	if ((letdownPipelineSystemcontr_ < alarmUPrAspiration) && (lineMode[CRUSHING_AREA] != ADJ_MODE)){
		(timerMinCoolerDustPeatyRun(timerUPrAspiration * 1000)) ? (alarmCoolerDustPeaty = 0) : (alarmCoolerDustPeaty = 1);
		Alarmstatus[90] = 1;
	} else {
		alarmCoolerDustPeaty = 0;
		minCoolerDustPeatyTON.Q = 1;
	}
	
	if (lineMode[CRUSHING_AREA]){
		if (elmotorM4.run){
			alarmElevator = alarmCheck(protElmotElev, protRelCrushOn,1,1,1,1,1,1,1,1,1,eqStopAdjustmModeCrush,3,3,7,
				CRUSHING_AREA);
			Alarmstatus[34] = !protElmotElev;
			if (!alarmElevator)
				alarmElevator = alarmTempCaseBunker;
			if (!alarmElevator)
				alarmElevator = alarmCoolerDustPeaty;
		} else{
			maxLevelBunkerTON.Q = 1;
			highLevelBunkerTON.Q = 1;
			beltDownTON.Q = 1;
			speedElevatorTON.Q = 1;
			minCoolerDustPeatyTON.Q = 1;
			maxLevelBunkerTON.Q = 1;
		}
		if (elmotorM2.run || elmotorM2.reverse){
			alarmShaftOut = alarmCheck(protElmotCrushShaftOut, FC_ready_0, protRelCrushOn, 1,1,1,
				elevOn,1,1,1,1,eqStopAdjustmModeCrush,3,8,8, CRUSHING_AREA);
			Alarmstatus[32] = !protElmotCrushShaftOut;
			Alarmstatus[45] = !FC_ready_0;
		} else{
			shaftOutTON.Q = 1;
		}
		if (elmotorM3.run || elmotorM3.reverse){
			alarmShaftIn = alarmCheck(protElmotCrushShaftIn, FC_ready_1, protRelCrushOn, 1,1,1,
				elevOn,1,1,1,1, eqStopAdjustmModeCrush,3,9,9, CRUSHING_AREA);
			Alarmstatus[33] = !protElmotCrushShaftIn;
			Alarmstatus[47] = !FC_ready_1;
		} else{
			shaftInTON.Q = 1;
		}
		if (elmotorM1.run){
			alarmConveyor = alarmCheck(protElmotConv, tempProtElmotBeltNorm, protRelCrushOn,1,1,1,
				FC_start_0, FC_start_1, irSeparOn, powerIrSeparOn,1,eqStopAdjustmModeCrush,3,10,10, CRUSHING_AREA);
			if (lineMode[CRUSHING_AREA] != ADJ_MODE){
				Alarmstatus[25] = !irSeparOn;
				Alarmstatus[37] = !powerIrSeparOn;
			}
			Alarmstatus[31] = !protElmotConv;
			Alarmstatus[17] = !tempProtElmotBeltNorm;
		} else speedConvTON.Q = 1;
		if (elmotorM9.run){
			alarmShaftFeeder = alarmCheck(protElmotShaftFeeder, shaftFeederTempNorm, protRelFeederOn, protRelCrushOn,1,1,
				convForward,1,1,1,1, eqStopAdjustmModeCrush,3,0,0, CRUSHING_AREA);
			Alarmstatus[35] = !protElmotShaftFeeder;
			Alarmstatus[27] = !shaftFeederTempNorm;
		}
		if (elmotorM10.run){
			alarmBeltFeeder = alarmCheck(protElmotBeltFeeder, protTempBeltFeeder, FC_ready_2, protRelFeederOn, protRelCrushOn, 1,
				shaftFeederElmotOn,1,1,1,1, eqStopAdjustmModeCrush,3,11,11, CRUSHING_AREA);
			Alarmstatus[36] = !protElmotBeltFeeder;
			Alarmstatus[28] = !protTempBeltFeeder;
			Alarmstatus[43] = !FC_ready_2;
		} else{
			beltFeederTON.Q = 1;
		}
	}
	/*ѕылеудаление(аспираци€)*/
	if (elmotorM13.run){
		alarmAspiration = alarmCheck(FC_ready_3, coolerPyleudalElcabinetOn, protMainRelOnSystemcontr,1,1,1,1,1,1,1,1,1,2,1,1,
			MILLING_AREA);
		Alarmstatus[78] = !FC_ready_3;
		Alarmstatus[79] = !coolerPyleudalElcabinetOn;
		Alarmstatus[83] = !protMainRelOnSystemcontr;
	} else{
		coolerDustPeatyTON.Q = 1;
	}
	/*”часток помола.*/
	if (autoMilling && (!lineMode[MILLING_AREA] || (lineMode[MILLING_AREA] == MAN_MODE))){		
		if (!checkAutoMillingAlarm())
			lineMode[MILLING_AREA] = AUTO_MODE;
	} else if ((lineMode[MILLING_AREA] == AUTO_MODE) && checkAutoMillingAlarm()){
		autoMilling = 0;
		orderManStart[0] = 0;
	}
	if (valve1ExplControl && valve2ExplControl && valve3ExplControl && valve4ExplControl){
		alarmValveExpl = 0;
		valveExplTON.Q = 1;
	}
	if (!alarmValveExpl && (lineMode[MILLING_AREA] != ADJ_MODE) && (lineMode[MILLING_AREA] != OFF_MODE)){
		if (!valve1ExplControl || !valve2ExplControl || !valve3ExplControl || !valve4ExplControl){
			(timerValveExplRun(timerValveExpl * 1000)) ? (alarmValveExpl = 1) : (alarmValveExpl = 0);
			Alarmstatus[61] = !valve1ExplControl;
			Alarmstatus[62] = !valve2ExplControl;
			Alarmstatus[63] = !valve3ExplControl;
			Alarmstatus[64] = !valve4ExplControl;
		}
	}
	if ((P_pnevmoTRANS1 < alarmMinPump) && (lineMode[MILLING_AREA] != ADJ_MODE)){
		(timerMinPumpPneumRun(timerPrAirInjector * 1000)) ? (alarmPumpPneumMin = 0) : (alarmPumpPneumMin = 1);
		Alarmstatus[88] = 1;
	}
	if ((P_pnevmoTRANS1 > alarmMaxPump) && (lineMode[MILLING_AREA] != ADJ_MODE)){
		(timerMaxPumpPneumRun(timerPrAirInjector * 1000)) ? (alarmPumpPneumMax = 0) : (alarmPumpPneumMax = 1);
		Alarmstatus[89] = 1;
	}
	if (lineMode[MILLING_AREA]){
		if (!Permission_Stove2)
			valveY5 = 0;
		if (elmotorM16.run){
			alarmPumpPneum = alarmCheck(FC_ready_4, powerElcabinetPumpPneumOn, protRelPomolOn, 1,1,1,
				valveY5,1,1,1,1, localPostPomolStop,3,12,12, MILLING_AREA);
			Alarmstatus[58] = !powerElcabinetPumpPneumOn;
			Alarmstatus[66] = !FC_ready_4;
			if (!alarmPumpPneum)
				alarmPumpPneum = alarmPumpPneumMin;
			if (!alarmPumpPneum)
				alarmPumpPneum = alarmPumpPneumMax;
		} else{
			pumpPneumTON.Q = 1;
		}
		if (elmotorM5.run){
			alarmMill = alarmCheck(FC_ready_5, powerConvMelnOn, tempElmotorMelnNorm, protRelPomolOn,1,1,
				1, 1, 1, 1, 1, localPostPomolStop,3,14,15, MILLING_AREA);
			if (!alarmMill)
				alarmMill = alarmTempCaseBunker;
			if (!alarmMill)
				alarmMill = alarmCoolerDustPeaty;
			Alarmstatus[68] = !FC_ready_5;
			Alarmstatus[54] = !powerConvMelnOn;
			Alarmstatus[48] = !tempElmotorMelnNorm;
		} else{
			millTON.Q = 1;
		}
		if (elmotorM12.run){
			alarmGatewayFeeder = alarmCheck(protElmotorShluzFeeder, tempProtShluzFeeder, protRelPomolOn,1,1,1,
				FC_run_5, FC_run_4,1,1,1, localPostPomolStop,3,0,0, MILLING_AREA);
			Alarmstatus[51] = !protElmotorShluzFeeder;
			Alarmstatus[52] = !tempProtShluzFeeder;
		}
		if (elmotorM11.run){
			alarmDozator = alarmCheck(powerElmotorDozatorOn, dozatorNeispr, protRelPomolOn,1,1,1,
				Feeder_mot_On,1,1,1,1, localPostPomolStop,3,15,15, MILLING_AREA);
			if (!alarmDozator)
				alarmDozator = alarmTempCaseBunker;
			Alarmstatus[53] = !powerElmotorDozatorOn;
			Alarmstatus[49] = !dozatorNeispr;
		}
		if (elmotorM7.run){
			alarmRipper = alarmCheck(protElmotorRyhlitel, tempProtRyhlitel, protRelPomolOn,1,1,1,
				objOn[11],1,1,1,1, localPostPomolStop,3,15,15, MILLING_AREA);
			if (!alarmRipper)
				alarmRipper = alarmTempCaseBunker;
			Alarmstatus[50] = !protElmotorRyhlitel;
			Alarmstatus[57] = !tempProtRyhlitel;
		
		}
	}
	if (!power220OnSystemcontr){
		valveY1 = 0;
		valveY2 = 0;
		valveY3 = 0;
		valveY4 = 0;
		valveY6 = 0;
	}
	alarmMsg();
}
