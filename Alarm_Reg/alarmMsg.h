/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: Alarm_Reg
 * File: alarmMsg.h
 * Author: str
 * Created: December 19, 2013
 *******************************************************************/

#include <bur/plctypes.h>
#include <bur/plc.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void alarmMsg(void)
{
	Alarmstatus[21] = !convCableSwitch;
	Alarmstatus[22] = !bunkerMinLevel;
	Alarmstatus[24] = !relDiscContolCrush;
	Alarmstatus[26] = !shaftFeederCapNOff;
	Alarmstatus[29] = !controlProtOvervoltCrush;
	Alarmstatus[30] = !powerInOutOnCrush;
	if (elmotorM4.run || elmotorM2.run || elmotorM3.run || elmotorM1.run || elmotorM9.run || elmotorM10.run)
		Alarmstatus[38] = !protRelCrushOn;
	if (elmotorM9.run || elmotorM10.run)
		Alarmstatus[39] = !protRelFeederOn;
	Alarmstatus[40] = !emrgPostFeederLoadOn;
	Alarmstatus[41] = !emrgPostFeederUnloadOn;
	Alarmstatus[55] = !powerInOutOnPomol;
	if (elmotorM16.run || elmotorM5.run || elmotorM12.run || elmotorM11.run || elmotorM7.run)
		Alarmstatus[56] = !protRelPomolOn;
	Alarmstatus[59] = !controlProtOvervoltPomol;
	Alarmstatus[60] = !relDiscContolPomol;
	Alarmstatus[69] = !controlExplValveBroken;
	Alarmstatus[70] = !emrgPostCrusher;
	Alarmstatus[71] = !emrgPost_20;
	Alarmstatus[72] = !emrgPost_65;
	Alarmstatus[73] = !emrgPost_124;
	Alarmstatus[74] = !emrgPost_157;
	Alarmstatus[75] = !emrgStopPanelControl;
	Alarmstatus[76] = !Permission_Stove2;
	Alarmstatus[80] = !controlProtOvervoltSystemcontr;
	Alarmstatus[81] = !powerInOutOnSystemcontr;
	Alarmstatus[82] = !power220OnSystemcontr;
	if (P_CO2_resiv < alarmPressureCO2)
		Alarmstatus[90] = 1;
	
	/* Очистка аварийных сообщений*/
	USINT i;
	if (resetAlarmMessages){
		for (i = 0; i <= sizeof(Alarmstatus); i++)
			Alarmstatus[i] = 0;
		resetAlarmMessages = 0;
	}
}
