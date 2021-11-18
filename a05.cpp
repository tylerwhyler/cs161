//  Author: Tyler Isaacson
//  Assignment: CS161 a05.cpp
//  Date: November 15th, 2021
//  Description: Menu driven gym membership simulator
//  Input: 1 char input and 2 int inputs
//  Output: Multiple lines of strings with integers and floating point values concatenated inside
//  Sources:

#include <iostream>
#include <iomanip>
#include <ctype.h>

using namespace std;

const double MEMBERSHIP_MONTHLY_FEE = 29.99;
const double PERSONAL_TRAINING_SESSION_FEE = 14.99;
const double YEAR_MEMBERSHIP_DISCOUNT = 0.10;
const double FIVE_PERSONAL_TRAINING_SESSIONS_DISCOUNT = 0.20;
const double SENIOR_DISCOUNT = 0.30;

void WelcomeMessage();
void UserInputContinueOrQuit(char&);
void CalcSubTotalCost(int, int, double&, double&, double&);
void GetAndPromptUserInputs(char&, int&, int&);
void TrySeniorDiscount(char, double, double&);
void IterationOutput(int, int, double, double, double, double&);

int main() {
    char userContinue;
    int numOfMembershipMonths;
    int numOfTrainingSessions;
    char isSenior = 'n';
    double subTotalCost;
    double totalCost;
    double totalMonthlyFees;
    double totalTrainingFees;

    do {
        WelcomeMessage();

        UserInputContinueOrQuit(userContinue);
        if (toupper(userContinue) == 'B') { // if user enters b, quit program right here
            return 0;
        }

        GetAndPromptUserInputs(isSenior, numOfMembershipMonths, numOfTrainingSessions);
        CalcSubTotalCost(numOfMembershipMonths, numOfTrainingSessions, subTotalCost, totalMonthlyFees, totalTrainingFees);
        TrySeniorDiscount(isSenior, subTotalCost, totalCost);
        
        IterationOutput(numOfMembershipMonths, numOfTrainingSessions, totalTrainingFees, subTotalCost, totalCost, totalMonthlyFees);
    
    } while (userContinue != 'b');

    return 0;
}

void WelcomeMessage() {
    cout << "Welcome to my fitClub program!!" << endl;
    cout << "The cost to become a member of the fitClub center is as follows:" << endl;
    cout << "\n\t1. The membership fee per month is $" << MEMBERSHIP_MONTHLY_FEE << endl;
    cout << "\t2. The personal training session fee per session is $" << PERSONAL_TRAINING_SESSION_FEE << endl;
    cout << "\t3. If the membership is bought and paid for 12 or more \n\t   months, the discount is " << YEAR_MEMBERSHIP_DISCOUNT * 100 << "% off membership cost." << endl;
    cout << "\t4. If more than five personal training sessions are bought\n\t   and paid for, the discount on each session is 20%." << endl;
    cout << "\t5. The senior citizens discount is " << int(SENIOR_DISCOUNT * 100) << "% off the total amount." << endl;
    cout << "\nPlease pick one of the following options:\n" << endl;
    cout << "\ta. Calculate membership costs." << endl;
    cout << "\tb. quit this program.\n" << endl;
}

void UserInputContinueOrQuit(char& userContinue) {
    cin >> userContinue;
    while (toupper(userContinue) != 'A' && toupper(userContinue) != 'B') {
        cout << "Bad input" << endl;
        cin >> userContinue;
    } 
}

void GetAndPromptUserInputs(char& isSenior, int& numOfMembershipMonths, int& numOfTrainingSessions) {
    cout << endl << "Are you a Senior Citizen (y|Y/n|N): " << flush;
    cin >> isSenior;
    while (toupper(isSenior) != 'Y' && toupper(isSenior) != 'N') {
        cout << "Bad input" << endl;
        cin >> isSenior;
    }
    cout << endl << "How many months of membership would you like? " << flush;
    cin >> numOfMembershipMonths;
    cout << endl << "How many personal training sessions would you like? " << flush;
    cin >> numOfTrainingSessions;
}

void CalcSubTotalCost(int numOfMembershipMonths, int numOfTrainingSessions, double& subTotalCost, double& totalMonthlyFees, double& totalTrainingFees) {
    totalMonthlyFees = numOfMembershipMonths * MEMBERSHIP_MONTHLY_FEE;
    totalTrainingFees = numOfTrainingSessions * PERSONAL_TRAINING_SESSION_FEE;
    if (numOfMembershipMonths >= 12) {
        totalMonthlyFees = totalMonthlyFees * (1.00 - YEAR_MEMBERSHIP_DISCOUNT);
    }
    if (numOfTrainingSessions > 5) {
        totalTrainingFees = totalTrainingFees * (1.00 - FIVE_PERSONAL_TRAINING_SESSIONS_DISCOUNT);
    }
    subTotalCost = totalMonthlyFees + totalTrainingFees;
}

void TrySeniorDiscount(char isSenior, double subTotalCost, double& totalCost) {
    if (toupper(isSenior) == 'Y') {
        totalCost = subTotalCost * (1 - SENIOR_DISCOUNT);
    }
    else {
        totalCost = subTotalCost;
    }
}

void IterationOutput(int numOfMembershipMonths, int numOfTrainingSessions, double totalTrainingFees, double subTotalCost, double totalCost, double& totalMonthlyFees) {
    cout << "\n\n---------------------------------------------------------------------" << endl;
    cout << "Your membership cost";
    if (numOfMembershipMonths >= 12) {
        cout << " after the " << YEAR_MEMBERSHIP_DISCOUNT * 100 << "% off";
    }
    cout << fixed << setprecision(2) << " is $" << totalMonthlyFees << endl;
    cout << "\nYour personal training cost for " << numOfTrainingSessions << " sessions is $" << totalTrainingFees << endl; 
    cout << "\nYour total membership cost is $" << subTotalCost << endl;
    cout << "\nAfter your Senior discount, your membership cost is $" << totalCost << endl;
    cout << "\nThank you for checking out my fitClub center!!  Come back and be fit!" << endl;
    cout << "---------------------------------------------------------------------\n\n" << endl;

}