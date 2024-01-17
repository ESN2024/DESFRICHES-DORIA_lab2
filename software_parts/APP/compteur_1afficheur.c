#include "system.h"
#include "sys/alt_stdio.h"
#include "alt_types.h"
#include "io.h"
#include <stdlib.h>
#include <unistd.h>
#include "altera_avalon_pio_regs.h"

#define DELAI 50000


int main()
{
    __uint8_t val;
    while(1)
    {
        for(val = 0; val<=9; val++)
        IOWR_ALTERA8AVALON_PIO_DATA(PIO_0_BASE, val);
        usleep(DELAI);
    }
}
