(********************************************************************
 * COPYRIGHT -- Bernecker + Rainer
 ********************************************************************
 * Library: PB_lib
 * File: PB_lib.typ
 * Author: B+R
 ********************************************************************
 * Data types of library PB_lib
 ********************************************************************)
                                                                      
TYPE
	PBInternalStruct : STRUCT		(*internal use*)
		init	: USINT ;		
		state	: USINT ;			
		vbli_ptr	: UDINT ;		
		kr_anz	: UINT ;		
		kr	: UINT ;				
		kr_merker	: UINT ;		
		apb_ptr	: UDINT ;			
		resp_adr	: UDINT ;		
		p_out_ptr	: UDINT ;		
		time	: UDINT ;			
		nurinit	: USINT ;			
		sapli_nr	: USINT ;		
	END_STRUCT;
END_TYPE
