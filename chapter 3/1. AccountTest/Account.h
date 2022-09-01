#include <string>

class Account{
    public:

        Account(std::string accountName, int accountBalance)
            : name{accountName} {
                if(accountBalance > 0){
                    balance = accountBalance;
                }
            }
        
        void deposit(int newDeposit){
            if(newDeposit > 0){
                balance = balance + newDeposit;
            }
        }

        int getBalance() const{
            return balance;
        }

        void setName(std::string accountName){
            name = accountName;
        }

        std::string getName() const{
            return name;
        }

        void withdraw(int withdrawAmount){
            if(withdrawAmount <= balance){
                balance = balance - withdrawAmount;
            }
        }
        
    private:

        std::string name;
        int balance{0};
};