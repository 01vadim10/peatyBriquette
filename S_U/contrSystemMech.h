/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: S_U
 * File: contrSystemMech.h
 * Author: vzylevich
 * Created: January 09, 2014
 *******************************************************************/

BOOL stopTimer(TIME presetTime)
{
	orderStopTimer.IN = !orderStopTimer.Q;
	orderStopTimer.PT = presetTime;
	TON(&orderStopTimer);
	return orderStopTimer.Q;
}

void crushingQuickStop(void)
{	
	elmotorM10.run = 0;
	elmotorM9.run = 0;
	elmotorM1.run = 0;
	elmotorM2.run = 0;
	elmotorM2.reverse = 0;
	elmotorM3.run = 0;
	elmotorM3.reverse = 0;
	elmotorM4.run = 0;
	lineMode[CRUSHING_AREA] = OFF_MODE;
}

BOOL crushingTechStop(USINT objOffNum)
{
	USINT i;
	BOOL stop;
	switch (objOffNum){
		case 1:
			if (orderStop[7] && !orderStop[8]){
				elmotorM1.run = 0;
				if (stopTimer(timerStop4 * 1000))
					orderStop[8] = 1;
			}
			break;
		case 2:
		case 3:
			if (orderStop[8] && !orderStop[9]){
				elmotorM2.run = 0;
				elmotorM2.reverse = 0;
				elmotorM3.run = 0;
				elmotorM3.reverse = 0;
				if (stopTimer(timerStop3 * 1000))
					orderStop[9] = 1;
			}
			break;
		case 4:
			if (orderStop[9] && !orderStop[10]){
				elmotorM4.run = 0;
				if (stopTimer(timerStop2 * 1000))
					orderStop[10] = 1;
			}
			break;
		case 9:
			if (orderStop[6] && !orderStop[7]){
				elmotorM9.run = 0;
				if (stopTimer(timerStop5 * 1000))
					orderStop[7] = 1;
			}
			break;
		case 10:
			if (!orderStop[6]){
				elmotorM10.run = 0;
				if (stopTimer(timerStop6 * 1000))
					orderStop[6] = 1;
			}
			break;
	}
	(!elmotorM1.run && !elmotorM2.run && !elmotorM3.run && !elmotorM4.run && !elmotorM9.run && !elmotorM10.run) ? (stop = 1) : (stop = 0);
	if (stop){
		for (i = 6; i <= 10; i++){
			orderStop[i] = 0;
		}
		orderStopTimer.Q = 1;
		lineMode[CRUSHING_AREA] = OFF_MODE;
	}
	return stop;
}

void adjCrushStopping(USINT objOffNum)
{
	if (!adjCrushSwitch && permission && lineMode[CRUSHING_AREA] == ADJ_MODE){
		if (crushingTechStop(objOffNum)){
			adjCrushSwitch = 1;
		}
	} else if (adjCrushSwitch && (lineMode[CRUSHING_AREA] != ADJ_MODE)){
		if (crushingTechStop(objOffNum)){
			adjCrushSwitch = 0;
		}
	} 

}

void millingQuickStop(void)
{	
	elmotorM7.run = 0;
	elmotorM11.run = 0;
	elmotorM12.run = 0;
	elmotorM5.run = 0;
	elmotorM16.run = 0;
	valveY5 = 0;
	lineMode[MILLING_AREA] = OFF_MODE;
}

BOOL millingTechStop(USINT objOffNum)
{
	USINT i;
	BOOL stop;
	switch (objOffNum){
		case 5:
			if (orderStop[2] && !orderStop[3]){
				elmotorM5.run = 0;
				if (stopTimer(timerStop8 * 1000))
					orderStop[3] = 1;
			}
			break;
		case 7:
			if (!orderStop[0]){
				elmotorM7.run = 0;
				if (stopTimer(timerStop11 * 1000))
					orderStop[0] = 1;
			}
			break;
		case 11:
			if (orderStop[0] && !orderStop[1]){
				elmotorM11.run = 0;
				if (stopTimer(timerStop10 * 1000))
					orderStop[1] = 1;
			}
			break;
		case 12:
			if (orderStop[1] && !orderStop[2]){
				elmotorM12.run = 0;
				if (stopTimer(timerStop9 * 1000))
					orderStop[2] = 1;
			}
			break;
		case 14:
			if (orderStop[3] && !orderStop[4]){
				elmotorM16.run = 0;
				if (stopTimer(timerStop7 * 1000))
					orderStop[4] = 1;
			}
			break;
	}
	if (orderStop[4] && !orderStop[5]){
		valveY5 = 0;
		if (stopTimer(timerStop6 * 1000))
			orderStop[5] = 1;
	}
	(!elmotorM5.run && !elmotorM7.run && !elmotorM11.run && !elmotorM12.run && !elmotorM16.run && !valveY5) ? (stop = 1) : (stop = 0);
	if (stop){
		for (i = 0; i <= 5; i++){
			orderStop[i] = 0;
		}
		orderStopTimer.Q = 1;
		lineMode[MILLING_AREA] = OFF_MODE;
	}
	return stop;
}

void adjMillStopping(USINT objOffNum)
{
	if (!adjMillSwitch && permission && (lineMode[MILLING_AREA] == ADJ_MODE)){
		if (millingTechStop(objOffNum)){
			adjMillSwitch = 1;
		}
	} else if (adjMillSwitch && (lineMode[MILLING_AREA] != ADJ_MODE)){
		if (millingTechStop(objOffNum))
			adjMillSwitch = 0;
	}
}

/*	Функция автоматического режима	*/
void autoModeStart(void)
{
	/* Если включена "Аспирация" включить сигнализацию, а за ней двигатель пылеудаления */
	/* Запуск механизмов участка дробления */
	if ((lineMode[CRUSHING_AREA] == AUTO_MODE) && !pointCrushingTechStop && autoCrushing){
//		if (aspiration){
//			(orderManStart[0]) ? (elmotorM13.run = 1) : (soundAlarm = 1);
//		} else {
//			elmotorM13.run  = 0;
//		}
		soundAlarm = 1;
		if (orderManStart[0]){
			elmotorM4.run  = 1;
			if (orderManStart[2])
				elmotorM2.run  = 1;
			if (orderManStart[12])
				elmotorM3.run = 1;
			if (orderManStart[3])
				elmotorM1.run  = 1;
			if (orderManStart[4])
				elmotorM9.run  = 1;
			if (orderManStart[5])
				elmotorM10.run  = 1;
		}
	}
	/* Запуск механизмов участка помола */
	if ((lineMode[MILLING_AREA] == AUTO_MODE) && !pointMillingTechStop && autoMilling){
		soundAlarm = 1;
		if (orderManStart[0]){
			if (Permission_Stove2)
				valveY5 = 1;
			if (valveY5)
				elmotorM16.run  = 1;
			if (orderManStart[7])
				elmotorM5.run  = 1;
			if (orderManStart[8])
				elmotorM12.run  = 1;
			if (orderManStart[9])
				elmotorM11.run  = 1;
			if (orderManStart[10])
				elmotorM7.run  = 1;
		}
	}
}

void autoModeQuickStop(void)
{
	if (pointCrushingQuickStop){
		crushingQuickStop();
		pointCrushingQuickStop = 0;
		sectorCrushing = 0;
		adjCrushSwitch = 0;
		autoCrushing = 0;
	}
	if (pointMillingQuickStop){
		millingQuickStop();
		pointMillingQuickStop = 0;
		sectorMilling = 0;
		adjMillSwitch = 0;
		autoMilling = 0;
	}
}

void autoModeTechStop(USINT objOff)
{
	if (pointCrushingTechStop){
		if (crushingTechStop(objOff)){
			pointCrushingTechStop = 0;
			autoCrushing = 0;
		}
		sectorCrushing = 0;
	}
	if (pointMillingTechStop){
		if (millingTechStop(objOff)){
			pointMillingTechStop = 0;
			autoMilling = 0;
		}
		sectorMilling = 0;
	}
}
