#include <iostream>
using namespace std;

class car{
    string brand;
    string model;
    double price;
    bool status;
    double totalRevenue=0.0;

    public:
        car() {
            brand="unknown";
            model="generic";
            price=0.0;
            status=true;
        }
        car(string bname,string mname,double p,bool s) {
            brand=bname;
            model=mname;
            price=p;
            status=s;
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
        void updateRevenue(int days) {
            if(!status) {
                cout<<"This car is currently not available for rent!";
            }
            else {
                double revenue = days * rentalPrice;
                this->totalRevenue+=revenue;
                status=false;
                cout<<"revenue added: "<<revenue<<endl;
            }
        }
        void applydiscount(int days) {
            if(status) {
                if(days >=5) {
                    if(days>=10) {
                        rentalPrice*=0.9;
                    }
                    else {
                        rentalPrice*=0.95;
                    }
                }
            }
            else {
                cout<<"This car is currently not available for rent";
            }
        }
        car(const car &c) {
            brand=c.brand;
            model=c.model;
            rentalPrice=c.rentalPrice;
            status=true;
        }
        
        void display() {
            cout<<"brand: "<<brand<<endl;
            cout<<"model: "<<model<<endl;
            cout<<"price: "<<price<<endl;
            cout<<"status: "<<status<<endl;
            cout<<"total revenue: "<<totalRevenue<<endl;
        }
       
};

int main() {
    car c1;
    car c2=c1;
    c1.setbrand("toyota");
    c1.setmodel("model");
    c1.setPrice(100);
    cout<<"diplaying car1 details: "<<endl;
    c1.display();
    cout<<"diplaying car2 details: "<<endl;
    c2.display();
}
