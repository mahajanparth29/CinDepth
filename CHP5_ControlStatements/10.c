#include <stdio.h>

int main(void)
{
    int limit = 50;
    printf("Pythagorean triplets with values less than %d:\n", limit);

    for (int x = 1; x < limit; ++x) {
        for (int y = x + 1; y < limit; ++y) {
            for (int z = y + 1; z < limit; ++z) {
                if (x*x + y*y == z*z) {
                    printf("(%d, %d, %d)\n", x, y, z);
                }
            }
        }
    }

    return 0;
}