#include "xc.h"

void delay_ms(time) 
{
    for(int i = 0; i < time*10000; i++){
        Nop();
    }
}