#include <stdio.h>
#include <stdint.h>

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

int main() {
    struct Computer computer = {3.2, 8, 32};

    //TODO: Change the bits to 64
    //TODO: print out the structure members

    computer.bits = 64;

    printf("CPU speed:\t%g \n", computer.cpu_speed_GHz);
    printf("RAM size:\t%d \n", computer.ram_size_GB);
    printf("bits:\t\t%d \n", computer.bits);

    return 0;
}
