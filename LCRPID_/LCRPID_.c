/********************************************************************
 * COPYRIGHT -- judenkov
 ********************************************************************
 * Program: LCRPID_
 * File: LCRPID_.c
 * Author: yudenkov
 * Created: April 20, 2013
 ********************************************************************
 * Implementation of program LCRPID_
 ********************************************************************/



#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif
#include <bur/plctypes.h> /** IEC datatypes **/
#include <loopconr.h>    /** LoopConR Library **/

/** Variable declarations **/
_LOCAL  LCRPID_typ         LCRPID_0;
_LOCAL  LCRPIDpara_typ  LCRPIDpara_0;
_LOCAL  LCRPT2_typ         LCRPT2_0;
_LOCAL  REAL            setValue, manipulatedVar;
_LOCAL  BOOL           start, paraEnter;

void _INIT LCRPID_INIT(void)
{
			/* Init variables */
		setValue      = 5.0;
		start         = 0;
		paraEnter = 1;
		/* PID parameters */
		LCRPIDpara_0.WX_max   = 100.0;
		LCRPIDpara_0.WX_min   = 0.0;
		LCRPIDpara_0.invert   = 0;
		LCRPIDpara_0.deadband = 1.0;
		LCRPIDpara_0.dY_max   = 0.0;
		LCRPIDpara_0.Kp       = 1;
		LCRPIDpara_0.Tn       = 0;
		LCRPIDpara_0.Tv       = 0;
		LCRPIDpara_0.Tf       = 0.16;
		LCRPIDpara_0.Kw       = 1.0;           
		LCRPIDpara_0.Kfbk     = 1.0;		/* windup damping enabled */
		LCRPIDpara_0.fbk_mode = LCRPID_FBK_MODE_INTERN;
		LCRPIDpara_0.d_mode   =  LCRPID_D_MODE_X;

		/* Parameters for PID controller */
		LCRPID_0.Y_max  = 20.0;
		LCRPID_0.Y_min  = -20.0;
		LCRPID_0.A      = 0.0;
		LCRPID_0.Y_man  = 0.0;
		LCRPID_0.Y_fbk  = 0.0;
		LCRPID_0.hold_I = 0;
		LCRPID_0.mode   = LCRPID_MODE_AUTO;

		/* Parameters for PT2 element */
		LCRPT2_0.V     = 3.9;
		LCRPT2_0.T1    = 0.9;
		LCRPT2_0.T2    = 15.3;
		LCRPT2_0.y_set = 0.0;
		LCRPT2_0.set   = 0;
	}

void _CYCLIC LCRPID_CYCLIC(void)
{
	/* ======== CYCLIC Part ======= */
		/* PID parameters */
		LCRPIDpara_0.enable = start;
		LCRPIDpara_0.enter  = paraEnter;   
		LCRPIDpara(&LCRPIDpara_0);	/* LCRPIDpara function block call */
		paraEnter = 0;
		/* PID controller */
		LCRPID_0.enable = start;
		LCRPID_0.ident  = LCRPIDpara_0.ident; /* ident of PIDpara -> provides parameters (Kp, Tn, Tv, ...) */
		LCRPID_0.W      =  dozator_P;	//Переменная с АРМа задания по производительности для Шенка от системы Pilar
		LCRPID_0.X      =    dozator_I;
		LCRPID(&LCRPID_0);		/* LCRPID function block call */
		                    manipulatedVar = LCRPID_0.Y;
	               Set_dozatorSchenck =  manipulatedVar;	//Переменная для управления производительностью дозатора через интерфейс Profibus
	                                        start   =  Dozator_Start;
		/* PT2 element */
	//	LCRPT2_0.enable = start;
	//	LCRPT2_0.x      = manipulatedVar;
	//	LCRPT2(&LCRPT2_0);		/* LCRPT2 function block call */
	//	actValue = LCRPT2_0.y;
	
}
