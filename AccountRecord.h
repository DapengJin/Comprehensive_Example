//
// Created by 45184 on 2020/5/25.
//

#ifndef COMPREHENSIVE_EXAMPLE_ACCOUNTRECORD_H
#define COMPREHENSIVE_EXAMPLE_ACCOUNTRECORD_H

#include "Date.h"
#include "Account.h"
#include <string>

using namespace std;

class Account; // 前置声明

class AccountRecord {
private:
    Date date; // 日期
    const Account * account; // 账户
    double amount; // 金额
    double balance; // 余额
    string desc; // 描述
public:
    // 构造函数
    AccountRecord(const Date &date, const Account * account, double amount, double balance, const string &desc);
    void show() const; // 输出当前记录
};


#endif //COMPREHENSIVE_EXAMPLE_ACCOUNTRECORD_H
