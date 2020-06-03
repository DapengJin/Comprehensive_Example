//
// Created by 45184 on 2020/5/31.
//

#ifndef COMPREHENSIVE_EXAMPLE_CONTROLLER_H
#define COMPREHENSIVE_EXAMPLE_CONTROLLER_H

#include "Date.h"
#include <vector>
#include "Account.h"
#include <algorithm> // 使用 for_each 来挨个删除索引
#include "deleter.h"
#include <sstream>

class Controller { // 控制器，用来存贮账户列表，处理命令
private:
    Date date; // 当前日期
    vector<Account *> accounts; // 账户列表
    bool end; // 是否退出
public:
    Controller(const Date &date) : date(date), end(false) {}

    ~Controller();

    const Date &getDate() const { return date; }

    bool isEnd() const { return end; }

    bool runCommand(const string &cmdLine);
};

#endif //COMPREHENSIVE_EXAMPLE_CONTROLLER_H
