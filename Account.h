//
// Created by 45184 on 2020/4/30.
//

#ifndef COMPREHENSIVE_EXAMPLE_ACCOUNT_H
#define COMPREHENSIVE_EXAMPLE_ACCOUNT_H

#include "Date.h"
#include "Accumulator.h"
#include <string>

using namespace std;

class Account { // 储蓄账户类
private:
    string id; // 账号
    double balance; // 余额
    static double total; // 所以账户的总金额
//    double rate; // 年利率
//    Date lastDate;  // 上次变更余额的时间
//    double accumulation; // 余额按日累加之和
//    // 记录一笔账，date 为日期，amount 为金额，desc 为说明
//    void record(const Date &date, double amount, const string &desc);
//    // 报告错误信息
//    void error(const string &msg) const;
//    // 获得到指定日期为止的存款金额的按日累积值
//    double accumulate(const Date &date) const{ return accumulation + balance * date.distance(lastDate);}
protected:
    // 供派生类调用的构造函数
    Account(const string &id, const Date &date);

    // 记入一笔账，date 日期，amount 金额，desc 说明
    void record(const Date &date, double amount, const string &desc);

    // 报告错误信息
    void error(const string &msg) const;

public:
    const string &getId() const { return id; }

    double getBalance() const { return balance; }

    static double getTotal() { return total; }

    // 存入现金，date 日期，amount 金额，desc 说明
    virtual void deposit(const Date &date, double amount, const string &desc) = 0;

    // 取出现金，date 日期，amount 金额，desc 说明
    virtual void withdraw(const Date &date, double amount, const string &desc) = 0;

    // 结算利息，每月结算一次，date 结算日期
    virtual void settle(const Date &date) = 0;

    // 显示账户信息
    virtual void show() const;
};


#endif //COMPREHENSIVE_EXAMPLE_ACCOUNT_H
