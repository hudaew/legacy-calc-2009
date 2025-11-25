#include <iostream>
#include <iomanip>
#include "LoanCalculator.h"
using namespace std;

int main() {
    LoanCalculator loan;
    long double a, r, fee, per;
    int m, pm;

    cout << "Enter loan amount: ";
    cin >> a;
    if(a<0) { cout<<"Invalid amount\n"; return 1; }
    loan.setamount(a);

    cout << "Enter yearly interest rate (%): ";
    cin >> r;
    if(r<0) { cout<<"Invalid interest rate\n"; return 1; }
    loan.setinterest(r);

    cout << "Enter total months: ";
    cin >> m;
    if(m<=0) { cout<<"Invalid months\n"; return 1; }
    loan.settotalmonths(m);

    loan.setpayment(loan.calculatemonthlypayment());

    cout << "Enter passed months: ";
    cin >> pm;
    if(pm<0) { cout<<"Invalid months\n"; return 1; }
    loan.setpassedmonths(pm);

    cout << "Enter opening fee: ";
    cin >> fee;
    if(fee<0) fee=0;
    loan.setopeningfee(fee);

    cout << "Enter opening percent (% of loan): ";
    cin >> per;
    if(per<0) per=0;
    loan.setopeningpercent(per);

    long double balance = loan.calculateloanbalance();
    long double totalpay = loan.calculatetotalpayment();
    long double interest_total = loan.calculatetotalinterest();
    long double effrate = loan.calculateeffectiveinterestrate();

    cout << fixed << setprecision(2) << endl;
    cout << "Loan Report" << endl;
    cout << "===============================" << endl;
    cout << "Loan amount: " << loan.amount << endl;
    cout << "Interest rate: " << loan.interest << "%" << endl;
    cout << "Monthly payment: " << loan.payment << endl;
    cout << "Balance after " << pm << " months: " << balance << endl;
    cout << "Total payment: " << totalpay << endl;
    cout << "Total interest: " << interest_total << endl;
    cout << "Effective interest (with fees): " << effrate << "%" << endl;
    cout << "===============================" << endl;

    return 0;
}