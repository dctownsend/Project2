//
//  account.cpp
//  BankAccount
//
//  Created by dakota townsend on 5/14/18.
//  Copyright © 2018 dakota townsend. All rights reserved.
//

#include "account.hpp"
Account::Account() {
    balance = 0.00;
    deposits = 0;
    withdrawals = 0;
    interestRate = 0.05;
    serviceCharges = 0.00;
}

Account::Account(double bal, double interest) {
    balance = bal;
    deposits = 0;
    withdrawals = 0;
    interestRate = interest;
    serviceCharges = 0.00;
}

void Account::calcInt() {
    balance += (interestRate/12) * balance;
}

void Account::deposit(double amount) {
    balance += amount;
    
    deposits ++;
}

int Account::withdraw(double amount) {
    balance -= amount;
    
    withdrawals ++;

    return 1;
}

double Account::monthlyProc() {
    calcInt();
    balance -= serviceCharges;
    withdrawals = 0;
    deposits = 0;
    
    double total = serviceCharges;
    
    serviceCharges = 0;
    
    return total;
}

int Account::getWithdrawals() {
    return withdrawals;
}

int Account::getDeposits() {
    return deposits;
}

double Account::getBalance() {
    return balance;
}
