#include <string>

class Invoice{
    public:
        ///constructor:
        Invoice(std::string partNumberParameter, std::string partDescriptionParameter,
                int quantityParameter, int priceParameter)
                
                : partNumber{partNumberParameter},
                  partDescription{partDescriptionParameter},
                  quantity{quantityParameter},
                  price{priceParameter},
                  tax{0.2},
                  discount{0}   {

                  }
        //getInvoiceAmount function:
        double getInvoiceAmount() const{
            return quantity * price * ((100 + tax) / 100) * ((100 - discount) / 100);
        }
        //partNumber member functions:
        void setPartNumber(std::string stringParameter){
            partNumber = stringParameter;
        }

        std::string getPartNumber() const{
            return partNumber;
        }
        //partDescription member functions:
        void setPartDescription(std::string stringParameter){
            partDescription = stringParameter;
        }

        std::string getPartDescription() const{
            return partDescription;
        }
        //quantitiy member functions:
        void setQuantity(int intParameter){
            if(intParameter > 0){
                quantity = intParameter;
            }
        }
        
        int getQuantity() const{
            return quantity;
        }
        //price member fucntions:
        void setPrice(int intParameter){
            if(intParameter > 0){
                price = intParameter;
            }
        }
        
        int getPrice() const{
            return price;
        }
        //tax member functions:
        void setTax(double doubleParameter){
            if(doubleParameter >= 0){
                tax = doubleParameter;
            }
        }
        
        double getTax() const{
            return tax;
        }
        //discount member functions:
        void setDiscount(double doubleParameter){
            if(doubleParameter >= 0){
                discount = doubleParameter;
            }
        }
        
        double getDiscount() const{
            return discount;
        }
        //data members:
    private:
        std::string partNumber;
        std::string partDescription;
        int quantity;
        int price;
        double tax;
        double discount;
};