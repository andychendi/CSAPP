#include <stdio.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
    unsigned sign = f>>31;
    unsigned exp = f>>23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (exp == 0xFF && frac != 0) {
        // NAN. return f
        return f;
    }
    // reassemble bits
    return (~sign << 31) | (exp << 23) | frac;
}

int main() {
    unsigned x;
    unsigned y;
    x = 0xfff01234; //nan
    printf("%f \n",*(float *)&x);
    printf("%u \n",float_negate(x));
    x = 0x3f000000;//+0.5f
    printf("%f \n",*(float *)&x);
    y = float_negate(x);
    printf("%f \n",*(float *)&y);
    x = 0xbf000000;//-0.5f
    printf("%f \n",*(float *)&x);
    y = float_negate(x);
    printf("%f \n",*(float *)&y);
}