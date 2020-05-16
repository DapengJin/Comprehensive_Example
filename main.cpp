#include <iostream>
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Array.h"

using namespace std;
int totalDate(const Date &date1, const Date &date2){
    return date1 - date2;
}
int main() {
    Date date(2008, 11, 1); // 起始日期
    Array<Account *> accounts(0); // 创建账户数组，元素个数为0

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
        date.show();
        cout << "\tTotal: " << Account::getTotal() << endl;
        cout << "(d) deposit, (w) withdraw, (s) show, (c) change day, (n) next month, (e) exit" << "\ncommand>_ ";
        char type; // 'c': credit account, 's' savings account
        int index, day;
        double amount, credit, rate, fee;
        string id, desc;
        Account * account;
        cin >> cmd;
        switch (cmd) {
            case 'a': // 增加新账户
                cout << "add a new account: type:'s' or 'c'  id:string" << "\ncommand>_ " ;
                cin >> type >> id;
                if (type == 's'){
                    cout << "\trate: double" << "\ncommand>_ " ;
                    cin >> rate;
                    account = new SavingsAccount(id, date, rate);
                } else{
                    cout << "\tcredit, rate, fee: double" << "\ncommand>_ " ;
                    account = new CreditAccount(id, date, credit, rate, fee);
                }
                accounts.resize(accounts.getSize() + 1);
                accounts[accounts.getSize() - 1] = account;
                break;
            case 'd':
                cout << "deposit: index:int  amount:double" << "\ncommand>_ " ;
                cin >> index >> amount;
                getline(cin, desc);
                accounts[index]->deposit(date, amount, desc);
                break;
            case 'w':
                cout << "withdraw: index:int  amount:double" << "\ncommand>_ ";
                cin >> index >> amount;
                getline(cin, desc);
                accounts[index]->withdraw(date, amount, desc);
                break;
            case 's':
                cout << "Show: " << endl;
                for (int i = 0; i < n; i++) {
                    cout << "[" << i << "]";
                    accounts[i]->show();
                    cout << endl;
                }
                break;
            case 'c':
                cout << "change day: day:int" << "\ncommand>_ ";
                cin >> day;
                if (day < date.getDay())
                    cout << "you cannot specify a previous day";
                else if (day > date.getMaxDay())
                    cout << "invalid day";
                else
                    date = Date(date.getYear(), date.getMonth(), day);
                break;
            case 'n':
                cout << "next month" << endl;
                if (date.getMonth() == 12)
                    date = Date(date.getYear()+1, 1, 1);
                else
                    date = Date(date.getYear(), date.getMonth()+1, 1);
                for (int i = 0; i < n; i++)
                    accounts[i]->settle(date);
                break;
        }
    }while (cmd != 'e');
    return 0;
}
