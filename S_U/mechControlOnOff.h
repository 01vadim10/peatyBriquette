/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: S_U
 * File: mechControlOnOff.h
 * Author: VZylevich
 * Created: January 14, 2014
 *******************************************************************/

#include <bur/plctypes.h>

/*
**	Преобразование входных аналоговых величин
*/

/* преобразование кода АЦП x20AI4622 в физическую величину*/
/* 4 мА - 20 мА */
REAL convFAI4622(REAL Fmin, REAL Fmax, INT d)
{
	return ( ( (Fmax - Fmin) / 32767 ) * ( d - 0 ) + Fmin );
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

void Head_CoolerSt () 
{
	Head_CoolerOn = Motor_Start (1,  0, 0 );
}
void Head_Cooler_Stop ()
{
	Head_CoolerOn=	Motor_Start (0,  0, 0);
}
//elevOn	Элеватор включить		
void elev_Start ()
{
	elevOn = Motor_Start (objOn[4], 0, 0 );
}

//shaftOutCrusherForward	Тихоходный вал дробилки. Тихоходный вал вперёд.Управление преобразователем.	
void shaftOutCrusherForward_Start ()
{
	/* upravlenie converter frecance    FORWARD   */
	FC_start_0=	 FC_ (objOn[2],RunHP1.in1.Con1_Fr ,  FC_ready_0  )  ;
}
//shaftOutCrusherBackward	Тихоходный вал дробилки. Тихоходный вал назад. Управление преобразователем.

void shaftOutCrusherBackward_Start ()
{
	/* upravlenie converter frecance    REVERS   */
	FC_start_0R=	FC_R (objOn[15],RunHP1.in1.Con1_Fr ,  FC_ready_0 )  ;
}
//shaftInCrusherForward		Быстроходный вал дробилки. Быстроходный вал дробилки вперед.  Управление преобразователем.
void  shaftInCrusherForward_Start ()
{
	/* upravlenie converter frecance    FORWARD   */
	FC_start_1=	FC_ (objOn[3],RunHP1.in1.Con2_Fr , FC_ready_1  )  ;
}
//shaftInCrusherBackward	Быстроходный вал дробилки. Быстроходный вал назад.Управление преобразователем.
void shaftInCrusherBackward_Start ()
{
	/* upravlenie converter frecance    REVERS   */
	FC_start_1R=	FC_R (objOn[16],RunHP1.in1.Con2_Fr ,  FC_ready_1  )  ;
}
//beltFeederMoveOn	Лента питателя. Включение  перемещения ленты. Управление преобразователем.

void  beltFeederMoveOn_Start ()
{
	/* upravlenie converter frecance    FORWARD   */
	FC_start_2=	FC_ (objOn[10],RunHP1.in1.Con1_Fr ,  FC_ready_2 )  ;
}
//
void Cooler_Head_Forward_Start()
{
	/* upravlenie converter frecance    FORWARD  aspiracia */
	FC_start_3=	FC_ (objOn[13],RunHP1.in1.Con6_Fr ,  FC_ready_3  )  ;
}
//
void Pump_Air_Forward_Start()
{
	/* upravlenie converter frecance    FORWARD  fulerni pump */
	FC_start_4=	FC_ (objOn[14],RunHP1.in1.Con5_Fr ,  FC_ready_4  )  ;
}
//
void Crasher_Head_Forward_Start ()
{
	/* upravlenie converter frecance    FORWARD  melnica */
	FC_start_5=	FC_ (objOn[5],RunHP1.in1.Con4_Fr ,  FC_ready_5  )  ;
}
//		shaftFeederElmotOn		Бильный вал питателя. Включить электродвигатель  вращения бильного вала.

void shaftFeederElmot_Start ()
{
	shaftFeederElmotOn=	Motor_Start (objOn[9], 0, 0);    //shaftFeederElmotOn
}
//		Конвейер включить
void conv_Start ()
{
	convForward =	Motor_Start (objOn[1],  0, 0);
}

void ripper()
{
	ripperElmotor1On = Motor_Start (objOn[7], 0, 0);
	ripperElmotor2On = ripperElmotor1On;
}

void shluzFeeder()
{
	Feeder_mot_On = Motor_Start (objOn[12], 0, 0);
}

void schenck()
{
	if (Motor_Start (objOn[11], 0, !dozatorNeispr))
		outBuffer[1] = 0x09;
	else outBuffer[1] = 0x0A;
}

void resetCounter1()
{
	if (elmotorM11.vis && objOn[6])
		outBuffer[1] = 0x49;
	else if (!elmotorM11.vis && objOn[6])
		outBuffer[1] = 0x48;
	reset1M11 = 0;
}

void siren(){
	sirenEq = objOn[0];
}

void pumpPeatCheck(void)
{
	(valveY5 && FC_start_4 && FC_start_5 && objOn[11] && Feeder_mot_On /*&& ripperElmotor2On
		&& ripperElmotor1On*/) ? (pumpPeatOn = 1) : (pumpPeatOn = 0);
}

void pumpAirCheck(void)
{
	(valveY5 && (P_pnevmoTRANS1 > 200)) ? (pumpAir = 1) : (pumpAir = 0);
}
