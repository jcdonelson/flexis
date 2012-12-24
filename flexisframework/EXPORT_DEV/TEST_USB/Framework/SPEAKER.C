/*
 *  SPEAKER,C
 *  Provides support for the on board speaker.
 *
 *  $Rev:: 53                        $:
 *  $Date:: 2011-04-25 23:33:36 -040#$:
 *  $Author:: jcdonelson             $:
*/

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "SPEAKER.H"

static SONG* current_song = (SONG*)0;
static word note = 0;
static word whole_note = 1024;
static word note_timer = 512; 
static word spacing = 0;
static word volume = 2;
static word last_value;
static word repeats = 1;
static int song_counter = 0;
typedef void(*PFNCALLBACKSONG)(void);
static void (*OnSongDone)(void) =(PFNCALLBACKSONG) 0;
 
typedef struct _note {
	char* name;
	dword freq;
} NOTE;
NOTE _notes[]=
{
		{"A", 	4400}, 	//0
		{"A#", 	4661}, 	//1
		{"B", 	4938}, 	//2
		{"C", 	5232}, 	//3
		{"C#", 	5543}, 	//4
		{"D", 	5873}, 	//5
		{"D#", 	6222}, 	//6
		{"E", 	6592}, 	//7
		{"F", 	6984}, 	//8
		{"F#", 	7399}, 	//9
		{"G", 	7839}, //10
		{"G#", 	8306}, 	//11
		{"A", 	8800}, //12
		{(byte*)0}
};

void SetOnSongDoneCallback(PFNCALLBACKSONG cb)
{
	OnSongDone = cb;	
}

void SpeakerInit(void)
{
	// Set up the speaker TPM for output frequencies
	// In this usage, we can set the TMP divider and always set the duty
	// cycle to 50% to get a square wave at different frequencies.
	// TPMxSC - Section 22.3
	//    7                                            0
	// | TOF | TOIE | CPWMS  | CLKS | CLKS | PS | PS | PS |
	//    0      0      0       0      1      0    1    0
	// CLK = 01 = Bus Rate Clock
	//  PS = 010 = /4
	//
	TPM2SC = 0xA; // 24/4 = 6MHz
	// TPMxCnSC
	//    7        6      5      4       3       2       1   0
	// | CHnF  | CHnIE | MSnB | MSnA | ELSnB  | ELSnA  | 0 | 0 |
	//    0        0      1      0      1        0       0   0
	// MSnB = 1  Configure to Edge aligned PWM when CPWMS = 0.
	// ElsnB:EKSnA =  10 Clear Output on compare.
	
	TPM2C1SC = 0x28;  // Set to PWM
	TPM2MOD = 0;
	TPM2C1V = 0; // Off
	
}

void SpeakerON(void)
{
	long long l = last_value;
	l *= 3;
	TPM2C1V = (word)(l >>  volume);
}
void SpeakerOFF(void)
{
	TPM2C1V = 0;
}
void SetFrequencySpeaker(dword f_times_10)
{
	dword count_value = 60000000/f_times_10;
	count_value *= 2;
	last_value = (word) (count_value);
	TPM2MOD = (word)count_value;
	TPM2C1V = 0;
	// note: does not turn speaker on!
	
}

byte PlayNote(byte which, byte octave)
{
	dword freq = _notes[which-1].freq * octave;
	// HACK for demo to be higher in pitch.
	// HACK for demo to be higher in pitch.
	freq += freq/2;
	if( which == 0)
		SpeakerOFF();
	
	if(which > 12)
		return 1;

	SetFrequencySpeaker(freq);
	SpeakerON();
	return 0;
}
void SetSong(SONG* song )
{
    current_song= song;
    repeats = 1;
    note = 0;
    song_counter = 0;
    
}

void SongRTCCallback(void)
{
  	
 if( !current_song )
   return;	
 // Service the song
  ++song_counter;
  if(song_counter > note_timer || repeats == 0 )
	  SpeakerOFF();  
	  
  if( song_counter == (note_timer+spacing) && repeats > 0)
  {
    	note_timer = (word)(whole_note /  current_song[note].duration);
    	spacing = (word)(note_timer/8);
    	note_timer -= spacing;
		// 255 indicates a rest.
    	if( current_song[note].note == 255)
    	{
    		SpeakerOFF();  
    	}
    	else
    	{
    		(void) PlayNote(current_song[note].note, current_song[note].octave);
    	}
	 
  	++note;
  	// Is the song done ?
  	if( current_song[note].note == 0)
  	{
  		if(OnSongDone)
  		  OnSongDone();
  			
  		 --repeats;
  	}

  	song_counter = 0;
  }
}

