// *** main.h *********************************************************

#ifndef MAIN_INCLUDED
#define STICKOS  1
#define FLASHER  0
#define SLEEP_DELAY  60
//#include "config.h"
//#include <ansi_parms.h>
//#include <stdlib.h>
#if ! _WIN32
#define NULL ((void*)0)
#endif

#if ! STICK_GUEST

#if EXTRACT && ! MCF51JM128
#include "extract.h"
#else
#if MCF52233
#include "MCF52235.h"
#elif MCF52221
#include "MCF52221.h"
#elif MCF52259
#include "MCF52259.h"
#elif MCF5211
#include "MCF5211.h"
#define MCF_INTC0_ICR01  MCF_INTC_ICR01
#define MCF_INTC0_ICR13  MCF_INTC_ICR13
#define MCF_INTC0_ICR55  MCF_INTC_ICR55
#define MCF_INTC0_IMRH  MCF_INTC_IMRH
#define MCF_INTC0_IMRL  MCF_INTC_IMRL
#elif MCF51JM128
#include "MCF51JM128.h"
#elif MCF51CN128
#include "compat.h"
#elif MCF51QE128
#elif MC9S08QE128
#elif MC9S12DT256
#elif MC9S12DP512
#elif PIC32
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
#else

#endif
#endif

#if MC9S08QE128 || MC9S12DT256 || MC9S12DP512
#if MC9S08QE128
#define MCU_CORE_BITS 8
#elif MC9S12DT256 || MC9S12DP512
#define MCU_CORE_BITS 16
#endif
typedef long intptr;
typedef unsigned long uintptr;
typedef uint16 size_t;
#else
#define MCU_CORE_BITS 32
typedef int intptr;
typedef unsigned int uintptr;
#endif
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
#if GCC
#define INTERRUPT __attribute__((interrupt))
#define far
#define __IPSBAR ((volatile uint8 *)0x40000000)
extern uint8 __RAMBAR[];
#define RAMBAR_ADDRESS ((uintptr)__RAMBAR)
#define FLASH_UPGRADE_RAM_BEGIN __attribute__((section(".text_flash_upgrade_ram_begin")))
#define FLASH_UPGRADE_RAM_END __attribute__((section(".text_flash_upgrade_ram_end")))

#define asm_halt() __asm__("halt")
#define asm_stop_2000(x) __asm__("stop #0x2000")
#define asm_stop_2700(x) __asm__("stop #0x2700")

#elif MCF52221 || MCF52233 || MCF52259 || MCF5211 || MCF51JM128 || MCF51CN128 || MCF51QE128
#if MCF51JM128 || MCF51CN128 || MCF51QE128
#define INTERRUPT  interrupt
#else
#define INTERRUPT  __declspec(interrupt)
#endif
#define asm_halt() asm { halt }
#define asm_stop_2000() asm { stop #0x2000 }
#define asm_stop_2700() asm { stop #0x2700 }
#elif MC9S08QE128
#define INTERRUPT
#define asm_halt()  asm("bgnd");
#elif MC9S12DT256 || MC9S12DP512
#define INTERRUPT
#define asm_halt()  asm("bgnd");
#elif PIC32
#define INTERRUPT
#define asm_halt()  asm("SDBBP");
#else
#error "What"
#endif

#else  // STICK_GUEST

#define INTERRUPT

#if WIN32
// _DEBUG/NDEBUG win
#if _DEBUG
#define SODEBUG  1
#else
#if NDEBUG
#define SODEBUG  0
#else
#error _DEBUG/NDEBUG?
#endif
#endif  // _DEBUG
#else  // WIN32
// SODEBUG wins
#if SODEBUG
#define _DEBUG
#undef NDEBUG
#else
#define NDEBUG
#undef _DEBUG
#endif  // SODEBUG
#endif  // WIN32

#if GCC
#include <inttypes.h>
#include <bits/wordsize.h>
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef uintptr_t uintptr;
typedef intptr_t intptr;
#if __WORDSIZE == 64
typedef uint64_t size_t;
#else
typedef uint32 size_t;
#endif
#else // ! GCC
#define _WIN32_WINNT 0x0601
#include <windows.h>
extern int isatty(int);
#if ! NO_UINT_TYPEDEFS
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef  int int32;
typedef unsigned int uint32;
typedef int intptr;
typedef unsigned int uintptr;
#endif
#define NO_UINT_TYPEDEFS  1
#endif // ! GCC
#include <assert.h>
#define ASSERT(x)  assert(x)
#define assert_ram(x)  assert(x)

extern void write(int, const void *, size_t);
extern char *gets(char *);

#define inline
#undef MAX_PATH

#endif  // ! STICK_GUEST
//typedef byte uint8;
//typedef word uint16;
//typedef long int32;
//typedef dword uint32;

//typedef unsigned int *) uintptr;
//typedef int* intptr;

typedef unsigned char bool;

typedef unsigned int uint;

enum {
    false,
    true
};

#define IN
#define OUT
#define OPTIONAL
#define VARIABLE  1
#define MIN(a, b)  ((a) < (b) ? (a) : (b))
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#define ROUNDUP(n, s)  (((n)+(s)-1)&~((s)-1))  // N.B. s must be power of 2!
#define ROUNDDOWN(n, s)  ((n)&~((s)-1))  // N.B. s must be power of 2!
#define LENGTHOF(a)  (sizeof(a)/sizeof(a[0]))
#define OFFSETOF(t, f)  ((int)(intptr)(&((t *)0)->f))
#define IS_POWER_OF_2(x) ((((x)-1)&(x))==0)

#define BASIC_OUTPUT_LINE_SIZE  79
#define BASIC_INPUT_LINE_SIZE  72
#define assert(x) if(!(x)){ asm{halt;}}
#include <stdarg.h>





#include "compat.h"
#include "util.h"
#include "terminal.h"
#include "ftdi.h"
#include "usb.h"

extern bool serial_active;
#define serial_send(buffer, length)
#define led_unknown_progress()
#define serial_command_ack()
#define os_yield()
extern long msecs;
extern int oscillator_frequency;
extern int cpu_frequency;
extern bool usb_host_mode;



#define ASSERT_RAM(x)  do { if (! (x)) { asm_halt(); } } while (0)
#define MAIN_INCLUDED  1
#endif  // MAIN_INCLUDED

