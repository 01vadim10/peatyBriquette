(*test*)

TYPE
	DP_typ : 	STRUCT 
		in : in_typ;
		out : out_typ;
	END_STRUCT;
	in_typ : 	STRUCT 
		ready : BOOL;
		fault : BOOL;
		cur_speed_5561 : REAL;
		cur_feed_5529 : REAL;
	END_STRUCT;
	out_typ : 	STRUCT 
		kiln_ready : BOOL;
		kiln_running : BOOL;
		kiln_fault : BOOL;
		set_speed_5561 : REAL;
		set_feed_5529 : REAL;
	END_STRUCT;
	page_typ : 	STRUCT 
		home : UINT;
		setPage : UINT;
		setPageOld : UINT;
		curPage : UINT;
		newPage : UINT;
	END_STRUCT;
	vis_typ : 	STRUCT 
		VBU_shaftIn : INT;
		VBU_shaftOut : INT;
		VBU_performFeeder : INT;
		VBU_diagnostics : INT;
		VBU_setup : INT;
	END_STRUCT;
	elmotor_typ : 	STRUCT 
		id : INT;
		run : BOOL;
		rotation : INT;
		current : INT;
		freq : INT;
		vis : USINT;
		reverse : BOOL;
	END_STRUCT;
END_TYPE
