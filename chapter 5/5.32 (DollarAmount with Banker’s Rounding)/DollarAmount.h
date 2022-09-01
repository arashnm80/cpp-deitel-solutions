#include <string>
#include <cmath> 

class DollarAmount {
public:

   DollarAmount(int64_t value1, int value2) : amount{value1 * 100 + value2} { } 


   void add(DollarAmount right) {
      amount += right.amount; 
   }

   void subtract(DollarAmount right) {
      amount -= right.amount;
   }

   void addInterest(int rate, int divisor) { // powered by divide member function, now it uses banker rounding
      DollarAmount interest(0, rate * amount);
      interest.divide(divisor);
      // the line below was our previous method for half-up rounding:
      // DollarAmount interest(0, (amount * rate + divisor / 2) / divisor);
      add(interest);
   }

   void divide(int divisor){ // renewed by banker rounding
      if(amount / divisor % 2){
         amount = static_cast<int64_t>((amount + static_cast<double>(divisor) * 0.5) / divisor);
      }else{
         amount = static_cast<int64_t>((amount + static_cast<double>(divisor) * 0.4) / divisor);
      }
   }

   std::string toString() const {
      std::string dollars{std::to_string(amount / 100)};
      std::string cents{std::to_string(std::abs(amount % 100))};
      return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
   }
private:
   int64_t amount{0};
};
