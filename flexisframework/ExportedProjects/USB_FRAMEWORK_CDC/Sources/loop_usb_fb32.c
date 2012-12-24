/*
 * loop_blink_fb32.c
 */
// New line...
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "ALL.H"
void usb_initialize(void);
#ifndef bool
#define bool int
#endif
typedef void (*terminal_command_cbfn)(char *command);
typedef void (*terminal_ctrlc_cbfn)(void);
typedef void (*ftdi_reset_cbfn)(void);
void ftdi_register(ftdi_reset_cbfn reset);
void terminal_register(terminal_command_cbfn command, terminal_ctrlc_cbfn ctrlc);
void terminal_poll(void);
void terminal_command_ack(bool edit);
void terminal_print(const byte *buffer, int length);

int splx(int level);
bool login=0;
const char l1[]="**********************\r\n";
const char l2[]="*** FB32 Framework ***\r\n";
const char l3[]="**********************\r\n";
bool main_edit=0;
char* main_command = 0;

static void main_command_cbfn(char *command)
{
    // pass the command to the run loop
    //assert(! main_command);
    main_command = command;
}
 
// this function is called by the FTDI transport when the user presses
// Ctrl-C.
static void main_ctrlc_cbfn(void)
{
    //stop();
}

// this function is called by the FTDI transport when the USB device
// is reset.
static volatile int resets;
static void main_reset_cbfn(void)
{
	++resets;
}
 bool serial_active;
//bool ftdi_attached;
long msecs;
int cpu_frequency = 48000000;
int bus_frequency = 48000000/2;
int oscillator_frequency = 12000000;

bool usb_host_mode=0;
// Prototypes for our functions.
void RTCTickCallback(void);
void setup(void);
void loop(void);

int counter = 0;	// Determine when 1/2 a second is up.
int blink_state=0;	// Toggles with XOR

void RTCTickCallback(void)
{
    ++counter;		// Increment the 1 ms counter.
    ++msecs;
    if(500 == counter )	// 1/2 second yet ?
    {
        counter = 0;            // reset the counter so we start over
        blink_state ^= 1;       // Use the "C" xor operator to toggle the state
        // write to the LED.
        digitalWrite(13,blink_state);
    }
}
void setup(void)
{
//	int x;
// Initialize the LED pin to output.
//    pinMode(13,OUTPUT);
    
  // 0 turns the LED on.
  //  digitalWrite(13,0);
    
  
	usb_initialize();
    if (!usb_host_mode) 
    {
        ftdi_register(main_reset_cbfn);
    }

   terminal_register(main_command_cbfn, main_ctrlc_cbfn);
    // if we're in device mode...
   EnableInterrupts;

}
const char prompt[]="\r\n>>";
char teststring[]= "ABCDEFGHIJKLMINOPQUSTUVWXYZ 1234567890\r\n";
void loop(void)
{
	int i;
	terminal_poll();
    if (main_command) {
    	// note: Main command will be a pointer to the line typed.
    	if( !login)
    	{
    		 for(i = 0 ; i < 1000 ; ++i)
    		 {
    			 terminal_print(&teststring[0],sizeof(teststring));
    		 }
     		terminal_print(&l1[0],sizeof(l1));
     		 delay(5);
     		terminal_print(&l2[0],sizeof(l1));
     		 delay(5);
     		terminal_print(&l3[0],sizeof(l1));
     		 delay(5);
     		 login = 1;
   	}
        terminal_print(&prompt[0],sizeof(prompt));
        delay(5);

        main_command = NULL;
        terminal_command_ack(main_edit);
        main_edit = 0;
    }

}

