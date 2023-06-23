#include "MCHP_modelInclude.h"

void PWM_Override(unsigned int);
void PWM_Scheme_Select(unsigned int);
void APP_UpdatePWMConfig_Scheme1(void);
void APP_UpdatePWMConfig_Scheme2(void);
void APP_UpdatePWMConfig_Scheme3(void);

unsigned int schemePWM = 0;

unsigned int PWM1[3][6] = {{0x1000, 0x1000, 0x3000, 0x2000, 0x2000, 0x3000},
					      {0x0000, 0x3000, 0x3400, 0x3400, 0x3000, 0x0000},
					      {0x0000, 0x0000, 0x3000, 0x4000, 0x4000, 0x7000}};

unsigned int PWM2[3][6] = {{0x2000, 0x3000, 0x1000, 0x1000, 0x3000, 0x2000},
					      {0x3000, 0x0000, 0x0000, 0x3000, 0x3400, 0x3400},
					      {0x4000, 0x7000, 0x0000, 0x0000, 0x3000, 0x4000}};

unsigned int PWM3[3][6] = {{0x3000, 0x2000, 0x2000, 0x3000, 0x1000, 0x1000},
				          {0x3400, 0x3400, 0x3000, 0x0000, 0x0000, 0x3000},
					      {0x3000, 0x4000, 0x4000, 0x7000, 0x0000, 0x0000}};

void PWM_Override(unsigned int sector)
{
    PG1IOCONL = PWM1[schemePWM][sector];
    PG2IOCONL = PWM2[schemePWM][sector];
    PG3IOCONL = PWM3[schemePWM][sector];
}

void PWM_Scheme_Select(unsigned int switch_case)
{
    switch(switch_case)
        {
            case 0: 
                PG3CONLbits.ON = 0;
                PG2CONLbits.ON = 0;
                PG1CONLbits.ON = 0;
            break;
            case 1: 
                APP_UpdatePWMConfig_Scheme1();
                schemePWM = 0;
            break;
            case 2:
                PG3CONLbits.ON = 0;
                PG2CONLbits.ON = 0;
                PG1CONLbits.ON = 0;
            break;
            case 3:
                APP_UpdatePWMConfig_Scheme2();
                schemePWM = 1;
            break;
            case 4: 
                PG3CONLbits.ON = 0;
                PG2CONLbits.ON = 0;
                PG1CONLbits.ON = 0;
            break;
            case 5:   
                APP_UpdatePWMConfig_Scheme3();
                schemePWM = 2;
            break;
        }
}

void APP_UpdatePWMConfig_Scheme1(void)
{ 
    PG3CONLbits.MODSEL = 0;
    PG3IOCONHbits.PMOD = 1;
    PG2CONLbits.MODSEL = 0;
    PG2IOCONHbits.PMOD = 1;
    PG1CONLbits.MODSEL = 0;
    PG1IOCONHbits.PMOD = 1;
    
    MPER = 10000;
    MDC  = 5000;
    PG1STATbits.UPDREQ = 1;
    

    PG3CONLbits.ON = 1;
    PG2CONLbits.ON = 1;
    PG1CONLbits.ON = 1;
}

void APP_UpdatePWMConfig_Scheme2(void)
{
    PG3CONLbits.MODSEL = 0;
    PG3IOCONHbits.PMOD = 0;
    PG2CONLbits.MODSEL = 0;
    PG2IOCONHbits.PMOD = 0;
    PG1CONLbits.MODSEL = 0;
    PG1IOCONHbits.PMOD = 0;
    
    MPER = 10000;
    MDC  = 5000;
    PG1DTH = 100;
    PG1DTL = 100;
    PG1STATbits.UPDREQ = 1;
    
    PG3CONLbits.ON = 1;
    PG2CONLbits.ON = 1;
    PG1CONLbits.ON = 1;
    
}

void APP_UpdatePWMConfig_Scheme3(void)
{
    PG3CONLbits.MODSEL = 4;
    PG3IOCONHbits.PMOD = 0;
    PG2CONLbits.MODSEL = 4;
    PG2IOCONHbits.PMOD = 0;
    PG1CONLbits.MODSEL = 4;
    PG1IOCONHbits.PMOD = 0;
    
    MPER = 5000;
    MDC  = 2500;
    PG1DTH = 200;
    PG1DTL = 200;
    PG1STATbits.UPDREQ = 1;
    
    PG3CONLbits.ON = 1;
    PG2CONLbits.ON = 1;
    PG1CONLbits.ON = 1;
}
