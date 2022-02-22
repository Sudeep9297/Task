#include<iostream>
#include<sqlite3.h>

using namespace std;

int main(int argc, char** argv)
{
	sqlite3*db;
	string sql="CREATE TABLE EMPLOYEE("
		   "ID INT PRIMARY KEY NOT NULL, "
		   "NAME TEXT NOT NULL, "
		   "AGE INT NOT NULL, "
		   "ADDRESS CHAR(50), "
		   "SALARY REAL ); ";
		   
		  
	int exit=0;
	exit=sqlite3_open("example.db", &db);//open the connection
	char* messageError;
	exit=sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
	
	if(exit !=SQLITE_OK) {
		cout<<"Error Create Table"<<endl;
		sqlite3_free(messageError);
	}
	else
	{
		cout<<"Table created succesfully"<<endl;
	}
	sqlite3_close(db);//connection closed
	return (0);
}
