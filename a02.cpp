#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <cstring>

using namespace std;

string doubleFormatter(double givenDoub) {
    string tempStr = to_string(givenDoub);
    if (tempStr.at(tempStr.size() - 4) >= 54 && tempStr.at(tempStr.size() - 4) <= 57) {
        tempStr.at(tempStr.size() - 5) = int(tempStr.at(tempStr.size() - 5)) + 1;
    }
    return ("$" + tempStr).substr(0, ("$" + tempStr).size() - 4);
}

int main() {
    const double FALL = 49.62;
    const double WINTER = 57.30;
    const double SPRING = 73.22;
    const double SUMMER = 101.70;

    int seasonSelect;
    int numOfRooms;
    int numOfDays;
    double tax;
    double seasonPrice;
    double totalCost;
    double discount;

    cout << fixed << setprecision(2) << "What season will your booking be in? (1)Fall (2)Winter (3)Spring (4)Summer:" << endl;
    cin >> seasonSelect;
    cout << "How many rooms? (10% discount if over 5 rooms!):" << endl;
    cin >> numOfRooms;
    cout << "How many nights will you be staying?:" << endl;
    cin >> numOfDays;
    cout << "What is your state's tax rate? (ex: enter 5.5 for 5.5%) If you have no state tax, enter 0:" << endl;
    cin >> tax;

    tax = tax / 100.0;

    cout << left << setw(16) << "\nSeason" << right << setw(13);
    switch (seasonSelect) {
        case 1:
            cout << "Fall" << endl;
            seasonPrice = FALL;
            break;
        case 2:
            cout << "Winter" << endl;
            seasonPrice = WINTER;
            break;
        case 3:
            cout << "Spring" << endl;
            seasonPrice = SPRING;
            break;
        case 4:
            cout << "Summer" << endl;
            seasonPrice = SUMMER;
            break;
        default:
            throw invalid_argument("\nInvalid input, please restart booking process");
    }

    totalCost = seasonPrice * numOfDays * numOfRooms;

    cout << left << setw(16) << "Price per night:" << right << setw(12) << doubleFormatter(seasonPrice) << endl;
    cout << left << setw(16) << "Number of rooms:" << right << setw(12) << numOfRooms << endl;
    cout << left << setw(16) << "Days of stay:" << right << setw(12) << numOfDays << endl;
    cout << left << setw(16) << "Price:" << right << setw(12) << doubleFormatter(totalCost) << endl;

    discount = (numOfRooms >= 6) ? 0.9 : 1.0;
    cout << left << setw(16) << "Discount:" << right << setw(12) << doubleFormatter((totalCost - (discount * totalCost))) << endl;
    
    totalCost = discount * totalCost;
    cout << left << setw(16) << "Sub-total:" << right << setw(12) << doubleFormatter(totalCost) << endl;

    cout << left << setw(16) << "Tax:" << right << setw(12) << doubleFormatter(totalCost * tax) << endl;
    totalCost = totalCost * (1.0 + tax);
    cout << left << setw(16) << "Total:" << right << setw(12) << doubleFormatter(totalCost) << endl;
            
}
