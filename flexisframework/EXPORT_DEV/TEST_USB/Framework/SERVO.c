/*
 * SERVO.C
 * Set up the main CPU clock to 48 MHz.
 *  $Rev:: 50                        $:
 *  $Date:: 2011-04-20 17:02:45 -040#$:
 *  $Author:: jcdonelson             $:
 *
 * 
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "CLOCK.H"
#include "RTC.H"
#include "DIGITAL_IO.H"
#include "SERVO.H"
static SERVO_DATA* __psrv_sd;
void SRVRTCCallback(int);
#define UPDATE_CHANNEL(ch) 
void SRVRTCCallback(int counter)
{
	
	if(__psrv_sd->ChainCallback)
		__psrv_sd->ChainCallback(counter);
}
int SRVInit(SERVO_DATA* sd)
{
	__psrv_sd = sd;
	__psrv_sd->flags |= 1;
	__psrv_sd->ChainCallback = SetRTChainCallback( SRVRTCCallback );
	return 0;
}
int SRVUseChannnel(int ch)
{
	if(ch > SRV_MAX_CHANNEL)
		return -1;
	if(!__psrv_sd)
		return -2;

	__psrv_sd->channels |= (1 << ch);
	return 0;
}
void SRVSetLimits(int us_upper, int us_lower)  // Set upper and lower limits typically 550-2400
{
	if(!__psrv_sd)
		return;
	
	__psrv_sd->upper_limit = us_upper;
	__psrv_sd->lower_limit = us_lower;
}
void SRVSetUpdate(int ms_update )              // Set update time is MS.
{
	if(!__psrv_sd)
		return;
   __psrv_sd->updatetime_ms = ms_update;
}
void SRVSetPosition(int ch, int pos)        // 0-100%
{
	if(!__psrv_sd)
		return;
	if(ch > SRV_MAX_CHANNEL)
		return;
    __psrv_sd->position[ch] = __psrv_sd->lower_limit +(((__psrv_sd->upper_limit - __psrv_sd->lower_limit) * pos) / 100);
}
int SRVGettPosition(int ch)        			// 0-100%
{
	if(ch > SRV_MAX_CHANNEL)
		return -2;
	if(!__psrv_sd)
		return -1;
	return __psrv_sd->position[ch];
}
void SRVSetPositionsUS(int ch, int posUS)  	// Set position in us.
{
	if(ch > SRV_MAX_CHANNEL)
		return;
	if(!__psrv_sd)
		return;

   if( posUS > __psrv_sd->upper_limit || posUS < __psrv_sd->lower_limit )
		return;
   __psrv_sd->position[ch] = posUS;
}
int  SRVGetPositionsUS(int ch)  			// Get position in us.
{
	if(ch > SRV_MAX_CHANNEL)
		return -1;
	if(!__psrv_sd)
		return -2;

	return __psrv_sd->position[ch];
}
