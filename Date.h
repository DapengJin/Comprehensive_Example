//
// Created by 45184 on 2020/4/30.
//

#ifndef COMPREHENSIVE_EXAMPLE_DATE_H
#define COMPREHENSIVE_EXAMPLE_DATE_H


class Date {
private:
    int year, month, day;
    int totalDays; // 从公元元年1月1号开始
public:
    Date(int year, int month, int day);

    int getYear() const { return year; }

    int getMonth() const { return month; }

    int getDay() const { return day; }

    int getMaxDay() const; // 获得当月有多少天
    bool isLeapYear() const { return year % 4 == 0 && year % 100 != 0 || year % 400 == 0; } // 是否为闰年
    void show() const; // 输出当前日期
    // 重载 减号，计算两个日期之间相差多少天，用来取代 distance， 增加可读性
    int operator - (const Date &date) const { return totalDays - date.totalDays; }
    //int distance(const Date &date) const {return totalDays - date.totalDays;} // 计算两个日期之间有多少天
};


#endif //COMPREHENSIVE_EXAMPLE_DATE_H
