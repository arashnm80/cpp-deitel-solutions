#include <string>
#include <cmath> 

class DollarAmount {
public:

   DollarAmount(int64_t value1, int value2) : amount{value1 * 100 + value2} { } // I removed explicit keyword because it has more that one parameter now
// I also added value2 and modified this constructor

   void add(DollarAmount right) {
      amount += right.amount; 
   }

   void subtract(DollarAmount right) {
      amount -= right.amount;
   }

   void addInterest(int rate, int divisor) {
      DollarAmount interest(0, (amount * rate + divisor / 2) / divisor); // I changed this line to match with new modified constructor
      add(interest);
   }

   std::string toString() const {
      std::string dollars{std::to_string(amount / 100)};
      std::string cents{std::to_string(std::abs(amount % 100))};
      return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
   }
private:
   int64_t amount{0};
};
