//
// Created by 45184 on 2020/4/30.
//

#include "Account.h"
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;
using namespace std::rel_ops;

double Account::total = 0;
RecordMap Account:: recordMap;

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
    recordMap.insert(make_pair(date, AccountRecord(date, this, amount, balance, desc)));
}

void Account::error(const string &msg) const {
    cout << "ERROR(#" << id << "): " << msg << endl;
}

void Account::show() const {
    cout << id << "\tBalance: " << balance;
}

void Account::query(const Date &begin, const Date &end){
    if (begin <= end){
        auto iter1 = recordMap.lower_bound(begin);
        RecordMap::iterator iter2 = recordMap.upper_bound(end);
        for (auto iter = iter1; iter != iter2; ++iter){
            iter->second.show();
        }
    }
}







