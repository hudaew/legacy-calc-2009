#include "LoanCalculator.h"

LoanCalculator::LoanCalculator() {
    amount = 0;
    interest = 0;
    interestm = 0;
    payment = 0;
    totalmonths = 0;
    passedmonths = 0;
    openingfee = 0;
    openingpercent = 0;
}

void LoanCalculator::setamount(double a) {
    if(a < 0) {
        std::cout << "Invalid loan amount, set to 0.\n";
        amount = 0;
    } else {
        amount = a;
    }
}

void LoanCalculator::setinterest(double r) {
    if(r < 0) {
        std::cout << "Invalid interest rate, set to 0.\n";
        interest = 0;
    } else {
        interest = r;
    }
    interestm = interest / 100.0 / 12.0;
}

void LoanCalculator::settotalmonths(int m) {
    if(m <= 0) {
        std::cout << "Invalid number of months, set to 1.\n";
        totalmonths = 1;
    } else {
        totalmonths = m;
    }
}

void LoanCalculator::setpayment(double p) {
    payment = p;
}

void LoanCalculator::setpassedmonths(int m) {
    if(m < 0) passedmonths = 0;
    else passedmonths = m;
}

void LoanCalculator::setopeningfee(double f) {
    if(f < 0) f = 0;
    openingfee = f;
}

void LoanCalculator::setopeningpercent(double p) {
    if(p < 0) p = 0;
    openingpercent = p;
}

double LoanCalculator::calculatemonthlypayment() {
    if(totalmonths <= 0 || amount <= 0) return 0;

    double i = interestm;

    if(i == 0) {
        return amount / totalmonths;
    }

    long double x = pow(1 + i, totalmonths);
    long double P = (i * amount * x) / (x - 1);
    return static_cast<double>(P);
}

double LoanCalculator::calculateloanbalance() {
    double i = interestm;

    if(i == 0) {
        double b = amount - payment * passedmonths;
        return (b < 0 ? 0 : b);
    }

    long double x = pow(1 + i, passedmonths);
    long double bn = amount * x - (payment / i) * (x - 1);
    return (bn < 0 ? 0 : static_cast<double>(bn));
}

double LoanCalculator::calculatetotalpayment() {
    return payment * totalmonths;
}

double LoanCalculator::calculatetotalinterest() {
    return calculatetotalpayment() - amount;
}

double LoanCalculator::calculateeffectiveinterestrate() {
    if(amount == 0 || totalmonths == 0) return 0;

    double extra = openingfee + (openingpercent / 100.0) * amount;
    double extrapermonth = extra / totalmonths;
    double addrate = extrapermonth / amount;

    double effective = (interestm + addrate) * 12.0 * 100.0;
    return effective;
}
