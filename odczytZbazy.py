from mysql.connector import connect, Error
import requests
from bs4 import BeautifulSoup

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

global temp1, temp2, waga, humi, AcceX, AcceY, AcceZ, RotX, RotY, RotZ

def do_pliku():
    connection = polaczenie()
    
    if(connection!=Null):
        select_query = "SELECT temperature, AdditionalTemperature, Weight, Humidity, AccelerationX, AccelerationY, AccelerationZ, RotationX, RotationY, RotationZ FROM Measurements"
        query = execute_read_query(connection, select_query)[-1]
         
        connection.close()
         
        #Temperatura wewnatrz - temp1
        temp1 = str(query[0])
        
        #Temperatura na zewnatrz - temp2
        temp2 = str(query[1])
        
        #Waga
        waga = str(query[2])

        #Wilgotnosc
        humi = str(query[3])
        
        #Przyspieszenia
        AcceX = str(query[4])
        AcceY = str(query[5])
        AcceZ = str(query[6])
        
        #Rotacja
        RotX = str(query[7])
        RotY = str(query[8])
        RotZ = str(query[9])
    
    else:
        
        temp1 = "0"
        temp2 = "0"
        waga = "0"
        humi = "0"
        AcceX = "0"
        AcceY = "0"
        AcceZ = "0"
        RotX = "0"
        RotY = "0"
        RotZ = "0"
        
       
do_pliku()

myfile = open("daneZbazy.txt", "w")
myfile.write("" + temp1 + "\n" + temp2 + "\n" + waga + "\n" + humi + "\n" + AcceX + "\n" + AcceY + "\n" + AcceZ + "\n" + RotX + "\n" +  RotY + "\n" +  RotZ + "")
myfile.close()