//
// Created by 45184 on 2020/5/31.
//

#include "Controller.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"


Controller::~Controller() {
    for_each(accounts.begin(), accounts.end(), deleter());
}

bool Controller::runCommand(const string &cmdLine) {
    istringstream str(cmdLine);
    char cmd, type;
    int index, day;
    double amount, credit, rate, fee;
    string id, desc;
    Account * account;
    Date date1, date2;
    str >> cmd;
    switch (cmd) {

        case 'a': // 增加新账户
            str >> type >> id;
            if (type == 's'){
                str >> rate;
                account = new SavingsAccount(id, date, rate);
            } else{
                str >> credit >> rate >> fee;
                account = new CreditAccount(id, date, credit, rate, fee);
            }
            accounts.push_back(account);
            return true;

        case 'd':
            str >> index >> amount >> desc;
            //getline(cin, desc);
            accounts[index]->deposit(date, amount, desc);
            return true;
        case 'w':
            str >> index >> amount >> desc;
            //getline(cin, desc);
            accounts[index]->withdraw(date, amount, desc);
            return true;
        case 's':
            for (int i = 0; i < accounts.size(); i++) {
                cout << "[" << i << "]";
                accounts[i]->show(cout);
                cout << endl;
            }
            return false;
        case 'c':
            str >> day;
            if (day < date.getDay())
                cout << "you cannot specify a previous day";
            else if (day > date.getMaxDay())
                cout << "invalid day";
            else
                date = Date(date.getYear(), date.getMonth(), day);
            return true;
        case 'n': // 进入下一个月
            if (date.getMonth() == 12)
                date = Date(date.getYear()+1, 1, 1);
            else
                date = Date(date.getYear(), date.getMonth()+1, 1);
            for (auto iter = accounts.begin(); iter != accounts.end(); ++iter)
                (*iter)->settle(date);
            return true;
        case 'q': // 查询一段时间的账目
            str >> date1 >> date2;
            Account::query(date1, date2);
            return false;
        case 'e':
            end = true;
            return false;
    }
    cout << "Invalid command: " << cmdLine << endl;
    return false;
}


