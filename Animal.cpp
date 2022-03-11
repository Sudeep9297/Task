//Polymorphism and MultiLevel Inheritance
#include <iostream>
using namespace std;

class Animal{
    public:
        void eat(){
            cout<<" Animal eats something "<<endl;
        }
};

class Tiger:public Animal{
    public:
        void eat(){
            cout<<" Tiger eats flesh "<<endl;
        }
};

class Deer:public Animal{
    public:
        string name="Deer";
        void eat(){
            cout<<" Deer eats grass and leaves "<<endl;
        }
};

class Monkey:public Animal{
    public:
        string name="Monkey";
        void eat(){
            cout<<" Monkey eats fruits "<<endl;
        }
};

int main(){
    Tiger t;
    Deer d;
    Monkey m;

    t.eat();
    d.eat();
    m.eat();

    return 0;
}