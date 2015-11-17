
/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: Alarm_Reg
 * File: alarmFunc.h
 * Author: str
 * Created: December 05, 2013
 *******************************************************************/

#include <bur/plctypes.h>
#include <bur/plc.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

#include "alarmTimer.h"

BOOL checkTimerAlarm(WORD begin, WORD end, const BYTE AREA)
{
//	BOOL timerAlarm;
	timerAlarm = 0;
	while (begin <= end){
		if (!timerAlarm){
			switch (begin)
			{
				case 1:
					if (timerCoolerDustPeatyRun(timerUPrAspiration * 1000) && (alarmTimerStart[8] == 1)){
						(!FC_run_3) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[77] = !FC_run_3;
						alarmTimerStart[8] = 2;
					} else if (alarmTimerStart[8] == 2){
						(!FC_run_3) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[77] = !FC_run_3;
					}
					break;
				case 2:
//					if (bunkerMaxLevel && (lineMode[AREA] != ADJ_MODE)){
//						(timerMaxLevelBunkerRun(timerTempBunker * 1000)) ? (timerAlarm = 0) : (timerAlarm = 1);
//						Alarmstatus[23] = !bunkerMaxLevel;
//					}
					break;
				case 3:
					if (bunkerHighLevel && (lineMode[AREA] != ADJ_MODE))
						(timerHighLevelBunkerRun(timerBunkerMidLevel * 1000)) ? (timerAlarm = 0) : (timerAlarm = 1);
					break;
				case 4:
//					if ((letdownPipelineSystemcontr_ < alarmUPrAspiration) && (lineMode[CRUSHING_AREA] != ADJ_MODE))
//						(timerMinCoolerDustPeatyRun(timerTempBunker * 1000)) ? (timerAlarm = 0) : (timerAlarm = 1);
					break;
				case 5:
//					if ((T_bunkdrobTF > alarmCaseMill) && (lineMode[AREA] != ADJ_MODE))
//						(timerTempMaxBunkerRun(timerTempBunker * 1000)) ? (timerAlarm = 0) : (timerAlarm = 1);
					break;
				case 6:
					if (timerBeltDownRun(5000) && (alarmTimerStart[0] == 1)){
						(!elevBeltDown) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[19] = !elevBeltDown;
						alarmTimerStart[0] = 2;
					}else if (alarmTimerStart[0] == 2){
						(!elevBeltDown) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[19] = !elevBeltDown;
					}
					break;
				case 7:
					if (timerSpeedElevatorRun(5000) && (alarmTimerStart[1] == 1)){
						(!elevContolSpeed) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[20] = !elevContolSpeed;
						alarmTimerStart[1] = 2;
					} else if (alarmTimerStart[1] == 2){
						(!elevContolSpeed) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[20] = !elevContolSpeed;
					}
					break;
				case 8:
					if (timerShaftOutRun(lockRunSet) && (alarmTimerStart[2] == 1)){
						(!FC_run_0) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[44] = !FC_run_0;
						alarmTimerStart[2] = 2;
					} else if(alarmTimerStart[2] == 2){
						(!FC_run_0) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[44] = !FC_run_0;
					}
					break;
				case 9:
					if (timerShaftInRun(lockRunSet) && (alarmTimerStart[3] == 1)){
						(!FC_run_1) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[46] = !FC_run_1;
						alarmTimerStart[3] = 2;
					} else if (alarmTimerStart[3] == 2){
						(!FC_run_1) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[46] = !FC_run_1;
					}
					break;
				case 10:
					if (timerSpeedConvRun(lockRunSet) && (alarmTimerStart[4] == 1)){
						(!convControlRot) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[18] = !convControlRot;
						alarmTimerStart[4] = 2;
					} else if (alarmTimerStart[4] == 2){
						(!convControlRot) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[18] = !convControlRot;
					}
					break;
				case 11:
					if (timerBeltFeederRun(lockRunSet) && (alarmTimerStart[5] == 1)){
						(!FC_run_2) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[42] = !FC_run_2;
						alarmTimerStart[5] = 2;
					} else if (alarmTimerStart[5] == 2){
						(!FC_run_2) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[42] = !FC_run_2;
					}
					break;
				case 12:
					if (timerPumpPneumRun(lockRunSet) && (alarmTimerStart[6] == 1)){
						(!FC_run_4) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[65] = !FC_run_4;
						alarmTimerStart[6] = 2;
					}else if (alarmTimerStart[6] == 2){
						(!FC_run_4) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[65] = !FC_run_4;
					}
					break;
				case 13:
//					if ((P_pnevmoTRANS1 < alarmPrAirInjector) && (lineMode[AREA] != ADJ_MODE))
//						(timerMinPumpPneumRun(timerPrAirInjector * 1000)) ? (timerAlarm = 0) : (timerAlarm = 1);
					break;
				case 14:
					if (timerMillRun(lockRunSet) && (alarmTimerStart[7] == 1)){
						(!FC_run_5) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[67] = !FC_run_5;
						alarmTimerStart[7] = 2;
					} else if ((alarmTimerStart[7] == 2)){
						(!FC_run_5) ? (timerAlarm = 1) : (timerAlarm = 0);
						Alarmstatus[67] = !FC_run_5;
					}
					break;
				case 15:
//					if (T_bunkdrobTF > alarmCaseMill)
//						(timerTempMaxMillRun(timerTempBunker * 1000)) ? (timerAlarm = 0) : (timerAlarm = 1);
					break;
			}
		}
		begin++;
	}
	return timerAlarm;
}

BOOL alarmCheck(BOOL varLock1, BOOL varLock2, BOOL varLock3, BOOL varLock4, BOOL varLock5, BOOL varLock6,
				BOOL nAdjustLock1, BOOL nAdjustLock2, BOOL nAdjustLock3, BOOL nAdjustLock4, BOOL nAdjustLock5,
				BOOL adjustLock, BYTE counter, BYTE begin, BYTE end, const BYTE AREA)
{
	alarm = 0;
	while (counter){
		if (!alarm){
			switch (counter){
				case 1:
					(!varLock1 || !varLock2 || !varLock3 || !varLock4 || !varLock5 || !varLock6) ? (alarm = 1) : (alarm = 0);
					break;
				case 2:
					alarm = checkTimerAlarm(begin, end, AREA);
					break;
				case 3:
					if (lineMode[AREA] != ADJ_MODE)
						(!nAdjustLock1 || !nAdjustLock2 || !nAdjustLock3 || !nAdjustLock4 || !nAdjustLock5)
						 ? (alarm = 1) : (alarm = 0);
					else (!adjustLock) ? (alarm = 1) : (alarm = 0);
			}
		}
		counter--;
	}
	return alarm;
}
