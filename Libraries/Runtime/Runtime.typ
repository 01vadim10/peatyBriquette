(********************************************************************
 * COPYRIGHT (C) BERNECKER + RAINER, AUSTRIA, A-5142 EGGELSBERG 120
 ********************************************************************
 * Library: Runtime
 * File: Runtime.typ
 * Created: 11.11.2003
 ********************************************************************
 * Data types of library Runtime
 ********************************************************************)
TYPE
	SFCActionType : STRUCT
		x	: BOOL ;
		_x	: BOOL ;
		t	: TIME ;
		_t	: TIME ;
		AC  : SFCActionControl;
	END_STRUCT;
	SFCStepType : STRUCT
		x	: BOOL ;
		t	: TIME ;
		_x	: BOOL ;
		_t	: TIME ;
	END_STRUCT;
END_TYPE
