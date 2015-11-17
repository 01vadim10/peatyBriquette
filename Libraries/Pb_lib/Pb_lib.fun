(********************************************************************
 * COPYRIGHT -- Bernecker + Rainer
 ********************************************************************
 * Library: PB_lib
 * File: PB_lib.fun
 * Author: B+R
 ********************************************************************
 * Functions and function blocks of library PB_lib
 ********************************************************************)
                                                                      
FUNCTION_BLOCK PBreadI 					(*reads variable / variables list via index*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station to be read from*)
		index	:UINT;					(*PROFIBUS index of the variable or variables list to be read from the target station*)
		subindex	:UINT;				(*subindex of the variable to be read from the target station*)
		data	:UDINT;					(*pointer to the data buffer in which the read data is stored*)
		len	:UINT;						(*size of the data data buffer in bytes*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBreadN 					(*reads variable / variables list via name*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station to be read from*)
		spec_id	:USINT;					(*1 ... name of a process variable, 2 ... name of a variables list*)
		name	:UDINT;					(*name of the process variable (PV name) or name of the variables list on the target station*)
		subindex	:UINT;				(*subindex of the variable to be read from the target station*)
		data	:UDINT;					(*pointer to the data buffer in which the read data is stored*)
		len	:UINT;						(*size of the data data buffer in bytes*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBwriteI 				(*writes variable/variable list via index*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference*)
		index	:UINT;					(*PROFIBUS index of the variable or variables list to be written to the target station*)
		subindex	:UINT;				(*subindex of the variable to be written to the target station*)
		data	:UDINT;					(*pointer to the data buffer in which the data to be written is stored*)		
		len	:UINT;						(*length of the data to be written (in bytes)*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBwriteN 				(*writes variable/variable lists via name*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference*)
		spec_id	:USINT;					(*1 ... name of a process variable, 2 ... name of a variables list*)
		name	:UDINT;					(*name of the process variable or name of the variables list on the target station*)
		subindex	:UINT;				(*subindex of the variable to be written to the target station*)
		data	:UDINT;					(*pointer to the data buffer in which the data to be written is stored*)
		len	:UINT;						(*length of the data to be written (in bytes)*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBwriteP 				(*writes variable via physical address*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference*)
		phy_adr	:UDINT;					(*physical address of the variable on the target station*)
		data	:UDINT;					(*pointer to the data buffer in which the data to be written is stored*)
		len	:UINT;						(*length of the data to be written (in bytes)*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
		phy_adr_merker	:UDINT;			(*internal variable*)
		data_ptr	:UDINT;				(*internal variable*)
		restlen	:UINT;					(*internal variable*)
		paket_len	:USINT;				(*internal variable*)
		req_len	:USINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBreadP 					(*reads variable via physical address*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station to be read from*)
		phy_adr	:UDINT;					(*physical address of the variable on the target station*)
		data	:UDINT;					(*pointer to the data buffer in which the read data is stored*)
		len	:UINT;						(*length of the data to be read in bytes*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
		phy_adr_merker	:UDINT;			(*internal variable*)
		data_ptr	:UDINT;				(*internal variable*)
		restlen	:UINT;					(*internal variable*)
		paket_len	:USINT;				(*internal variable*)
		req_len	:USINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBautoKR 				(*makes or breaks connection*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates connection to be established or broken*)
		onoff	:USINT;					(*1 ... establish connection, 0 ... break connection*)
	END_VAR	
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBinfoKR 				(*queries connection information*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		name	:UDINT;					(*symbolic name of the desired connection from the communication relations list*)
		info_ptr	:UDINT;				(*pointer to the KR structure in which additional information about the desired connection is stored*)
	END_VAR
	VAR_OUTPUT
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		kr	:UINT;						(*communication reference (logical connection number) for the specified symbolic name*)
	END_VAR	
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBrdDVL 					(*reads variables via dynamic variables list*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station to be read from*)
		liste	:UDINT;					(*address of the dynamic variables list (UINT or UDINT array)*)
		anzahl	:USINT;					(*number of variables in the variables list*)
		ind_phy	:USINT;					(*0 ... list with PROFIBUS indices (UINT array), 1 ... list with physical addresses (UDINT array)*)
		data	:UDINT;					(*pointer to the data buffer in which the read data is stored*)
		len	:UINT;						(*length of the data to be read (in bytes)*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		rdlen	:UINT;					(*length of the read data in bytes*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBreadX 					(*reads variable in extended mode (longer than a frame)*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station to be read from*)
		offset	:UINT;					(*offset (relative to the variable address) from which the read operation is to start*)
		name	:UDINT;					(*name of the process variable (PV name) on the target station*)
		data	:UDINT;					(*pointer to the data buffer in which the read data is stored*)
		len	:UINT;						(*length of the data to be read in bytes*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
		phy_adr	:UDINT;					(*internal variable*)
		phy_adr_merker	:UDINT;			(*internal variable*)
		data_ptr	:UDINT;				(*internal variable*)
		restlen	:UINT;					(*internal variable*)
		paket_len	:USINT;				(*internal variable*)
		req_len	:USINT;					(*internal variable*)
		name_merker	:USINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBrec 					(*receives telegrams*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		par_ptr	:UDINT;					(*pointer to the structure where the parameters of the received services are placed*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready or an error (error_nr) has occurred, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		dat_ptr	:UDINT;					(*pointer to the data received with this service*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBevnotI 				(*executes an event notification service*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) for the target station*)
		index	:UINT;					(*PROFIBUS index for the event object to be sent*)
		ev_nr	:USINT;					(*event number*)
		data	:UDINT;					(*event information to be sent*)
		len	:UINT;						(*length of the event information in bytes*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBdelVLN 				(*deletes variables list via name*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) for the target station*)
		name	:UDINT;					(*pointer to the name of the variables list to be deleted*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBrdDPR 					(*reads memory from the reserved DPR area*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station to be read from*)
		offset	:UINT;					(*offset in the target station DPR (dual ported RAM)*)
		data	:UDINT;					(*pointer to the data buffer in which the read data is stored*)
		len	:UINT;						(*length of the data to be read in bytes*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
		phy_adr_merker	:UDINT;			(*internal variable*)
		data_ptr	:UDINT;				(*internal variable*)
		restlen	:UINT;					(*internal variable*)
		paket_len	:USINT;				(*internal variable*)
		req_len	:USINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBinit 					(*initializes all structures in the network controller DPR*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		srv_cnt	:UINT;					(*number of buffers to be reserved*)
		memsize	:UDINT;					(*size of the memory area to be reserved for the user in the network controller DPR*)
		par_ptr	:UDINT;					(*parameter has no function at present so must always be assigned the value 0*)
	END_VAR
	VAR_OUTPUT
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		memadr	:UDINT;					(*address of the memory area (in the network controller DPR) available for the user*)
	END_VAR
	VAR
		init	:USINT;					(*internal variable*)
		nurinit	:USINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBwriteX 				(*writes variable extended (longer than a frame)*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station to be read from*)
		offset	:UINT;					(*offset (relative to the variable address) from which the write operation is to start*)
		name	:UDINT;					(*name of the process variable (PV name) or name of the variables list on the target station*)
		data	:UDINT;					(*pointer to the data buffer in which the data to be written is stored*)
		len	:UINT;						(*length of the data to be written (in bytes)*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
		phy_adr	:UDINT;					(*internal variable*)
		phy_adr_merker	:UDINT;			(*internal variable*)
		data_ptr	:UDINT;				(*internal variable*)
		restlen	:UINT;					(*internal variable*)
		paket_len	:USINT;				(*internal variable*)
		req_len	:USINT;					(*internal variable*)
		name_merker	:USINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBdlI 					(*downloads by index*)
	VAR_INPUT	
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station*)
		index	:UINT;					(*PROFIBUS index of the memory area on the target station to which the B&R module is to be transferred*)
		modptr	:UDINT;					(*physical address of the B&R module to be uploaded onto the target station*)
		modlen	:UDINT;					(*total length of the B&R module in bytes*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
		data_ptr	:UDINT;				(*internal variable*)
		restlen	:UDINT;					(*internal variable*)
		paket_len	:USINT;				(*internal variable*)
		req_len	:USINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBkeyena 				(*enables key stroke*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		ena_ptr	:UDINT;					(*bit = 1 ... signal keystroke to the target system, bit = 0 ... store key status in the flag map*)
		len	:UINT;						(*length of the ena_ptr USINT array*)
	END_VAR
	VAR_OUTPUT
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBkeyon 					(*calls key status*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		key_ptr	:UDINT;					(*bit = 1 ... key has been pressed, Bit = 0 ... key has not been pressed*)
		len	:UINT;						(*length of the key_ptr USINT array*)
	END_VAR
	VAR_OUTPUT
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBwrDPR 					(*writes memory in reserved DPR area*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		offset	:UINT;					(*offset in the target station DPR (dual ported RAM)*)
		data	:UDINT;					(*pointer to the data buffer in which the data to be written is stored*)
		len	:UINT;						(*length of the data to be written (in bytes)*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
		phy_adr_merker	:UDINT;			(*internal variable*)
		data_ptr	:UDINT;				(*internal variable*)
		restlen	:UINT;					(*internal variable*)
		paket_len	:USINT;				(*internal variable*)
		req_len	:USINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBsyncKR 				(*reads sync counter for a connection*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		dir	:USINT;						(*0 ... read receive sync counter, 1 ... read send sync counter*)
	END_VAR
	VAR_OUTPUT
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		count	:USINT;					(*current counter value of the receive sync counter (dir = 0) or the send sync counter (dir = 1)*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBdlN 					(*downloads by name*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		modname	:UDINT;					(*PROFIBUS name of the memory area on the target station to which the B&R module is to be transferred*)
		modptr	:UDINT;					(*physical address of the B&R module (software object or data object) to be uploaded onto the target station*)
		modlen	:UDINT;					(*total length of the B&R module in bytes*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
		data_ptr	:UDINT;				(*internal variable*)
		restlen	:UDINT;					(*internal variable*)
		paket_len	:USINT;				(*internal variable*)
		req_len	:USINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBgetOVM 				(*gets object description for multiple object*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station*)
		startind	:UINT;				(*PROFIBUS index starting from which the object descriptions are to be read from the target station*)
		ovliste	:UDINT;					(*address of a structure array containing the pointers to the individual object descriptions read*)
		maxobj	:USINT;					(*maximum number of object descriptions that can be read (list must not exceed this length)*)
		long_ver	:USINT;				(*two formats for the object description: 0 ... short version, 1 ... long version*)
		data	:UDINT;					(*pointer to the data buffer in which the read data (object description) is stored*)
		len	:UINT;						(*size of the data data buffer in bytes*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		obj_cnt	:USINT;					(*number of read objects*)
		morefoll	:USINT;				(*there are more objects to follow*)
	END_VAR
	VAR	
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBgetOVN 				(*gets object description via name*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station*)
		spec_id	:USINT;					(*1 ... name of a process variable, 2 ... name of a variables list, 3 ... domain name, ...*)
		name	:UDINT;					(*name of the object on the target station (parameter is given as a pointer to the string)*)
		long_ver	:USINT;				(*two formats for the object description: 0 ... short version, 1 ... long version*)
		data	:UDINT;					(*pointer to the data buffer in which the read data (object description) is stored*)
		len	:UINT;						(*size of the data data buffer in bytes*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		obj_len	:USINT;					(*length of the read data (object description) in bytes*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBgetOVI 				(*gets object description via index*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) indicates the target station*)
		index	:UINT;					(*PROFIBUS index of the object description to be read from the target station*)
		long_ver	:USINT;				(*two formats for the object description: 0 ... short version, 1 ... long version*)
		data	:UDINT;					(*pointer to data buffer in which the read data (object description) is stored*)
		len	:UINT;						(*size of the data data buffer in bytes*)
	END_VAR		
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		obj_len	:USINT;					(*length of the read data (object description) in bytes*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBdelVLI 				(*deletes variables list via index*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		index	:UINT;					(*PROFIBUS index for the variables list to be deleted*)
	END_VAR	
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBstatKR 				(*queries connection status*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
	END_VAR			
	VAR_OUTPUT
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		status	:USINT;					(*current status of connection: e.g. 0x00 ... connection broken, ...*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBirepI 					(*executes an information report service*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) for the target station*)
		index	:UINT;					(*PROFIBUS index for the variable to be sent*)
		subindex	:UINT;				(*subindex for the variable to be sent*)
		data	:UDINT;					(*variable to be sent*)
		len	:UINT;						(*length of the data data in bytes*)
	END_VAR	
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBdefVLI 				(*defines variables list via index*)	
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		liste	:UDINT;					(*address of the dynamic variables list (UINT array)*)
		anzahl	:USINT;					(*number of variables in the variables list*)
		pw	:USINT;						(*PROFIBUS password for the new variables list (default value = 0)*)
		group	:USINT;					(*PROFIBUS group (access group) to which the new variables list is to belong*)
		rights	:UINT;					(*PROFIBUS access rights for the new variables list (default value = 0x33)*)
		name	:UDINT;					(*name of the new variables list (parameter is given as a pointer to the string)*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		newindex	:UINT;				(*PROFIBUS index for the new variables list*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBdefVLN 				(*defines variables list via name*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		liste	:UDINT;					(*address of the dynamic variables list (UDINT array)*)
		anzahl	:USINT;					(*number of variables in the variables list*)
		pw	:USINT;						(*PROFIBUS password for the new variables list (default value = 0)*)
		group	:USINT;					(*PROFIBUS group (access group) to which the new variables list is to belong*)
		rights	:UINT;					(*PROFIBUS access rights for the new variables list (default value = 0x33)*)
		name	:UDINT;					(*name of the new variables list (parameter is given as a pointer to the string)*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		newindex	:UINT;				(*PROFIBUS index for the new variables list*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBwrDVL 					(*writes variables via dynamic variables list*)	
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		liste	:UDINT;					(*address of the dynamic variables list*)
		anzahl	:USINT;					(*number of variables in the variables list*)
		ind_phy	:USINT;					(*0 ... list with PROFIBUS indices (UINT array), 1 ... list with physical addresses (UDINT array)*)
		data	:UDINT;					(*pointer to the data buffer in which the data to be written is stored*)
		len	:UINT;						(*length of the data to be written (in bytes)*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR	
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBustat 					(*sends status telegram*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number) for the target station*)
		log_stat	:USINT;				(*logical status*)
		phy_stat	:USINT;				(*physical status*)
		ld_ptr	:UDINT;					(*pointer to the local detail (detailed information)*)
	END_VAR
	VAR_OUTPUT	
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBackevI 				(*acknowledges an event notification service by PROFIBUS index*)
	VAR_INPUT	
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		index	:UINT;					(*PROFIBUS index for the event object*)
		ev_nr	:USINT;					(*event number*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBaltevI 				(*executes an alter event condition monitoring service by PROFIBUS index*)	
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		kr	:UINT;						(*communication reference (logical connection number, see PBinfoKR() function block)*)
		index	:UINT;					(*PROFIBUS index for the event object*)
		ev_en	:USINT;					(*event enable: 0xFF ... enable event, 0x00 ... disable event*) 
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK PBsend 					(*sends telegrams*)	
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		par_ptr	:UDINT;					(*pointer to the par structure*)
		send_ptr	:UDINT;				(*pointer to the send data*)
	END_VAR
	VAR_OUTPUT
		ready	:BOOL;					(*0 ... service is not ready or an error (error_nr) has occurred, 1 ... service is ready*)
		error_nr	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)	
		rec_ptr	:UDINT;					(*pointer to the incoming data (if any is delivered by the activated service)*)
	END_VAR
	VAR
		StaticStruct	:PBInternalStruct;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
