//
// Created by 45184 on 2020/5/3.
//

#ifndef COMPREHENSIVE_EXAMPLE_SAVINGSACCOUNT_H
#define COMPREHENSIVE_EXAMPLE_SAVINGSACCOUNT_H

#include "Account.h"
#include "Accumulator.h"

class SavingsAccount : public Account {
private:
    Accumulator acc; // 辅助计算年利率的累加器
    double rate; // 存款的年利率
public:
    // 构造函数
    SavingsAccount(const string &id, Date &date, double rate);

    // 查询利率
    double getRate() const { return rate; }

    // 存入现金
    void deposit(const Date &date, double amount, const string &desc) override;

    // 取出现金
    void withdraw(const Date &date, double amount, const string &desc) override;

    // 结算利息（每月）
    void settle(const Date &date) override;

    // 显示账户信息
    virtual void show() const override;
};


#endif //COMPREHENSIVE_EXAMPLE_SAVINGSACCOUNT_H
