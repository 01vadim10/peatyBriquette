#include <astime.h>

/* time */
_GLOBAL UINT year_21;
_GLOBAL USINT month_21;
_GLOBAL USINT day_21;
_GLOBAL USINT hour_21;
_GLOBAL USINT minute_21;
_GLOBAL USINT second_21;
_GLOBAL BOOL demidov_21;

_LOCAL BOOL GetEnable;
_LOCAL UINT GetStatus;
_LOCAL BOOL SetEnable;
_LOCAL UINT SetStatus;

_LOCAL DATE_AND_TIME DT1;
_LOCAL DATE_AND_TIME DT2;

_LOCAL DTGetTime_typ      DTGetTime_1;
_LOCAL DTSetTime_typ      DTSetTime_1;

_LOCAL DTStructure    DT2Struct;
_LOCAL DTStructure    DT3Struct;
/* time end */
void SetCPUTime()
{
    DTGetTime_1.enable = GetEnable;
    DTGetTime(&DTGetTime_1);
    GetStatus = DTGetTime_1.status;
    DT1 = DTGetTime_1.DT1;

	DT2Struct.year = year_21;
	DT2Struct.month = month_21;
	DT2Struct.day = day_21;
	DT2Struct.hour = hour_21;
	DT2Struct.minute = minute_21;
	DT2Struct.second = second_21;

    DT2 = DTStructure_TO_DT((UDINT) &DT2Struct);

    DTSetTime_1.enable = SetEnable;
    DTSetTime_1.DT1 = DT2;
    DTSetTime(&DTSetTime_1);
    SetStatus = DTSetTime_1.status;
 
    DT_TO_DTStructure(DT1, (UDINT) &DT3Struct);
	SetEnable = 1;
}
