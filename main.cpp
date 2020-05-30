#include <iostream>
#include <string>
#include "SavingsAccount.h"
#include "CreditAccount.h"
//#include "Array.h"
#include "AccountRecord.h"
#include <algorithm> // 使用 for_each 来挨个删除索引
#include <vector>

using namespace std;

struct deleter{
    template<class T>
    void operator () (T *p){delete p;};
};

int totalDate(const Date &date1, const Date &date2){
    return date1 - date2;
}
int main() {
    Date date(2008, 11, 1); // 起始日期
    vector<Account *> accounts(0); // 创建账户数组，元素个数为0

//    SavingsAccount s1 = SavingsAccount("jin", date, 0.015);
//    SavingsAccount s2 = SavingsAccount("li", date, 0.015);
//    CreditAccount c1 = CreditAccount("li2", date, 50000, 0.15, 0);
//    Account * accounts[] = {&s1, &s2, &c1};
//
//    const int n = sizeof(accounts) / sizeof(accounts[0]); // 账户总数，
//                // 但是当数组作为函数参数的时候，sizeof(accounts) 返回指针的大小

    //cout << "(d) deposit, (w) withdraw, (s) show, (c) change day, (n) next month, (e) exit" << endl;

    char cmd;
    do {
        cout << "\n" << endl;
        date.show();
        cout << "--------------------------------------------------------------------------------------" ;
        cout << "Total: " << Account::getTotal() << endl;
        cout << "(a) add an account, (d) deposit, (w) withdraw, (s) show, (c) change day, (n) next month, (q) query, (e) exit" << "\ncommand>_ ";
        char type; // 'c': credit account, 's' savings account
        int index, day;
        double amount, credit, rate, fee;
        string id, desc;
        Account * account;
        Date start, end;
        cin >> cmd;
        switch (cmd) {

            case 'a': // 增加新账户
                cout << "add a new account: type:'s' or 'c'  id:string" << "\ncommand>_ " ;
                cin >> type >> id;
                if (type == 's'){
                    cout << "\trate: double \n\tcommand>_ " ;
                    cin >> rate;
                    account = new SavingsAccount(id, date, rate);
                } else{
                    cout << "\tcredit, rate, fee: double \n\tcommand>_ " ;
                    cin >> credit >> rate >> fee;
                    account = new CreditAccount(id, date, credit, rate, fee);
                }
                accounts.push_back(account);
                break;

            case 'd':
                cout << "deposit: index:int  amount:double \ncommand>_ " ;
                cin >> index >> amount;
                getline(cin, desc);
                accounts[index]->deposit(date, amount, desc);
                break;
            case 'w':
                cout << "withdraw: index:int  amount:double \ncommand>_ ";
                cin >> index >> amount;
                getline(cin, desc);
                accounts[index]->withdraw(date, amount, desc);
                break;
            case 's':
                cout << "Show: " << endl;
                for (int i = 0; i < accounts.size(); i++) {
                    cout << "[" << i << "]";
                    accounts[i]->show();
                    cout << endl;
                }
                break;
            case 'c':
                cout << "change day: day:int \ncommand>_ ";
                cin >> day;
                if (day < date.getDay())
                    cout << "you cannot specify a previous day";
                else if (day > date.getMaxDay())
                    cout << "invalid day";
                else
                    date = Date(date.getYear(), date.getMonth(), day);
                break;
            case 'n': // 进入下一个月
                cout << "next month" << endl;
                if (date.getMonth() == 12)
                    date = Date(date.getYear()+1, 1, 1);
                else
                    date = Date(date.getYear(), date.getMonth()+1, 1);
                for (auto iter = accounts.begin(); iter != accounts.end(); ++iter)
                    (*iter)->settle(date);
                break;
            case 'q': // 查询一段时间的账目
                cout << "query records for some time range: start/end date: year-month-day" << "\ncommand>_ " ;
                start = Date::read();
                end = Date::read();
                Account::query(start, end);
                break;
        }
    } while (cmd != 'e');

    for_each(accounts.begin(), accounts.end(), deleter());
    return 0;
}
