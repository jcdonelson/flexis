/*
* CONSOLE_IO.C
* Support for printf on SCI1,SCI2,LCD and debug console
* V1 Only. 
*  $Rev:: 44                        $:
*  $Date:: 2011-04-18 08:18:30 -040#$:
*  $Author:: jcdonelson             $:
* This code is licensed under GPL, any version.
*/
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <stdio.h>

#include <ansi_parms.h>
#include "SERIAL_B.H"
#include "CONSOLE_IO.H"
#include "KEYBRD_LCD.H"
#include "CONFIG.H"
#ifndef CONSOLE_IO_SUPPORT
#define CONSOLE_IO_SUPPORT  0 
#endif

#ifndef CONSOLE_LCD_SUPPORT
#define CONSOLE_LCD_SUPPORT  0 
#endif
#ifndef CONSOLE_SCI1_SUPPORT
#define CONSOLE_SCI1_SUPPORT  0 
#endif
#ifndef CONSOLE_SCI2_SUPPORT
#define CONSOLE_SCI2_SUPPORT  0 
#endif

 

#if CONSOLE_IO_SUPPORT == 1


 int  Debugger_write_console(  __std(__file_handle) handle, unsigned char * buffer,
          __std(size_t) * count);



#define DEBUGGER_CONSOLE		1
#define LCD_CONSOLE				2
#define SCI1_CONSOLE			4
#define SCI2_CONSOLE			8
int active_consoles = 0;

void SetActiveConsole(int cons)
{
	active_consoles = cons;
	asm {
		
	// Force the halt instruction to cause an exception 
	// instead of a reset so when the debugger is not
	// attached, it will not reset.
	// There is also special code in exception.c to handle this situation.
		move.l #0x40000000,D0
		movec D0,cpucr
	}
}

 typedef enum DSIOResult
 {
     kDSIONoError    = 0x00,
     kDSIOError      = 0x01,
     kDSIOEOF        = 0x02
 } DSIOResult;

 /*
  *    MessageCommandID
  */
 typedef enum MessageCommandID
 {
     /*
      * target->host support commands
      */

     kDSWriteFile                = 0xD0,        /*        L2    L3        */
     kDSReadFile                 = 0xD1         /*        L2    L3        */

 } MessageCommandID;
 typedef int             bool;
  static const bool false = 0;
  static const bool true  = 1;

static  interrupt  VectorNumber_Vtrap14   void Local_TrapHandler_printf(void)
  {
	 asm {
     HALT
;     RTE
	 }
  }
 static asm __declspec(register_abi) unsigned char TRKAccessFile(long command, unsigned long file_handle, unsigned long *length_ptr, char *buffer_ptr)
 {
     move.l    D3,-(a7)
     andi.l    #0x000000ff, D0
     move.l    A1, D3
     movea.l    A0, A1
     move.l    (A1),D2
     trap  	#14
     move.l    D1, (A1)
     move.l    (A7)+,D3
     rts
 }
 
 static long __access_file( __std(__file_handle) handle, unsigned char * buffer,
                    __std(size_t) * count, bool read )
 {
     unsigned long local_count;
     long result;

     /*
     ** Convert MSL types (loosely specified sizes and forms) into
     ** types with well-defined sizes and forms.
     */

     local_count = *count;

     result = TRKAccessFile( (read ? kDSReadFile : kDSWriteFile),
                             (unsigned long)handle, &local_count,
                             (char *)buffer );

     *count = (__std(size_t))local_count;

     /*
     ** Convert the result into the MSL equivalent.
     */

     switch (result)
     {
         case kDSIONoError:
             return( __std(__no_io_error) );
         case kDSIOEOF:
             return( __std(__io_EOF) );
         case kDSIOError:
         default:
             return( __std(__io_error) );
     }
     
 }

 int Debugger_read_console( __std(__file_handle) handle, unsigned char * buffer,
                      __std(size_t) * count);
  
 int Debugger_read_console( __std(__file_handle) handle, unsigned char * buffer,
                     __std(size_t) * count)
 {
 #pragma unused(handle)
     return __access_file(0,buffer,count,true);

 }

 
 int  Debugger_write_console(  __std(__file_handle) handle, unsigned char * buffer,
         __std(size_t) * count)
 {
#pragma unused(handle)
     return __access_file(0,buffer,count,false);

 }
 /*
 *    LCD Console support
 */
#if CONSOLE_LCD_SUPPORT == 1
 int LCD_read_console( __std(__file_handle) handle, unsigned char * buffer,
                       __std(size_t) * count);
   
int LCD_read_console( __std(__file_handle) handle, unsigned char * buffer,
                      __std(size_t) * count)
{
	 // Read from the keyboard.
	 handle;
	 buffer;
	 count;
	 return 0;
}

int  LCD_write_console(  __std(__file_handle) handle, unsigned char * buffer,
          __std(size_t) * count);
  
int  LCD_write_console(  __std(__file_handle) handle, unsigned char * buffer,
          __std(size_t) * count)
  {
	handle;
	int width = LCDGetWidth();
	LCDWriteBuffer(buffer,(int)*count, 0);
	if( *count > width)
		LCDWriteBuffer(buffer+width,(int)*count + width, 1);

	return 0;

  }
#endif // #if CONSOLE_LCD_SUPPORT == 1

/*
*    SCI1 Console Support
*/
#if CONSOLE_SCI1_SUPPORT == 1
int SCI1_read_console( __std(__file_handle) handle, unsigned char * buffer,
                        __std(size_t) * count);

int SCI1_read_console( __std(__file_handle) handle, unsigned char * buffer,
                      __std(size_t) * count)
  {
	
	int lcount = (int) *count;
	(buffer);
	(handle);
	 *count = 0;
	 while(0 ==  Serial_rxbyte(0,(byte*) *buffer) && lcount )
	 {
		 --lcount;
		 (*count)++;
		 ++buffer;
	 }

     return 0;

  }
int  SCI1_write_console(  __std(__file_handle) handle, unsigned char * buffer,
          __std(size_t) * count);

int  SCI1_write_console(  __std(__file_handle) handle, unsigned char * buffer,
          __std(size_t) * count)
  {
	  int lcount =(int) *count;
	  (handle);
	   while(lcount) 
	   {
	       while(TX_FULL == Serial_txbyte(0,*buffer))
				   ;
	       ++buffer;
	       --lcount;
	   }


      return 0;

  }
#endif // #if CONSOLE_SCI1_SUPPORT == 1
  
/*
*    SCI2 Console Support
*/
#if CONSOLE_SCI2_SUPPORT == 1
  
int SCI2_read_console( __std(__file_handle) handle, unsigned char * buffer,
                      __std(size_t) * count)
  {
	 *count = 0;
	 while(0 ==  Serial_rxbyte(1, &rxdata) )
		 ++count;

      return 0;

  }

  
  int  SCI2_write_console(  __std(__file_handle) handle, unsigned char * buffer,
          __std(size_t) * count)
  {
	  int lcount =(int) *count;
	   while(lcount) 
	   {
	       while(TX_FULL == Serial_txbyte(1,*buffer))
				   ;
	       ++buffer;
	       --lcount;
	   }


      return 0;

  }

#endif // #if CONSOLE_SCI1_SUPPORT == 1

/*
*   Stubs.
*/
  int __read_console( __std(__file_handle) handle, unsigned char * buffer,
                        __std(size_t) * count);

  int __read_console( __std(__file_handle) handle, unsigned char * buffer,
                      __std(size_t) * count)
  {
	  if( active_consoles & DEBUGGER_CONSOLE)
	     Debugger_read_console( 0, buffer, count);
#if CONSOLE_LCD_SUPPORT == 1	  
	  if( active_consoles & LCD_CONSOLE)
	     LCD_read_console( handle, buffer, count);
#endif	  
#if CONSOLE_SCI1_SUPPORT == 1	  
	  if( active_consoles & SCI1_CONSOLE)
	     SCI1_read_console( handle, buffer, count);
#endif	  
#if CONSOLE_SCI2_SUPPORT == 1
	  if( active_consoles & SCI2_CONSOLE)
	     SCI2_read_console( handle, buffer, count);
#endif	  
	  return 0;
 }

int  __write_console(  __std(__file_handle) handle, unsigned char * buffer,
            __std(size_t) * count);
  
int  __write_console(  __std(__file_handle) handle, unsigned char * buffer,
          __std(size_t) * count)
  {
	  if( active_consoles & DEBUGGER_CONSOLE)
	     Debugger_write_console( handle, buffer, count);
#if CONSOLE_LCD_SUPPORT == 1
	  if( active_consoles & LCD_CONSOLE)
	     LCD_write_console( handle, buffer, count);
#endif
#if CONSOLE_SCI1_SUPPORT == 1
	  if( active_consoles & SCI1_CONSOLE)
	     SCI1_write_console( handle, buffer, count);
#endif	  
#if CONSOLE_SCI2_SUPPORT == 1
	  if( active_consoles & SCI2_CONSOLE)
	     SCI2_write_console( handle, buffer, count);
#endif
    return 0;
}

#endif
