#include <iostream>
using namespace std;

// Function for Delta to Star Conversion
void deltaTOstar(double R1d, double R2d, double R3d)
{
    // Calculate star circuit resistances
    double R1s = ((R1d * R2d) / (R1d + R2d + R3d));
    double R2s = ((R2d * R3d) / (R1d + R2d + R3d));
    double R3s = ((R3d * R1d) / (R1d + R2d + R3d));

    // Display the conversion and calculated resistances
    cout << "Delta to Star Conversion (DD=SS)" << endl;
    cout << "R1s = " << R1s << endl;
    cout << "R2s = " << R2s << endl;
    cout << "R3s = " << R3s << endl;
}

// Function for Star to Delta Conversion
void starTOdelta(double R1s, double R2s, double R3s)
{
    // Calculate delta circuit resistances
    double R1d = (((R1s * R2s) + (R2s * R3s) + (R3s * R1s)) / (R2s));
    double R2d = (((R1s * R2s) + (R2s * R3s) + (R3s * R1s)) / (R3s));
    double R3d = (((R1s * R2s) + (R2s * R3s) + (R3s * R1s)) / (R1s));

    // Display the conversion and calculated resistances
    cout << "Star to Delta Conversion (SS=DD)" << endl;
    cout << "R1d = " << R1d << endl;
    cout << "R2d = " << R2d << endl;
    cout << "R3d = " << R3d << endl;
}

int main()
{
    double R1, R2, R3; // Use double for precision

    cout << "Select your Conversion method:" << endl;
    cout << "1. Delta to Star Conversion" << endl;
    cout << "2. Star to Delta Conversion" << endl;

    int choice;
    cout << "Method = ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter Delta Circuit Resistance R1 = ";
            cin >> R1;
    
            cout << "Enter Delta Circuit Resistance R2 = ";
            cin >> R2;
    
            cout << "Enter Delta Circuit Resistance R3 = ";
            cin >> R3;
    
            deltaTOstar(R1, R2, R3);
            break;

        case 2:
            cout << "Enter Star Circuit Resistance R1s = ";
            cin >> R1;
    
            cout << "Enter Star Circuit Resistance R2s = ";
            cin >> R2;
    
            cout << "Enter Star Circuit Resistance R3s = ";
            cin >> R3;
    
            starTOdelta(R1, R2, R3);
            break;

        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}
