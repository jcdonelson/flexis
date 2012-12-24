/*
 * CONSOLE_IO.H
 * This will make the printf  function work.
 * In the debugger make sure that in the Connection "Setup" dialog, 
 * "Debug Options" property page, the check box 
 * "Enable Terminal printf support" is set.
 * Also note that the MCU freezes (no interrupts when printing to the debugger console)
 * NOTE: You must use the provided exceptions_frwk.c
 * or when the debugger is not attached it will crash
 *
 *  $Rev:: 43                        $:
 *  $Date:: 2011-04-15 06:10:50 -040#$:
 *  $Author:: jcdonelson             $:

 * 
 * 
 */
/*  See CONFIG.H
#define CONSOLE_IO_SUPPORT  	1    // Must be set to 1 or no support at all.
#define CONSOLE_LCD_SUPPORT     0
#define CONSOLE_SCI1_SUPPORT    0
#define CONSOLE_SCI2_SUPPORT    0
*/
#define DEBUGGER_CONSOLE		1
#define LCD_CONSOLE				2
#define SCI1_CONSOLE			4
#define SCI2_CONSOLE			8
/*
 *    SetActiveConsole(int cons) - Sets which devices will get printf's
 *    Can be or'd together  
 */
void SetActiveConsole(int cons);
