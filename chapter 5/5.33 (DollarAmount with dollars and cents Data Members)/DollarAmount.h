#include <string>
#include <cmath>

class DollarAmount {
public:

   DollarAmount(int64_t value1, int value2){ // change of tactic: for negative values we negate both dollars & cents
      dollars = value1;
      cents = value2;
      centsFixer();
   }

   void add(DollarAmount right) {
      dollars += right.dollars;
      cents += right.cents;
      centsFixer();
   }

   void subtract(DollarAmount right) {
      dollars -= right.dollars;
      cents -= right.cents;
      centsFixer();
   }

   void addInterest(int rate, int divisor) {
      DollarAmount interest(rate * dollars, rate * cents); // it has centsFixer in its constructor so we won't write it again
      interest.divide(divisor);
      add(interest);
   }

   void divide(int divisor){
      // this whole idea of replacing amount with dollars & cents is not a good thing
      // becuase at the end we have to make another temporary amount variable for calculating divide
      int64_t amount{dollars * 100 + cents};
      if(amount / divisor % 2){
         amount = static_cast<int64_t>((amount + static_cast<double>(divisor) * 0.5) / divisor);
      }else{
         amount = static_cast<int64_t>((amount + static_cast<double>(divisor) * 0.4) / divisor);
      }
      dollars = amount / 100;
      cents = amount - dollars * 100;
      centsFixer();
   }

   std::string toString() const { // optimized to work well with both negative and positive numbers
      std::string dollarsString{std::to_string(std::abs(dollars))};
      std::string centsString{std::to_string(std::abs(cents))};
      return (dollars * 100 + cents < 0 ? "-" : "") + dollarsString + "." + (centsString.size() == 1 ? "0" : "") + centsString;
   }

private:
   int64_t dollars{0};
   int cents{0};

   void centsFixer(){ // makes sure that cents is always in the correct range, no need to be implemented as public
      if(dollars * 100 + cents > 0){
         while(cents >= 100){
            cents -= 100;
            dollars++;
         }
         while(cents < 0){
            cents += 100;
            dollars--;
         }
      }else{
         while(cents > 0){
            cents -= 100;
            dollars++;
         }
         while(cents <= -100){
            cents += 100;
            dollars--;
         }
      }
   }
};
