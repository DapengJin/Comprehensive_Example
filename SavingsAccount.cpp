//
// Created by 45184 on 2020/5/3.
//

#include "SavingsAccount.h"
#include <iostream>

using namespace std;

SavingsAccount::SavingsAccount(const string &id, Date &date, double rate)
        : Account(id, date), rate(rate), acc(date, 0) {}

void SavingsAccount::deposit(const Date &date, double amount, const string &desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void SavingsAccount::withdraw(const Date &date, double amount, const string &desc) {
    if (amount > getBalance())
        error("not enough money");
    else {
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
}

void SavingsAccount::settle(const Date &date) {
    if (date.getMonth() == 1) { // 每年1月1号计算利息
        double interest = acc.getSum(date) * rate / (date - Date(date.getYear() - 1, 1, 1));
        if (interest != 0)
            record(date, interest, "interest");
        acc.reset(date, getBalance());
    }
}

void SavingsAccount::show() const {
    cout << getId() << "\tBalance: " << getBalance();
}
