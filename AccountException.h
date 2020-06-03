//
// Created by 45184 on 2020/6/2.
//

#ifndef COMPREHENSIVE_EXAMPLE_ACCOUNTEXCEPTION_H
#define COMPREHENSIVE_EXAMPLE_ACCOUNTEXCEPTION_H

#include <stdexcept>
#include "Account.h"
using namespace std;

class Account;

class AccountException : public runtime_error{
private:
    const Account * account;
public:
    AccountException(const Account * account, const string &msg)
        :runtime_error(msg), account(account){ }

    const Account * getAccount() const {return account;}

};


#endif //COMPREHENSIVE_EXAMPLE_ACCOUNTEXCEPTION_H
