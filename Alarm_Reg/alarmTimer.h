/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: Alarm_Reg
 * File: alarmTimer.h
 * Author: str
 * Created: December 05, 2013
 *******************************************************************/

#include <bur/plctypes.h>
#include <bur/plc.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

	/*Участок дробления. Таймеры*/
BOOL timerCoolerDustPeatyRun(const TIME presetTimeTimer)
{
	coolerDustPeatyTON.IN = !coolerDustPeatyTON.Q;
	coolerDustPeatyTON.PT = presetTimeTimer;
	TON(&coolerDustPeatyTON);
	return coolerDustPeatyTON.Q;
}

BOOL timerMaxLevelBunkerRun(const TIME presetTimeTimer)
{
	maxLevelBunkerTON.IN = !maxLevelBunkerTON.Q;
	maxLevelBunkerTON.PT = presetTimeTimer;
	TON(&maxLevelBunkerTON);
	return maxLevelBunkerTON.Q;
}

BOOL timerHighLevelBunkerRun(const TIME presetTimeTimer)
{
	highLevelBunkerTON.IN = !highLevelBunkerTON.Q;
	highLevelBunkerTON.PT = presetTimeTimer;
	TON(&highLevelBunkerTON);
	return highLevelBunkerTON.Q;
}

BOOL timerBeltDownRun(const TIME presetTimeTimer)
{
	beltDownTON.IN = !beltDownTON.Q;
	beltDownTON.PT = presetTimeTimer;
	TON(&beltDownTON);
	return beltDownTON.Q;
}

BOOL timerSpeedElevatorRun(const TIME presetTimeTimer)
{
	speedElevatorTON.IN = !speedElevatorTON.Q;
	speedElevatorTON.PT = presetTimeTimer;
	TON(&speedElevatorTON);
	return speedElevatorTON.Q;
}

BOOL timerMinCoolerDustPeatyRun(const TIME presetTimeTimer)
{
	minCoolerDustPeatyTON.IN = !minCoolerDustPeatyTON.Q;
	minCoolerDustPeatyTON.PT = presetTimeTimer;
	TON(&minCoolerDustPeatyTON);
	return minCoolerDustPeatyTON.Q;
}

BOOL timerShaftInRun(const TIME presetTimeTimer)
{
	shaftInTON.IN = !shaftInTON.Q;
	shaftInTON.PT = presetTimeTimer;
	TON(&shaftInTON);
	return shaftInTON.Q;
}

BOOL timerShaftOutRun(const TIME presetTimeTimer)
{
	shaftOutTON.IN = !shaftOutTON.Q;
	shaftOutTON.PT = presetTimeTimer;
	TON(&shaftOutTON);
	return shaftOutTON.Q;
}

BOOL timerSpeedConvRun(const TIME presetTimeTimer)
{
	speedConvTON.IN = !speedConvTON.Q;
	speedConvTON.PT = presetTimeTimer;
	TON(&speedConvTON);
	return speedConvTON.Q;
}

BOOL timerBeltFeederRun(const TIME presetTimeTimer)
{
	beltFeederTON.IN = !beltFeederTON.Q;
	beltFeederTON.PT = presetTimeTimer;
	TON(&beltFeederTON);

	return beltFeederTON.Q;
}

 /*Участок помола*/
BOOL timerPumpPneumRun(const TIME presetTimeTimer)
{
	pumpPneumTON.IN = !pumpPneumTON.Q;
	pumpPneumTON.PT = presetTimeTimer;
	TON(&pumpPneumTON);
	return pumpPneumTON.Q;
}

BOOL timerMinPumpPneumRun(const TIME presetTimeTimer)
{
	minPumpPneumTON.IN = !minPumpPneumTON.Q;
	minPumpPneumTON.PT = presetTimeTimer;
	TON(&minPumpPneumTON);
	return minPumpPneumTON.Q;
}

BOOL timerMaxPumpPneumRun(const TIME presetTimeTimer)
{
	maxPumpPneumTON.IN = !maxPumpPneumTON.Q;
	maxPumpPneumTON.PT = presetTimeTimer;
	TON(&maxPumpPneumTON);
	return maxPumpPneumTON.Q;
}

BOOL timerMillRun(const TIME presetTimeTimer)
{
	millTON.IN = !millTON.Q;
	millTON.PT = presetTimeTimer;
	TON(&millTON);
	return millTON.Q;
}

BOOL timerTempMaxMillRun(const TIME presetTimeTimer)
{
	tempMaxMillTON.IN = !tempMaxMillTON.Q;
	tempMaxMillTON.PT = presetTimeTimer;
	TON(&tempMaxMillTON);
	return tempMaxMillTON.Q;
}

BOOL timerTempMaxBunkerRun(const TIME presetTimeTimer)
{
	tempMaxBunkerTON.IN = !tempMaxBunkerTON.Q;
	tempMaxBunkerTON.PT = presetTimeTimer;
	TON(&tempMaxBunkerTON);
	return tempMaxBunkerTON.Q;
}

BOOL timerValveExplRun(const TIME presetTimeTimer)
{
	valveExplTON.IN = !valveExplTON.Q;
	valveExplTON.PT = presetTimeTimer;
	TON(&valveExplTON);
	return valveExplTON.Q;
}
