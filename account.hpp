//
//  account.hpp
//  BankAccount
//
//  Created by dakota townsend on 5/14/18.
//  Copyright © 2018 dakota townsend. All rights reserved.
//

#ifndef account_hpp
#define account_hpp
#include <stdio.h>

class Account {
protected:
    double balance;
    int deposits;
    int withdrawals;
    double interestRate;
    double serviceCharges;
    virtual void calcInt();
public:
    Account();
    Account(double, double);
    virtual void deposit(double);
    virtual int withdraw(double);
    virtual double monthlyProc();
    
    int getWithdrawals();
    int getDeposits();
    double getBalance();
};

#endif
