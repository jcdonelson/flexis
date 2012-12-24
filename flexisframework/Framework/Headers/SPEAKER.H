/*
 *  SPEAKER.H
 *  Support for the internal speaker on FB32 and NANO32
 *  $Rev:: 46                        $:
 *  $Date:: 2011-04-18 09:41:32 -040#$:
 *  $Author:: jcdonelson             $:
 */

#ifndef SPEAKER_H_
#define SPEAKER_H_
typedef struct _song {
	byte note;
	byte octave;
	byte duration;
} SONG;

void SpeakerInit(void);
void SpeakerON(void);
void SpeakerOFF(void);
void SetFrequencySpeaker(dword f_times_10);
byte PlayNote(byte which, byte octave);

// This will be called on the RTC thread.
void SetOnSongDoneCallback(void (*cb) (void));
// This must be called from the RTC interrupt
void SongRTCCallback(void);
void SetSong(SONG* song );

#endif /* SPEAKER_H_ */
