import psycopg2

# Connect to PostgreSQL
conn = psycopg2.connect(
    host="localhost",
    database="pbr_project",
    user="postgres",
    password="1234"
)

cur = conn.cursor()

# -------- Employees Table --------
print("Employees Table:\n")

cur.execute("SELECT * FROM employees")
employees = cur.fetchall()

for row in employees:
    print(row)

# -------- Games Table --------
print("\nGames Table:\n")

cur.execute("SELECT * FROM games")
games = cur.fetchall()

for row in games:
    print(row)

# Close connection
cur.close()
conn.close()