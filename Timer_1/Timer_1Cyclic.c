#include <bur/plc.h>       /* macros for B&R PLC programming */
#include <bur/plctypes.h>
#include <standard.h>      /* prototypes for STANDARD-Library */
#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void timerManualMode(void)
{
	/* set input parameters */
	TON_01.IN = input;
	//TON_01.IN = !TON_01.Q;
	TON_01.PT = presetTime;
	/* call TON with address of instance variable */
	TON(&TON_01);
	/* read output parameters */
	output = TON_01.Q;
	elapsedTime = TON_01.ET;
}
	
_CYCLIC void cyclic(void)
{
	timerManualMode();
	/*timerCoolerDustPeatyRun(lockRunSet);
	timerShaftInRun(lockRunSet);
	timerShaftOutRun(lockRunSet);
	timerSpeedConvRun(lockRunSet);
	timerBeltFeederRun(lockRunSet);*/
}
