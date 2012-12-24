/*
 *  SERVO.H
 *  Support for RC Servos.
 *
 *  $Rev:: 49                        $:
 *  $Date:: 2011-04-18 13:39:56 -040#$:
 *  $Author:: jcdonelson             $:
*/

#ifndef SERVO_H_
#define SERVO_H_
#define SRV_MAX_CHANNEL 8

#define SRV_DECALARE_DATA() SERVO_DATA __srv_data={2400,600,20} 
#define SRV_DATA &__srv_data

typedef struct {
	int upper_limit;
	int lower_limit;
	int updatetime_ms;
	int position[SRV_MAX_CHANNEL];
	byte flags;
	byte channels;
	PFNRTCCB_I ChainCallback;
} SERVO_DATA;
extern SERVO_DATA __srv_data;
int SRVInit(SERVO_DATA* sd);
int SRVUseChannnel(int ch);
void SRVSetLimits( int us_upper, int us_lower);  // Set upper and lower limits typically 550-2400
void SRVSetUpdate(int ms_update );              // Set update time is MS.
void SRVSetPosition(int ch, int pos);        // 0-100%
int SRVGettPosition(int ch);        			// 0-100%
void SRVSetPositionsUS(int ch, int posUS);  	// Set position in us.
int  SRVGetPositionsUS(int ch);  			// Get position in us.
#endif // Header stop
