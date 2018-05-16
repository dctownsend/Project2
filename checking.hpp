//
//  checking.hpp
//  BankAccount
//
//  Created by dakota townsend on 5/14/18.
//  Copyright © 2018 dakota townsend. All rights reserved.
//

#ifndef checking_hpp
#define checking_hpp

#include <stdio.h>
#include "account.hpp"

class Checking : public Account {
public:
    Checking() : Account()
    {}
    Checking(double bal, double interest) : Account(bal, interest)
    {}
    int withdraw(double);
    void deposit(double);
    double monthlyProc();
};

#endif
