#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct node{
    string data;
    string data1;
    struct node* link;

    node(char n,char a){
        data =n;
        data1 =a;
        link =NULL;
    }
};

struct node* head=NULL;

void add(string p_data,string p_data1){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=p_data;
    p->data1=p_data1;
    p->link=head;
    head=p;
}

void search(node* head,string name){
    struct node*temp;
    temp=head;
    cout<<"book to be searched: ";
    cin>>name;
    while (temp!=NULL)
    {
        if (temp->data==name)
        {
            cout<<"This book is available :)\n";
            break;
        }
        else
        {
            temp=temp->link;
        }   
    }
    if (temp==NULL)
    {
        cout<<"OOPS!This book is not available :(\n";
    } 
    
}

void remove(string name){
    struct node*temp;struct node*temp1;struct node*temp2;
    temp=head;
    cout<<"Name of the book to be removed: ";
    cin>>name;

    while ((temp->data)!=name)
    {
        temp=temp->link;
    }
    if ((temp->data)==name)
    {
        temp2=temp->link;
        temp1->link=temp;
        temp1->link=temp2;
        free(temp);
        cout<<"Book removed successfully \n";
    }
          
}

void count(){
    struct node*temp;
    int c=0;
    temp=head;

    while (temp!=NULL)
    {
        temp=temp->link;
        c++;
    }
    cout<<"The number of books available: "<<c;
}

void display(){
    struct node*temp;
    temp=head;
    cout<<"       Books Information: \n";
    cout<<"---------------------------------------\n";
    cout<<"Name"<<"            "<<"Author\n";
    cout<<"---------------------------------------\n";

    while(temp!=NULL){
        cout<<"\n"<<temp->data<<"            "<<temp->data1;
        temp=temp->link;
    }
    cout<<"\n---------------------------------------\n";
}

int main()
{
    string name;
    string author;
    int choice;

    do{
        cout<<"\nEnter ur choice: \n1)Add books \n2)Display books \n3)Search books \n4)Remove books \n5)Count of books \n6)Exit\n";
        cin>>choice;
        switch (choice)
        {
            case 1: 
                cout<<"book name: ";
                cin>>name;
                cout<<"author name: ";
                cin>>author;
                add(name,author);
                break;

            case 2:
                if (head==NULL)
                {
                   cout<<"OOPS! Cant display any as no book is available :(\n";
                }
                else
                {
                display();
                }
                break;

            case 3:
                if (head==NULL)
                {
                    cout<<"OOPS! Cant search as no book is available :(\n";
                }
                else
                {
                    search(head,name);
                }
                break;
                
            case 4:
                if (head==NULL)
                {
                   cout<<"OOPS! Can't remove, as no book is available :(\n";
                }
                else
                {
                    remove(name);
                }
                break;

            case 5:
                if (head==NULL)
                {
                    cout<<"OOPS! Zero books are available :(\n";
                }
                else
                {
                    count();
                }
                break;
            case 6:
                cout<<"Exiting!";
                exit(1);
            default:
                cout<<"\nInvalid choice. Enter valid choice. Thank You :) \n";
                break;
        }
    }while(1);

    return 0;
}