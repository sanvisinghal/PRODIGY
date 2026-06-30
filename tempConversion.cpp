#include <iostream>
#include <iomanip>
#include<cctype>
using namespace std;

int main() {
    double temperature;
    char unit;

    cout << "========== TEMPERATURE CONVERSION =========="<<endl;
    cout << "Enter the temperature value: "<<endl;
    cin >> temperature;

    cout << "Enter the unit (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> unit;

    unit = toupper(unit);

    cout << fixed << setprecision(2);

    switch (unit) {
        case 'C':
            cout << "Temperature in Celsius: " << temperature << " C" << endl;
            cout << "Temperature in Fahrenheit: " << (temperature * 9 / 5) + 32 << " F" << endl;
            cout << "Temperature in Kelvin: " << temperature + 273.15 << " K" << endl;
            break;

        case 'F':
            cout << "Temperature in Fahrenheit: " << temperature << " F" << endl;
            cout << "Temperature in Celsius: " << (temperature - 32) * 5 / 9 << " C" << endl;
            cout << "Temperature in Kelvin: " << ((temperature - 32) * 5 / 9) + 273.15 << " K" << endl;
            break;

        case 'K':
            cout << "Temperature in Kelvin: " << temperature << " K" << endl;
            cout << "Temperature in Celsius: " << temperature - 273.15 << " C" << endl;
            cout << "Temperature in Fahrenheit: " << ((temperature - 273.15) * 9 / 5) + 32 << " F" << endl;
            break;

        default:
            cout << "Invalid unit entered! Please enter C, F, or K." << endl;
    }

    return 0;
}