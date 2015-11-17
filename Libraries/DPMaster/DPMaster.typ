(********************************************************************
 * COPYRIGHT -- Bernecker + Rainer
 ********************************************************************
 * Library: DPMaster
 * File: DPMaster.typ
 * Author: B+R
 ********************************************************************
 * Data types of library DPMaster
 ********************************************************************)
                                                                      
TYPE
	DPDevice_typ : STRUCT			(*internal use*)
		DevType	: USINT ;
		MemorySize	: USINT ;
		DevAdress	: UDINT ;
		DevInfo	: UDINT ;
		DPIdent	: UDINT ;
		DevNumber	: UINT ;
		ConfMsgNr	: USINT ;
		CommandMsgNr	: USINT ;
		StatusMsgNr	: USINT ;
		OtherMsgNr	: USINT ;
	END_STRUCT;
END_TYPE