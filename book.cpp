#include <iostream>
using namespace std;

struct book{
    char name[20];
    char author[30];
};

void insert(){
    struct book b;
    cout<<"book name: ";
    cin>>b.name;
    cout<<"book author: ";
    cin>>b.author;
}

void display(){
    struct book b;
    cout<<"\nBook Details\n";
    cout<<"name"<<"   "<<"author"<<"   "<<"\n";
    cout<<b.name<<"   "<<b.author<<"   "<<"\n";
}

int main()
{
    struct book b;
    int choice;

    do{
        cout<<"\nEnter your choice: \n1.Add books \n2.Display books\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            insert();
            break;
        
        case 2:
            display();
            break;

        default: 
            cout<<"Invalid choice.";
            break;
        }
    }while(1);
    return 0;
}