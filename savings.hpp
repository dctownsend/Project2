//
//  savings.hpp
//  BankAccount
//
//  Created by dakota townsend on 5/14/18.
//  Copyright © 2018 dakota townsend. All rights reserved.
//

#ifndef savings_hpp
#define savings_hpp
#include <stdio.h>
#include "account.hpp"

class Savings : public Account {
protected:
    bool status;
public:
    //inline constr
    Savings() : Account() {
        status = false;
    }
    Savings(double bal, double interest) : Account(bal, interest) {}
    int withdraw(double);
    void deposit(double);
    double monthlyProc();
};

#endif
