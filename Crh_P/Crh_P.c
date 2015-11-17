/********************************************************************
 * COPYRIGHT -- judenkov
 ********************************************************************
 * Program: Crh_P
 * File: Crh_P.c
 * Author: yudenkov
 * Created: April 17, 2013
 ********************************************************************
 * Implementation of program Crh_P
 ********************************************************************/


#include <bur/plctypes.h>
#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif
//#include "hp1.h"
#include "adc.h"
#include <bur/plc.h>       /* macros for B&R PLC programming */
#include <standard.h>     /* prototypes for STANDARD-Library */
#include  <loopconr.h>     /** LoopConR Library **/
/* === variables declaration === */
_GLOBAL BOOL input;         /* input */
_GLOBAL TIME presetTime;    /* Time for switch on delay */
_GLOBAL BOOL output;        /* output is input with an on switch delay of presetTime */                    

/*
**							Объявление GLOBAL и LOCAL переменных
************************************************************************************************************************************************/

_GLOBAL BOOL ConnectionHP;
_GLOBAL   HP_data1     RunHP1;				/* структура для контроллера */
_LOCAL    HP_data1     UsrHP1;				   /* структура для панели */

_LOCAL BOOL HP_alarm_button_OFF; 	/* Кнопка аварийного  отключение функции через 30 с. */
_LOCAL INT timer_HP_alarm_button_OFF;
_LOCAL INT timer1;
_LOCAL INT timer2;

_GLOBAL REAL	var[20];
/*
**								Подпрограмма инициализации переменных контроллера
*/

void _INIT Init()
{
	ConnectionHP = 1;
	/* time */	
	GetEnable = 1;
	/* time end */
  
	memset(&RunHP1, 0, sizeof(RunHP1));
	memset(&UsrHP1, 0, sizeof(UsrHP1));
    
	//RunHP1.out1.regim = UsrHP1.out1.regim = 1;
	HP_alarm_button_OFF = 0;
	timer_HP_alarm_button_OFF = 0;
	timer1 = 0;
	timer2 = 0;

}
/*
**								Преобразование входных аналоговых величин
*/

/* преобразование кода АЦП x20AI4622 .A14 в физическую величину */
/* 4 мА - 20 мА */
REAL convFAI4622T(REAL Fmin, REAL Fmax, INT d)
{
	return ( ( (Fmax - Fmin) / 26208.0 ) * ( d - 6552 ) + Fmin );
}
/* преобразование кода АЦП x20AI4622 A15 в физическую величину */
/* 0 мА - 20 мА */
REAL convFAI4622P1(REAL Fmin, REAL Fmax, INT d)
{
	return ( ( (Fmax - Fmin) / 32760 - 0 ) * ( d - 0 ) + Fmin );
}

/* преобразование кода АЦП x20AI4622 A16 в физическую величину */
/* 0 мА - 20 мА */
REAL convFAI4622P2(REAL Fmin, REAL Fmax, INT d)
{
	return ( ( (Fmax - Fmin) / 32760 - 0 ) * ( d - 0 ) + Fmin );
}
/* преобразование кода АЦП x20AI4622 A16 в физическую величину */
/* 0 мА - 20 мА */
REAL convFAI4622P3(REAL Fmin, REAL Fmax, INT d)
{
	return ( ( (Fmax - Fmin) / 32760 - 0 ) * ( d - 0 ) + Fmin );
}
/* преобразование кода АЦП x20AI4622 A16 в физическую величину */
/* 0 мА - 20 мА */
REAL convFAI4622P4(REAL Fmin, REAL Fmax, INT d)
{
	return ( ( (Fmax - Fmin) / 32760 - 0 ) * ( d - 0 ) + Fmin );
}


/* upravlenie converter frecance    FORWARD   */
BOOL  FC_ (BOOL D_st, REAL Fset , BOOL FC_ready )
{  BOOL FC_start;
	if   ((D_st) && (FC_ready) &&( Fset>=0)) {
		FC_start = 1;
	}
	else{
		FC_start = 0;
	}
	return FC_start;
}
		
/* upravlenie converter frecance   REVERS   */
BOOL  FC_R (BOOL D_st, REAL  Fset, BOOL FC_ready )
{BOOL FC_start_R;
	if   ((D_st) && (FC_ready) &&( Fset>=0)) {
		FC_start_R = 1;
	}
	else{
		FC_start_R = 0;
	}
	return FC_start_R;
}

/* upravlenie   elektromotors : '1'-start, '0'- stop   */
BOOL Motor_Start (BOOL D_st,  BOOL  M_Tmax, BOOL  M_Imax )
{BOOL M_start_F;
	if   ((D_st) && ( ! M_Tmax)  &&  ( ! M_Imax)) {
		M_start_F = 1;
	}
	else{
		M_start_F= 0;
	}
	return M_start_F ;
}

/* upravlenie   elektroklapan : '1'-ON, '0'- OFF   */
BOOL  Klapan_ON (BOOL D_st  )
{BOOL KL_ON;
	if  (D_st)  {
		KL_ON = 1;
	}
	else{
		KL_ON = 0;
	}
	return KL_ON ;
}

//	    Melnica	 Включение вентилятора принудительного обдува электродвигателя.
//      Air_Pump  Включение вентилятора принудительного обдува электродвигателя.
//		Aspiration_Cooler Включение вентилятора принудительного обдува электродвигателя.	

void Cooler_Crh_Start ()
{
Crusher_HeadCoolerOn=	Motor_Start (1,  0, 0 );
Pump_AirCoolerOn=	Motor_Start (1,  0, 0 );
Head_CoolerOn=	Motor_Start (1,  0, 0 );
}
void Cooler_Crh_Stop ()
{
Crusher_HeadCoolerOn=	Motor_Start (0,  0, 0  );
Pump_AirCoolerOn=	Motor_Start (0,  0, 0   );
Head_CoolerOn=	Motor_Start (0,  0, 0);
}
//Vorosh_On	Voroshilka включить		
void Vorosh_Start ()
{
Vorosh_On=	Motor_Start (1, protmotor_Vorosh_T, protmotor_Vorosh_I );
}
void Vorosh_Stop ()
{
Vorosh_On=	Motor_Start (0, protmotor_Vorosh_T, protmotor_Vorosh_I );
}

//Старт  ПЧ двигателя аспирации (пылеудаления)
void Cooler_Head_Forward_Start ()
{
	/* upravlenie converter frecance    FORWARD   */
 FC_start_3=	FC_ (test1,RunHP1.in1.Con4_Fr ,  FC_ready_3 )  ;
}
//Старт  ПЧ воздушно- винтового насоса 
void Pump_Air_Forward_Start ()
{
	/* upravlenie converter frecance    FORWARD   */
FC_start_4=	FC_ (test1,RunHP1.in1.Con5_Fr ,  FC_ready_4  )  ;
}
//Старт  ПЧ мельницы 200 квт
void Crasher_Head_Forward_Start ()
{
	/* upravlenie converter frecance    FORWARD   */
FC_start_5=	FC_ (test1,RunHP1.in1.Con6_Fr ,  FC_ready_5  )  ;
}
//			Включить электродвигатель   шлюзовой  питателя. 

void Feeder_mot_Start ()
{
Feeder_mot_On=	Motor_Start (test1,  prot_mot_Feeder_T  , prot_mot_Feeder_I  );    //Feeder_mot_On
}
//Вiключить электродвигатель   шлюзовой  питателя.
void Feeder_mot_Stop ()
{
Feeder_mot_On=	Motor_Start (0,  prot_mot_Feeder_T  , prot_mot_Feeder_I  );    //Feeder_mot_On
}

void Sound (void)
{
	presetTime = timer_cold1;
	if (output=0 ) 
	{ input=Sirena=1;}   //Timer;
	else	{	Sirena=0;	input=0;}
}

//								Функция Start automat
void Crh_Start (void)    
{

	/*elmotorM1.run = 0;
	elmotorM2.run = 0;
	elmotorM3.run = 0;
	elmotorM4.run = 0;
	elmotorM5.run = 0;
	elmotorM7.run = 0;
	elmotorM9.run = 0;
	elmotorM10.run = 0;
	elmotorM11.run = 0;
	elmotorM12.run = 0;
	elmotorM13.run = 0;
	elmotorM16.run = 0;
	/*	if (RunHP1.out1.func == 0)
	{
	if (UsrHP1.out1.func == 0) RunHP1.out1 = UsrHP1.out1;
	else RunHP1.out1.func1 = UsrHP1.out1.func;
	}
	else
	{*/
	switch (RunHP1.out1.step1)
	{
		case 1: 
			//	Sound;
			presetTime = timer_cold1;
			if (!output ) 
			{ input=Sirena=1;}   //Timer;
			else	{	Sirena=0;	input=0;
				RunHP1.out1.step1=2;
			}
			break;
		case 2: 
			Cooler_Crh_Start ();
			if  (  Crusher_HeadCoolerOn &&Head_CoolerOn   &&  Pump_AirCoolerOn  ) RunHP1.out1.step1=3;
			break;
		case 3: 
			Cooler_Head_Forward_Start ();
			presetTime = timer_cold9;
			if (!output )
			{input=1; } //Timer;
			else	{	input=0;
				if ( FC_run_3 )  RunHP1.out1.step1=4; Head_CoolerOn=1;}
			break;
		case 4: 
			if (P_aspirat>=P_aspirat_Nom) {  RunHP1.out1.step1=5;     }
			else	{presetTime = timer_cold9;
				if (!output )
				{input=1; } //Timer;
				else	{	input=0;
					RunHP1.out1.Alarm=1;
					RunHP1.out1.step1=4;
				}
			}		
			break;
		case 5: 
		Y1_=	Klapan_ON (test1); Y3_=Klapan_ON (test1 ); Y6_= Klapan_ON (test1 );
			if (P_CO2_resiv<=P_CO2_resiv_Nom ) {RunHP1.out1.step1=6;}
			break;
		case  6: 
			Crasher_Head_Forward_Start ();
			presetTime = timer_cold8;
			if (!output )
			{input=1; } //Timer;
			else	{	input=0;
				if (FC_run_5 )  RunHP1.out1.step1=7; Crusher_HeadOn=1;}
			break;
		case 7: 
	Y5_=		Klapan_ON (test1 ); Pump_Air_Forward_Start ();
			presetTime = timer_cold8;
			if (!output )
			{input=1; } //Timer;
			else	{	input=0;
				if (FC_run_4 )  RunHP1.out1.step1=8;Pump_AirOn =1;}
			break;
		case 8: 
		Y6_=	Klapan_ON (0 ); Feeder_mot_Start (); Vorosh_Start ();
			if  (Feeder_mot_On    && Vorosh_On     ) {RunHP1.out1.step1=9;}
				break;
	case 9: // rabota dozatora SCHENCK: 
			if (Dozator_ON&&Dozator_Ready&& !Dozator_Error &&Permission_Stove ) {Dozator_Start=1; Vorosh_Start ();
				if (dozator_I>=Wnom_dozatorSchenck) { Y1_=Klapan_ON (0 ); Y3_= Klapan_ON (0 ); RunHP1.out1.step1=9 ; }
		
		}
			else  	
			{	Vorosh_Stop ();	presetTime = timer_cold8;
				if (!output )
				{input=1; } //Timer;
				else	{	input=0; Counter++; RunHP1.out1.step1=9 ;
					if (Counter==5 ) {RunHP1.out1.Alarm=2; RunHP1.out1.step1=10;}
			            	}
			}
		break;
		case 10: // rabota uchastka  pomola
			//Аварийный останов, работа по датчикам бункера,останов оператором
					Alarm_Stop_Pomol=1;	
			
			break;
	}
	

}


//								Функция Останов


void Crh_stop() /*Функция останова управляемого обьекта */
{	test1=0;

	switch (RunHP1.out1.step1)
	{
		case 1: 
			if (Dozator_ON&&Dozator_Ready&& !Dozator_Error &&Permission_Stove ) {Dozator_Start=1; Vorosh_Start ();
				if (dozator_I<=Wnom_dozatorSchenck) {Y1_= Klapan_ON (1  ); Y3_=Klapan_ON (1  ); RunHP1.out1.step1=2 ; }}
			break;
		case 2: 
			if (P_CO2_resiv<=P_CO2_resiv_Min ) {	RunHP1.out1.Alarm=3; RunHP1.out1.step1=8;} //coobchenie- nizkoe P_CO2
			else { 	if (Dozator_ON&&Dozator_Ready&& !Dozator_Error &&Permission_Stove ) {Dozator_Start=1; Vorosh_Start ();
					if (dozator_I<=Wmin_dozatorSchenck) {Y1_=Klapan_ON (1 ); Y3_=Klapan_ON (1);Dozator_Start=0; Vorosh_Stop (); RunHP1.out1.step1=3 ; }} }
			break;
		case 3: 
			Crasher_Head_Forward_Start ();
			presetTime = timer_cold8;
			if (!output )
			{input=1; } //Timer;
			else	{	input=0;
				if (!FC_run_5 )  RunHP1.out1.step1=4; Crusher_HeadOn=0;}
			break;
		case 4: 
		 Pump_Air_Forward_Start ();
			presetTime = timer_cold8;
			if (!output )
			{input=1; } //Timer;
			else	{	input=0;
				if (!FC_run_4 )  RunHP1.out1.step1=5;Pump_AirOn =0;}
			break;
		case 5: 
		  Y5_=	Klapan_ON (test1 );Y1_= Klapan_ON (0  ); Y3_= Klapan_ON (0 );Feeder_mot_Start (); RunHP1.out1.step1=0;
			break;
		case  6: 
		
			break;
		case 7: 
			RunHP1.out1.step1=0;
			break;
		case 8: // rabota drobilnogo uchastka: 
			//Аварийный останов, работа по датчикам бункера,останов оператором
		Alarm_Stop_Pomol=1;	
			
			break;
	}
}



/*
** 										Функция ручной режим
*/

void Crh_handling() /*функция для ручного управления*/
{
	/*действия по ручному управлению обьекта*/
  
	
	switch (RunHP1.out1.func1)
	{
		case 9: 
			presetTime = timer_cold1;

			if (!output ) 
			{ input=Sirena=1;}   //Timer;
			else	{	Sirena=0;	input=0;
			}
			break;
		case 10: 
			if (test1)
			{Cooler_Crh_Start ();
				if  (  Crusher_HeadCoolerOn && Pump_AirCoolerOn   &&  Head_CoolerOn   )  Cooler_converter_ON=1;  }
			Cooler_Crh_Stop ();Cooler_converter_ON=0; 
			break;
		case 11: 
				if (test1)
			Cooler_Head_Forward_Start ();
			presetTime = timer_cold9;
			if (!output )
			{input=1; } //Timer;
			else	{	input=0;
				if ( FC_run_3 )  RunHP1.out1.step1=4; Head_CoolerOn=1;}
			test1=0; 	Cooler_Head_Forward_Start ();	if (!FC_run_3 )   Head_CoolerOn=0;RunHP1.out1.step1=0;
			break;
		case 12: 
			if (P_aspirat>=P_aspirat_Nom) {  RunHP1.out1.step1=12;     }
			else	{presetTime = timer_cold9;
				if (!output )
				{input=1; } //Timer;
				else	{	input=0;
					RunHP1.out1.Alarm=1;
					RunHP1.out1.step1=4;
				}
			}		
				break;
		case 13: 
				if (test1&&(P_aspirat>=P_aspirat_Nom))
		Y1_=	Klapan_ON (test1  ); Y3_=Klapan_ON (test1 );Y6_=Klapan_ON (test1 );
			if (P_CO2_resiv<=P_CO2_resiv_Nom ) {RunHP1.out1.step1=6;}
		Y1_=	Klapan_ON (0  );Y3_= Klapan_ON (0 );Y6_ =Klapan_ON (0  );RunHP1.out1.step1=0;
			break;
		case 14: 
				if (test1&&(P_aspirat>=P_aspirat_Nom)  &&(P_CO2_resiv>= P_CO2_resiv_Min))
			Crasher_Head_Forward_Start ();
			presetTime = timer_cold8;
			if (!output )
			{input=1; } //Timer;
			else	{	input=0;
				if (FC_run_5 )  RunHP1.out1.step1=7; Crusher_HeadOn=1;}
			test1=0; 	Crasher_Head_Forward_Start ();	if (!FC_run_5 )  { Crusher_HeadOn=0;RunHP1.out1.step1=0;}
			break;
		case 15: 
			if (test1&& (Crusher_HeadOn=1))
	 Y5_=	Klapan_ON (test1 ); Pump_Air_Forward_Start ();
			presetTime = timer_cold8;
			if (!output )
			{input=1; } //Timer;
			else	{	input=0;
				if (FC_run_4 )  RunHP1.out1.step1=15;Pump_AirOn =1;}
				test1=0; Y5_=Klapan_ON (test1  ); Pump_Air_Forward_Start ();	if (!FC_run_4 )  {Pump_AirOn =0;RunHP1.out1.step1=0;}
			break;
		case 16: 
				if (test1&& (Pump_AirOn=1))
		Y6_=	Klapan_ON (0); Feeder_mot_Start (); Vorosh_Start ();
			if  (Feeder_mot_On    && Vorosh_On     ) {RunHP1.out1.step1=9;}
			test1=0;Feeder_mot_Stop (); Vorosh_Stop ();	if  (!Feeder_mot_On    &&! Vorosh_On     ) {RunHP1.out1.step1=0;}
			break;
		case 17: 
				if  (test1&&Feeder_mot_On    && Vorosh_On&& (Pump_AirOn=1) )
			if (Dozator_ON&&Dozator_Ready&& !Dozator_Error &&Permission_Stove ) {Dozator_Start=1; Vorosh_Start ();
				if (dozator_I>=Wnom_dozatorSchenck) {Y1_= Klapan_ON (0  );  Y3_=Klapan_ON (0 ); RunHP1.out1.step1=16 ; }
					}
			Dozator_Start=0; Vorosh_Stop (); Feeder_mot_Stop (); RunHP1.out1.step1=0 ; 
			break;
	}
	
}
void _CYCLIC Crh_main (void)
{	
	switch (DigitI)
	{
		case 1:
			RunHP1.out1.step1 = sectorMilling;
			Crh_Start ();
			if (  emrgPostFeederLoadOn || emrgPostFeederUnloadOn || convCableSwitch ) Crh_stop();
			break;
		case 0:
			//RunHP1.out1.func1 = 
			Crh_handling();
			if ( eqStopAdjustmMode || relDiscContol)  Crh_stop();
			break;
		case 2:
			//наладочный  режим
			break;
	}
}
