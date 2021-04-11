from mysql.connector import connect, Error
from bs4 import BeautifulSoup
import requests
import datetime

def tcp():
    try:
        page = requests.get('https://github.com/ZuzGom/remote/blob/main/tcp.txt')
    except requests.exceptions.ConnectionError:
        linia = None
    else:       
        soup = BeautifulSoup(page.content, 'html.parser')
        linia = str(soup.find("td", {"id": "LC1"})).split()[-1][9:-5]                        
    return linia

global connection=Null

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
    
#Funkcja ktora odczytuje dane z bazy
def execute_read_query(connection, query):
    cursor = connection.cursor()
    try:
        cursor.execute(query)
        result = cursor.fetchall()
        return result
    except Error:
        result = None
        return result

global miesiac="0"

def sprawdzenie_miodu():
    connection = polaczenie()
    teraz = datetime.datetime.now()
    miesiac = str(teraz.month())
    
    if(connection!=Null):
        select_query = "SELECT Weight FROM Measurements WHERE (Month = " + str(miesiac) + " AND Day = 15 AND Hour = 19)"
        query = execute_read_query(connection, select_query)[-1]
        
        connection.close()
        
        waga = str(query[0])
    else:
        waga = "0"
    
    return waga

waga = sprawdzenie_miodu()

myfile = open(str(miesiac) + ".txt", "w")
myfile.write(waga)
myfile.close()