#include <bur/plctypes.h>
#include <bur/plc.h>       /* macros for B&R PLC programming */
#include <standard.h>
#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

#include "adc.h"
#include "hp1.h"
#include "contrSystemMech.h"

_GLOBAL BOOL ConnectionHP;
_GLOBAL   HP_data1     RunHP1;				/* структура для контроллера */
_LOCAL    HP_data1     UsrHP1;				   /* структура для панели */

#include "mechControlOnOff.h"

/*
**	Подпрограмма инициализации переменных контроллера
*/

void _INIT Init()
{
	ConnectionHP = 1;
	/* time */
	year_21 = 2013;
	month_21 = 05;
	day_21 = 05;
	hour_21 = 15;
	minute_21 = 03;
	second_21 = 0;
	//demidov_21= 0;
	
	GetEnable = 1;
	/* time end */
  
	memset(&RunHP1, 0, sizeof(RunHP1));
	memset(&UsrHP1, 0, sizeof(UsrHP1));
}
/*
** 			Функция ручной режим
*/
void  Drob_handling(USINT objOnNum) /*функция для ручного управления. Участок дробления*/
{
	/*действия по ручному управлению обьекта*/
	RunHP1.out1.func = objOnNum;
	switch (RunHP1.out1.func)
	{
		case 1: /*Включение конвейера*/
			if (orderManStart[3] && !orderManStart[4]){
				presetTime = timer_cold4 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[4] = 1;
				}
			} else if (!orderManStart[3]){
				elmotorM1.run = 0;
				orderManStart[4] = 0;
			}
			break;
		case 2:
			if (orderManStart[2] && !orderManStart[12]){
				presetTime = timer_cold3 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[12] = 1;
				}
			} else if (!orderManStart[2]){
				elmotorM2.run = 0;
				orderManStart[12] = 0;
			}
		case 3: /*Включение ЧП дробилки*/
			if (orderManStart[12] && !orderManStart[3]){
				presetTime = timer_cold3 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[3] = 1;
				}
			} else if (!orderManStart[12]){
				elmotorM3.run = 0;
				orderManStart[3] = 0;
			}
			break;
		case 4: /*Включение элеватора*/
			if (orderManStart[1] && !orderManStart[2]){
				presetTime = timer_cold2 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[2] = 1;
				}
			}
			if (!orderManStart[1] && !elmotorM4.run){
				orderManStart[2] = 0;
			}
			break;
		//		shaftFeederElmotOn		Бильный вал питателя. Включить электродвигатель  вращения бильного вала.
		case 9:
			if (orderManStart[4] && !orderManStart[5]){
				presetTime = timer_cold5 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[5] = 1;
				}
			} else if (!orderManStart[4]){
				elmotorM9.run = 0;
				orderManStart[5] = 0;
			}
			break;
		//beltFeederMoveOn	Лента питателя. Включение  перемещения ленты. Управление преобразователем.
		case 10: 
			if (orderManStart[5] && !orderManStart[6]){
				presetTime = timer_cold6 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[6] = 1;
				}
			} else if (!orderManStart[5]){
				elmotorM10.run = 0;
				orderManStart[6] = 0;
			}
			break;
	}
}

void  Mill_handling(USINT objOnNum) /*функция для ручного управления. */
{
	/*действия по ручному управлению обьекта*/
	RunHP1.out1.func = objOnNum;
	switch (RunHP1.out1.func)
	{
		case 5: /*The mill on*/
			if (orderManStart[1] && !orderManStart[8]){
				presetTime = timer_cold8 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[8] = 1;
				}
			} else if (!orderManStart[1]){
				elmotorM5.run = 0;
			}
			break;
		case 7: /*The ripper on*/
			if (orderManStart[10] && !orderManStart[11]){
				presetTime = timer_cold11 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[11] = 1;
				}
			} else if (!orderManStart[10]){
				elmotorM7.run = 0;
				orderManStart[11] = 0;
			}
			break;
		case 11: /*The feeder*/
			if (orderManStart[9] && !orderManStart[10]){
				presetTime = timer_cold10 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[10] = 1;
				}
			} else if (!orderManStart[9]){
				elmotorM11.run = 0;
				orderManStart[10] = 0;
			}
		case 12: /*The elmotor gateway feeder*/
			if (orderManStart[8] && !orderManStart[9]){
				presetTime = timer_cold9 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[9] = 1;
				}
			} else if (!orderManStart[8]){
				elmotorM12.run = 0;
				orderManStart[9] = 0;
			}
			break;
		case 14: /*Electromotor pump pneumatic on*/
			if (!orderManStart[7]){
				presetTime = timer_cold7 * 1000;
				(!output) ? (input = 1) : (input = 0);
				if (output){
					orderManStart[7] = 1;
				}
			}
			break;
	}
}

/*Запуск сигнализации и аспирации в ручном режиме*/
void dedusting(USINT objOnNum)
{
	RunHP1.out1.func = objOnNum;
	switch (RunHP1.out1.func)
	{
		case 0: /*Включение сирены*/
			if (lineMode[CRUSHING_AREA] != ADJ_MODE){
				presetTime = timer_cold0 * 1000;
				(!output) ? (input = 1) : (input = 0);	//Timer
				if (output){
					orderManStart[0] = 1;
					aspiration = 1;
					soundAlarm = 0;
				}
			} else orderManStart[0] = 0;
			break;
		case 13: /*Включение ЧП аспирации*/
			if (orderManStart[0] && !orderManStart[1]){
				presetTime = timer_cold1 * 1000;
				(!output) ? (input = 1) : (input = 0);	//Timer
				if (output){
					orderManStart[1] = 1;
				}
			}
			if (!elmotorM13.run){
				orderManStart[0] = 0;
				orderManStart[1] = 0;
			}
			break;
	}
}

void _CYCLIC MyExampleCyclic(void)
{
	/* преобразование кода АЦП x20AI4622 .A14 в физическую величину - температура в середине бункера 1*/
	/* 4 мА - 20 мА */
	tempMidBunker_1	= convFAI4622(tempMidBunkerMin, tempMidBunkerMax, tempMidBunker1);
	tempMidBunker_2	= convFAI4622(tempMidBunkerMin, tempMidBunkerMax, tempMidBunker2);
	tempHighBunker_1 = convFAI4622(tempHighBunkerMin, tempHighBunkerMax, tempHighBunker1);
	tempHighBunker_2 = convFAI4622(tempHighBunkerMin, tempHighBunkerMax, tempHighBunker2);
	if (tempHighBunker_2 > alarmTempHighBunker)
		Alarmstatus[86] = 1;
	T_bunkdrobTF = (tempMidBunker_1 + tempMidBunker_2 + tempHighBunker_1 + tempHighBunker_2) / 4;
	/* преобразование кода АЦП x20AI4622 A15 в физическую величину - давление в системе подачи углекислого газа, в насосе пневматическом, в трубопроводе пылеудаления*/
	/* 0 мА - 20 мА */
	P_pnevmoTRANS1 = convFAI4622(pressurePumpPneumMin, pressurePumpPneumMax, P_PumpAir_Systemcontr);
	P_CO2_resiv = convFAI4622(pressureCO2Min, pressureCO2Max,P_CO2_Systemcontr );
	T_korpusMEL_ = convFAI4622(tempCaseMillMin, tempCaseMillMax,T_korpusMEL);
	P_truboprovodSystemcontr_ = convFAI4622(pressurePipelineKilnMin, pressurePipelineKilnMax,P_truboprovodSystemcontr );  	/* функция измерения давления в трубопроводе перед печью 2 */
	letdownPipelineSystemcontr_ = convFAI4622(pressureDustPeatyMin, pressureDustPeatyMax,letdownPipelineSystemcontr );   /* функция измерения разряжения в трубопроводе пылеудаления */
	/* Вызов функций ручного и автоматического режимов */
	USINT i, area;
	for (area = 0; area < 2; area++){
		if (lineMode[area] != OFF_MODE){
			if (lineMode[area] != ADJ_MODE){
				autoModeStart();
				for (i = 0; i < sizeof(objOn); i++){
					if (objOn[i]){
						dedusting(i);
						if (!adjCrushSwitch)
							Drob_handling(i);
						if (!adjMillSwitch)
							Mill_handling(i);
					}
				}
			}
		}
	}
	for (i = 0; i < sizeof(objOn); i++){
//		adjCrushStopping(i);
//		adjMillStopping(i);
		autoModeTechStop(i);
	}
	autoModeQuickStop();
	
	/* Запуск механизмов */
	siren();
	Cooler_Head_Forward_Start();
	elev_Start();
	shaftOutCrusherForward_Start();
	shaftOutCrusherBackward_Start();
	shaftInCrusherForward_Start();
	shaftInCrusherBackward_Start();
	conv_Start();
	shaftFeederElmot_Start();
	beltFeederMoveOn_Start();
	Pump_Air_Forward_Start();
	Crasher_Head_Forward_Start();
	shluzFeeder();
	schenck();
	resetCounter1();
	ripper();
	pumpPeatCheck();
	pumpAirCheck();
}
