//multiple inheritance
#include <iostream>
using namespace std;

class Father{
    public:
        void height(){
            cout<<" is having height of 6ft. "<<endl;
        }
};

class Mother{
    public:
        void look(){
            cout<<" has mole on her cheek. "<<endl;
        }
};

class Child:public Father,public Mother{
    public:
};

int main(){
    Child c;

    cout<<"Child ";
    c.look();

    cout<<"\nChild ";
    c.height();

    return 0;
}