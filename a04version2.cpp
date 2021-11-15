/*  
    Author: Tyler Isaacson
    Assignment: CS161 a04_version2.cpp
    Date: November 13th, 2021
    Description: refactor assignment ao3.cpp to be more modular with functions, where possible
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

const double PI = 3.14159265358979323846;
const double LOADFACTOR = 0.605;

void IterationOutput(int, int, double, double);
void FinalOutput(int, int , int, double, double, int);
double CalcJellySize(double, double);
int CalcNumJellyInJar(int, double);
int AccumulateJellys(int, int);

int main() {
    double beanLength;
    double beanHeight;
    int jarVolume;
    double jellySize;
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
            jellySize = CalcJellySize(beanLength, beanHeight);
            numJellyInJar = CalcNumJellyInJar(jarVolume, jellySize);
        
            IterationOutput(numJellyInJar, jarVolume, beanLength, beanHeight);

            if (maxEstimate < numJellyInJar) {
                maxEstimate = numJellyInJar;
                jarVolForMaxEstimate = jarVolume;
                jellyLengthWhenMax = beanLength;
                jellyHeightWhenMax = beanHeight;
    }
            jellyAccumulator = AccumulateJellys(jellyAccumulator, numJellyInJar);
            numJellyInJar = 0;
        }
        else flag = false;

    } while(flag);

    FinalOutput(entriesAccumulator, jellyAccumulator, maxEstimate, jellyLengthWhenMax, jellyHeightWhenMax, jarVolForMaxEstimate);

    return 0;
}

void IterationOutput(int numJellyInJar, int jarVolume, double beanLength, double beanHeight) {
    cout << "\nJellybean size: (" << beanLength << "cm x " << beanHeight << "cm)\n" << endl;
    cout << "Roughly " << numJellyInJar;
    if (numJellyInJar == 1) {
        cout << " jellybean would fit into a " << jarVolume << "ml jar" << endl;
    }
    else {
        cout << " jellybeans would fit into a " << jarVolume << "ml jar" << endl;
    }
}

void FinalOutput(int entriesAccumulator, int jellyAccumulator, int maxEstimate, double jellyLengthWhenMax, double jellyHeightWhenMax, int jarVolForMaxEstimate) {
    cout << "\nTotal number of entries: " << entriesAccumulator << endl;
    cout << "Average number of jellybeans: " << (jellyAccumulator * 1.0) / (entriesAccumulator * 1.0) << endl;
    cout << "Largest Estimate: " << maxEstimate << " jellybeans" << endl;
    cout << "Jellybean size for the largest estimate:  " << jellyLengthWhenMax << " cm and " << jellyHeightWhenMax << " cm" << endl;
    cout << "Jar volume for the largest estimate:  " << jarVolForMaxEstimate << " ml" << endl;
    cout << "\n\nGoodbye\n" << endl;
}

double CalcJellySize(double beanLength, double beanHeight) {
    return ( 5 * PI * beanLength * pow(beanHeight, 2.0)) / 24.0;
}

int CalcNumJellyInJar(int jarVolume, double jellySize) {
    return static_cast<int>(jarVolume * LOADFACTOR / jellySize);
}

int AccumulateJellys(int jellyAccumulator, int numJellyInJar) {
    jellyAccumulator += numJellyInJar;
    return jellyAccumulator;
}
