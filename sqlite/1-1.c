#include <stdio.h>
#include "sqlite3.h"

int main(void)
{
		sqlite3* db = 0;
		sqlite3_stmt* stmt = 0;
		int retcode;
		retcode = sqlite3_open("MyDB",&db);
		if(retcode != SQLITE_OK)
		{
				sqlite3_close(db);
				fprintf(stderr, "Could not open MyDB\n");
				return retcode;
		}
		retcode = sqlite3_prepare(db, "select SID from Students order by SID",
						-1, &stmt, 0);
		if(retcode != SQLITE_OK)
		{
				sqlite3_close(db);
				fprintf(stderr,"Could not execute SELECT\n");
				return retcode;
		}
		while(sqlite3_step(stmt) == SQLITE_ROW)
		{
				int i = sqlite3_column_int(stmt, 0);
				printf("SID = %d\n", i);
		}
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		return SQLITE_OK;
}
