#include <bur/plc.h>
#include <bur/plctypes.h>
#include <string.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include "hp1.h"
#include <dvframe.h>

_LOCAL   BOOL 		    status_read;
_LOCAL  UDINT  		 Ident;                                       
_LOCAL  UDINT* 		 SendBuffer;                                 
_LOCAL  UDINT* 		 ReadBuffer;        
_LOCAL  FRM_xopen_typ FrameXOpenStruct;    
_LOCAL XOPENCONFIG   XOpenConfigStruct;                     
_LOCAL  FRM_gbuf_typ  FrameGetBufferStruct;                 
_LOCAL FRM_rbuf_typ  FrameReleaseBufferStruct;             
_LOCAL  FRM_robuf_typ FrameReleaseOutputBufferStruct;      
_LOCAL  FRM_write_typ FrameWriteStruct;                    
_LOCAL  FRM_read_typ  FrameReadStruct;                      
_LOCAL UINT   		 StatusOpen, StatusWrite, StatusRead, StatusGetBuffer, StatusReleaseBuffer;     
_LOCAL UINT   		 SendBufferLength, ReadBufferLength, StatusReleaseOutputBuffer;
_LOCAL USINT  		 T[8], T1[8],R1[13], Error, leng, step, counter;

_LOCAL STRING  		 StringDevice[30], StringMode[40];

_GLOBAL   HP_data1   RunHP1;	
_LOCAL      HP_data1   UsrHP1;

void _INIT Init()
{
	memset(&T, 0, sizeof(T));
	memset(&R1, 0, sizeof(R1));
	memset(&F, 0, sizeof(F));
	memset(&Fr, 0, sizeof(Fr));
	memset(&U, 0, sizeof(U));
	memset(&I, 0, sizeof(I));
	memset(&T1, 0, sizeof(T1));
	status_read = 0;
	step = 1;
	leng = sizeof(T);
	Error = 0;
 
	strcpy(StringDevice, "SL1.SS2.IF1");        //   "SL1.SS2.IF1"
	strcpy(StringMode, "PHY=RS485 /BD=9600 /PA=E /DB=8 /SB=1");

	XOpenConfigStruct.idle     = 4;
	XOpenConfigStruct.delimc   = 0;
	XOpenConfigStruct.delim[0] = 0;
	XOpenConfigStruct.delim[1] = 0;
	XOpenConfigStruct.tx_cnt   = 2;
	XOpenConfigStruct.rx_cnt   = 2;
	XOpenConfigStruct.tx_len   = 256;
	XOpenConfigStruct.rx_len   = 256;
	XOpenConfigStruct.argc     = 0;
	XOpenConfigStruct.argv     = 0;

	FrameXOpenStruct.device = (UDINT) StringDevice;
	FrameXOpenStruct.mode   = (UDINT) StringMode;
	FrameXOpenStruct.config = (UDINT) &XOpenConfigStruct;
	FrameXOpenStruct.enable = 1;

	FRM_xopen(&FrameXOpenStruct);
	StatusOpen = FrameXOpenStruct.status;             
	Ident = FrameXOpenStruct.ident;                   

	if (StatusOpen != 0)                                    
	{
		Error = 1;                                
	}
}

UINT CRC(USINT *data, int length)
{
	int i, j;
	UINT CRC = 0xFFFF, bit;

	for (i = 0; i < length; i++)
	{
		CRC ^= (UINT)data[i];

		for (j = 0; j < 8 ; j++)
		{
			bit = CRC & 0x0001;
			CRC >>= 1;
			if (bit) CRC ^= 0xA001;
		}
	}
	return CRC;
}
/*функция записи команды для ПЧ при записи и чтении по Modbus RTU */
void Write(USINT s,USINT Icode,USINT A1,USINT A2,USINT D1,USINT D2)
{
	FrameGetBufferStruct.enable = 1;
	FrameGetBufferStruct.ident  = Ident;
	FRM_gbuf(&FrameGetBufferStruct);           
	SendBuffer = (UDINT*) FrameGetBufferStruct.buffer; 
	SendBufferLength = FrameGetBufferStruct.buflng; 
	StatusGetBuffer  = FrameGetBufferStruct.status;  
	
	if (StatusGetBuffer){
//		switch case
		if (s == 1)
			Alarmstatus[91] = 1;
		else if (s == 2)
			Alarmstatus[92] = 1;
		else if (s == 3)
			Alarmstatus[93] = 1;
		else if (s == 4)
			Alarmstatus[94] = 1;
		else if (s == 5)
			Alarmstatus[95] = 1;
		else if (s == 6)
			Alarmstatus[96] = 1;
	}
	if (StatusGetBuffer == 0)                             
	{		
		T[0]  = s;	    /*номер инвертора*/	
		T[1]  = Icode;  /* код инструкции 0x03 или 0х06*/		
		T[2]  = A1;	 /*начальный адрес Н/адрес регистра H*/	
		T[3]  = A2;	 /*начальный адрес L/адрес регистра L*/ 	
		T[4]  = D1;	 /*количество адресов Н/данные Н*/
		T[5]  = D2;	 /* количество адресов L/данные L*/
		T[6]  = 0x00;	 /*контрольная сумма L*/
		T[7]  = 0x00;	 /* контрольная сумма H*/
			        
		*(UINT *)(T + sizeof(T) - 2) = CRC(T, sizeof(T) - 2);
		memcpy(SendBuffer, T, sizeof (T)); 
                        
	 /*	status_read = 1;                  запрет для функции чтения*/
                        
		FrameWriteStruct.ident  = Ident;
		FrameWriteStruct.buffer = (UDINT) SendBuffer;
		FrameWriteStruct.buflng = sizeof (T);
		FrameWriteStruct.enable = 1;
		FRM_write(&FrameWriteStruct);            
		StatusWrite = FrameWriteStruct.status;  
                        
		if (StatusWrite != 0)                          
		{
			FrameReleaseOutputBufferStruct.enable = 1;
			FrameReleaseOutputBufferStruct.ident  = Ident;
			FrameReleaseOutputBufferStruct.buffer = (UDINT) SendBuffer;
			FrameReleaseOutputBufferStruct.buflng = SendBufferLength;
			FRM_robuf(&FrameReleaseOutputBufferStruct); 
			StatusReleaseOutputBuffer = FrameReleaseOutputBufferStruct.status;
			Error = 3;                    

			if (StatusReleaseOutputBuffer != 0) 
			{
				Error = 4;            
			}
		}
	}
	else
	{
		Error = 2;                            
	}
}
/* */
void Read()
{		
	USINT rr = 0;
	USINT B[2];
	FrameReadStruct.enable = 1;
	FrameReadStruct.ident = Ident;
	
	FRM_read(&FrameReadStruct);   
	
	ReadBuffer = (UDINT*) FrameReadStruct.buffer;    
	ReadBufferLength = FrameReadStruct.buflng;       
	StatusRead = FrameReadStruct.status;             
		
	if (StatusRead == 0)                              
	{
		memset(&B, 0, sizeof(B));
		memcpy(R1, ReadBuffer, sizeof(R1)); 
		*(UINT *)B = CRC(R1, sizeof(R1) - 2);
		if ((B[0] == R1[11])&&(B[1] == R1[12]))
		{		
			rr = R1[0];
			F[rr]  = 256*R1[3] + R1[4];         
			I[rr]  = 256*R1[5] + R1[6];         
			U[rr]  = 256*R1[7] + R1[8]; 
              
		} 
		FrameReleaseBufferStruct.enable = 1;
		FrameReleaseBufferStruct.ident  = Ident;
		FrameReleaseBufferStruct.buffer = (UDINT) ReadBuffer;
		FrameReleaseBufferStruct.buflng = ReadBufferLength;
		FRM_rbuf(&FrameReleaseBufferStruct);      
		StatusReleaseBuffer = FrameReleaseBufferStruct.status;  
                  
		if (StatusReleaseBuffer != 0)          
		{
			Error = 5;                     
		}
	}
}
/*функция чтения ПЧ при записи заданной частоты (06)*/
void Read_W()
{		
	USINT rr = 0;
	USINT B[2];
	FrameReadStruct.enable = 1;
	FrameReadStruct.ident = Ident;
	
	FRM_read(&FrameReadStruct);   
	
	ReadBuffer = (UDINT*) FrameReadStruct.buffer;    
	ReadBufferLength = FrameReadStruct.buflng;       
	StatusRead = FrameReadStruct.status;             
		
	if (StatusRead == 0)                              
	{
		memset(&B, 0, sizeof(B));
		memcpy(R1, ReadBuffer, sizeof(R1)); 
		*(UINT *)B = CRC(R1, sizeof(R1) - 2);
		if ((B[0] == R1[11])&&(B[1] == R1[12]))
		{		
			
			rr = R1[0];
			Fr[rr] = 256*R1[3] + R1[4]; 
		} 
		FrameReleaseBufferStruct.enable = 1;
		FrameReleaseBufferStruct.ident  = Ident;
		FrameReleaseBufferStruct.buffer = (UDINT) ReadBuffer;
		FrameReleaseBufferStruct.buflng = ReadBufferLength;
		FRM_rbuf(&FrameReleaseBufferStruct);      
		StatusReleaseBuffer = FrameReleaseBufferStruct.status;  
                  
		if (StatusReleaseBuffer != 0)          
		{
			Error = 5;                     
		}
	}
	else
	{
		Error = 6; 
	}   
}
/*функция чтения ПЧ по Modbus RTU */
void Read_R()
{
	T1[1]=0x03;
	T1[2]=0x00;
	T1[3]=0xc8;
	T1[4]=0x00;
	T1[5]=0x04;
	Write(step, T1[1] , T1[2],T1[3],T1[4],T1[5]);

	Read();
	
	RunHP1.in1.Con1_F = F[1]*0.01;//ЛЕНТА ПИТАТЕЛЯ(адрес 1)
	RunHP1.in1.Con1_U = U[1]*0.01;
	RunHP1.in1.Con1_I = I[1]*0.01;
	
	RunHP1.in1.Con2_F = F[2]*0.01; 	// тихоходный вал дробилки(адрес 2)
	RunHP1.in1.Con2_U = U[2]*0.01;
	RunHP1.in1.Con2_I = I[2]*0.01;		

	RunHP1.in1.Con3_F = F[3]*0.01;   //быстроходный вал дробилки(адрес 3)
	RunHP1.in1.Con3_U = U[3]*0.01;
	RunHP1.in1.Con3_I = I[3]*0.01;


	RunHP1.in1.Con4_F = F[4]*0.01;		//Мельница(адрес 4)
	RunHP1.in1.Con4_U = U[4]*0.1;		
	RunHP1.in1.Con4_I = I[4]*0.1;
		
	RunHP1.in1.Con5_F = F[5]*0.01;		//Фулерный насос(адрес 5)
	RunHP1.in1.Con5_U = U[5]*0.1;		
	RunHP1.in1.Con5_I = I[5]*0.1;
		
	RunHP1.in1.Con6_F = F[6]*0.01;		//Вентилятор аспирации(адрес 6)
	RunHP1.in1.Con6_U = U[6]*0.01;		
	RunHP1.in1.Con6_I = I[6]*0.01;
}  
	/*функция записи Fr в ПЧ по Modbus RTU */
void Write_Fr()
{
	T1[1]=0x06;
	T1[2]=0x00;
	T1[3]=0x0d;
	if (step==1)
	{
		T1[4]=UsrHP1.in1.Con1_Fr*100 / 256;  //ЛЕНТА ПИТАТЕЛЯ адрес 1
		T1[5]=UsrHP1.in1.Con1_Fr*100-T1[4]*256;
	}
	if (step==2)
	{
		T1[4]=UsrHP1.in1.Con2_Fr*100 / 256;  //тихоходный вал дробилки(адрес 2)
		T1[5]=UsrHP1.in1.Con2_Fr*100-T1[4]*256;
	}
	if (step==3)
	{
		T1[4]=UsrHP1.in1.Con3_Fr*100 / 256;  // быстроходный вал дробилки(адрес 3)
		T1[5]=UsrHP1.in1.Con3_Fr*100-T1[4]*256;
	}
	if (step==4)
	{
		T1[4]=UsrHP1.in1.Con4_Fr*100 / 256;   //Мельница(адрес 4)
		T1[5]=UsrHP1.in1.Con4_Fr*100-T1[4]*256;
	}
	if (step==5)
	{
		T1[4]=UsrHP1.in1.Con5_Fr*100 / 256;   //Фулерный насос(адрес 5)
		T1[5]=UsrHP1.in1.Con5_Fr*100-T1[4]*256;
	}
	if (step==6)
	{
		T1[4]=UsrHP1.in1.Con6_Fr*100 / 256;    //Вентилятор аспирации(адрес 6)
		T1[5]=UsrHP1.in1.Con6_Fr*100-T1[4]*256;
	}					
	Write(step, T1[1] , T1[2],T1[3],T1[4],T1[5]);
	Read_W();

}  

void _CYCLIC run()
{
	int counter;
	counter = 0;
	UsrHP1.in1=RunHP1.in1;

	RunHP1.in1.Con1_Fr = Fset_2;    //питатель
	RunHP1.in1.Con2_Fr = Fset_0;    //тихоходный вал дробилки(адрес 2)
	RunHP1.in1.Con3_Fr = Fset_1;    // быстроходный вал дробилки(адрес 3)
	RunHP1.in1.Con4_Fr = Fset_5;    //мельница
	RunHP1.in1.Con5_Fr = Fset_4;    // фулерный насос
	RunHP1.in1.Con6_Fr = Fset_3;     // аспирация
	
	if (step<=6)
	{
		counter++;
		if (counter<=1)
		{
			Write_Fr();
		}
		else
			if (counter <= 3)
		{	
			Read_R();	
		}	
		else
		{
			counter =0;
			step++;
		}
	} else step=1;
}  
