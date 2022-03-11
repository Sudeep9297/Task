#include<iostream>
#include<string.h>
using namespace std;

class books {
 	public:
 		char bookname[50];
 		char author[50];
 		char stream[50];
 		int stock;

 		void addbooks();
 		void display();
};

void books::addbooks() {
 	cout<<"\nEnter Book Name:";
 	cin>>bookname;
 	cout<<"\nEnter Author Name:";
 	cin>>author;
 	cout<<"\nEnter Stream:";
 	cin>>stream;
 	cout<<"\nEnter Stock:";
 	cin>>stock;
}

void books::display() {
 	cout<<"\nName of the Book:"<<bookname;
 	cout<<"\nAuthor of the Book:"<<author;
 	cout<<"\nStream of the Book:"<<stream;
 	cout<<"\nStock Present:"<<stock;
}

int main() {
 	books bk[10];
 	int choice, n;

     do
     {
  	cout<<"\n1.Add Books\n2.Display Books\n3.Search Books\n4.Exit\n";
  	cout<<"\n\nEnter your Choice:";
  	cin>>choice;
  	switch(choice)
  	{
  		case 1: cout<<"Enter Number of Books:";
  		        cin>>n;
  			for(int i=0;i<n;i++)
   				bk[i].addbooks();
  		        break;
 	        case 2:
 		        for(int i=0;i<n;i++)
                                bk[i].display();
 		        break;
 	        case 3:
  
   			char bname[20], aname[20];
  			 cout<<"Enter name of the Book:";
  			 cin>>bname;
  			 cout<<"Enter name of the Author:";
  			 cin>>aname;
  			 for(int i=0;i<n;i++)
   			 {
    				if(strcmp(bname, bk[i].bookname)==0 && strcmp(aname,bk[i].author)==0)
    				{
    				 cout<<"\nBook is available\n\n";
   			         cout<<"\nName of the Book:"<<bk[i].bookname;
    			         cout<<"\nAuthor of the Book:"<<bk[i].author;
    				 cout<<"\nStream of the Book:"<<bk[i].stream;
     				 cout<<"\nStock Available:"<<bk[i].stock;
     				 break;
    				}
    				else
    				{
    				 cout<<"Not Available!!";
   				 break;
  				}
  			 }
  			 break;
 		         default: cout<<"Enter a valid choice!!";
 		 case 4: exit(1);
  	}
  }while(1);
}
