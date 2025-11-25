#ifndef LOANCALCULATOR_H_INCLUDED
#define LOANCALCULATOR_H_INCLUDED
#include <cmath>
#include <iostream>

class LoanCalculator {
public:
    long double amount;
    long double interest;
    long double interestm;
    long double payment;
    int totalmonths;
    int passedmonths;
    long double openingfee;
    long double openingpercent;

    LoanCalculator() {
        amount = 0; interest = 0; interestm = 0; payment = 0;
        totalmonths = 0; passedmonths = 0; openingfee = 0; openingpercent = 0;
    }

   
    void setamount(long double a){ if(a>=0) amount=a; else amount=0; }
    void setinterest(long double r){ 
        if(r>=0) interest=r; else interest=0; 
        interestm = interest/100.0/12.0; 
    }
    void settotalmonths(int m){ totalmonths = (m>=0 ? m : 0); }
    void setpayment(long double p){ payment=p; }
    void setpassedmonths(int m){ passedmonths = (m>=0 ? m : 0); }
    void setopeningfee(long double f){ openingfee = (f>=0 ? f : 0); }
    void setopeningpercent(long double p){ openingpercent = (p>=0 ? p : 0); }

    // EMI calculation
    long double calculatemonthlypayment(){
        if(totalmonths<=0) return 0;
        long double i = interestm;
        if(i==0) return amount/totalmonths;
        long double x = pow(1+i,totalmonths);
        return (i*amount*x)/(x-1);
    }

    // Balance after passed months
    long double calculateloanbalance(){
        long double i = interestm;
        if(i==0){
            long double b = amount - payment*passedmonths;
            return (b>=0 ? b : 0);
        }
        long double x = pow(1+i,passedmonths);
        long double bn = amount*x - (payment/i)*(x-1);
        return (bn>=0 ? bn : 0);
    }

    long double calculatetotalpayment(){ return payment*totalmonths; }
    long double calculatetotalinterest(){ return calculatetotalpayment() - amount; }

    long double calculateeffectiveinterestrate(){
        if(amount==0 || totalmonths==0) return 0;
        long double extra = openingfee + (openingpercent/100.0)*amount;
        long double extrapermonth = extra/totalmonths;
        long double addrate = extrapermonth/amount;
        return (interestm + addrate)*12*100;
    }
};

#endif
