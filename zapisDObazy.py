from mysql.connector import connect, Error

def polaczenie():
    try:
        connection = connect(
        #Tutaj trzeba wpisac HOSTA - jak Zuzia i Kuba dokoncza serwer
            host=" ",
            user="ul",
            password="earp123",
            database="Baza_EARP"
        )
        return connection
    except Error:
        connection = Null
        return connection
    
    
#Funkcja przekazuje dane do bazy
def execute_query(connection, query):
    cursor = connection.cursor()
    try:
        cursor.execute(query)
        connection.commit()
    except Error :
        a=0
        
        
''' Tworze zarys funkcji
def nazwafunkcji():
    connection = polaczenie()

    if(connection!=Null):
        insert_error =  "INSERT INTO 'nazwa tabeli' ('parametry') VALUES ('parametry')
        execute_query(connection, insert_error)
        
    connection.close()
'''

myfile = open("KodyBledow.txt", "r")
tresc = myfile.read()
myfile.close()