#include<iostream>
#include<sqlite3.h>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName)
{
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	
	for(i=0;i<argc;i++){
		printf("%s=%s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	
	printf("\n");
	return 0;
}

int main(int argc, char** argv)
{
	sqlite3*db;
	int exit=0;
	exit=sqlite3_open("example.db", &db);
	string data("CALLBACK FUNCTION");
	
	string sql("SELECT * FROM EMPLOYEE;");
	if(exit){
		cout<<"Error open DB"<<sqlite3_errmsg(db)<<endl;
		return (-1);
	}
	else
	{
		cout<<"Open Database Successfully!"<<endl;
	}
	int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data.c_str(), NULL);
	
	if(rc!=SQLITE_OK)
		cout<<"Error SELECT"<<endl;
	else{
		cout<<"Operation OK!"<<endl;
	}
	
	sqlite3_close(db);
	return (0);
}
