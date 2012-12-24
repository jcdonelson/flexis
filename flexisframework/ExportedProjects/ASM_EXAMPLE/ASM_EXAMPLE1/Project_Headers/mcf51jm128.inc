;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Assembly Language Includes for mcf51jm128
;
; V1.0 
; Copyright (c)2011 James Donelson 
; GPL (any version) or Apache License Applies
; Free for any use. Please notify of any correction or improvements
;
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;*********************************************
; Interrupt Vector Numbers 
;*********************************************

VectorNumber_INITSP                     .equ 0
VectorNumber_INITPC                     .equ 1
VectorNumber_Vaccerr                    .equ 2
VectorNumber_Vadderr                    .equ 3
VectorNumber_Viinstr                    .equ 4
VectorNumber_VReserved5                 .equ 5
VectorNumber_VReserved6                 .equ 6
VectorNumber_VReserved7                 .equ 7
VectorNumber_Vprviol                    .equ 8
VectorNumber_Vtrace                     .equ 9
VectorNumber_Vunilaop                   .equ 10
VectorNumber_Vunilfop                   .equ 11
VectorNumber_Vdbgi                      .equ 12
VectorNumber_VReserved13                .equ 13
VectorNumber_Vferror                    .equ 14
VectorNumber_VReserved15                .equ 15
VectorNumber_VReserved16                .equ 16
VectorNumber_VReserved17                .equ 17
VectorNumber_VReserved18                .equ 18
VectorNumber_VReserved19                .equ 19
VectorNumber_VReserved20                .equ 20
VectorNumber_VReserved21                .equ 21
VectorNumber_VReserved22                .equ 22
VectorNumber_VReserved23                .equ 23
VectorNumber_Vspuri                     .equ 24
VectorNumber_VReserved25                .equ 25
VectorNumber_VReserved26                .equ 26
VectorNumber_VReserved27                .equ 27
VectorNumber_VReserved28                .equ 28
VectorNumber_VReserved29                .equ 29
VectorNumber_VReserved30                .equ 30
VectorNumber_VReserved31                .equ 31
VectorNumber_Vtrap0                     .equ 32
VectorNumber_Vtrap1                     .equ 33
VectorNumber_Vtrap2                     .equ 34
VectorNumber_Vtrap3                     .equ 35
VectorNumber_Vtrap4                     .equ 36
VectorNumber_Vtrap5                     .equ 37
VectorNumber_Vtrap6                     .equ 38
VectorNumber_Vtrap7                     .equ 39
VectorNumber_Vtrap8                     .equ 40
VectorNumber_Vtrap9                     .equ 41
VectorNumber_Vtrap10                    .equ 42
VectorNumber_Vtrap11                    .equ 43
VectorNumber_Vtrap12                    .equ 44
VectorNumber_Vtrap13                    .equ 45
VectorNumber_Vtrap14                    .equ 46
VectorNumber_Vtrap15                    .equ 47
VectorNumber_VReserved48                .equ 48
VectorNumber_VReserved49                .equ 49
VectorNumber_VReserved50                .equ 50
VectorNumber_VReserved51                .equ 51
VectorNumber_VReserved52                .equ 52
VectorNumber_VReserved53                .equ 53
VectorNumber_VReserved54                .equ 54
VectorNumber_VReserved55                .equ 55
VectorNumber_VReserved56                .equ 56
VectorNumber_VReserved57                .equ 57
VectorNumber_VReserved58                .equ 58
VectorNumber_VReserved59                .equ 59
VectorNumber_VReserved60                .equ 60
VectorNumber_Vunsinstr                  .equ 61
VectorNumber_VReserved62                .equ 62
VectorNumber_VReserved63                .equ 63
VectorNumber_Virq                       .equ 64
VectorNumber_Vlvd                       .equ 65
VectorNumber_Vlol                       .equ 66
VectorNumber_Vspi1                      .equ 67
VectorNumber_Vspi2                      .equ 68
VectorNumber_Vusb                       .equ 69
VectorNumber_VReserved70                .equ 70
VectorNumber_Vtpm1ch0                   .equ 71
VectorNumber_Vtpm1ch1                   .equ 72
VectorNumber_Vtpm1ch2                   .equ 73
VectorNumber_Vtpm1ch3                   .equ 74
VectorNumber_Vtpm1ch4                   .equ 75
VectorNumber_Vtpm1ch5                   .equ 76
VectorNumber_Vtpm1ovf                   .equ 77
VectorNumber_Vtpm2ch0                   .equ 78
VectorNumber_Vtpm2ch1                   .equ 79
VectorNumber_Vtpm2ovf                   .equ 80
VectorNumber_Vsci1err                   .equ 81
VectorNumber_Vsci1rx                    .equ 82
VectorNumber_Vsci1tx                    .equ 83
VectorNumber_Vsci2err                   .equ 84
VectorNumber_Vsci2rx                    .equ 85
VectorNumber_Vsci2tx                    .equ 86
VectorNumber_Vkeyboard                  .equ 87
VectorNumber_Vadc                       .equ 88
VectorNumber_Vacmpx                     .equ 89
VectorNumber_Viic1x                     .equ 90
VectorNumber_Vrtc                       .equ 91
VectorNumber_Viic2x                     .equ 92
VectorNumber_Vcmt                       .equ 93
VectorNumber_Vcanwu                     .equ 94
VectorNumber_Vcanerr                    .equ 95
VectorNumber_Vcanrx                     .equ 96
VectorNumber_Vcantx                     .equ 97
VectorNumber_Vrnga                      .equ 98
VectorNumber_VReserved99                .equ 99
VectorNumber_VReserved100               .equ 100
VectorNumber_VReserved101               .equ 101
VectorNumber_VReserved102               .equ 102
VectorNumber_VReserved103               .equ 103
VectorNumber_VL7swi                     .equ 104
VectorNumber_VL6swi                     .equ 105
VectorNumber_VL5swi                     .equ 106
VectorNumber_VL4swi                     .equ 107
VectorNumber_VL3swi                     .equ 108
VectorNumber_VL2swi                     .equ 109
VectorNumber_VL1swi                     .equ 110

;*********************************************
; Interrupt Vector Table Address 
;*********************************************

INITSP                                  .equ 0x00000000
INITPC                                  .equ 0x00000004
Vaccerr                                 .equ 0x00000008
Vadderr                                 .equ 0x0000000C
Viinstr                                 .equ 0x00000010
VReserved5                              .equ 0x00000014
VReserved6                              .equ 0x00000018
VReserved7                              .equ 0x0000001C
Vprviol                                 .equ 0x00000020
Vtrace                                  .equ 0x00000024
Vunilaop                                .equ 0x00000028
Vunilfop                                .equ 0x0000002C
Vdbgi                                   .equ 0x00000030
VReserved13                             .equ 0x00000034
Vferror                                 .equ 0x00000038
VReserved15                             .equ 0x0000003C
VReserved16                             .equ 0x00000040
VReserved17                             .equ 0x00000044
VReserved18                             .equ 0x00000048
VReserved19                             .equ 0x0000004C
VReserved20                             .equ 0x00000050
VReserved21                             .equ 0x00000054
VReserved22                             .equ 0x00000058
VReserved23                             .equ 0x0000005C
Vspuri                                  .equ 0x00000060
VReserved25                             .equ 0x00000064
VReserved26                             .equ 0x00000068
VReserved27                             .equ 0x0000006C
VReserved28                             .equ 0x00000070
VReserved29                             .equ 0x00000074
VReserved30                             .equ 0x00000078
VReserved31                             .equ 0x0000007C
Vtrap0                                  .equ 0x00000080
Vtrap1                                  .equ 0x00000084
Vtrap2                                  .equ 0x00000088
Vtrap3                                  .equ 0x0000008C
Vtrap4                                  .equ 0x00000090
Vtrap5                                  .equ 0x00000094
Vtrap6                                  .equ 0x00000098
Vtrap7                                  .equ 0x0000009C
Vtrap8                                  .equ 0x000000A0
Vtrap9                                  .equ 0x000000A4
Vtrap10                                 .equ 0x000000A8
Vtrap11                                 .equ 0x000000AC
Vtrap12                                 .equ 0x000000B0
Vtrap13                                 .equ 0x000000B4
Vtrap14                                 .equ 0x000000B8
Vtrap15                                 .equ 0x000000BC
VReserved48                             .equ 0x000000C0
VReserved49                             .equ 0x000000C4
VReserved50                             .equ 0x000000C8
VReserved51                             .equ 0x000000CC
VReserved52                             .equ 0x000000D0
VReserved53                             .equ 0x000000D4
VReserved54                             .equ 0x000000D8
VReserved55                             .equ 0x000000DC
VReserved56                             .equ 0x000000E0
VReserved57                             .equ 0x000000E4
VReserved58                             .equ 0x000000E8
VReserved59                             .equ 0x000000EC
VReserved60                             .equ 0x000000F0
Vunsinstr                               .equ 0x000000F4
VReserved62                             .equ 0x000000F8
VReserved63                             .equ 0x000000FC
Virq                                    .equ 0x00000100
Vlvd                                    .equ 0x00000104
Vlol                                    .equ 0x00000108
Vspi1                                   .equ 0x0000010C
Vspi2                                   .equ 0x00000110
Vusb                                    .equ 0x00000114
VReserved70                             .equ 0x00000118
Vtpm1ch0                                .equ 0x0000011C
Vtpm1ch1                                .equ 0x00000120
Vtpm1ch2                                .equ 0x00000124
Vtpm1ch3                                .equ 0x00000128
Vtpm1ch4                                .equ 0x0000012C
Vtpm1ch5                                .equ 0x00000130
Vtpm1ovf                                .equ 0x00000134
Vtpm2ch0                                .equ 0x00000138
Vtpm2ch1                                .equ 0x0000013C
Vtpm2ovf                                .equ 0x00000140
Vsci1err                                .equ 0x00000144
Vsci1rx                                 .equ 0x00000148
Vsci1tx                                 .equ 0x0000014C
Vsci2err                                .equ 0x00000150
Vsci2rx                                 .equ 0x00000154
Vsci2tx                                 .equ 0x00000158
Vkeyboard                               .equ 0x0000015C
Vadc                                    .equ 0x00000160
Vacmpx                                  .equ 0x00000164
Viic1x                                  .equ 0x00000168
Vrtc                                    .equ 0x0000016C
Viic2x                                  .equ 0x00000170
Vcmt                                    .equ 0x00000174
Vcanwu                                  .equ 0x00000178
Vcanerr                                 .equ 0x0000017C
Vcanrx                                  .equ 0x00000180
Vcantx                                  .equ 0x00000184
Vrnga                                   .equ 0x00000188
VReserved99                             .equ 0x0000018C
VReserved100                            .equ 0x00000190
VReserved101                            .equ 0x00000194
VReserved102                            .equ 0x00000198
VReserved103                            .equ 0x0000019C
VL7swi                                  .equ 0x000001A0
VL6swi                                  .equ 0x000001A4
VL5swi                                  .equ 0x000001A8
VL4swi                                  .equ 0x000001AC
VL3swi                                  .equ 0x000001B0
VL2swi                                  .equ 0x000001B4
VL1swi                                  .equ 0x000001B8

;*********************************************
; I/O Register Locations 
;*********************************************


;*********************************************
;  Nonvolatile MCG Fine Trim
;*********************************************
NVFTRIM                                 .equ 0x000003FE ;  Nonvolatile MCG Fine Trim
NVFTRIM_FTRIM_MASK                      .equ 0x01
NVFTRIM_FTRIM_BIT                       .equ 0x00

;*********************************************
;  Nonvolatile MCG Trim Register
;*********************************************
NVMCGTRM                                .equ 0x000003FF ;  Nonvolatile MCG Trim Register
NVMCGTRM_TRIM0_MASK                     .equ 0x01
NVMCGTRM_TRIM0_BIT                      .equ 0x00
NVMCGTRM_TRIM1_MASK                     .equ 0x02
NVMCGTRM_TRIM1_BIT                      .equ 0x01
NVMCGTRM_TRIM2_MASK                     .equ 0x04
NVMCGTRM_TRIM2_BIT                      .equ 0x02
NVMCGTRM_TRIM3_MASK                     .equ 0x08
NVMCGTRM_TRIM3_BIT                      .equ 0x03
NVMCGTRM_TRIM4_MASK                     .equ 0x10
NVMCGTRM_TRIM4_BIT                      .equ 0x04
NVMCGTRM_TRIM5_MASK                     .equ 0x20
NVMCGTRM_TRIM5_BIT                      .equ 0x05
NVMCGTRM_TRIM6_MASK                     .equ 0x40
NVMCGTRM_TRIM6_BIT                      .equ 0x06
NVMCGTRM_TRIM7_MASK                     .equ 0x80
NVMCGTRM_TRIM7_BIT                      .equ 0x07

;*********************************************
;  Backdoor Comparison Key 0
;*********************************************
NVBACKKEY0                              .equ 0x00000400 ;  Backdoor Comparison Key 0
NVBACKKEY0_KEY0_MASK                    .equ 0x01
NVBACKKEY0_KEY0_BIT                     .equ 0x00
NVBACKKEY0_KEY1_MASK                    .equ 0x02
NVBACKKEY0_KEY1_BIT                     .equ 0x01
NVBACKKEY0_KEY2_MASK                    .equ 0x04
NVBACKKEY0_KEY2_BIT                     .equ 0x02
NVBACKKEY0_KEY3_MASK                    .equ 0x08
NVBACKKEY0_KEY3_BIT                     .equ 0x03
NVBACKKEY0_KEY4_MASK                    .equ 0x10
NVBACKKEY0_KEY4_BIT                     .equ 0x04
NVBACKKEY0_KEY5_MASK                    .equ 0x20
NVBACKKEY0_KEY5_BIT                     .equ 0x05
NVBACKKEY0_KEY6_MASK                    .equ 0x40
NVBACKKEY0_KEY6_BIT                     .equ 0x06
NVBACKKEY0_KEY7_MASK                    .equ 0x80
NVBACKKEY0_KEY7_BIT                     .equ 0x07

;*********************************************
;  Backdoor Comparison Key 1
;*********************************************
NVBACKKEY1                              .equ 0x00000401 ;  Backdoor Comparison Key 1
NVBACKKEY1_KEY0_MASK                    .equ 0x01
NVBACKKEY1_KEY0_BIT                     .equ 0x00
NVBACKKEY1_KEY1_MASK                    .equ 0x02
NVBACKKEY1_KEY1_BIT                     .equ 0x01
NVBACKKEY1_KEY2_MASK                    .equ 0x04
NVBACKKEY1_KEY2_BIT                     .equ 0x02
NVBACKKEY1_KEY3_MASK                    .equ 0x08
NVBACKKEY1_KEY3_BIT                     .equ 0x03
NVBACKKEY1_KEY4_MASK                    .equ 0x10
NVBACKKEY1_KEY4_BIT                     .equ 0x04
NVBACKKEY1_KEY5_MASK                    .equ 0x20
NVBACKKEY1_KEY5_BIT                     .equ 0x05
NVBACKKEY1_KEY6_MASK                    .equ 0x40
NVBACKKEY1_KEY6_BIT                     .equ 0x06
NVBACKKEY1_KEY7_MASK                    .equ 0x80
NVBACKKEY1_KEY7_BIT                     .equ 0x07

;*********************************************
;  Backdoor Comparison Key 2
;*********************************************
NVBACKKEY2                              .equ 0x00000402 ;  Backdoor Comparison Key 2
NVBACKKEY2_KEY0_MASK                    .equ 0x01
NVBACKKEY2_KEY0_BIT                     .equ 0x00
NVBACKKEY2_KEY1_MASK                    .equ 0x02
NVBACKKEY2_KEY1_BIT                     .equ 0x01
NVBACKKEY2_KEY2_MASK                    .equ 0x04
NVBACKKEY2_KEY2_BIT                     .equ 0x02
NVBACKKEY2_KEY3_MASK                    .equ 0x08
NVBACKKEY2_KEY3_BIT                     .equ 0x03
NVBACKKEY2_KEY4_MASK                    .equ 0x10
NVBACKKEY2_KEY4_BIT                     .equ 0x04
NVBACKKEY2_KEY5_MASK                    .equ 0x20
NVBACKKEY2_KEY5_BIT                     .equ 0x05
NVBACKKEY2_KEY6_MASK                    .equ 0x40
NVBACKKEY2_KEY6_BIT                     .equ 0x06
NVBACKKEY2_KEY7_MASK                    .equ 0x80
NVBACKKEY2_KEY7_BIT                     .equ 0x07

;*********************************************
;  Backdoor Comparison Key 3
;*********************************************
NVBACKKEY3                              .equ 0x00000403 ;  Backdoor Comparison Key 3
NVBACKKEY3_KEY0_MASK                    .equ 0x01
NVBACKKEY3_KEY0_BIT                     .equ 0x00
NVBACKKEY3_KEY1_MASK                    .equ 0x02
NVBACKKEY3_KEY1_BIT                     .equ 0x01
NVBACKKEY3_KEY2_MASK                    .equ 0x04
NVBACKKEY3_KEY2_BIT                     .equ 0x02
NVBACKKEY3_KEY3_MASK                    .equ 0x08
NVBACKKEY3_KEY3_BIT                     .equ 0x03
NVBACKKEY3_KEY4_MASK                    .equ 0x10
NVBACKKEY3_KEY4_BIT                     .equ 0x04
NVBACKKEY3_KEY5_MASK                    .equ 0x20
NVBACKKEY3_KEY5_BIT                     .equ 0x05
NVBACKKEY3_KEY6_MASK                    .equ 0x40
NVBACKKEY3_KEY6_BIT                     .equ 0x06
NVBACKKEY3_KEY7_MASK                    .equ 0x80
NVBACKKEY3_KEY7_BIT                     .equ 0x07

;*********************************************
;  Backdoor Comparison Key 4
;*********************************************
NVBACKKEY4                              .equ 0x00000404 ;  Backdoor Comparison Key 4
NVBACKKEY4_KEY0_MASK                    .equ 0x01
NVBACKKEY4_KEY0_BIT                     .equ 0x00
NVBACKKEY4_KEY1_MASK                    .equ 0x02
NVBACKKEY4_KEY1_BIT                     .equ 0x01
NVBACKKEY4_KEY2_MASK                    .equ 0x04
NVBACKKEY4_KEY2_BIT                     .equ 0x02
NVBACKKEY4_KEY3_MASK                    .equ 0x08
NVBACKKEY4_KEY3_BIT                     .equ 0x03
NVBACKKEY4_KEY4_MASK                    .equ 0x10
NVBACKKEY4_KEY4_BIT                     .equ 0x04
NVBACKKEY4_KEY5_MASK                    .equ 0x20
NVBACKKEY4_KEY5_BIT                     .equ 0x05
NVBACKKEY4_KEY6_MASK                    .equ 0x40
NVBACKKEY4_KEY6_BIT                     .equ 0x06
NVBACKKEY4_KEY7_MASK                    .equ 0x80
NVBACKKEY4_KEY7_BIT                     .equ 0x07

;*********************************************
;  Backdoor Comparison Key 5
;*********************************************
NVBACKKEY5                              .equ 0x00000405 ;  Backdoor Comparison Key 5
NVBACKKEY5_KEY0_MASK                    .equ 0x01
NVBACKKEY5_KEY0_BIT                     .equ 0x00
NVBACKKEY5_KEY1_MASK                    .equ 0x02
NVBACKKEY5_KEY1_BIT                     .equ 0x01
NVBACKKEY5_KEY2_MASK                    .equ 0x04
NVBACKKEY5_KEY2_BIT                     .equ 0x02
NVBACKKEY5_KEY3_MASK                    .equ 0x08
NVBACKKEY5_KEY3_BIT                     .equ 0x03
NVBACKKEY5_KEY4_MASK                    .equ 0x10
NVBACKKEY5_KEY4_BIT                     .equ 0x04
NVBACKKEY5_KEY5_MASK                    .equ 0x20
NVBACKKEY5_KEY5_BIT                     .equ 0x05
NVBACKKEY5_KEY6_MASK                    .equ 0x40
NVBACKKEY5_KEY6_BIT                     .equ 0x06
NVBACKKEY5_KEY7_MASK                    .equ 0x80
NVBACKKEY5_KEY7_BIT                     .equ 0x07

;*********************************************
;  Backdoor Comparison Key 6
;*********************************************
NVBACKKEY6                              .equ 0x00000406 ;  Backdoor Comparison Key 6
NVBACKKEY6_KEY0_MASK                    .equ 0x01
NVBACKKEY6_KEY0_BIT                     .equ 0x00
NVBACKKEY6_KEY1_MASK                    .equ 0x02
NVBACKKEY6_KEY1_BIT                     .equ 0x01
NVBACKKEY6_KEY2_MASK                    .equ 0x04
NVBACKKEY6_KEY2_BIT                     .equ 0x02
NVBACKKEY6_KEY3_MASK                    .equ 0x08
NVBACKKEY6_KEY3_BIT                     .equ 0x03
NVBACKKEY6_KEY4_MASK                    .equ 0x10
NVBACKKEY6_KEY4_BIT                     .equ 0x04
NVBACKKEY6_KEY5_MASK                    .equ 0x20
NVBACKKEY6_KEY5_BIT                     .equ 0x05
NVBACKKEY6_KEY6_MASK                    .equ 0x40
NVBACKKEY6_KEY6_BIT                     .equ 0x06
NVBACKKEY6_KEY7_MASK                    .equ 0x80
NVBACKKEY6_KEY7_BIT                     .equ 0x07

;*********************************************
;  Backdoor Comparison Key 7
;*********************************************
NVBACKKEY7                              .equ 0x00000407 ;  Backdoor Comparison Key 7
NVBACKKEY7_KEY0_MASK                    .equ 0x01
NVBACKKEY7_KEY0_BIT                     .equ 0x00
NVBACKKEY7_KEY1_MASK                    .equ 0x02
NVBACKKEY7_KEY1_BIT                     .equ 0x01
NVBACKKEY7_KEY2_MASK                    .equ 0x04
NVBACKKEY7_KEY2_BIT                     .equ 0x02
NVBACKKEY7_KEY3_MASK                    .equ 0x08
NVBACKKEY7_KEY3_BIT                     .equ 0x03
NVBACKKEY7_KEY4_MASK                    .equ 0x10
NVBACKKEY7_KEY4_BIT                     .equ 0x04
NVBACKKEY7_KEY5_MASK                    .equ 0x20
NVBACKKEY7_KEY5_BIT                     .equ 0x05
NVBACKKEY7_KEY6_MASK                    .equ 0x40
NVBACKKEY7_KEY6_BIT                     .equ 0x06
NVBACKKEY7_KEY7_MASK                    .equ 0x80
NVBACKKEY7_KEY7_BIT                     .equ 0x07

;*********************************************
;  Nonvolatile Flash Protection Register
;*********************************************
NVPROT                                  .equ 0x0000040D ;  Nonvolatile Flash Protection Register
NVPROT_FPOPEN_MASK                      .equ 0x01
NVPROT_FPOPEN_BIT                       .equ 0x00
NVPROT_FPS0_MASK                        .equ 0x02
NVPROT_FPS0_BIT                         .equ 0x01
NVPROT_FPS1_MASK                        .equ 0x04
NVPROT_FPS1_BIT                         .equ 0x02
NVPROT_FPS2_MASK                        .equ 0x08
NVPROT_FPS2_BIT                         .equ 0x03
NVPROT_FPS3_MASK                        .equ 0x10
NVPROT_FPS3_BIT                         .equ 0x04
NVPROT_FPS4_MASK                        .equ 0x20
NVPROT_FPS4_BIT                         .equ 0x05
NVPROT_FPS5_MASK                        .equ 0x40
NVPROT_FPS5_BIT                         .equ 0x06
NVPROT_FPS6_MASK                        .equ 0x80
NVPROT_FPS6_BIT                         .equ 0x07
NVPROT_FPS_MASK                         .equ 0xFE

;*********************************************
;  Nonvolatile Flash Options Register
;*********************************************
NVOPT                                   .equ 0x0000040F ;  Nonvolatile Flash Options Register
NVOPT_SEC0_MASK                         .equ 0x01
NVOPT_SEC0_BIT                          .equ 0x00
NVOPT_SEC1_MASK                         .equ 0x02
NVOPT_SEC1_BIT                          .equ 0x01
NVOPT_KEYEN0_MASK                       .equ 0x40
NVOPT_KEYEN0_BIT                        .equ 0x06
NVOPT_KEYEN1_MASK                       .equ 0x80
NVOPT_KEYEN1_BIT                        .equ 0x07
NVOPT_SEC_MASK                          .equ 0x03
NVOPT_KEYEN_MASK                        .equ 0xC0

;*********************************************
;  RGPIO Data Direction Register
;*********************************************
RGPIO_DIR                               .equ 0x00C00000 ;  RGPIO Data Direction Register
RGPIO_DIR_DIR0_MASK                     .equ 0x01
RGPIO_DIR_DIR0_BIT                      .equ 0x00
RGPIO_DIR_DIR1_MASK                     .equ 0x02
RGPIO_DIR_DIR1_BIT                      .equ 0x01
RGPIO_DIR_DIR2_MASK                     .equ 0x04
RGPIO_DIR_DIR2_BIT                      .equ 0x02
RGPIO_DIR_DIR3_MASK                     .equ 0x08
RGPIO_DIR_DIR3_BIT                      .equ 0x03
RGPIO_DIR_DIR4_MASK                     .equ 0x10
RGPIO_DIR_DIR4_BIT                      .equ 0x04
RGPIO_DIR_DIR5_MASK                     .equ 0x20
RGPIO_DIR_DIR5_BIT                      .equ 0x05
RGPIO_DIR_DIR6_MASK                     .equ 0x40
RGPIO_DIR_DIR6_BIT                      .equ 0x06
RGPIO_DIR_DIR7_MASK                     .equ 0x80
RGPIO_DIR_DIR7_BIT                      .equ 0x07
RGPIO_DIR_DIR8_MASK                     .equ 0x100
RGPIO_DIR_DIR8_BIT                      .equ 0x08
RGPIO_DIR_DIR9_MASK                     .equ 0x200
RGPIO_DIR_DIR9_BIT                      .equ 0x09
RGPIO_DIR_DIR10_MASK                    .equ 0x400
RGPIO_DIR_DIR10_BIT                     .equ 0x0A
RGPIO_DIR_DIR11_MASK                    .equ 0x800
RGPIO_DIR_DIR11_BIT                     .equ 0x0B
RGPIO_DIR_DIR12_MASK                    .equ 0x1000
RGPIO_DIR_DIR12_BIT                     .equ 0x0C
RGPIO_DIR_DIR13_MASK                    .equ 0x2000
RGPIO_DIR_DIR13_BIT                     .equ 0x0D
RGPIO_DIR_DIR14_MASK                    .equ 0x4000
RGPIO_DIR_DIR14_BIT                     .equ 0x0E
RGPIO_DIR_DIR15_MASK                    .equ 0x8000
RGPIO_DIR_DIR15_BIT                     .equ 0x0F

;*********************************************
;  RGPIO Data Register
;*********************************************
RGPIO_DATA                              .equ 0x00C00002 ;  RGPIO Data Register
RGPIO_DATA_DATA0_MASK                   .equ 0x01
RGPIO_DATA_DATA0_BIT                    .equ 0x00
RGPIO_DATA_DATA1_MASK                   .equ 0x02
RGPIO_DATA_DATA1_BIT                    .equ 0x01
RGPIO_DATA_DATA2_MASK                   .equ 0x04
RGPIO_DATA_DATA2_BIT                    .equ 0x02
RGPIO_DATA_DATA3_MASK                   .equ 0x08
RGPIO_DATA_DATA3_BIT                    .equ 0x03
RGPIO_DATA_DATA4_MASK                   .equ 0x10
RGPIO_DATA_DATA4_BIT                    .equ 0x04
RGPIO_DATA_DATA5_MASK                   .equ 0x20
RGPIO_DATA_DATA5_BIT                    .equ 0x05
RGPIO_DATA_DATA6_MASK                   .equ 0x40
RGPIO_DATA_DATA6_BIT                    .equ 0x06
RGPIO_DATA_DATA7_MASK                   .equ 0x80
RGPIO_DATA_DATA7_BIT                    .equ 0x07
RGPIO_DATA_DATA8_MASK                   .equ 0x100
RGPIO_DATA_DATA8_BIT                    .equ 0x08
RGPIO_DATA_DATA9_MASK                   .equ 0x200
RGPIO_DATA_DATA9_BIT                    .equ 0x09
RGPIO_DATA_DATA10_MASK                  .equ 0x400
RGPIO_DATA_DATA10_BIT                   .equ 0x0A
RGPIO_DATA_DATA11_MASK                  .equ 0x800
RGPIO_DATA_DATA11_BIT                   .equ 0x0B
RGPIO_DATA_DATA12_MASK                  .equ 0x1000
RGPIO_DATA_DATA12_BIT                   .equ 0x0C
RGPIO_DATA_DATA13_MASK                  .equ 0x2000
RGPIO_DATA_DATA13_BIT                   .equ 0x0D
RGPIO_DATA_DATA14_MASK                  .equ 0x4000
RGPIO_DATA_DATA14_BIT                   .equ 0x0E
RGPIO_DATA_DATA15_MASK                  .equ 0x8000
RGPIO_DATA_DATA15_BIT                   .equ 0x0F

;*********************************************
;  RGPIO Pin Enable Register
;*********************************************
RGPIO_ENB                               .equ 0x00C00004 ;  RGPIO Pin Enable Register
RGPIO_ENB_ENB0_MASK                     .equ 0x01
RGPIO_ENB_ENB0_BIT                      .equ 0x00
RGPIO_ENB_ENB1_MASK                     .equ 0x02
RGPIO_ENB_ENB1_BIT                      .equ 0x01
RGPIO_ENB_ENB2_MASK                     .equ 0x04
RGPIO_ENB_ENB2_BIT                      .equ 0x02
RGPIO_ENB_ENB3_MASK                     .equ 0x08
RGPIO_ENB_ENB3_BIT                      .equ 0x03
RGPIO_ENB_ENB4_MASK                     .equ 0x10
RGPIO_ENB_ENB4_BIT                      .equ 0x04
RGPIO_ENB_ENB5_MASK                     .equ 0x20
RGPIO_ENB_ENB5_BIT                      .equ 0x05
RGPIO_ENB_ENB6_MASK                     .equ 0x40
RGPIO_ENB_ENB6_BIT                      .equ 0x06
RGPIO_ENB_ENB7_MASK                     .equ 0x80
RGPIO_ENB_ENB7_BIT                      .equ 0x07
RGPIO_ENB_ENB8_MASK                     .equ 0x100
RGPIO_ENB_ENB8_BIT                      .equ 0x08
RGPIO_ENB_ENB9_MASK                     .equ 0x200
RGPIO_ENB_ENB9_BIT                      .equ 0x09
RGPIO_ENB_ENB10_MASK                    .equ 0x400
RGPIO_ENB_ENB10_BIT                     .equ 0x0A
RGPIO_ENB_ENB11_MASK                    .equ 0x800
RGPIO_ENB_ENB11_BIT                     .equ 0x0B
RGPIO_ENB_ENB12_MASK                    .equ 0x1000
RGPIO_ENB_ENB12_BIT                     .equ 0x0C
RGPIO_ENB_ENB13_MASK                    .equ 0x2000
RGPIO_ENB_ENB13_BIT                     .equ 0x0D
RGPIO_ENB_ENB14_MASK                    .equ 0x4000
RGPIO_ENB_ENB14_BIT                     .equ 0x0E
RGPIO_ENB_ENB15_MASK                    .equ 0x8000
RGPIO_ENB_ENB15_BIT                     .equ 0x0F

;*********************************************
;  RGPIO Clear Data Register
;*********************************************
RGPIO_CLR                               .equ 0x00C00006 ;  RGPIO Clear Data Register
RGPIO_CLR_CLR0_MASK                     .equ 0x01
RGPIO_CLR_CLR0_BIT                      .equ 0x00
RGPIO_CLR_CLR1_MASK                     .equ 0x02
RGPIO_CLR_CLR1_BIT                      .equ 0x01
RGPIO_CLR_CLR2_MASK                     .equ 0x04
RGPIO_CLR_CLR2_BIT                      .equ 0x02
RGPIO_CLR_CLR3_MASK                     .equ 0x08
RGPIO_CLR_CLR3_BIT                      .equ 0x03
RGPIO_CLR_CLR4_MASK                     .equ 0x10
RGPIO_CLR_CLR4_BIT                      .equ 0x04
RGPIO_CLR_CLR5_MASK                     .equ 0x20
RGPIO_CLR_CLR5_BIT                      .equ 0x05
RGPIO_CLR_CLR6_MASK                     .equ 0x40
RGPIO_CLR_CLR6_BIT                      .equ 0x06
RGPIO_CLR_CLR7_MASK                     .equ 0x80
RGPIO_CLR_CLR7_BIT                      .equ 0x07
RGPIO_CLR_CLR8_MASK                     .equ 0x100
RGPIO_CLR_CLR8_BIT                      .equ 0x08
RGPIO_CLR_CLR9_MASK                     .equ 0x200
RGPIO_CLR_CLR9_BIT                      .equ 0x09
RGPIO_CLR_CLR10_MASK                    .equ 0x400
RGPIO_CLR_CLR10_BIT                     .equ 0x0A
RGPIO_CLR_CLR11_MASK                    .equ 0x800
RGPIO_CLR_CLR11_BIT                     .equ 0x0B
RGPIO_CLR_CLR12_MASK                    .equ 0x1000
RGPIO_CLR_CLR12_BIT                     .equ 0x0C
RGPIO_CLR_CLR13_MASK                    .equ 0x2000
RGPIO_CLR_CLR13_BIT                     .equ 0x0D
RGPIO_CLR_CLR14_MASK                    .equ 0x4000
RGPIO_CLR_CLR14_BIT                     .equ 0x0E
RGPIO_CLR_CLR15_MASK                    .equ 0x8000
RGPIO_CLR_CLR15_BIT                     .equ 0x0F

;*********************************************
;  RGPIO Set Data Register
;*********************************************
RGPIO_SET                               .equ 0x00C0000A ;  RGPIO Set Data Register
RGPIO_SET_SET0_MASK                     .equ 0x01
RGPIO_SET_SET0_BIT                      .equ 0x00
RGPIO_SET_SET1_MASK                     .equ 0x02
RGPIO_SET_SET1_BIT                      .equ 0x01
RGPIO_SET_SET2_MASK                     .equ 0x04
RGPIO_SET_SET2_BIT                      .equ 0x02
RGPIO_SET_SET3_MASK                     .equ 0x08
RGPIO_SET_SET3_BIT                      .equ 0x03
RGPIO_SET_SET4_MASK                     .equ 0x10
RGPIO_SET_SET4_BIT                      .equ 0x04
RGPIO_SET_SET5_MASK                     .equ 0x20
RGPIO_SET_SET5_BIT                      .equ 0x05
RGPIO_SET_SET6_MASK                     .equ 0x40
RGPIO_SET_SET6_BIT                      .equ 0x06
RGPIO_SET_SET7_MASK                     .equ 0x80
RGPIO_SET_SET7_BIT                      .equ 0x07
RGPIO_SET_SET8_MASK                     .equ 0x100
RGPIO_SET_SET8_BIT                      .equ 0x08
RGPIO_SET_SET9_MASK                     .equ 0x200
RGPIO_SET_SET9_BIT                      .equ 0x09
RGPIO_SET_SET10_MASK                    .equ 0x400
RGPIO_SET_SET10_BIT                     .equ 0x0A
RGPIO_SET_SET11_MASK                    .equ 0x800
RGPIO_SET_SET11_BIT                     .equ 0x0B
RGPIO_SET_SET12_MASK                    .equ 0x1000
RGPIO_SET_SET12_BIT                     .equ 0x0C
RGPIO_SET_SET13_MASK                    .equ 0x2000
RGPIO_SET_SET13_BIT                     .equ 0x0D
RGPIO_SET_SET14_MASK                    .equ 0x4000
RGPIO_SET_SET14_BIT                     .equ 0x0E
RGPIO_SET_SET15_MASK                    .equ 0x8000
RGPIO_SET_SET15_BIT                     .equ 0x0F

;*********************************************
;  RGPIO Toggle Data Register
;*********************************************
RGPIO_TOG                               .equ 0x00C0000E ;  RGPIO Toggle Data Register
RGPIO_TOG_TOG0_MASK                     .equ 0x01
RGPIO_TOG_TOG0_BIT                      .equ 0x00
RGPIO_TOG_TOG1_MASK                     .equ 0x02
RGPIO_TOG_TOG1_BIT                      .equ 0x01
RGPIO_TOG_TOG2_MASK                     .equ 0x04
RGPIO_TOG_TOG2_BIT                      .equ 0x02
RGPIO_TOG_TOG3_MASK                     .equ 0x08
RGPIO_TOG_TOG3_BIT                      .equ 0x03
RGPIO_TOG_TOG4_MASK                     .equ 0x10
RGPIO_TOG_TOG4_BIT                      .equ 0x04
RGPIO_TOG_TOG5_MASK                     .equ 0x20
RGPIO_TOG_TOG5_BIT                      .equ 0x05
RGPIO_TOG_TOG6_MASK                     .equ 0x40
RGPIO_TOG_TOG6_BIT                      .equ 0x06
RGPIO_TOG_TOG7_MASK                     .equ 0x80
RGPIO_TOG_TOG7_BIT                      .equ 0x07
RGPIO_TOG_TOG8_MASK                     .equ 0x100
RGPIO_TOG_TOG8_BIT                      .equ 0x08
RGPIO_TOG_TOG9_MASK                     .equ 0x200
RGPIO_TOG_TOG9_BIT                      .equ 0x09
RGPIO_TOG_TOG10_MASK                    .equ 0x400
RGPIO_TOG_TOG10_BIT                     .equ 0x0A
RGPIO_TOG_TOG11_MASK                    .equ 0x800
RGPIO_TOG_TOG11_BIT                     .equ 0x0B
RGPIO_TOG_TOG12_MASK                    .equ 0x1000
RGPIO_TOG_TOG12_BIT                     .equ 0x0C
RGPIO_TOG_TOG13_MASK                    .equ 0x2000
RGPIO_TOG_TOG13_BIT                     .equ 0x0D
RGPIO_TOG_TOG14_MASK                    .equ 0x4000
RGPIO_TOG_TOG14_BIT                     .equ 0x0E
RGPIO_TOG_TOG15_MASK                    .equ 0x8000
RGPIO_TOG_TOG15_BIT                     .equ 0x0F

;*********************************************
;  Port A Data Register
;*********************************************
PTAD                                    .equ 0xFFFF8000 ;  Port A Data Register
PTAD_PTAD0_MASK                         .equ 0x01
PTAD_PTAD0_BIT                          .equ 0x00
PTAD_PTAD1_MASK                         .equ 0x02
PTAD_PTAD1_BIT                          .equ 0x01
PTAD_PTAD2_MASK                         .equ 0x04
PTAD_PTAD2_BIT                          .equ 0x02
PTAD_PTAD3_MASK                         .equ 0x08
PTAD_PTAD3_BIT                          .equ 0x03
PTAD_PTAD4_MASK                         .equ 0x10
PTAD_PTAD4_BIT                          .equ 0x04
PTAD_PTAD5_MASK                         .equ 0x20
PTAD_PTAD5_BIT                          .equ 0x05
PTAD_PTAD6_MASK                         .equ 0x40
PTAD_PTAD6_BIT                          .equ 0x06
PTAD_PTAD7_MASK                         .equ 0x80
PTAD_PTAD7_BIT                          .equ 0x07

;*********************************************
;  Port A Data Direction Register
;*********************************************
PTADD                                   .equ 0xFFFF8001 ;  Port A Data Direction Register
PTADD_PTADD0_MASK                       .equ 0x01
PTADD_PTADD0_BIT                        .equ 0x00
PTADD_PTADD1_MASK                       .equ 0x02
PTADD_PTADD1_BIT                        .equ 0x01
PTADD_PTADD2_MASK                       .equ 0x04
PTADD_PTADD2_BIT                        .equ 0x02
PTADD_PTADD3_MASK                       .equ 0x08
PTADD_PTADD3_BIT                        .equ 0x03
PTADD_PTADD4_MASK                       .equ 0x10
PTADD_PTADD4_BIT                        .equ 0x04
PTADD_PTADD5_MASK                       .equ 0x20
PTADD_PTADD5_BIT                        .equ 0x05
PTADD_PTADD6_MASK                       .equ 0x40
PTADD_PTADD6_BIT                        .equ 0x06
PTADD_PTADD7_MASK                       .equ 0x80
PTADD_PTADD7_BIT                        .equ 0x07

;*********************************************
;  Port B Data Register
;*********************************************
PTBD                                    .equ 0xFFFF8002 ;  Port B Data Register
PTBD_PTBD0_MASK                         .equ 0x01
PTBD_PTBD0_BIT                          .equ 0x00
PTBD_PTBD1_MASK                         .equ 0x02
PTBD_PTBD1_BIT                          .equ 0x01
PTBD_PTBD2_MASK                         .equ 0x04
PTBD_PTBD2_BIT                          .equ 0x02
PTBD_PTBD3_MASK                         .equ 0x08
PTBD_PTBD3_BIT                          .equ 0x03
PTBD_PTBD4_MASK                         .equ 0x10
PTBD_PTBD4_BIT                          .equ 0x04
PTBD_PTBD5_MASK                         .equ 0x20
PTBD_PTBD5_BIT                          .equ 0x05
PTBD_PTBD6_MASK                         .equ 0x40
PTBD_PTBD6_BIT                          .equ 0x06
PTBD_PTBD7_MASK                         .equ 0x80
PTBD_PTBD7_BIT                          .equ 0x07

;*********************************************
;  Port B Data Direction Register
;*********************************************
PTBDD                                   .equ 0xFFFF8003 ;  Port B Data Direction Register
PTBDD_PTBDD0_MASK                       .equ 0x01
PTBDD_PTBDD0_BIT                        .equ 0x00
PTBDD_PTBDD1_MASK                       .equ 0x02
PTBDD_PTBDD1_BIT                        .equ 0x01
PTBDD_PTBDD2_MASK                       .equ 0x04
PTBDD_PTBDD2_BIT                        .equ 0x02
PTBDD_PTBDD3_MASK                       .equ 0x08
PTBDD_PTBDD3_BIT                        .equ 0x03
PTBDD_PTBDD4_MASK                       .equ 0x10
PTBDD_PTBDD4_BIT                        .equ 0x04
PTBDD_PTBDD5_MASK                       .equ 0x20
PTBDD_PTBDD5_BIT                        .equ 0x05
PTBDD_PTBDD6_MASK                       .equ 0x40
PTBDD_PTBDD6_BIT                        .equ 0x06
PTBDD_PTBDD7_MASK                       .equ 0x80
PTBDD_PTBDD7_BIT                        .equ 0x07

;*********************************************
;  Port C Data Register
;*********************************************
PTCD                                    .equ 0xFFFF8004 ;  Port C Data Register
PTCD_PTCD0_MASK                         .equ 0x01
PTCD_PTCD0_BIT                          .equ 0x00
PTCD_PTCD1_MASK                         .equ 0x02
PTCD_PTCD1_BIT                          .equ 0x01
PTCD_PTCD2_MASK                         .equ 0x04
PTCD_PTCD2_BIT                          .equ 0x02
PTCD_PTCD3_MASK                         .equ 0x08
PTCD_PTCD3_BIT                          .equ 0x03
PTCD_PTCD4_MASK                         .equ 0x10
PTCD_PTCD4_BIT                          .equ 0x04
PTCD_PTCD5_MASK                         .equ 0x20
PTCD_PTCD5_BIT                          .equ 0x05
PTCD_PTCD6_MASK                         .equ 0x40
PTCD_PTCD6_BIT                          .equ 0x06
PTCD_PTCD7_MASK                         .equ 0x80
PTCD_PTCD7_BIT                          .equ 0x07

;*********************************************
;  Port C Data Direction Register
;*********************************************
PTCDD                                   .equ 0xFFFF8005 ;  Port C Data Direction Register
PTCDD_PTCDD0_MASK                       .equ 0x01
PTCDD_PTCDD0_BIT                        .equ 0x00
PTCDD_PTCDD1_MASK                       .equ 0x02
PTCDD_PTCDD1_BIT                        .equ 0x01
PTCDD_PTCDD2_MASK                       .equ 0x04
PTCDD_PTCDD2_BIT                        .equ 0x02
PTCDD_PTCDD3_MASK                       .equ 0x08
PTCDD_PTCDD3_BIT                        .equ 0x03
PTCDD_PTCDD4_MASK                       .equ 0x10
PTCDD_PTCDD4_BIT                        .equ 0x04
PTCDD_PTCDD5_MASK                       .equ 0x20
PTCDD_PTCDD5_BIT                        .equ 0x05
PTCDD_PTCDD6_MASK                       .equ 0x40
PTCDD_PTCDD6_BIT                        .equ 0x06
PTCDD_PTCDD7_MASK                       .equ 0x80
PTCDD_PTCDD7_BIT                        .equ 0x07

;*********************************************
;  Port D Data Register
;*********************************************
PTDD                                    .equ 0xFFFF8006 ;  Port D Data Register
PTDD_PTDD0_MASK                         .equ 0x01
PTDD_PTDD0_BIT                          .equ 0x00
PTDD_PTDD1_MASK                         .equ 0x02
PTDD_PTDD1_BIT                          .equ 0x01
PTDD_PTDD2_MASK                         .equ 0x04
PTDD_PTDD2_BIT                          .equ 0x02
PTDD_PTDD3_MASK                         .equ 0x08
PTDD_PTDD3_BIT                          .equ 0x03
PTDD_PTDD4_MASK                         .equ 0x10
PTDD_PTDD4_BIT                          .equ 0x04
PTDD_PTDD5_MASK                         .equ 0x20
PTDD_PTDD5_BIT                          .equ 0x05
PTDD_PTDD6_MASK                         .equ 0x40
PTDD_PTDD6_BIT                          .equ 0x06
PTDD_PTDD7_MASK                         .equ 0x80
PTDD_PTDD7_BIT                          .equ 0x07

;*********************************************
;  Port D Data Direction Register
;*********************************************
PTDDD                                   .equ 0xFFFF8007 ;  Port D Data Direction Register
PTDDD_PTDDD0_MASK                       .equ 0x01
PTDDD_PTDDD0_BIT                        .equ 0x00
PTDDD_PTDDD1_MASK                       .equ 0x02
PTDDD_PTDDD1_BIT                        .equ 0x01
PTDDD_PTDDD2_MASK                       .equ 0x04
PTDDD_PTDDD2_BIT                        .equ 0x02
PTDDD_PTDDD3_MASK                       .equ 0x08
PTDDD_PTDDD3_BIT                        .equ 0x03
PTDDD_PTDDD4_MASK                       .equ 0x10
PTDDD_PTDDD4_BIT                        .equ 0x04
PTDDD_PTDDD5_MASK                       .equ 0x20
PTDDD_PTDDD5_BIT                        .equ 0x05
PTDDD_PTDDD6_MASK                       .equ 0x40
PTDDD_PTDDD6_BIT                        .equ 0x06
PTDDD_PTDDD7_MASK                       .equ 0x80
PTDDD_PTDDD7_BIT                        .equ 0x07

;*********************************************
;  Port E Data Register
;*********************************************
PTED                                    .equ 0xFFFF8008 ;  Port E Data Register
PTED_PTED0_MASK                         .equ 0x01
PTED_PTED0_BIT                          .equ 0x00
PTED_PTED1_MASK                         .equ 0x02
PTED_PTED1_BIT                          .equ 0x01
PTED_PTED2_MASK                         .equ 0x04
PTED_PTED2_BIT                          .equ 0x02
PTED_PTED3_MASK                         .equ 0x08
PTED_PTED3_BIT                          .equ 0x03
PTED_PTED4_MASK                         .equ 0x10
PTED_PTED4_BIT                          .equ 0x04
PTED_PTED5_MASK                         .equ 0x20
PTED_PTED5_BIT                          .equ 0x05
PTED_PTED6_MASK                         .equ 0x40
PTED_PTED6_BIT                          .equ 0x06
PTED_PTED7_MASK                         .equ 0x80
PTED_PTED7_BIT                          .equ 0x07

;*********************************************
;  Port E Data Direction Register
;*********************************************
PTEDD                                   .equ 0xFFFF8009 ;  Port E Data Direction Register
PTEDD_PTEDD0_MASK                       .equ 0x01
PTEDD_PTEDD0_BIT                        .equ 0x00
PTEDD_PTEDD1_MASK                       .equ 0x02
PTEDD_PTEDD1_BIT                        .equ 0x01
PTEDD_PTEDD2_MASK                       .equ 0x04
PTEDD_PTEDD2_BIT                        .equ 0x02
PTEDD_PTEDD3_MASK                       .equ 0x08
PTEDD_PTEDD3_BIT                        .equ 0x03
PTEDD_PTEDD4_MASK                       .equ 0x10
PTEDD_PTEDD4_BIT                        .equ 0x04
PTEDD_PTEDD5_MASK                       .equ 0x20
PTEDD_PTEDD5_BIT                        .equ 0x05
PTEDD_PTEDD6_MASK                       .equ 0x40
PTEDD_PTEDD6_BIT                        .equ 0x06
PTEDD_PTEDD7_MASK                       .equ 0x80
PTEDD_PTEDD7_BIT                        .equ 0x07

;*********************************************
;  Port F Data Register
;*********************************************
PTFD                                    .equ 0xFFFF800A ;  Port F Data Register
PTFD_PTFD0_MASK                         .equ 0x01
PTFD_PTFD0_BIT                          .equ 0x00
PTFD_PTFD1_MASK                         .equ 0x02
PTFD_PTFD1_BIT                          .equ 0x01
PTFD_PTFD2_MASK                         .equ 0x04
PTFD_PTFD2_BIT                          .equ 0x02
PTFD_PTFD3_MASK                         .equ 0x08
PTFD_PTFD3_BIT                          .equ 0x03
PTFD_PTFD4_MASK                         .equ 0x10
PTFD_PTFD4_BIT                          .equ 0x04
PTFD_PTFD5_MASK                         .equ 0x20
PTFD_PTFD5_BIT                          .equ 0x05
PTFD_PTFD6_MASK                         .equ 0x40
PTFD_PTFD6_BIT                          .equ 0x06
PTFD_PTFD7_MASK                         .equ 0x80
PTFD_PTFD7_BIT                          .equ 0x07

;*********************************************
;  Port F Data Direction Register
;*********************************************
PTFDD                                   .equ 0xFFFF800B ;  Port F Data Direction Register
PTFDD_PTFDD0_MASK                       .equ 0x01
PTFDD_PTFDD0_BIT                        .equ 0x00
PTFDD_PTFDD1_MASK                       .equ 0x02
PTFDD_PTFDD1_BIT                        .equ 0x01
PTFDD_PTFDD2_MASK                       .equ 0x04
PTFDD_PTFDD2_BIT                        .equ 0x02
PTFDD_PTFDD3_MASK                       .equ 0x08
PTFDD_PTFDD3_BIT                        .equ 0x03
PTFDD_PTFDD4_MASK                       .equ 0x10
PTFDD_PTFDD4_BIT                        .equ 0x04
PTFDD_PTFDD5_MASK                       .equ 0x20
PTFDD_PTFDD5_BIT                        .equ 0x05
PTFDD_PTFDD6_MASK                       .equ 0x40
PTFDD_PTFDD6_BIT                        .equ 0x06
PTFDD_PTFDD7_MASK                       .equ 0x80
PTFDD_PTFDD7_BIT                        .equ 0x07

;*********************************************
;  Port G Data Register
;*********************************************
PTGD                                    .equ 0xFFFF800C ;  Port G Data Register
PTGD_PTGD0_MASK                         .equ 0x01
PTGD_PTGD0_BIT                          .equ 0x00
PTGD_PTGD1_MASK                         .equ 0x02
PTGD_PTGD1_BIT                          .equ 0x01
PTGD_PTGD2_MASK                         .equ 0x04
PTGD_PTGD2_BIT                          .equ 0x02
PTGD_PTGD3_MASK                         .equ 0x08
PTGD_PTGD3_BIT                          .equ 0x03
PTGD_PTGD4_MASK                         .equ 0x10
PTGD_PTGD4_BIT                          .equ 0x04
PTGD_PTGD5_MASK                         .equ 0x20
PTGD_PTGD5_BIT                          .equ 0x05
PTGD_PTGD6_MASK                         .equ 0x40
PTGD_PTGD6_BIT                          .equ 0x06
PTGD_PTGD7_MASK                         .equ 0x80
PTGD_PTGD7_BIT                          .equ 0x07

;*********************************************
;  Port G Data Direction Register
;*********************************************
PTGDD                                   .equ 0xFFFF800D ;  Port G Data Direction Register
PTGDD_PTGDD0_MASK                       .equ 0x01
PTGDD_PTGDD0_BIT                        .equ 0x00
PTGDD_PTGDD1_MASK                       .equ 0x02
PTGDD_PTGDD1_BIT                        .equ 0x01
PTGDD_PTGDD2_MASK                       .equ 0x04
PTGDD_PTGDD2_BIT                        .equ 0x02
PTGDD_PTGDD3_MASK                       .equ 0x08
PTGDD_PTGDD3_BIT                        .equ 0x03
PTGDD_PTGDD4_MASK                       .equ 0x10
PTGDD_PTGDD4_BIT                        .equ 0x04
PTGDD_PTGDD5_MASK                       .equ 0x20
PTGDD_PTGDD5_BIT                        .equ 0x05
PTGDD_PTGDD6_MASK                       .equ 0x40
PTGDD_PTGDD6_BIT                        .equ 0x06
PTGDD_PTGDD7_MASK                       .equ 0x80
PTGDD_PTGDD7_BIT                        .equ 0x07

;*********************************************
;  ACMP Status and Control Register
;*********************************************
ACMPSC                                  .equ 0xFFFF800E ;  ACMP Status and Control Register
ACMPSC_ACMOD0_MASK                      .equ 0x01
ACMPSC_ACMOD0_BIT                       .equ 0x00
ACMPSC_ACMOD1_MASK                      .equ 0x02
ACMPSC_ACMOD1_BIT                       .equ 0x01
ACMPSC_ACOPE_MASK                       .equ 0x04
ACMPSC_ACOPE_BIT                        .equ 0x02
ACMPSC_ACO_MASK                         .equ 0x08
ACMPSC_ACO_BIT                          .equ 0x03
ACMPSC_ACIE_MASK                        .equ 0x10
ACMPSC_ACIE_BIT                         .equ 0x04
ACMPSC_ACF_MASK                         .equ 0x20
ACMPSC_ACF_BIT                          .equ 0x05
ACMPSC_ACBGS_MASK                       .equ 0x40
ACMPSC_ACBGS_BIT                        .equ 0x06
ACMPSC_ACME_MASK                        .equ 0x80
ACMPSC_ACME_BIT                         .equ 0x07
ACMPSC_ACMOD_MASK                       .equ 0x03

;*********************************************
;  Status and Control Register 1
;*********************************************
ADCSC1                                  .equ 0xFFFF8010 ;  Status and Control Register 1
ADCSC1_ADCH0_MASK                       .equ 0x01
ADCSC1_ADCH0_BIT                        .equ 0x00
ADCSC1_ADCH1_MASK                       .equ 0x02
ADCSC1_ADCH1_BIT                        .equ 0x01
ADCSC1_ADCH2_MASK                       .equ 0x04
ADCSC1_ADCH2_BIT                        .equ 0x02
ADCSC1_ADCH3_MASK                       .equ 0x08
ADCSC1_ADCH3_BIT                        .equ 0x03
ADCSC1_ADCH4_MASK                       .equ 0x10
ADCSC1_ADCH4_BIT                        .equ 0x04
ADCSC1_ADCO_MASK                        .equ 0x20
ADCSC1_ADCO_BIT                         .equ 0x05
ADCSC1_AIEN_MASK                        .equ 0x40
ADCSC1_AIEN_BIT                         .equ 0x06
ADCSC1_COCO_MASK                        .equ 0x80
ADCSC1_COCO_BIT                         .equ 0x07
ADCSC1_ADCH_MASK                        .equ 0x1F

;*********************************************
;  Status and Control Register 2
;*********************************************
ADCSC2                                  .equ 0xFFFF8011 ;  Status and Control Register 2
ADCSC2_ACFGT_MASK                       .equ 0x10
ADCSC2_ACFGT_BIT                        .equ 0x04
ADCSC2_ACFE_MASK                        .equ 0x20
ADCSC2_ACFE_BIT                         .equ 0x05
ADCSC2_ADTRG_MASK                       .equ 0x40
ADCSC2_ADTRG_BIT                        .equ 0x06
ADCSC2_ADACT_MASK                       .equ 0x80
ADCSC2_ADACT_BIT                        .equ 0x07

;*********************************************
;  Data Result Register
;*********************************************
ADCRH_ADR8_MASK                         .equ 0x01
ADCRH_ADR8_BIT                          .equ 0x00
ADCRH_ADR9_MASK                         .equ 0x02
ADCRH_ADR9_BIT                          .equ 0x01
ADCRH_ADR10_MASK                        .equ 0x04
ADCRH_ADR10_BIT                         .equ 0x02
ADCRH_ADR11_MASK                        .equ 0x08
ADCRH_ADR11_BIT                         .equ 0x03
ADCRH_ADR_8_MASK                        .equ 0x0F
ADCRL_ADR0_MASK                         .equ 0x01
ADCRL_ADR0_BIT                          .equ 0x00
ADCRL_ADR1_MASK                         .equ 0x02
ADCRL_ADR1_BIT                          .equ 0x01
ADCRL_ADR2_MASK                         .equ 0x04
ADCRL_ADR2_BIT                          .equ 0x02
ADCRL_ADR3_MASK                         .equ 0x08
ADCRL_ADR3_BIT                          .equ 0x03
ADCRL_ADR4_MASK                         .equ 0x10
ADCRL_ADR4_BIT                          .equ 0x04
ADCRL_ADR5_MASK                         .equ 0x20
ADCRL_ADR5_BIT                          .equ 0x05
ADCRL_ADR6_MASK                         .equ 0x40
ADCRL_ADR6_BIT                          .equ 0x06
ADCRL_ADR7_MASK                         .equ 0x80
ADCRL_ADR7_BIT                          .equ 0x07
ADCR                                    .equ 0xFFFF8012 ;  Data Result Register
ADCR_ADR0_MASK                          .equ 0x01
ADCR_ADR0_BIT                           .equ 0x00
ADCR_ADR1_MASK                          .equ 0x02
ADCR_ADR1_BIT                           .equ 0x01
ADCR_ADR2_MASK                          .equ 0x04
ADCR_ADR2_BIT                           .equ 0x02
ADCR_ADR3_MASK                          .equ 0x08
ADCR_ADR3_BIT                           .equ 0x03
ADCR_ADR4_MASK                          .equ 0x10
ADCR_ADR4_BIT                           .equ 0x04
ADCR_ADR5_MASK                          .equ 0x20
ADCR_ADR5_BIT                           .equ 0x05
ADCR_ADR6_MASK                          .equ 0x40
ADCR_ADR6_BIT                           .equ 0x06
ADCR_ADR7_MASK                          .equ 0x80
ADCR_ADR7_BIT                           .equ 0x07
ADCR_ADR8_MASK                          .equ 0x100
ADCR_ADR8_BIT                           .equ 0x08
ADCR_ADR9_MASK                          .equ 0x200
ADCR_ADR9_BIT                           .equ 0x09
ADCR_ADR10_MASK                         .equ 0x400
ADCR_ADR10_BIT                          .equ 0x0A
ADCR_ADR11_MASK                         .equ 0x800
ADCR_ADR11_BIT                          .equ 0x0B
ADCR_ADR_MASK                           .equ 0xFFF

;*********************************************
;  Compare Value Register
;*********************************************
ADCCVH_ADCV8_MASK                       .equ 0x01
ADCCVH_ADCV8_BIT                        .equ 0x00
ADCCVH_ADCV9_MASK                       .equ 0x02
ADCCVH_ADCV9_BIT                        .equ 0x01
ADCCVH_ADCV10_MASK                      .equ 0x04
ADCCVH_ADCV10_BIT                       .equ 0x02
ADCCVH_ADCV11_MASK                      .equ 0x08
ADCCVH_ADCV11_BIT                       .equ 0x03
ADCCVH_ADCV_8_MASK                      .equ 0x0F
ADCCVL_ADCV0_MASK                       .equ 0x01
ADCCVL_ADCV0_BIT                        .equ 0x00
ADCCVL_ADCV1_MASK                       .equ 0x02
ADCCVL_ADCV1_BIT                        .equ 0x01
ADCCVL_ADCV2_MASK                       .equ 0x04
ADCCVL_ADCV2_BIT                        .equ 0x02
ADCCVL_ADCV3_MASK                       .equ 0x08
ADCCVL_ADCV3_BIT                        .equ 0x03
ADCCVL_ADCV4_MASK                       .equ 0x10
ADCCVL_ADCV4_BIT                        .equ 0x04
ADCCVL_ADCV5_MASK                       .equ 0x20
ADCCVL_ADCV5_BIT                        .equ 0x05
ADCCVL_ADCV6_MASK                       .equ 0x40
ADCCVL_ADCV6_BIT                        .equ 0x06
ADCCVL_ADCV7_MASK                       .equ 0x80
ADCCVL_ADCV7_BIT                        .equ 0x07
ADCCV                                   .equ 0xFFFF8014 ;  Compare Value Register
ADCCV_ADCV0_MASK                        .equ 0x01
ADCCV_ADCV0_BIT                         .equ 0x00
ADCCV_ADCV1_MASK                        .equ 0x02
ADCCV_ADCV1_BIT                         .equ 0x01
ADCCV_ADCV2_MASK                        .equ 0x04
ADCCV_ADCV2_BIT                         .equ 0x02
ADCCV_ADCV3_MASK                        .equ 0x08
ADCCV_ADCV3_BIT                         .equ 0x03
ADCCV_ADCV4_MASK                        .equ 0x10
ADCCV_ADCV4_BIT                         .equ 0x04
ADCCV_ADCV5_MASK                        .equ 0x20
ADCCV_ADCV5_BIT                         .equ 0x05
ADCCV_ADCV6_MASK                        .equ 0x40
ADCCV_ADCV6_BIT                         .equ 0x06
ADCCV_ADCV7_MASK                        .equ 0x80
ADCCV_ADCV7_BIT                         .equ 0x07
ADCCV_ADCV8_MASK                        .equ 0x100
ADCCV_ADCV8_BIT                         .equ 0x08
ADCCV_ADCV9_MASK                        .equ 0x200
ADCCV_ADCV9_BIT                         .equ 0x09
ADCCV_ADCV10_MASK                       .equ 0x400
ADCCV_ADCV10_BIT                        .equ 0x0A
ADCCV_ADCV11_MASK                       .equ 0x800
ADCCV_ADCV11_BIT                        .equ 0x0B
ADCCV_ADCV_MASK                         .equ 0xFFF

;*********************************************
;  Configuration Register
;*********************************************
ADCCFG                                  .equ 0xFFFF8016 ;  Configuration Register
ADCCFG_ADICLK0_MASK                     .equ 0x01
ADCCFG_ADICLK0_BIT                      .equ 0x00
ADCCFG_ADICLK1_MASK                     .equ 0x02
ADCCFG_ADICLK1_BIT                      .equ 0x01
ADCCFG_MODE0_MASK                       .equ 0x04
ADCCFG_MODE0_BIT                        .equ 0x02
ADCCFG_MODE1_MASK                       .equ 0x08
ADCCFG_MODE1_BIT                        .equ 0x03
ADCCFG_ADLSMP_MASK                      .equ 0x10
ADCCFG_ADLSMP_BIT                       .equ 0x04
ADCCFG_ADIV0_MASK                       .equ 0x20
ADCCFG_ADIV0_BIT                        .equ 0x05
ADCCFG_ADIV1_MASK                       .equ 0x40
ADCCFG_ADIV1_BIT                        .equ 0x06
ADCCFG_ADLPC_MASK                       .equ 0x80
ADCCFG_ADLPC_BIT                        .equ 0x07
ADCCFG_ADICLK_MASK                      .equ 0x03
ADCCFG_MODE_MASK                        .equ 0x0C
ADCCFG_ADIV_MASK                        .equ 0x60

;*********************************************
;  Pin Control 1 Register
;*********************************************
APCTL1                                  .equ 0xFFFF8017 ;  Pin Control 1 Register
APCTL1_ADPC0_MASK                       .equ 0x01
APCTL1_ADPC0_BIT                        .equ 0x00
APCTL1_ADPC1_MASK                       .equ 0x02
APCTL1_ADPC1_BIT                        .equ 0x01
APCTL1_ADPC2_MASK                       .equ 0x04
APCTL1_ADPC2_BIT                        .equ 0x02
APCTL1_ADPC3_MASK                       .equ 0x08
APCTL1_ADPC3_BIT                        .equ 0x03
APCTL1_ADPC4_MASK                       .equ 0x10
APCTL1_ADPC4_BIT                        .equ 0x04
APCTL1_ADPC5_MASK                       .equ 0x20
APCTL1_ADPC5_BIT                        .equ 0x05
APCTL1_ADPC6_MASK                       .equ 0x40
APCTL1_ADPC6_BIT                        .equ 0x06
APCTL1_ADPC7_MASK                       .equ 0x80
APCTL1_ADPC7_BIT                        .equ 0x07

;*********************************************
;  Pin Control 2 Register
;*********************************************
APCTL2                                  .equ 0xFFFF8018 ;  Pin Control 2 Register
APCTL2_ADPC8_MASK                       .equ 0x01
APCTL2_ADPC8_BIT                        .equ 0x00
APCTL2_ADPC9_MASK                       .equ 0x02
APCTL2_ADPC9_BIT                        .equ 0x01
APCTL2_ADPC10_MASK                      .equ 0x04
APCTL2_ADPC10_BIT                       .equ 0x02
APCTL2_ADPC11_MASK                      .equ 0x08
APCTL2_ADPC11_BIT                       .equ 0x03
APCTL2_ADPC_8_MASK                      .equ 0x0F

;*********************************************
;  Interrupt request status and control register
;*********************************************
IRQSC                                   .equ 0xFFFF801B ;  Interrupt request status and control register
IRQSC_IRQMOD_MASK                       .equ 0x01
IRQSC_IRQMOD_BIT                        .equ 0x00
IRQSC_IRQIE_MASK                        .equ 0x02
IRQSC_IRQIE_BIT                         .equ 0x01
IRQSC_IRQACK_MASK                       .equ 0x04
IRQSC_IRQACK_BIT                        .equ 0x02
IRQSC_IRQF_MASK                         .equ 0x08
IRQSC_IRQF_BIT                          .equ 0x03
IRQSC_IRQPE_MASK                        .equ 0x10
IRQSC_IRQPE_BIT                         .equ 0x04
IRQSC_IRQEDG_MASK                       .equ 0x20
IRQSC_IRQEDG_BIT                        .equ 0x05
IRQSC_IRQPDD_MASK                       .equ 0x40
IRQSC_IRQPDD_BIT                        .equ 0x06

;*********************************************
;  KBI1 Status and Control Register
;*********************************************
KBI1SC                                  .equ 0xFFFF801C ;  KBI1 Status and Control Register
KBI1SC_KBIMOD_MASK                      .equ 0x01
KBI1SC_KBIMOD_BIT                       .equ 0x00
KBI1SC_KBIE_MASK                        .equ 0x02
KBI1SC_KBIE_BIT                         .equ 0x01
KBI1SC_KBACK_MASK                       .equ 0x04
KBI1SC_KBACK_BIT                        .equ 0x02
KBI1SC_KBF_MASK                         .equ 0x08
KBI1SC_KBF_BIT                          .equ 0x03

;*********************************************
;  KBI1 Pin Enable Register
;*********************************************
KBI1PE                                  .equ 0xFFFF801D ;  KBI1 Pin Enable Register
KBI1PE_KBIPE0_MASK                      .equ 0x01
KBI1PE_KBIPE0_BIT                       .equ 0x00
KBI1PE_KBIPE1_MASK                      .equ 0x02
KBI1PE_KBIPE1_BIT                       .equ 0x01
KBI1PE_KBIPE2_MASK                      .equ 0x04
KBI1PE_KBIPE2_BIT                       .equ 0x02
KBI1PE_KBIPE3_MASK                      .equ 0x08
KBI1PE_KBIPE3_BIT                       .equ 0x03
KBI1PE_KBIPE4_MASK                      .equ 0x10
KBI1PE_KBIPE4_BIT                       .equ 0x04
KBI1PE_KBIPE5_MASK                      .equ 0x20
KBI1PE_KBIPE5_BIT                       .equ 0x05
KBI1PE_KBIPE6_MASK                      .equ 0x40
KBI1PE_KBIPE6_BIT                       .equ 0x06
KBI1PE_KBIPE7_MASK                      .equ 0x80
KBI1PE_KBIPE7_BIT                       .equ 0x07

;*********************************************
;  KBI1 Edge Select Register
;*********************************************
KBI1ES                                  .equ 0xFFFF801E ;  KBI1 Edge Select Register
KBI1ES_KBEDG0_MASK                      .equ 0x01
KBI1ES_KBEDG0_BIT                       .equ 0x00
KBI1ES_KBEDG1_MASK                      .equ 0x02
KBI1ES_KBEDG1_BIT                       .equ 0x01
KBI1ES_KBEDG2_MASK                      .equ 0x04
KBI1ES_KBEDG2_BIT                       .equ 0x02
KBI1ES_KBEDG3_MASK                      .equ 0x08
KBI1ES_KBEDG3_BIT                       .equ 0x03
KBI1ES_KBEDG4_MASK                      .equ 0x10
KBI1ES_KBEDG4_BIT                       .equ 0x04
KBI1ES_KBEDG5_MASK                      .equ 0x20
KBI1ES_KBEDG5_BIT                       .equ 0x05
KBI1ES_KBEDG6_MASK                      .equ 0x40
KBI1ES_KBEDG6_BIT                       .equ 0x06
KBI1ES_KBEDG7_MASK                      .equ 0x80
KBI1ES_KBEDG7_BIT                       .equ 0x07

;*********************************************
;  TPM1 Status and Control Register
;*********************************************
TPM1SC                                  .equ 0xFFFF8020 ;  TPM1 Status and Control Register
TPM1SC_PS0_MASK                         .equ 0x01
TPM1SC_PS0_BIT                          .equ 0x00
TPM1SC_PS1_MASK                         .equ 0x02
TPM1SC_PS1_BIT                          .equ 0x01
TPM1SC_PS2_MASK                         .equ 0x04
TPM1SC_PS2_BIT                          .equ 0x02
TPM1SC_CLKSA_MASK                       .equ 0x08
TPM1SC_CLKSA_BIT                        .equ 0x03
TPM1SC_CLKSB_MASK                       .equ 0x10
TPM1SC_CLKSB_BIT                        .equ 0x04
TPM1SC_CPWMS_MASK                       .equ 0x20
TPM1SC_CPWMS_BIT                        .equ 0x05
TPM1SC_TOIE_MASK                        .equ 0x40
TPM1SC_TOIE_BIT                         .equ 0x06
TPM1SC_TOF_MASK                         .equ 0x80
TPM1SC_TOF_BIT                          .equ 0x07
TPM1SC_PS_MASK                          .equ 0x07
TPM1SC_CLKSx_MASK                       .equ 0x18

;*********************************************
;  TPM1 Timer Counter Register
;*********************************************
TPM1CNT                                 .equ 0xFFFF8021 ;  TPM1 Timer Counter Register

;*********************************************
;  TPM1 Timer Counter Modulo Register
;*********************************************
TPM1MOD                                 .equ 0xFFFF8023 ;  TPM1 Timer Counter Modulo Register

;*********************************************
;  TPM1 Timer Channel 0 Status and Control Register
;*********************************************
TPM1C0SC                                .equ 0xFFFF8025 ;  TPM1 Timer Channel 0 Status and Control Register
TPM1C0SC_ELS0A_MASK                     .equ 0x04
TPM1C0SC_ELS0A_BIT                      .equ 0x02
TPM1C0SC_ELS0B_MASK                     .equ 0x08
TPM1C0SC_ELS0B_BIT                      .equ 0x03
TPM1C0SC_MS0A_MASK                      .equ 0x10
TPM1C0SC_MS0A_BIT                       .equ 0x04
TPM1C0SC_MS0B_MASK                      .equ 0x20
TPM1C0SC_MS0B_BIT                       .equ 0x05
TPM1C0SC_CH0IE_MASK                     .equ 0x40
TPM1C0SC_CH0IE_BIT                      .equ 0x06
TPM1C0SC_CH0F_MASK                      .equ 0x80
TPM1C0SC_CH0F_BIT                       .equ 0x07
TPM1C0SC_ELS0x_MASK                     .equ 0x0C
TPM1C0SC_MS0x_MASK                      .equ 0x30

;*********************************************
;  TPM1 Timer Channel 0 Value Register
;*********************************************
TPM1C0V                                 .equ 0xFFFF8026 ;  TPM1 Timer Channel 0 Value Register

;*********************************************
;  TPM1 Timer Channel 1 Status and Control Register
;*********************************************
TPM1C1SC                                .equ 0xFFFF8028 ;  TPM1 Timer Channel 1 Status and Control Register
TPM1C1SC_ELS1A_MASK                     .equ 0x04
TPM1C1SC_ELS1A_BIT                      .equ 0x02
TPM1C1SC_ELS1B_MASK                     .equ 0x08
TPM1C1SC_ELS1B_BIT                      .equ 0x03
TPM1C1SC_MS1A_MASK                      .equ 0x10
TPM1C1SC_MS1A_BIT                       .equ 0x04
TPM1C1SC_MS1B_MASK                      .equ 0x20
TPM1C1SC_MS1B_BIT                       .equ 0x05
TPM1C1SC_CH1IE_MASK                     .equ 0x40
TPM1C1SC_CH1IE_BIT                      .equ 0x06
TPM1C1SC_CH1F_MASK                      .equ 0x80
TPM1C1SC_CH1F_BIT                       .equ 0x07
TPM1C1SC_ELS1x_MASK                     .equ 0x0C
TPM1C1SC_MS1x_MASK                      .equ 0x30

;*********************************************
;  TPM1 Timer Channel 1 Value Register
;*********************************************
TPM1C1V                                 .equ 0xFFFF8029 ;  TPM1 Timer Channel 1 Value Register

;*********************************************
;  TPM1 Timer Channel 2 Status and Control Register
;*********************************************
TPM1C2SC                                .equ 0xFFFF802B ;  TPM1 Timer Channel 2 Status and Control Register
TPM1C2SC_ELS2A_MASK                     .equ 0x04
TPM1C2SC_ELS2A_BIT                      .equ 0x02
TPM1C2SC_ELS2B_MASK                     .equ 0x08
TPM1C2SC_ELS2B_BIT                      .equ 0x03
TPM1C2SC_MS2A_MASK                      .equ 0x10
TPM1C2SC_MS2A_BIT                       .equ 0x04
TPM1C2SC_MS2B_MASK                      .equ 0x20
TPM1C2SC_MS2B_BIT                       .equ 0x05
TPM1C2SC_CH2IE_MASK                     .equ 0x40
TPM1C2SC_CH2IE_BIT                      .equ 0x06
TPM1C2SC_CH2F_MASK                      .equ 0x80
TPM1C2SC_CH2F_BIT                       .equ 0x07
TPM1C2SC_ELS2x_MASK                     .equ 0x0C
TPM1C2SC_MS2x_MASK                      .equ 0x30

;*********************************************
;  TPM1 Timer Channel 2 Value Register
;*********************************************
TPM1C2V                                 .equ 0xFFFF802C ;  TPM1 Timer Channel 2 Value Register

;*********************************************
;  TPM1 Timer Channel 3 Status and Control Register
;*********************************************
TPM1C3SC                                .equ 0xFFFF802E ;  TPM1 Timer Channel 3 Status and Control Register
TPM1C3SC_ELS3A_MASK                     .equ 0x04
TPM1C3SC_ELS3A_BIT                      .equ 0x02
TPM1C3SC_ELS3B_MASK                     .equ 0x08
TPM1C3SC_ELS3B_BIT                      .equ 0x03
TPM1C3SC_MS3A_MASK                      .equ 0x10
TPM1C3SC_MS3A_BIT                       .equ 0x04
TPM1C3SC_MS3B_MASK                      .equ 0x20
TPM1C3SC_MS3B_BIT                       .equ 0x05
TPM1C3SC_CH3IE_MASK                     .equ 0x40
TPM1C3SC_CH3IE_BIT                      .equ 0x06
TPM1C3SC_CH3F_MASK                      .equ 0x80
TPM1C3SC_CH3F_BIT                       .equ 0x07
TPM1C3SC_ELS3x_MASK                     .equ 0x0C
TPM1C3SC_MS3x_MASK                      .equ 0x30

;*********************************************
;  TPM1 Timer Channel 3 Value Register
;*********************************************
TPM1C3V                                 .equ 0xFFFF802F ;  TPM1 Timer Channel 3 Value Register

;*********************************************
;  TPM1 Timer Channel 4 Status and Control Register
;*********************************************
TPM1C4SC                                .equ 0xFFFF8031 ;  TPM1 Timer Channel 4 Status and Control Register
TPM1C4SC_ELS4A_MASK                     .equ 0x04
TPM1C4SC_ELS4A_BIT                      .equ 0x02
TPM1C4SC_ELS4B_MASK                     .equ 0x08
TPM1C4SC_ELS4B_BIT                      .equ 0x03
TPM1C4SC_MS4A_MASK                      .equ 0x10
TPM1C4SC_MS4A_BIT                       .equ 0x04
TPM1C4SC_MS4B_MASK                      .equ 0x20
TPM1C4SC_MS4B_BIT                       .equ 0x05
TPM1C4SC_CH4IE_MASK                     .equ 0x40
TPM1C4SC_CH4IE_BIT                      .equ 0x06
TPM1C4SC_CH4F_MASK                      .equ 0x80
TPM1C4SC_CH4F_BIT                       .equ 0x07
TPM1C4SC_ELS4x_MASK                     .equ 0x0C
TPM1C4SC_MS4x_MASK                      .equ 0x30

;*********************************************
;  TPM1 Timer Channel 4 Value Register
;*********************************************
TPM1C4V                                 .equ 0xFFFF8032 ;  TPM1 Timer Channel 4 Value Register

;*********************************************
;  TPM1 Timer Channel 5 Status and Control Register
;*********************************************
TPM1C5SC                                .equ 0xFFFF8034 ;  TPM1 Timer Channel 5 Status and Control Register
TPM1C5SC_ELS5A_MASK                     .equ 0x04
TPM1C5SC_ELS5A_BIT                      .equ 0x02
TPM1C5SC_ELS5B_MASK                     .equ 0x08
TPM1C5SC_ELS5B_BIT                      .equ 0x03
TPM1C5SC_MS5A_MASK                      .equ 0x10
TPM1C5SC_MS5A_BIT                       .equ 0x04
TPM1C5SC_MS5B_MASK                      .equ 0x20
TPM1C5SC_MS5B_BIT                       .equ 0x05
TPM1C5SC_CH5IE_MASK                     .equ 0x40
TPM1C5SC_CH5IE_BIT                      .equ 0x06
TPM1C5SC_CH5F_MASK                      .equ 0x80
TPM1C5SC_CH5F_BIT                       .equ 0x07
TPM1C5SC_ELS5x_MASK                     .equ 0x0C
TPM1C5SC_MS5x_MASK                      .equ 0x30

;*********************************************
;  TPM1 Timer Channel 5 Value Register
;*********************************************
TPM1C5V                                 .equ 0xFFFF8035 ;  TPM1 Timer Channel 5 Value Register

;*********************************************
;  SCI1 Baud Rate Register
;*********************************************
SCI1BDH_SBR8_MASK                       .equ 0x01
SCI1BDH_SBR8_BIT                        .equ 0x00
SCI1BDH_SBR9_MASK                       .equ 0x02
SCI1BDH_SBR9_BIT                        .equ 0x01
SCI1BDH_SBR10_MASK                      .equ 0x04
SCI1BDH_SBR10_BIT                       .equ 0x02
SCI1BDH_SBR11_MASK                      .equ 0x08
SCI1BDH_SBR11_BIT                       .equ 0x03
SCI1BDH_SBR12_MASK                      .equ 0x10
SCI1BDH_SBR12_BIT                       .equ 0x04
SCI1BDH_RXEDGIE_MASK                    .equ 0x40
SCI1BDH_RXEDGIE_BIT                     .equ 0x06
SCI1BDH_LBKDIE_MASK                     .equ 0x80
SCI1BDH_LBKDIE_BIT                      .equ 0x07
SCI1BDH_SBR_8_MASK                      .equ 0x1F
SCI1BDL_SBR0_MASK                       .equ 0x01
SCI1BDL_SBR0_BIT                        .equ 0x00
SCI1BDL_SBR1_MASK                       .equ 0x02
SCI1BDL_SBR1_BIT                        .equ 0x01
SCI1BDL_SBR2_MASK                       .equ 0x04
SCI1BDL_SBR2_BIT                        .equ 0x02
SCI1BDL_SBR3_MASK                       .equ 0x08
SCI1BDL_SBR3_BIT                        .equ 0x03
SCI1BDL_SBR4_MASK                       .equ 0x10
SCI1BDL_SBR4_BIT                        .equ 0x04
SCI1BDL_SBR5_MASK                       .equ 0x20
SCI1BDL_SBR5_BIT                        .equ 0x05
SCI1BDL_SBR6_MASK                       .equ 0x40
SCI1BDL_SBR6_BIT                        .equ 0x06
SCI1BDL_SBR7_MASK                       .equ 0x80
SCI1BDL_SBR7_BIT                        .equ 0x07
SCI1BD                                  .equ 0xFFFF8038 ;  SCI1 Baud Rate Register
SCI1BD_SBR0_MASK                        .equ 0x01
SCI1BD_SBR0_BIT                         .equ 0x00
SCI1BD_SBR1_MASK                        .equ 0x02
SCI1BD_SBR1_BIT                         .equ 0x01
SCI1BD_SBR2_MASK                        .equ 0x04
SCI1BD_SBR2_BIT                         .equ 0x02
SCI1BD_SBR3_MASK                        .equ 0x08
SCI1BD_SBR3_BIT                         .equ 0x03
SCI1BD_SBR4_MASK                        .equ 0x10
SCI1BD_SBR4_BIT                         .equ 0x04
SCI1BD_SBR5_MASK                        .equ 0x20
SCI1BD_SBR5_BIT                         .equ 0x05
SCI1BD_SBR6_MASK                        .equ 0x40
SCI1BD_SBR6_BIT                         .equ 0x06
SCI1BD_SBR7_MASK                        .equ 0x80
SCI1BD_SBR7_BIT                         .equ 0x07
SCI1BD_SBR8_MASK                        .equ 0x100
SCI1BD_SBR8_BIT                         .equ 0x08
SCI1BD_SBR9_MASK                        .equ 0x200
SCI1BD_SBR9_BIT                         .equ 0x09
SCI1BD_SBR10_MASK                       .equ 0x400
SCI1BD_SBR10_BIT                        .equ 0x0A
SCI1BD_SBR11_MASK                       .equ 0x800
SCI1BD_SBR11_BIT                        .equ 0x0B
SCI1BD_SBR12_MASK                       .equ 0x1000
SCI1BD_SBR12_BIT                        .equ 0x0C
SCI1BD_RXEDGIE_MASK                     .equ 0x4000
SCI1BD_RXEDGIE_BIT                      .equ 0x0E
SCI1BD_LBKDIE_MASK                      .equ 0x8000
SCI1BD_LBKDIE_BIT                       .equ 0x0F
SCI1BD_SBR_MASK                         .equ 0x1FFF

;*********************************************
;  SCI1 Control Register 1
;*********************************************
SCI1C1                                  .equ 0xFFFF803A ;  SCI1 Control Register 1
SCI1C1_PT_MASK                          .equ 0x01
SCI1C1_PT_BIT                           .equ 0x00
SCI1C1_PE_MASK                          .equ 0x02
SCI1C1_PE_BIT                           .equ 0x01
SCI1C1_ILT_MASK                         .equ 0x04
SCI1C1_ILT_BIT                          .equ 0x02
SCI1C1_WAKE_MASK                        .equ 0x08
SCI1C1_WAKE_BIT                         .equ 0x03
SCI1C1_M_MASK                           .equ 0x10
SCI1C1_M_BIT                            .equ 0x04
SCI1C1_RSRC_MASK                        .equ 0x20
SCI1C1_RSRC_BIT                         .equ 0x05
SCI1C1_SCISWAI_MASK                     .equ 0x40
SCI1C1_SCISWAI_BIT                      .equ 0x06
SCI1C1_LOOPS_MASK                       .equ 0x80
SCI1C1_LOOPS_BIT                        .equ 0x07

;*********************************************
;  SCI1 Control Register 2
;*********************************************
SCI1C2                                  .equ 0xFFFF803B ;  SCI1 Control Register 2
SCI1C2_SBK_MASK                         .equ 0x01
SCI1C2_SBK_BIT                          .equ 0x00
SCI1C2_RWU_MASK                         .equ 0x02
SCI1C2_RWU_BIT                          .equ 0x01
SCI1C2_RE_MASK                          .equ 0x04
SCI1C2_RE_BIT                           .equ 0x02
SCI1C2_TE_MASK                          .equ 0x08
SCI1C2_TE_BIT                           .equ 0x03
SCI1C2_ILIE_MASK                        .equ 0x10
SCI1C2_ILIE_BIT                         .equ 0x04
SCI1C2_RIE_MASK                         .equ 0x20
SCI1C2_RIE_BIT                          .equ 0x05
SCI1C2_TCIE_MASK                        .equ 0x40
SCI1C2_TCIE_BIT                         .equ 0x06
SCI1C2_TIE_MASK                         .equ 0x80
SCI1C2_TIE_BIT                          .equ 0x07

;*********************************************
;  SCI1 Status Register 1
;*********************************************
SCI1S1                                  .equ 0xFFFF803C ;  SCI1 Status Register 1
SCI1S1_PF_MASK                          .equ 0x01
SCI1S1_PF_BIT                           .equ 0x00
SCI1S1_FE_MASK                          .equ 0x02
SCI1S1_FE_BIT                           .equ 0x01
SCI1S1_NF_MASK                          .equ 0x04
SCI1S1_NF_BIT                           .equ 0x02
SCI1S1_OR_MASK                          .equ 0x08
SCI1S1_OR_BIT                           .equ 0x03
SCI1S1_IDLE_MASK                        .equ 0x10
SCI1S1_IDLE_BIT                         .equ 0x04
SCI1S1_RDRF_MASK                        .equ 0x20
SCI1S1_RDRF_BIT                         .equ 0x05
SCI1S1_TC_MASK                          .equ 0x40
SCI1S1_TC_BIT                           .equ 0x06
SCI1S1_TDRE_MASK                        .equ 0x80
SCI1S1_TDRE_BIT                         .equ 0x07

;*********************************************
;  SCI1 Status Register 2
;*********************************************
SCI1S2                                  .equ 0xFFFF803D ;  SCI1 Status Register 2
SCI1S2_RAF_MASK                         .equ 0x01
SCI1S2_RAF_BIT                          .equ 0x00
SCI1S2_LBKDE_MASK                       .equ 0x02
SCI1S2_LBKDE_BIT                        .equ 0x01
SCI1S2_BRK13_MASK                       .equ 0x04
SCI1S2_BRK13_BIT                        .equ 0x02
SCI1S2_RWUID_MASK                       .equ 0x08
SCI1S2_RWUID_BIT                        .equ 0x03
SCI1S2_RXINV_MASK                       .equ 0x10
SCI1S2_RXINV_BIT                        .equ 0x04
SCI1S2_RXEDGIF_MASK                     .equ 0x40
SCI1S2_RXEDGIF_BIT                      .equ 0x06
SCI1S2_LBKDIF_MASK                      .equ 0x80
SCI1S2_LBKDIF_BIT                       .equ 0x07

;*********************************************
;  SCI1 Control Register 3
;*********************************************
SCI1C3                                  .equ 0xFFFF803E ;  SCI1 Control Register 3
SCI1C3_PEIE_MASK                        .equ 0x01
SCI1C3_PEIE_BIT                         .equ 0x00
SCI1C3_FEIE_MASK                        .equ 0x02
SCI1C3_FEIE_BIT                         .equ 0x01
SCI1C3_NEIE_MASK                        .equ 0x04
SCI1C3_NEIE_BIT                         .equ 0x02
SCI1C3_ORIE_MASK                        .equ 0x08
SCI1C3_ORIE_BIT                         .equ 0x03
SCI1C3_TXINV_MASK                       .equ 0x10
SCI1C3_TXINV_BIT                        .equ 0x04
SCI1C3_TXDIR_MASK                       .equ 0x20
SCI1C3_TXDIR_BIT                        .equ 0x05
SCI1C3_T8_MASK                          .equ 0x40
SCI1C3_T8_BIT                           .equ 0x06
SCI1C3_R8_MASK                          .equ 0x80
SCI1C3_R8_BIT                           .equ 0x07

;*********************************************
;  SCI1 Data Register
;*********************************************
SCI1D                                   .equ 0xFFFF803F ;  SCI1 Data Register
SCI1D_R0_T0_MASK                        .equ 0x01
SCI1D_R0_T0_BIT                         .equ 0x00
SCI1D_R1_T1_MASK                        .equ 0x02
SCI1D_R1_T1_BIT                         .equ 0x01
SCI1D_R2_T2_MASK                        .equ 0x04
SCI1D_R2_T2_BIT                         .equ 0x02
SCI1D_R3_T3_MASK                        .equ 0x08
SCI1D_R3_T3_BIT                         .equ 0x03
SCI1D_R4_T4_MASK                        .equ 0x10
SCI1D_R4_T4_BIT                         .equ 0x04
SCI1D_R5_T5_MASK                        .equ 0x20
SCI1D_R5_T5_BIT                         .equ 0x05
SCI1D_R6_T6_MASK                        .equ 0x40
SCI1D_R6_T6_BIT                         .equ 0x06
SCI1D_R7_T7_MASK                        .equ 0x80
SCI1D_R7_T7_BIT                         .equ 0x07

;*********************************************
;  SCI2 Baud Rate Register
;*********************************************
SCI2BDH_SBR8_MASK                       .equ 0x01
SCI2BDH_SBR8_BIT                        .equ 0x00
SCI2BDH_SBR9_MASK                       .equ 0x02
SCI2BDH_SBR9_BIT                        .equ 0x01
SCI2BDH_SBR10_MASK                      .equ 0x04
SCI2BDH_SBR10_BIT                       .equ 0x02
SCI2BDH_SBR11_MASK                      .equ 0x08
SCI2BDH_SBR11_BIT                       .equ 0x03
SCI2BDH_SBR12_MASK                      .equ 0x10
SCI2BDH_SBR12_BIT                       .equ 0x04
SCI2BDH_RXEDGIE_MASK                    .equ 0x40
SCI2BDH_RXEDGIE_BIT                     .equ 0x06
SCI2BDH_LBKDIE_MASK                     .equ 0x80
SCI2BDH_LBKDIE_BIT                      .equ 0x07
SCI2BDH_SBR_8_MASK                      .equ 0x1F
SCI2BDL_SBR0_MASK                       .equ 0x01
SCI2BDL_SBR0_BIT                        .equ 0x00
SCI2BDL_SBR1_MASK                       .equ 0x02
SCI2BDL_SBR1_BIT                        .equ 0x01
SCI2BDL_SBR2_MASK                       .equ 0x04
SCI2BDL_SBR2_BIT                        .equ 0x02
SCI2BDL_SBR3_MASK                       .equ 0x08
SCI2BDL_SBR3_BIT                        .equ 0x03
SCI2BDL_SBR4_MASK                       .equ 0x10
SCI2BDL_SBR4_BIT                        .equ 0x04
SCI2BDL_SBR5_MASK                       .equ 0x20
SCI2BDL_SBR5_BIT                        .equ 0x05
SCI2BDL_SBR6_MASK                       .equ 0x40
SCI2BDL_SBR6_BIT                        .equ 0x06
SCI2BDL_SBR7_MASK                       .equ 0x80
SCI2BDL_SBR7_BIT                        .equ 0x07
SCI2BD                                  .equ 0xFFFF8040 ;  SCI2 Baud Rate Register
SCI2BD_SBR0_MASK                        .equ 0x01
SCI2BD_SBR0_BIT                         .equ 0x00
SCI2BD_SBR1_MASK                        .equ 0x02
SCI2BD_SBR1_BIT                         .equ 0x01
SCI2BD_SBR2_MASK                        .equ 0x04
SCI2BD_SBR2_BIT                         .equ 0x02
SCI2BD_SBR3_MASK                        .equ 0x08
SCI2BD_SBR3_BIT                         .equ 0x03
SCI2BD_SBR4_MASK                        .equ 0x10
SCI2BD_SBR4_BIT                         .equ 0x04
SCI2BD_SBR5_MASK                        .equ 0x20
SCI2BD_SBR5_BIT                         .equ 0x05
SCI2BD_SBR6_MASK                        .equ 0x40
SCI2BD_SBR6_BIT                         .equ 0x06
SCI2BD_SBR7_MASK                        .equ 0x80
SCI2BD_SBR7_BIT                         .equ 0x07
SCI2BD_SBR8_MASK                        .equ 0x100
SCI2BD_SBR8_BIT                         .equ 0x08
SCI2BD_SBR9_MASK                        .equ 0x200
SCI2BD_SBR9_BIT                         .equ 0x09
SCI2BD_SBR10_MASK                       .equ 0x400
SCI2BD_SBR10_BIT                        .equ 0x0A
SCI2BD_SBR11_MASK                       .equ 0x800
SCI2BD_SBR11_BIT                        .equ 0x0B
SCI2BD_SBR12_MASK                       .equ 0x1000
SCI2BD_SBR12_BIT                        .equ 0x0C
SCI2BD_RXEDGIE_MASK                     .equ 0x4000
SCI2BD_RXEDGIE_BIT                      .equ 0x0E
SCI2BD_LBKDIE_MASK                      .equ 0x8000
SCI2BD_LBKDIE_BIT                       .equ 0x0F
SCI2BD_SBR_MASK                         .equ 0x1FFF

;*********************************************
;  SCI2 Control Register 1
;*********************************************
SCI2C1                                  .equ 0xFFFF8042 ;  SCI2 Control Register 1
SCI2C1_PT_MASK                          .equ 0x01
SCI2C1_PT_BIT                           .equ 0x00
SCI2C1_PE_MASK                          .equ 0x02
SCI2C1_PE_BIT                           .equ 0x01
SCI2C1_ILT_MASK                         .equ 0x04
SCI2C1_ILT_BIT                          .equ 0x02
SCI2C1_WAKE_MASK                        .equ 0x08
SCI2C1_WAKE_BIT                         .equ 0x03
SCI2C1_M_MASK                           .equ 0x10
SCI2C1_M_BIT                            .equ 0x04
SCI2C1_RSRC_MASK                        .equ 0x20
SCI2C1_RSRC_BIT                         .equ 0x05
SCI2C1_SCISWAI_MASK                     .equ 0x40
SCI2C1_SCISWAI_BIT                      .equ 0x06
SCI2C1_LOOPS_MASK                       .equ 0x80
SCI2C1_LOOPS_BIT                        .equ 0x07

;*********************************************
;  SCI2 Control Register 2
;*********************************************
SCI2C2                                  .equ 0xFFFF8043 ;  SCI2 Control Register 2
SCI2C2_SBK_MASK                         .equ 0x01
SCI2C2_SBK_BIT                          .equ 0x00
SCI2C2_RWU_MASK                         .equ 0x02
SCI2C2_RWU_BIT                          .equ 0x01
SCI2C2_RE_MASK                          .equ 0x04
SCI2C2_RE_BIT                           .equ 0x02
SCI2C2_TE_MASK                          .equ 0x08
SCI2C2_TE_BIT                           .equ 0x03
SCI2C2_ILIE_MASK                        .equ 0x10
SCI2C2_ILIE_BIT                         .equ 0x04
SCI2C2_RIE_MASK                         .equ 0x20
SCI2C2_RIE_BIT                          .equ 0x05
SCI2C2_TCIE_MASK                        .equ 0x40
SCI2C2_TCIE_BIT                         .equ 0x06
SCI2C2_TIE_MASK                         .equ 0x80
SCI2C2_TIE_BIT                          .equ 0x07

;*********************************************
;  SCI2 Status Register 1
;*********************************************
SCI2S1                                  .equ 0xFFFF8044 ;  SCI2 Status Register 1
SCI2S1_PF_MASK                          .equ 0x01
SCI2S1_PF_BIT                           .equ 0x00
SCI2S1_FE_MASK                          .equ 0x02
SCI2S1_FE_BIT                           .equ 0x01
SCI2S1_NF_MASK                          .equ 0x04
SCI2S1_NF_BIT                           .equ 0x02
SCI2S1_OR_MASK                          .equ 0x08
SCI2S1_OR_BIT                           .equ 0x03
SCI2S1_IDLE_MASK                        .equ 0x10
SCI2S1_IDLE_BIT                         .equ 0x04
SCI2S1_RDRF_MASK                        .equ 0x20
SCI2S1_RDRF_BIT                         .equ 0x05
SCI2S1_TC_MASK                          .equ 0x40
SCI2S1_TC_BIT                           .equ 0x06
SCI2S1_TDRE_MASK                        .equ 0x80
SCI2S1_TDRE_BIT                         .equ 0x07

;*********************************************
;  SCI2 Status Register 2
;*********************************************
SCI2S2                                  .equ 0xFFFF8045 ;  SCI2 Status Register 2
SCI2S2_RAF_MASK                         .equ 0x01
SCI2S2_RAF_BIT                          .equ 0x00
SCI2S2_LBKDE_MASK                       .equ 0x02
SCI2S2_LBKDE_BIT                        .equ 0x01
SCI2S2_BRK13_MASK                       .equ 0x04
SCI2S2_BRK13_BIT                        .equ 0x02
SCI2S2_RWUID_MASK                       .equ 0x08
SCI2S2_RWUID_BIT                        .equ 0x03
SCI2S2_RXINV_MASK                       .equ 0x10
SCI2S2_RXINV_BIT                        .equ 0x04
SCI2S2_RXEDGIF_MASK                     .equ 0x40
SCI2S2_RXEDGIF_BIT                      .equ 0x06
SCI2S2_LBKDIF_MASK                      .equ 0x80
SCI2S2_LBKDIF_BIT                       .equ 0x07

;*********************************************
;  SCI2 Control Register 3
;*********************************************
SCI2C3                                  .equ 0xFFFF8046 ;  SCI2 Control Register 3
SCI2C3_PEIE_MASK                        .equ 0x01
SCI2C3_PEIE_BIT                         .equ 0x00
SCI2C3_FEIE_MASK                        .equ 0x02
SCI2C3_FEIE_BIT                         .equ 0x01
SCI2C3_NEIE_MASK                        .equ 0x04
SCI2C3_NEIE_BIT                         .equ 0x02
SCI2C3_ORIE_MASK                        .equ 0x08
SCI2C3_ORIE_BIT                         .equ 0x03
SCI2C3_TXINV_MASK                       .equ 0x10
SCI2C3_TXINV_BIT                        .equ 0x04
SCI2C3_TXDIR_MASK                       .equ 0x20
SCI2C3_TXDIR_BIT                        .equ 0x05
SCI2C3_T8_MASK                          .equ 0x40
SCI2C3_T8_BIT                           .equ 0x06
SCI2C3_R8_MASK                          .equ 0x80
SCI2C3_R8_BIT                           .equ 0x07

;*********************************************
;  SCI2 Data Register
;*********************************************
SCI2D                                   .equ 0xFFFF8047 ;  SCI2 Data Register
SCI2D_R0_T0_MASK                        .equ 0x01
SCI2D_R0_T0_BIT                         .equ 0x00
SCI2D_R1_T1_MASK                        .equ 0x02
SCI2D_R1_T1_BIT                         .equ 0x01
SCI2D_R2_T2_MASK                        .equ 0x04
SCI2D_R2_T2_BIT                         .equ 0x02
SCI2D_R3_T3_MASK                        .equ 0x08
SCI2D_R3_T3_BIT                         .equ 0x03
SCI2D_R4_T4_MASK                        .equ 0x10
SCI2D_R4_T4_BIT                         .equ 0x04
SCI2D_R5_T5_MASK                        .equ 0x20
SCI2D_R5_T5_BIT                         .equ 0x05
SCI2D_R6_T6_MASK                        .equ 0x40
SCI2D_R6_T6_BIT                         .equ 0x06
SCI2D_R7_T7_MASK                        .equ 0x80
SCI2D_R7_T7_BIT                         .equ 0x07

;*********************************************
;  MCG Control Register 1
;*********************************************
MCGC1                                   .equ 0xFFFF8048 ;  MCG Control Register 1
MCGC1_IREFSTEN_MASK                     .equ 0x01
MCGC1_IREFSTEN_BIT                      .equ 0x00
MCGC1_IRCLKEN_MASK                      .equ 0x02
MCGC1_IRCLKEN_BIT                       .equ 0x01
MCGC1_IREFS_MASK                        .equ 0x04
MCGC1_IREFS_BIT                         .equ 0x02
MCGC1_RDIV0_MASK                        .equ 0x08
MCGC1_RDIV0_BIT                         .equ 0x03
MCGC1_RDIV1_MASK                        .equ 0x10
MCGC1_RDIV1_BIT                         .equ 0x04
MCGC1_RDIV2_MASK                        .equ 0x20
MCGC1_RDIV2_BIT                         .equ 0x05
MCGC1_CLKS0_MASK                        .equ 0x40
MCGC1_CLKS0_BIT                         .equ 0x06
MCGC1_CLKS1_MASK                        .equ 0x80
MCGC1_CLKS1_BIT                         .equ 0x07
MCGC1_RDIV_MASK                         .equ 0x38
MCGC1_CLKS_MASK                         .equ 0xC0

;*********************************************
;  MCG Control Register 2
;*********************************************
MCGC2                                   .equ 0xFFFF8049 ;  MCG Control Register 2
MCGC2_EREFSTEN_MASK                     .equ 0x01
MCGC2_EREFSTEN_BIT                      .equ 0x00
MCGC2_ERCLKEN_MASK                      .equ 0x02
MCGC2_ERCLKEN_BIT                       .equ 0x01
MCGC2_EREFS_MASK                        .equ 0x04
MCGC2_EREFS_BIT                         .equ 0x02
MCGC2_LP_MASK                           .equ 0x08
MCGC2_LP_BIT                            .equ 0x03
MCGC2_HGO_MASK                          .equ 0x10
MCGC2_HGO_BIT                           .equ 0x04
MCGC2_RANGE_MASK                        .equ 0x20
MCGC2_RANGE_BIT                         .equ 0x05
MCGC2_BDIV0_MASK                        .equ 0x40
MCGC2_BDIV0_BIT                         .equ 0x06
MCGC2_BDIV1_MASK                        .equ 0x80
MCGC2_BDIV1_BIT                         .equ 0x07
MCGC2_BDIV_MASK                         .equ 0xC0

;*********************************************
;  MCG Trim Register
;*********************************************
MCGTRM                                  .equ 0xFFFF804A ;  MCG Trim Register
MCGTRM_TRIM0_MASK                       .equ 0x01
MCGTRM_TRIM0_BIT                        .equ 0x00
MCGTRM_TRIM1_MASK                       .equ 0x02
MCGTRM_TRIM1_BIT                        .equ 0x01
MCGTRM_TRIM2_MASK                       .equ 0x04
MCGTRM_TRIM2_BIT                        .equ 0x02
MCGTRM_TRIM3_MASK                       .equ 0x08
MCGTRM_TRIM3_BIT                        .equ 0x03
MCGTRM_TRIM4_MASK                       .equ 0x10
MCGTRM_TRIM4_BIT                        .equ 0x04
MCGTRM_TRIM5_MASK                       .equ 0x20
MCGTRM_TRIM5_BIT                        .equ 0x05
MCGTRM_TRIM6_MASK                       .equ 0x40
MCGTRM_TRIM6_BIT                        .equ 0x06
MCGTRM_TRIM7_MASK                       .equ 0x80
MCGTRM_TRIM7_BIT                        .equ 0x07

;*********************************************
;  MCG Status and Control Register
;*********************************************
MCGSC                                   .equ 0xFFFF804B ;  MCG Status and Control Register
MCGSC_FTRIM_MASK                        .equ 0x01
MCGSC_FTRIM_BIT                         .equ 0x00
MCGSC_OSCINIT_MASK                      .equ 0x02
MCGSC_OSCINIT_BIT                       .equ 0x01
MCGSC_CLKST0_MASK                       .equ 0x04
MCGSC_CLKST0_BIT                        .equ 0x02
MCGSC_CLKST1_MASK                       .equ 0x08
MCGSC_CLKST1_BIT                        .equ 0x03
MCGSC_IREFST_MASK                       .equ 0x10
MCGSC_IREFST_BIT                        .equ 0x04
MCGSC_PLLST_MASK                        .equ 0x20
MCGSC_PLLST_BIT                         .equ 0x05
MCGSC_LOCK_MASK                         .equ 0x40
MCGSC_LOCK_BIT                          .equ 0x06
MCGSC_LOLS_MASK                         .equ 0x80
MCGSC_LOLS_BIT                          .equ 0x07
MCGSC_CLKST_MASK                        .equ 0x0C

;*********************************************
;  MCG Control Register 3
;*********************************************
MCGC3                                   .equ 0xFFFF804C ;  MCG Control Register 3
MCGC3_VDIV0_MASK                        .equ 0x01
MCGC3_VDIV0_BIT                         .equ 0x00
MCGC3_VDIV1_MASK                        .equ 0x02
MCGC3_VDIV1_BIT                         .equ 0x01
MCGC3_VDIV2_MASK                        .equ 0x04
MCGC3_VDIV2_BIT                         .equ 0x02
MCGC3_VDIV3_MASK                        .equ 0x08
MCGC3_VDIV3_BIT                         .equ 0x03
MCGC3_DIV32_MASK                        .equ 0x10
MCGC3_DIV32_BIT                         .equ 0x04
MCGC3_CME_MASK                          .equ 0x20
MCGC3_CME_BIT                           .equ 0x05
MCGC3_PLLS_MASK                         .equ 0x40
MCGC3_PLLS_BIT                          .equ 0x06
MCGC3_LOLIE_MASK                        .equ 0x80
MCGC3_LOLIE_BIT                         .equ 0x07
MCGC3_VDIV_MASK                         .equ 0x0F

;*********************************************
;  MCG Control Register 4
;*********************************************
MCGC4                                   .equ 0xFFFF804D ;  MCG Control Register 4
MCGC4_DRST_DRS0_MASK                    .equ 0x01
MCGC4_DRST_DRS0_BIT                     .equ 0x00
MCGC4_DRST_DRS1_MASK                    .equ 0x02
MCGC4_DRST_DRS1_BIT                     .equ 0x01
MCGC4_DMX32_MASK                        .equ 0x20
MCGC4_DMX32_BIT                         .equ 0x05
MCGC4_DRST_DRS_MASK                     .equ 0x03

;*********************************************
;  SPI1 Control Register 1
;*********************************************
SPI1C1                                  .equ 0xFFFF8050 ;  SPI1 Control Register 1
SPI1C1_LSBFE_MASK                       .equ 0x01
SPI1C1_LSBFE_BIT                        .equ 0x00
SPI1C1_SSOE_MASK                        .equ 0x02
SPI1C1_SSOE_BIT                         .equ 0x01
SPI1C1_CPHA_MASK                        .equ 0x04
SPI1C1_CPHA_BIT                         .equ 0x02
SPI1C1_CPOL_MASK                        .equ 0x08
SPI1C1_CPOL_BIT                         .equ 0x03
SPI1C1_MSTR_MASK                        .equ 0x10
SPI1C1_MSTR_BIT                         .equ 0x04
SPI1C1_SPTIE_MASK                       .equ 0x20
SPI1C1_SPTIE_BIT                        .equ 0x05
SPI1C1_SPE_MASK                         .equ 0x40
SPI1C1_SPE_BIT                          .equ 0x06
SPI1C1_SPIE_MASK                        .equ 0x80
SPI1C1_SPIE_BIT                         .equ 0x07

;*********************************************
;  SPI1 Control Register 2
;*********************************************
SPI1C2                                  .equ 0xFFFF8051 ;  SPI1 Control Register 2
SPI1C2_SPC0_MASK                        .equ 0x01
SPI1C2_SPC0_BIT                         .equ 0x00
SPI1C2_SPISWAI_MASK                     .equ 0x02
SPI1C2_SPISWAI_BIT                      .equ 0x01
SPI1C2_BIDIROE_MASK                     .equ 0x08
SPI1C2_BIDIROE_BIT                      .equ 0x03
SPI1C2_MODFEN_MASK                      .equ 0x10
SPI1C2_MODFEN_BIT                       .equ 0x04
SPI1C2_SPIMODE_MASK                     .equ 0x40
SPI1C2_SPIMODE_BIT                      .equ 0x06
SPI1C2_SPMIE_MASK                       .equ 0x80
SPI1C2_SPMIE_BIT                        .equ 0x07

;*********************************************
;  SPI1 Baud Rate Register
;*********************************************
SPI1BR                                  .equ 0xFFFF8052 ;  SPI1 Baud Rate Register
SPI1BR_SPR0_MASK                        .equ 0x01
SPI1BR_SPR0_BIT                         .equ 0x00
SPI1BR_SPR1_MASK                        .equ 0x02
SPI1BR_SPR1_BIT                         .equ 0x01
SPI1BR_SPR2_MASK                        .equ 0x04
SPI1BR_SPR2_BIT                         .equ 0x02
SPI1BR_SPPR0_MASK                       .equ 0x10
SPI1BR_SPPR0_BIT                        .equ 0x04
SPI1BR_SPPR1_MASK                       .equ 0x20
SPI1BR_SPPR1_BIT                        .equ 0x05
SPI1BR_SPPR2_MASK                       .equ 0x40
SPI1BR_SPPR2_BIT                        .equ 0x06
SPI1BR_SPR_MASK                         .equ 0x07
SPI1BR_SPPR_MASK                        .equ 0x70

;*********************************************
;  SPI1 Status Register
;*********************************************
SPI1S                                   .equ 0xFFFF8053 ;  SPI1 Status Register
SPI1S_MODF_MASK                         .equ 0x10
SPI1S_MODF_BIT                          .equ 0x04
SPI1S_SPTEF_MASK                        .equ 0x20
SPI1S_SPTEF_BIT                         .equ 0x05
SPI1S_SPMF_MASK                         .equ 0x40
SPI1S_SPMF_BIT                          .equ 0x06
SPI1S_SPRF_MASK                         .equ 0x80
SPI1S_SPRF_BIT                          .equ 0x07

;*********************************************
;  SPI1 Data Register
;*********************************************
SPI1D_Bit0_MASK                         .equ 0x01
SPI1D_Bit0_BIT                          .equ 0x00
SPI1D_Bit1_MASK                         .equ 0x02
SPI1D_Bit1_BIT                          .equ 0x01
SPI1D_Bit2_MASK                         .equ 0x04
SPI1D_Bit2_BIT                          .equ 0x02
SPI1D_Bit3_MASK                         .equ 0x08
SPI1D_Bit3_BIT                          .equ 0x03
SPI1D_Bit4_MASK                         .equ 0x10
SPI1D_Bit4_BIT                          .equ 0x04
SPI1D_Bit5_MASK                         .equ 0x20
SPI1D_Bit5_BIT                          .equ 0x05
SPI1D_Bit6_MASK                         .equ 0x40
SPI1D_Bit6_BIT                          .equ 0x06
SPI1D_Bit7_MASK                         .equ 0x80
SPI1D_Bit7_BIT                          .equ 0x07
SPI1D16                                 .equ 0xFFFF8054 ;  SPI1 Data Register

;*********************************************
;  SPI1 Match Register
;*********************************************
SPI1MH_Bit8_MASK                        .equ 0x01
SPI1MH_Bit8_BIT                         .equ 0x00
SPI1MH_Bit9_MASK                        .equ 0x02
SPI1MH_Bit9_BIT                         .equ 0x01
SPI1MH_Bit10_MASK                       .equ 0x04
SPI1MH_Bit10_BIT                        .equ 0x02
SPI1MH_Bit11_MASK                       .equ 0x08
SPI1MH_Bit11_BIT                        .equ 0x03
SPI1MH_Bit12_MASK                       .equ 0x10
SPI1MH_Bit12_BIT                        .equ 0x04
SPI1MH_Bit13_MASK                       .equ 0x20
SPI1MH_Bit13_BIT                        .equ 0x05
SPI1MH_Bit14_MASK                       .equ 0x40
SPI1MH_Bit14_BIT                        .equ 0x06
SPI1MH_Bit15_MASK                       .equ 0x80
SPI1MH_Bit15_BIT                        .equ 0x07
SPI1ML_Bit0_MASK                        .equ 0x01
SPI1ML_Bit0_BIT                         .equ 0x00
SPI1ML_Bit1_MASK                        .equ 0x02
SPI1ML_Bit1_BIT                         .equ 0x01
SPI1ML_Bit2_MASK                        .equ 0x04
SPI1ML_Bit2_BIT                         .equ 0x02
SPI1ML_Bit3_MASK                        .equ 0x08
SPI1ML_Bit3_BIT                         .equ 0x03
SPI1ML_Bit4_MASK                        .equ 0x10
SPI1ML_Bit4_BIT                         .equ 0x04
SPI1ML_Bit5_MASK                        .equ 0x20
SPI1ML_Bit5_BIT                         .equ 0x05
SPI1ML_Bit6_MASK                        .equ 0x40
SPI1ML_Bit6_BIT                         .equ 0x06
SPI1ML_Bit7_MASK                        .equ 0x80
SPI1ML_Bit7_BIT                         .equ 0x07
SPI1M                                   .equ 0xFFFF8056 ;  SPI1 Match Register
SPI1M_Bit0_MASK                         .equ 0x01
SPI1M_Bit0_BIT                          .equ 0x00
SPI1M_Bit1_MASK                         .equ 0x02
SPI1M_Bit1_BIT                          .equ 0x01
SPI1M_Bit2_MASK                         .equ 0x04
SPI1M_Bit2_BIT                          .equ 0x02
SPI1M_Bit3_MASK                         .equ 0x08
SPI1M_Bit3_BIT                          .equ 0x03
SPI1M_Bit4_MASK                         .equ 0x10
SPI1M_Bit4_BIT                          .equ 0x04
SPI1M_Bit5_MASK                         .equ 0x20
SPI1M_Bit5_BIT                          .equ 0x05
SPI1M_Bit6_MASK                         .equ 0x40
SPI1M_Bit6_BIT                          .equ 0x06
SPI1M_Bit7_MASK                         .equ 0x80
SPI1M_Bit7_BIT                          .equ 0x07
SPI1M_Bit8_MASK                         .equ 0x100
SPI1M_Bit8_BIT                          .equ 0x08
SPI1M_Bit9_MASK                         .equ 0x200
SPI1M_Bit9_BIT                          .equ 0x09
SPI1M_Bit10_MASK                        .equ 0x400
SPI1M_Bit10_BIT                         .equ 0x0A
SPI1M_Bit11_MASK                        .equ 0x800
SPI1M_Bit11_BIT                         .equ 0x0B
SPI1M_Bit12_MASK                        .equ 0x1000
SPI1M_Bit12_BIT                         .equ 0x0C
SPI1M_Bit13_MASK                        .equ 0x2000
SPI1M_Bit13_BIT                         .equ 0x0D
SPI1M_Bit14_MASK                        .equ 0x4000
SPI1M_Bit14_BIT                         .equ 0x0E
SPI1M_Bit15_MASK                        .equ 0x8000
SPI1M_Bit15_BIT                         .equ 0x0F

;*********************************************
;  IIC Address Register
;*********************************************
IIC1A                                   .equ 0xFFFF8058 ;  IIC Address Register
IIC1A_AD1_MASK                          .equ 0x02
IIC1A_AD1_BIT                           .equ 0x01
IIC1A_AD2_MASK                          .equ 0x04
IIC1A_AD2_BIT                           .equ 0x02
IIC1A_AD3_MASK                          .equ 0x08
IIC1A_AD3_BIT                           .equ 0x03
IIC1A_AD4_MASK                          .equ 0x10
IIC1A_AD4_BIT                           .equ 0x04
IIC1A_AD5_MASK                          .equ 0x20
IIC1A_AD5_BIT                           .equ 0x05
IIC1A_AD6_MASK                          .equ 0x40
IIC1A_AD6_BIT                           .equ 0x06
IIC1A_AD7_MASK                          .equ 0x80
IIC1A_AD7_BIT                           .equ 0x07
IIC1A_AD_1_MASK                         .equ 0xFE

;*********************************************
;  IIC Frequency Divider Register
;*********************************************
IIC1F                                   .equ 0xFFFF8059 ;  IIC Frequency Divider Register
IIC1F_ICR0_MASK                         .equ 0x01
IIC1F_ICR0_BIT                          .equ 0x00
IIC1F_ICR1_MASK                         .equ 0x02
IIC1F_ICR1_BIT                          .equ 0x01
IIC1F_ICR2_MASK                         .equ 0x04
IIC1F_ICR2_BIT                          .equ 0x02
IIC1F_ICR3_MASK                         .equ 0x08
IIC1F_ICR3_BIT                          .equ 0x03
IIC1F_ICR4_MASK                         .equ 0x10
IIC1F_ICR4_BIT                          .equ 0x04
IIC1F_ICR5_MASK                         .equ 0x20
IIC1F_ICR5_BIT                          .equ 0x05
IIC1F_MULT0_MASK                        .equ 0x40
IIC1F_MULT0_BIT                         .equ 0x06
IIC1F_MULT1_MASK                        .equ 0x80
IIC1F_MULT1_BIT                         .equ 0x07
IIC1F_ICR_MASK                          .equ 0x3F
IIC1F_MULT_MASK                         .equ 0xC0

;*********************************************
;  IIC Control Register 1
;*********************************************
IIC1C1_RSTA_MASK                        .equ 0x04
IIC1C1_RSTA_BIT                         .equ 0x02
IIC1C1_TXAK_MASK                        .equ 0x08
IIC1C1_TXAK_BIT                         .equ 0x03
IIC1C1_TX_MASK                          .equ 0x10
IIC1C1_TX_BIT                           .equ 0x04
IIC1C1_MST_MASK                         .equ 0x20
IIC1C1_MST_BIT                          .equ 0x05
IIC1C1_IICIE_MASK                       .equ 0x40
IIC1C1_IICIE_BIT                        .equ 0x06
IIC1C1_IICEN_MASK                       .equ 0x80
IIC1C1_IICEN_BIT                        .equ 0x07
IIC1C_RSTA_MASK                         .equ 0x04
IIC1C_RSTA_BIT                          .equ 0x02
IIC1C_TXAK_MASK                         .equ 0x08
IIC1C_TXAK_BIT                          .equ 0x03
IIC1C_TX_MASK                           .equ 0x10
IIC1C_TX_BIT                            .equ 0x04
IIC1C_MST_MASK                          .equ 0x20
IIC1C_MST_BIT                           .equ 0x05
IIC1C_IICIE_MASK                        .equ 0x40
IIC1C_IICIE_BIT                         .equ 0x06
IIC1C_IICEN_MASK                        .equ 0x80
IIC1C_IICEN_BIT                         .equ 0x07
IIC1C1                                  .equ 0xFFFF805A ;  IIC Control Register 1

;*********************************************
;  IIC Status Register
;*********************************************
IIC1S                                   .equ 0xFFFF805B ;  IIC Status Register
IIC1S_RXAK_MASK                         .equ 0x01
IIC1S_RXAK_BIT                          .equ 0x00
IIC1S_IICIF_MASK                        .equ 0x02
IIC1S_IICIF_BIT                         .equ 0x01
IIC1S_SRW_MASK                          .equ 0x04
IIC1S_SRW_BIT                           .equ 0x02
IIC1S_ARBL_MASK                         .equ 0x10
IIC1S_ARBL_BIT                          .equ 0x04
IIC1S_BUSY_MASK                         .equ 0x20
IIC1S_BUSY_BIT                          .equ 0x05
IIC1S_IAAS_MASK                         .equ 0x40
IIC1S_IAAS_BIT                          .equ 0x06
IIC1S_TCF_MASK                          .equ 0x80
IIC1S_TCF_BIT                           .equ 0x07

;*********************************************
;  IIC Data I/O Register
;*********************************************
IIC1D                                   .equ 0xFFFF805C ;  IIC Data I/O Register
IIC1D_DATA0_MASK                        .equ 0x01
IIC1D_DATA0_BIT                         .equ 0x00
IIC1D_DATA1_MASK                        .equ 0x02
IIC1D_DATA1_BIT                         .equ 0x01
IIC1D_DATA2_MASK                        .equ 0x04
IIC1D_DATA2_BIT                         .equ 0x02
IIC1D_DATA3_MASK                        .equ 0x08
IIC1D_DATA3_BIT                         .equ 0x03
IIC1D_DATA4_MASK                        .equ 0x10
IIC1D_DATA4_BIT                         .equ 0x04
IIC1D_DATA5_MASK                        .equ 0x20
IIC1D_DATA5_BIT                         .equ 0x05
IIC1D_DATA6_MASK                        .equ 0x40
IIC1D_DATA6_BIT                         .equ 0x06
IIC1D_DATA7_MASK                        .equ 0x80
IIC1D_DATA7_BIT                         .equ 0x07

;*********************************************
;  IIC Control Register 2
;*********************************************
IIC1C2                                  .equ 0xFFFF805D ;  IIC Control Register 2
IIC1C2_AD8_MASK                         .equ 0x01
IIC1C2_AD8_BIT                          .equ 0x00
IIC1C2_AD9_MASK                         .equ 0x02
IIC1C2_AD9_BIT                          .equ 0x01
IIC1C2_AD10_MASK                        .equ 0x04
IIC1C2_AD10_BIT                         .equ 0x02
IIC1C2_ADEXT_MASK                       .equ 0x40
IIC1C2_ADEXT_BIT                        .equ 0x06
IIC1C2_GCAEN_MASK                       .equ 0x80
IIC1C2_GCAEN_BIT                        .equ 0x07
IIC1C2_AD_8_MASK                        .equ 0x07

;*********************************************
;  TPM2 Status and Control Register
;*********************************************
TPM2SC                                  .equ 0xFFFF8060 ;  TPM2 Status and Control Register
TPM2SC_PS0_MASK                         .equ 0x01
TPM2SC_PS0_BIT                          .equ 0x00
TPM2SC_PS1_MASK                         .equ 0x02
TPM2SC_PS1_BIT                          .equ 0x01
TPM2SC_PS2_MASK                         .equ 0x04
TPM2SC_PS2_BIT                          .equ 0x02
TPM2SC_CLKSA_MASK                       .equ 0x08
TPM2SC_CLKSA_BIT                        .equ 0x03
TPM2SC_CLKSB_MASK                       .equ 0x10
TPM2SC_CLKSB_BIT                        .equ 0x04
TPM2SC_CPWMS_MASK                       .equ 0x20
TPM2SC_CPWMS_BIT                        .equ 0x05
TPM2SC_TOIE_MASK                        .equ 0x40
TPM2SC_TOIE_BIT                         .equ 0x06
TPM2SC_TOF_MASK                         .equ 0x80
TPM2SC_TOF_BIT                          .equ 0x07
TPM2SC_PS_MASK                          .equ 0x07
TPM2SC_CLKSx_MASK                       .equ 0x18

;*********************************************
;  TPM2 Timer Counter Register
;*********************************************
TPM2CNT                                 .equ 0xFFFF8061 ;  TPM2 Timer Counter Register

;*********************************************
;  TPM2 Timer Counter Modulo Register
;*********************************************
TPM2MOD                                 .equ 0xFFFF8063 ;  TPM2 Timer Counter Modulo Register

;*********************************************
;  TPM2 Timer Channel 0 Status and Control Register
;*********************************************
TPM2C0SC                                .equ 0xFFFF8065 ;  TPM2 Timer Channel 0 Status and Control Register
TPM2C0SC_ELS0A_MASK                     .equ 0x04
TPM2C0SC_ELS0A_BIT                      .equ 0x02
TPM2C0SC_ELS0B_MASK                     .equ 0x08
TPM2C0SC_ELS0B_BIT                      .equ 0x03
TPM2C0SC_MS0A_MASK                      .equ 0x10
TPM2C0SC_MS0A_BIT                       .equ 0x04
TPM2C0SC_MS0B_MASK                      .equ 0x20
TPM2C0SC_MS0B_BIT                       .equ 0x05
TPM2C0SC_CH0IE_MASK                     .equ 0x40
TPM2C0SC_CH0IE_BIT                      .equ 0x06
TPM2C0SC_CH0F_MASK                      .equ 0x80
TPM2C0SC_CH0F_BIT                       .equ 0x07
TPM2C0SC_ELS0x_MASK                     .equ 0x0C
TPM2C0SC_MS0x_MASK                      .equ 0x30

;*********************************************
;  TPM2 Timer Channel 0 Value Register
;*********************************************
TPM2C0V                                 .equ 0xFFFF8066 ;  TPM2 Timer Channel 0 Value Register

;*********************************************
;  TPM2 Timer Channel 1 Status and Control Register
;*********************************************
TPM2C1SC                                .equ 0xFFFF8068 ;  TPM2 Timer Channel 1 Status and Control Register
TPM2C1SC_ELS1A_MASK                     .equ 0x04
TPM2C1SC_ELS1A_BIT                      .equ 0x02
TPM2C1SC_ELS1B_MASK                     .equ 0x08
TPM2C1SC_ELS1B_BIT                      .equ 0x03
TPM2C1SC_MS1A_MASK                      .equ 0x10
TPM2C1SC_MS1A_BIT                       .equ 0x04
TPM2C1SC_MS1B_MASK                      .equ 0x20
TPM2C1SC_MS1B_BIT                       .equ 0x05
TPM2C1SC_CH1IE_MASK                     .equ 0x40
TPM2C1SC_CH1IE_BIT                      .equ 0x06
TPM2C1SC_CH1F_MASK                      .equ 0x80
TPM2C1SC_CH1F_BIT                       .equ 0x07
TPM2C1SC_ELS1x_MASK                     .equ 0x0C
TPM2C1SC_MS1x_MASK                      .equ 0x30

;*********************************************
;  TPM2 Timer Channel 1 Value Register
;*********************************************
TPM2C1V                                 .equ 0xFFFF8069 ;  TPM2 Timer Channel 1 Value Register

;*********************************************
;  RTC Status and Control Register
;*********************************************
RTCSC                                   .equ 0xFFFF806C ;  RTC Status and Control Register
RTCSC_RTCPS0_MASK                       .equ 0x01
RTCSC_RTCPS0_BIT                        .equ 0x00
RTCSC_RTCPS1_MASK                       .equ 0x02
RTCSC_RTCPS1_BIT                        .equ 0x01
RTCSC_RTCPS2_MASK                       .equ 0x04
RTCSC_RTCPS2_BIT                        .equ 0x02
RTCSC_RTCPS3_MASK                       .equ 0x08
RTCSC_RTCPS3_BIT                        .equ 0x03
RTCSC_RTIE_MASK                         .equ 0x10
RTCSC_RTIE_BIT                          .equ 0x04
RTCSC_RTCLKS0_MASK                      .equ 0x20
RTCSC_RTCLKS0_BIT                       .equ 0x05
RTCSC_RTCLKS1_MASK                      .equ 0x40
RTCSC_RTCLKS1_BIT                       .equ 0x06
RTCSC_RTIF_MASK                         .equ 0x80
RTCSC_RTIF_BIT                          .equ 0x07
RTCSC_RTCPS_MASK                        .equ 0x0F
RTCSC_RTCLKS_MASK                       .equ 0x60

;*********************************************
;  RTC Counter Register
;*********************************************
RTCCNT                                  .equ 0xFFFF806D ;  RTC Counter Register

;*********************************************
;  RTC Modulo Register
;*********************************************
RTCMOD                                  .equ 0xFFFF806E ;  RTC Modulo Register

;*********************************************
;  SPI2 Control Register 1
;*********************************************
SPI2C1                                  .equ 0xFFFF8070 ;  SPI2 Control Register 1
SPI2C1_LSBFE_MASK                       .equ 0x01
SPI2C1_LSBFE_BIT                        .equ 0x00
SPI2C1_SSOE_MASK                        .equ 0x02
SPI2C1_SSOE_BIT                         .equ 0x01
SPI2C1_CPHA_MASK                        .equ 0x04
SPI2C1_CPHA_BIT                         .equ 0x02
SPI2C1_CPOL_MASK                        .equ 0x08
SPI2C1_CPOL_BIT                         .equ 0x03
SPI2C1_MSTR_MASK                        .equ 0x10
SPI2C1_MSTR_BIT                         .equ 0x04
SPI2C1_SPTIE_MASK                       .equ 0x20
SPI2C1_SPTIE_BIT                        .equ 0x05
SPI2C1_SPE_MASK                         .equ 0x40
SPI2C1_SPE_BIT                          .equ 0x06
SPI2C1_SPIE_MASK                        .equ 0x80
SPI2C1_SPIE_BIT                         .equ 0x07

;*********************************************
;  SPI2 Control Register 2
;*********************************************
SPI2C2                                  .equ 0xFFFF8071 ;  SPI2 Control Register 2
SPI2C2_SPC0_MASK                        .equ 0x01
SPI2C2_SPC0_BIT                         .equ 0x00
SPI2C2_SPISWAI_MASK                     .equ 0x02
SPI2C2_SPISWAI_BIT                      .equ 0x01
SPI2C2_BIDIROE_MASK                     .equ 0x08
SPI2C2_BIDIROE_BIT                      .equ 0x03
SPI2C2_MODFEN_MASK                      .equ 0x10
SPI2C2_MODFEN_BIT                       .equ 0x04
SPI2C2_SPIMODE_MASK                     .equ 0x40
SPI2C2_SPIMODE_BIT                      .equ 0x06
SPI2C2_SPMIE_MASK                       .equ 0x80
SPI2C2_SPMIE_BIT                        .equ 0x07

;*********************************************
;  SPI2 Baud Rate Register
;*********************************************
SPI2BR                                  .equ 0xFFFF8072 ;  SPI2 Baud Rate Register
SPI2BR_SPR0_MASK                        .equ 0x01
SPI2BR_SPR0_BIT                         .equ 0x00
SPI2BR_SPR1_MASK                        .equ 0x02
SPI2BR_SPR1_BIT                         .equ 0x01
SPI2BR_SPR2_MASK                        .equ 0x04
SPI2BR_SPR2_BIT                         .equ 0x02
SPI2BR_SPPR0_MASK                       .equ 0x10
SPI2BR_SPPR0_BIT                        .equ 0x04
SPI2BR_SPPR1_MASK                       .equ 0x20
SPI2BR_SPPR1_BIT                        .equ 0x05
SPI2BR_SPPR2_MASK                       .equ 0x40
SPI2BR_SPPR2_BIT                        .equ 0x06
SPI2BR_SPR_MASK                         .equ 0x07
SPI2BR_SPPR_MASK                        .equ 0x70

;*********************************************
;  SPI2 Status Register
;*********************************************
SPI2S                                   .equ 0xFFFF8073 ;  SPI2 Status Register
SPI2S_RFIFOEF_MASK                      .equ 0x01
SPI2S_RFIFOEF_BIT                       .equ 0x00
SPI2S_TXFULLF_MASK                      .equ 0x02
SPI2S_TXFULLF_BIT                       .equ 0x01
SPI2S_TNEAREF_MASK                      .equ 0x04
SPI2S_TNEAREF_BIT                       .equ 0x02
SPI2S_RNFULLF_MASK                      .equ 0x08
SPI2S_RNFULLF_BIT                       .equ 0x03
SPI2S_MODF_MASK                         .equ 0x10
SPI2S_MODF_BIT                          .equ 0x04
SPI2S_SPTEF_MASK                        .equ 0x20
SPI2S_SPTEF_BIT                         .equ 0x05
SPI2S_SPMF_MASK                         .equ 0x40
SPI2S_SPMF_BIT                          .equ 0x06
SPI2S_SPRF_MASK                         .equ 0x80
SPI2S_SPRF_BIT                          .equ 0x07

;*********************************************
;  SPI2 Data Register
;*********************************************
SPI2D_Bit0_MASK                         .equ 0x01
SPI2D_Bit0_BIT                          .equ 0x00
SPI2D_Bit1_MASK                         .equ 0x02
SPI2D_Bit1_BIT                          .equ 0x01
SPI2D_Bit2_MASK                         .equ 0x04
SPI2D_Bit2_BIT                          .equ 0x02
SPI2D_Bit3_MASK                         .equ 0x08
SPI2D_Bit3_BIT                          .equ 0x03
SPI2D_Bit4_MASK                         .equ 0x10
SPI2D_Bit4_BIT                          .equ 0x04
SPI2D_Bit5_MASK                         .equ 0x20
SPI2D_Bit5_BIT                          .equ 0x05
SPI2D_Bit6_MASK                         .equ 0x40
SPI2D_Bit6_BIT                          .equ 0x06
SPI2D_Bit7_MASK                         .equ 0x80
SPI2D_Bit7_BIT                          .equ 0x07
SPI2D16                                 .equ 0xFFFF8074 ;  SPI2 Data Register

;*********************************************
;  SPI2 Match Register
;*********************************************
SPI2MH_Bit8_MASK                        .equ 0x01
SPI2MH_Bit8_BIT                         .equ 0x00
SPI2MH_Bit9_MASK                        .equ 0x02
SPI2MH_Bit9_BIT                         .equ 0x01
SPI2MH_Bit10_MASK                       .equ 0x04
SPI2MH_Bit10_BIT                        .equ 0x02
SPI2MH_Bit11_MASK                       .equ 0x08
SPI2MH_Bit11_BIT                        .equ 0x03
SPI2MH_Bit12_MASK                       .equ 0x10
SPI2MH_Bit12_BIT                        .equ 0x04
SPI2MH_Bit13_MASK                       .equ 0x20
SPI2MH_Bit13_BIT                        .equ 0x05
SPI2MH_Bit14_MASK                       .equ 0x40
SPI2MH_Bit14_BIT                        .equ 0x06
SPI2MH_Bit15_MASK                       .equ 0x80
SPI2MH_Bit15_BIT                        .equ 0x07
SPI2ML_Bit0_MASK                        .equ 0x01
SPI2ML_Bit0_BIT                         .equ 0x00
SPI2ML_Bit1_MASK                        .equ 0x02
SPI2ML_Bit1_BIT                         .equ 0x01
SPI2ML_Bit2_MASK                        .equ 0x04
SPI2ML_Bit2_BIT                         .equ 0x02
SPI2ML_Bit3_MASK                        .equ 0x08
SPI2ML_Bit3_BIT                         .equ 0x03
SPI2ML_Bit4_MASK                        .equ 0x10
SPI2ML_Bit4_BIT                         .equ 0x04
SPI2ML_Bit5_MASK                        .equ 0x20
SPI2ML_Bit5_BIT                         .equ 0x05
SPI2ML_Bit6_MASK                        .equ 0x40
SPI2ML_Bit6_BIT                         .equ 0x06
SPI2ML_Bit7_MASK                        .equ 0x80
SPI2ML_Bit7_BIT                         .equ 0x07
SPI2M                                   .equ 0xFFFF8076 ;  SPI2 Match Register
SPI2M_Bit0_MASK                         .equ 0x01
SPI2M_Bit0_BIT                          .equ 0x00
SPI2M_Bit1_MASK                         .equ 0x02
SPI2M_Bit1_BIT                          .equ 0x01
SPI2M_Bit2_MASK                         .equ 0x04
SPI2M_Bit2_BIT                          .equ 0x02
SPI2M_Bit3_MASK                         .equ 0x08
SPI2M_Bit3_BIT                          .equ 0x03
SPI2M_Bit4_MASK                         .equ 0x10
SPI2M_Bit4_BIT                          .equ 0x04
SPI2M_Bit5_MASK                         .equ 0x20
SPI2M_Bit5_BIT                          .equ 0x05
SPI2M_Bit6_MASK                         .equ 0x40
SPI2M_Bit6_BIT                          .equ 0x06
SPI2M_Bit7_MASK                         .equ 0x80
SPI2M_Bit7_BIT                          .equ 0x07
SPI2M_Bit8_MASK                         .equ 0x100
SPI2M_Bit8_BIT                          .equ 0x08
SPI2M_Bit9_MASK                         .equ 0x200
SPI2M_Bit9_BIT                          .equ 0x09
SPI2M_Bit10_MASK                        .equ 0x400
SPI2M_Bit10_BIT                         .equ 0x0A
SPI2M_Bit11_MASK                        .equ 0x800
SPI2M_Bit11_BIT                         .equ 0x0B
SPI2M_Bit12_MASK                        .equ 0x1000
SPI2M_Bit12_BIT                         .equ 0x0C
SPI2M_Bit13_MASK                        .equ 0x2000
SPI2M_Bit13_BIT                         .equ 0x0D
SPI2M_Bit14_MASK                        .equ 0x4000
SPI2M_Bit14_BIT                         .equ 0x0E
SPI2M_Bit15_MASK                        .equ 0x8000
SPI2M_Bit15_BIT                         .equ 0x0F

;*********************************************
;  SPI2 Control Register 3
;*********************************************
SPI2C3                                  .equ 0xFFFF8078 ;  SPI2 Control Register 3
SPI2C3_FIFOMODE_MASK                    .equ 0x01
SPI2C3_FIFOMODE_BIT                     .equ 0x00
SPI2C3_RNFULLIEN_MASK                   .equ 0x02
SPI2C3_RNFULLIEN_BIT                    .equ 0x01
SPI2C3_TNEARIEN_MASK                    .equ 0x04
SPI2C3_TNEARIEN_BIT                     .equ 0x02
SPI2C3_RNFULLF_MARK_MASK                .equ 0x10
SPI2C3_RNFULLF_MARK_BIT                 .equ 0x04
SPI2C3_TNEAREF_MARK_MASK                .equ 0x20
SPI2C3_TNEAREF_MARK_BIT                 .equ 0x05

;*********************************************
;  System Reset Status Register
;*********************************************
SRS                                     .equ 0xFFFF9800 ;  System Reset Status Register
SRS_LVD_MASK                            .equ 0x02
SRS_LVD_BIT                             .equ 0x01
SRS_LOC_MASK                            .equ 0x04
SRS_LOC_BIT                             .equ 0x02
SRS_ILAD_MASK                           .equ 0x08
SRS_ILAD_BIT                            .equ 0x03
SRS_ILOP_MASK                           .equ 0x10
SRS_ILOP_BIT                            .equ 0x04
SRS_COP_MASK                            .equ 0x20
SRS_COP_BIT                             .equ 0x05
SRS_PIN_MASK                            .equ 0x40
SRS_PIN_BIT                             .equ 0x06
SRS_POR_MASK                            .equ 0x80
SRS_POR_BIT                             .equ 0x07

;*********************************************
;  System Options Register 1
;*********************************************
SOPT1                                   .equ 0xFFFF9802 ;  System Options Register 1
SOPT1_WAITE_MASK                        .equ 0x10
SOPT1_WAITE_BIT                         .equ 0x04
SOPT1_STOPE_MASK                        .equ 0x20
SOPT1_STOPE_BIT                         .equ 0x05
SOPT1_COPT0_MASK                        .equ 0x40
SOPT1_COPT0_BIT                         .equ 0x06
SOPT1_COPT1_MASK                        .equ 0x80
SOPT1_COPT1_BIT                         .equ 0x07
SOPT1_COPT_MASK                         .equ 0xC0

;*********************************************
;  System Options Register 2
;*********************************************
SOPT2                                   .equ 0xFFFF9803 ;  System Options Register 2
SOPT2_ACIC_MASK                         .equ 0x01
SOPT2_ACIC_BIT                          .equ 0x00
SOPT2_SPI2FE_MASK                       .equ 0x02
SOPT2_SPI2FE_BIT                        .equ 0x01
SOPT2_SPI1FE_MASK                       .equ 0x04
SOPT2_SPI1FE_BIT                        .equ 0x02
SOPT2_CMT_CLK_SEL_MASK                  .equ 0x08
SOPT2_CMT_CLK_SEL_BIT                   .equ 0x03
SOPT2_CLKOUT_EN_MASK                    .equ 0x10
SOPT2_CLKOUT_EN_BIT                     .equ 0x04
SOPT2_USB_BIGEND_MASK                   .equ 0x20
SOPT2_USB_BIGEND_BIT                    .equ 0x05
SOPT2_COPW_MASK                         .equ 0x40
SOPT2_COPW_BIT                          .equ 0x06
SOPT2_COPCLKS_MASK                      .equ 0x80
SOPT2_COPCLKS_BIT                       .equ 0x07

;*********************************************
;  System Device Identification Register
;*********************************************
SDIDH_ID8_MASK                          .equ 0x01
SDIDH_ID8_BIT                           .equ 0x00
SDIDH_ID9_MASK                          .equ 0x02
SDIDH_ID9_BIT                           .equ 0x01
SDIDH_ID10_MASK                         .equ 0x04
SDIDH_ID10_BIT                          .equ 0x02
SDIDH_ID11_MASK                         .equ 0x08
SDIDH_ID11_BIT                          .equ 0x03
SDIDH_REV0_MASK                         .equ 0x10
SDIDH_REV0_BIT                          .equ 0x04
SDIDH_REV1_MASK                         .equ 0x20
SDIDH_REV1_BIT                          .equ 0x05
SDIDH_REV2_MASK                         .equ 0x40
SDIDH_REV2_BIT                          .equ 0x06
SDIDH_REV3_MASK                         .equ 0x80
SDIDH_REV3_BIT                          .equ 0x07
SDIDH_ID_8_MASK                         .equ 0x0F
SDIDH_REV_MASK                          .equ 0xF0
SDIDL_ID0_MASK                          .equ 0x01
SDIDL_ID0_BIT                           .equ 0x00
SDIDL_ID1_MASK                          .equ 0x02
SDIDL_ID1_BIT                           .equ 0x01
SDIDL_ID2_MASK                          .equ 0x04
SDIDL_ID2_BIT                           .equ 0x02
SDIDL_ID3_MASK                          .equ 0x08
SDIDL_ID3_BIT                           .equ 0x03
SDIDL_ID4_MASK                          .equ 0x10
SDIDL_ID4_BIT                           .equ 0x04
SDIDL_ID5_MASK                          .equ 0x20
SDIDL_ID5_BIT                           .equ 0x05
SDIDL_ID6_MASK                          .equ 0x40
SDIDL_ID6_BIT                           .equ 0x06
SDIDL_ID7_MASK                          .equ 0x80
SDIDL_ID7_BIT                           .equ 0x07
SDID                                    .equ 0xFFFF9806 ;  System Device Identification Register
SDID_ID0_MASK                           .equ 0x01
SDID_ID0_BIT                            .equ 0x00
SDID_ID1_MASK                           .equ 0x02
SDID_ID1_BIT                            .equ 0x01
SDID_ID2_MASK                           .equ 0x04
SDID_ID2_BIT                            .equ 0x02
SDID_ID3_MASK                           .equ 0x08
SDID_ID3_BIT                            .equ 0x03
SDID_ID4_MASK                           .equ 0x10
SDID_ID4_BIT                            .equ 0x04
SDID_ID5_MASK                           .equ 0x20
SDID_ID5_BIT                            .equ 0x05
SDID_ID6_MASK                           .equ 0x40
SDID_ID6_BIT                            .equ 0x06
SDID_ID7_MASK                           .equ 0x80
SDID_ID7_BIT                            .equ 0x07
SDID_ID8_MASK                           .equ 0x100
SDID_ID8_BIT                            .equ 0x08
SDID_ID9_MASK                           .equ 0x200
SDID_ID9_BIT                            .equ 0x09
SDID_ID10_MASK                          .equ 0x400
SDID_ID10_BIT                           .equ 0x0A
SDID_ID11_MASK                          .equ 0x800
SDID_ID11_BIT                           .equ 0x0B
SDID_REV0_MASK                          .equ 0x1000
SDID_REV0_BIT                           .equ 0x0C
SDID_REV1_MASK                          .equ 0x2000
SDID_REV1_BIT                           .equ 0x0D
SDID_REV2_MASK                          .equ 0x4000
SDID_REV2_BIT                           .equ 0x0E
SDID_REV3_MASK                          .equ 0x8000
SDID_REV3_BIT                           .equ 0x0F
SDID_ID_MASK                            .equ 0xFFF
SDID_REV_MASK                           .equ 0xF000

;*********************************************
;  System Power Management Status and Control 1 Register
;*********************************************
SPMSC1                                  .equ 0xFFFF9809 ;  System Power Management Status and Control 1 Register
SPMSC1_BGBE_MASK                        .equ 0x01
SPMSC1_BGBE_BIT                         .equ 0x00
SPMSC1_LVDE_MASK                        .equ 0x04
SPMSC1_LVDE_BIT                         .equ 0x02
SPMSC1_LVDSE_MASK                       .equ 0x08
SPMSC1_LVDSE_BIT                        .equ 0x03
SPMSC1_LVDRE_MASK                       .equ 0x10
SPMSC1_LVDRE_BIT                        .equ 0x04
SPMSC1_LVWIE_MASK                       .equ 0x20
SPMSC1_LVWIE_BIT                        .equ 0x05
SPMSC1_LVWACK_MASK                      .equ 0x40
SPMSC1_LVWACK_BIT                       .equ 0x06
SPMSC1_LVWF_MASK                        .equ 0x80
SPMSC1_LVWF_BIT                         .equ 0x07

;*********************************************
;  System Power Management Status and Control 2 Register
;*********************************************
SPMSC2                                  .equ 0xFFFF980A ;  System Power Management Status and Control 2 Register
SPMSC2_PPDC_MASK                        .equ 0x01
SPMSC2_PPDC_BIT                         .equ 0x00
SPMSC2_PPDACK_MASK                      .equ 0x04
SPMSC2_PPDACK_BIT                       .equ 0x02
SPMSC2_PPDF_MASK                        .equ 0x08
SPMSC2_PPDF_BIT                         .equ 0x03
SPMSC2_LVWV_MASK                        .equ 0x10
SPMSC2_LVWV_BIT                         .equ 0x04
SPMSC2_LVDV_MASK                        .equ 0x20
SPMSC2_LVDV_BIT                         .equ 0x05

;*********************************************
;  System Clock Gating Control 1 Register
;*********************************************
SCGC1                                   .equ 0xFFFF980B ;  System Clock Gating Control 1 Register
SCGC1_SCI1_MASK                         .equ 0x01
SCGC1_SCI1_BIT                          .equ 0x00
SCGC1_SCI2_MASK                         .equ 0x02
SCGC1_SCI2_BIT                          .equ 0x01
SCGC1_IIC1_MASK                         .equ 0x04
SCGC1_IIC1_BIT                          .equ 0x02
SCGC1_IIC2_MASK                         .equ 0x08
SCGC1_IIC2_BIT                          .equ 0x03
SCGC1_ADC_MASK                          .equ 0x10
SCGC1_ADC_BIT                           .equ 0x04
SCGC1_TPM1_MASK                         .equ 0x20
SCGC1_TPM1_BIT                          .equ 0x05
SCGC1_TPM2_MASK                         .equ 0x40
SCGC1_TPM2_BIT                          .equ 0x06
SCGC1_CMT_MASK                          .equ 0x80
SCGC1_CMT_BIT                           .equ 0x07
SCGC1_SCI_1_MASK                        .equ 0x03
SCGC1_IIC_1_MASK                        .equ 0x0C
SCGC1_TPM_1_MASK                        .equ 0x60

;*********************************************
;  System Clock Gating Control 2 Register
;*********************************************
SCGC2                                   .equ 0xFFFF980C ;  System Clock Gating Control 2 Register
SCGC2_SPI1_MASK                         .equ 0x01
SCGC2_SPI1_BIT                          .equ 0x00
SCGC2_SPI2_MASK                         .equ 0x02
SCGC2_SPI2_BIT                          .equ 0x01
SCGC2_RTC_MASK                          .equ 0x04
SCGC2_RTC_BIT                           .equ 0x02
SCGC2_ACMP_MASK                         .equ 0x08
SCGC2_ACMP_BIT                          .equ 0x03
SCGC2_KBI_MASK                          .equ 0x10
SCGC2_KBI_BIT                           .equ 0x04
SCGC2_IRQ_MASK                          .equ 0x20
SCGC2_IRQ_BIT                           .equ 0x05
SCGC2_FLS_MASK                          .equ 0x40
SCGC2_FLS_BIT                           .equ 0x06
SCGC2_USB_MASK                          .equ 0x80
SCGC2_USB_BIT                           .equ 0x07
SCGC2_SPI_1_MASK                        .equ 0x03

;*********************************************
;  System Clock Gating Control 3 Register
;*********************************************
SCGC3                                   .equ 0xFFFF980D ;  System Clock Gating Control 3 Register
SCGC3_RNGA_MASK                         .equ 0x01
SCGC3_RNGA_BIT                          .equ 0x00

;*********************************************
;  System Options 3 Register
;*********************************************
SOPT3                                   .equ 0xFFFF980E ;  System Options 3 Register
SOPT3_CMT_PAD_MASK                      .equ 0x01
SOPT3_CMT_PAD_BIT                       .equ 0x00

;*********************************************
;  System Options 4 Register
;*********************************************
SOPT4                                   .equ 0xFFFF980F ;  System Options 4 Register
SOPT4_PMC_LVD_TRIM0_MASK                .equ 0x01
SOPT4_PMC_LVD_TRIM0_BIT                 .equ 0x00
SOPT4_PMC_LVD_TRIM1_MASK                .equ 0x02
SOPT4_PMC_LVD_TRIM1_BIT                 .equ 0x01
SOPT4_PMC_LVD_TRIM2_MASK                .equ 0x04
SOPT4_PMC_LVD_TRIM2_BIT                 .equ 0x02
SOPT4_PMC_LVD_TRIM3_MASK                .equ 0x08
SOPT4_PMC_LVD_TRIM3_BIT                 .equ 0x03
SOPT4_PMC_LVD_TRIM_MASK                 .equ 0x0F

;*********************************************
;  FLASH Clock Divider Register
;*********************************************
FCDIV                                   .equ 0xFFFF9820 ;  FLASH Clock Divider Register
FCDIV_FDIV0_MASK                        .equ 0x01
FCDIV_FDIV0_BIT                         .equ 0x00
FCDIV_FDIV1_MASK                        .equ 0x02
FCDIV_FDIV1_BIT                         .equ 0x01
FCDIV_FDIV2_MASK                        .equ 0x04
FCDIV_FDIV2_BIT                         .equ 0x02
FCDIV_FDIV3_MASK                        .equ 0x08
FCDIV_FDIV3_BIT                         .equ 0x03
FCDIV_FDIV4_MASK                        .equ 0x10
FCDIV_FDIV4_BIT                         .equ 0x04
FCDIV_FDIV5_MASK                        .equ 0x20
FCDIV_FDIV5_BIT                         .equ 0x05
FCDIV_PRDIV8_MASK                       .equ 0x40
FCDIV_PRDIV8_BIT                        .equ 0x06
FCDIV_FDIVLD_MASK                       .equ 0x80
FCDIV_FDIVLD_BIT                        .equ 0x07
FCDIV_FDIV_MASK                         .equ 0x3F

;*********************************************
;  Flash Options Register
;*********************************************
FOPT                                    .equ 0xFFFF9821 ;  Flash Options Register
FOPT_SEC0_MASK                          .equ 0x01
FOPT_SEC0_BIT                           .equ 0x00
FOPT_SEC1_MASK                          .equ 0x02
FOPT_SEC1_BIT                           .equ 0x01
FOPT_KEYEN0_MASK                        .equ 0x40
FOPT_KEYEN0_BIT                         .equ 0x06
FOPT_KEYEN1_MASK                        .equ 0x80
FOPT_KEYEN1_BIT                         .equ 0x07
FOPT_SEC_MASK                           .equ 0x03
FOPT_KEYEN_MASK                         .equ 0xC0

;*********************************************
;  Flash Configuration Register
;*********************************************
FCNFG                                   .equ 0xFFFF9823 ;  Flash Configuration Register
FCNFG_KEYACC_MASK                       .equ 0x20
FCNFG_KEYACC_BIT                        .equ 0x05

;*********************************************
;  Flash Protection Register
;*********************************************
FPROT                                   .equ 0xFFFF9824 ;  Flash Protection Register
FPROT_FPOPEN_MASK                       .equ 0x01
FPROT_FPOPEN_BIT                        .equ 0x00
FPROT_FPS0_MASK                         .equ 0x02
FPROT_FPS0_BIT                          .equ 0x01
FPROT_FPS1_MASK                         .equ 0x04
FPROT_FPS1_BIT                          .equ 0x02
FPROT_FPS2_MASK                         .equ 0x08
FPROT_FPS2_BIT                          .equ 0x03
FPROT_FPS3_MASK                         .equ 0x10
FPROT_FPS3_BIT                          .equ 0x04
FPROT_FPS4_MASK                         .equ 0x20
FPROT_FPS4_BIT                          .equ 0x05
FPROT_FPS5_MASK                         .equ 0x40
FPROT_FPS5_BIT                          .equ 0x06
FPROT_FPS6_MASK                         .equ 0x80
FPROT_FPS6_BIT                          .equ 0x07
FPROT_FPS_MASK                          .equ 0xFE

;*********************************************
;  Flash Status Register
;*********************************************
FSTAT                                   .equ 0xFFFF9825 ;  Flash Status Register
FSTAT_FBLANK_MASK                       .equ 0x04
FSTAT_FBLANK_BIT                        .equ 0x02
FSTAT_FACCERR_MASK                      .equ 0x10
FSTAT_FACCERR_BIT                       .equ 0x04
FSTAT_FPVIOL_MASK                       .equ 0x20
FSTAT_FPVIOL_BIT                        .equ 0x05
FSTAT_FCCF_MASK                         .equ 0x40
FSTAT_FCCF_BIT                          .equ 0x06
FSTAT_FCBEF_MASK                        .equ 0x80
FSTAT_FCBEF_BIT                         .equ 0x07

;*********************************************
;  Flash Command Register
;*********************************************
FCMD                                    .equ 0xFFFF9826 ;  Flash Command Register
FCMD_FCMD0_MASK                         .equ 0x01
FCMD_FCMD0_BIT                          .equ 0x00
FCMD_FCMD1_MASK                         .equ 0x02
FCMD_FCMD1_BIT                          .equ 0x01
FCMD_FCMD2_MASK                         .equ 0x04
FCMD_FCMD2_BIT                          .equ 0x02
FCMD_FCMD3_MASK                         .equ 0x08
FCMD_FCMD3_BIT                          .equ 0x03
FCMD_FCMD4_MASK                         .equ 0x10
FCMD_FCMD4_BIT                          .equ 0x04
FCMD_FCMD5_MASK                         .equ 0x20
FCMD_FCMD5_BIT                          .equ 0x05
FCMD_FCMD6_MASK                         .equ 0x40
FCMD_FCMD6_BIT                          .equ 0x06
FCMD_FCMD_MASK                          .equ 0x7F

;*********************************************
;  IIC Address Register
;*********************************************
IIC2A                                   .equ 0xFFFF9838 ;  IIC Address Register
IIC2A_AD1_MASK                          .equ 0x02
IIC2A_AD1_BIT                           .equ 0x01
IIC2A_AD2_MASK                          .equ 0x04
IIC2A_AD2_BIT                           .equ 0x02
IIC2A_AD3_MASK                          .equ 0x08
IIC2A_AD3_BIT                           .equ 0x03
IIC2A_AD4_MASK                          .equ 0x10
IIC2A_AD4_BIT                           .equ 0x04
IIC2A_AD5_MASK                          .equ 0x20
IIC2A_AD5_BIT                           .equ 0x05
IIC2A_AD6_MASK                          .equ 0x40
IIC2A_AD6_BIT                           .equ 0x06
IIC2A_AD7_MASK                          .equ 0x80
IIC2A_AD7_BIT                           .equ 0x07
IIC2A_AD_1_MASK                         .equ 0xFE

;*********************************************
;  IIC Frequency Divider Register
;*********************************************
IIC2F                                   .equ 0xFFFF9839 ;  IIC Frequency Divider Register
IIC2F_ICR0_MASK                         .equ 0x01
IIC2F_ICR0_BIT                          .equ 0x00
IIC2F_ICR1_MASK                         .equ 0x02
IIC2F_ICR1_BIT                          .equ 0x01
IIC2F_ICR2_MASK                         .equ 0x04
IIC2F_ICR2_BIT                          .equ 0x02
IIC2F_ICR3_MASK                         .equ 0x08
IIC2F_ICR3_BIT                          .equ 0x03
IIC2F_ICR4_MASK                         .equ 0x10
IIC2F_ICR4_BIT                          .equ 0x04
IIC2F_ICR5_MASK                         .equ 0x20
IIC2F_ICR5_BIT                          .equ 0x05
IIC2F_MULT0_MASK                        .equ 0x40
IIC2F_MULT0_BIT                         .equ 0x06
IIC2F_MULT1_MASK                        .equ 0x80
IIC2F_MULT1_BIT                         .equ 0x07
IIC2F_ICR_MASK                          .equ 0x3F
IIC2F_MULT_MASK                         .equ 0xC0

;*********************************************
;  IIC Control Register 1
;*********************************************
IIC2C1_RSTA_MASK                        .equ 0x04
IIC2C1_RSTA_BIT                         .equ 0x02
IIC2C1_TXAK_MASK                        .equ 0x08
IIC2C1_TXAK_BIT                         .equ 0x03
IIC2C1_TX_MASK                          .equ 0x10
IIC2C1_TX_BIT                           .equ 0x04
IIC2C1_MST_MASK                         .equ 0x20
IIC2C1_MST_BIT                          .equ 0x05
IIC2C1_IICIE_MASK                       .equ 0x40
IIC2C1_IICIE_BIT                        .equ 0x06
IIC2C1_IICEN_MASK                       .equ 0x80
IIC2C1_IICEN_BIT                        .equ 0x07
IIC2C_RSTA_MASK                         .equ 0x04
IIC2C_RSTA_BIT                          .equ 0x02
IIC2C_TXAK_MASK                         .equ 0x08
IIC2C_TXAK_BIT                          .equ 0x03
IIC2C_TX_MASK                           .equ 0x10
IIC2C_TX_BIT                            .equ 0x04
IIC2C_MST_MASK                          .equ 0x20
IIC2C_MST_BIT                           .equ 0x05
IIC2C_IICIE_MASK                        .equ 0x40
IIC2C_IICIE_BIT                         .equ 0x06
IIC2C_IICEN_MASK                        .equ 0x80
IIC2C_IICEN_BIT                         .equ 0x07
IIC2C1                                  .equ 0xFFFF983A ;  IIC Control Register 1

;*********************************************
;  IIC Status Register
;*********************************************
IIC2S                                   .equ 0xFFFF983B ;  IIC Status Register
IIC2S_RXAK_MASK                         .equ 0x01
IIC2S_RXAK_BIT                          .equ 0x00
IIC2S_IICIF_MASK                        .equ 0x02
IIC2S_IICIF_BIT                         .equ 0x01
IIC2S_SRW_MASK                          .equ 0x04
IIC2S_SRW_BIT                           .equ 0x02
IIC2S_ARBL_MASK                         .equ 0x10
IIC2S_ARBL_BIT                          .equ 0x04
IIC2S_BUSY_MASK                         .equ 0x20
IIC2S_BUSY_BIT                          .equ 0x05
IIC2S_IAAS_MASK                         .equ 0x40
IIC2S_IAAS_BIT                          .equ 0x06
IIC2S_TCF_MASK                          .equ 0x80
IIC2S_TCF_BIT                           .equ 0x07

;*********************************************
;  IIC Data I/O Register
;*********************************************
IIC2D                                   .equ 0xFFFF983C ;  IIC Data I/O Register
IIC2D_DATA0_MASK                        .equ 0x01
IIC2D_DATA0_BIT                         .equ 0x00
IIC2D_DATA1_MASK                        .equ 0x02
IIC2D_DATA1_BIT                         .equ 0x01
IIC2D_DATA2_MASK                        .equ 0x04
IIC2D_DATA2_BIT                         .equ 0x02
IIC2D_DATA3_MASK                        .equ 0x08
IIC2D_DATA3_BIT                         .equ 0x03
IIC2D_DATA4_MASK                        .equ 0x10
IIC2D_DATA4_BIT                         .equ 0x04
IIC2D_DATA5_MASK                        .equ 0x20
IIC2D_DATA5_BIT                         .equ 0x05
IIC2D_DATA6_MASK                        .equ 0x40
IIC2D_DATA6_BIT                         .equ 0x06
IIC2D_DATA7_MASK                        .equ 0x80
IIC2D_DATA7_BIT                         .equ 0x07

;*********************************************
;  IIC Control Register 2
;*********************************************
IIC2C2                                  .equ 0xFFFF983D ;  IIC Control Register 2
IIC2C2_AD8_MASK                         .equ 0x01
IIC2C2_AD8_BIT                          .equ 0x00
IIC2C2_AD9_MASK                         .equ 0x02
IIC2C2_AD9_BIT                          .equ 0x01
IIC2C2_AD10_MASK                        .equ 0x04
IIC2C2_AD10_BIT                         .equ 0x02
IIC2C2_ADEXT_MASK                       .equ 0x40
IIC2C2_ADEXT_BIT                        .equ 0x06
IIC2C2_GCAEN_MASK                       .equ 0x80
IIC2C2_GCAEN_BIT                        .equ 0x07
IIC2C2_AD_8_MASK                        .equ 0x07

;*********************************************
;  Port A Pull Enable Register
;*********************************************
PTAPE                                   .equ 0xFFFF9840 ;  Port A Pull Enable Register
PTAPE_PTAPE0_MASK                       .equ 0x01
PTAPE_PTAPE0_BIT                        .equ 0x00
PTAPE_PTAPE1_MASK                       .equ 0x02
PTAPE_PTAPE1_BIT                        .equ 0x01
PTAPE_PTAPE2_MASK                       .equ 0x04
PTAPE_PTAPE2_BIT                        .equ 0x02
PTAPE_PTAPE3_MASK                       .equ 0x08
PTAPE_PTAPE3_BIT                        .equ 0x03
PTAPE_PTAPE4_MASK                       .equ 0x10
PTAPE_PTAPE4_BIT                        .equ 0x04
PTAPE_PTAPE5_MASK                       .equ 0x20
PTAPE_PTAPE5_BIT                        .equ 0x05
PTAPE_PTAPE6_MASK                       .equ 0x40
PTAPE_PTAPE6_BIT                        .equ 0x06
PTAPE_PTAPE7_MASK                       .equ 0x80
PTAPE_PTAPE7_BIT                        .equ 0x07

;*********************************************
;  Port A Slew Rate Enable Register
;*********************************************
PTASE                                   .equ 0xFFFF9841 ;  Port A Slew Rate Enable Register
PTASE_PTASE0_MASK                       .equ 0x01
PTASE_PTASE0_BIT                        .equ 0x00
PTASE_PTASE1_MASK                       .equ 0x02
PTASE_PTASE1_BIT                        .equ 0x01
PTASE_PTASE2_MASK                       .equ 0x04
PTASE_PTASE2_BIT                        .equ 0x02
PTASE_PTASE3_MASK                       .equ 0x08
PTASE_PTASE3_BIT                        .equ 0x03
PTASE_PTASE4_MASK                       .equ 0x10
PTASE_PTASE4_BIT                        .equ 0x04
PTASE_PTASE5_MASK                       .equ 0x20
PTASE_PTASE5_BIT                        .equ 0x05
PTASE_PTASE6_MASK                       .equ 0x40
PTASE_PTASE6_BIT                        .equ 0x06
PTASE_PTASE7_MASK                       .equ 0x80
PTASE_PTASE7_BIT                        .equ 0x07

;*********************************************
;  Port A Drive Strength Selection Register
;*********************************************
PTADS                                   .equ 0xFFFF9842 ;  Port A Drive Strength Selection Register
PTADS_PTADS0_MASK                       .equ 0x01
PTADS_PTADS0_BIT                        .equ 0x00
PTADS_PTADS1_MASK                       .equ 0x02
PTADS_PTADS1_BIT                        .equ 0x01
PTADS_PTADS2_MASK                       .equ 0x04
PTADS_PTADS2_BIT                        .equ 0x02
PTADS_PTADS3_MASK                       .equ 0x08
PTADS_PTADS3_BIT                        .equ 0x03
PTADS_PTADS4_MASK                       .equ 0x10
PTADS_PTADS4_BIT                        .equ 0x04
PTADS_PTADS5_MASK                       .equ 0x20
PTADS_PTADS5_BIT                        .equ 0x05
PTADS_PTADS6_MASK                       .equ 0x40
PTADS_PTADS6_BIT                        .equ 0x06
PTADS_PTADS7_MASK                       .equ 0x80
PTADS_PTADS7_BIT                        .equ 0x07

;*********************************************
;  Port A Input Filter Enable Register
;*********************************************
PTAIFE                                  .equ 0xFFFF9843 ;  Port A Input Filter Enable Register
PTAIFE_PTAIFE0_MASK                     .equ 0x01
PTAIFE_PTAIFE0_BIT                      .equ 0x00
PTAIFE_PTAIFE1_MASK                     .equ 0x02
PTAIFE_PTAIFE1_BIT                      .equ 0x01
PTAIFE_PTAIFE2_MASK                     .equ 0x04
PTAIFE_PTAIFE2_BIT                      .equ 0x02
PTAIFE_PTAIFE3_MASK                     .equ 0x08
PTAIFE_PTAIFE3_BIT                      .equ 0x03
PTAIFE_PTAIFE4_MASK                     .equ 0x10
PTAIFE_PTAIFE4_BIT                      .equ 0x04
PTAIFE_PTAIFE5_MASK                     .equ 0x20
PTAIFE_PTAIFE5_BIT                      .equ 0x05
PTAIFE_PTAIFE6_MASK                     .equ 0x40
PTAIFE_PTAIFE6_BIT                      .equ 0x06
PTAIFE_PTAIFE7_MASK                     .equ 0x80
PTAIFE_PTAIFE7_BIT                      .equ 0x07

;*********************************************
;  Port B Pull Enable Register
;*********************************************
PTBPE                                   .equ 0xFFFF9844 ;  Port B Pull Enable Register
PTBPE_PTBPE0_MASK                       .equ 0x01
PTBPE_PTBPE0_BIT                        .equ 0x00
PTBPE_PTBPE1_MASK                       .equ 0x02
PTBPE_PTBPE1_BIT                        .equ 0x01
PTBPE_PTBPE2_MASK                       .equ 0x04
PTBPE_PTBPE2_BIT                        .equ 0x02
PTBPE_PTBPE3_MASK                       .equ 0x08
PTBPE_PTBPE3_BIT                        .equ 0x03
PTBPE_PTBPE4_MASK                       .equ 0x10
PTBPE_PTBPE4_BIT                        .equ 0x04
PTBPE_PTBPE5_MASK                       .equ 0x20
PTBPE_PTBPE5_BIT                        .equ 0x05
PTBPE_PTBPE6_MASK                       .equ 0x40
PTBPE_PTBPE6_BIT                        .equ 0x06
PTBPE_PTBPE7_MASK                       .equ 0x80
PTBPE_PTBPE7_BIT                        .equ 0x07

;*********************************************
;  Port B Slew Rate Enable Register
;*********************************************
PTBSE                                   .equ 0xFFFF9845 ;  Port B Slew Rate Enable Register
PTBSE_PTBSE0_MASK                       .equ 0x01
PTBSE_PTBSE0_BIT                        .equ 0x00
PTBSE_PTBSE1_MASK                       .equ 0x02
PTBSE_PTBSE1_BIT                        .equ 0x01
PTBSE_PTBSE2_MASK                       .equ 0x04
PTBSE_PTBSE2_BIT                        .equ 0x02
PTBSE_PTBSE3_MASK                       .equ 0x08
PTBSE_PTBSE3_BIT                        .equ 0x03
PTBSE_PTBSE4_MASK                       .equ 0x10
PTBSE_PTBSE4_BIT                        .equ 0x04
PTBSE_PTBSE5_MASK                       .equ 0x20
PTBSE_PTBSE5_BIT                        .equ 0x05
PTBSE_PTBSE6_MASK                       .equ 0x40
PTBSE_PTBSE6_BIT                        .equ 0x06
PTBSE_PTBSE7_MASK                       .equ 0x80
PTBSE_PTBSE7_BIT                        .equ 0x07

;*********************************************
;  Port B Drive Strength Selection Register
;*********************************************
PTBDS                                   .equ 0xFFFF9846 ;  Port B Drive Strength Selection Register
PTBDS_PTBDS0_MASK                       .equ 0x01
PTBDS_PTBDS0_BIT                        .equ 0x00
PTBDS_PTBDS1_MASK                       .equ 0x02
PTBDS_PTBDS1_BIT                        .equ 0x01
PTBDS_PTBDS2_MASK                       .equ 0x04
PTBDS_PTBDS2_BIT                        .equ 0x02
PTBDS_PTBDS3_MASK                       .equ 0x08
PTBDS_PTBDS3_BIT                        .equ 0x03
PTBDS_PTBDS4_MASK                       .equ 0x10
PTBDS_PTBDS4_BIT                        .equ 0x04
PTBDS_PTBDS5_MASK                       .equ 0x20
PTBDS_PTBDS5_BIT                        .equ 0x05
PTBDS_PTBDS6_MASK                       .equ 0x40
PTBDS_PTBDS6_BIT                        .equ 0x06
PTBDS_PTBDS7_MASK                       .equ 0x80
PTBDS_PTBDS7_BIT                        .equ 0x07

;*********************************************
;  Port B Input Filter Enable Register
;*********************************************
PTBIFE                                  .equ 0xFFFF9847 ;  Port B Input Filter Enable Register
PTBIFE_PTBIFE0_MASK                     .equ 0x01
PTBIFE_PTBIFE0_BIT                      .equ 0x00
PTBIFE_PTBIFE1_MASK                     .equ 0x02
PTBIFE_PTBIFE1_BIT                      .equ 0x01
PTBIFE_PTBIFE2_MASK                     .equ 0x04
PTBIFE_PTBIFE2_BIT                      .equ 0x02
PTBIFE_PTBIFE3_MASK                     .equ 0x08
PTBIFE_PTBIFE3_BIT                      .equ 0x03
PTBIFE_PTBIFE4_MASK                     .equ 0x10
PTBIFE_PTBIFE4_BIT                      .equ 0x04
PTBIFE_PTBIFE5_MASK                     .equ 0x20
PTBIFE_PTBIFE5_BIT                      .equ 0x05
PTBIFE_PTBIFE6_MASK                     .equ 0x40
PTBIFE_PTBIFE6_BIT                      .equ 0x06
PTBIFE_PTBIFE7_MASK                     .equ 0x80
PTBIFE_PTBIFE7_BIT                      .equ 0x07

;*********************************************
;  Port C Pull Enable Register
;*********************************************
PTCPE                                   .equ 0xFFFF9848 ;  Port C Pull Enable Register
PTCPE_PTCPE0_MASK                       .equ 0x01
PTCPE_PTCPE0_BIT                        .equ 0x00
PTCPE_PTCPE1_MASK                       .equ 0x02
PTCPE_PTCPE1_BIT                        .equ 0x01
PTCPE_PTCPE2_MASK                       .equ 0x04
PTCPE_PTCPE2_BIT                        .equ 0x02
PTCPE_PTCPE3_MASK                       .equ 0x08
PTCPE_PTCPE3_BIT                        .equ 0x03
PTCPE_PTCPE4_MASK                       .equ 0x10
PTCPE_PTCPE4_BIT                        .equ 0x04
PTCPE_PTCPE5_MASK                       .equ 0x20
PTCPE_PTCPE5_BIT                        .equ 0x05
PTCPE_PTCPE6_MASK                       .equ 0x40
PTCPE_PTCPE6_BIT                        .equ 0x06
PTCPE_PTCPE7_MASK                       .equ 0x80
PTCPE_PTCPE7_BIT                        .equ 0x07

;*********************************************
;  Port C Slew Rate Enable Register
;*********************************************
PTCSE                                   .equ 0xFFFF9849 ;  Port C Slew Rate Enable Register
PTCSE_PTCSE0_MASK                       .equ 0x01
PTCSE_PTCSE0_BIT                        .equ 0x00
PTCSE_PTCSE1_MASK                       .equ 0x02
PTCSE_PTCSE1_BIT                        .equ 0x01
PTCSE_PTCSE2_MASK                       .equ 0x04
PTCSE_PTCSE2_BIT                        .equ 0x02
PTCSE_PTCSE3_MASK                       .equ 0x08
PTCSE_PTCSE3_BIT                        .equ 0x03
PTCSE_PTCSE4_MASK                       .equ 0x10
PTCSE_PTCSE4_BIT                        .equ 0x04
PTCSE_PTCSE5_MASK                       .equ 0x20
PTCSE_PTCSE5_BIT                        .equ 0x05
PTCSE_PTCSE6_MASK                       .equ 0x40
PTCSE_PTCSE6_BIT                        .equ 0x06
PTCSE_PTCSE7_MASK                       .equ 0x80
PTCSE_PTCSE7_BIT                        .equ 0x07

;*********************************************
;  Port C Drive Strength Selection Register
;*********************************************
PTCDS                                   .equ 0xFFFF984A ;  Port C Drive Strength Selection Register
PTCDS_PTCDS0_MASK                       .equ 0x01
PTCDS_PTCDS0_BIT                        .equ 0x00
PTCDS_PTCDS1_MASK                       .equ 0x02
PTCDS_PTCDS1_BIT                        .equ 0x01
PTCDS_PTCDS2_MASK                       .equ 0x04
PTCDS_PTCDS2_BIT                        .equ 0x02
PTCDS_PTCDS3_MASK                       .equ 0x08
PTCDS_PTCDS3_BIT                        .equ 0x03
PTCDS_PTCDS4_MASK                       .equ 0x10
PTCDS_PTCDS4_BIT                        .equ 0x04
PTCDS_PTCDS5_MASK                       .equ 0x20
PTCDS_PTCDS5_BIT                        .equ 0x05
PTCDS_PTCDS6_MASK                       .equ 0x40
PTCDS_PTCDS6_BIT                        .equ 0x06
PTCDS_PTCDS7_MASK                       .equ 0x80
PTCDS_PTCDS7_BIT                        .equ 0x07

;*********************************************
;  Port C Input Filter Enable Register
;*********************************************
PTCIFE                                  .equ 0xFFFF984B ;  Port C Input Filter Enable Register
PTCIFE_PTCIFE0_MASK                     .equ 0x01
PTCIFE_PTCIFE0_BIT                      .equ 0x00
PTCIFE_PTCIFE1_MASK                     .equ 0x02
PTCIFE_PTCIFE1_BIT                      .equ 0x01
PTCIFE_PTCIFE2_MASK                     .equ 0x04
PTCIFE_PTCIFE2_BIT                      .equ 0x02
PTCIFE_PTCIFE3_MASK                     .equ 0x08
PTCIFE_PTCIFE3_BIT                      .equ 0x03
PTCIFE_PTCIFE4_MASK                     .equ 0x10
PTCIFE_PTCIFE4_BIT                      .equ 0x04
PTCIFE_PTCIFE5_MASK                     .equ 0x20
PTCIFE_PTCIFE5_BIT                      .equ 0x05
PTCIFE_PTCIFE6_MASK                     .equ 0x40
PTCIFE_PTCIFE6_BIT                      .equ 0x06
PTCIFE_PTCIFE7_MASK                     .equ 0x80
PTCIFE_PTCIFE7_BIT                      .equ 0x07

;*********************************************
;  Port D Pull Enable Register
;*********************************************
PTDPE                                   .equ 0xFFFF984C ;  Port D Pull Enable Register
PTDPE_PTDPE0_MASK                       .equ 0x01
PTDPE_PTDPE0_BIT                        .equ 0x00
PTDPE_PTDPE1_MASK                       .equ 0x02
PTDPE_PTDPE1_BIT                        .equ 0x01
PTDPE_PTDPE2_MASK                       .equ 0x04
PTDPE_PTDPE2_BIT                        .equ 0x02
PTDPE_PTDPE3_MASK                       .equ 0x08
PTDPE_PTDPE3_BIT                        .equ 0x03
PTDPE_PTDPE4_MASK                       .equ 0x10
PTDPE_PTDPE4_BIT                        .equ 0x04
PTDPE_PTDPE5_MASK                       .equ 0x20
PTDPE_PTDPE5_BIT                        .equ 0x05
PTDPE_PTDPE6_MASK                       .equ 0x40
PTDPE_PTDPE6_BIT                        .equ 0x06
PTDPE_PTDPE7_MASK                       .equ 0x80
PTDPE_PTDPE7_BIT                        .equ 0x07

;*********************************************
;  Port D Slew Rate Enable Register
;*********************************************
PTDSE                                   .equ 0xFFFF984D ;  Port D Slew Rate Enable Register
PTDSE_PTDSE0_MASK                       .equ 0x01
PTDSE_PTDSE0_BIT                        .equ 0x00
PTDSE_PTDSE1_MASK                       .equ 0x02
PTDSE_PTDSE1_BIT                        .equ 0x01
PTDSE_PTDSE2_MASK                       .equ 0x04
PTDSE_PTDSE2_BIT                        .equ 0x02
PTDSE_PTDSE3_MASK                       .equ 0x08
PTDSE_PTDSE3_BIT                        .equ 0x03
PTDSE_PTDSE4_MASK                       .equ 0x10
PTDSE_PTDSE4_BIT                        .equ 0x04
PTDSE_PTDSE5_MASK                       .equ 0x20
PTDSE_PTDSE5_BIT                        .equ 0x05
PTDSE_PTDSE6_MASK                       .equ 0x40
PTDSE_PTDSE6_BIT                        .equ 0x06
PTDSE_PTDSE7_MASK                       .equ 0x80
PTDSE_PTDSE7_BIT                        .equ 0x07

;*********************************************
;  Port D Drive Strength Selection Register
;*********************************************
PTDDS                                   .equ 0xFFFF984E ;  Port D Drive Strength Selection Register
PTDDS_PTDDS0_MASK                       .equ 0x01
PTDDS_PTDDS0_BIT                        .equ 0x00
PTDDS_PTDDS1_MASK                       .equ 0x02
PTDDS_PTDDS1_BIT                        .equ 0x01
PTDDS_PTDDS2_MASK                       .equ 0x04
PTDDS_PTDDS2_BIT                        .equ 0x02
PTDDS_PTDDS3_MASK                       .equ 0x08
PTDDS_PTDDS3_BIT                        .equ 0x03
PTDDS_PTDDS4_MASK                       .equ 0x10
PTDDS_PTDDS4_BIT                        .equ 0x04
PTDDS_PTDDS5_MASK                       .equ 0x20
PTDDS_PTDDS5_BIT                        .equ 0x05
PTDDS_PTDDS6_MASK                       .equ 0x40
PTDDS_PTDDS6_BIT                        .equ 0x06
PTDDS_PTDDS7_MASK                       .equ 0x80
PTDDS_PTDDS7_BIT                        .equ 0x07

;*********************************************
;  Port D Input Filter Enable Register
;*********************************************
PTDIFE                                  .equ 0xFFFF984F ;  Port D Input Filter Enable Register
PTDIFE_PTDIFE0_MASK                     .equ 0x01
PTDIFE_PTDIFE0_BIT                      .equ 0x00
PTDIFE_PTDIFE1_MASK                     .equ 0x02
PTDIFE_PTDIFE1_BIT                      .equ 0x01
PTDIFE_PTDIFE2_MASK                     .equ 0x04
PTDIFE_PTDIFE2_BIT                      .equ 0x02
PTDIFE_PTDIFE3_MASK                     .equ 0x08
PTDIFE_PTDIFE3_BIT                      .equ 0x03
PTDIFE_PTDIFE4_MASK                     .equ 0x10
PTDIFE_PTDIFE4_BIT                      .equ 0x04
PTDIFE_PTDIFE5_MASK                     .equ 0x20
PTDIFE_PTDIFE5_BIT                      .equ 0x05
PTDIFE_PTDIFE6_MASK                     .equ 0x40
PTDIFE_PTDIFE6_BIT                      .equ 0x06
PTDIFE_PTDIFE7_MASK                     .equ 0x80
PTDIFE_PTDIFE7_BIT                      .equ 0x07

;*********************************************
;  Port E Pull Enable Register
;*********************************************
PTEPE                                   .equ 0xFFFF9850 ;  Port E Pull Enable Register
PTEPE_PTEPE0_MASK                       .equ 0x01
PTEPE_PTEPE0_BIT                        .equ 0x00
PTEPE_PTEPE1_MASK                       .equ 0x02
PTEPE_PTEPE1_BIT                        .equ 0x01
PTEPE_PTEPE2_MASK                       .equ 0x04
PTEPE_PTEPE2_BIT                        .equ 0x02
PTEPE_PTEPE3_MASK                       .equ 0x08
PTEPE_PTEPE3_BIT                        .equ 0x03
PTEPE_PTEPE4_MASK                       .equ 0x10
PTEPE_PTEPE4_BIT                        .equ 0x04
PTEPE_PTEPE5_MASK                       .equ 0x20
PTEPE_PTEPE5_BIT                        .equ 0x05
PTEPE_PTEPE6_MASK                       .equ 0x40
PTEPE_PTEPE6_BIT                        .equ 0x06
PTEPE_PTEPE7_MASK                       .equ 0x80
PTEPE_PTEPE7_BIT                        .equ 0x07

;*********************************************
;  Port E Slew Rate Enable Register
;*********************************************
PTESE                                   .equ 0xFFFF9851 ;  Port E Slew Rate Enable Register
PTESE_PTESE0_MASK                       .equ 0x01
PTESE_PTESE0_BIT                        .equ 0x00
PTESE_PTESE1_MASK                       .equ 0x02
PTESE_PTESE1_BIT                        .equ 0x01
PTESE_PTESE2_MASK                       .equ 0x04
PTESE_PTESE2_BIT                        .equ 0x02
PTESE_PTESE3_MASK                       .equ 0x08
PTESE_PTESE3_BIT                        .equ 0x03
PTESE_PTESE4_MASK                       .equ 0x10
PTESE_PTESE4_BIT                        .equ 0x04
PTESE_PTESE5_MASK                       .equ 0x20
PTESE_PTESE5_BIT                        .equ 0x05
PTESE_PTESE6_MASK                       .equ 0x40
PTESE_PTESE6_BIT                        .equ 0x06
PTESE_PTESE7_MASK                       .equ 0x80
PTESE_PTESE7_BIT                        .equ 0x07

;*********************************************
;  Port E Drive Strength Selection Register
;*********************************************
PTEDS                                   .equ 0xFFFF9852 ;  Port E Drive Strength Selection Register
PTEDS_PTEDS0_MASK                       .equ 0x01
PTEDS_PTEDS0_BIT                        .equ 0x00
PTEDS_PTEDS1_MASK                       .equ 0x02
PTEDS_PTEDS1_BIT                        .equ 0x01
PTEDS_PTEDS2_MASK                       .equ 0x04
PTEDS_PTEDS2_BIT                        .equ 0x02
PTEDS_PTEDS3_MASK                       .equ 0x08
PTEDS_PTEDS3_BIT                        .equ 0x03
PTEDS_PTEDS4_MASK                       .equ 0x10
PTEDS_PTEDS4_BIT                        .equ 0x04
PTEDS_PTEDS5_MASK                       .equ 0x20
PTEDS_PTEDS5_BIT                        .equ 0x05
PTEDS_PTEDS6_MASK                       .equ 0x40
PTEDS_PTEDS6_BIT                        .equ 0x06
PTEDS_PTEDS7_MASK                       .equ 0x80
PTEDS_PTEDS7_BIT                        .equ 0x07

;*********************************************
;  Port E Input Filter Enable Register
;*********************************************
PTEIFE                                  .equ 0xFFFF9853 ;  Port E Input Filter Enable Register
PTEIFE_PTEIFE0_MASK                     .equ 0x01
PTEIFE_PTEIFE0_BIT                      .equ 0x00
PTEIFE_PTEIFE1_MASK                     .equ 0x02
PTEIFE_PTEIFE1_BIT                      .equ 0x01
PTEIFE_PTEIFE2_MASK                     .equ 0x04
PTEIFE_PTEIFE2_BIT                      .equ 0x02
PTEIFE_PTEIFE3_MASK                     .equ 0x08
PTEIFE_PTEIFE3_BIT                      .equ 0x03
PTEIFE_PTEIFE4_MASK                     .equ 0x10
PTEIFE_PTEIFE4_BIT                      .equ 0x04
PTEIFE_PTEIFE5_MASK                     .equ 0x20
PTEIFE_PTEIFE5_BIT                      .equ 0x05
PTEIFE_PTEIFE6_MASK                     .equ 0x40
PTEIFE_PTEIFE6_BIT                      .equ 0x06
PTEIFE_PTEIFE7_MASK                     .equ 0x80
PTEIFE_PTEIFE7_BIT                      .equ 0x07

;*********************************************
;  Port F Pull Enable Register
;*********************************************
PTFPE                                   .equ 0xFFFF9854 ;  Port F Pull Enable Register
PTFPE_PTFPE0_MASK                       .equ 0x01
PTFPE_PTFPE0_BIT                        .equ 0x00
PTFPE_PTFPE1_MASK                       .equ 0x02
PTFPE_PTFPE1_BIT                        .equ 0x01
PTFPE_PTFPE2_MASK                       .equ 0x04
PTFPE_PTFPE2_BIT                        .equ 0x02
PTFPE_PTFPE3_MASK                       .equ 0x08
PTFPE_PTFPE3_BIT                        .equ 0x03
PTFPE_PTFPE4_MASK                       .equ 0x10
PTFPE_PTFPE4_BIT                        .equ 0x04
PTFPE_PTFPE5_MASK                       .equ 0x20
PTFPE_PTFPE5_BIT                        .equ 0x05
PTFPE_PTFPE6_MASK                       .equ 0x40
PTFPE_PTFPE6_BIT                        .equ 0x06
PTFPE_PTFPE7_MASK                       .equ 0x80
PTFPE_PTFPE7_BIT                        .equ 0x07

;*********************************************
;  Port F Slew Rate Enable Register
;*********************************************
PTFSE                                   .equ 0xFFFF9855 ;  Port F Slew Rate Enable Register
PTFSE_PTFSE0_MASK                       .equ 0x01
PTFSE_PTFSE0_BIT                        .equ 0x00
PTFSE_PTFSE1_MASK                       .equ 0x02
PTFSE_PTFSE1_BIT                        .equ 0x01
PTFSE_PTFSE2_MASK                       .equ 0x04
PTFSE_PTFSE2_BIT                        .equ 0x02
PTFSE_PTFSE3_MASK                       .equ 0x08
PTFSE_PTFSE3_BIT                        .equ 0x03
PTFSE_PTFSE4_MASK                       .equ 0x10
PTFSE_PTFSE4_BIT                        .equ 0x04
PTFSE_PTFSE5_MASK                       .equ 0x20
PTFSE_PTFSE5_BIT                        .equ 0x05
PTFSE_PTFSE6_MASK                       .equ 0x40
PTFSE_PTFSE6_BIT                        .equ 0x06
PTFSE_PTFSE7_MASK                       .equ 0x80
PTFSE_PTFSE7_BIT                        .equ 0x07

;*********************************************
;  Port F Drive Strength Selection Register
;*********************************************
PTFDS                                   .equ 0xFFFF9856 ;  Port F Drive Strength Selection Register
PTFDS_PTFDS0_MASK                       .equ 0x01
PTFDS_PTFDS0_BIT                        .equ 0x00
PTFDS_PTFDS1_MASK                       .equ 0x02
PTFDS_PTFDS1_BIT                        .equ 0x01
PTFDS_PTFDS2_MASK                       .equ 0x04
PTFDS_PTFDS2_BIT                        .equ 0x02
PTFDS_PTFDS3_MASK                       .equ 0x08
PTFDS_PTFDS3_BIT                        .equ 0x03
PTFDS_PTFDS4_MASK                       .equ 0x10
PTFDS_PTFDS4_BIT                        .equ 0x04
PTFDS_PTFDS5_MASK                       .equ 0x20
PTFDS_PTFDS5_BIT                        .equ 0x05
PTFDS_PTFDS6_MASK                       .equ 0x40
PTFDS_PTFDS6_BIT                        .equ 0x06
PTFDS_PTFDS7_MASK                       .equ 0x80
PTFDS_PTFDS7_BIT                        .equ 0x07

;*********************************************
;  Port F Input Filter Enable Register
;*********************************************
PTFIFE                                  .equ 0xFFFF9857 ;  Port F Input Filter Enable Register
PTFIFE_PTFIFE0_MASK                     .equ 0x01
PTFIFE_PTFIFE0_BIT                      .equ 0x00
PTFIFE_PTFIFE1_MASK                     .equ 0x02
PTFIFE_PTFIFE1_BIT                      .equ 0x01
PTFIFE_PTFIFE2_MASK                     .equ 0x04
PTFIFE_PTFIFE2_BIT                      .equ 0x02
PTFIFE_PTFIFE3_MASK                     .equ 0x08
PTFIFE_PTFIFE3_BIT                      .equ 0x03
PTFIFE_PTFIFE4_MASK                     .equ 0x10
PTFIFE_PTFIFE4_BIT                      .equ 0x04
PTFIFE_PTFIFE5_MASK                     .equ 0x20
PTFIFE_PTFIFE5_BIT                      .equ 0x05
PTFIFE_PTFIFE6_MASK                     .equ 0x40
PTFIFE_PTFIFE6_BIT                      .equ 0x06
PTFIFE_PTFIFE7_MASK                     .equ 0x80
PTFIFE_PTFIFE7_BIT                      .equ 0x07

;*********************************************
;  Port G Pull Enable Register
;*********************************************
PTGPE                                   .equ 0xFFFF9858 ;  Port G Pull Enable Register
PTGPE_PTGPE0_MASK                       .equ 0x01
PTGPE_PTGPE0_BIT                        .equ 0x00
PTGPE_PTGPE1_MASK                       .equ 0x02
PTGPE_PTGPE1_BIT                        .equ 0x01
PTGPE_PTGPE2_MASK                       .equ 0x04
PTGPE_PTGPE2_BIT                        .equ 0x02
PTGPE_PTGPE3_MASK                       .equ 0x08
PTGPE_PTGPE3_BIT                        .equ 0x03
PTGPE_PTGPE4_MASK                       .equ 0x10
PTGPE_PTGPE4_BIT                        .equ 0x04
PTGPE_PTGPE5_MASK                       .equ 0x20
PTGPE_PTGPE5_BIT                        .equ 0x05
PTGPE_PTGPE6_MASK                       .equ 0x40
PTGPE_PTGPE6_BIT                        .equ 0x06
PTGPE_PTGPE7_MASK                       .equ 0x80
PTGPE_PTGPE7_BIT                        .equ 0x07

;*********************************************
;  Port G Slew Rate Enable Register
;*********************************************
PTGSE                                   .equ 0xFFFF9859 ;  Port G Slew Rate Enable Register
PTGSE_PTGSE0_MASK                       .equ 0x01
PTGSE_PTGSE0_BIT                        .equ 0x00
PTGSE_PTGSE1_MASK                       .equ 0x02
PTGSE_PTGSE1_BIT                        .equ 0x01
PTGSE_PTGSE2_MASK                       .equ 0x04
PTGSE_PTGSE2_BIT                        .equ 0x02
PTGSE_PTGSE3_MASK                       .equ 0x08
PTGSE_PTGSE3_BIT                        .equ 0x03
PTGSE_PTGSE4_MASK                       .equ 0x10
PTGSE_PTGSE4_BIT                        .equ 0x04
PTGSE_PTGSE5_MASK                       .equ 0x20
PTGSE_PTGSE5_BIT                        .equ 0x05
PTGSE_PTGSE6_MASK                       .equ 0x40
PTGSE_PTGSE6_BIT                        .equ 0x06
PTGSE_PTGSE7_MASK                       .equ 0x80
PTGSE_PTGSE7_BIT                        .equ 0x07

;*********************************************
;  Port G Drive Strength Selection Register
;*********************************************
PTGDS                                   .equ 0xFFFF985A ;  Port G Drive Strength Selection Register
PTGDS_PTGDS0_MASK                       .equ 0x01
PTGDS_PTGDS0_BIT                        .equ 0x00
PTGDS_PTGDS1_MASK                       .equ 0x02
PTGDS_PTGDS1_BIT                        .equ 0x01
PTGDS_PTGDS2_MASK                       .equ 0x04
PTGDS_PTGDS2_BIT                        .equ 0x02
PTGDS_PTGDS3_MASK                       .equ 0x08
PTGDS_PTGDS3_BIT                        .equ 0x03
PTGDS_PTGDS4_MASK                       .equ 0x10
PTGDS_PTGDS4_BIT                        .equ 0x04
PTGDS_PTGDS5_MASK                       .equ 0x20
PTGDS_PTGDS5_BIT                        .equ 0x05
PTGDS_PTGDS6_MASK                       .equ 0x40
PTGDS_PTGDS6_BIT                        .equ 0x06
PTGDS_PTGDS7_MASK                       .equ 0x80
PTGDS_PTGDS7_BIT                        .equ 0x07

;*********************************************
;  Port G Input Filter Enable Register
;*********************************************
PTGIFE                                  .equ 0xFFFF985B ;  Port G Input Filter Enable Register
PTGIFE_PTGIFE0_MASK                     .equ 0x01
PTGIFE_PTGIFE0_BIT                      .equ 0x00
PTGIFE_PTGIFE1_MASK                     .equ 0x02
PTGIFE_PTGIFE1_BIT                      .equ 0x01
PTGIFE_PTGIFE2_MASK                     .equ 0x04
PTGIFE_PTGIFE2_BIT                      .equ 0x02
PTGIFE_PTGIFE3_MASK                     .equ 0x08
PTGIFE_PTGIFE3_BIT                      .equ 0x03
PTGIFE_PTGIFE4_MASK                     .equ 0x10
PTGIFE_PTGIFE4_BIT                      .equ 0x04
PTGIFE_PTGIFE5_MASK                     .equ 0x20
PTGIFE_PTGIFE5_BIT                      .equ 0x05
PTGIFE_PTGIFE6_MASK                     .equ 0x40
PTGIFE_PTGIFE6_BIT                      .equ 0x06
PTGIFE_PTGIFE7_MASK                     .equ 0x80
PTGIFE_PTGIFE7_BIT                      .equ 0x07

;*********************************************
;  Port H Pull Enable Register
;*********************************************
PTHPE                                   .equ 0xFFFF985C ;  Port H Pull Enable Register
PTHPE_PTHPE0_MASK                       .equ 0x01
PTHPE_PTHPE0_BIT                        .equ 0x00
PTHPE_PTHPE1_MASK                       .equ 0x02
PTHPE_PTHPE1_BIT                        .equ 0x01
PTHPE_PTHPE2_MASK                       .equ 0x04
PTHPE_PTHPE2_BIT                        .equ 0x02
PTHPE_PTHPE3_MASK                       .equ 0x08
PTHPE_PTHPE3_BIT                        .equ 0x03
PTHPE_PTHPE4_MASK                       .equ 0x10
PTHPE_PTHPE4_BIT                        .equ 0x04
PTHPE_PTHPE_MASK                        .equ 0x1F

;*********************************************
;  Port H Slew Rate Enable Register
;*********************************************
PTHSE                                   .equ 0xFFFF985D ;  Port H Slew Rate Enable Register
PTHSE_PTHSE0_MASK                       .equ 0x01
PTHSE_PTHSE0_BIT                        .equ 0x00
PTHSE_PTHSE1_MASK                       .equ 0x02
PTHSE_PTHSE1_BIT                        .equ 0x01
PTHSE_PTHSE2_MASK                       .equ 0x04
PTHSE_PTHSE2_BIT                        .equ 0x02
PTHSE_PTHSE3_MASK                       .equ 0x08
PTHSE_PTHSE3_BIT                        .equ 0x03
PTHSE_PTHSE4_MASK                       .equ 0x10
PTHSE_PTHSE4_BIT                        .equ 0x04
PTHSE_PTHSE_MASK                        .equ 0x1F

;*********************************************
;  Port H Drive Strength Selection Register
;*********************************************
PTHDS                                   .equ 0xFFFF985E ;  Port H Drive Strength Selection Register
PTHDS_PTHDS0_MASK                       .equ 0x01
PTHDS_PTHDS0_BIT                        .equ 0x00
PTHDS_PTHDS1_MASK                       .equ 0x02
PTHDS_PTHDS1_BIT                        .equ 0x01
PTHDS_PTHDS2_MASK                       .equ 0x04
PTHDS_PTHDS2_BIT                        .equ 0x02
PTHDS_PTHDS3_MASK                       .equ 0x08
PTHDS_PTHDS3_BIT                        .equ 0x03
PTHDS_PTHDS4_MASK                       .equ 0x10
PTHDS_PTHDS4_BIT                        .equ 0x04
PTHDS_PTHDS_MASK                        .equ 0x1F

;*********************************************
;  Port H Input Filter Enable Register
;*********************************************
PTHIFE                                  .equ 0xFFFF985F ;  Port H Input Filter Enable Register
PTHIFE_PTHIFE0_MASK                     .equ 0x01
PTHIFE_PTHIFE0_BIT                      .equ 0x00
PTHIFE_PTHIFE1_MASK                     .equ 0x02
PTHIFE_PTHIFE1_BIT                      .equ 0x01
PTHIFE_PTHIFE2_MASK                     .equ 0x04
PTHIFE_PTHIFE2_BIT                      .equ 0x02
PTHIFE_PTHIFE3_MASK                     .equ 0x08
PTHIFE_PTHIFE3_BIT                      .equ 0x03
PTHIFE_PTHIFE4_MASK                     .equ 0x10
PTHIFE_PTHIFE4_BIT                      .equ 0x04
PTHIFE_PTHIFE_MASK                      .equ 0x1F

;*********************************************
;  Port J Pull Enable Register
;*********************************************
PTJPE                                   .equ 0xFFFF9860 ;  Port J Pull Enable Register
PTJPE_PTJPE0_MASK                       .equ 0x01
PTJPE_PTJPE0_BIT                        .equ 0x00
PTJPE_PTJPE1_MASK                       .equ 0x02
PTJPE_PTJPE1_BIT                        .equ 0x01
PTJPE_PTJPE2_MASK                       .equ 0x04
PTJPE_PTJPE2_BIT                        .equ 0x02
PTJPE_PTJPE3_MASK                       .equ 0x08
PTJPE_PTJPE3_BIT                        .equ 0x03
PTJPE_PTJPE4_MASK                       .equ 0x10
PTJPE_PTJPE4_BIT                        .equ 0x04
PTJPE_PTJPE_MASK                        .equ 0x1F

;*********************************************
;  Port J Slew Rate Enable Register
;*********************************************
PTJSE                                   .equ 0xFFFF9861 ;  Port J Slew Rate Enable Register
PTJSE_PTJSE0_MASK                       .equ 0x01
PTJSE_PTJSE0_BIT                        .equ 0x00
PTJSE_PTJSE1_MASK                       .equ 0x02
PTJSE_PTJSE1_BIT                        .equ 0x01
PTJSE_PTJSE2_MASK                       .equ 0x04
PTJSE_PTJSE2_BIT                        .equ 0x02
PTJSE_PTJSE3_MASK                       .equ 0x08
PTJSE_PTJSE3_BIT                        .equ 0x03
PTJSE_PTJSE4_MASK                       .equ 0x10
PTJSE_PTJSE4_BIT                        .equ 0x04
PTJSE_PTJSE_MASK                        .equ 0x1F

;*********************************************
;  Port J Drive Strength Selection Register
;*********************************************
PTJDS                                   .equ 0xFFFF9862 ;  Port J Drive Strength Selection Register
PTJDS_PTJDS0_MASK                       .equ 0x01
PTJDS_PTJDS0_BIT                        .equ 0x00
PTJDS_PTJDS1_MASK                       .equ 0x02
PTJDS_PTJDS1_BIT                        .equ 0x01
PTJDS_PTJDS2_MASK                       .equ 0x04
PTJDS_PTJDS2_BIT                        .equ 0x02
PTJDS_PTJDS3_MASK                       .equ 0x08
PTJDS_PTJDS3_BIT                        .equ 0x03
PTJDS_PTJDS4_MASK                       .equ 0x10
PTJDS_PTJDS4_BIT                        .equ 0x04
PTJDS_PTJDS_MASK                        .equ 0x1F

;*********************************************
;  Port J Input Filter Enable Register
;*********************************************
PTJIFE                                  .equ 0xFFFF9863 ;  Port J Input Filter Enable Register
PTJIFE_PTJIFE0_MASK                     .equ 0x01
PTJIFE_PTJIFE0_BIT                      .equ 0x00
PTJIFE_PTJIFE1_MASK                     .equ 0x02
PTJIFE_PTJIFE1_BIT                      .equ 0x01
PTJIFE_PTJIFE2_MASK                     .equ 0x04
PTJIFE_PTJIFE2_BIT                      .equ 0x02
PTJIFE_PTJIFE3_MASK                     .equ 0x08
PTJIFE_PTJIFE3_BIT                      .equ 0x03
PTJIFE_PTJIFE4_MASK                     .equ 0x10
PTJIFE_PTJIFE4_BIT                      .equ 0x04
PTJIFE_PTJIFE_MASK                      .equ 0x1F

;*********************************************
;  Carrier Generator Data Register 1
;*********************************************
CMTCG1                                  .equ 0xFFFF9868 ;  Carrier Generator Data Register 1
CMTCG1_PL0_MASK                         .equ 0x01
CMTCG1_PL0_BIT                          .equ 0x00
CMTCG1_PL1_MASK                         .equ 0x02
CMTCG1_PL1_BIT                          .equ 0x01
CMTCG1_PL2_MASK                         .equ 0x04
CMTCG1_PL2_BIT                          .equ 0x02
CMTCG1_PL3_MASK                         .equ 0x08
CMTCG1_PL3_BIT                          .equ 0x03
CMTCG1_PL4_MASK                         .equ 0x10
CMTCG1_PL4_BIT                          .equ 0x04
CMTCG1_PL5_MASK                         .equ 0x20
CMTCG1_PL5_BIT                          .equ 0x05
CMTCG1_PL6_MASK                         .equ 0x40
CMTCG1_PL6_BIT                          .equ 0x06
CMTCG1_PL7_MASK                         .equ 0x80
CMTCG1_PL7_BIT                          .equ 0x07
CMTCG1_PH0_MASK                         .equ 0x100
CMTCG1_PH0_BIT                          .equ 0x08
CMTCG1_PH1_MASK                         .equ 0x200
CMTCG1_PH1_BIT                          .equ 0x09
CMTCG1_PH2_MASK                         .equ 0x400
CMTCG1_PH2_BIT                          .equ 0x0A
CMTCG1_PH3_MASK                         .equ 0x800
CMTCG1_PH3_BIT                          .equ 0x0B
CMTCG1_PH4_MASK                         .equ 0x1000
CMTCG1_PH4_BIT                          .equ 0x0C
CMTCG1_PH5_MASK                         .equ 0x2000
CMTCG1_PH5_BIT                          .equ 0x0D
CMTCG1_PH6_MASK                         .equ 0x4000
CMTCG1_PH6_BIT                          .equ 0x0E
CMTCG1_PH7_MASK                         .equ 0x8000
CMTCG1_PH7_BIT                          .equ 0x0F
CMTCG1_PL_MASK                          .equ 0xFF
CMTCG1_PH_MASK                          .equ 0xFF00

;*********************************************
;  Carrier Generator Data Register 2
;*********************************************
CMTCG2                                  .equ 0xFFFF986A ;  Carrier Generator Data Register 2
CMTCG2_SL0_MASK                         .equ 0x01
CMTCG2_SL0_BIT                          .equ 0x00
CMTCG2_SL1_MASK                         .equ 0x02
CMTCG2_SL1_BIT                          .equ 0x01
CMTCG2_SL2_MASK                         .equ 0x04
CMTCG2_SL2_BIT                          .equ 0x02
CMTCG2_SL3_MASK                         .equ 0x08
CMTCG2_SL3_BIT                          .equ 0x03
CMTCG2_SL4_MASK                         .equ 0x10
CMTCG2_SL4_BIT                          .equ 0x04
CMTCG2_SL5_MASK                         .equ 0x20
CMTCG2_SL5_BIT                          .equ 0x05
CMTCG2_SL6_MASK                         .equ 0x40
CMTCG2_SL6_BIT                          .equ 0x06
CMTCG2_SL7_MASK                         .equ 0x80
CMTCG2_SL7_BIT                          .equ 0x07
CMTCG2_SH0_MASK                         .equ 0x100
CMTCG2_SH0_BIT                          .equ 0x08
CMTCG2_SH1_MASK                         .equ 0x200
CMTCG2_SH1_BIT                          .equ 0x09
CMTCG2_SH2_MASK                         .equ 0x400
CMTCG2_SH2_BIT                          .equ 0x0A
CMTCG2_SH3_MASK                         .equ 0x800
CMTCG2_SH3_BIT                          .equ 0x0B
CMTCG2_SH4_MASK                         .equ 0x1000
CMTCG2_SH4_BIT                          .equ 0x0C
CMTCG2_SH5_MASK                         .equ 0x2000
CMTCG2_SH5_BIT                          .equ 0x0D
CMTCG2_SH6_MASK                         .equ 0x4000
CMTCG2_SH6_BIT                          .equ 0x0E
CMTCG2_SH7_MASK                         .equ 0x8000
CMTCG2_SH7_BIT                          .equ 0x0F
CMTCG2_SL_MASK                          .equ 0xFF
CMTCG2_SH_MASK                          .equ 0xFF00

;*********************************************
;  CMT Output Control Register
;*********************************************
CMTOC                                   .equ 0xFFFF986C ;  CMT Output Control Register
CMTOC_IROPEN_MASK                       .equ 0x20
CMTOC_IROPEN_BIT                        .equ 0x05
CMTOC_CMTPOL_MASK                       .equ 0x40
CMTOC_CMTPOL_BIT                        .equ 0x06
CMTOC_IROL_MASK                         .equ 0x80
CMTOC_IROL_BIT                          .equ 0x07

;*********************************************
;  CMT Modulator Status and Control Register
;*********************************************
CMTMSC                                  .equ 0xFFFF986D ;  CMT Modulator Status and Control Register
CMTMSC_MCGEN_MASK                       .equ 0x01
CMTMSC_MCGEN_BIT                        .equ 0x00
CMTMSC_EOCIE_MASK                       .equ 0x02
CMTMSC_EOCIE_BIT                        .equ 0x01
CMTMSC_FSK_MASK                         .equ 0x04
CMTMSC_FSK_BIT                          .equ 0x02
CMTMSC_BASE_MASK                        .equ 0x08
CMTMSC_BASE_BIT                         .equ 0x03
CMTMSC_EXSPC_MASK                       .equ 0x10
CMTMSC_EXSPC_BIT                        .equ 0x04
CMTMSC_CMTDIV0_MASK                     .equ 0x20
CMTMSC_CMTDIV0_BIT                      .equ 0x05
CMTMSC_CMTDIV1_MASK                     .equ 0x40
CMTMSC_CMTDIV1_BIT                      .equ 0x06
CMTMSC_EOCF_MASK                        .equ 0x80
CMTMSC_EOCF_BIT                         .equ 0x07
CMTMSC_CMTDIV_MASK                      .equ 0x60

;*********************************************
;  CMT Modulator Data Register 12
;*********************************************
CMTCMD2_MB0_MASK                        .equ 0x01
CMTCMD2_MB0_BIT                         .equ 0x00
CMTCMD2_MB1_MASK                        .equ 0x02
CMTCMD2_MB1_BIT                         .equ 0x01
CMTCMD2_MB2_MASK                        .equ 0x04
CMTCMD2_MB2_BIT                         .equ 0x02
CMTCMD2_MB3_MASK                        .equ 0x08
CMTCMD2_MB3_BIT                         .equ 0x03
CMTCMD2_MB4_MASK                        .equ 0x10
CMTCMD2_MB4_BIT                         .equ 0x04
CMTCMD2_MB5_MASK                        .equ 0x20
CMTCMD2_MB5_BIT                         .equ 0x05
CMTCMD2_MB6_MASK                        .equ 0x40
CMTCMD2_MB6_BIT                         .equ 0x06
CMTCMD2_MB7_MASK                        .equ 0x80
CMTCMD2_MB7_BIT                         .equ 0x07
CMTCMD12                                .equ 0xFFFF986E ;  CMT Modulator Data Register 12
CMTCMD12_MB0_MASK                       .equ 0x01
CMTCMD12_MB0_BIT                        .equ 0x00
CMTCMD12_MB1_MASK                       .equ 0x02
CMTCMD12_MB1_BIT                        .equ 0x01
CMTCMD12_MB2_MASK                       .equ 0x04
CMTCMD12_MB2_BIT                        .equ 0x02
CMTCMD12_MB3_MASK                       .equ 0x08
CMTCMD12_MB3_BIT                        .equ 0x03
CMTCMD12_MB4_MASK                       .equ 0x10
CMTCMD12_MB4_BIT                        .equ 0x04
CMTCMD12_MB5_MASK                       .equ 0x20
CMTCMD12_MB5_BIT                        .equ 0x05
CMTCMD12_MB6_MASK                       .equ 0x40
CMTCMD12_MB6_BIT                        .equ 0x06
CMTCMD12_MB7_MASK                       .equ 0x80
CMTCMD12_MB7_BIT                        .equ 0x07
CMTCMD12_MB8_MASK                       .equ 0x100
CMTCMD12_MB8_BIT                        .equ 0x08
CMTCMD12_MB9_MASK                       .equ 0x200
CMTCMD12_MB9_BIT                        .equ 0x09
CMTCMD12_MB10_MASK                      .equ 0x400
CMTCMD12_MB10_BIT                       .equ 0x0A
CMTCMD12_MB11_MASK                      .equ 0x800
CMTCMD12_MB11_BIT                       .equ 0x0B
CMTCMD12_MB12_MASK                      .equ 0x1000
CMTCMD12_MB12_BIT                       .equ 0x0C
CMTCMD12_MB13_MASK                      .equ 0x2000
CMTCMD12_MB13_BIT                       .equ 0x0D
CMTCMD12_MB14_MASK                      .equ 0x4000
CMTCMD12_MB14_BIT                       .equ 0x0E
CMTCMD12_MB15_MASK                      .equ 0x8000
CMTCMD12_MB15_BIT                       .equ 0x0F

;*********************************************
;  CMT Modulator Data Register 34
;*********************************************
CMTCMD4_SB0_MASK                        .equ 0x01
CMTCMD4_SB0_BIT                         .equ 0x00
CMTCMD4_SB1_MASK                        .equ 0x02
CMTCMD4_SB1_BIT                         .equ 0x01
CMTCMD4_SB2_MASK                        .equ 0x04
CMTCMD4_SB2_BIT                         .equ 0x02
CMTCMD4_SB3_MASK                        .equ 0x08
CMTCMD4_SB3_BIT                         .equ 0x03
CMTCMD4_SB4_MASK                        .equ 0x10
CMTCMD4_SB4_BIT                         .equ 0x04
CMTCMD4_SB5_MASK                        .equ 0x20
CMTCMD4_SB5_BIT                         .equ 0x05
CMTCMD4_SB6_MASK                        .equ 0x40
CMTCMD4_SB6_BIT                         .equ 0x06
CMTCMD4_SB7_MASK                        .equ 0x80
CMTCMD4_SB7_BIT                         .equ 0x07
CMTCMD34                                .equ 0xFFFF9870 ;  CMT Modulator Data Register 34
CMTCMD34_SB0_MASK                       .equ 0x01
CMTCMD34_SB0_BIT                        .equ 0x00
CMTCMD34_SB1_MASK                       .equ 0x02
CMTCMD34_SB1_BIT                        .equ 0x01
CMTCMD34_SB2_MASK                       .equ 0x04
CMTCMD34_SB2_BIT                        .equ 0x02
CMTCMD34_SB3_MASK                       .equ 0x08
CMTCMD34_SB3_BIT                        .equ 0x03
CMTCMD34_SB4_MASK                       .equ 0x10
CMTCMD34_SB4_BIT                        .equ 0x04
CMTCMD34_SB5_MASK                       .equ 0x20
CMTCMD34_SB5_BIT                        .equ 0x05
CMTCMD34_SB6_MASK                       .equ 0x40
CMTCMD34_SB6_BIT                        .equ 0x06
CMTCMD34_SB7_MASK                       .equ 0x80
CMTCMD34_SB7_BIT                        .equ 0x07
CMTCMD34_SB8_MASK                       .equ 0x100
CMTCMD34_SB8_BIT                        .equ 0x08
CMTCMD34_SB9_MASK                       .equ 0x200
CMTCMD34_SB9_BIT                        .equ 0x09
CMTCMD34_SB10_MASK                      .equ 0x400
CMTCMD34_SB10_BIT                       .equ 0x0A
CMTCMD34_SB11_MASK                      .equ 0x800
CMTCMD34_SB11_BIT                       .equ 0x0B
CMTCMD34_SB12_MASK                      .equ 0x1000
CMTCMD34_SB12_BIT                       .equ 0x0C
CMTCMD34_SB13_MASK                      .equ 0x2000
CMTCMD34_SB13_BIT                       .equ 0x0D
CMTCMD34_SB14_MASK                      .equ 0x4000
CMTCMD34_SB14_BIT                       .equ 0x0E
CMTCMD34_SB15_MASK                      .equ 0x8000
CMTCMD34_SB15_BIT                       .equ 0x0F

;*********************************************
;  Port H Data Register
;*********************************************
PTHD                                    .equ 0xFFFF9874 ;  Port H Data Register
PTHD_PTHD0_MASK                         .equ 0x01
PTHD_PTHD0_BIT                          .equ 0x00
PTHD_PTHD1_MASK                         .equ 0x02
PTHD_PTHD1_BIT                          .equ 0x01
PTHD_PTHD2_MASK                         .equ 0x04
PTHD_PTHD2_BIT                          .equ 0x02
PTHD_PTHD3_MASK                         .equ 0x08
PTHD_PTHD3_BIT                          .equ 0x03
PTHD_PTHD4_MASK                         .equ 0x10
PTHD_PTHD4_BIT                          .equ 0x04
PTHD_PTHD_MASK                          .equ 0x1F

;*********************************************
;  Port H Data Direction Register
;*********************************************
PTHDD                                   .equ 0xFFFF9875 ;  Port H Data Direction Register
PTHDD_PTHDD0_MASK                       .equ 0x01
PTHDD_PTHDD0_BIT                        .equ 0x00
PTHDD_PTHDD1_MASK                       .equ 0x02
PTHDD_PTHDD1_BIT                        .equ 0x01
PTHDD_PTHDD2_MASK                       .equ 0x04
PTHDD_PTHDD2_BIT                        .equ 0x02
PTHDD_PTHDD3_MASK                       .equ 0x08
PTHDD_PTHDD3_BIT                        .equ 0x03
PTHDD_PTHDD4_MASK                       .equ 0x10
PTHDD_PTHDD4_BIT                        .equ 0x04
PTHDD_PTHDD_MASK                        .equ 0x1F

;*********************************************
;  Port J Data Register
;*********************************************
PTJD                                    .equ 0xFFFF9876 ;  Port J Data Register
PTJD_PTJD0_MASK                         .equ 0x01
PTJD_PTJD0_BIT                          .equ 0x00
PTJD_PTJD1_MASK                         .equ 0x02
PTJD_PTJD1_BIT                          .equ 0x01
PTJD_PTJD2_MASK                         .equ 0x04
PTJD_PTJD2_BIT                          .equ 0x02
PTJD_PTJD3_MASK                         .equ 0x08
PTJD_PTJD3_BIT                          .equ 0x03
PTJD_PTJD4_MASK                         .equ 0x10
PTJD_PTJD4_BIT                          .equ 0x04
PTJD_PTJD_MASK                          .equ 0x1F

;*********************************************
;  Port J Data Direction Register
;*********************************************
PTJDD                                   .equ 0xFFFF9877 ;  Port J Data Direction Register
PTJDD_PTJDD0_MASK                       .equ 0x01
PTJDD_PTJDD0_BIT                        .equ 0x00
PTJDD_PTJDD1_MASK                       .equ 0x02
PTJDD_PTJDD1_BIT                        .equ 0x01
PTJDD_PTJDD2_MASK                       .equ 0x04
PTJDD_PTJDD2_BIT                        .equ 0x02
PTJDD_PTJDD3_MASK                       .equ 0x08
PTJDD_PTJDD3_BIT                        .equ 0x03
PTJDD_PTJDD4_MASK                       .equ 0x10
PTJDD_PTJDD4_BIT                        .equ 0x04
PTJDD_PTJDD_MASK                        .equ 0x1F

;*********************************************
;  MSCAN Control 0 Register
;*********************************************
CANCTL0                                 .equ 0xFFFF9880 ;  MSCAN Control 0 Register
CANCTL0_INITRQ_MASK                     .equ 0x01
CANCTL0_INITRQ_BIT                      .equ 0x00
CANCTL0_SLPRQ_MASK                      .equ 0x02
CANCTL0_SLPRQ_BIT                       .equ 0x01
CANCTL0_WUPE_MASK                       .equ 0x04
CANCTL0_WUPE_BIT                        .equ 0x02
CANCTL0_TIME_MASK                       .equ 0x08
CANCTL0_TIME_BIT                        .equ 0x03
CANCTL0_SYNCH_MASK                      .equ 0x10
CANCTL0_SYNCH_BIT                       .equ 0x04
CANCTL0_CSWAI_MASK                      .equ 0x20
CANCTL0_CSWAI_BIT                       .equ 0x05
CANCTL0_RXACT_MASK                      .equ 0x40
CANCTL0_RXACT_BIT                       .equ 0x06
CANCTL0_RXFRM_MASK                      .equ 0x80
CANCTL0_RXFRM_BIT                       .equ 0x07

;*********************************************
;  MSCAN Control 1 Register
;*********************************************
CANCTL1                                 .equ 0xFFFF9881 ;  MSCAN Control 1 Register
CANCTL1_INITAK_MASK                     .equ 0x01
CANCTL1_INITAK_BIT                      .equ 0x00
CANCTL1_SLPAK_MASK                      .equ 0x02
CANCTL1_SLPAK_BIT                       .equ 0x01
CANCTL1_WUPM_MASK                       .equ 0x04
CANCTL1_WUPM_BIT                        .equ 0x02
CANCTL1_BORM_MASK                       .equ 0x08
CANCTL1_BORM_BIT                        .equ 0x03
CANCTL1_LISTEN_MASK                     .equ 0x10
CANCTL1_LISTEN_BIT                      .equ 0x04
CANCTL1_LOOPB_MASK                      .equ 0x20
CANCTL1_LOOPB_BIT                       .equ 0x05
CANCTL1_CLKSRC_MASK                     .equ 0x40
CANCTL1_CLKSRC_BIT                      .equ 0x06
CANCTL1_CANE_MASK                       .equ 0x80
CANCTL1_CANE_BIT                        .equ 0x07

;*********************************************
;  MSCAN Bus Timing Register 0
;*********************************************
CANBTR0                                 .equ 0xFFFF9882 ;  MSCAN Bus Timing Register 0
CANBTR0_BRP0_MASK                       .equ 0x01
CANBTR0_BRP0_BIT                        .equ 0x00
CANBTR0_BRP1_MASK                       .equ 0x02
CANBTR0_BRP1_BIT                        .equ 0x01
CANBTR0_BRP2_MASK                       .equ 0x04
CANBTR0_BRP2_BIT                        .equ 0x02
CANBTR0_BRP3_MASK                       .equ 0x08
CANBTR0_BRP3_BIT                        .equ 0x03
CANBTR0_BRP4_MASK                       .equ 0x10
CANBTR0_BRP4_BIT                        .equ 0x04
CANBTR0_BRP5_MASK                       .equ 0x20
CANBTR0_BRP5_BIT                        .equ 0x05
CANBTR0_SJW0_MASK                       .equ 0x40
CANBTR0_SJW0_BIT                        .equ 0x06
CANBTR0_SJW1_MASK                       .equ 0x80
CANBTR0_SJW1_BIT                        .equ 0x07
CANBTR0_BRP_MASK                        .equ 0x3F
CANBTR0_SJW_MASK                        .equ 0xC0

;*********************************************
;  MSCAN Bus Timing Register 1
;*********************************************
CANBTR1                                 .equ 0xFFFF9883 ;  MSCAN Bus Timing Register 1
CANBTR1_TSEG10_MASK                     .equ 0x01
CANBTR1_TSEG10_BIT                      .equ 0x00
CANBTR1_TSEG11_MASK                     .equ 0x02
CANBTR1_TSEG11_BIT                      .equ 0x01
CANBTR1_TSEG12_MASK                     .equ 0x04
CANBTR1_TSEG12_BIT                      .equ 0x02
CANBTR1_TSEG13_MASK                     .equ 0x08
CANBTR1_TSEG13_BIT                      .equ 0x03
CANBTR1_TSEG20_MASK                     .equ 0x10
CANBTR1_TSEG20_BIT                      .equ 0x04
CANBTR1_TSEG21_MASK                     .equ 0x20
CANBTR1_TSEG21_BIT                      .equ 0x05
CANBTR1_TSEG22_MASK                     .equ 0x40
CANBTR1_TSEG22_BIT                      .equ 0x06
CANBTR1_SAMP_MASK                       .equ 0x80
CANBTR1_SAMP_BIT                        .equ 0x07
CANBTR1_TSEG_10_MASK                    .equ 0x0F
CANBTR1_TSEG_20_MASK                    .equ 0x70

;*********************************************
;  MSCAN Receiver Flag Register
;*********************************************
CANRFLG                                 .equ 0xFFFF9884 ;  MSCAN Receiver Flag Register
CANRFLG_RXF_MASK                        .equ 0x01
CANRFLG_RXF_BIT                         .equ 0x00
CANRFLG_OVRIF_MASK                      .equ 0x02
CANRFLG_OVRIF_BIT                       .equ 0x01
CANRFLG_TSTAT0_MASK                     .equ 0x04
CANRFLG_TSTAT0_BIT                      .equ 0x02
CANRFLG_TSTAT1_MASK                     .equ 0x08
CANRFLG_TSTAT1_BIT                      .equ 0x03
CANRFLG_RSTAT0_MASK                     .equ 0x10
CANRFLG_RSTAT0_BIT                      .equ 0x04
CANRFLG_RSTAT1_MASK                     .equ 0x20
CANRFLG_RSTAT1_BIT                      .equ 0x05
CANRFLG_CSCIF_MASK                      .equ 0x40
CANRFLG_CSCIF_BIT                       .equ 0x06
CANRFLG_WUPIF_MASK                      .equ 0x80
CANRFLG_WUPIF_BIT                       .equ 0x07
CANRFLG_TSTAT_MASK                      .equ 0x0C
CANRFLG_RSTAT_MASK                      .equ 0x30

;*********************************************
;  MSCAN Receiver Interrupt Enable Register
;*********************************************
CANRIER                                 .equ 0xFFFF9885 ;  MSCAN Receiver Interrupt Enable Register
CANRIER_RXFIE_MASK                      .equ 0x01
CANRIER_RXFIE_BIT                       .equ 0x00
CANRIER_OVRIE_MASK                      .equ 0x02
CANRIER_OVRIE_BIT                       .equ 0x01
CANRIER_TSTATE0_MASK                    .equ 0x04
CANRIER_TSTATE0_BIT                     .equ 0x02
CANRIER_TSTATE1_MASK                    .equ 0x08
CANRIER_TSTATE1_BIT                     .equ 0x03
CANRIER_RSTATE0_MASK                    .equ 0x10
CANRIER_RSTATE0_BIT                     .equ 0x04
CANRIER_RSTATE1_MASK                    .equ 0x20
CANRIER_RSTATE1_BIT                     .equ 0x05
CANRIER_CSCIE_MASK                      .equ 0x40
CANRIER_CSCIE_BIT                       .equ 0x06
CANRIER_WUPIE_MASK                      .equ 0x80
CANRIER_WUPIE_BIT                       .equ 0x07
CANRIER_TSTATE_MASK                     .equ 0x0C
CANRIER_RSTATE_MASK                     .equ 0x30

;*********************************************
;  MSCAN Transmitter Flag Register
;*********************************************
CANTFLG                                 .equ 0xFFFF9886 ;  MSCAN Transmitter Flag Register
CANTFLG_TXE0_MASK                       .equ 0x01
CANTFLG_TXE0_BIT                        .equ 0x00
CANTFLG_TXE1_MASK                       .equ 0x02
CANTFLG_TXE1_BIT                        .equ 0x01
CANTFLG_TXE2_MASK                       .equ 0x04
CANTFLG_TXE2_BIT                        .equ 0x02
CANTFLG_TXE_MASK                        .equ 0x07

;*********************************************
;  MSCAN Transmitter Interrupt Enable Register
;*********************************************
CANTIER                                 .equ 0xFFFF9887 ;  MSCAN Transmitter Interrupt Enable Register
CANTIER_TXEIE0_MASK                     .equ 0x01
CANTIER_TXEIE0_BIT                      .equ 0x00
CANTIER_TXEIE1_MASK                     .equ 0x02
CANTIER_TXEIE1_BIT                      .equ 0x01
CANTIER_TXEIE2_MASK                     .equ 0x04
CANTIER_TXEIE2_BIT                      .equ 0x02
CANTIER_TXEIE_MASK                      .equ 0x07

;*********************************************
;  MSCAN Transmitter Message Abort Request
;*********************************************
CANTARQ                                 .equ 0xFFFF9888 ;  MSCAN Transmitter Message Abort Request
CANTARQ_ABTRQ0_MASK                     .equ 0x01
CANTARQ_ABTRQ0_BIT                      .equ 0x00
CANTARQ_ABTRQ1_MASK                     .equ 0x02
CANTARQ_ABTRQ1_BIT                      .equ 0x01
CANTARQ_ABTRQ2_MASK                     .equ 0x04
CANTARQ_ABTRQ2_BIT                      .equ 0x02
CANTARQ_ABTRQ_MASK                      .equ 0x07

;*********************************************
;  MSCAN Transmitter Message Abort Acknowledge
;*********************************************
CANTAAK                                 .equ 0xFFFF9889 ;  MSCAN Transmitter Message Abort Acknowledge
CANTAAK_ABTAK0_MASK                     .equ 0x01
CANTAAK_ABTAK0_BIT                      .equ 0x00
CANTAAK_ABTAK1_MASK                     .equ 0x02
CANTAAK_ABTAK1_BIT                      .equ 0x01
CANTAAK_ABTAK2_MASK                     .equ 0x04
CANTAAK_ABTAK2_BIT                      .equ 0x02
CANTAAK_ABTAK_MASK                      .equ 0x07

;*********************************************
;  MSCAN Transmit Buffer Selection
;*********************************************
CANTBSEL                                .equ 0xFFFF988A ;  MSCAN Transmit Buffer Selection
CANTBSEL_TX0_MASK                       .equ 0x01
CANTBSEL_TX0_BIT                        .equ 0x00
CANTBSEL_TX1_MASK                       .equ 0x02
CANTBSEL_TX1_BIT                        .equ 0x01
CANTBSEL_TX2_MASK                       .equ 0x04
CANTBSEL_TX2_BIT                        .equ 0x02
CANTBSEL_TX_MASK                        .equ 0x07

;*********************************************
;  MSCAN Identifier Acceptance Control Register
;*********************************************
CANIDAC                                 .equ 0xFFFF988B ;  MSCAN Identifier Acceptance Control Register
CANIDAC_IDHIT0_MASK                     .equ 0x01
CANIDAC_IDHIT0_BIT                      .equ 0x00
CANIDAC_IDHIT1_MASK                     .equ 0x02
CANIDAC_IDHIT1_BIT                      .equ 0x01
CANIDAC_IDHIT2_MASK                     .equ 0x04
CANIDAC_IDHIT2_BIT                      .equ 0x02
CANIDAC_IDAM0_MASK                      .equ 0x10
CANIDAC_IDAM0_BIT                       .equ 0x04
CANIDAC_IDAM1_MASK                      .equ 0x20
CANIDAC_IDAM1_BIT                       .equ 0x05
CANIDAC_IDHIT_MASK                      .equ 0x07
CANIDAC_IDAM_MASK                       .equ 0x30

;*********************************************
;  MSCAN Miscellaneous Register
;*********************************************
CANMISC                                 .equ 0xFFFF988D ;  MSCAN Miscellaneous Register
CANMISC_BOHOLD_MASK                     .equ 0x01
CANMISC_BOHOLD_BIT                      .equ 0x00

;*********************************************
;  MSCAN Receive Error Counter Register
;*********************************************
CANRXERR                                .equ 0xFFFF988E ;  MSCAN Receive Error Counter Register
CANRXERR_RXERR0_MASK                    .equ 0x01
CANRXERR_RXERR0_BIT                     .equ 0x00
CANRXERR_RXERR1_MASK                    .equ 0x02
CANRXERR_RXERR1_BIT                     .equ 0x01
CANRXERR_RXERR2_MASK                    .equ 0x04
CANRXERR_RXERR2_BIT                     .equ 0x02
CANRXERR_RXERR3_MASK                    .equ 0x08
CANRXERR_RXERR3_BIT                     .equ 0x03
CANRXERR_RXERR4_MASK                    .equ 0x10
CANRXERR_RXERR4_BIT                     .equ 0x04
CANRXERR_RXERR5_MASK                    .equ 0x20
CANRXERR_RXERR5_BIT                     .equ 0x05
CANRXERR_RXERR6_MASK                    .equ 0x40
CANRXERR_RXERR6_BIT                     .equ 0x06
CANRXERR_RXERR7_MASK                    .equ 0x80
CANRXERR_RXERR7_BIT                     .equ 0x07

;*********************************************
;  MSCAN Transmit Error Counter Register
;*********************************************
CANTXERR                                .equ 0xFFFF988F ;  MSCAN Transmit Error Counter Register
CANTXERR_TXERR0_MASK                    .equ 0x01
CANTXERR_TXERR0_BIT                     .equ 0x00
CANTXERR_TXERR1_MASK                    .equ 0x02
CANTXERR_TXERR1_BIT                     .equ 0x01
CANTXERR_TXERR2_MASK                    .equ 0x04
CANTXERR_TXERR2_BIT                     .equ 0x02
CANTXERR_TXERR3_MASK                    .equ 0x08
CANTXERR_TXERR3_BIT                     .equ 0x03
CANTXERR_TXERR4_MASK                    .equ 0x10
CANTXERR_TXERR4_BIT                     .equ 0x04
CANTXERR_TXERR5_MASK                    .equ 0x20
CANTXERR_TXERR5_BIT                     .equ 0x05
CANTXERR_TXERR6_MASK                    .equ 0x40
CANTXERR_TXERR6_BIT                     .equ 0x06
CANTXERR_TXERR7_MASK                    .equ 0x80
CANTXERR_TXERR7_BIT                     .equ 0x07

;*********************************************
;  MSCAN Identifier Acceptance Register 0
;*********************************************
CANIDAR0                                .equ 0xFFFF9890 ;  MSCAN Identifier Acceptance Register 0
CANIDAR0_AC0_MASK                       .equ 0x01
CANIDAR0_AC0_BIT                        .equ 0x00
CANIDAR0_AC1_MASK                       .equ 0x02
CANIDAR0_AC1_BIT                        .equ 0x01
CANIDAR0_AC2_MASK                       .equ 0x04
CANIDAR0_AC2_BIT                        .equ 0x02
CANIDAR0_AC3_MASK                       .equ 0x08
CANIDAR0_AC3_BIT                        .equ 0x03
CANIDAR0_AC4_MASK                       .equ 0x10
CANIDAR0_AC4_BIT                        .equ 0x04
CANIDAR0_AC5_MASK                       .equ 0x20
CANIDAR0_AC5_BIT                        .equ 0x05
CANIDAR0_AC6_MASK                       .equ 0x40
CANIDAR0_AC6_BIT                        .equ 0x06
CANIDAR0_AC7_MASK                       .equ 0x80
CANIDAR0_AC7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Acceptance Register 1
;*********************************************
CANIDAR1                                .equ 0xFFFF9891 ;  MSCAN Identifier Acceptance Register 1
CANIDAR1_AC0_MASK                       .equ 0x01
CANIDAR1_AC0_BIT                        .equ 0x00
CANIDAR1_AC1_MASK                       .equ 0x02
CANIDAR1_AC1_BIT                        .equ 0x01
CANIDAR1_AC2_MASK                       .equ 0x04
CANIDAR1_AC2_BIT                        .equ 0x02
CANIDAR1_AC3_MASK                       .equ 0x08
CANIDAR1_AC3_BIT                        .equ 0x03
CANIDAR1_AC4_MASK                       .equ 0x10
CANIDAR1_AC4_BIT                        .equ 0x04
CANIDAR1_AC5_MASK                       .equ 0x20
CANIDAR1_AC5_BIT                        .equ 0x05
CANIDAR1_AC6_MASK                       .equ 0x40
CANIDAR1_AC6_BIT                        .equ 0x06
CANIDAR1_AC7_MASK                       .equ 0x80
CANIDAR1_AC7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Acceptance Register 2
;*********************************************
CANIDAR2                                .equ 0xFFFF9892 ;  MSCAN Identifier Acceptance Register 2
CANIDAR2_AC0_MASK                       .equ 0x01
CANIDAR2_AC0_BIT                        .equ 0x00
CANIDAR2_AC1_MASK                       .equ 0x02
CANIDAR2_AC1_BIT                        .equ 0x01
CANIDAR2_AC2_MASK                       .equ 0x04
CANIDAR2_AC2_BIT                        .equ 0x02
CANIDAR2_AC3_MASK                       .equ 0x08
CANIDAR2_AC3_BIT                        .equ 0x03
CANIDAR2_AC4_MASK                       .equ 0x10
CANIDAR2_AC4_BIT                        .equ 0x04
CANIDAR2_AC5_MASK                       .equ 0x20
CANIDAR2_AC5_BIT                        .equ 0x05
CANIDAR2_AC6_MASK                       .equ 0x40
CANIDAR2_AC6_BIT                        .equ 0x06
CANIDAR2_AC7_MASK                       .equ 0x80
CANIDAR2_AC7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Acceptance Register 3
;*********************************************
CANIDAR3                                .equ 0xFFFF9893 ;  MSCAN Identifier Acceptance Register 3
CANIDAR3_AC0_MASK                       .equ 0x01
CANIDAR3_AC0_BIT                        .equ 0x00
CANIDAR3_AC1_MASK                       .equ 0x02
CANIDAR3_AC1_BIT                        .equ 0x01
CANIDAR3_AC2_MASK                       .equ 0x04
CANIDAR3_AC2_BIT                        .equ 0x02
CANIDAR3_AC3_MASK                       .equ 0x08
CANIDAR3_AC3_BIT                        .equ 0x03
CANIDAR3_AC4_MASK                       .equ 0x10
CANIDAR3_AC4_BIT                        .equ 0x04
CANIDAR3_AC5_MASK                       .equ 0x20
CANIDAR3_AC5_BIT                        .equ 0x05
CANIDAR3_AC6_MASK                       .equ 0x40
CANIDAR3_AC6_BIT                        .equ 0x06
CANIDAR3_AC7_MASK                       .equ 0x80
CANIDAR3_AC7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Mask Register 0
;*********************************************
CANIDMR0                                .equ 0xFFFF9894 ;  MSCAN Identifier Mask Register 0
CANIDMR0_AM0_MASK                       .equ 0x01
CANIDMR0_AM0_BIT                        .equ 0x00
CANIDMR0_AM1_MASK                       .equ 0x02
CANIDMR0_AM1_BIT                        .equ 0x01
CANIDMR0_AM2_MASK                       .equ 0x04
CANIDMR0_AM2_BIT                        .equ 0x02
CANIDMR0_AM3_MASK                       .equ 0x08
CANIDMR0_AM3_BIT                        .equ 0x03
CANIDMR0_AM4_MASK                       .equ 0x10
CANIDMR0_AM4_BIT                        .equ 0x04
CANIDMR0_AM5_MASK                       .equ 0x20
CANIDMR0_AM5_BIT                        .equ 0x05
CANIDMR0_AM6_MASK                       .equ 0x40
CANIDMR0_AM6_BIT                        .equ 0x06
CANIDMR0_AM7_MASK                       .equ 0x80
CANIDMR0_AM7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Mask Register 1
;*********************************************
CANIDMR1                                .equ 0xFFFF9895 ;  MSCAN Identifier Mask Register 1
CANIDMR1_AM0_MASK                       .equ 0x01
CANIDMR1_AM0_BIT                        .equ 0x00
CANIDMR1_AM1_MASK                       .equ 0x02
CANIDMR1_AM1_BIT                        .equ 0x01
CANIDMR1_AM2_MASK                       .equ 0x04
CANIDMR1_AM2_BIT                        .equ 0x02
CANIDMR1_AM3_MASK                       .equ 0x08
CANIDMR1_AM3_BIT                        .equ 0x03
CANIDMR1_AM4_MASK                       .equ 0x10
CANIDMR1_AM4_BIT                        .equ 0x04
CANIDMR1_AM5_MASK                       .equ 0x20
CANIDMR1_AM5_BIT                        .equ 0x05
CANIDMR1_AM6_MASK                       .equ 0x40
CANIDMR1_AM6_BIT                        .equ 0x06
CANIDMR1_AM7_MASK                       .equ 0x80
CANIDMR1_AM7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Mask Register 2
;*********************************************
CANIDMR2                                .equ 0xFFFF9896 ;  MSCAN Identifier Mask Register 2
CANIDMR2_AM0_MASK                       .equ 0x01
CANIDMR2_AM0_BIT                        .equ 0x00
CANIDMR2_AM1_MASK                       .equ 0x02
CANIDMR2_AM1_BIT                        .equ 0x01
CANIDMR2_AM2_MASK                       .equ 0x04
CANIDMR2_AM2_BIT                        .equ 0x02
CANIDMR2_AM3_MASK                       .equ 0x08
CANIDMR2_AM3_BIT                        .equ 0x03
CANIDMR2_AM4_MASK                       .equ 0x10
CANIDMR2_AM4_BIT                        .equ 0x04
CANIDMR2_AM5_MASK                       .equ 0x20
CANIDMR2_AM5_BIT                        .equ 0x05
CANIDMR2_AM6_MASK                       .equ 0x40
CANIDMR2_AM6_BIT                        .equ 0x06
CANIDMR2_AM7_MASK                       .equ 0x80
CANIDMR2_AM7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Mask Register 3
;*********************************************
CANIDMR3                                .equ 0xFFFF9897 ;  MSCAN Identifier Mask Register 3
CANIDMR3_AM0_MASK                       .equ 0x01
CANIDMR3_AM0_BIT                        .equ 0x00
CANIDMR3_AM1_MASK                       .equ 0x02
CANIDMR3_AM1_BIT                        .equ 0x01
CANIDMR3_AM2_MASK                       .equ 0x04
CANIDMR3_AM2_BIT                        .equ 0x02
CANIDMR3_AM3_MASK                       .equ 0x08
CANIDMR3_AM3_BIT                        .equ 0x03
CANIDMR3_AM4_MASK                       .equ 0x10
CANIDMR3_AM4_BIT                        .equ 0x04
CANIDMR3_AM5_MASK                       .equ 0x20
CANIDMR3_AM5_BIT                        .equ 0x05
CANIDMR3_AM6_MASK                       .equ 0x40
CANIDMR3_AM6_BIT                        .equ 0x06
CANIDMR3_AM7_MASK                       .equ 0x80
CANIDMR3_AM7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Acceptance Register 4
;*********************************************
CANIDAR4                                .equ 0xFFFF9898 ;  MSCAN Identifier Acceptance Register 4
CANIDAR4_AC0_MASK                       .equ 0x01
CANIDAR4_AC0_BIT                        .equ 0x00
CANIDAR4_AC1_MASK                       .equ 0x02
CANIDAR4_AC1_BIT                        .equ 0x01
CANIDAR4_AC2_MASK                       .equ 0x04
CANIDAR4_AC2_BIT                        .equ 0x02
CANIDAR4_AC3_MASK                       .equ 0x08
CANIDAR4_AC3_BIT                        .equ 0x03
CANIDAR4_AC4_MASK                       .equ 0x10
CANIDAR4_AC4_BIT                        .equ 0x04
CANIDAR4_AC5_MASK                       .equ 0x20
CANIDAR4_AC5_BIT                        .equ 0x05
CANIDAR4_AC6_MASK                       .equ 0x40
CANIDAR4_AC6_BIT                        .equ 0x06
CANIDAR4_AC7_MASK                       .equ 0x80
CANIDAR4_AC7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Acceptance Register 5
;*********************************************
CANIDAR5                                .equ 0xFFFF9899 ;  MSCAN Identifier Acceptance Register 5
CANIDAR5_AC0_MASK                       .equ 0x01
CANIDAR5_AC0_BIT                        .equ 0x00
CANIDAR5_AC1_MASK                       .equ 0x02
CANIDAR5_AC1_BIT                        .equ 0x01
CANIDAR5_AC2_MASK                       .equ 0x04
CANIDAR5_AC2_BIT                        .equ 0x02
CANIDAR5_AC3_MASK                       .equ 0x08
CANIDAR5_AC3_BIT                        .equ 0x03
CANIDAR5_AC4_MASK                       .equ 0x10
CANIDAR5_AC4_BIT                        .equ 0x04
CANIDAR5_AC5_MASK                       .equ 0x20
CANIDAR5_AC5_BIT                        .equ 0x05
CANIDAR5_AC6_MASK                       .equ 0x40
CANIDAR5_AC6_BIT                        .equ 0x06
CANIDAR5_AC7_MASK                       .equ 0x80
CANIDAR5_AC7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Acceptance Register 6
;*********************************************
CANIDAR6                                .equ 0xFFFF989A ;  MSCAN Identifier Acceptance Register 6
CANIDAR6_AC0_MASK                       .equ 0x01
CANIDAR6_AC0_BIT                        .equ 0x00
CANIDAR6_AC1_MASK                       .equ 0x02
CANIDAR6_AC1_BIT                        .equ 0x01
CANIDAR6_AC2_MASK                       .equ 0x04
CANIDAR6_AC2_BIT                        .equ 0x02
CANIDAR6_AC3_MASK                       .equ 0x08
CANIDAR6_AC3_BIT                        .equ 0x03
CANIDAR6_AC4_MASK                       .equ 0x10
CANIDAR6_AC4_BIT                        .equ 0x04
CANIDAR6_AC5_MASK                       .equ 0x20
CANIDAR6_AC5_BIT                        .equ 0x05
CANIDAR6_AC6_MASK                       .equ 0x40
CANIDAR6_AC6_BIT                        .equ 0x06
CANIDAR6_AC7_MASK                       .equ 0x80
CANIDAR6_AC7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Acceptance Register 7
;*********************************************
CANIDAR7                                .equ 0xFFFF989B ;  MSCAN Identifier Acceptance Register 7
CANIDAR7_AC0_MASK                       .equ 0x01
CANIDAR7_AC0_BIT                        .equ 0x00
CANIDAR7_AC1_MASK                       .equ 0x02
CANIDAR7_AC1_BIT                        .equ 0x01
CANIDAR7_AC2_MASK                       .equ 0x04
CANIDAR7_AC2_BIT                        .equ 0x02
CANIDAR7_AC3_MASK                       .equ 0x08
CANIDAR7_AC3_BIT                        .equ 0x03
CANIDAR7_AC4_MASK                       .equ 0x10
CANIDAR7_AC4_BIT                        .equ 0x04
CANIDAR7_AC5_MASK                       .equ 0x20
CANIDAR7_AC5_BIT                        .equ 0x05
CANIDAR7_AC6_MASK                       .equ 0x40
CANIDAR7_AC6_BIT                        .equ 0x06
CANIDAR7_AC7_MASK                       .equ 0x80
CANIDAR7_AC7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Mask Register 4
;*********************************************
CANIDMR4                                .equ 0xFFFF989C ;  MSCAN Identifier Mask Register 4
CANIDMR4_AM0_MASK                       .equ 0x01
CANIDMR4_AM0_BIT                        .equ 0x00
CANIDMR4_AM1_MASK                       .equ 0x02
CANIDMR4_AM1_BIT                        .equ 0x01
CANIDMR4_AM2_MASK                       .equ 0x04
CANIDMR4_AM2_BIT                        .equ 0x02
CANIDMR4_AM3_MASK                       .equ 0x08
CANIDMR4_AM3_BIT                        .equ 0x03
CANIDMR4_AM4_MASK                       .equ 0x10
CANIDMR4_AM4_BIT                        .equ 0x04
CANIDMR4_AM5_MASK                       .equ 0x20
CANIDMR4_AM5_BIT                        .equ 0x05
CANIDMR4_AM6_MASK                       .equ 0x40
CANIDMR4_AM6_BIT                        .equ 0x06
CANIDMR4_AM7_MASK                       .equ 0x80
CANIDMR4_AM7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Mask Register 5
;*********************************************
CANIDMR5                                .equ 0xFFFF989D ;  MSCAN Identifier Mask Register 5
CANIDMR5_AM0_MASK                       .equ 0x01
CANIDMR5_AM0_BIT                        .equ 0x00
CANIDMR5_AM1_MASK                       .equ 0x02
CANIDMR5_AM1_BIT                        .equ 0x01
CANIDMR5_AM2_MASK                       .equ 0x04
CANIDMR5_AM2_BIT                        .equ 0x02
CANIDMR5_AM3_MASK                       .equ 0x08
CANIDMR5_AM3_BIT                        .equ 0x03
CANIDMR5_AM4_MASK                       .equ 0x10
CANIDMR5_AM4_BIT                        .equ 0x04
CANIDMR5_AM5_MASK                       .equ 0x20
CANIDMR5_AM5_BIT                        .equ 0x05
CANIDMR5_AM6_MASK                       .equ 0x40
CANIDMR5_AM6_BIT                        .equ 0x06
CANIDMR5_AM7_MASK                       .equ 0x80
CANIDMR5_AM7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Mask Register 6
;*********************************************
CANIDMR6                                .equ 0xFFFF989E ;  MSCAN Identifier Mask Register 6
CANIDMR6_AM0_MASK                       .equ 0x01
CANIDMR6_AM0_BIT                        .equ 0x00
CANIDMR6_AM1_MASK                       .equ 0x02
CANIDMR6_AM1_BIT                        .equ 0x01
CANIDMR6_AM2_MASK                       .equ 0x04
CANIDMR6_AM2_BIT                        .equ 0x02
CANIDMR6_AM3_MASK                       .equ 0x08
CANIDMR6_AM3_BIT                        .equ 0x03
CANIDMR6_AM4_MASK                       .equ 0x10
CANIDMR6_AM4_BIT                        .equ 0x04
CANIDMR6_AM5_MASK                       .equ 0x20
CANIDMR6_AM5_BIT                        .equ 0x05
CANIDMR6_AM6_MASK                       .equ 0x40
CANIDMR6_AM6_BIT                        .equ 0x06
CANIDMR6_AM7_MASK                       .equ 0x80
CANIDMR6_AM7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Identifier Mask Register 7
;*********************************************
CANIDMR7                                .equ 0xFFFF989F ;  MSCAN Identifier Mask Register 7
CANIDMR7_AM0_MASK                       .equ 0x01
CANIDMR7_AM0_BIT                        .equ 0x00
CANIDMR7_AM1_MASK                       .equ 0x02
CANIDMR7_AM1_BIT                        .equ 0x01
CANIDMR7_AM2_MASK                       .equ 0x04
CANIDMR7_AM2_BIT                        .equ 0x02
CANIDMR7_AM3_MASK                       .equ 0x08
CANIDMR7_AM3_BIT                        .equ 0x03
CANIDMR7_AM4_MASK                       .equ 0x10
CANIDMR7_AM4_BIT                        .equ 0x04
CANIDMR7_AM5_MASK                       .equ 0x20
CANIDMR7_AM5_BIT                        .equ 0x05
CANIDMR7_AM6_MASK                       .equ 0x40
CANIDMR7_AM6_BIT                        .equ 0x06
CANIDMR7_AM7_MASK                       .equ 0x80
CANIDMR7_AM7_BIT                        .equ 0x07

;*********************************************
;  MSCAN 0 Receive Identifier Register
;*********************************************
CANRIDR0_ID21_MASK                      .equ 0x01
CANRIDR0_ID21_BIT                       .equ 0x00
CANRIDR0_ID22_MASK                      .equ 0x02
CANRIDR0_ID22_BIT                       .equ 0x01
CANRIDR0_ID23_MASK                      .equ 0x04
CANRIDR0_ID23_BIT                       .equ 0x02
CANRIDR0_ID24_MASK                      .equ 0x08
CANRIDR0_ID24_BIT                       .equ 0x03
CANRIDR0_ID25_MASK                      .equ 0x10
CANRIDR0_ID25_BIT                       .equ 0x04
CANRIDR0_ID26_MASK                      .equ 0x20
CANRIDR0_ID26_BIT                       .equ 0x05
CANRIDR0_ID27_MASK                      .equ 0x40
CANRIDR0_ID27_BIT                       .equ 0x06
CANRIDR0_ID28_MASK                      .equ 0x80
CANRIDR0_ID28_BIT                       .equ 0x07
CANRIDR1_ID15_MASK                      .equ 0x01
CANRIDR1_ID15_BIT                       .equ 0x00
CANRIDR1_ID16_MASK                      .equ 0x02
CANRIDR1_ID16_BIT                       .equ 0x01
CANRIDR1_ID17_MASK                      .equ 0x04
CANRIDR1_ID17_BIT                       .equ 0x02
CANRIDR1_IDE_MASK                       .equ 0x08
CANRIDR1_IDE_BIT                        .equ 0x03
CANRIDR1_SRR_MASK                       .equ 0x10
CANRIDR1_SRR_BIT                        .equ 0x04
CANRIDR1_ID18_MASK                      .equ 0x20
CANRIDR1_ID18_BIT                       .equ 0x05
CANRIDR1_ID19_MASK                      .equ 0x40
CANRIDR1_ID19_BIT                       .equ 0x06
CANRIDR1_ID20_MASK                      .equ 0x80
CANRIDR1_ID20_BIT                       .equ 0x07
CANRIDR1_ID_15_MASK                     .equ 0x07
CANRIDR1_ID_18_MASK                     .equ 0xE0
CANRIDR2_ID7_MASK                       .equ 0x01
CANRIDR2_ID7_BIT                        .equ 0x00
CANRIDR2_ID8_MASK                       .equ 0x02
CANRIDR2_ID8_BIT                        .equ 0x01
CANRIDR2_ID9_MASK                       .equ 0x04
CANRIDR2_ID9_BIT                        .equ 0x02
CANRIDR2_ID10_MASK                      .equ 0x08
CANRIDR2_ID10_BIT                       .equ 0x03
CANRIDR2_ID11_MASK                      .equ 0x10
CANRIDR2_ID11_BIT                       .equ 0x04
CANRIDR2_ID12_MASK                      .equ 0x20
CANRIDR2_ID12_BIT                       .equ 0x05
CANRIDR2_ID13_MASK                      .equ 0x40
CANRIDR2_ID13_BIT                       .equ 0x06
CANRIDR2_ID14_MASK                      .equ 0x80
CANRIDR2_ID14_BIT                       .equ 0x07
CANRIDR3_RTR_MASK                       .equ 0x01
CANRIDR3_RTR_BIT                        .equ 0x00
CANRIDR3_ID0_MASK                       .equ 0x02
CANRIDR3_ID0_BIT                        .equ 0x01
CANRIDR3_ID1_MASK                       .equ 0x04
CANRIDR3_ID1_BIT                        .equ 0x02
CANRIDR3_ID2_MASK                       .equ 0x08
CANRIDR3_ID2_BIT                        .equ 0x03
CANRIDR3_ID3_MASK                       .equ 0x10
CANRIDR3_ID3_BIT                        .equ 0x04
CANRIDR3_ID4_MASK                       .equ 0x20
CANRIDR3_ID4_BIT                        .equ 0x05
CANRIDR3_ID5_MASK                       .equ 0x40
CANRIDR3_ID5_BIT                        .equ 0x06
CANRIDR3_ID6_MASK                       .equ 0x80
CANRIDR3_ID6_BIT                        .equ 0x07
CANRIDR3_ID_MASK                        .equ 0xFE
CANRIDR                                 .equ 0xFFFF98A0 ;  MSCAN 0 Receive Identifier Register
CANRIDR_RTR_MASK                        .equ 0x01
CANRIDR_RTR_BIT                         .equ 0x00
CANRIDR_ID0_MASK                        .equ 0x02
CANRIDR_ID0_BIT                         .equ 0x01
CANRIDR_ID1_MASK                        .equ 0x04
CANRIDR_ID1_BIT                         .equ 0x02
CANRIDR_ID2_MASK                        .equ 0x08
CANRIDR_ID2_BIT                         .equ 0x03
CANRIDR_ID3_MASK                        .equ 0x10
CANRIDR_ID3_BIT                         .equ 0x04
CANRIDR_ID4_MASK                        .equ 0x20
CANRIDR_ID4_BIT                         .equ 0x05
CANRIDR_ID5_MASK                        .equ 0x40
CANRIDR_ID5_BIT                         .equ 0x06
CANRIDR_ID6_MASK                        .equ 0x80
CANRIDR_ID6_BIT                         .equ 0x07
CANRIDR_ID7_MASK                        .equ 0x100
CANRIDR_ID7_BIT                         .equ 0x08
CANRIDR_ID8_MASK                        .equ 0x200
CANRIDR_ID8_BIT                         .equ 0x09
CANRIDR_ID9_MASK                        .equ 0x400
CANRIDR_ID9_BIT                         .equ 0x0A
CANRIDR_ID10_MASK                       .equ 0x800
CANRIDR_ID10_BIT                        .equ 0x0B
CANRIDR_ID11_MASK                       .equ 0x1000
CANRIDR_ID11_BIT                        .equ 0x0C
CANRIDR_ID12_MASK                       .equ 0x2000
CANRIDR_ID12_BIT                        .equ 0x0D
CANRIDR_ID13_MASK                       .equ 0x4000
CANRIDR_ID13_BIT                        .equ 0x0E
CANRIDR_ID14_MASK                       .equ 0x8000
CANRIDR_ID14_BIT                        .equ 0x0F
CANRIDR_ID15_MASK                       .equ 0x10000
CANRIDR_ID15_BIT                        .equ 0x10
CANRIDR_ID16_MASK                       .equ 0x20000
CANRIDR_ID16_BIT                        .equ 0x11
CANRIDR_ID17_MASK                       .equ 0x40000
CANRIDR_ID17_BIT                        .equ 0x12
CANRIDR_IDE_MASK                        .equ 0x80000
CANRIDR_IDE_BIT                         .equ 0x13
CANRIDR_SRR_MASK                        .equ 0x100000
CANRIDR_SRR_BIT                         .equ 0x14
CANRIDR_ID18_MASK                       .equ 0x200000
CANRIDR_ID18_BIT                        .equ 0x15
CANRIDR_ID19_MASK                       .equ 0x400000
CANRIDR_ID19_BIT                        .equ 0x16
CANRIDR_ID20_MASK                       .equ 0x800000
CANRIDR_ID20_BIT                        .equ 0x17
CANRIDR_ID21_MASK                       .equ 0x1000000
CANRIDR_ID21_BIT                        .equ 0x18
CANRIDR_ID22_MASK                       .equ 0x2000000
CANRIDR_ID22_BIT                        .equ 0x19
CANRIDR_ID23_MASK                       .equ 0x4000000
CANRIDR_ID23_BIT                        .equ 0x1A
CANRIDR_ID24_MASK                       .equ 0x8000000
CANRIDR_ID24_BIT                        .equ 0x1B
CANRIDR_ID25_MASK                       .equ 0x10000000
CANRIDR_ID25_BIT                        .equ 0x1C
CANRIDR_ID26_MASK                       .equ 0x20000000
CANRIDR_ID26_BIT                        .equ 0x1D
CANRIDR_ID27_MASK                       .equ 0x40000000
CANRIDR_ID27_BIT                        .equ 0x1E
CANRIDR_ID28_MASK                       .equ 0x80000000
CANRIDR_ID28_BIT                        .equ 0x1F
CANRIDR_ID_MASK                         .equ 0x7FFFE
CANRIDR_ID_18_MASK                      .equ 0xFFE00000

;*********************************************
;  MSCAN Receive Data Segment Register 0
;*********************************************
CANRDSR0                                .equ 0xFFFF98A4 ;  MSCAN Receive Data Segment Register 0
CANRDSR0_DB0_MASK                       .equ 0x01
CANRDSR0_DB0_BIT                        .equ 0x00
CANRDSR0_DB1_MASK                       .equ 0x02
CANRDSR0_DB1_BIT                        .equ 0x01
CANRDSR0_DB2_MASK                       .equ 0x04
CANRDSR0_DB2_BIT                        .equ 0x02
CANRDSR0_DB3_MASK                       .equ 0x08
CANRDSR0_DB3_BIT                        .equ 0x03
CANRDSR0_DB4_MASK                       .equ 0x10
CANRDSR0_DB4_BIT                        .equ 0x04
CANRDSR0_DB5_MASK                       .equ 0x20
CANRDSR0_DB5_BIT                        .equ 0x05
CANRDSR0_DB6_MASK                       .equ 0x40
CANRDSR0_DB6_BIT                        .equ 0x06
CANRDSR0_DB7_MASK                       .equ 0x80
CANRDSR0_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Receive Data Segment Register 1
;*********************************************
CANRDSR1                                .equ 0xFFFF98A5 ;  MSCAN Receive Data Segment Register 1
CANRDSR1_DB0_MASK                       .equ 0x01
CANRDSR1_DB0_BIT                        .equ 0x00
CANRDSR1_DB1_MASK                       .equ 0x02
CANRDSR1_DB1_BIT                        .equ 0x01
CANRDSR1_DB2_MASK                       .equ 0x04
CANRDSR1_DB2_BIT                        .equ 0x02
CANRDSR1_DB3_MASK                       .equ 0x08
CANRDSR1_DB3_BIT                        .equ 0x03
CANRDSR1_DB4_MASK                       .equ 0x10
CANRDSR1_DB4_BIT                        .equ 0x04
CANRDSR1_DB5_MASK                       .equ 0x20
CANRDSR1_DB5_BIT                        .equ 0x05
CANRDSR1_DB6_MASK                       .equ 0x40
CANRDSR1_DB6_BIT                        .equ 0x06
CANRDSR1_DB7_MASK                       .equ 0x80
CANRDSR1_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Receive Data Segment Register 2
;*********************************************
CANRDSR2                                .equ 0xFFFF98A6 ;  MSCAN Receive Data Segment Register 2
CANRDSR2_DB0_MASK                       .equ 0x01
CANRDSR2_DB0_BIT                        .equ 0x00
CANRDSR2_DB1_MASK                       .equ 0x02
CANRDSR2_DB1_BIT                        .equ 0x01
CANRDSR2_DB2_MASK                       .equ 0x04
CANRDSR2_DB2_BIT                        .equ 0x02
CANRDSR2_DB3_MASK                       .equ 0x08
CANRDSR2_DB3_BIT                        .equ 0x03
CANRDSR2_DB4_MASK                       .equ 0x10
CANRDSR2_DB4_BIT                        .equ 0x04
CANRDSR2_DB5_MASK                       .equ 0x20
CANRDSR2_DB5_BIT                        .equ 0x05
CANRDSR2_DB6_MASK                       .equ 0x40
CANRDSR2_DB6_BIT                        .equ 0x06
CANRDSR2_DB7_MASK                       .equ 0x80
CANRDSR2_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Receive Data Segment Register 3
;*********************************************
CANRDSR3                                .equ 0xFFFF98A7 ;  MSCAN Receive Data Segment Register 3
CANRDSR3_DB0_MASK                       .equ 0x01
CANRDSR3_DB0_BIT                        .equ 0x00
CANRDSR3_DB1_MASK                       .equ 0x02
CANRDSR3_DB1_BIT                        .equ 0x01
CANRDSR3_DB2_MASK                       .equ 0x04
CANRDSR3_DB2_BIT                        .equ 0x02
CANRDSR3_DB3_MASK                       .equ 0x08
CANRDSR3_DB3_BIT                        .equ 0x03
CANRDSR3_DB4_MASK                       .equ 0x10
CANRDSR3_DB4_BIT                        .equ 0x04
CANRDSR3_DB5_MASK                       .equ 0x20
CANRDSR3_DB5_BIT                        .equ 0x05
CANRDSR3_DB6_MASK                       .equ 0x40
CANRDSR3_DB6_BIT                        .equ 0x06
CANRDSR3_DB7_MASK                       .equ 0x80
CANRDSR3_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Receive Data Segment Register 4
;*********************************************
CANRDSR4                                .equ 0xFFFF98A8 ;  MSCAN Receive Data Segment Register 4
CANRDSR4_DB0_MASK                       .equ 0x01
CANRDSR4_DB0_BIT                        .equ 0x00
CANRDSR4_DB1_MASK                       .equ 0x02
CANRDSR4_DB1_BIT                        .equ 0x01
CANRDSR4_DB2_MASK                       .equ 0x04
CANRDSR4_DB2_BIT                        .equ 0x02
CANRDSR4_DB3_MASK                       .equ 0x08
CANRDSR4_DB3_BIT                        .equ 0x03
CANRDSR4_DB4_MASK                       .equ 0x10
CANRDSR4_DB4_BIT                        .equ 0x04
CANRDSR4_DB5_MASK                       .equ 0x20
CANRDSR4_DB5_BIT                        .equ 0x05
CANRDSR4_DB6_MASK                       .equ 0x40
CANRDSR4_DB6_BIT                        .equ 0x06
CANRDSR4_DB7_MASK                       .equ 0x80
CANRDSR4_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Receive Data Segment Register 5
;*********************************************
CANRDSR5                                .equ 0xFFFF98A9 ;  MSCAN Receive Data Segment Register 5
CANRDSR5_DB0_MASK                       .equ 0x01
CANRDSR5_DB0_BIT                        .equ 0x00
CANRDSR5_DB1_MASK                       .equ 0x02
CANRDSR5_DB1_BIT                        .equ 0x01
CANRDSR5_DB2_MASK                       .equ 0x04
CANRDSR5_DB2_BIT                        .equ 0x02
CANRDSR5_DB3_MASK                       .equ 0x08
CANRDSR5_DB3_BIT                        .equ 0x03
CANRDSR5_DB4_MASK                       .equ 0x10
CANRDSR5_DB4_BIT                        .equ 0x04
CANRDSR5_DB5_MASK                       .equ 0x20
CANRDSR5_DB5_BIT                        .equ 0x05
CANRDSR5_DB6_MASK                       .equ 0x40
CANRDSR5_DB6_BIT                        .equ 0x06
CANRDSR5_DB7_MASK                       .equ 0x80
CANRDSR5_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Receive Data Segment Register 6
;*********************************************
CANRDSR6                                .equ 0xFFFF98AA ;  MSCAN Receive Data Segment Register 6
CANRDSR6_DB0_MASK                       .equ 0x01
CANRDSR6_DB0_BIT                        .equ 0x00
CANRDSR6_DB1_MASK                       .equ 0x02
CANRDSR6_DB1_BIT                        .equ 0x01
CANRDSR6_DB2_MASK                       .equ 0x04
CANRDSR6_DB2_BIT                        .equ 0x02
CANRDSR6_DB3_MASK                       .equ 0x08
CANRDSR6_DB3_BIT                        .equ 0x03
CANRDSR6_DB4_MASK                       .equ 0x10
CANRDSR6_DB4_BIT                        .equ 0x04
CANRDSR6_DB5_MASK                       .equ 0x20
CANRDSR6_DB5_BIT                        .equ 0x05
CANRDSR6_DB6_MASK                       .equ 0x40
CANRDSR6_DB6_BIT                        .equ 0x06
CANRDSR6_DB7_MASK                       .equ 0x80
CANRDSR6_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Receive Data Segment Register 7
;*********************************************
CANRDSR7                                .equ 0xFFFF98AB ;  MSCAN Receive Data Segment Register 7
CANRDSR7_DB0_MASK                       .equ 0x01
CANRDSR7_DB0_BIT                        .equ 0x00
CANRDSR7_DB1_MASK                       .equ 0x02
CANRDSR7_DB1_BIT                        .equ 0x01
CANRDSR7_DB2_MASK                       .equ 0x04
CANRDSR7_DB2_BIT                        .equ 0x02
CANRDSR7_DB3_MASK                       .equ 0x08
CANRDSR7_DB3_BIT                        .equ 0x03
CANRDSR7_DB4_MASK                       .equ 0x10
CANRDSR7_DB4_BIT                        .equ 0x04
CANRDSR7_DB5_MASK                       .equ 0x20
CANRDSR7_DB5_BIT                        .equ 0x05
CANRDSR7_DB6_MASK                       .equ 0x40
CANRDSR7_DB6_BIT                        .equ 0x06
CANRDSR7_DB7_MASK                       .equ 0x80
CANRDSR7_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Receive Data Length Register
;*********************************************
CANRDLR                                 .equ 0xFFFF98AC ;  MSCAN Receive Data Length Register
CANRDLR_DLC0_MASK                       .equ 0x01
CANRDLR_DLC0_BIT                        .equ 0x00
CANRDLR_DLC1_MASK                       .equ 0x02
CANRDLR_DLC1_BIT                        .equ 0x01
CANRDLR_DLC2_MASK                       .equ 0x04
CANRDLR_DLC2_BIT                        .equ 0x02
CANRDLR_DLC3_MASK                       .equ 0x08
CANRDLR_DLC3_BIT                        .equ 0x03
CANRDLR_DLC_MASK                        .equ 0x0F

;*********************************************
;  MSCAN Receive Time Stamp Register
;*********************************************
CANRTSRH_TSR8_MASK                      .equ 0x01
CANRTSRH_TSR8_BIT                       .equ 0x00
CANRTSRH_TSR9_MASK                      .equ 0x02
CANRTSRH_TSR9_BIT                       .equ 0x01
CANRTSRH_TSR10_MASK                     .equ 0x04
CANRTSRH_TSR10_BIT                      .equ 0x02
CANRTSRH_TSR11_MASK                     .equ 0x08
CANRTSRH_TSR11_BIT                      .equ 0x03
CANRTSRH_TSR12_MASK                     .equ 0x10
CANRTSRH_TSR12_BIT                      .equ 0x04
CANRTSRH_TSR13_MASK                     .equ 0x20
CANRTSRH_TSR13_BIT                      .equ 0x05
CANRTSRH_TSR14_MASK                     .equ 0x40
CANRTSRH_TSR14_BIT                      .equ 0x06
CANRTSRH_TSR15_MASK                     .equ 0x80
CANRTSRH_TSR15_BIT                      .equ 0x07
CANRTSRL_TSR0_MASK                      .equ 0x01
CANRTSRL_TSR0_BIT                       .equ 0x00
CANRTSRL_TSR1_MASK                      .equ 0x02
CANRTSRL_TSR1_BIT                       .equ 0x01
CANRTSRL_TSR2_MASK                      .equ 0x04
CANRTSRL_TSR2_BIT                       .equ 0x02
CANRTSRL_TSR3_MASK                      .equ 0x08
CANRTSRL_TSR3_BIT                       .equ 0x03
CANRTSRL_TSR4_MASK                      .equ 0x10
CANRTSRL_TSR4_BIT                       .equ 0x04
CANRTSRL_TSR5_MASK                      .equ 0x20
CANRTSRL_TSR5_BIT                       .equ 0x05
CANRTSRL_TSR6_MASK                      .equ 0x40
CANRTSRL_TSR6_BIT                       .equ 0x06
CANRTSRL_TSR7_MASK                      .equ 0x80
CANRTSRL_TSR7_BIT                       .equ 0x07
CANRTSR                                 .equ 0xFFFF98AE ;  MSCAN Receive Time Stamp Register
CANRTSR_TSR0_MASK                       .equ 0x01
CANRTSR_TSR0_BIT                        .equ 0x00
CANRTSR_TSR1_MASK                       .equ 0x02
CANRTSR_TSR1_BIT                        .equ 0x01
CANRTSR_TSR2_MASK                       .equ 0x04
CANRTSR_TSR2_BIT                        .equ 0x02
CANRTSR_TSR3_MASK                       .equ 0x08
CANRTSR_TSR3_BIT                        .equ 0x03
CANRTSR_TSR4_MASK                       .equ 0x10
CANRTSR_TSR4_BIT                        .equ 0x04
CANRTSR_TSR5_MASK                       .equ 0x20
CANRTSR_TSR5_BIT                        .equ 0x05
CANRTSR_TSR6_MASK                       .equ 0x40
CANRTSR_TSR6_BIT                        .equ 0x06
CANRTSR_TSR7_MASK                       .equ 0x80
CANRTSR_TSR7_BIT                        .equ 0x07
CANRTSR_TSR8_MASK                       .equ 0x100
CANRTSR_TSR8_BIT                        .equ 0x08
CANRTSR_TSR9_MASK                       .equ 0x200
CANRTSR_TSR9_BIT                        .equ 0x09
CANRTSR_TSR10_MASK                      .equ 0x400
CANRTSR_TSR10_BIT                       .equ 0x0A
CANRTSR_TSR11_MASK                      .equ 0x800
CANRTSR_TSR11_BIT                       .equ 0x0B
CANRTSR_TSR12_MASK                      .equ 0x1000
CANRTSR_TSR12_BIT                       .equ 0x0C
CANRTSR_TSR13_MASK                      .equ 0x2000
CANRTSR_TSR13_BIT                       .equ 0x0D
CANRTSR_TSR14_MASK                      .equ 0x4000
CANRTSR_TSR14_BIT                       .equ 0x0E
CANRTSR_TSR15_MASK                      .equ 0x8000
CANRTSR_TSR15_BIT                       .equ 0x0F

;*********************************************
;  MSCAN 0 Transmit Identifier Register
;*********************************************
CANTIDR0_ID21_MASK                      .equ 0x01
CANTIDR0_ID21_BIT                       .equ 0x00
CANTIDR0_ID22_MASK                      .equ 0x02
CANTIDR0_ID22_BIT                       .equ 0x01
CANTIDR0_ID23_MASK                      .equ 0x04
CANTIDR0_ID23_BIT                       .equ 0x02
CANTIDR0_ID24_MASK                      .equ 0x08
CANTIDR0_ID24_BIT                       .equ 0x03
CANTIDR0_ID25_MASK                      .equ 0x10
CANTIDR0_ID25_BIT                       .equ 0x04
CANTIDR0_ID26_MASK                      .equ 0x20
CANTIDR0_ID26_BIT                       .equ 0x05
CANTIDR0_ID27_MASK                      .equ 0x40
CANTIDR0_ID27_BIT                       .equ 0x06
CANTIDR0_ID28_MASK                      .equ 0x80
CANTIDR0_ID28_BIT                       .equ 0x07
CANTIDR1_ID15_MASK                      .equ 0x01
CANTIDR1_ID15_BIT                       .equ 0x00
CANTIDR1_ID16_MASK                      .equ 0x02
CANTIDR1_ID16_BIT                       .equ 0x01
CANTIDR1_ID17_MASK                      .equ 0x04
CANTIDR1_ID17_BIT                       .equ 0x02
CANTIDR1_IDE_MASK                       .equ 0x08
CANTIDR1_IDE_BIT                        .equ 0x03
CANTIDR1_SRR_MASK                       .equ 0x10
CANTIDR1_SRR_BIT                        .equ 0x04
CANTIDR1_ID18_MASK                      .equ 0x20
CANTIDR1_ID18_BIT                       .equ 0x05
CANTIDR1_ID19_MASK                      .equ 0x40
CANTIDR1_ID19_BIT                       .equ 0x06
CANTIDR1_ID20_MASK                      .equ 0x80
CANTIDR1_ID20_BIT                       .equ 0x07
CANTIDR1_ID_15_MASK                     .equ 0x07
CANTIDR1_ID_18_MASK                     .equ 0xE0
CANTIDR2_ID7_MASK                       .equ 0x01
CANTIDR2_ID7_BIT                        .equ 0x00
CANTIDR2_ID8_MASK                       .equ 0x02
CANTIDR2_ID8_BIT                        .equ 0x01
CANTIDR2_ID9_MASK                       .equ 0x04
CANTIDR2_ID9_BIT                        .equ 0x02
CANTIDR2_ID10_MASK                      .equ 0x08
CANTIDR2_ID10_BIT                       .equ 0x03
CANTIDR2_ID11_MASK                      .equ 0x10
CANTIDR2_ID11_BIT                       .equ 0x04
CANTIDR2_ID12_MASK                      .equ 0x20
CANTIDR2_ID12_BIT                       .equ 0x05
CANTIDR2_ID13_MASK                      .equ 0x40
CANTIDR2_ID13_BIT                       .equ 0x06
CANTIDR2_ID14_MASK                      .equ 0x80
CANTIDR2_ID14_BIT                       .equ 0x07
CANTIDR3_RTR_MASK                       .equ 0x01
CANTIDR3_RTR_BIT                        .equ 0x00
CANTIDR3_ID0_MASK                       .equ 0x02
CANTIDR3_ID0_BIT                        .equ 0x01
CANTIDR3_ID1_MASK                       .equ 0x04
CANTIDR3_ID1_BIT                        .equ 0x02
CANTIDR3_ID2_MASK                       .equ 0x08
CANTIDR3_ID2_BIT                        .equ 0x03
CANTIDR3_ID3_MASK                       .equ 0x10
CANTIDR3_ID3_BIT                        .equ 0x04
CANTIDR3_ID4_MASK                       .equ 0x20
CANTIDR3_ID4_BIT                        .equ 0x05
CANTIDR3_ID5_MASK                       .equ 0x40
CANTIDR3_ID5_BIT                        .equ 0x06
CANTIDR3_ID6_MASK                       .equ 0x80
CANTIDR3_ID6_BIT                        .equ 0x07
CANTIDR3_ID_MASK                        .equ 0xFE
CANTIDR                                 .equ 0xFFFF98B0 ;  MSCAN 0 Transmit Identifier Register
CANTIDR_RTR_MASK                        .equ 0x01
CANTIDR_RTR_BIT                         .equ 0x00
CANTIDR_ID0_MASK                        .equ 0x02
CANTIDR_ID0_BIT                         .equ 0x01
CANTIDR_ID1_MASK                        .equ 0x04
CANTIDR_ID1_BIT                         .equ 0x02
CANTIDR_ID2_MASK                        .equ 0x08
CANTIDR_ID2_BIT                         .equ 0x03
CANTIDR_ID3_MASK                        .equ 0x10
CANTIDR_ID3_BIT                         .equ 0x04
CANTIDR_ID4_MASK                        .equ 0x20
CANTIDR_ID4_BIT                         .equ 0x05
CANTIDR_ID5_MASK                        .equ 0x40
CANTIDR_ID5_BIT                         .equ 0x06
CANTIDR_ID6_MASK                        .equ 0x80
CANTIDR_ID6_BIT                         .equ 0x07
CANTIDR_ID7_MASK                        .equ 0x100
CANTIDR_ID7_BIT                         .equ 0x08
CANTIDR_ID8_MASK                        .equ 0x200
CANTIDR_ID8_BIT                         .equ 0x09
CANTIDR_ID9_MASK                        .equ 0x400
CANTIDR_ID9_BIT                         .equ 0x0A
CANTIDR_ID10_MASK                       .equ 0x800
CANTIDR_ID10_BIT                        .equ 0x0B
CANTIDR_ID11_MASK                       .equ 0x1000
CANTIDR_ID11_BIT                        .equ 0x0C
CANTIDR_ID12_MASK                       .equ 0x2000
CANTIDR_ID12_BIT                        .equ 0x0D
CANTIDR_ID13_MASK                       .equ 0x4000
CANTIDR_ID13_BIT                        .equ 0x0E
CANTIDR_ID14_MASK                       .equ 0x8000
CANTIDR_ID14_BIT                        .equ 0x0F
CANTIDR_ID15_MASK                       .equ 0x10000
CANTIDR_ID15_BIT                        .equ 0x10
CANTIDR_ID16_MASK                       .equ 0x20000
CANTIDR_ID16_BIT                        .equ 0x11
CANTIDR_ID17_MASK                       .equ 0x40000
CANTIDR_ID17_BIT                        .equ 0x12
CANTIDR_IDE_MASK                        .equ 0x80000
CANTIDR_IDE_BIT                         .equ 0x13
CANTIDR_SRR_MASK                        .equ 0x100000
CANTIDR_SRR_BIT                         .equ 0x14
CANTIDR_ID18_MASK                       .equ 0x200000
CANTIDR_ID18_BIT                        .equ 0x15
CANTIDR_ID19_MASK                       .equ 0x400000
CANTIDR_ID19_BIT                        .equ 0x16
CANTIDR_ID20_MASK                       .equ 0x800000
CANTIDR_ID20_BIT                        .equ 0x17
CANTIDR_ID21_MASK                       .equ 0x1000000
CANTIDR_ID21_BIT                        .equ 0x18
CANTIDR_ID22_MASK                       .equ 0x2000000
CANTIDR_ID22_BIT                        .equ 0x19
CANTIDR_ID23_MASK                       .equ 0x4000000
CANTIDR_ID23_BIT                        .equ 0x1A
CANTIDR_ID24_MASK                       .equ 0x8000000
CANTIDR_ID24_BIT                        .equ 0x1B
CANTIDR_ID25_MASK                       .equ 0x10000000
CANTIDR_ID25_BIT                        .equ 0x1C
CANTIDR_ID26_MASK                       .equ 0x20000000
CANTIDR_ID26_BIT                        .equ 0x1D
CANTIDR_ID27_MASK                       .equ 0x40000000
CANTIDR_ID27_BIT                        .equ 0x1E
CANTIDR_ID28_MASK                       .equ 0x80000000
CANTIDR_ID28_BIT                        .equ 0x1F
CANTIDR_ID_MASK                         .equ 0x7FFFE
CANTIDR_ID_18_MASK                      .equ 0xFFE00000

;*********************************************
;  MSCAN Transmit Data Segment Register 0
;*********************************************
CANTDSR0                                .equ 0xFFFF98B4 ;  MSCAN Transmit Data Segment Register 0
CANTDSR0_DB0_MASK                       .equ 0x01
CANTDSR0_DB0_BIT                        .equ 0x00
CANTDSR0_DB1_MASK                       .equ 0x02
CANTDSR0_DB1_BIT                        .equ 0x01
CANTDSR0_DB2_MASK                       .equ 0x04
CANTDSR0_DB2_BIT                        .equ 0x02
CANTDSR0_DB3_MASK                       .equ 0x08
CANTDSR0_DB3_BIT                        .equ 0x03
CANTDSR0_DB4_MASK                       .equ 0x10
CANTDSR0_DB4_BIT                        .equ 0x04
CANTDSR0_DB5_MASK                       .equ 0x20
CANTDSR0_DB5_BIT                        .equ 0x05
CANTDSR0_DB6_MASK                       .equ 0x40
CANTDSR0_DB6_BIT                        .equ 0x06
CANTDSR0_DB7_MASK                       .equ 0x80
CANTDSR0_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Transmit Data Segment Register 1
;*********************************************
CANTDSR1                                .equ 0xFFFF98B5 ;  MSCAN Transmit Data Segment Register 1
CANTDSR1_DB0_MASK                       .equ 0x01
CANTDSR1_DB0_BIT                        .equ 0x00
CANTDSR1_DB1_MASK                       .equ 0x02
CANTDSR1_DB1_BIT                        .equ 0x01
CANTDSR1_DB2_MASK                       .equ 0x04
CANTDSR1_DB2_BIT                        .equ 0x02
CANTDSR1_DB3_MASK                       .equ 0x08
CANTDSR1_DB3_BIT                        .equ 0x03
CANTDSR1_DB4_MASK                       .equ 0x10
CANTDSR1_DB4_BIT                        .equ 0x04
CANTDSR1_DB5_MASK                       .equ 0x20
CANTDSR1_DB5_BIT                        .equ 0x05
CANTDSR1_DB6_MASK                       .equ 0x40
CANTDSR1_DB6_BIT                        .equ 0x06
CANTDSR1_DB7_MASK                       .equ 0x80
CANTDSR1_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Transmit Data Segment Register 2
;*********************************************
CANTDSR2                                .equ 0xFFFF98B6 ;  MSCAN Transmit Data Segment Register 2
CANTDSR2_DB0_MASK                       .equ 0x01
CANTDSR2_DB0_BIT                        .equ 0x00
CANTDSR2_DB1_MASK                       .equ 0x02
CANTDSR2_DB1_BIT                        .equ 0x01
CANTDSR2_DB2_MASK                       .equ 0x04
CANTDSR2_DB2_BIT                        .equ 0x02
CANTDSR2_DB3_MASK                       .equ 0x08
CANTDSR2_DB3_BIT                        .equ 0x03
CANTDSR2_DB4_MASK                       .equ 0x10
CANTDSR2_DB4_BIT                        .equ 0x04
CANTDSR2_DB5_MASK                       .equ 0x20
CANTDSR2_DB5_BIT                        .equ 0x05
CANTDSR2_DB6_MASK                       .equ 0x40
CANTDSR2_DB6_BIT                        .equ 0x06
CANTDSR2_DB7_MASK                       .equ 0x80
CANTDSR2_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Transmit Data Segment Register 3
;*********************************************
CANTDSR3                                .equ 0xFFFF98B7 ;  MSCAN Transmit Data Segment Register 3
CANTDSR3_DB0_MASK                       .equ 0x01
CANTDSR3_DB0_BIT                        .equ 0x00
CANTDSR3_DB1_MASK                       .equ 0x02
CANTDSR3_DB1_BIT                        .equ 0x01
CANTDSR3_DB2_MASK                       .equ 0x04
CANTDSR3_DB2_BIT                        .equ 0x02
CANTDSR3_DB3_MASK                       .equ 0x08
CANTDSR3_DB3_BIT                        .equ 0x03
CANTDSR3_DB4_MASK                       .equ 0x10
CANTDSR3_DB4_BIT                        .equ 0x04
CANTDSR3_DB5_MASK                       .equ 0x20
CANTDSR3_DB5_BIT                        .equ 0x05
CANTDSR3_DB6_MASK                       .equ 0x40
CANTDSR3_DB6_BIT                        .equ 0x06
CANTDSR3_DB7_MASK                       .equ 0x80
CANTDSR3_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Transmit Data Segment Register 4
;*********************************************
CANTDSR4                                .equ 0xFFFF98B8 ;  MSCAN Transmit Data Segment Register 4
CANTDSR4_DB0_MASK                       .equ 0x01
CANTDSR4_DB0_BIT                        .equ 0x00
CANTDSR4_DB1_MASK                       .equ 0x02
CANTDSR4_DB1_BIT                        .equ 0x01
CANTDSR4_DB2_MASK                       .equ 0x04
CANTDSR4_DB2_BIT                        .equ 0x02
CANTDSR4_DB3_MASK                       .equ 0x08
CANTDSR4_DB3_BIT                        .equ 0x03
CANTDSR4_DB4_MASK                       .equ 0x10
CANTDSR4_DB4_BIT                        .equ 0x04
CANTDSR4_DB5_MASK                       .equ 0x20
CANTDSR4_DB5_BIT                        .equ 0x05
CANTDSR4_DB6_MASK                       .equ 0x40
CANTDSR4_DB6_BIT                        .equ 0x06
CANTDSR4_DB7_MASK                       .equ 0x80
CANTDSR4_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Transmit Data Segment Register 5
;*********************************************
CANTDSR5                                .equ 0xFFFF98B9 ;  MSCAN Transmit Data Segment Register 5
CANTDSR5_DB0_MASK                       .equ 0x01
CANTDSR5_DB0_BIT                        .equ 0x00
CANTDSR5_DB1_MASK                       .equ 0x02
CANTDSR5_DB1_BIT                        .equ 0x01
CANTDSR5_DB2_MASK                       .equ 0x04
CANTDSR5_DB2_BIT                        .equ 0x02
CANTDSR5_DB3_MASK                       .equ 0x08
CANTDSR5_DB3_BIT                        .equ 0x03
CANTDSR5_DB4_MASK                       .equ 0x10
CANTDSR5_DB4_BIT                        .equ 0x04
CANTDSR5_DB5_MASK                       .equ 0x20
CANTDSR5_DB5_BIT                        .equ 0x05
CANTDSR5_DB6_MASK                       .equ 0x40
CANTDSR5_DB6_BIT                        .equ 0x06
CANTDSR5_DB7_MASK                       .equ 0x80
CANTDSR5_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Transmit Data Segment Register 6
;*********************************************
CANTDSR6                                .equ 0xFFFF98BA ;  MSCAN Transmit Data Segment Register 6
CANTDSR6_DB0_MASK                       .equ 0x01
CANTDSR6_DB0_BIT                        .equ 0x00
CANTDSR6_DB1_MASK                       .equ 0x02
CANTDSR6_DB1_BIT                        .equ 0x01
CANTDSR6_DB2_MASK                       .equ 0x04
CANTDSR6_DB2_BIT                        .equ 0x02
CANTDSR6_DB3_MASK                       .equ 0x08
CANTDSR6_DB3_BIT                        .equ 0x03
CANTDSR6_DB4_MASK                       .equ 0x10
CANTDSR6_DB4_BIT                        .equ 0x04
CANTDSR6_DB5_MASK                       .equ 0x20
CANTDSR6_DB5_BIT                        .equ 0x05
CANTDSR6_DB6_MASK                       .equ 0x40
CANTDSR6_DB6_BIT                        .equ 0x06
CANTDSR6_DB7_MASK                       .equ 0x80
CANTDSR6_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Transmit Data Segment Register 7
;*********************************************
CANTDSR7                                .equ 0xFFFF98BB ;  MSCAN Transmit Data Segment Register 7
CANTDSR7_DB0_MASK                       .equ 0x01
CANTDSR7_DB0_BIT                        .equ 0x00
CANTDSR7_DB1_MASK                       .equ 0x02
CANTDSR7_DB1_BIT                        .equ 0x01
CANTDSR7_DB2_MASK                       .equ 0x04
CANTDSR7_DB2_BIT                        .equ 0x02
CANTDSR7_DB3_MASK                       .equ 0x08
CANTDSR7_DB3_BIT                        .equ 0x03
CANTDSR7_DB4_MASK                       .equ 0x10
CANTDSR7_DB4_BIT                        .equ 0x04
CANTDSR7_DB5_MASK                       .equ 0x20
CANTDSR7_DB5_BIT                        .equ 0x05
CANTDSR7_DB6_MASK                       .equ 0x40
CANTDSR7_DB6_BIT                        .equ 0x06
CANTDSR7_DB7_MASK                       .equ 0x80
CANTDSR7_DB7_BIT                        .equ 0x07

;*********************************************
;  MSCAN Transmit Data Length Register
;*********************************************
CANTDLR                                 .equ 0xFFFF98BC ;  MSCAN Transmit Data Length Register
CANTDLR_DLC0_MASK                       .equ 0x01
CANTDLR_DLC0_BIT                        .equ 0x00
CANTDLR_DLC1_MASK                       .equ 0x02
CANTDLR_DLC1_BIT                        .equ 0x01
CANTDLR_DLC2_MASK                       .equ 0x04
CANTDLR_DLC2_BIT                        .equ 0x02
CANTDLR_DLC3_MASK                       .equ 0x08
CANTDLR_DLC3_BIT                        .equ 0x03
CANTDLR_DLC_MASK                        .equ 0x0F

;*********************************************
;  MSCAN Transmit Buffer Priority
;*********************************************
CANTTBPR                                .equ 0xFFFF98BD ;  MSCAN Transmit Buffer Priority
CANTTBPR_PRIO0_MASK                     .equ 0x01
CANTTBPR_PRIO0_BIT                      .equ 0x00
CANTTBPR_PRIO1_MASK                     .equ 0x02
CANTTBPR_PRIO1_BIT                      .equ 0x01
CANTTBPR_PRIO2_MASK                     .equ 0x04
CANTTBPR_PRIO2_BIT                      .equ 0x02
CANTTBPR_PRIO3_MASK                     .equ 0x08
CANTTBPR_PRIO3_BIT                      .equ 0x03
CANTTBPR_PRIO4_MASK                     .equ 0x10
CANTTBPR_PRIO4_BIT                      .equ 0x04
CANTTBPR_PRIO5_MASK                     .equ 0x20
CANTTBPR_PRIO5_BIT                      .equ 0x05
CANTTBPR_PRIO6_MASK                     .equ 0x40
CANTTBPR_PRIO6_BIT                      .equ 0x06
CANTTBPR_PRIO7_MASK                     .equ 0x80
CANTTBPR_PRIO7_BIT                      .equ 0x07

;*********************************************
;  MSCAN Transmit Time Stamp Register
;*********************************************
CANTTSRH_TSR8_MASK                      .equ 0x01
CANTTSRH_TSR8_BIT                       .equ 0x00
CANTTSRH_TSR9_MASK                      .equ 0x02
CANTTSRH_TSR9_BIT                       .equ 0x01
CANTTSRH_TSR10_MASK                     .equ 0x04
CANTTSRH_TSR10_BIT                      .equ 0x02
CANTTSRH_TSR11_MASK                     .equ 0x08
CANTTSRH_TSR11_BIT                      .equ 0x03
CANTTSRH_TSR12_MASK                     .equ 0x10
CANTTSRH_TSR12_BIT                      .equ 0x04
CANTTSRH_TSR13_MASK                     .equ 0x20
CANTTSRH_TSR13_BIT                      .equ 0x05
CANTTSRH_TSR14_MASK                     .equ 0x40
CANTTSRH_TSR14_BIT                      .equ 0x06
CANTTSRH_TSR15_MASK                     .equ 0x80
CANTTSRH_TSR15_BIT                      .equ 0x07
CANTTSRL_TSR0_MASK                      .equ 0x01
CANTTSRL_TSR0_BIT                       .equ 0x00
CANTTSRL_TSR1_MASK                      .equ 0x02
CANTTSRL_TSR1_BIT                       .equ 0x01
CANTTSRL_TSR2_MASK                      .equ 0x04
CANTTSRL_TSR2_BIT                       .equ 0x02
CANTTSRL_TSR3_MASK                      .equ 0x08
CANTTSRL_TSR3_BIT                       .equ 0x03
CANTTSRL_TSR4_MASK                      .equ 0x10
CANTTSRL_TSR4_BIT                       .equ 0x04
CANTTSRL_TSR5_MASK                      .equ 0x20
CANTTSRL_TSR5_BIT                       .equ 0x05
CANTTSRL_TSR6_MASK                      .equ 0x40
CANTTSRL_TSR6_BIT                       .equ 0x06
CANTTSRL_TSR7_MASK                      .equ 0x80
CANTTSRL_TSR7_BIT                       .equ 0x07
CANTTSR                                 .equ 0xFFFF98BE ;  MSCAN Transmit Time Stamp Register
CANTTSR_TSR0_MASK                       .equ 0x01
CANTTSR_TSR0_BIT                        .equ 0x00
CANTTSR_TSR1_MASK                       .equ 0x02
CANTTSR_TSR1_BIT                        .equ 0x01
CANTTSR_TSR2_MASK                       .equ 0x04
CANTTSR_TSR2_BIT                        .equ 0x02
CANTTSR_TSR3_MASK                       .equ 0x08
CANTTSR_TSR3_BIT                        .equ 0x03
CANTTSR_TSR4_MASK                       .equ 0x10
CANTTSR_TSR4_BIT                        .equ 0x04
CANTTSR_TSR5_MASK                       .equ 0x20
CANTTSR_TSR5_BIT                        .equ 0x05
CANTTSR_TSR6_MASK                       .equ 0x40
CANTTSR_TSR6_BIT                        .equ 0x06
CANTTSR_TSR7_MASK                       .equ 0x80
CANTTSR_TSR7_BIT                        .equ 0x07
CANTTSR_TSR8_MASK                       .equ 0x100
CANTTSR_TSR8_BIT                        .equ 0x08
CANTTSR_TSR9_MASK                       .equ 0x200
CANTTSR_TSR9_BIT                        .equ 0x09
CANTTSR_TSR10_MASK                      .equ 0x400
CANTTSR_TSR10_BIT                       .equ 0x0A
CANTTSR_TSR11_MASK                      .equ 0x800
CANTTSR_TSR11_BIT                       .equ 0x0B
CANTTSR_TSR12_MASK                      .equ 0x1000
CANTTSR_TSR12_BIT                       .equ 0x0C
CANTTSR_TSR13_MASK                      .equ 0x2000
CANTTSR_TSR13_BIT                       .equ 0x0D
CANTTSR_TSR14_MASK                      .equ 0x4000
CANTTSR_TSR14_BIT                       .equ 0x0E
CANTTSR_TSR15_MASK                      .equ 0x8000
CANTTSR_TSR15_BIT                       .equ 0x0F

;*********************************************
;  Control Register
;*********************************************
RNGCR                                   .equ 0xFFFF98C0 ;  Control Register
RNGCR_GO_MASK                           .equ 0x01
RNGCR_GO_BIT                            .equ 0x00
RNGCR_HA_MASK                           .equ 0x02
RNGCR_HA_BIT                            .equ 0x01
RNGCR_IM_MASK                           .equ 0x04
RNGCR_IM_BIT                            .equ 0x02
RNGCR_CI_MASK                           .equ 0x08
RNGCR_CI_BIT                            .equ 0x03
RNGCR_SLM_MASK                          .equ 0x10
RNGCR_SLM_BIT                           .equ 0x04

;*********************************************
;  Status Register
;*********************************************
RNGSR                                   .equ 0xFFFF98C4 ;  Status Register
RNGSR_SV_MASK                           .equ 0x01
RNGSR_SV_BIT                            .equ 0x00
RNGSR_LRS_MASK                          .equ 0x02
RNGSR_LRS_BIT                           .equ 0x01
RNGSR_OUF_MASK                          .equ 0x04
RNGSR_OUF_BIT                           .equ 0x02
RNGSR_EI_MASK                           .equ 0x08
RNGSR_EI_BIT                            .equ 0x03
RNGSR_SLP_MASK                          .equ 0x10
RNGSR_SLP_BIT                           .equ 0x04
RNGSR_ORL0_MASK                         .equ 0x100
RNGSR_ORL0_BIT                          .equ 0x08
RNGSR_ORL1_MASK                         .equ 0x200
RNGSR_ORL1_BIT                          .equ 0x09
RNGSR_ORL2_MASK                         .equ 0x400
RNGSR_ORL2_BIT                          .equ 0x0A
RNGSR_ORL3_MASK                         .equ 0x800
RNGSR_ORL3_BIT                          .equ 0x0B
RNGSR_ORL4_MASK                         .equ 0x1000
RNGSR_ORL4_BIT                          .equ 0x0C
RNGSR_ORL5_MASK                         .equ 0x2000
RNGSR_ORL5_BIT                          .equ 0x0D
RNGSR_ORL6_MASK                         .equ 0x4000
RNGSR_ORL6_BIT                          .equ 0x0E
RNGSR_ORL7_MASK                         .equ 0x8000
RNGSR_ORL7_BIT                          .equ 0x0F
RNGSR_ORS0_MASK                         .equ 0x10000
RNGSR_ORS0_BIT                          .equ 0x10
RNGSR_ORS1_MASK                         .equ 0x20000
RNGSR_ORS1_BIT                          .equ 0x11
RNGSR_ORS2_MASK                         .equ 0x40000
RNGSR_ORS2_BIT                          .equ 0x12
RNGSR_ORS3_MASK                         .equ 0x80000
RNGSR_ORS3_BIT                          .equ 0x13
RNGSR_ORS4_MASK                         .equ 0x100000
RNGSR_ORS4_BIT                          .equ 0x14
RNGSR_ORS5_MASK                         .equ 0x200000
RNGSR_ORS5_BIT                          .equ 0x15
RNGSR_ORS6_MASK                         .equ 0x400000
RNGSR_ORS6_BIT                          .equ 0x16
RNGSR_ORS7_MASK                         .equ 0x800000
RNGSR_ORS7_BIT                          .equ 0x17
RNGSR_OD_MASK                           .equ 0x80000000
RNGSR_OD_BIT                            .equ 0x1F
RNGSR_ORL_MASK                          .equ 0xFF00
RNGSR_ORS_MASK                          .equ 0xFF0000

;*********************************************
;  Entropy Register
;*********************************************
RNGER                                   .equ 0xFFFF98C8 ;  Entropy Register
RNGER_ENT0_MASK                         .equ 0x01
RNGER_ENT0_BIT                          .equ 0x00
RNGER_ENT1_MASK                         .equ 0x02
RNGER_ENT1_BIT                          .equ 0x01
RNGER_ENT2_MASK                         .equ 0x04
RNGER_ENT2_BIT                          .equ 0x02
RNGER_ENT3_MASK                         .equ 0x08
RNGER_ENT3_BIT                          .equ 0x03
RNGER_ENT4_MASK                         .equ 0x10
RNGER_ENT4_BIT                          .equ 0x04
RNGER_ENT5_MASK                         .equ 0x20
RNGER_ENT5_BIT                          .equ 0x05
RNGER_ENT6_MASK                         .equ 0x40
RNGER_ENT6_BIT                          .equ 0x06
RNGER_ENT7_MASK                         .equ 0x80
RNGER_ENT7_BIT                          .equ 0x07
RNGER_ENT8_MASK                         .equ 0x100
RNGER_ENT8_BIT                          .equ 0x08
RNGER_ENT9_MASK                         .equ 0x200
RNGER_ENT9_BIT                          .equ 0x09
RNGER_ENT10_MASK                        .equ 0x400
RNGER_ENT10_BIT                         .equ 0x0A
RNGER_ENT11_MASK                        .equ 0x800
RNGER_ENT11_BIT                         .equ 0x0B
RNGER_ENT12_MASK                        .equ 0x1000
RNGER_ENT12_BIT                         .equ 0x0C
RNGER_ENT13_MASK                        .equ 0x2000
RNGER_ENT13_BIT                         .equ 0x0D
RNGER_ENT14_MASK                        .equ 0x4000
RNGER_ENT14_BIT                         .equ 0x0E
RNGER_ENT15_MASK                        .equ 0x8000
RNGER_ENT15_BIT                         .equ 0x0F
RNGER_ENT16_MASK                        .equ 0x10000
RNGER_ENT16_BIT                         .equ 0x10
RNGER_ENT17_MASK                        .equ 0x20000
RNGER_ENT17_BIT                         .equ 0x11
RNGER_ENT18_MASK                        .equ 0x40000
RNGER_ENT18_BIT                         .equ 0x12
RNGER_ENT19_MASK                        .equ 0x80000
RNGER_ENT19_BIT                         .equ 0x13
RNGER_ENT20_MASK                        .equ 0x100000
RNGER_ENT20_BIT                         .equ 0x14
RNGER_ENT21_MASK                        .equ 0x200000
RNGER_ENT21_BIT                         .equ 0x15
RNGER_ENT22_MASK                        .equ 0x400000
RNGER_ENT22_BIT                         .equ 0x16
RNGER_ENT23_MASK                        .equ 0x800000
RNGER_ENT23_BIT                         .equ 0x17
RNGER_ENT24_MASK                        .equ 0x1000000
RNGER_ENT24_BIT                         .equ 0x18
RNGER_ENT25_MASK                        .equ 0x2000000
RNGER_ENT25_BIT                         .equ 0x19
RNGER_ENT26_MASK                        .equ 0x4000000
RNGER_ENT26_BIT                         .equ 0x1A
RNGER_ENT27_MASK                        .equ 0x8000000
RNGER_ENT27_BIT                         .equ 0x1B
RNGER_ENT28_MASK                        .equ 0x10000000
RNGER_ENT28_BIT                         .equ 0x1C
RNGER_ENT29_MASK                        .equ 0x20000000
RNGER_ENT29_BIT                         .equ 0x1D
RNGER_ENT30_MASK                        .equ 0x40000000
RNGER_ENT30_BIT                         .equ 0x1E
RNGER_ENT31_MASK                        .equ 0x80000000
RNGER_ENT31_BIT                         .equ 0x1F

;*********************************************
;  Output Register
;*********************************************
RNGOUT                                  .equ 0xFFFF98CC ;  Output Register
RNGOUT_RANDOM_OUTPUT0_MASK              .equ 0x01
RNGOUT_RANDOM_OUTPUT0_BIT               .equ 0x00
RNGOUT_RANDOM_OUTPUT1_MASK              .equ 0x02
RNGOUT_RANDOM_OUTPUT1_BIT               .equ 0x01
RNGOUT_RANDOM_OUTPUT2_MASK              .equ 0x04
RNGOUT_RANDOM_OUTPUT2_BIT               .equ 0x02
RNGOUT_RANDOM_OUTPUT3_MASK              .equ 0x08
RNGOUT_RANDOM_OUTPUT3_BIT               .equ 0x03
RNGOUT_RANDOM_OUTPUT4_MASK              .equ 0x10
RNGOUT_RANDOM_OUTPUT4_BIT               .equ 0x04
RNGOUT_RANDOM_OUTPUT5_MASK              .equ 0x20
RNGOUT_RANDOM_OUTPUT5_BIT               .equ 0x05
RNGOUT_RANDOM_OUTPUT6_MASK              .equ 0x40
RNGOUT_RANDOM_OUTPUT6_BIT               .equ 0x06
RNGOUT_RANDOM_OUTPUT7_MASK              .equ 0x80
RNGOUT_RANDOM_OUTPUT7_BIT               .equ 0x07
RNGOUT_RANDOM_OUTPUT8_MASK              .equ 0x100
RNGOUT_RANDOM_OUTPUT8_BIT               .equ 0x08
RNGOUT_RANDOM_OUTPUT9_MASK              .equ 0x200
RNGOUT_RANDOM_OUTPUT9_BIT               .equ 0x09
RNGOUT_RANDOM_OUTPUT10_MASK             .equ 0x400
RNGOUT_RANDOM_OUTPUT10_BIT              .equ 0x0A
RNGOUT_RANDOM_OUTPUT11_MASK             .equ 0x800
RNGOUT_RANDOM_OUTPUT11_BIT              .equ 0x0B
RNGOUT_RANDOM_OUTPUT12_MASK             .equ 0x1000
RNGOUT_RANDOM_OUTPUT12_BIT              .equ 0x0C
RNGOUT_RANDOM_OUTPUT13_MASK             .equ 0x2000
RNGOUT_RANDOM_OUTPUT13_BIT              .equ 0x0D
RNGOUT_RANDOM_OUTPUT14_MASK             .equ 0x4000
RNGOUT_RANDOM_OUTPUT14_BIT              .equ 0x0E
RNGOUT_RANDOM_OUTPUT15_MASK             .equ 0x8000
RNGOUT_RANDOM_OUTPUT15_BIT              .equ 0x0F
RNGOUT_RANDOM_OUTPUT16_MASK             .equ 0x10000
RNGOUT_RANDOM_OUTPUT16_BIT              .equ 0x10
RNGOUT_RANDOM_OUTPUT17_MASK             .equ 0x20000
RNGOUT_RANDOM_OUTPUT17_BIT              .equ 0x11
RNGOUT_RANDOM_OUTPUT18_MASK             .equ 0x40000
RNGOUT_RANDOM_OUTPUT18_BIT              .equ 0x12
RNGOUT_RANDOM_OUTPUT19_MASK             .equ 0x80000
RNGOUT_RANDOM_OUTPUT19_BIT              .equ 0x13
RNGOUT_RANDOM_OUTPUT20_MASK             .equ 0x100000
RNGOUT_RANDOM_OUTPUT20_BIT              .equ 0x14
RNGOUT_RANDOM_OUTPUT21_MASK             .equ 0x200000
RNGOUT_RANDOM_OUTPUT21_BIT              .equ 0x15
RNGOUT_RANDOM_OUTPUT22_MASK             .equ 0x400000
RNGOUT_RANDOM_OUTPUT22_BIT              .equ 0x16
RNGOUT_RANDOM_OUTPUT23_MASK             .equ 0x800000
RNGOUT_RANDOM_OUTPUT23_BIT              .equ 0x17
RNGOUT_RANDOM_OUTPUT24_MASK             .equ 0x1000000
RNGOUT_RANDOM_OUTPUT24_BIT              .equ 0x18
RNGOUT_RANDOM_OUTPUT25_MASK             .equ 0x2000000
RNGOUT_RANDOM_OUTPUT25_BIT              .equ 0x19
RNGOUT_RANDOM_OUTPUT26_MASK             .equ 0x4000000
RNGOUT_RANDOM_OUTPUT26_BIT              .equ 0x1A
RNGOUT_RANDOM_OUTPUT27_MASK             .equ 0x8000000
RNGOUT_RANDOM_OUTPUT27_BIT              .equ 0x1B
RNGOUT_RANDOM_OUTPUT28_MASK             .equ 0x10000000
RNGOUT_RANDOM_OUTPUT28_BIT              .equ 0x1C
RNGOUT_RANDOM_OUTPUT29_MASK             .equ 0x20000000
RNGOUT_RANDOM_OUTPUT29_BIT              .equ 0x1D
RNGOUT_RANDOM_OUTPUT30_MASK             .equ 0x40000000
RNGOUT_RANDOM_OUTPUT30_BIT              .equ 0x1E
RNGOUT_RANDOM_OUTPUT31_MASK             .equ 0x80000000
RNGOUT_RANDOM_OUTPUT31_BIT              .equ 0x1F

;*********************************************
;  Peripherial ID Register
;*********************************************
PER_ID                                  .equ 0xFFFF9A00 ;  Peripherial ID Register
PER_ID_ID0_MASK                         .equ 0x01
PER_ID_ID0_BIT                          .equ 0x00
PER_ID_ID1_MASK                         .equ 0x02
PER_ID_ID1_BIT                          .equ 0x01
PER_ID_ID2_MASK                         .equ 0x04
PER_ID_ID2_BIT                          .equ 0x02
PER_ID_ID3_MASK                         .equ 0x08
PER_ID_ID3_BIT                          .equ 0x03
PER_ID_ID4_MASK                         .equ 0x10
PER_ID_ID4_BIT                          .equ 0x04
PER_ID_ID5_MASK                         .equ 0x20
PER_ID_ID5_BIT                          .equ 0x05
PER_ID_ID_MASK                          .equ 0x3F

;*********************************************
;  Peripheral ID Complement Register
;*********************************************
ID_COMP                                 .equ 0xFFFF9A04 ;  Peripheral ID Complement Register
ID_COMP_NID0_MASK                       .equ 0x01
ID_COMP_NID0_BIT                        .equ 0x00
ID_COMP_NID1_MASK                       .equ 0x02
ID_COMP_NID1_BIT                        .equ 0x01
ID_COMP_NID2_MASK                       .equ 0x04
ID_COMP_NID2_BIT                        .equ 0x02
ID_COMP_NID3_MASK                       .equ 0x08
ID_COMP_NID3_BIT                        .equ 0x03
ID_COMP_NID4_MASK                       .equ 0x10
ID_COMP_NID4_BIT                        .equ 0x04
ID_COMP_NID5_MASK                       .equ 0x20
ID_COMP_NID5_BIT                        .equ 0x05
ID_COMP_NID_MASK                        .equ 0x3F

;*********************************************
;  Peripheral Revision Register
;*********************************************
REV                                     .equ 0xFFFF9A08 ;  Peripheral Revision Register

;*********************************************
;  Peripheral Additional Info Register
;*********************************************
ADD_INFO                                .equ 0xFFFF9A0C ;  Peripheral Additional Info Register
ADD_INFO_IEHOST_MASK                    .equ 0x01
ADD_INFO_IEHOST_BIT                     .equ 0x00
ADD_INFO_IRQ_NUM0_MASK                  .equ 0x08
ADD_INFO_IRQ_NUM0_BIT                   .equ 0x03
ADD_INFO_IRQ_NUM1_MASK                  .equ 0x10
ADD_INFO_IRQ_NUM1_BIT                   .equ 0x04
ADD_INFO_IRQ_NUM2_MASK                  .equ 0x20
ADD_INFO_IRQ_NUM2_BIT                   .equ 0x05
ADD_INFO_IRQ_NUM3_MASK                  .equ 0x40
ADD_INFO_IRQ_NUM3_BIT                   .equ 0x06
ADD_INFO_IRQ_NUM4_MASK                  .equ 0x80
ADD_INFO_IRQ_NUM4_BIT                   .equ 0x07
ADD_INFO_IRQ_NUM_MASK                   .equ 0xF8

;*********************************************
;  OTG Interrupt Status Register
;*********************************************
OTG_INT_STAT                            .equ 0xFFFF9A10 ;  OTG Interrupt Status Register
OTG_INT_STAT_A_VBUS_CHG_MASK            .equ 0x01
OTG_INT_STAT_A_VBUS_CHG_BIT             .equ 0x00
OTG_INT_STAT_B_SESS_CHG_MASK            .equ 0x04
OTG_INT_STAT_B_SESS_CHG_BIT             .equ 0x02
OTG_INT_STAT_SESS_VLD_CHG_MASK          .equ 0x08
OTG_INT_STAT_SESS_VLD_CHG_BIT           .equ 0x03
OTG_INT_STAT_LINE_STATE_CHG_MASK        .equ 0x20
OTG_INT_STAT_LINE_STATE_CHG_BIT         .equ 0x05
OTG_INT_STAT_ONE_MSEC_MASK              .equ 0x40
OTG_INT_STAT_ONE_MSEC_BIT               .equ 0x06
OTG_INT_STAT_ID_CHG_MASK                .equ 0x80
OTG_INT_STAT_ID_CHG_BIT                 .equ 0x07

;*********************************************
;  OTG Interrupt Control Register
;*********************************************
OTG_INT_EN                              .equ 0xFFFF9A14 ;  OTG Interrupt Control Register
OTG_INT_EN_A_VBUS_EN_MASK               .equ 0x01
OTG_INT_EN_A_VBUS_EN_BIT                .equ 0x00
OTG_INT_EN_B_SESS_EN_MASK               .equ 0x04
OTG_INT_EN_B_SESS_EN_BIT                .equ 0x02
OTG_INT_EN_SESS_VLD_EN_MASK             .equ 0x08
OTG_INT_EN_SESS_VLD_EN_BIT              .equ 0x03
OTG_INT_EN_LINE_STATE_EN_MASK           .equ 0x20
OTG_INT_EN_LINE_STATE_EN_BIT            .equ 0x05
OTG_INT_EN_ONE_MSEC_EN_MASK             .equ 0x40
OTG_INT_EN_ONE_MSEC_EN_BIT              .equ 0x06
OTG_INT_EN_ID_EN_MASK                   .equ 0x80
OTG_INT_EN_ID_EN_BIT                    .equ 0x07

;*********************************************
;  Interrupt Status Register
;*********************************************
OTG_STAT                                .equ 0xFFFF9A18 ;  Interrupt Status Register
OTG_STAT_A_VBUS_VLD_MASK                .equ 0x01
OTG_STAT_A_VBUS_VLD_BIT                 .equ 0x00
OTG_STAT_B_SESS_END_MASK                .equ 0x04
OTG_STAT_B_SESS_END_BIT                 .equ 0x02
OTG_STAT_SESS_VLD_MASK                  .equ 0x08
OTG_STAT_SESS_VLD_BIT                   .equ 0x03
OTG_STAT_LINE_STATE_STABLE_MASK         .equ 0x20
OTG_STAT_LINE_STATE_STABLE_BIT          .equ 0x05
OTG_STAT_ONE_MSEC_EN_MASK               .equ 0x40
OTG_STAT_ONE_MSEC_EN_BIT                .equ 0x06
OTG_STAT_ID_MASK                        .equ 0x80
OTG_STAT_ID_BIT                         .equ 0x07

;*********************************************
;  OTG Control Register
;*********************************************
OTG_CTRL                                .equ 0xFFFF9A1C ;  OTG Control Register
OTG_CTRL_OTG_EN_MASK                    .equ 0x04
OTG_CTRL_OTG_EN_BIT                     .equ 0x02
OTG_CTRL_DM_LOW_MASK                    .equ 0x10
OTG_CTRL_DM_LOW_BIT                     .equ 0x04
OTG_CTRL_DP_LOW_MASK                    .equ 0x20
OTG_CTRL_DP_LOW_BIT                     .equ 0x05
OTG_CTRL_DP_HIGH_MASK                   .equ 0x80
OTG_CTRL_DP_HIGH_BIT                    .equ 0x07

;*********************************************
;  Interrupt Status Register
;*********************************************
INT_STAT                                .equ 0xFFFF9A80 ;  Interrupt Status Register
INT_STAT_USB_RST_MASK                   .equ 0x01
INT_STAT_USB_RST_BIT                    .equ 0x00
INT_STAT_ERROR_MASK                     .equ 0x02
INT_STAT_ERROR_BIT                      .equ 0x01
INT_STAT_SOF_TOK_MASK                   .equ 0x04
INT_STAT_SOF_TOK_BIT                    .equ 0x02
INT_STAT_TOK_DNE_MASK                   .equ 0x08
INT_STAT_TOK_DNE_BIT                    .equ 0x03
INT_STAT_SLEEP_MASK                     .equ 0x10
INT_STAT_SLEEP_BIT                      .equ 0x04
INT_STAT_RESUME_MASK                    .equ 0x20
INT_STAT_RESUME_BIT                     .equ 0x05
INT_STAT_ATTACH_MASK                    .equ 0x40
INT_STAT_ATTACH_BIT                     .equ 0x06
INT_STAT_STALL_MASK                     .equ 0x80
INT_STAT_STALL_BIT                      .equ 0x07

;*********************************************
;  Interrupt Enable Register
;*********************************************
INT_ENB                                 .equ 0xFFFF9A84 ;  Interrupt Enable Register
INT_ENB_USB_RST_EN_MASK                 .equ 0x01
INT_ENB_USB_RST_EN_BIT                  .equ 0x00
INT_ENB_ERROR_EN_MASK                   .equ 0x02
INT_ENB_ERROR_EN_BIT                    .equ 0x01
INT_ENB_SOF_TOK_EN_MASK                 .equ 0x04
INT_ENB_SOF_TOK_EN_BIT                  .equ 0x02
INT_ENB_TOK_DNE_EN_MASK                 .equ 0x08
INT_ENB_TOK_DNE_EN_BIT                  .equ 0x03
INT_ENB_SLEEP_EN_MASK                   .equ 0x10
INT_ENB_SLEEP_EN_BIT                    .equ 0x04
INT_ENB_RESUME_EN_MASK                  .equ 0x20
INT_ENB_RESUME_EN_BIT                   .equ 0x05
INT_ENB_ATTACH_EN_MASK                  .equ 0x40
INT_ENB_ATTACH_EN_BIT                   .equ 0x06
INT_ENB_STALL_EN_MASK                   .equ 0x80
INT_ENB_STALL_EN_BIT                    .equ 0x07

;*********************************************
;  Error Interrupt Status Register
;*********************************************
ERR_STAT                                .equ 0xFFFF9A88 ;  Error Interrupt Status Register
ERR_STAT_PID_ERR_MASK                   .equ 0x01
ERR_STAT_PID_ERR_BIT                    .equ 0x00
ERR_STAT_CRC5_EOF_MASK                  .equ 0x02
ERR_STAT_CRC5_EOF_BIT                   .equ 0x01
ERR_STAT_CRC16_MASK                     .equ 0x04
ERR_STAT_CRC16_BIT                      .equ 0x02
ERR_STAT_DFN8_MASK                      .equ 0x08
ERR_STAT_DFN8_BIT                       .equ 0x03
ERR_STAT_BTO_ERR_MASK                   .equ 0x10
ERR_STAT_BTO_ERR_BIT                    .equ 0x04
ERR_STAT_DMA_ERR_MASK                   .equ 0x20
ERR_STAT_DMA_ERR_BIT                    .equ 0x05
ERR_STAT_BTS_ERR_MASK                   .equ 0x80
ERR_STAT_BTS_ERR_BIT                    .equ 0x07

;*********************************************
;  Error Interrupt Enable Register
;*********************************************
ERR_ENB                                 .equ 0xFFFF9A8C ;  Error Interrupt Enable Register
ERR_ENB_PID_ERR_EN_MASK                 .equ 0x01
ERR_ENB_PID_ERR_EN_BIT                  .equ 0x00
ERR_ENB_CRC5_EOF_EN_MASK                .equ 0x02
ERR_ENB_CRC5_EOF_EN_BIT                 .equ 0x01
ERR_ENB_CRC16_EN_MASK                   .equ 0x04
ERR_ENB_CRC16_EN_BIT                    .equ 0x02
ERR_ENB_DFN8_EN_MASK                    .equ 0x08
ERR_ENB_DFN8_EN_BIT                     .equ 0x03
ERR_ENB_BTO_ERR_EN_MASK                 .equ 0x10
ERR_ENB_BTO_ERR_EN_BIT                  .equ 0x04
ERR_ENB_DMA_ERR_EN_MASK                 .equ 0x20
ERR_ENB_DMA_ERR_EN_BIT                  .equ 0x05
ERR_ENB_BTS_ERR_EN_MASK                 .equ 0x80
ERR_ENB_BTS_ERR_EN_BIT                  .equ 0x07

;*********************************************
;  Status Register
;*********************************************
STAT                                    .equ 0xFFFF9A90 ;  Status Register
STAT_ODD_MASK                           .equ 0x04
STAT_ODD_BIT                            .equ 0x02
STAT_TX_MASK                            .equ 0x08
STAT_TX_BIT                             .equ 0x03
STAT_ENDP0_MASK                         .equ 0x10
STAT_ENDP0_BIT                          .equ 0x04
STAT_ENDP1_MASK                         .equ 0x20
STAT_ENDP1_BIT                          .equ 0x05
STAT_ENDP2_MASK                         .equ 0x40
STAT_ENDP2_BIT                          .equ 0x06
STAT_ENDP3_MASK                         .equ 0x80
STAT_ENDP3_BIT                          .equ 0x07
STAT_ENDP_MASK                          .equ 0xF0

;*********************************************
;  Control Register
;*********************************************
CTL                                     .equ 0xFFFF9A94 ;  Control Register
CTL_USB_EN_SOF_EN_MASK                  .equ 0x01
CTL_USB_EN_SOF_EN_BIT                   .equ 0x00
CTL_ODD_RST_MASK                        .equ 0x02
CTL_ODD_RST_BIT                         .equ 0x01
CTL_RESUME_MASK                         .equ 0x04
CTL_RESUME_BIT                          .equ 0x02
CTL_HOST_MODE_EN_MASK                   .equ 0x08
CTL_HOST_MODE_EN_BIT                    .equ 0x03
CTL_RESET_MASK                          .equ 0x10
CTL_RESET_BIT                           .equ 0x04
CTL_TXSUSPEND_TOKENBUSY_MASK            .equ 0x20
CTL_TXSUSPEND_TOKENBUSY_BIT             .equ 0x05
CTL_SE0_MASK                            .equ 0x40
CTL_SE0_BIT                             .equ 0x06
CTL_JSTATE_MASK                         .equ 0x80
CTL_JSTATE_BIT                          .equ 0x07

;*********************************************
;  Address Register
;*********************************************
ADDR                                    .equ 0xFFFF9A98 ;  Address Register
ADDR_ADDR0_MASK                         .equ 0x01
ADDR_ADDR0_BIT                          .equ 0x00
ADDR_ADDR1_MASK                         .equ 0x02
ADDR_ADDR1_BIT                          .equ 0x01
ADDR_ADDR2_MASK                         .equ 0x04
ADDR_ADDR2_BIT                          .equ 0x02
ADDR_ADDR3_MASK                         .equ 0x08
ADDR_ADDR3_BIT                          .equ 0x03
ADDR_ADDR4_MASK                         .equ 0x10
ADDR_ADDR4_BIT                          .equ 0x04
ADDR_ADDR5_MASK                         .equ 0x20
ADDR_ADDR5_BIT                          .equ 0x05
ADDR_ADDR6_MASK                         .equ 0x40
ADDR_ADDR6_BIT                          .equ 0x06
ADDR_LS_EN_MASK                         .equ 0x80
ADDR_LS_EN_BIT                          .equ 0x07
ADDR_ADDR_MASK                          .equ 0x7F

;*********************************************
;  BDT Page Register 1
;*********************************************
BDT_PAGE_01                             .equ 0xFFFF9A9C ;  BDT Page Register 1
BDT_PAGE_01_BDT_BA9_MASK                .equ 0x02
BDT_PAGE_01_BDT_BA9_BIT                 .equ 0x01
BDT_PAGE_01_BDT_BA10_MASK               .equ 0x04
BDT_PAGE_01_BDT_BA10_BIT                .equ 0x02
BDT_PAGE_01_BDT_BA11_MASK               .equ 0x08
BDT_PAGE_01_BDT_BA11_BIT                .equ 0x03
BDT_PAGE_01_BDT_BA12_MASK               .equ 0x10
BDT_PAGE_01_BDT_BA12_BIT                .equ 0x04
BDT_PAGE_01_BDT_BA13_MASK               .equ 0x20
BDT_PAGE_01_BDT_BA13_BIT                .equ 0x05
BDT_PAGE_01_BDT_BA14_MASK               .equ 0x40
BDT_PAGE_01_BDT_BA14_BIT                .equ 0x06
BDT_PAGE_01_BDT_BA15_MASK               .equ 0x80
BDT_PAGE_01_BDT_BA15_BIT                .equ 0x07
BDT_PAGE_01_BDT_BA_9_MASK               .equ 0xFE

;*********************************************
;  Frame Number Register Low
;*********************************************
FRM_NUML                                .equ 0xFFFF9AA0 ;  Frame Number Register Low
FRM_NUML_FRM0_MASK                      .equ 0x01
FRM_NUML_FRM0_BIT                       .equ 0x00
FRM_NUML_FRM1_MASK                      .equ 0x02
FRM_NUML_FRM1_BIT                       .equ 0x01
FRM_NUML_FRM2_MASK                      .equ 0x04
FRM_NUML_FRM2_BIT                       .equ 0x02
FRM_NUML_FRM3_MASK                      .equ 0x08
FRM_NUML_FRM3_BIT                       .equ 0x03
FRM_NUML_FRM4_MASK                      .equ 0x10
FRM_NUML_FRM4_BIT                       .equ 0x04
FRM_NUML_FRM5_MASK                      .equ 0x20
FRM_NUML_FRM5_BIT                       .equ 0x05
FRM_NUML_FRM6_MASK                      .equ 0x40
FRM_NUML_FRM6_BIT                       .equ 0x06
FRM_NUML_FRM7_MASK                      .equ 0x80
FRM_NUML_FRM7_BIT                       .equ 0x07

;*********************************************
;  Frame Number Register High
;*********************************************
FRM_NUMH                                .equ 0xFFFF9AA4 ;  Frame Number Register High
FRM_NUMH_FRM8_MASK                      .equ 0x01
FRM_NUMH_FRM8_BIT                       .equ 0x00
FRM_NUMH_FRM9_MASK                      .equ 0x02
FRM_NUMH_FRM9_BIT                       .equ 0x01
FRM_NUMH_FRM10_MASK                     .equ 0x04
FRM_NUMH_FRM10_BIT                      .equ 0x02
FRM_NUMH_FRM_8_MASK                     .equ 0x07

;*********************************************
;  Token Register
;*********************************************
TOKEN                                   .equ 0xFFFF9AA8 ;  Token Register
TOKEN_TOKEN_ENDPT0_MASK                 .equ 0x01
TOKEN_TOKEN_ENDPT0_BIT                  .equ 0x00
TOKEN_TOKEN_ENDPT1_MASK                 .equ 0x02
TOKEN_TOKEN_ENDPT1_BIT                  .equ 0x01
TOKEN_TOKEN_ENDPT2_MASK                 .equ 0x04
TOKEN_TOKEN_ENDPT2_BIT                  .equ 0x02
TOKEN_TOKEN_ENDPT3_MASK                 .equ 0x08
TOKEN_TOKEN_ENDPT3_BIT                  .equ 0x03
TOKEN_TOKEN_PID0_MASK                   .equ 0x10
TOKEN_TOKEN_PID0_BIT                    .equ 0x04
TOKEN_TOKEN_PID1_MASK                   .equ 0x20
TOKEN_TOKEN_PID1_BIT                    .equ 0x05
TOKEN_TOKEN_PID2_MASK                   .equ 0x40
TOKEN_TOKEN_PID2_BIT                    .equ 0x06
TOKEN_TOKEN_PID3_MASK                   .equ 0x80
TOKEN_TOKEN_PID3_BIT                    .equ 0x07
TOKEN_TOKEN_ENDPT_MASK                  .equ 0x0F
TOKEN_TOKEN_PID_MASK                    .equ 0xF0

;*********************************************
;  SOF Threshold Register
;*********************************************
SOF_THLD                                .equ 0xFFFF9AAC ;  SOF Threshold Register
SOF_THLD_CNT0_MASK                      .equ 0x01
SOF_THLD_CNT0_BIT                       .equ 0x00
SOF_THLD_CNT1_MASK                      .equ 0x02
SOF_THLD_CNT1_BIT                       .equ 0x01
SOF_THLD_CNT2_MASK                      .equ 0x04
SOF_THLD_CNT2_BIT                       .equ 0x02
SOF_THLD_CNT3_MASK                      .equ 0x08
SOF_THLD_CNT3_BIT                       .equ 0x03
SOF_THLD_CNT4_MASK                      .equ 0x10
SOF_THLD_CNT4_BIT                       .equ 0x04
SOF_THLD_CNT5_MASK                      .equ 0x20
SOF_THLD_CNT5_BIT                       .equ 0x05
SOF_THLD_CNT6_MASK                      .equ 0x40
SOF_THLD_CNT6_BIT                       .equ 0x06
SOF_THLD_CNT7_MASK                      .equ 0x80
SOF_THLD_CNT7_BIT                       .equ 0x07

;*********************************************
;  BDT Page Register 2
;*********************************************
BDT_PAGE_02                             .equ 0xFFFF9AB0 ;  BDT Page Register 2
BDT_PAGE_02_BDT_BA16_MASK               .equ 0x01
BDT_PAGE_02_BDT_BA16_BIT                .equ 0x00
BDT_PAGE_02_BDT_BA17_MASK               .equ 0x02
BDT_PAGE_02_BDT_BA17_BIT                .equ 0x01
BDT_PAGE_02_BDT_BA18_MASK               .equ 0x04
BDT_PAGE_02_BDT_BA18_BIT                .equ 0x02
BDT_PAGE_02_BDT_BA19_MASK               .equ 0x08
BDT_PAGE_02_BDT_BA19_BIT                .equ 0x03
BDT_PAGE_02_BDT_BA20_MASK               .equ 0x10
BDT_PAGE_02_BDT_BA20_BIT                .equ 0x04
BDT_PAGE_02_BDT_BA21_MASK               .equ 0x20
BDT_PAGE_02_BDT_BA21_BIT                .equ 0x05
BDT_PAGE_02_BDT_BA22_MASK               .equ 0x40
BDT_PAGE_02_BDT_BA22_BIT                .equ 0x06
BDT_PAGE_02_BDT_BA23_MASK               .equ 0x80
BDT_PAGE_02_BDT_BA23_BIT                .equ 0x07

;*********************************************
;  BDT Page Register 3
;*********************************************
BDT_PAGE_03                             .equ 0xFFFF9AB4 ;  BDT Page Register 3
BDT_PAGE_03_BDT_BA24_MASK               .equ 0x01
BDT_PAGE_03_BDT_BA24_BIT                .equ 0x00
BDT_PAGE_03_BDT_BA25_MASK               .equ 0x02
BDT_PAGE_03_BDT_BA25_BIT                .equ 0x01
BDT_PAGE_03_BDT_BA26_MASK               .equ 0x04
BDT_PAGE_03_BDT_BA26_BIT                .equ 0x02
BDT_PAGE_03_BDT_BA27_MASK               .equ 0x08
BDT_PAGE_03_BDT_BA27_BIT                .equ 0x03
BDT_PAGE_03_BDT_BA28_MASK               .equ 0x10
BDT_PAGE_03_BDT_BA28_BIT                .equ 0x04
BDT_PAGE_03_BDT_BA29_MASK               .equ 0x20
BDT_PAGE_03_BDT_BA29_BIT                .equ 0x05
BDT_PAGE_03_BDT_BA30_MASK               .equ 0x40
BDT_PAGE_03_BDT_BA30_BIT                .equ 0x06
BDT_PAGE_03_BDT_BA31_MASK               .equ 0x80
BDT_PAGE_03_BDT_BA31_BIT                .equ 0x07

;*********************************************
;  Endpoint Control Register 0
;*********************************************
ENDPT0                                  .equ 0xFFFF9AC0 ;  Endpoint Control Register 0
ENDPT0_EP_HSHK_MASK                     .equ 0x01
ENDPT0_EP_HSHK_BIT                      .equ 0x00
ENDPT0_EP_STALL_MASK                    .equ 0x02
ENDPT0_EP_STALL_BIT                     .equ 0x01
ENDPT0_EP_TX_EN_MASK                    .equ 0x04
ENDPT0_EP_TX_EN_BIT                     .equ 0x02
ENDPT0_EP_RX_EN_MASK                    .equ 0x08
ENDPT0_EP_RX_EN_BIT                     .equ 0x03
ENDPT0_EP_CTL_DIS_MASK                  .equ 0x10
ENDPT0_EP_CTL_DIS_BIT                   .equ 0x04
ENDPT0_RETRY_DIS_MASK                   .equ 0x40
ENDPT0_RETRY_DIS_BIT                    .equ 0x06
ENDPT0_HOST_WO_HUB_MASK                 .equ 0x80
ENDPT0_HOST_WO_HUB_BIT                  .equ 0x07

;*********************************************
;  Endpoint Control Register 1
;*********************************************
ENDPT1                                  .equ 0xFFFF9AC4 ;  Endpoint Control Register 1
ENDPT1_EP_HSHK_MASK                     .equ 0x01
ENDPT1_EP_HSHK_BIT                      .equ 0x00
ENDPT1_EP_STALL_MASK                    .equ 0x02
ENDPT1_EP_STALL_BIT                     .equ 0x01
ENDPT1_EP_TX_EN_MASK                    .equ 0x04
ENDPT1_EP_TX_EN_BIT                     .equ 0x02
ENDPT1_EP_RX_EN_MASK                    .equ 0x08
ENDPT1_EP_RX_EN_BIT                     .equ 0x03
ENDPT1_EP_CTL_DIS_MASK                  .equ 0x10
ENDPT1_EP_CTL_DIS_BIT                   .equ 0x04
ENDPT1_RETRY_DIS_MASK                   .equ 0x40
ENDPT1_RETRY_DIS_BIT                    .equ 0x06
ENDPT1_HOST_WO_HUB_MASK                 .equ 0x80
ENDPT1_HOST_WO_HUB_BIT                  .equ 0x07

;*********************************************
;  Endpoint Control Register 2
;*********************************************
ENDPT2                                  .equ 0xFFFF9AC8 ;  Endpoint Control Register 2
ENDPT2_EP_HSHK_MASK                     .equ 0x01
ENDPT2_EP_HSHK_BIT                      .equ 0x00
ENDPT2_EP_STALL_MASK                    .equ 0x02
ENDPT2_EP_STALL_BIT                     .equ 0x01
ENDPT2_EP_TX_EN_MASK                    .equ 0x04
ENDPT2_EP_TX_EN_BIT                     .equ 0x02
ENDPT2_EP_RX_EN_MASK                    .equ 0x08
ENDPT2_EP_RX_EN_BIT                     .equ 0x03
ENDPT2_EP_CTL_DIS_MASK                  .equ 0x10
ENDPT2_EP_CTL_DIS_BIT                   .equ 0x04
ENDPT2_RETRY_DIS_MASK                   .equ 0x40
ENDPT2_RETRY_DIS_BIT                    .equ 0x06
ENDPT2_HOST_WO_HUB_MASK                 .equ 0x80
ENDPT2_HOST_WO_HUB_BIT                  .equ 0x07

;*********************************************
;  Endpoint Control Register 3
;*********************************************
ENDPT3                                  .equ 0xFFFF9ACC ;  Endpoint Control Register 3
ENDPT3_EP_HSHK_MASK                     .equ 0x01
ENDPT3_EP_HSHK_BIT                      .equ 0x00
ENDPT3_EP_STALL_MASK                    .equ 0x02
ENDPT3_EP_STALL_BIT                     .equ 0x01
ENDPT3_EP_TX_EN_MASK                    .equ 0x04
ENDPT3_EP_TX_EN_BIT                     .equ 0x02
ENDPT3_EP_RX_EN_MASK                    .equ 0x08
ENDPT3_EP_RX_EN_BIT                     .equ 0x03
ENDPT3_EP_CTL_DIS_MASK                  .equ 0x10
ENDPT3_EP_CTL_DIS_BIT                   .equ 0x04
ENDPT3_RETRY_DIS_MASK                   .equ 0x40
ENDPT3_RETRY_DIS_BIT                    .equ 0x06
ENDPT3_HOST_WO_HUB_MASK                 .equ 0x80
ENDPT3_HOST_WO_HUB_BIT                  .equ 0x07

;*********************************************
;  Endpoint Control Register 4
;*********************************************
ENDPT4                                  .equ 0xFFFF9AD0 ;  Endpoint Control Register 4
ENDPT4_EP_HSHK_MASK                     .equ 0x01
ENDPT4_EP_HSHK_BIT                      .equ 0x00
ENDPT4_EP_STALL_MASK                    .equ 0x02
ENDPT4_EP_STALL_BIT                     .equ 0x01
ENDPT4_EP_TX_EN_MASK                    .equ 0x04
ENDPT4_EP_TX_EN_BIT                     .equ 0x02
ENDPT4_EP_RX_EN_MASK                    .equ 0x08
ENDPT4_EP_RX_EN_BIT                     .equ 0x03
ENDPT4_EP_CTL_DIS_MASK                  .equ 0x10
ENDPT4_EP_CTL_DIS_BIT                   .equ 0x04
ENDPT4_RETRY_DIS_MASK                   .equ 0x40
ENDPT4_RETRY_DIS_BIT                    .equ 0x06
ENDPT4_HOST_WO_HUB_MASK                 .equ 0x80
ENDPT4_HOST_WO_HUB_BIT                  .equ 0x07

;*********************************************
;  Endpoint Control Register 5
;*********************************************
ENDPT5                                  .equ 0xFFFF9AD4 ;  Endpoint Control Register 5
ENDPT5_EP_HSHK_MASK                     .equ 0x01
ENDPT5_EP_HSHK_BIT                      .equ 0x00
ENDPT5_EP_STALL_MASK                    .equ 0x02
ENDPT5_EP_STALL_BIT                     .equ 0x01
ENDPT5_EP_TX_EN_MASK                    .equ 0x04
ENDPT5_EP_TX_EN_BIT                     .equ 0x02
ENDPT5_EP_RX_EN_MASK                    .equ 0x08
ENDPT5_EP_RX_EN_BIT                     .equ 0x03
ENDPT5_EP_CTL_DIS_MASK                  .equ 0x10
ENDPT5_EP_CTL_DIS_BIT                   .equ 0x04
ENDPT5_RETRY_DIS_MASK                   .equ 0x40
ENDPT5_RETRY_DIS_BIT                    .equ 0x06
ENDPT5_HOST_WO_HUB_MASK                 .equ 0x80
ENDPT5_HOST_WO_HUB_BIT                  .equ 0x07

;*********************************************
;  Endpoint Control Register 6
;*********************************************
ENDPT6                                  .equ 0xFFFF9AD8 ;  Endpoint Control Register 6
ENDPT6_EP_HSHK_MASK                     .equ 0x01
ENDPT6_EP_HSHK_BIT                      .equ 0x00
ENDPT6_EP_STALL_MASK                    .equ 0x02
ENDPT6_EP_STALL_BIT                     .equ 0x01
ENDPT6_EP_TX_EN_MASK                    .equ 0x04
ENDPT6_EP_TX_EN_BIT                     .equ 0x02
ENDPT6_EP_RX_EN_MASK                    .equ 0x08
ENDPT6_EP_RX_EN_BIT                     .equ 0x03
ENDPT6_EP_CTL_DIS_MASK                  .equ 0x10
ENDPT6_EP_CTL_DIS_BIT                   .equ 0x04
ENDPT6_RETRY_DIS_MASK                   .equ 0x40
ENDPT6_RETRY_DIS_BIT                    .equ 0x06
ENDPT6_HOST_WO_HUB_MASK                 .equ 0x80
ENDPT6_HOST_WO_HUB_BIT                  .equ 0x07

;*********************************************
;  Endpoint Control Register 7
;*********************************************
ENDPT7                                  .equ 0xFFFF9ADC ;  Endpoint Control Register 7
ENDPT7_EP_HSHK_MASK                     .equ 0x01
ENDPT7_EP_HSHK_BIT                      .equ 0x00
ENDPT7_EP_STALL_MASK                    .equ 0x02
ENDPT7_EP_STALL_BIT                     .equ 0x01
ENDPT7_EP_TX_EN_MASK                    .equ 0x04
ENDPT7_EP_TX_EN_BIT                     .equ 0x02
ENDPT7_EP_RX_EN_MASK                    .equ 0x08
ENDPT7_EP_RX_EN_BIT                     .equ 0x03
ENDPT7_EP_CTL_DIS_MASK                  .equ 0x10
ENDPT7_EP_CTL_DIS_BIT                   .equ 0x04
ENDPT7_RETRY_DIS_MASK                   .equ 0x40
ENDPT7_RETRY_DIS_BIT                    .equ 0x06
ENDPT7_HOST_WO_HUB_MASK                 .equ 0x80
ENDPT7_HOST_WO_HUB_BIT                  .equ 0x07

;*********************************************
;  Endpoint Control Register 8
;*********************************************
ENDPT8                                  .equ 0xFFFF9AE0 ;  Endpoint Control Register 8
ENDPT8_EP_HSHK_MASK                     .equ 0x01
ENDPT8_EP_HSHK_BIT                      .equ 0x00
ENDPT8_EP_STALL_MASK                    .equ 0x02
ENDPT8_EP_STALL_BIT                     .equ 0x01
ENDPT8_EP_TX_EN_MASK                    .equ 0x04
ENDPT8_EP_TX_EN_BIT                     .equ 0x02
ENDPT8_EP_RX_EN_MASK                    .equ 0x08
ENDPT8_EP_RX_EN_BIT                     .equ 0x03
ENDPT8_EP_CTL_DIS_MASK                  .equ 0x10
ENDPT8_EP_CTL_DIS_BIT                   .equ 0x04
ENDPT8_RETRY_DIS_MASK                   .equ 0x40
ENDPT8_RETRY_DIS_BIT                    .equ 0x06
ENDPT8_HOST_WO_HUB_MASK                 .equ 0x80
ENDPT8_HOST_WO_HUB_BIT                  .equ 0x07

;*********************************************
;  Endpoint Control Register 9
;*********************************************
ENDPT9                                  .equ 0xFFFF9AE4 ;  Endpoint Control Register 9
ENDPT9_EP_HSHK_MASK                     .equ 0x01
ENDPT9_EP_HSHK_BIT                      .equ 0x00
ENDPT9_EP_STALL_MASK                    .equ 0x02
ENDPT9_EP_STALL_BIT                     .equ 0x01
ENDPT9_EP_TX_EN_MASK                    .equ 0x04
ENDPT9_EP_TX_EN_BIT                     .equ 0x02
ENDPT9_EP_RX_EN_MASK                    .equ 0x08
ENDPT9_EP_RX_EN_BIT                     .equ 0x03
ENDPT9_EP_CTL_DIS_MASK                  .equ 0x10
ENDPT9_EP_CTL_DIS_BIT                   .equ 0x04
ENDPT9_RETRY_DIS_MASK                   .equ 0x40
ENDPT9_RETRY_DIS_BIT                    .equ 0x06
ENDPT9_HOST_WO_HUB_MASK                 .equ 0x80
ENDPT9_HOST_WO_HUB_BIT                  .equ 0x07

;*********************************************
;  Endpoint Control Register 10
;*********************************************
ENDPT10                                 .equ 0xFFFF9AE8 ;  Endpoint Control Register 10
ENDPT10_EP_HSHK_MASK                    .equ 0x01
ENDPT10_EP_HSHK_BIT                     .equ 0x00
ENDPT10_EP_STALL_MASK                   .equ 0x02
ENDPT10_EP_STALL_BIT                    .equ 0x01
ENDPT10_EP_TX_EN_MASK                   .equ 0x04
ENDPT10_EP_TX_EN_BIT                    .equ 0x02
ENDPT10_EP_RX_EN_MASK                   .equ 0x08
ENDPT10_EP_RX_EN_BIT                    .equ 0x03
ENDPT10_EP_CTL_DIS_MASK                 .equ 0x10
ENDPT10_EP_CTL_DIS_BIT                  .equ 0x04
ENDPT10_RETRY_DIS_MASK                  .equ 0x40
ENDPT10_RETRY_DIS_BIT                   .equ 0x06
ENDPT10_HOST_WO_HUB_MASK                .equ 0x80
ENDPT10_HOST_WO_HUB_BIT                 .equ 0x07

;*********************************************
;  Endpoint Control Register 11
;*********************************************
ENDPT11                                 .equ 0xFFFF9AEC ;  Endpoint Control Register 11
ENDPT11_EP_HSHK_MASK                    .equ 0x01
ENDPT11_EP_HSHK_BIT                     .equ 0x00
ENDPT11_EP_STALL_MASK                   .equ 0x02
ENDPT11_EP_STALL_BIT                    .equ 0x01
ENDPT11_EP_TX_EN_MASK                   .equ 0x04
ENDPT11_EP_TX_EN_BIT                    .equ 0x02
ENDPT11_EP_RX_EN_MASK                   .equ 0x08
ENDPT11_EP_RX_EN_BIT                    .equ 0x03
ENDPT11_EP_CTL_DIS_MASK                 .equ 0x10
ENDPT11_EP_CTL_DIS_BIT                  .equ 0x04
ENDPT11_RETRY_DIS_MASK                  .equ 0x40
ENDPT11_RETRY_DIS_BIT                   .equ 0x06
ENDPT11_HOST_WO_HUB_MASK                .equ 0x80
ENDPT11_HOST_WO_HUB_BIT                 .equ 0x07

;*********************************************
;  Endpoint Control Register 12
;*********************************************
ENDPT12                                 .equ 0xFFFF9AF0 ;  Endpoint Control Register 12
ENDPT12_EP_HSHK_MASK                    .equ 0x01
ENDPT12_EP_HSHK_BIT                     .equ 0x00
ENDPT12_EP_STALL_MASK                   .equ 0x02
ENDPT12_EP_STALL_BIT                    .equ 0x01
ENDPT12_EP_TX_EN_MASK                   .equ 0x04
ENDPT12_EP_TX_EN_BIT                    .equ 0x02
ENDPT12_EP_RX_EN_MASK                   .equ 0x08
ENDPT12_EP_RX_EN_BIT                    .equ 0x03
ENDPT12_EP_CTL_DIS_MASK                 .equ 0x10
ENDPT12_EP_CTL_DIS_BIT                  .equ 0x04
ENDPT12_RETRY_DIS_MASK                  .equ 0x40
ENDPT12_RETRY_DIS_BIT                   .equ 0x06
ENDPT12_HOST_WO_HUB_MASK                .equ 0x80
ENDPT12_HOST_WO_HUB_BIT                 .equ 0x07

;*********************************************
;  Endpoint Control Register 13
;*********************************************
ENDPT13                                 .equ 0xFFFF9AF4 ;  Endpoint Control Register 13
ENDPT13_EP_HSHK_MASK                    .equ 0x01
ENDPT13_EP_HSHK_BIT                     .equ 0x00
ENDPT13_EP_STALL_MASK                   .equ 0x02
ENDPT13_EP_STALL_BIT                    .equ 0x01
ENDPT13_EP_TX_EN_MASK                   .equ 0x04
ENDPT13_EP_TX_EN_BIT                    .equ 0x02
ENDPT13_EP_RX_EN_MASK                   .equ 0x08
ENDPT13_EP_RX_EN_BIT                    .equ 0x03
ENDPT13_EP_CTL_DIS_MASK                 .equ 0x10
ENDPT13_EP_CTL_DIS_BIT                  .equ 0x04
ENDPT13_RETRY_DIS_MASK                  .equ 0x40
ENDPT13_RETRY_DIS_BIT                   .equ 0x06
ENDPT13_HOST_WO_HUB_MASK                .equ 0x80
ENDPT13_HOST_WO_HUB_BIT                 .equ 0x07

;*********************************************
;  Endpoint Control Register 14
;*********************************************
ENDPT14                                 .equ 0xFFFF9AF8 ;  Endpoint Control Register 14
ENDPT14_EP_HSHK_MASK                    .equ 0x01
ENDPT14_EP_HSHK_BIT                     .equ 0x00
ENDPT14_EP_STALL_MASK                   .equ 0x02
ENDPT14_EP_STALL_BIT                    .equ 0x01
ENDPT14_EP_TX_EN_MASK                   .equ 0x04
ENDPT14_EP_TX_EN_BIT                    .equ 0x02
ENDPT14_EP_RX_EN_MASK                   .equ 0x08
ENDPT14_EP_RX_EN_BIT                    .equ 0x03
ENDPT14_EP_CTL_DIS_MASK                 .equ 0x10
ENDPT14_EP_CTL_DIS_BIT                  .equ 0x04
ENDPT14_RETRY_DIS_MASK                  .equ 0x40
ENDPT14_RETRY_DIS_BIT                   .equ 0x06
ENDPT14_HOST_WO_HUB_MASK                .equ 0x80
ENDPT14_HOST_WO_HUB_BIT                 .equ 0x07

;*********************************************
;  Endpoint Control Register 15
;*********************************************
ENDPT15                                 .equ 0xFFFF9AFC ;  Endpoint Control Register 15
ENDPT15_EP_HSHK_MASK                    .equ 0x01
ENDPT15_EP_HSHK_BIT                     .equ 0x00
ENDPT15_EP_STALL_MASK                   .equ 0x02
ENDPT15_EP_STALL_BIT                    .equ 0x01
ENDPT15_EP_TX_EN_MASK                   .equ 0x04
ENDPT15_EP_TX_EN_BIT                    .equ 0x02
ENDPT15_EP_RX_EN_MASK                   .equ 0x08
ENDPT15_EP_RX_EN_BIT                    .equ 0x03
ENDPT15_EP_CTL_DIS_MASK                 .equ 0x10
ENDPT15_EP_CTL_DIS_BIT                  .equ 0x04
ENDPT15_RETRY_DIS_MASK                  .equ 0x40
ENDPT15_RETRY_DIS_BIT                   .equ 0x06
ENDPT15_HOST_WO_HUB_MASK                .equ 0x80
ENDPT15_HOST_WO_HUB_BIT                 .equ 0x07

;*********************************************
;  USB Control Register
;*********************************************
USB_CTRL                                .equ 0xFFFF9B00 ;  USB Control Register
USB_CTRL_CLK_SRC0_MASK                  .equ 0x01
USB_CTRL_CLK_SRC0_BIT                   .equ 0x00
USB_CTRL_CLK_SRC1_MASK                  .equ 0x02
USB_CTRL_CLK_SRC1_BIT                   .equ 0x01
USB_CTRL_PDE_MASK                       .equ 0x40
USB_CTRL_PDE_BIT                        .equ 0x06
USB_CTRL_SUSP_MASK                      .equ 0x80
USB_CTRL_SUSP_BIT                       .equ 0x07
USB_CTRL_CLK_SRC_MASK                   .equ 0x03

;*********************************************
;  USB OTG Observe Register
;*********************************************
USB_OTG_OBSERVE                         .equ 0xFFFF9B04 ;  USB OTG Observe Register
USB_OTG_OBSERVE_DM_PD_MASK              .equ 0x10
USB_OTG_OBSERVE_DM_PD_BIT               .equ 0x04
USB_OTG_OBSERVE_DP_PD_MASK              .equ 0x40
USB_OTG_OBSERVE_DP_PD_BIT               .equ 0x06
USB_OTG_OBSERVE_DP_PU_MASK              .equ 0x80
USB_OTG_OBSERVE_DP_PU_BIT               .equ 0x07

;*********************************************
;  USB OTG Control Register
;*********************************************
USB_OTG_CONTROL                         .equ 0xFFFF9B08 ;  USB OTG Control Register
USB_OTG_CONTROL_SESSEND_MASK            .equ 0x01
USB_OTG_CONTROL_SESSEND_BIT             .equ 0x00
USB_OTG_CONTROL_SESSVLD_MASK            .equ 0x02
USB_OTG_CONTROL_SESSVLD_BIT             .equ 0x01
USB_OTG_CONTROL_VBUSVLD_MASK            .equ 0x04
USB_OTG_CONTROL_VBUSVLD_BIT             .equ 0x02
USB_OTG_CONTROL_ID_MASK                 .equ 0x08
USB_OTG_CONTROL_ID_BIT                  .equ 0x03
USB_OTG_CONTROL_DPPULLUP_NONOTG_MASK    .equ 0x10
USB_OTG_CONTROL_DPPULLUP_NONOTG_BIT     .equ 0x04

;*********************************************
;  USB Transceiver and Regulator Control Register 0
;*********************************************
USBTRC0                                 .equ 0xFFFF9B0C ;  USB Transceiver and Regulator Control Register 0
USBTRC0_USB_RESUME_INT_MASK             .equ 0x01
USBTRC0_USB_RESUME_INT_BIT              .equ 0x00
USBTRC0_USBVREN_MASK                    .equ 0x04
USBTRC0_USBVREN_BIT                     .equ 0x02
USBTRC0_USBRESMEN_MASK                  .equ 0x20
USBTRC0_USBRESMEN_BIT                   .equ 0x05
USBTRC0_USBPU_MASK                      .equ 0x40
USBTRC0_USBPU_BIT                       .equ 0x06
USBTRC0_USBRESET_MASK                   .equ 0x80
USBTRC0_USBRESET_BIT                    .equ 0x07

;*********************************************
;  USB OTG Pin Control Register
;*********************************************
OTGPIN                                  .equ 0xFFFF9B10 ;  USB OTG Pin Control Register
OTGPIN_SESSVLD_MASK                     .equ 0x01
OTGPIN_SESSVLD_BIT                      .equ 0x00
OTGPIN_SESSEND_MASK                     .equ 0x02
OTGPIN_SESSEND_BIT                      .equ 0x01
OTGPIN_VBUSVLD_MASK                     .equ 0x04
OTGPIN_VBUSVLD_BIT                      .equ 0x02
OTGPIN_PULLUP_MASK                      .equ 0x08
OTGPIN_PULLUP_BIT                       .equ 0x03
OTGPIN_DPDOWN_MASK                      .equ 0x10
OTGPIN_DPDOWN_BIT                       .equ 0x04
OTGPIN_DMDOWN_MASK                      .equ 0x20
OTGPIN_DMDOWN_BIT                       .equ 0x05
OTGPIN_USBID_MASK                       .equ 0x40
OTGPIN_USBID_BIT                        .equ 0x06

;*********************************************
;  INTC Force Interrupt Register
;*********************************************
INTC_FRC                                .equ 0xFFFFFFD0 ;  INTC Force Interrupt Register
INTC_FRC_LVL7_MASK                      .equ 0x01
INTC_FRC_LVL7_BIT                       .equ 0x00
INTC_FRC_LVL6_MASK                      .equ 0x02
INTC_FRC_LVL6_BIT                       .equ 0x01
INTC_FRC_LVL5_MASK                      .equ 0x04
INTC_FRC_LVL5_BIT                       .equ 0x02
INTC_FRC_LVL4_MASK                      .equ 0x08
INTC_FRC_LVL4_BIT                       .equ 0x03
INTC_FRC_LVL3_MASK                      .equ 0x10
INTC_FRC_LVL3_BIT                       .equ 0x04
INTC_FRC_LVL2_MASK                      .equ 0x20
INTC_FRC_LVL2_BIT                       .equ 0x05
INTC_FRC_LVL1_MASK                      .equ 0x40
INTC_FRC_LVL1_BIT                       .equ 0x06

;*********************************************
;  INTC Programmable Level 6, Priority 7 Register
;*********************************************
INTC_PL6P7                              .equ 0xFFFFFFD8 ;  INTC Programmable Level 6, Priority 7 Register
INTC_PL6P7_REQN0_MASK                   .equ 0x01
INTC_PL6P7_REQN0_BIT                    .equ 0x00
INTC_PL6P7_REQN1_MASK                   .equ 0x02
INTC_PL6P7_REQN1_BIT                    .equ 0x01
INTC_PL6P7_REQN2_MASK                   .equ 0x04
INTC_PL6P7_REQN2_BIT                    .equ 0x02
INTC_PL6P7_REQN3_MASK                   .equ 0x08
INTC_PL6P7_REQN3_BIT                    .equ 0x03
INTC_PL6P7_REQN4_MASK                   .equ 0x10
INTC_PL6P7_REQN4_BIT                    .equ 0x04
INTC_PL6P7_REQN5_MASK                   .equ 0x20
INTC_PL6P7_REQN5_BIT                    .equ 0x05
INTC_PL6P7_REQN_MASK                    .equ 0x3F

;*********************************************
;  INTC Programmable Level 6, Priority 6 Register
;*********************************************
INTC_PL6P6                              .equ 0xFFFFFFD9 ;  INTC Programmable Level 6, Priority 6 Register
INTC_PL6P6_REQN0_MASK                   .equ 0x01
INTC_PL6P6_REQN0_BIT                    .equ 0x00
INTC_PL6P6_REQN1_MASK                   .equ 0x02
INTC_PL6P6_REQN1_BIT                    .equ 0x01
INTC_PL6P6_REQN2_MASK                   .equ 0x04
INTC_PL6P6_REQN2_BIT                    .equ 0x02
INTC_PL6P6_REQN3_MASK                   .equ 0x08
INTC_PL6P6_REQN3_BIT                    .equ 0x03
INTC_PL6P6_REQN4_MASK                   .equ 0x10
INTC_PL6P6_REQN4_BIT                    .equ 0x04
INTC_PL6P6_REQN5_MASK                   .equ 0x20
INTC_PL6P6_REQN5_BIT                    .equ 0x05
INTC_PL6P6_REQN_MASK                    .equ 0x3F

;*********************************************
;  INTC Wake-up Control Register
;*********************************************
INTC_WCR                                .equ 0xFFFFFFDB ;  INTC Wake-up Control Register
INTC_WCR_MASK0_MASK                     .equ 0x01
INTC_WCR_BIT0_BIT                       .equ 0x00
INTC_WCR_MASK1_MASK                     .equ 0x02
INTC_WCR_BIT1_BIT                       .equ 0x01
INTC_WCR_MASK2_MASK                     .equ 0x04
INTC_WCR_BIT2_BIT                       .equ 0x02
INTC_WCR_ENB_MASK                       .equ 0x80
INTC_WCR_ENB_BIT                        .equ 0x07
INTC_WCR_MASK_MASK                      .equ 0x07

;*********************************************
;  INTC Set Interrupt Force Register
;*********************************************
INTC_SFRC                               .equ 0xFFFFFFDE ;  INTC Set Interrupt Force Register
INTC_SFRC_SET0_MASK                     .equ 0x01
INTC_SFRC_SET0_BIT                      .equ 0x00
INTC_SFRC_SET1_MASK                     .equ 0x02
INTC_SFRC_SET1_BIT                      .equ 0x01
INTC_SFRC_SET2_MASK                     .equ 0x04
INTC_SFRC_SET2_BIT                      .equ 0x02
INTC_SFRC_SET3_MASK                     .equ 0x08
INTC_SFRC_SET3_BIT                      .equ 0x03
INTC_SFRC_SET4_MASK                     .equ 0x10
INTC_SFRC_SET4_BIT                      .equ 0x04
INTC_SFRC_SET5_MASK                     .equ 0x20
INTC_SFRC_SET5_BIT                      .equ 0x05
INTC_SFRC_SET_MASK                      .equ 0x3F

;*********************************************
;  INTC Clear Interrupt Force Register
;*********************************************
INTC_CFRC                               .equ 0xFFFFFFDF ;  INTC Clear Interrupt Force Register
INTC_CFRC_CLR0_MASK                     .equ 0x01
INTC_CFRC_CLR0_BIT                      .equ 0x00
INTC_CFRC_CLR1_MASK                     .equ 0x02
INTC_CFRC_CLR1_BIT                      .equ 0x01
INTC_CFRC_CLR2_MASK                     .equ 0x04
INTC_CFRC_CLR2_BIT                      .equ 0x02
INTC_CFRC_CLR3_MASK                     .equ 0x08
INTC_CFRC_CLR3_BIT                      .equ 0x03
INTC_CFRC_CLR4_MASK                     .equ 0x10
INTC_CFRC_CLR4_BIT                      .equ 0x04
INTC_CFRC_CLR5_MASK                     .equ 0x20
INTC_CFRC_CLR5_BIT                      .equ 0x05
INTC_CFRC_CLR_MASK                      .equ 0x3F

;*********************************************
;  INTC Software IACK Register
;*********************************************
INTC_SWIACK                             .equ 0xFFFFFFE0 ;  INTC Software IACK Register
INTC_SWIACK_VECN0_MASK                  .equ 0x01
INTC_SWIACK_VECN0_BIT                   .equ 0x00
INTC_SWIACK_VECN1_MASK                  .equ 0x02
INTC_SWIACK_VECN1_BIT                   .equ 0x01
INTC_SWIACK_VECN2_MASK                  .equ 0x04
INTC_SWIACK_VECN2_BIT                   .equ 0x02
INTC_SWIACK_VECN3_MASK                  .equ 0x08
INTC_SWIACK_VECN3_BIT                   .equ 0x03
INTC_SWIACK_VECN4_MASK                  .equ 0x10
INTC_SWIACK_VECN4_BIT                   .equ 0x04
INTC_SWIACK_VECN5_MASK                  .equ 0x20
INTC_SWIACK_VECN5_BIT                   .equ 0x05
INTC_SWIACK_VECN6_MASK                  .equ 0x40
INTC_SWIACK_VECN6_BIT                   .equ 0x06
INTC_SWIACK_VECN_MASK                   .equ 0x7F

;*********************************************
;  INTC Level 1 IACK Register
;*********************************************
INTC_LVL1IACK                           .equ 0xFFFFFFE4 ;  INTC Level 1 IACK Register
INTC_LVL1IACK_VECN0_MASK                .equ 0x01
INTC_LVL1IACK_VECN0_BIT                 .equ 0x00
INTC_LVL1IACK_VECN1_MASK                .equ 0x02
INTC_LVL1IACK_VECN1_BIT                 .equ 0x01
INTC_LVL1IACK_VECN2_MASK                .equ 0x04
INTC_LVL1IACK_VECN2_BIT                 .equ 0x02
INTC_LVL1IACK_VECN3_MASK                .equ 0x08
INTC_LVL1IACK_VECN3_BIT                 .equ 0x03
INTC_LVL1IACK_VECN4_MASK                .equ 0x10
INTC_LVL1IACK_VECN4_BIT                 .equ 0x04
INTC_LVL1IACK_VECN5_MASK                .equ 0x20
INTC_LVL1IACK_VECN5_BIT                 .equ 0x05
INTC_LVL1IACK_VECN6_MASK                .equ 0x40
INTC_LVL1IACK_VECN6_BIT                 .equ 0x06
INTC_LVL1IACK_VECN_MASK                 .equ 0x7F

;*********************************************
;  INTC Level 2 IACK Register
;*********************************************
INTC_LVL2IACK                           .equ 0xFFFFFFE8 ;  INTC Level 2 IACK Register
INTC_LVL2IACK_VECN0_MASK                .equ 0x01
INTC_LVL2IACK_VECN0_BIT                 .equ 0x00
INTC_LVL2IACK_VECN1_MASK                .equ 0x02
INTC_LVL2IACK_VECN1_BIT                 .equ 0x01
INTC_LVL2IACK_VECN2_MASK                .equ 0x04
INTC_LVL2IACK_VECN2_BIT                 .equ 0x02
INTC_LVL2IACK_VECN3_MASK                .equ 0x08
INTC_LVL2IACK_VECN3_BIT                 .equ 0x03
INTC_LVL2IACK_VECN4_MASK                .equ 0x10
INTC_LVL2IACK_VECN4_BIT                 .equ 0x04
INTC_LVL2IACK_VECN5_MASK                .equ 0x20
INTC_LVL2IACK_VECN5_BIT                 .equ 0x05
INTC_LVL2IACK_VECN6_MASK                .equ 0x40
INTC_LVL2IACK_VECN6_BIT                 .equ 0x06
INTC_LVL2IACK_VECN_MASK                 .equ 0x7F

;*********************************************
;  INTC Level 3 IACK Register
;*********************************************
INTC_LVL3IACK                           .equ 0xFFFFFFEC ;  INTC Level 3 IACK Register
INTC_LVL3IACK_VECN0_MASK                .equ 0x01
INTC_LVL3IACK_VECN0_BIT                 .equ 0x00
INTC_LVL3IACK_VECN1_MASK                .equ 0x02
INTC_LVL3IACK_VECN1_BIT                 .equ 0x01
INTC_LVL3IACK_VECN2_MASK                .equ 0x04
INTC_LVL3IACK_VECN2_BIT                 .equ 0x02
INTC_LVL3IACK_VECN3_MASK                .equ 0x08
INTC_LVL3IACK_VECN3_BIT                 .equ 0x03
INTC_LVL3IACK_VECN4_MASK                .equ 0x10
INTC_LVL3IACK_VECN4_BIT                 .equ 0x04
INTC_LVL3IACK_VECN5_MASK                .equ 0x20
INTC_LVL3IACK_VECN5_BIT                 .equ 0x05
INTC_LVL3IACK_VECN6_MASK                .equ 0x40
INTC_LVL3IACK_VECN6_BIT                 .equ 0x06
INTC_LVL3IACK_VECN_MASK                 .equ 0x7F

;*********************************************
;  INTC Level 4 IACK Register
;*********************************************
INTC_LVL4IACK                           .equ 0xFFFFFFF0 ;  INTC Level 4 IACK Register
INTC_LVL4IACK_VECN0_MASK                .equ 0x01
INTC_LVL4IACK_VECN0_BIT                 .equ 0x00
INTC_LVL4IACK_VECN1_MASK                .equ 0x02
INTC_LVL4IACK_VECN1_BIT                 .equ 0x01
INTC_LVL4IACK_VECN2_MASK                .equ 0x04
INTC_LVL4IACK_VECN2_BIT                 .equ 0x02
INTC_LVL4IACK_VECN3_MASK                .equ 0x08
INTC_LVL4IACK_VECN3_BIT                 .equ 0x03
INTC_LVL4IACK_VECN4_MASK                .equ 0x10
INTC_LVL4IACK_VECN4_BIT                 .equ 0x04
INTC_LVL4IACK_VECN5_MASK                .equ 0x20
INTC_LVL4IACK_VECN5_BIT                 .equ 0x05
INTC_LVL4IACK_VECN6_MASK                .equ 0x40
INTC_LVL4IACK_VECN6_BIT                 .equ 0x06
INTC_LVL4IACK_VECN_MASK                 .equ 0x7F

;*********************************************
;  INTC Level 5 IACK Register
;*********************************************
INTC_LVL5IACK                           .equ 0xFFFFFFF4 ;  INTC Level 5 IACK Register
INTC_LVL5IACK_VECN0_MASK                .equ 0x01
INTC_LVL5IACK_VECN0_BIT                 .equ 0x00
INTC_LVL5IACK_VECN1_MASK                .equ 0x02
INTC_LVL5IACK_VECN1_BIT                 .equ 0x01
INTC_LVL5IACK_VECN2_MASK                .equ 0x04
INTC_LVL5IACK_VECN2_BIT                 .equ 0x02
INTC_LVL5IACK_VECN3_MASK                .equ 0x08
INTC_LVL5IACK_VECN3_BIT                 .equ 0x03
INTC_LVL5IACK_VECN4_MASK                .equ 0x10
INTC_LVL5IACK_VECN4_BIT                 .equ 0x04
INTC_LVL5IACK_VECN5_MASK                .equ 0x20
INTC_LVL5IACK_VECN5_BIT                 .equ 0x05
INTC_LVL5IACK_VECN6_MASK                .equ 0x40
INTC_LVL5IACK_VECN6_BIT                 .equ 0x06
INTC_LVL5IACK_VECN_MASK                 .equ 0x7F

;*********************************************
;  INTC Level 6 IACK Register
;*********************************************
INTC_LVL6IACK                           .equ 0xFFFFFFF8 ;  INTC Level 6 IACK Register
INTC_LVL6IACK_VECN0_MASK                .equ 0x01
INTC_LVL6IACK_VECN0_BIT                 .equ 0x00
INTC_LVL6IACK_VECN1_MASK                .equ 0x02
INTC_LVL6IACK_VECN1_BIT                 .equ 0x01
INTC_LVL6IACK_VECN2_MASK                .equ 0x04
INTC_LVL6IACK_VECN2_BIT                 .equ 0x02
INTC_LVL6IACK_VECN3_MASK                .equ 0x08
INTC_LVL6IACK_VECN3_BIT                 .equ 0x03
INTC_LVL6IACK_VECN4_MASK                .equ 0x10
INTC_LVL6IACK_VECN4_BIT                 .equ 0x04
INTC_LVL6IACK_VECN5_MASK                .equ 0x20
INTC_LVL6IACK_VECN5_BIT                 .equ 0x05
INTC_LVL6IACK_VECN6_MASK                .equ 0x40
INTC_LVL6IACK_VECN6_BIT                 .equ 0x06
INTC_LVL6IACK_VECN_MASK                 .equ 0x7F

;*********************************************
;  INTC Level 7 IACK Register
;*********************************************
INTC_LVL7IACK                           .equ 0xFFFFFFFC ;  INTC Level 7 IACK Register
INTC_LVL7IACK_VECN0_MASK                .equ 0x01
INTC_LVL7IACK_VECN0_BIT                 .equ 0x00
INTC_LVL7IACK_VECN1_MASK                .equ 0x02
INTC_LVL7IACK_VECN1_BIT                 .equ 0x01
INTC_LVL7IACK_VECN2_MASK                .equ 0x04
INTC_LVL7IACK_VECN2_BIT                 .equ 0x02
INTC_LVL7IACK_VECN3_MASK                .equ 0x08
INTC_LVL7IACK_VECN3_BIT                 .equ 0x03
INTC_LVL7IACK_VECN4_MASK                .equ 0x10
INTC_LVL7IACK_VECN4_BIT                 .equ 0x04
INTC_LVL7IACK_VECN5_MASK                .equ 0x20
INTC_LVL7IACK_VECN5_BIT                 .equ 0x05
INTC_LVL7IACK_VECN6_MASK                .equ 0x40
INTC_LVL7IACK_VECN6_BIT                 .equ 0x06
INTC_LVL7IACK_VECN_MASK                 .equ 0x7F
