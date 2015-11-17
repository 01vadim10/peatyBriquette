(********************************************************************
 * COPYRIGHT -- Bernecker + Rainer
 ********************************************************************
 * Library: AsPROFIBUS
 * File: AsPROFIBUS.fun
 * Author: B+R
 ********************************************************************
 * Functions and function blocks of library AsPROFIBUS
 ********************************************************************)
                                                                      
FUNCTION_BLOCK PROFIBUSCommand 				(*sends PROFIBUS commands*)
	VAR_INPUT
		enable: 					BOOL; 	(*enables execution*)
		pDevice: 					UDINT; 	(*device name given as a pointer*)
		RemoteAddress: 				USINT; 	(*station address of the requested slave 0-127*)
		GroupSelect: 				USINT; 	(*command is sent to a slave group; valid values 0...FF *)
		Command: 					USINT; 	(*command to be send - see pbCMD_ definitions*)
	END_VAR
	VAR_OUTPUT
		status: 					UINT; 	(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)		
	END_VAR
	VAR
		_stateman: 					UINT;  	(*internal variable*)
		_statusbuffer: 				UINT; 	(*internal variable*)
		_bConfirm:                 USINT;   (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK PROFIBUSStart 				(*starts cyclic I/O-data exchange*)
	VAR_INPUT
		enable: 					BOOL; 	(*enables execution*)
		pDevice: 					UDINT; 	(*device name given as a pointer*)
		RemoteAddress: 				USINT; 	(*station address of the requested slave 0-127, 127 starts all slaves*)
	END_VAR
	VAR_OUTPUT
		status: 					UINT; 	(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		_stateman: 					UINT;  	(*internal variable*)
		_statusbuffer: 				UINT; 	(*internal variable*)
		_bConfirm:                 USINT;  	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK PROFIBUSStop 				(*stops cyclic I/O-data exchange*)
	VAR_INPUT
		enable: 					BOOL; 	(*enables execution*)
		pDevice: 					UDINT; 	(*device name given as a pointer; defines which master is to stop*)
		RemoteAddress: 				USINT; 	(*station address of the requested slave 0-127, 127 stops all slaves*)
	END_VAR
	VAR_OUTPUT
		status: 					UINT; 	(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		_stateman: 					UINT;  	(*internal variable*)
		_statusbuffer: 				UINT; 	(*internal variable*)
		_bConfirm:                 USINT;   (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK PROFIBUSSlaveStat 			(*reads diagnostic information for defined PROFIBUS device*)
	VAR_INPUT
		enable: 					BOOL; 	(*enables execution*)
		pDevice: 					UDINT; 	(*device name given as a pointer*)
		ExtDiagnostics:				BOOL;   (*flag if extended diagnostic text strings should be received*)
		RemoteAddress: 				USINT; 	(*station address of the requested slave 0-126*)
		pSlaveDiagData:				UDINT; 	(*pointer to the field of 244 Bytes for slave diagnostic data*)
		pSlaveExtDiagData: 			UDINT;  (*pointer to the field of ExtDiagDataLen Bytes for extended slave diagnostic data*)
		ExtDiagDataLen:				UINT; 	(*size of byte field for extended slave diagnostic data*)
	END_VAR
	VAR_OUTPUT
		status: 					UINT; 	(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		StationNotExist:			BOOL;   (*slave not responding*)
		StationNotReady:			BOOL;   (*slave not ready*)
		ConfigFault:				BOOL;   (*slave is wrong parametrized*)
		ExtDiag:					BOOL;   (*the area Ext_diag is used for extended diagnostic*)
		NotSupp:					BOOL;   (*unknown command deleted by the slave*)
		InvSlaveResponse:			BOOL;   (*inplausible response of slave*)
		PrmFault:					BOOL;   (*last parameter telegram faulty*)
		MasterLock:					BOOL;   (*slave is parameterized by another master*)
		PrmReq:						BOOL;   (*slave must be parameterized*)
		StationDiag:				BOOL;   (*get diagnostic from slave, till bit is released*)
		WatchdogOn:					BOOL;   (*watchdog activated*)
		FreezeMode:					BOOL;   (*freeze-command active*)
		SyncMode:					BOOL;   (*sync-command active*)
		Deactivated:				BOOL;   (*slave not projected*)
		ExtDiagOvfl:				BOOL;   (*the slave has more diagnostic data available than it can send*)
		MasterAddress: 				USINT;	(*contains master address of master which has parameterized the slave*)
		IdentNumber:				UINT;	(*ident number of the slave station*)
		WrittenDiagDataLen: 		UINT;	(*size of diagnostic data block that was written*)
		WrittenExtDiagDataLen:		UINT;	(*size of extended diagnostic data block that was written*)
		Error:						UINT;	(*errors that occured while processing the FUB*)
	END_VAR
	VAR
		_stateman: 					UINT;  	(*internal variable*)
		_statusbuffer: 				UINT; 	(*internal variable*)
		_bConfirm:                  USINT;  (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK PROFIBUSControl 				(*passes information from internal interface to fieldbus device driver and DMP mailbox structures*)
	VAR_INPUT
		enable: 					BOOL; 	(*enables execution*)
		pDevice: 					UDINT; 	(*device name given as a pointer*)
		InRx: 						USINT;  (*receiver*)
		InLn:						USINT;  (*size of message*)
		InA:						USINT;	(*no answer*)
		InB: 						USINT;  (*command*)
		InE:						USINT;  (*extension*)
		pData: 						UDINT; 	(*pointer to the data of DataLen BYTE*)
		DataLen:					UINT; 	(*size of byte field for extended slave diagnostic data*)
	END_VAR
	VAR_OUTPUT
		status: 					UINT; 	(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		OutTx: 						USINT;  (*transmitter*)
		OutLn:						USINT;  (*size of message*)
		OutA:						USINT;	(*answer, command*)
		OutF: 						USINT;  (*error, state*)
		OutB:						USINT;  (*no command*)
		OutE:						USINT;	(*extension*)
		WrittenDataLen: 			UINT;	(*size of data block that was written*)
		Error:						UINT;	(*errors that occured while processing the FUB*)
	END_VAR
	VAR
		_stateman: 					UINT;  	(*internal variable*)
		_statusbuffer: 				UINT; 	(*internal variable*)
		_bConfirm:                  USINT;  (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK PROFIBUSControlExt 			(*passes information from internal interface to fieldbus device driver and DMP mailbox structures*)
	VAR_INPUT
		enable: 					BOOL; 	(*enables execution*)
		pDevice: 					UDINT; 	(*device name given as a pointer*)
		InRx: 						USINT;  (*receiver*)
		InLn:						USINT;  (*size of message*)
		InA:						USINT;	(*no answer*)
		InB: 						USINT;  (*command*)
		InE:						USINT;  (*extension*)
		InDeviceAdr: 				USINT;  (*remote address 0-254*)
		InDataArea:					USINT;  (*data area*)
		InDataAdr:					UINT;	(*slot number*)
		InDataIdx: 					USINT;  (*index*)
		InDataCnt:					USINT;  (*count of data*)
		InDataType: 				USINT;  (*data type*)
		InFunction:					USINT;  (*function*)
		pData: 						UDINT; 	(*pointer to the data of DataLen BYTE*)
		DataLen:					UINT; 	(*size of byte field for extended slave diagnostic data*)
	END_VAR
	VAR_OUTPUT
		status: 					UINT; 	(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		OutTx: 						USINT;  (*transmitter*)
		OutLn:						USINT;  (*size of message*)
		OutA:						USINT;	(*answer, command*)
		OutF: 						USINT;  (*error, state*)
		OutB:						USINT;  (*no command*)
		OutE:						USINT;	(*extension*)
		OutDeviceAdr: 				USINT;  (*remote address*)
		OutDataArea:				USINT;  (*data area*)
		OutDataAdr:					UINT;	(*slot number*)
		OutDataIdx: 				USINT;  (*index*)
		OutDataCnt:					USINT;  (*count of data*)
		OutDataType: 				USINT;  (*data type*)
		OutFunction:				USINT;  (*function*)
		WrittenDataLen: 			UINT;	(*size of data block that was written*)
		Error:						UINT;	(*errors that occured while processing the FUB*)
	END_VAR
	VAR
		_stateman: 					UINT;  	(*internal variable*)
		_statusbuffer: 				UINT; 	(*internal variable*)
		_bConfirm:                  USINT;  (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK PROFIBUSDPV1AlarmReceive 	(*returns alarm information for a certain slave*)
	VAR_INPUT
		enable: 					BOOL; 	(*enables execution*)
		pDevice: 					UDINT; 	(*device name given as a pointer*)
		RemoteAddress: 				USINT; 	(*station address of the requested slave 0-126*)
		pAlarmInfo: 				UDINT;  (*pointer to the field of AlarmInfoLen bytes for alarm information*)
		AlarmInfoLen:				UINT; 	(*size of byte field for alarm information*)
	END_VAR
	VAR_OUTPUT
		status: 					UINT; 	(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		SlotNumber: 				UINT; 	(*indicates the source of the alarm 0-254, 255 reserved*)
		SeqNumber:					USINT; 	(*unique identification of alarm message 0...31*)
		WrittenAlarmInfoLen: 		USINT;	(*size of alarm information that was written*)
		AlarmType: 					USINT;  (*alarm type e.g. pull alarm 1-6, 32-126*)
		AlarmSpecAck:				USINT; 	(*additional alarm information*)
		Error:						UINT;	(*errors that occured while processing the FUB*)
	END_VAR
	VAR
		_stateman: 					UINT;  	(*internal variable*)
		_statusbuffer: 				UINT; 	(*internal variable*)
		_bConfirm:                  USINT;  (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK PROFIBUSDPV1AlarmReset 		(*acknowledges a received DPV1 alarm*)
	VAR_INPUT
		enable: 					BOOL; 	(*enables execution*)
		pDevice: 					UDINT; 	(*device name given as a pointer*)
		RemoteAddress: 				USINT; 	(*station address of the requested slave 0-126*)
		SlotNumber: 				UINT; 	(*indicates the source of the alarm 0-254, 255 reserved*)
		SeqNumber:					USINT; 	(*unique identification of alarm message 0...31*)
		AlarmType: 					USINT;  (*alarm type e.g. pull alarm 1-6, 32-126*)
		AlarmSpecAck:				USINT; 	(*additional alarm information 0-7*)
	END_VAR
	VAR_OUTPUT
		status: 					UINT; 	(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		Error:						UINT;	(*errors that occured while processing the FUB*)
	END_VAR
	VAR
		_stateman: 					UINT;  	(*internal variable*)
		_statusbuffer: 				UINT; 	(*internal variable*)
		_bConfirm:                  USINT;  (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK PROFIBUSDPV1Read 			(*reads request for a datablock is transferred to a DPV1-slave*)
	VAR_INPUT
		enable: 					BOOL; 	(*enables execution*)
		pDevice: 					UDINT; 	(*device name given as a pointer*)
		RemoteAddress: 				USINT; 	(*station address of the requested slave 0-126*)
		SlotNumber: 				UINT; 	(*destination address of the the desired data block slot 0...254*)
		Index:						USINT; 	(*index to address a data block 0...254*)
		pData: 						UDINT;  (*pointer to the field of DataLen bytes*)
		DataLen:					UINT; 	(*size of data to be read*)
	END_VAR
	VAR_OUTPUT
		status: 					UINT; 	(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		Error:						UINT;	(*errors that occured while processing the FUB*)
		ReadDataLen:				USINT;	(*size of data block that was read*)
		ErrorClass:					USINT;	(*additional error for DPV1Read -> only 4 bits are interesting*)
		ErrorCode:					USINT;	(*additional error for DPV1Read -> only 4 bits are interesting*)
		ErrorCode2:					USINT;	(*additional error for DPV1Read -> includes ErrorCode and ErrorClass -> manufacturerspecific*)
	END_VAR
	VAR
		_stateman: 					UINT;  	(*internal variable*)
		_statusbuffer: 				UINT; 	(*internal variable*)
		_bConfirm:                  USINT;  (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK PROFIBUSDPV1Write 			(*writes request for a datablock is transferred to a DPV1-slave*)
	VAR_INPUT
		enable: 					BOOL; 	(*enables execution*)
		pDevice: 					UDINT; 	(*device name given as a pointer*)
		RemoteAddress: 				USINT; 	(*station address of the requested slave 0-126*)
		SlotNumber: 				UINT; 	(*destination address of the the desired data block slot 0...254*)
		Index:						USINT; 	(*index to address a data block 0...254*)
		pData: 						UDINT;  (*pointer to the field of DataLen bytes*)
		DataLen:					UINT; 	(*size of data to be written*)
	END_VAR
	VAR_OUTPUT
		status: 					UINT; 	(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		Error:						UINT;	(*errors that occured while processing the FUB*)
		WrittenDataLen:				USINT;	(*size of data block that was written*)
		ErrorClass:					USINT;	(*additional error for DPV1Write -> only 4 bits are interesting*)
		ErrorCode:					USINT;	(*additional error for DPV1Write -> only 4 bits are interesting*)
		ErrorCode2:					USINT;	(*additional error for DPV1Write -> includes ErrorCode and ErrorClass -> manufacturerspecific*)
	END_VAR
	VAR
		_stateman: 					UINT;  	(*internal variable*)
		_statusbuffer: 				UINT; 	(*internal variable*)
		_bConfirm:                  USINT;  (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK




