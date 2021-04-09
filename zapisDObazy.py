from mysql.connector import connect, Error
from bs4 import BeautifulSoup
import requests

def tcp():
    try:
        page = requests.get('https://github.com/ZuzGom/remote/blob/main/tcp.txt')
    except requests.exceptions.ConnectionError:
        linia = None
    else:       
        soup = BeautifulSoup(page.content, 'html.parser')
        linia = str(soup.find("td", {"id": "LC1"})).split()[-1][9:-5]                        
    return linia

#Function which connect with database
def polaczenie():
    url = tcp().split(':')
    try:
        connection = connect(
            host=url[1][2:],
            port=url[2],
            user="ul",
            password="earp123",
            database="Dane"
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
        #Nic nie robi
        a=0
            
#Tworze zarys funkcji
def nazwafunkcji(tresc):
    connection = polaczenie()

    if(connection!=Null):
        insert_error =  "INSERT INTO Alerty ( id, tekst ) VALUES ( 5, \""+ str(tresc) + "\" )"
        execute_query(connection, insert_error)
        
    connection.close()

myfile = open("KodyBledow.txt", "r")

for x in myfile:
    tresc = myfile.readline()
    nazwafunkcji(tresc)

myfile.close()
