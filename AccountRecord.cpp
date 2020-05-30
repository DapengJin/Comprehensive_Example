//
// Created by 45184 on 2020/5/25.
//

#include <iostream>
#include "AccountRecord.h"

AccountRecord::AccountRecord(const Date &date, const Account *account, double amount, double balance, const string &desc)
    : date(date), account(account), amount(amount), balance(balance), desc(desc){

}

void AccountRecord::show() const {
    date.show();
    cout << "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << desc << endl;

}


