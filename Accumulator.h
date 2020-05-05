//
// Created by 45184 on 2020/5/2.
//

#ifndef COMPREHENSIVE_EXAMPLE_ACCUMULATOR_H
#define COMPREHENSIVE_EXAMPLE_ACCUMULATOR_H

#include "Date.h"

class Accumulator { // 将某个数值按日累加
private:
    Date lastDate; // 上次变更数值的时间
    double value; // 数值的当前值
    double sum; // 数值按日累加之和
public:
    // 构造函数，date 为开始累加的日期，value 为初始值
    Accumulator(const Date &date, double value)
            : lastDate(date), value(value), sum(0) {}

    // 获得日期 date 的累加结果
    double getSum(const Date &date) { return sum + value * (date - lastDate); }

    // 在某一时间 date， 将 value 改变
    void change(const Date &date, double value);

    // 初始化，将日期变为 date，数值变为value，累加器 清零。
    void reset(const Date &date, double value);
};


#endif //COMPREHENSIVE_EXAMPLE_ACCUMULATOR_H
