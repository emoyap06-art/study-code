#include <iostream>
#include <string>



class BankAccount {
    private:
    std::string owner;
    double balance=0.0;

    public:
    void setOwner(std::string owner) {
        this->owner = owner;
    }
    std::string getOwner() {
        return owner;
    }

    void deposit(double amount) {
        if(amount > 0) {
            balance+=amount;
            std::cout<<"Balance after deposit:"<<balance <<std::endl;
        }
        else {
            std::cout<<"Invalid Deposit-Amount";
            std::cout << std::endl;
        }
    }
    void withdraw(double amount) {
        if(amount>0 && amount <= balance) {
            balance-=amount;
            std::cout<<"Balance after withdrawal:"<<balance <<std::endl;
        }
        else {
            std::cout <<"No enough to withdraw this amount";
            std::cout<< std::endl;
        }
    }
    double getbalance();

    void getAccountInfo();

};

double BankAccount::getbalance() {
    std::cout<<"Current Balance: "<<balance <<std::endl;
    return balance;
}

void BankAccount::getAccountInfo() {
    std::cout<<"Name of Accountowner: "<< getOwner() <<std::endl;
    std::cout<<"balance of this account: "<<balance <<std::endl;
}

int main() {
    BankAccount Bank_1;

    Bank_1.setOwner("Max Mustermann");
    
    Bank_1.getbalance();

    Bank_1.deposit(671.67);
    Bank_1.getbalance();
    Bank_1.withdraw(100.11);
    Bank_1.getAccountInfo();

    return 0;
}