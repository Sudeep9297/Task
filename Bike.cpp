//inheritance
#include <iostream>
using namespace std;

class TwoWheeler{
    public:
        string brand="Yamaha";
};

class Bike:public TwoWheeler{
    public:
        string model="R15";
        int price=150000;
};

int main(){
    Bike b;
    cout<<b.brand<<" "<<b.model<<" "<<b.price<<endl;

    return 0;
}
