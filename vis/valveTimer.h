/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: vis
 * File: valveTimer.h
 * Author: Admin
 * Created: January 22, 2014
 *******************************************************************/

#include <bur/plctypes.h>
#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void valveY1Timer(void)
{
	valveY1T.IN = !valveY1T.Q;
	valveY1T.PT = 1000000;
	TON(&valveY1T);
	valveY1TSec = valveY1T.ET / 1000;
}

void valveY2Timer(void)
{
	valveY2T.IN = !valveY2T.Q;
	valveY2T.PT = 1000000;
	TON(&valveY2T);
	valveY2TSec = valveY2T.ET / 1000;
}

void valveY3Timer(void)
{
	valveY3T.IN = !valveY3T.Q;
	valveY3T.PT = 1000000;
	TON(&valveY3T);
	valveY3TSec = valveY3T.ET / 1000;
}

void valveY4Timer(void)
{
	valveY4T.IN = !valveY4T.Q;
	valveY4T.PT = 1000000;
	TON(&valveY4T);
	valveY4TSec = valveY4T.ET / 1000;
}

BOOL stopCoolerBeltFeeder(const TIME presetTime)
{
	coolerBeltFeederTON.IN = !coolerBeltFeederTON.Q;
	coolerBeltFeederTON.PT = presetTime;
	TON(&coolerBeltFeederTON);
	
	return coolerBeltFeederTON.Q;
}

BOOL stopCoolerShaftOut(const TIME presetTime)
{
	coolerShaftOutTON.IN = !coolerShaftOutTON.Q;
	coolerShaftOutTON.PT = presetTime;
	TON(&coolerShaftOutTON);
	
	return coolerShaftOutTON.Q;
}

BOOL stopCoolerShaftIn(const TIME presetTime)
{
	coolerShaftInTON.IN = !coolerShaftInTON.Q;
	coolerShaftInTON.PT = presetTime;
	TON(&coolerShaftInTON);
	
	return coolerShaftInTON.Q;
}

BOOL lowBatcherCapacityTimer(const TIME presetTime)
{
	lowBatcherCapacityTON.IN = !lowBatcherCapacityTON.Q;
	lowBatcherCapacityTON.PT = presetTime;
	TON(&lowBatcherCapacityTON);
	
	return lowBatcherCapacityTON.Q;
}
