#include <iostream>
using namespace std;

class car{
    string brand;
    string model;
    double price;
    bool status;
    
    public:
        car() {
            brand="unknown";
            model="generic";
            price=0.0;
            status=true;
        }
        void setbrand(string b) {
            brand=n;
        }
        void setmodel(string m) {
            model=m;
        }
        void setPrice(double p) {
            if(p>0.0) {
                price=p;
            }
        }
        void setStatus(bool s) {
            status=s;
        }
        void rentrequest() {
            if(status) status = !status;
        }
        void checkStatus() {
            if(status) {
                cout<<"The car is now booked"<<endl;
            }
            else {
                cout<<"This car is currently not available for rent"<<endl;
            }
        }
        
};

int main() {
    car c1;
    c1.checkStatus();
    c1.rentrequest();
    c1.checkStatus();
    c1.rentrequest();
}
