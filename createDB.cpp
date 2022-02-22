#include <iostream>
#include <sqlite3.h>

using namespace std;

int main()
{
	sqlite3*db;
	 int exit=0;
	 exit =sqlite3_open("example.db", &db);//open the connection 
	 if (exit)
	 {
	 	cout<< "DB Open error: "<< sqlite3_errmsg(db)<<endl;
	 }
	 else
	 {
	 	cout<< "Opened database successfully!"<<endl;
	 }
	 sqlite3_close(db);//closes the connection
	 
	 return (0);
	 
}

