#include <stdio.h>

int main()
{
    float radius, area, perimeter;
    float pi = 3.14;

    printf("Enter radius of circle: ");
    scanf("%f", &radius);

    area = pi * radius * radius;
    perimeter = 2 * pi * radius;

    printf("Area of circle = %.2f\n", area);
    printf("Perimeter of circle = %.2f", perimeter);

    return 0;
}
