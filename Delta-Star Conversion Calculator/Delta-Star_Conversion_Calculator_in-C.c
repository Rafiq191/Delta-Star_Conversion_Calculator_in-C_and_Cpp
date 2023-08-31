#include <stdio.h>

// Function for Delta to Star Conversion
void deltaTOstar(double R1d, double R2d, double R3d)
{
    // Calculate star circuit resistances
    double R1s = ((R1d * R2d) / (R1d + R2d + R3d));
    double R2s = ((R2d * R3d) / (R1d + R2d + R3d));
    double R3s = ((R3d * R1d) / (R1d + R2d + R3d));

    // Display the conversion and calculated resistances
    printf("Delta to Star Conversion (DD=SS)\n");
    printf("R1s = %0.2lf\n", R1s);
    printf("R2s = %0.2lf\n", R2s);
    printf("R3s = %0.2lf\n", R3s);
}

// Function for Star to Delta Conversion
void starTOdelta(double R1s, double R2s, double R3s)
{
    // Calculate delta circuit resistances
    double R1d = (((R1s * R2s) + (R2s * R3s) + (R3s * R1s)) / (R2s));
    double R2d = (((R1s * R2s) + (R2s * R3s) + (R3s * R1s)) / (R3s));
    double R3d = (((R1s * R2s) + (R2s * R3s) + (R3s * R1s)) / (R1s));

    // Display the conversion and calculated resistances
    printf("Star to Delta Conversion (SS=DD)\n");
    printf("R1d = %0.2lf\n", R1d);
    printf("R2d = %0.2lf\n", R2d);
    printf("R3d = %0.2lf\n", R3d);
}

int main()
{
    double R1, R2, R3; // Use double for precision

    printf("Select your Conversion method:\n");
    printf("1. Delta to Star Conversion\n");
    printf("2. Star to Delta Conversion\n");

    int choice;
    printf("Method = ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter Delta Circuit Resistance R1 = ");
            scanf("%lf", &R1);
    
            printf("Enter Delta Circuit Resistance R2 = ");
            scanf("%lf", &R2);
    
            printf("Enter Delta Circuit Resistance R3 = ");
            scanf("%lf", &R3);
    
            deltaTOstar(R1, R2, R3);
            break;

        case 2:
            printf("Enter Star Circuit Resistance R1s = ");
            scanf("%lf", &R1);
    
            printf("Enter Star Circuit Resistance R2s = ");
            scanf("%lf", &R2);
    
            printf("Enter Star Circuit Resistance R3s = ");
            scanf("%lf", &R3);
    
            starTOdelta(R1, R2, R3);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}