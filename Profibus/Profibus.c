#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif

#include 	<AsL2DP.h> 		
#include 	<string.h> 	

#define RM8732E_COUNT       23                      // Количество расходомеров Rosemount 8732E
#define RM8732E_VARSIZE     5                       // Размер переменной, читаемой с прибора
#define RM8732E_VARCOUNT    2                       // Количество переменных, читаемых с прибора
                                                    //  - расход
                                                    //  - сумматор
#define RM8732E_BUFSIZE     RM8732E_COUNT * RM8732E_VARSIZE * RM8732E_VARCOUNT   // Размер буфера чтения с расходомеров

/*Преобразование из 16-го вида в REAL тип по стандарту IEEE 754*/
REAL convert_value (const BYTE* src)
{
	DWORD d0 = src[0];
	DWORD d1 = src[1];
	DWORD d2 = src[2];
	DWORD d3 = src[3];
	DWORD r  = d3 | (d2 << 8) | (d1 << 16) | (d0 << 24);
	return *(REAL*)&r;
}

/*Преобразование из REAL типа в 16-й вид по стандарту IEEE 754*/
UDINT convert_valueR (const REAL r, BYTE * src)
{
	UDINT out;
	out = *(UDINT*)&r;
	src[0] = out >> 24;
	src[1] = out >> 16;
	src[2] = out >> 8;
	src[3] = out;
	return 0;
}
/* initialize program */
void _INIT AsL2DP_test (void)
{
	/* init in */
	outBuffer[0] = 0;
	outBuffer[1] = 0x08;
	outBuffer[2] = 0;
	outBuffer[3] = 0;
	outBuffer[9] = 0x10;
} 			/* end INIT DP */

/* cyclic program */
void _CYCLIC AsL2DP_test_cyclic (void)
{
	res2[3] = W_dozatorSchenck;
	int i;
	for (i = 3; i < 8; i++){
		res[i] = convert_value(buffer + i*4);
		convert_valueR(res2[i], outBuffer + i*4);
	}
	dozator_I = res[3];
	dozator_Z1 = res[4];
	dozator_Q = res[5];
	dozator_v = res[6];
	dozator_P = res[7];
	int buf_offset = 0;
	int ai_offset  = 0;
	for (i = 0; i < RM8732E_COUNT; ++i)
	{
		weight_data.volume_flow  = convert_value (buffer + buf_offset);
		weight_data.volume_total = convert_value (buffer + buf_offset + RM8732E_VARSIZE);
        
		buf_offset += RM8732E_VARSIZE * RM8732E_VARCOUNT;
		ai_offset  += 1;
	}

}
