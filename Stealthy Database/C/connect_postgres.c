#include <stdio.h>
#include <libpq-fe.h>

void print_table(PGconn *conn, const char *query)
{
    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("Query failed: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }

    int rows = PQntuples(res);
    int cols = PQnfields(res);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%s\t", PQgetvalue(res, i, j));
        }
        printf("\n");
    }

    PQclear(res);
}

int main() {

    PGconn *conn;

    conn = PQconnectdb("host=localhost dbname=pbr_project user=postgres password=1234");

    if (PQstatus(conn) != CONNECTION_OK) {
        printf("Connection failed: %s\n", PQerrorMessage(conn));
        return 1;
    }

    printf("Connected to PostgreSQL\n\n");

    printf("Employees Table:\n");
    print_table(conn, "SELECT * FROM employees");

    printf("\nGames Table:\n");
    print_table(conn, "SELECT * FROM games");

    PQfinish(conn);

    return 0;
}