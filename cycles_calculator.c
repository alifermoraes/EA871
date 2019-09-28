#include <stdio.h>
#include <stdint.h>

#define R1 198
#define R2 21
#define R24 232
#define R25 3

double count_base_cycles(uint8_t r1, uint8_t r2);
double count_parameter_cycles(uint8_t r1, uint8_t r2, uint8_t r24, uint8_t r25);

int main(void) {
    double counter = 0.0;

    counter += count_parameter_cycles(R1, R2, R24, R25);

    printf("%.10lf\n", counter / 16000);
    return 0;
}

double count_base_cycles(uint8_t r1, uint8_t r2) {
    double counter = 2.0; /* R1, R2 LDI */

    while(r2) {
        r1--;
        if (r1) {
            counter += 3;
            continue;
        } counter += 2;

        r2--;
        if (r2) {
            counter += 3;
            continue;
        } counter += 2;
    }

    return counter;
}

double count_parameter_cycles(uint8_t r1, uint8_t r2, uint8_t r24, uint8_t r25) {
    double counter = 9.0; /* R1, R2, R24, R25 PUSH/POP; INC R25 */
    double base_cycles = count_base_cycles(r1, r2);
    r25++;
    
    while(r25) {
        counter += base_cycles;

        r24--;
        if (r24) {
            counter += 3;
            continue;
        } counter += 2;

        r25--;
        if (r25) {
            counter += 3;
            continue;
        } counter += 2;
    }

    return counter;
}
