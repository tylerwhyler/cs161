/*  
    Author: Tyler Isaacson
    Assignment: CS161 a03.cpp
    Date: October 24th, 2021
    Description: Give user statistical data from all the jellybean estimates
    Input: 2 doubles and 1 integer
    Output: Strings with doubles and integers within them
    Sources:
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <string>

using namespace std;

int main() {
    const double PI = 3.14159265358979323846;
    const double LOADFACTOR = 0.605;

    double beanLength;
    double beanHeight;
    int jarVolume;
    double avgJellySize;
    int numJellyInJar;
    int jellyAccumulator = 0;
    int entriesAccumulator = 0;
    int jarVolForMaxEstimate = 0;
    double jellyLengthWhenMax = 0.0;
    double jellyHeightWhenMax = 0.0;
    int maxEstimate = 0;
    bool flag = true;

    do {
        cout << fixed << setprecision(2) << "\nIn centimeters, enter jellybean length and height, \nthen the volume of the jar in millimeters (cm cm ml)[0 0 0 to quit]:\n";
        cin >> beanLength >> beanHeight >> jarVolume;
        cin.ignore(100, '\n');
        cin.clear();

        if(beanLength != 0 && beanHeight != 0 && int(jarVolume) != 0) {
            entriesAccumulator += 1;
            avgJellySize = ( 5 * PI * beanLength * pow(beanHeight, 2.0)) / 24.0;
            numJellyInJar = static_cast<int>(jarVolume * LOADFACTOR / avgJellySize);

            cout << "\nJellybean size: (" << beanLength << "cm x " << beanHeight << "cm)\n" << endl;
            cout << "Roughly " << numJellyInJar;
            if (numJellyInJar == 1) {
                cout << " jellybean would fit into a " << jarVolume << "ml jar" << endl;
            }
            else {
                cout << " jellybeans would fit into a " << jarVolume << "ml jar" << endl;
            }
            if (maxEstimate < numJellyInJar) {
                maxEstimate = numJellyInJar;
                jarVolForMaxEstimate = jarVolume;
                jellyLengthWhenMax = beanLength;
                jellyHeightWhenMax = beanHeight;
            }

            jarVolume = 0;

            jellyAccumulator += numJellyInJar;
            numJellyInJar = 0;
        }
        else flag = false;

    } while(flag);

    cout << "\nTotal number of entries: " << entriesAccumulator << endl;
    cout << "Average number of jellybeans: " << (jellyAccumulator * 1.0) / (entriesAccumulator * 1.0) << endl;
    cout << "Largest Estimate: " << maxEstimate << " jellybeans" << endl;
    cout << "Jellybean size for the largest estimate:  " << jellyLengthWhenMax << " cm and " << jellyHeightWhenMax << " cm" << endl;
    cout << "Jar volume for the largest estimate:  " << jarVolForMaxEstimate << " ml" << endl;

    cout << "\n\nGoodbye\n" << endl;

    return 0;
}