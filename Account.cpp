//
// Created by 45184 on 2020/4/30.
//

#include "Account.h"
#include <cmath>
#include <iostream>

using namespace std;

double Account::total = 0;

Account::Account(const string &id, const Date &date)
        : id(id), balance(0) {
    date.show();
    cout << "\t#" << id << " created" << endl;
}

void Account::record(const Date &date, double amount, const string &desc) {
    amount = floor(amount * 100 + 0.5) / 100; // 保留小数点后两位
    balance += amount;
    total += amount;
    date.show();
    cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

void Account::error(const string &msg) const {
    cout << "ERROR(#" << id << "): " << msg << endl;
}

void Account::show() const {
    cout << id << "\tBalance: " << balance;
}







