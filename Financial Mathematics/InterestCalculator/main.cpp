#include <iostream>
#include <cmath>

using namespace std;

double compoundInterest(double P, double i, double n)
{
    double interest = P * pow(1 + 0.01*i, n) - P;
    return interest;
}

int main()
{
    int principal;
    double interestRate;
    int numberOfYears;

    cout <<"How much are you investing?\n";
    cin >>principal;
    cout <<"What is the annual interest rate(%)?\n";
    cin >>interestRate;
    cout <<"How long for(years)?\n";
    cin >>numberOfYears;

    double interest = compoundInterest(principal, interestRate, numberOfYears);

    cout <<"You will earn ";
    cout <<interest ;
    cout <<"\n";

    return 0;
}
