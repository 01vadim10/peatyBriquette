(********************************************************************
 * COPYRIGHT (C) BERNECKER + RAINER, AUSTRIA, A-5142 EGGELSBERG 120
 ********************************************************************
 * Library: Runtime
 * File: Runtime.fun
 * Created: 11.11.2003
 ********************************************************************
 * Functions and function blocks of library Runtime
 ********************************************************************)
FUNCTION_BLOCK r_trig (* for internal use *)
	VAR_INPUT
		CLK	:BOOL;
		Q	:BOOL;
	END_VAR
	VAR_OUTPUT
		M	:BOOL;
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK f_trig (* for internal use *)
	VAR_INPUT
		CLK	:BOOL;
		Q	:BOOL;
	END_VAR
	VAR_OUTPUT
		M	:BOOL;
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK rf_trig (* for internal use *)
	VAR_INPUT
		CLK	:BOOL;
		Q	:BOOL;
	END_VAR
	VAR_OUTPUT
		M	:BOOL;
	END_VAR
END_FUNCTION_BLOCK
FUNCTION GetTime : TIME (* for internal use *)
END_FUNCTION
FUNCTION_BLOCK SFCActionControl (* for internal use *)
	VAR_INPUT
		N	:BOOL;
		R0	:BOOL;
		S0	:BOOL;
		L	:BOOL;
		D	:BOOL;
		P	:BOOL;
		SD	:BOOL;
		DS	:BOOL;
		SL	:BOOL;
		T	:TIME;
	END_VAR
	VAR_OUTPUT
		Q	:BOOL;
	END_VAR
	VAR
		S_FF_SET	: USINT ;
		S_FF_R1		: USINT ;
		S_FF_Q		: USINT ;
		dummy1		: USINT ;
		L_TMR_PT	: UDINT ;
		L_TMR_ET	: UDINT ;
		L_TMR_STAR	: UDINT ;
		L_TMR_IN	: USINT ;
		L_TMR_Q		: USINT ;
		L_TMR_M		: USINT ;
		dummy2		: USINT ;
		D_TMR_PT	: UDINT ;
		D_TMR_ET	: UDINT ;
		D_TMR_STAR	: UDINT ;
		D_TMR_IN	: USINT ;
		D_TMR_Q		: USINT ;
		D_TMR_M		: USINT ;
		dummy3		: USINT ;
		P_TRIG_CLK	: USINT ;
		P_TRIG_Q	: USINT ;
		P_TRIG_M	: USINT ;
		dummy4		: USINT ;
		SD_TMR_PT	: UDINT ;
		SD_TMR_ET	: UDINT ;
		SD_TMR_STA	: UDINT ;
		SD_TMR_IN	: USINT ;
		SD_TMR_Q	: USINT ;
		SD_TMR_M	: USINT ;
		dummy5		: USINT ;
		SD_FF_SET	: USINT ;
		SD_FF_R1	: USINT ;
		SD_FF_Q		: USINT ;
		DS_FF_SET	: USINT ;
		DS_FF_R1	: USINT ;
		DS_FF_Q		: USINT ;
		DS_TMR_PT	: UDINT ;
		DS_TMR_ET	: UDINT ;
		DS_TMR_STA	: UDINT ;
		DS_TMR_IN	: USINT ;
		DS_TMR_Q	: USINT ;
		DS_TMR_M	: USINT ;
		dummy6		: USINT ;
		SL_FF_SET	: USINT ;
		SL_FF_R1	: USINT ;
		SL_FF_Q		: USINT ;
		dummy7		: USINT ;
		SL_TMR_PT	: UDINT ;
		SL_TMR_ET	: UDINT ;
		SL_TMR_STA	: UDINT ;
		SL_TMR_IN	: USINT ;
		SL_TMR_Q	: USINT ;
		SL_TMR_M	: USINT ;
		dummy8		: USINT ;
	END_VAR
END_FUNCTION_BLOCK
