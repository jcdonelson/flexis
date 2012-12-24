//#include <hidef.h> /* for EnableInterrupts macro */

#include "mcf51jm128.inc"
.global _main
.global main
.global _RTC_Handler
.global RTC_Handler
#define ioreg(a) a-IOBASE(A4) 
.extern   __SDA_BASE;
;
; Helpful macros
;
DISABLE_WATCHDOG	.equ 0x10
; Disable watchdog timer.
disableWatchdog: .macro 
	 moveq	#DISABLE_WATCHDOG,d0
	 move.b	d0,SOPT1
.endm
; Push a register on to the stack.
push: .macro reg
	move.l reg,-(A7)
.endm
; Pop a register from the stack.
pop: .macro reg
   move.l (A7)+,reg
.endm	
; Set interrupts on
EnableInterrupts: .macro
	move.w SR,D0
	andi.l #0xF8FF,D0
    move.w D0,SR
.endm
; Shut interrupts off.
DisableInterrupts: .macro
	move.w SR,D0
	ori.l #0x0700,D0
    move.w D0,SR
.endm
IOBASE		.equ 0xFFFF8000	 
//	.rodata
//	.org Vrtc
//	.long RTC_Handler
; Initialized RAM Data	
	.sdata
byte_data: 		.byte 		$45
word_data: 		.short 		$dead
long_data:  	.long 		$beefabcd
buffer:	    	.space 		80
; Used in the RTC hanldler
counter:   		.long 		0

; Read Only data in Flash
	.rodata
msg:
	.asciz "Hello World!"
	
; Code section.
	.text

_main:

main:
	 move.l	4(sp),a0
	 move.l #IOBASE,A4	; Never blow away A4. It is used for I/O
	 disableWatchdog
;	 moveq	#DISABLE_WATCHDOG,d0
;	 move.b	d0,SOPT1
	bsr	init_clock
    
	clr.l D0
	;move.l #0xabcd789,D0
	move.l D0,counter
	; clr.l D0
	// A5 Always points to the data area.
	lea           __SDA_BASE,a5
	// A5 is the base register to allow short (16 bit) access to RAM variables..
	// sdax -
	// For labels in a small data section, the offset from the base of the
    // small data section to the label. This syntax is not allowed for labels
    // in other sections.
	move.l long_data@sdax(A5),D0
 	move.w #0xFEED,long_data@sdax(A5)
 	move.b #0xFE,0xFFFF8000-PTAD(A5)
 	move.l D0,long_data@sdax(A5)
 	move.l #IOBASE-PTAD,D0
	tas.b counter
	lea byte_data,A0
	move.b byte_data,D0
	clr d1
	move.w word_data,D1
	clr d2
	move.l long_data,D3
; Set up the RTC for a 1 ms tick.
	clr.l 	D0				; Clear the 500ms counter
	move.l 	D0,counter
;	RTCMOD = 0     
	move.b 	D0,RTCMOD
;RTCSC = 0x18;
	move.b 	#0x18,D0		; Use the internal 1Khz clock.
	move.b 	D0,RTCSC	
	EnableInterrupts
; strcpy msg to buffer.		
; Set up copy address...	 
	 lea msg,A0
	 lea buffer,A1
	 
COPY_LOOP:
	 move.b (a0)+,(A1)+
	 bne COPY_LOOP	 
;	Bit  operations on an I/O register 
	 move.b D0, PTAD
	 move.l #PTEDD,A0
	 bset.b #6,(A0)
	 bset.b #0,(A0)
	 bset.b #0,-(A0)
	 move.b #1,D0
TOGGLE_LOOP:
	bchg.b 	#0,(A0)
	bra		TOGGLE_LOOP
	rts
/*
*   init_clock: No input parameters
*   Set clock to 48MHz, using a 12Mhz xtal.
*/

init_clock:
	// Allocate stack space 24/4 = 6 dwords.
	link	A6,#-24
	// Save registers on the stack
    movem.l A0-A4/D0,(A7)
; Set up the I/O registers we need to work with.
	move.l 	#MCGC1,A1
	move.l 	#MCGC2,A2
	move.l 	#MCGC3,A3
;	move.l 	#MCGSC,A4
; Set MGCC2 to 36
	move.b 	#0x36,(A2)

init_clock1:	
; Loop until the osc starts up
	;btst 	#MCGSC_OSCINIT_BIT,(A4)
	btst    #MCGSC_OSCINIT_BIT,ioreg(MCGSC)
	beq     init_clock1
; Set MCGC1
	move.b  #0x98 | MCGC1_IRCLKEN_MASK,(A1) 

init_clock2:
; Wait for clock to show selected
	;move.b	(A4),D0
	move.b  ioreg(MCGSC),D0
	andi.l	#MCGSC_CLKST1_MASK |MCGSC_CLKST0_MASK,D0
	cmpi.b	#MCGSC_CLKST1_MASK,D0
	bne   	init_clock2

//MCGC3 = 0x48
	move.b 	#0x48,(A3)
init_clock3:
; Wait for PLL to start and lock.
;	move.b  (A4),D0
;	btst	#MCGSC_PLLST_BIT,D0     ; PLL start
	btst	#MCGSC_PLLST_BIT,ioreg(MCGSC)     ; PLL start
	beq     init_clock3
;	btst	#MCGSC_LOCK_BIT,D0	    ; PLL Lock
	btst	#MCGSC_LOCK_BIT,ioreg(MCGSC) 	
	beq     init_clock3
; Clear bits 6 & 7 to 0 to select the PLL output as the CPU clock.
	move.b  (A1),D0
	andi.l  #~(MCGC1_CLKS1_MASK | MCGC1_CLKS0_MASK),D0
	move.b	D0,(A1)
;	 movem.l (sp), d0-d2/a0-a4
	// Restore the registers we clobbered.
    movem.l (A7),A0-A4/D0
    // Restore the stack pointer.
	unlk	A6
	rts
	//{&PTEDD,&PTED,0x40,0,&PTEPE,&PTEDS,&PTDSE},			// Shield 13 PTE6
//
// Interrupt handler for the RTC
//	
RTC_Handler:
_RTC_Handler:
//RTCSC |= 0x80;
	push A0
	push D0
	push D1
	// Increment the counter.
    move.l counter,D0
    add.l #1,D0
    // Test if 500
    cmp.l #500,D0
    bls NOT_500
    // Reset the count.
	move.l #0,D0
	// Toggle a pin.
	move.l #PTED,A0
	;bchg.b #6,PTED-IOBASE(A4)
	bchg.b #6,ioreg(PTED)	
NOT_500:    	
	move.l D0,counter
	
	// Read the status register and clear the interrupt.
	move.l #RTCSC,A0
	move.b (A0),D0
	bset.b #RTCSC_RTIF_BIT,(A0)
	pop D1
	pop D0
	pop A0
	rte
ADDRESSING_MODES:
	//move.l    5(a0,d0),5(a0,d0)
	move.b    3(a0,d1),d0
	addq.l   #1,counter	
	move.b    d0,3(a1,d1)
	move.w    d0,3(a1,d1)
	move.l    d0,3(a1,d1)
	neg.l 		d0
	ori.l	#3,d0
	andi.l  #4,d0
	or.l    d1,d0
	cmpi.b  #3,d0
	cmpi.w  #3,d0
	cmpi.l  #3,d0
	btst.l #2,d0
	 bset.b  #2,(a0)
	.end
