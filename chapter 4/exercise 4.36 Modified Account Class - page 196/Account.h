#include <string>

class Account{
    public:

        Account(std::string accountName, double accountBalance)
            : name{accountName} {
                if(accountBalance > 0){
                    balance = accountBalance;
                }
            }
        
        void deposit(double newDeposit){
            if(newDeposit > 0){
                balance = balance + newDeposit;
            }
        }

        double getBalance() const{
            return balance;
        }

        void setName(std::string accountName){
            name = accountName;
        }

        std::string getName() const{
            return name;
        }

        void withdraw(double withdrawAmount){
            if(withdrawAmount <= balance){
                balance = balance - withdrawAmount;
            }
        }
        
    private:

        std::string name;
        double balance{0};
};