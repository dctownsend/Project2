//
//  main.cpp
//  BankAccount
//
//  Created by dakota townsend on 5/14/18.
//  Copyright © 2018 dakota townsend. All rights reserved.
//

#include <iostream>
#include "savings.hpp"
#include "checking.hpp"
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int printMenu(fstream*, fstream*);
void sWithdraw(Savings*, double, fstream*);
void cWithdraw(Checking*, double, fstream*);
void dispTotal(Savings*, Checking*, fstream*);


int main(int argc, char* argv[]) {
   
    if(argc < 3)
        exit(1);
    else {
       
        fstream inFile, outFile;
        
     
        inFile.open(argv[1], ios::in);
        
        if(!inFile) {
            cout << "InFile not found!";
            exit(1);
        }
        
        outFile.open(argv[2], ios::out);
        
        if(!outFile) {
            cout << "OutFile not found!";
            exit(1);
        }
        
        if(inFile && outFile) {
            Checking cAccount;
            Savings sAccount;
            int choice = 0;
            double amount = 0;
            
            do {
                choice = printMenu(&inFile, &outFile);
                
                switch(choice) {
                    case 1:
                    case 2:
                        outFile << "Enter amount to deposit: ";
                        inFile >> amount;
                        //1 = Savings, 2 = Checking.
                        if(choice == 1)
                            //deposit to the savings
                            sAccount.deposit(amount);
                        else
                            //deposit to the checking
                            cAccount.deposit(amount);
                        break;
                    case 3:
                    case 4:
                        outFile << "Enter amount to withdraw: ";
                        inFile >> amount;
                        //3 = savings, 2 = checking.
                        if(choice == 3)
                            //withdraw from saving
                            sWithdraw(&sAccount, amount, &outFile);
                        else
                            //withdraw from checking
                            cWithdraw(&cAccount, amount, &outFile);
                        break;
                    case 5:
                        //Display the stats
                        dispTotal(&sAccount, &cAccount, &outFile);
                        break;
                    case 6:
                        break;
                    default:
                        break;
                }
            }
            while(choice != 6);
            
            
            inFile.close();
            outFile.close();
        }
    }
}

int printMenu(fstream* inFile, fstream* outFile)
{
    *outFile << "\n\n";
    *outFile << "******** BANK ACCOUNT MENU ********\n\n";
    *outFile << "1. Savings Account Deposit\n";
    *outFile << "2. Checking Account Deposit\n";
    *outFile << "3. Savings Account Withdrawal\n";
    *outFile << "4. Checking Account Withdrawal\n";
    *outFile << "5. Update and Display Account Statistics\n";
    *outFile << "6. Exit\n\n";
    *outFile << "Your choice, please: (1-6) ";
    
    int choice;
    *inFile >> choice;
    
    while(choice > 6 || choice < 1)
    {
        *outFile << "Enter a number from 1 through 6 please: ";
        *inFile >> choice;
    }
    
    return choice;
}

void sWithdraw(Savings* acc, double amount, fstream* outFile)
{
    int result = acc->withdraw(amount);
    if(result == -1)
        *outFile << "Account is inactive.\n\n";
    else if(result == -2)
    {
        *outFile << "\nYour account has fallen below $25.00.";
        *outFile << "\nIt will be deactivated.\n";
    }
}

void cWithdraw(Checking* acc, double amount, fstream* outFile)
{
    int result = acc->withdraw(amount);
    if(result == -1)
    {
        *outFile << "You are attempting to withdraw more ";
        *outFile << "than the account balance.\n";
    }
}

void dispTotal(Savings* sAcc, Checking* cAcc, fstream* outFile)
{
    
    *outFile << fixed << setprecision(2) << "\n\n";
    *outFile << "SAVINGS ACCOUNT MONTHLY STATISTICS:\n";
    *outFile << "Withdrawals:       " << sAcc->getWithdrawals() << "\n";
    *outFile << "Deposits:       " << sAcc->getDeposits() << "\n";
    *outFile << "Service Charges:   " << sAcc->monthlyProc() << "\n";
    *outFile << "\nEnding Balance:    " << sAcc->getBalance() << "\n";
    *outFile << "\n\n\n";
    *outFile << "CHECKING ACCOUNT MONTHLY STATISTICS:\n";
    *outFile << "Withdrawals:       " << cAcc->getWithdrawals() << "\n";
    *outFile << "Deposits:       " << cAcc->getDeposits() << "\n";
    *outFile << "Service Charges:   " << cAcc->monthlyProc() << "\n";
    *outFile << "\nEnding Balance:    " << cAcc->getBalance() << "\n";
    *outFile << "\n";
}
