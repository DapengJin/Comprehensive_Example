//
// Created by 45184 on 2020/5/3.
//

#ifndef COMPREHENSIVE_EXAMPLE_CREDITACCOUNT_H
#define COMPREHENSIVE_EXAMPLE_CREDITACCOUNT_H

#include "Account.h"

class CreditAccount : public Account {
private:
    Accumulator acc; // 辅助计算年利率的累加器
    double credit; // 信用额度
    double rate; // 存款的年利率
    double fee; // 信用卡年费
    double getDebt() const;

public:
    // 构造函数
    CreditAccount(const string &id, Date &date, double credit, double rate, double fee);

    // 查询利率
    double getRate() const { return rate; }

    // 查询信用额度
    double getCredit() const { return credit; }

    // 查询年费
    double getFee() const { return fee; }

    // 获得可用额度
    double getAvailableCredit() const;

    // 存入现金
    void deposit(const Date &date, double amount, const string &desc) override;

    // 取出现金
    void withdraw(const Date &date, double amount, const string &desc) override;

    // 结算利息（每月）
    void settle(const Date &date) override;

    void show(ostream &out) const override;
};

#endif //COMPREHENSIVE_EXAMPLE_CREDITACCOUNT_H
