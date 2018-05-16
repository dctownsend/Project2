//
//  checking.cpp
//  BankAccount
//
//  Created by dakota townsend on 5/14/18.
//  Copyright © 2018 dakota townsend. All rights reserved.
//

#include "checking.hpp"

int Checking::withdraw(double amount) {
    
    double newBal = balance - amount;
    
    if(newBal < 0)
    {
        serviceCharges -= 15;
        return -1;
    } else {
        balance = newBal;
        withdrawals ++;
    }
    
    return 1;
}

void Checking::deposit(double amount) {
    Account::deposit(amount);
}

double Checking::monthlyProc() {
    serviceCharges += 5 + (0.1 * withdrawals);
    
    return Account::monthlyProc();
}

