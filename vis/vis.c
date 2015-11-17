#include <bur/plctypes.h>
#include <string.h>
//#include "hp1.h"
#include "valveTimer.h"

#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif

//_GLOBAL HP_data1     RunHP1;				/* структура для контроллера */

void _INIT visINIT(void){
	/*valves*/
	valveY1 = 0;
	valveY2 = 0;
	valveY3 = 0;
	valveY4 = 0;
	valveY5 = 0;
	valveY6 = 0;
	
	/* page */
	areaCrushing = 0;
	areaMilling = 1;
	page.home = 0;
	page.setPage = 0;
	page.curPage = 0;
	page.newPage = 65535;
									
	hid.VBU_shaftIn				= 1;
	hid.VBU_shaftOut			= 1;
	hid.VBU_performFeeder		= 1;
	hid.VBU_diagnostics			= 1;
	hid.VBU_setup				= 1;
	
	/*Electromotors*/
	elmotorM1.run = 0;
	elmotorM1.id = 1;
	elmotorM2.id = 2;
	elmotorM3.id = 3;
	elmotorM4.id = 4;
	elmotorM5.id = 5;
	elmotorM7.id = 7;
	elmotorM8.id = 8;
	elmotorM9.id = 9;
	elmotorM10.id = 10;
	elmotorM11.id = 11;
	elmotorM13.id = 13;
	elmotorM16.id = 16;
	visElmotorM1 = 1;
	visElmotorM2 = 1;
	visElmotorM3 = 1;
	visElmotorM4 = 1;
	visElmotorM5 = 1;
	visElmotorM7 = 1;
	visElmotorM8 = 1;
	visElmotorM9 = 1;
	visElmotorM10 = 1;
	visElmotorM11 = 1;
	visElmotorM12 = 1;
	visElmotorM13 = 1;
	visElmotorM16 = 1;
	
	/*ControlsMode*/
	autoModeScreen = 1;
	autoMode = 0;
	autoModeButton = 1;
	manModeButton = 1;
	manModeScreen = 1;
	manMode = 0;
	adjustModeScreen = 1;
	adjustModeButton = 1;
	adjustMode = 1;
	mode = 1;
	aspiration = 0;
	aspirationOnOff = 1;
	sectorCrushing = 0;
	crushingOnOff = 1;
	sectorMilling = 0;
	millingOnOff = 1;
	binaryFuel = 0;
	dustPeaty = 0;
	InOutControl = 0;
	binFuelMax = 0;
	dustPeatyMax = 0;
	/*Аналог. сигн.*/
	tempMidBunker1 = 0;
	tempMidBunker2 = 0;
	tempHighBunker1 = 0;
	tempHighBunker2 = 0;
	P_CO2_Systemcontr = 0;
	P_PumpAir_Systemcontr = 0;
	P_truboprovodSystemcontr = 0;
	letdownPipelineSystemcontr = 0;
	/*Дискретные сигн.*/
	emrgPostCrusher = 0;
	emrgPost_20 = 0;
	emrgPost_65 = 0;
	emrgPost_124 = 0;
	emrgPost_157 = 0;
	emrgStopPanelControl = 0;
	controlingPanelControl = 0;
	remoteControl = 0;
	Permission_Stove2 = 0;
	coolerPyleudalElcabinetOn = 0;
	controlProtOvervoltSystemcontr = 0;
	powerInOutOnSystemcontr = 0;
	power220OnSystemcontr = 0;
	protMainRelOnSystemcontr = 0;
	tempProtElmotBeltNorm = 0;
	convControlRot = 0;
	elevBeltDown = 0;
	elevBeltUp = 0;
	elevContolSpeed = 0;
	convCableSwitch = 0;
	bunkerMinLevel = 0;
	bunkerLowLevel = 0;
	bunkerHighLevel = 0;
	bunkerMaxLevel = 0;
	relDiscContolCrush = 0;
	eqStartAdjustmModeCrush = 0;
	eqStopAdjustmModeCrush = 0;
	irSeparOn = 0;
	shaftFeederCapNOff = 0;
	shaftFeederTempNorm = 0;
	protTempBeltFeeder = 0;
	controlProtOvervoltCrush = 0;
	powerElcabinet2QueOn = 0;
	powerInOutOnCrush = 0;
	protElmotConv = 0;
	protElmotCrushShaftOut = 0;
	protElmotCrushShaftIn = 0;
	protElmotElev = 0;
	protElmotShaftFeeder = 0;
	protElmotBeltFeeder = 0;
	powerIrSeparOn = 0;
	protRelCrushOn = 0;
	protRelFeederOn = 0;
	emrgPostFeederLoadOn = 0;
	emrgPostFeederUnloadOn = 0;
	alarmMelnTechkaMaxLevel = 0;
	tempElmotorMelnNorm = 0;
	weightOn = 0;
	dozatorNeispr = 0;
	protElmotorRyhlitel = 0;
	protElmotorShluzFeeder = 0;
	tempProtShluzFeeder = 0;
	powerElmotorDozatorOn = 0;
	powerInOutOnPomol = 0;
	protRelPomolOn = 0;
	tempProtRyhlitel = 0;
	powerElcabinetPumpPneumOn = 0;
	controlProtOvervoltPomol = 0;
	relDiscContolPomol = 0;
	eqStartAdjustmModePomol = 0;
	localPostPomolStop = 0;
	valve1ExplControl = 0;
	valve2ExplControl = 0;
	valve3ExplControl = 0;
	valve4ExplControl = 0;
	controlExplValveBroken = 0;
	sirenEq = 0;
	visChooseMode = 1;
	passPage = 1;
	permission = 0;
//	USINT lineMode[2] = {0, 0};
	lineMode[0] = 0;
	lineMode[1] = 0;
	page.curPage = 2;
	crArA12 = 1;
	crArA13 = 1;
	crArA14 = 1;
	crArA15 = 1;
	crArA16 = 1;
	crArA17 = 1;
	mArA12 = 1;
	mArA13 = 1;
	mArA14 = 1;
	mArA15 = 1;
	ctrlSysA12 = 1;
	ctrlSysA13 = 1;
	ctrlSysA18 = 1;
	ctrlSysA19 = 1;
	colorBatcherCapacity = 0;
	
	STRING password[80] = "";
	DigitI = 0;
}

void checkAccess(void)
{
	if (login && !passPage){
		if (strcmp(password, "")){
			passColor = 0;
			if (!strcmp(password, passAccess1))
				permission = 1;
			else if (!strcmp(password, passAccess2))
				permission = 2;
			else {
				permission = 0;
				passColor = 1;
			}
		} else passColor = 1;
		if (!passColor)
			passPage = 1;
		login = 0;
	} else if (logOut && !passPage){
		strcpy(password, "");
		passPage = 1;
		logOut = 0;
		permission = 0;
	}
}

BOOL checkCrushingArea(void)
{
	return ((pointCrushingQuickStop || pointCrushingTechStop) && !elmotorM4.vis);
}

BOOL checkMillingArea(void)
{
	return ((pointMillingQuickStop || pointMillingTechStop) && !valveY5);
}

//void countDosing(void)
//{
//	if (pointCrushingTechStop && countD){
//		countDosingStart = dozator_Z1;
//		countDosingMat = dozator_Z1 / 
//	}
//}
void _CYCLIC visCYCLIC( void )
{
	/*Присвоить структуре электродвигателей содержащих ЧП их состояние (Включение/выключение)*/
	elmotorM1.vis = convForward; 		//Контроль вращения конвейера
	elmotorM2.vis = FC_run_0;			/*Работа ПЧ тихоходного вала дробилки.*/
	elmotorM3.vis = FC_run_1;			/*Работа ПЧ быстроходного  вала дробилки.*/
	elmotorM4.vis = elevOn;				//Элеватор
	elmotorM5.vis = FC_run_5;			/*Работа ПЧ мельницы 200 квт*/
	elmotorM7.vis = ripperElmotor1On; 	//Рыхлитель. Двигатель 1 и 2 включить
	elmotorM9.vis = shaftFeederElmotOn; //Бильный вал питателя
	elmotorM10.vis = FC_run_2;			/*Работа ПЧ ленточного питателя.*/
	elmotorM11.vis = buffer[1] & 0x01;	//Питание дозатора
	elmotorM12.vis = Feeder_mot_On; 	//Питатель шлюзовый
	elmotorM13.vis = FC_run_3;			/*Работа  ПЧ двигателя аспирации*/
	elmotorM16.vis = FC_run_4;			/*Работа  ПЧ воздушно- винтового насоса*/
	
	checkAccess();
	
//	if (!bunkerMaxLevel)
//		if (!elmotorM4.vis && !elmotorM2.vis && !elmotorM3.vis && !elmotorM1.vis && !elmotorM9.vis && !elmotorM10.vis)
//			lineMode[CRUSHING_AREA] = 0;
//	if (!valveY5 && !elmotorM16.vis && !elmotorM5.vis && !elmotorM12.vis && !elmotorM11.vis && !elmotorM7.vis)
//		lineMode[MILLING_AREA] = 0;
	if (elevUp){
		if (elevBeltUp)
			elevBeltDirection = 1;
		else if (elevBeltDown)
			elevBeltDirection = 4;
	}
	if (!controlingPanelControl){
		lockCrushingAreaVis = 1;
		lockMillingAreaVis = 1;
	}else{
		(lineMode[CRUSHING_AREA] < 2) ? (lockCrushingAreaVis = 1) : (lockCrushingAreaVis = 0);
		(lineMode[MILLING_AREA] < 2) ? (lockMillingAreaVis = 1) : (lockMillingAreaVis = 0);
	}
	if (dozator_Z1 < (dozator_Z1 * lowBatcherCapacity / 100)){
		if (lowBatcherCapacityTimer(timer_cold12 * 1000)){
			colorBatcherCapacity = 1;
		}
		Alarmstatus[108] = 1;
	}
	/*Проверяем в каком режиме зашёл пользователь, если не в наладочном,
	то возвращаем на страницу Мнемосхемы установки*/	
	if (page.newPage == 61){
		(permission) ? (page.curPage = 61) : (page.setPage = 2);
//		(permission == 2) ? (adjustMode = 0) : (adjustMode = 1);
	}
	if ((page.curPage != 2) && !visChooseMode)
		visChooseMode = 1;
	
	if (page.curPage == 2){
		if (permission){
			if (checkCrushingArea())
				lineMode[CRUSHING_AREA] = OFF_MODE;
			if (checkMillingArea())
				lineMode[MILLING_AREA] = OFF_MODE;
		} else{
			if (lineMode[CRUSHING_AREA] == ADJ_MODE)
				lineMode[CRUSHING_AREA] = OFF_MODE;
			if (lineMode[MILLING_AREA] == ADJ_MODE)
				lineMode[MILLING_AREA] = OFF_MODE;
		}
//		if ((lineMode[CRUSHING_AREA] < ADJ_MODE) && (lineMode[CRUSHING_AREA] > OFF_MODE))
//			adjCrushSwitch = 0;
		if (valveY1)
			valveY1Timer();
		else valveY1T.Q = 1;
		if (valveY2)
			valveY2Timer();
		else valveY2T.Q = 1;
		if (valveY3)
			valveY3Timer();
		else valveY3T.Q = 1;
		if (valveY4)
			valveY4Timer();
		else valveY4T.Q = 1;
//		if ((lineMode[CRUSHING_AREA] < ADJ_MODE) || (lineMode[MILLING_AREA] < ADJ_MODE) && (page.newPage != 61))
//			strcpy(password, "");
		if (soundAlarm)
			objOn[0] = 1;
		else{
			objOn[0] = 0;
//			orderManStart[0] = 0;
		}
		//Если выбрано дистанционное управление или одна линий находится в автомат. режиме и звуковая сигнал-я еще не
		//сработала, заблокирвать кнопку зв. сигн-ции
		if (!controlingPanelControl || ((autoCrushing || autoMilling) && !orderManStart[0]))
			soundLock = 1;
		else soundLock = 0;
		//двигатель конвейера
		if (elmotorM1.run && !alarmConveyor){
			objOn[1] = 1;
			if (alarmTimerStart[4] != 2) alarmTimerStart[4] = 1;
		} else {
			elmotorM1.run = 0;
			objOn[1] = 0;
			alarmConveyor = 0;
			alarmTimerStart[4] = 0;
			orderManStart[4] = 0;
		}
		//двигатель тихоходного вала дробилки
		if (elmotorM2.run && !alarmShaftOut){
			shaftOutCrusherCoolerOn = 1;
			objOn[2] = 1;
			coolerShaftOutTON.Q = 1;
			if (alarmTimerStart[2] != 2) alarmTimerStart[2] = 1;
		} else{
			elmotorM2.run = 0;
			if (lineMode[CRUSHING_AREA] == AUTO_MODE)
				elmotorM3.run = 0;
			objOn[2] = 0;
			alarmTimerStart[2] = 0;
			orderManStart[12] = 0;
			if (!elmotorM2.reverse){
				alarmShaftOut = 0;
				if (shaftOutCrusherCoolerOn){
					if (stopCoolerShaftOut(timerCoolerShaftOut * 1000))
						shaftOutCrusherCoolerOn = 0;
				}
			}
		}
		if (lineMode[CRUSHING_AREA] == ADJ_MODE){
			if (elmotorM2.reverse && !alarmShaftOut){
				coolerShaftOutTON.Q = 1;
				shaftOutCrusherCoolerOn = 1;
				objOn[15] = 1;
			} else{
				elmotorM2.reverse = 0;
				objOn[15] = 0;
				if (!elmotorM2.run){
					alarmShaftOut = 0;
					if (shaftOutCrusherCoolerOn){
						if (stopCoolerShaftOut(timerCoolerShaftOut * 1000))
							shaftOutCrusherCoolerOn = 0;
					}
				}
			}
			if (elmotorM3.reverse && !alarmShaftIn){
				coolerShaftInTON.Q = 1;
				shaftInCrusherCoolerOn = 1;
				objOn[16] = 1;
			} else{
				elmotorM3.reverse = 0;
				objOn[16] = 0;
				if (!elmotorM3.run){
					alarmShaftIn = 0;
					if (shaftInCrusherCoolerOn){
						if (stopCoolerShaftIn(timerCoolerShaftIn * 1000))
							shaftInCrusherCoolerOn = 0;
					}
				}
			}
		}
		//двигатель быстроходного вала дробилки
		if (elmotorM3.run && !alarmShaftIn){
			coolerShaftInTON.Q = 1;
			shaftInCrusherCoolerOn = 1;
			objOn[3] = 1;
			if (alarmTimerStart[3] != 2) alarmTimerStart[3] = 1;
		} else{
			elmotorM3.run = 0;
			objOn[3] = 0;
			alarmTimerStart[3] = 0;
			orderManStart[3] = 0;
			if (!elmotorM3.reverse){
				alarmShaftIn = 0;
				if (shaftInCrusherCoolerOn){
					if (stopCoolerShaftIn(timerCoolerShaftIn * 1000))
						shaftInCrusherCoolerOn = 0;
				}
			}
		}
		//двигатель элеватора
		if (elmotorM4.run && !alarmElevator && !alarmBunkerMaxLevel){
			objOn[4] = 1;
			if (alarmTimerStart[0] != 2) alarmTimerStart[0] = 1;
			if (alarmTimerStart[1] != 2) alarmTimerStart[1] = 1;
		} else {
			elmotorM4.run = 0;
			objOn[4] = 0;
			alarmElevator = 0;
			alarmTimerStart[0] = 0;
			alarmTimerStart[1] = 0;
			orderManStart[2] = 0;
		}
		//двигатель мельницы
		if (elmotorM5.run && !alarmMill && !alarmValveExpl){
			objOn[5] = 1;
			if (alarmTimerStart[7] != 2) alarmTimerStart[7] = 1;
		} else {
			objOn[5] = 0;
			elmotorM5.run = 0;
			alarmMill = 0;
			alarmTimerStart[7] = 0;
			orderManStart[8] = 0;
		}
		//двигатель рыхлителя
		if (elmotorM7.run && !alarmRipper){
			objOn[7] = 1;
		} else {
			objOn[7] = 0;
			elmotorM7.run = 0;
			alarmRipper = 0;
			orderManStart[11] = 0;
		}
		//двигатель бильного вала питателя
		if (elmotorM9.run && !alarmShaftFeeder){
			objOn[9] = 1;
		} else {
			objOn[9] = 0;
			elmotorM9.run = 0;
			alarmShaftFeeder = 0;
			orderManStart[5] = 0;
		}
		//двигатель ленты питателя
		if (elmotorM10.run && !alarmBeltFeeder){
			beltFeederCoolerOn = 1;
			objOn[10] = 1;
			coolerBeltFeederTON.Q = 1;
			if (alarmTimerStart[5] != 2) alarmTimerStart[5] = 1;
		} else {
			objOn[10] = 0;
			elmotorM10.run = 0;
			alarmBeltFeeder = 0;
			alarmTimerStart[5] = 0;
			orderManStart[6] = 0;
			if (beltFeederCoolerOn){
				if (stopCoolerBeltFeeder(timerCoolerBeltFeeder * 1000) && !alarmBeltFeeder)
					beltFeederCoolerOn = 0;
				else if (alarmBeltFeeder)
					beltFeederCoolerOn = 0;
			}
		}
		//двигатель дозатора «Шенк»
		if (elmotorM11.run && !alarmDozator){
			objOn[11] = 1;
		} else {
			objOn[11] = 0;
			elmotorM11.run = 0;
			alarmDozator = 0;
			orderManStart[10] = 0;
		}
		//Сбросить счетчик количества подаваемого материала 1
		(reset1M11) ? (objOn[6] = 1) : (objOn[6] = 0);
			
		//двигатель шлюзового питателя
		if (elmotorM12.run && !alarmGatewayFeeder){
			objOn[12] = 1;
		} else {
			objOn[12] = 0;
			elmotorM12.run = 0;
			alarmGatewayFeeder = 0;
			orderManStart[9] = 0;
		}
		/*Работа двигателя аспирации*/
		if (elmotorM13.run && !alarmAspiration){
			objOn[13] = 1;
			if (alarmTimerStart[8] != 2) alarmTimerStart[8] = 1;
		} else {
			elmotorM13.run = 0;
			objOn[13] = 0;
			alarmTimerStart[8] = 0;
			alarmAspiration = 0;
			orderManStart[1] = 0;
		}
		/*Работа воздушно-винтового насоса*/
		if (elmotorM16.run && !alarmPumpPneum){
			objOn[14] = 1;
			if (alarmTimerStart[6] != 2) alarmTimerStart[6] = 1;
		} else {
			objOn[14] = 0;
			elmotorM16.run = 0;
			alarmPumpPneum = 0;
			alarmTimerStart[6] = 0;
			orderManStart[7] = 0;
		}
	} else passPage = 1;
	/*Окно управления в автоматическом режиме*/
	if (autoModeScreen){
		aspirationOnOff = 1;
		crushingOnOff = 1;
		millingOnOff = 1;
	}
	if (!autoModeButton){
		adjustModeScreen = 1;
		manModeScreen = 1;
	}
	
	/*Переключение Участков дробления и помола на странице входов/выходов*/
	if (page.curPage == 62){
		(areaMilling == 0) ? (areaCrushing = 1) : (areaCrushing = 0);
	}
	
	 /*Переключение страниц с кнопок на мнемосхемах */
	if ((page.newPage == 65535) && (page.setPage != page.setPageOld)){
		if (!page.setPage){
			page.setPage 		= page.setPageOld;
		}	
		else{
			page.newPage 		= page.setPage;
			page.setPageOld 	= page.setPage;
		}
	}
}
