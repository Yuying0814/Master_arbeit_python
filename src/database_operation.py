import sqlite3

DATABASE_PATH = r"D:\python\master_arbeit\data\database.db"

connection = sqlite3.connect(database_path)

try:
    cursor = connection.cursor()

    cursor.execute("SELECT name FROM sqlite_master WHERE type='table'")
    tables = cursor.fetchall()

    print(tables)
finally:
    connection.close()