#include<iostream>
#include<sqlite3.h>
#include<string>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName)
{
	int i;
	fprintf(stderr, "%s: ", (const char*)data);//returns number of character                                                                         written
	
	for(i=0; i< argc; i++) {
		printf("%s =%s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	
	printf("\n");
	return 0;
	}
	
	int main(int argc, char** argv)
	{
		sqlite3*db;
		char* messageError;
		int exit = sqlite3_open("example.db", &db);
		string query= "SELECT * FROM EMPLOYEE;";
		
		cout<<"STATE OF TABLE BEFORE INSERT"<<endl;
		
		sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
		
		string sql("INSERT INTO EMPLOYEE VALUES(1,'AMAN',38,'PUNE',30000);"
			   "INSERT INTO EMPLOYEE VALUES(2,'ANUPAM',34,'DELHI',50000);"
			   "INSERT INTO EMPLOYEE VALUES(3,'PIYUSH',28,'MUMBAI',40000);");
		
		exit=sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
		if(exit!=SQLITE_OK)
		{
			cout<<"Error insert"<<endl;
			sqlite3_free(messageError);
		}
		else
		{
			cout<<"Records created successfully!"<<endl;
		}
		
		cout<<"STATE OF TABLE AFTER INSERT"<<endl;
		
		sqlite3_exec(db,query.c_str(), callback,NULL,NULL);
		
		sql="DELETE FROM EMPLOYEE WHERE ID=2;";
		exit =sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
		if(exit!=SQLITE_OK)
		{
			cout<<"Error DELETE"<<endl;
			sqlite3_free(messageError);
		}
		else
		{
			cout<<"Record deleted successfully!"<<endl;
		}
		cout<<"STATE OF TABLE AFTER DELETE OF ELEMENT"<<endl;
		sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
		
		sqlite3_close(db);
		return (0);
	}

