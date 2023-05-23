#include "MCHP_modelInclude.h"

void inline PWMOverride_Scheme1(unsigned int sector)
{ 
    //Independent Edge PWM mode
    PG3CONLbits.MODSEL = 0;
    PG2CONLbits.MODSEL = 0;
    PG1CONLbits.MODSEL = 0;

    // Independent Output Mode
    PG3IOCONHbits.PMOD = 1;
    PG2IOCONHbits.PMOD = 1;
    PG1IOCONHbits.PMOD = 1;

    const unsigned int PWM_STATE3_CLKW[8]	=	{0x3000,0x1000,0x1000,0x3000,0x2000,0x2000,0x3000,0x3000};
    const unsigned int PWM_STATE2_CLKW[8]	=	{0x3000,0x2000,0x3000,0x1000,0x1000,0x3000,0x2000,0x3000};
    const unsigned int PWM_STATE1_CLKW[8]	=	{0x3000,0x3000,0x2000,0x2000,0x3000,0x1000,0x1000,0x3000};

    
    // Override State is drive low
    PG3IOCONL = PWM_STATE1_CLKW[sector];
    PG2IOCONL = PWM_STATE2_CLKW[sector];
    PG1IOCONL = PWM_STATE3_CLKW[sector];
}

void inline PWMOverride_Scheme2(unsigned int sector)
{ 
    //Independent Edge PWM mode
    PG3CONLbits.MODSEL = 0;
    PG2CONLbits.MODSEL = 0;
    PG1CONLbits.MODSEL = 0;

    // Complementary Output Mode
    PG3IOCONHbits.PMOD = 0;
    PG2IOCONHbits.PMOD = 0;
    PG1IOCONHbits.PMOD = 0;

    const unsigned int PWM_STATE3_CLKW[8]	=	{0x3000,0x0000,0x0000,0x3000,0x3400,0x3400,0x3000,0x3000};
    const unsigned int PWM_STATE2_CLKW[8]	=	{0x3000,0x3400,0x3000,0x0000,0x0000,0x3000,0x3400,0x3000};
    const unsigned int PWM_STATE1_CLKW[8]	=	{0x3000,0x3000,0x3400,0x3400,0x3000,0x0000,0x0000,0x3000};

    // Override State is Dependent on Sector State
    PG3IOCONL = PWM_STATE1_CLKW[sector];
    PG2IOCONL = PWM_STATE2_CLKW[sector];
    PG1IOCONL = PWM_STATE3_CLKW[sector];
}

void inline PWMOverride_Scheme3(unsigned int sector)
{ 
    //Center-Aligned PWM mode
    PG3CONLbits.MODSEL = 4;
    PG2CONLbits.MODSEL = 4;
    PG1CONLbits.MODSEL = 4;

    // Complementary Output Mode
    PG3IOCONHbits.PMOD = 0;
    PG2IOCONHbits.PMOD = 0;
    PG1IOCONHbits.PMOD = 0;

    const unsigned int PWM_STATE3_CLKW[8]	=	{0x3000,0x0000,0x0000,0x3000,0x4000,0x4000,0x7000,0x3000};
    const unsigned int PWM_STATE2_CLKW[8]	=	{0x3000,0x4000,0x7000,0x0000,0x0000,0x3000,0x4000,0x3000};
    const unsigned int PWM_STATE1_CLKW[8]	=	{0x3000,0x3000,0x4000,0x4000,0x7000,0x0000,0x0000,0x3000};

    // Override and SWAP State is Dependent on Sector State
    PG3IOCONL = PWM_STATE1_CLKW[sector];
    PG2IOCONL = PWM_STATE2_CLKW[sector];
    PG1IOCONL = PWM_STATE3_CLKW[sector];
}