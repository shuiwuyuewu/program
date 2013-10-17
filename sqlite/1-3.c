#include <stdio.h>
#include <pthread.h>
#include "sqlite3.h"

void* myInsert(void* arg)
{
		sqlite3* db = 0;
		sqlite3_stmt* stmt = 0;
		int val = (int)arg;
		char SQL[100];
		int rc;
		rc = sqlite3_open("MyDB", &db);
		if(rc != SQLITE_OK){
				fprintf(stderr, "Thread[%d] fails to open the database\n", val);
				goto errorRet;
		}
		sprintf(SQL, "insert into Students values(%d)",val);
		rc = sqlite3_prepare(db, SQL, -1, &stmt, 0);
		if(rc != SQLITE_OK){
				fprintf(stderr, "Thread[%d] fails to prepare SQL: %s ->"
								"return code %d\n",val, SQL, rc);
				goto errorRet;
		}
		rc =sqlite3_step(stmt);
		if(rc != SQLITE_DONE){
				fprintf(stderr,"Thread[%d] fails to executes SQL: %s\n",val,SQL);
		}
		else {
				printf("Thread[%d] successfully executes SQL: %s\n", val, SQL);
		}
errorRet:
		sqlite3_close(db);
		return (void *)rc;
}

int main(void)
{
		pthread_t t[10];
		int i;
		for(i = 0; i < 10; i++)
				pthread_create(&t[i], 0, myInsert, (void*)i);
		for(i=0; i<10;i++)
				pthread_join(t[i],0);
		return 0;

}
