#ifndef LOANCALCULATOR_H_INCLUDED
#define LOANCALCULATOR_H_INCLUDED

#include <iostream>
#include <cmath>

/**
 * @class LoanCalculator
 * @brief Calculates loan payments, balances, total interest, and effective interest rates.
 */
class LoanCalculator {
public:
    double amount;          ///< Principal loan amount
    double interest;        ///< Yearly interest rate (%)
    double interestm;       ///< Monthly interest rate
    double payment;         ///< Monthly payment
    int totalmonths;        ///< Total months of loan
    int passedmonths;       ///< Number of months already passed
    double openingfee;      ///< Opening fee
    double openingpercent;  ///< Opening percent fee

    LoanCalculator();

    void setamount(double a);
    void setinterest(double r);
    void settotalmonths(int m);
    void setpayment(double p);
    void setpassedmonths(int m);
    void setopeningfee(double f);
    void setopeningpercent(double p);

    double calculatemonthlypayment();
    double calculateloanbalance();
    double calculatetotalpayment();
    double calculatetotalinterest();
    double calculateeffectiveinterestrate();
};

#endif

