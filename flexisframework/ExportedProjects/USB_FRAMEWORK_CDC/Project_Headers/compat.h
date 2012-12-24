// this file equates the various freescale MCU register namespaces for
// common peripherals.

// N.B. for some MCUs we have peripherals 0 and 1 and others have 1 and 2;
// in this case we use an X in the source file to eliminate a #define
// recursion.
#define V1_CW		1  // CW Already defines these.

#ifdef V1_CW
#define NO_UINT_TYPEDEFS  1
#endif

#ifndef NO_UINT_TYPEDEFS

typedef unsigned char uint8;
typedef unsigned short uint16;
#if MC9S08QE128 || MC9S12DT256 || MC9S12DP512
typedef long int32;
typedef unsigned long uint32;
#else
typedef int int32;
typedef unsigned int uint32;
#endif

#define NO_UINT_TYPEDEFS  1
#endif

#if MC9S12DT256 || MC9S12DP512
#define SCI1C1X  SCI0CR1
#define SCI1C2X  SCI0CR2
#define SCI1S1X  SCI0SR1
#define SCI1S2X  SCI0SR2
#define SCI1BDHX  SCI0BDH
#define SCI1BDLX  SCI0BDL
#define SCI1DX  SCI0DRL

#define SCI2C1X  SCI1CR1
#define SCI2C2X  SCI1CR2
#define SCI2S1X  SCI1SR1
#define SCI2S2X  SCI1SR2
#define SCI2BDHX  SCI1BDH
#define SCI2BDLX  SCI1BDL
#define SCI2DX  SCI1DRL

#define SCI1C2_RIE_MASK  SCI1CR2_RIE_MASK
#define SCI1C2_TE_MASK  SCI1CR2_TE_MASK
#define SCI1C2_RE_MASK  SCI1CR2_RE_MASK
#define SCI1C1_LOOPS_MASK  SCI1CR1_LOOPS_MASK
#define SCI1C1_M_MASK  SCI1CR1_M_MASK
#define SCI1C1_PT_MASK  SCI1CR1_PT_MASK
#define SCI1C1_PE_MASK  SCI1CR1_PE_MASK
#define SCI1S1_TDRE_MASK  SCI1SR1_TDRE_MASK
#define SCI1S1_TC_MASK  SCI1SR1_TC_MASK
#define SCI1S1_RDRF_MASK  SCI1SR1_RDRF_MASK

#define SPI1C1X  SPI0CR1
#define SPI1C2X  SPI0CR2
#define SPI1BRX  SPI0BR
#define SPI1SX  SPI0SR
#define SPI1DL  SPI0DR
#define SPI1BRX_SPR  SPI0BR_SPR
#define SPI1BRX_SPPR  SPI0BR_SPPR
#define SPI1S_SPTEF_MASK  SPI0SR_SPTEF_MASK
#define SPI1S_SPRF_MASK  SPI0SR_SPIF_MASK
#define SPI1C1_SPE_MASK  SPI0CR1_SPE_MASK
#define SPI1C1_MSTR_MASK  SPI0CR1_MSTR_MASK

#define MCF_CFM_CFMCLKD  FCLKDIV
#define MCF_CFM_CFMCLKD_DIVLD  FCLKDIV_FDIVLD_MASK
#define MCF_CFM_CFMUSTAT  FSTAT
#define MCF_CFM_CFMUSTAT_CBEIF  FSTAT_CBEIF_MASK
#define MCF_CFM_CFMUSTAT_PVIOL  FSTAT_PVIOL_MASK
#define MCF_CFM_CFMUSTAT_ACCERR  FSTAT_ACCERR_MASK
#define MCF_CFM_CFMCMD  FCMD
#define MCF_CFM_CFMUSTAT_CCIF  FSTAT_CCIF_MASK
#define MCF_CFM_CFMCLKD_PRDIV8  FCLKDIV_PRDIV8_MASK
#define MCF_CFM_CFMCLKD_DIV(x)  (x)

#else
#define SCI1C1X  SCI1C1
#define SCI1C2X  SCI1C2
#define SCI1S1X  SCI1S1
#define SCI1S2X  SCI1S2
#define SCI1BDHX  SCI1BDH
#define SCI1BDLX  SCI1BDL
#define SCI1DX  SCI1D

#define SCI2C1X  SCI2C1
#define SCI2C2X  SCI2C2
#define SCI2S1X  SCI2S1
#define SCI2S2X  SCI2S2
#define SCI2BDHX  SCI2BDH
#define SCI2BDLX  SCI2BDL
#define SCI2DX  SCI2D

#define SPI1C1X  SPI1C1
#define SPI1C2X  SPI1C2
#define SPI1BRX  SPI1BR
#define SPI1SX  SPI1S
#define SPI1BRX_SPR  SPI1BR_SPR
#define SPI1BRX_SPPR  SPI1BR_SPPR

#define MCF_CFM_CFMCLKD  FCDIV
#define MCF_CFM_CFMCLKD_DIVLD  FCDIV_FDIVLD_MASK
#define MCF_CFM_CFMUSTAT  FSTAT
#define MCF_CFM_CFMUSTAT_CBEIF  FSTAT_FCBEF_MASK
#define MCF_CFM_CFMUSTAT_PVIOL  FSTAT_FPVIOL_MASK
#define MCF_CFM_CFMUSTAT_ACCERR  FSTAT_FACCERR_MASK
#define MCF_CFM_CFMCMD  FCMD
#define MCF_CFM_CFMUSTAT_CCIF  FSTAT_FCCF_MASK
#define MCF_CFM_CFMCLKD_PRDIV8  FCDIV_PRDIV8_MASK
#define MCF_CFM_CFMCLKD_DIV(x)  (x)
#endif

#if MCF51QE128 || MC9S08QE128 || MCF51CN128
#define SPI1DL  SPI1D
#endif
#undef ENDPT_ARR
#define ENDPT_ARR                       ((volatile byte *) &ENDPT0)
#define MCF_USB_OTG_ENDPT(x) ENDPT_ARR[4*(x)]
#define MCF_USB_OTG_ENDPT_EP_HSHK ENDPT0_EP_HSHK_MASK
#define MCF_USB_OTG_ENDPT_EP_RX_EN ENDPT0_EP_RX_EN_MASK
#define MCF_USB_OTG_ENDPT_EP_TX_EN ENDPT0_EP_TX_EN_MASK
#define MCF_USB_OTG_ENDPT_EP_CTL_DIS  ENDPT0_EP_CTL_DIS_MASK
#define MCF_USB_OTG_ENDPT_HOST_WO_HUB ENDPT0_HOST_WO_HUB_MASK
#define MCF_USB_OTG_ENDPT_RETRY_DIS ENDPT0_RETRY_DIS_MASK
#define MCF_USB_OTG_USB_CTRL_CLK_SRC(x)  (x)

#define MCF_USB_OTG_TOKEN_TOKEN_PID(x)  ((x)<<4)
#define MCF_USB_OTG_TOKEN_TOKEN_ENDPT(x)  (x)

#define MCF_CFM_CFMCMD_PAGE_ERASE  0x40
#define MCF_CFM_CFMCMD_WORD_PROGRAM  0x20

// automatic below

#define MCF_USB_OTG_ADDR ADDR
#define MCF_USB_OTG_ADDR_LS_EN ADDR_LS_EN_MASK
#define MCF_USB_OTG_BDT_PAGE_01 BDT_PAGE_01
#define MCF_USB_OTG_BDT_PAGE_02 BDT_PAGE_02
#define MCF_USB_OTG_BDT_PAGE_03 BDT_PAGE_03
#define MCF_USB_OTG_CTL CTL
#define MCF_USB_OTG_CTL_HOST_MODE_EN CTL_HOST_MODE_EN_MASK
#define MCF_USB_OTG_CTL_JSTATE CTL_JSTATE_MASK
#define MCF_USB_OTG_CTL_ODD_RST CTL_ODD_RST_MASK
#define MCF_USB_OTG_CTL_RESET CTL_RESET_MASK
#define MCF_USB_OTG_CTL_TXSUSPEND_TOKENBUSY CTL_TXSUSPEND_TOKENBUSY_MASK
#define MCF_USB_OTG_CTL_USB_EN_SOF_EN CTL_USB_EN_SOF_EN_MASK
#define MCF_USB_OTG_ENDPT0 ENDPT0
#define MCF_USB_OTG_INT_ENB INT_ENB
#define MCF_USB_OTG_INT_ENB_ATTACH_EN INT_ENB_ATTACH_EN_MASK
#define MCF_USB_OTG_INT_ENB_SLEEP_EN INT_ENB_SLEEP_EN_MASK
#define MCF_USB_OTG_INT_ENB_TOK_DNE_EN INT_ENB_TOK_DNE_EN_MASK
#define MCF_USB_OTG_INT_ENB_USB_RST_EN INT_ENB_USB_RST_EN_MASK
#define MCF_USB_OTG_INT_STAT INT_STAT
#define MCF_USB_OTG_INT_STAT_ATTACH INT_STAT_ATTACH_MASK
#define MCF_USB_OTG_INT_STAT_ERROR INT_STAT_ERROR_MASK
#define MCF_USB_OTG_INT_STAT_RESUME INT_STAT_RESUME_MASK
#define MCF_USB_OTG_INT_STAT_SLEEP INT_STAT_SLEEP_MASK
#define MCF_USB_OTG_INT_STAT_STALL INT_STAT_STALL_MASK
#define MCF_USB_OTG_INT_STAT_TOK_DNE INT_STAT_TOK_DNE_MASK
#define MCF_USB_OTG_INT_STAT_USB_RST INT_STAT_USB_RST_MASK
#define MCF_USB_OTG_OTG_CTRL OTG_CTRL
#define MCF_USB_OTG_OTG_CTRL_DM_LOW OTG_CTRL_DM_LOW_MASK
#define MCF_USB_OTG_OTG_CTRL_DP_HIGH OTG_CTRL_DP_HIGH_MASK
#define MCF_USB_OTG_OTG_CTRL_DP_LOW OTG_CTRL_DP_LOW_MASK
#define MCF_USB_OTG_OTG_CTRL_OTG_EN OTG_CTRL_OTG_EN_MASK
#define MCF_USB_OTG_SOF_THLD SOF_THLD
#define MCF_USB_OTG_STAT STAT
#define MCF_USB_OTG_STAT_ODD STAT_ODD_MASK
#define MCF_USB_OTG_STAT_TX STAT_TX_MASK
#define MCF_USB_OTG_TOKEN TOKEN
#define MCF_USB_OTG_USB_CTRL USB_CTRL
