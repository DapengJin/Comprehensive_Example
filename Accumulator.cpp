//
// Created by 45184 on 2020/5/2.
//

#include "Accumulator.h"

void Accumulator::change(const Date &date, double value) {
    sum = getSum(date);
    lastDate = date;
    this->value = value;
}

void Accumulator::reset(const Date &date, double value) {
    lastDate = date;
    this->value = value;
    sum = 0;
}
