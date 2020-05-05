#include <iostream>
#include "SavingsAccount.h"
#include "CreditAccount.h"

using namespace std;
int totalDate(const Date &date1, const Date &date2){
    return date1 - date2;
}
int main() {
    Date date(2008, 11, 1); // 起始日期
    SavingsAccount s1 = SavingsAccount("jin", date, 0.015);
    SavingsAccount s2 = SavingsAccount("li", date, 0.015);
    CreditAccount c1 = CreditAccount("li2", date, 50000, 0.15, 0);
    Account * accounts[] = {&s1, &s2, &c1};

    const int n = sizeof(accounts) / sizeof(accounts[0]); // 账户总数

    //cout << "(d) deposit, (w) withdraw, (s) show, (c) change day, (n) next month, (e) exit" << endl;

    char cmd;
    do {
        date.show();
        cout << "\tTotal: " << Account::getTotal() << endl;
        cout << "(d) deposit, (w) withdraw, (s) show, (c) change day, (n) next month, (e) exit" << "\ncommand>_ ";
        int index, day;
        double amount;
        string desc;
        cin >> cmd;
        switch (cmd) {
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
