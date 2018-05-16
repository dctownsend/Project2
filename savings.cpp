//
//  savings.cpp
//  BankAccount
//
//  Created by dakota townsend on 5/14/18.
//  Copyright © 2018 dakota townsend. All rights reserved.
//

#include "savings.hpp"
int Savings::withdraw(double amount) {
    if(status)
        Account::withdraw(amount);
    else 
        return -1;
    
    status = balance >= 25;
    
    if(!status)
        return -2;
    
    return 1;
}

void Savings::deposit(double amount) {
   
    if(!status && (balance + amount) >= 25)
        status = true;
    
    Account::deposit(amount);
}

double Savings::monthlyProc() {
    if(withdrawals > 4)
        serviceCharges += withdrawals;

    double total = Account::monthlyProc();
    
    status = balance >= 25;
    
    return total;
}
