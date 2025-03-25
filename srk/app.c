#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define GHS_MULTI         (1U << 0)  // 0x01
#define LAUTERBACH        (1U << 1)  // 0x02
#define S32_DESIGN_STUDIO (1U << 2)  // 0x04
#define OSCILLOSCOPE      (1U << 3)  // 0x08
#define TRACE_ANALYZER    (1U << 4)  // 0x10
#define LOGIC_ANALYZER    (1U << 5)  // 0x20

int sub_main(void)
{
	uint8_t expertise = (uint8_t)(GHS_MULTI | LAUTERBACH | S32_DESIGN_STUDIO | OSCILLOSCOPE | TRACE_ANALYZER | LOGIC_ANALYZER);
	printf("Expertise Bitmask (hex): 0x%02X\n", expertise);
	return expertise;
}
int main()
{
	printf("Hello! Welcome to Linux \n", __func__);
	printf("expertise  : %d \n", sub_main());
	printf("%s = pid %u", __func__, getpid());
    getchar();
	return 0;
}