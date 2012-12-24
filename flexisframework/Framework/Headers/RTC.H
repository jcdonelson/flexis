/*
 * RTC.H
 *
 *  $Rev:: 165                       $:
 *  $Date:: 2012-09-08 22:16:07 -040#$:
 *  $Author:: jcdonelson             $:
 */

#ifndef RTC_H_
#define RTC_H_
typedef void (*PFNRTCCB) (void) ;
typedef void (*PFNRTCCB_I) (int counter) ;
void InitRTC(void);
void RTCSetPeriod(int us);
int RTCGetPeriod();
#define RTC_1MS			11
#define RTC_500US    	5
#define RTC_250US		2
void InitRTCInternalClock(void);
void RTC_msDelay(unsigned int ms);
// Use this call for chaining.
PFNRTCCB GetRTCUserCallback();
// Set a pointer to a function to callback each ms.
void SetRTCUserCallback( void(*uc)(void) );
PFNRTCCB_I SetRTChainCallback( void(*uc)(int) );
#define RTC_LPO_1000MS		15
#define RTC_LPO_100MS		13
#define RTC_LPO_10MS		11
#define RTC_LPO_2MS			9
#define RTC_LPO_1MS		    8

void RTCSetPeriodLPO(int us);

#endif /* RTC_H_ */
