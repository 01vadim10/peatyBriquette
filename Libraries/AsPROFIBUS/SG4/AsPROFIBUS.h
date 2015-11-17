/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASPROFIBUS_
#define _ASPROFIBUS_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Constants */
#ifdef _REPLACE_CONST
 #define ERR_PROFIBUS_PARAMETER_NOT_FOUND 31500U
 #define ERR_PROFIBUS_HWTREE_CORRUPT 31501U
 #define ERR_PROFIBUS_ILLEGAL_PARAMETER 31502U
 #define ERR_PROFIBUS_STATIC_CONFIG 31503U
 #define ERR_PROFIBUS_COMM_STOPPED 31504U
 #define ERR_PROFIBUS_STARTUP_FAILED 31505U
 #define ERR_PROFIBUS_DATAPOINT_UNKNOWN 31506U
 #define ERR_PROFIBUS_SET_SLAVE_ADD 31507U
 #define ERR_PROFIBUS_LOAD_CONFIG 31508U
 #define ERR_PROFIBUS_MEMORY_FAILURE 31509U
 #define ERR_PROFIBUS_STATION_UNKNOWN 31510U
 #define ERR_PROFIBUS_CON_UNKNOWN 31511U
 #define ERR_PROFIBUS_FUB_TIMEOUT 31512U
 #define ERR_PROFIBUS_CON_RR 31513U
 #define ERR_PROFIBUS_CON_RS 31514U
 #define ERR_PROFIBUS_CON_NR 31515U
 #define ERR_PROFIBUS_CON_NA 31516U
 #define ERR_PROFIBUS_CON_DS 31517U
 #define ERR_PROFIBUS_CON_NP 31518U
 #define ERR_PROFIBUS_CON_AD 31519U
 #define ERR_PROFIBUS_REJ_SE 31520U
 #define ERR_PROFIBUS_REJ_ABORT 31521U
 #define ERR_PROFIBUS_REJ_PS 31522U
 #define ERR_PROFIBUS_REJ_LE 31523U
 #define ERR_PROFIBUS_REJ_IV 31524U
 #define ERR_PROFIBUS_REJ_INT 31525U
 #define ERR_PROFIBUS_REJ_SRT 31526U
 #define ERR_PROFIBUS_REJ_ENA 31527U
 #define ERR_PROFIBUS_REJ_NPD 31528U
 #define ERR_PROFIBUS_REJ_COM 31529U
 #define ERR_PROFIBUS_TASK_F_DEVICE_ADR 31530U
 #define ERR_PROFIBUS_NO_ALARM_PENDING 31531U
 #define ERR_PROFIBUS_DEVICE_NOT_FOUND 31540U
 #define ERR_PROFIBUS_DEVICE_NOT_OPENED 31541U
 #define ERR_PROFIBUS_INVALID_POINTER 31542U
 #define ERR_PROFIBUS_FB_CAL_ERROR 31543U
 #define ERR_PROFIBUS_INVALID_REMOTEADR 31544U
 #define ERR_PROFIBUS_INVALID_REMOTEADR1 31545U
 #define ERR_PROFIBUS_INVALID_DATALEN 31546U
 #define ERR_PROFIBUS_INVALID_SEQNUMBER 31547U
 #define ERR_PROFIBUS_INVALID_ALARMTYPE 31548U
 #define ERR_PROFIBUS_INVALID_ALARMSPEC 31549U
 #define pbCMD_NO_GROUP 0U
 #define pbCMD_GROUP1 1U
 #define pbCMD_GROUP2 2U
 #define pbCMD_GROUP3 4U
 #define pbCMD_GROUP4 8U
 #define pbCMD_GROUP5 16U
 #define pbCMD_GROUP6 32U
 #define pbCMD_GROUP7 64U
 #define pbCMD_GROUP8 128U
 #define pbCMD_CLEAR 2U
 #define pbCMD_UNFREEZE 4U
 #define pbCMD_FREEZE 8U
 #define pbCMD_UNSYNC 16U
 #define pbCMD_SYNC 32U
#else
 _IEC_CONST unsigned short ERR_PROFIBUS_PARAMETER_NOT_FOUND = 31500U;
 _IEC_CONST unsigned short ERR_PROFIBUS_HWTREE_CORRUPT = 31501U;
 _IEC_CONST unsigned short ERR_PROFIBUS_ILLEGAL_PARAMETER = 31502U;
 _IEC_CONST unsigned short ERR_PROFIBUS_STATIC_CONFIG = 31503U;
 _IEC_CONST unsigned short ERR_PROFIBUS_COMM_STOPPED = 31504U;
 _IEC_CONST unsigned short ERR_PROFIBUS_STARTUP_FAILED = 31505U;
 _IEC_CONST unsigned short ERR_PROFIBUS_DATAPOINT_UNKNOWN = 31506U;
 _IEC_CONST unsigned short ERR_PROFIBUS_SET_SLAVE_ADD = 31507U;
 _IEC_CONST unsigned short ERR_PROFIBUS_LOAD_CONFIG = 31508U;
 _IEC_CONST unsigned short ERR_PROFIBUS_MEMORY_FAILURE = 31509U;
 _IEC_CONST unsigned short ERR_PROFIBUS_STATION_UNKNOWN = 31510U;
 _IEC_CONST unsigned short ERR_PROFIBUS_CON_UNKNOWN = 31511U;
 _IEC_CONST unsigned short ERR_PROFIBUS_FUB_TIMEOUT = 31512U;
 _IEC_CONST unsigned short ERR_PROFIBUS_CON_RR = 31513U;
 _IEC_CONST unsigned short ERR_PROFIBUS_CON_RS = 31514U;
 _IEC_CONST unsigned short ERR_PROFIBUS_CON_NR = 31515U;
 _IEC_CONST unsigned short ERR_PROFIBUS_CON_NA = 31516U;
 _IEC_CONST unsigned short ERR_PROFIBUS_CON_DS = 31517U;
 _IEC_CONST unsigned short ERR_PROFIBUS_CON_NP = 31518U;
 _IEC_CONST unsigned short ERR_PROFIBUS_CON_AD = 31519U;
 _IEC_CONST unsigned short ERR_PROFIBUS_REJ_SE = 31520U;
 _IEC_CONST unsigned short ERR_PROFIBUS_REJ_ABORT = 31521U;
 _IEC_CONST unsigned short ERR_PROFIBUS_REJ_PS = 31522U;
 _IEC_CONST unsigned short ERR_PROFIBUS_REJ_LE = 31523U;
 _IEC_CONST unsigned short ERR_PROFIBUS_REJ_IV = 31524U;
 _IEC_CONST unsigned short ERR_PROFIBUS_REJ_INT = 31525U;
 _IEC_CONST unsigned short ERR_PROFIBUS_REJ_SRT = 31526U;
 _IEC_CONST unsigned short ERR_PROFIBUS_REJ_ENA = 31527U;
 _IEC_CONST unsigned short ERR_PROFIBUS_REJ_NPD = 31528U;
 _IEC_CONST unsigned short ERR_PROFIBUS_REJ_COM = 31529U;
 _IEC_CONST unsigned short ERR_PROFIBUS_TASK_F_DEVICE_ADR = 31530U;
 _IEC_CONST unsigned short ERR_PROFIBUS_NO_ALARM_PENDING = 31531U;
 _IEC_CONST unsigned short ERR_PROFIBUS_DEVICE_NOT_FOUND = 31540U;
 _IEC_CONST unsigned short ERR_PROFIBUS_DEVICE_NOT_OPENED = 31541U;
 _IEC_CONST unsigned short ERR_PROFIBUS_INVALID_POINTER = 31542U;
 _IEC_CONST unsigned short ERR_PROFIBUS_FB_CAL_ERROR = 31543U;
 _IEC_CONST unsigned short ERR_PROFIBUS_INVALID_REMOTEADR = 31544U;
 _IEC_CONST unsigned short ERR_PROFIBUS_INVALID_REMOTEADR1 = 31545U;
 _IEC_CONST unsigned short ERR_PROFIBUS_INVALID_DATALEN = 31546U;
 _IEC_CONST unsigned short ERR_PROFIBUS_INVALID_SEQNUMBER = 31547U;
 _IEC_CONST unsigned short ERR_PROFIBUS_INVALID_ALARMTYPE = 31548U;
 _IEC_CONST unsigned short ERR_PROFIBUS_INVALID_ALARMSPEC = 31549U;
 _IEC_CONST unsigned short pbCMD_NO_GROUP = 0U;
 _IEC_CONST unsigned short pbCMD_GROUP1 = 1U;
 _IEC_CONST unsigned short pbCMD_GROUP2 = 2U;
 _IEC_CONST unsigned short pbCMD_GROUP3 = 4U;
 _IEC_CONST unsigned short pbCMD_GROUP4 = 8U;
 _IEC_CONST unsigned short pbCMD_GROUP5 = 16U;
 _IEC_CONST unsigned short pbCMD_GROUP6 = 32U;
 _IEC_CONST unsigned short pbCMD_GROUP7 = 64U;
 _IEC_CONST unsigned short pbCMD_GROUP8 = 128U;
 _IEC_CONST unsigned short pbCMD_CLEAR = 2U;
 _IEC_CONST unsigned short pbCMD_UNFREEZE = 4U;
 _IEC_CONST unsigned short pbCMD_FREEZE = 8U;
 _IEC_CONST unsigned short pbCMD_UNSYNC = 16U;
 _IEC_CONST unsigned short pbCMD_SYNC = 32U;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct PROFIBUSCommand
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char RemoteAddress;
	unsigned char GroupSelect;
	unsigned char Command;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short _stateman;
	unsigned short _statusbuffer;
	unsigned char _bConfirm;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PROFIBUSCommand_typ;

typedef struct PROFIBUSStart
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char RemoteAddress;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short _stateman;
	unsigned short _statusbuffer;
	unsigned char _bConfirm;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PROFIBUSStart_typ;

typedef struct PROFIBUSStop
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char RemoteAddress;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short _stateman;
	unsigned short _statusbuffer;
	unsigned char _bConfirm;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PROFIBUSStop_typ;

typedef struct PROFIBUSSlaveStat
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char RemoteAddress;
	unsigned long pSlaveDiagData;
	unsigned long pSlaveExtDiagData;
	unsigned short ExtDiagDataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char MasterAddress;
	unsigned short IdentNumber;
	unsigned short WrittenDiagDataLen;
	unsigned short WrittenExtDiagDataLen;
	unsigned short Error;
	/* VAR (analog) */
	unsigned short _stateman;
	unsigned short _statusbuffer;
	unsigned char _bConfirm;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit ExtDiagnostics;
	/* VAR_OUTPUT (digital) */
	plcbit StationNotExist;
	plcbit StationNotReady;
	plcbit ConfigFault;
	plcbit ExtDiag;
	plcbit NotSupp;
	plcbit InvSlaveResponse;
	plcbit PrmFault;
	plcbit MasterLock;
	plcbit PrmReq;
	plcbit StationDiag;
	plcbit WatchdogOn;
	plcbit FreezeMode;
	plcbit SyncMode;
	plcbit Deactivated;
	plcbit ExtDiagOvfl;
} PROFIBUSSlaveStat_typ;

typedef struct PROFIBUSControl
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char InRx;
	unsigned char InLn;
	unsigned char InA;
	unsigned char InB;
	unsigned char InE;
	unsigned long pData;
	unsigned short DataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char OutTx;
	unsigned char OutLn;
	unsigned char OutA;
	unsigned char OutF;
	unsigned char OutB;
	unsigned char OutE;
	unsigned short WrittenDataLen;
	unsigned short Error;
	/* VAR (analog) */
	unsigned short _stateman;
	unsigned short _statusbuffer;
	unsigned char _bConfirm;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PROFIBUSControl_typ;

typedef struct PROFIBUSControlExt
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char InRx;
	unsigned char InLn;
	unsigned char InA;
	unsigned char InB;
	unsigned char InE;
	unsigned char InDeviceAdr;
	unsigned char InDataArea;
	unsigned short InDataAdr;
	unsigned char InDataIdx;
	unsigned char InDataCnt;
	unsigned char InDataType;
	unsigned char InFunction;
	unsigned long pData;
	unsigned short DataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char OutTx;
	unsigned char OutLn;
	unsigned char OutA;
	unsigned char OutF;
	unsigned char OutB;
	unsigned char OutE;
	unsigned char OutDeviceAdr;
	unsigned char OutDataArea;
	unsigned short OutDataAdr;
	unsigned char OutDataIdx;
	unsigned char OutDataCnt;
	unsigned char OutDataType;
	unsigned char OutFunction;
	unsigned short WrittenDataLen;
	unsigned short Error;
	/* VAR (analog) */
	unsigned short _stateman;
	unsigned short _statusbuffer;
	unsigned char _bConfirm;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PROFIBUSControlExt_typ;

typedef struct PROFIBUSDPV1AlarmReceive
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char RemoteAddress;
	unsigned long pAlarmInfo;
	unsigned short AlarmInfoLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned short SlotNumber;
	unsigned char SeqNumber;
	unsigned char WrittenAlarmInfoLen;
	unsigned char AlarmType;
	unsigned char AlarmSpecAck;
	unsigned short Error;
	/* VAR (analog) */
	unsigned short _stateman;
	unsigned short _statusbuffer;
	unsigned char _bConfirm;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PROFIBUSDPV1AlarmReceive_typ;

typedef struct PROFIBUSDPV1AlarmReset
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char RemoteAddress;
	unsigned short SlotNumber;
	unsigned char SeqNumber;
	unsigned char AlarmType;
	unsigned char AlarmSpecAck;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned short Error;
	/* VAR (analog) */
	unsigned short _stateman;
	unsigned short _statusbuffer;
	unsigned char _bConfirm;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PROFIBUSDPV1AlarmReset_typ;

typedef struct PROFIBUSDPV1Read
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char RemoteAddress;
	unsigned short SlotNumber;
	unsigned char Index;
	unsigned long pData;
	unsigned short DataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned short Error;
	unsigned char ReadDataLen;
	unsigned char ErrorClass;
	unsigned char ErrorCode;
	unsigned char ErrorCode2;
	/* VAR (analog) */
	unsigned short _stateman;
	unsigned short _statusbuffer;
	unsigned char _bConfirm;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PROFIBUSDPV1Read_typ;

typedef struct PROFIBUSDPV1Write
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char RemoteAddress;
	unsigned short SlotNumber;
	unsigned char Index;
	unsigned long pData;
	unsigned short DataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned short Error;
	unsigned char WrittenDataLen;
	unsigned char ErrorClass;
	unsigned char ErrorCode;
	unsigned char ErrorCode2;
	/* VAR (analog) */
	unsigned short _stateman;
	unsigned short _statusbuffer;
	unsigned char _bConfirm;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PROFIBUSDPV1Write_typ;



/* Prototyping of functions and function blocks */
void PROFIBUSCommand(struct PROFIBUSCommand* inst);
void PROFIBUSStart(struct PROFIBUSStart* inst);
void PROFIBUSStop(struct PROFIBUSStop* inst);
void PROFIBUSSlaveStat(struct PROFIBUSSlaveStat* inst);
void PROFIBUSControl(struct PROFIBUSControl* inst);
void PROFIBUSControlExt(struct PROFIBUSControlExt* inst);
void PROFIBUSDPV1AlarmReceive(struct PROFIBUSDPV1AlarmReceive* inst);
void PROFIBUSDPV1AlarmReset(struct PROFIBUSDPV1AlarmReset* inst);
void PROFIBUSDPV1Read(struct PROFIBUSDPV1Read* inst);
void PROFIBUSDPV1Write(struct PROFIBUSDPV1Write* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASPROFIBUS_ */

                                                           
