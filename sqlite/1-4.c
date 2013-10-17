#include <stdio.h>
#include "sqlite3.h"

int main(void)
{
		sqlite3* db = 0;

		sqlite3_open("MyDB", &db);
		sqlite3_exec(db, "attach database MyDBExtn as DB1",0,0,0);
		sqlite3_exec(db, "begin",0,0,0);
		sqlite3_exec(db, "insert into Students values(2000)", 0,0,0);
		sqlite3_exec(db, "insert into Courses values('SQLite Database',2000)",
						0,0,0);
		sqlite3_exec(db, "commit",0,0,0);

		sqlite3_close(db);
		return SQLITE_OK;
}
