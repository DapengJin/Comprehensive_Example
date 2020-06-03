//
// Created by 45184 on 2020/5/3.
//

#include "CreditAccount.h"
#include <iostream>
using namespace std;

double CreditAccount::getAvailableCredit() const {
    if (getBalance() < 0)
        return credit + getBalance();
    else
        return credit;
}

double CreditAccount::getDebt() const {
    double balance = getBalance();
    return (balance < 0 ? balance: 0);
}

CreditAccount::CreditAccount(const string &id, Date &date, double credit, double rate, double fee)
        : Account(id, date), credit(credit), rate(rate), fee(fee), acc(date, 0) {

}

void CreditAccount::deposit(const Date &date, double amount, const string &desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void CreditAccount::withdraw(const Date &date, double amount, const string &desc) {
    if (amount - getBalance() > credit)
        error("not enough credit");
    else{
        record(date, -amount, desc);
        acc.change(date, getDebt()); // 因为在信用卡了，存款是不计利息的，只有欠款收利息
    }
}

void CreditAccount::settle(const Date &date) {
    double interest = acc.getSum(date) * rate / (date - Date(date.getYear() - 1, 1, 1));
    if (interest != 0)
        record(date, interest, "interest");
    if (date.getMonth() == 1)
        record(date, -fee, "annual fee");
    acc.reset(date, getDebt());

}

void CreditAccount::show(ostream &out) const {
    Account::show(out);
    out << "\tAvailable credit: " << getAvailableCredit();
}
