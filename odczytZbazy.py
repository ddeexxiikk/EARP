from mysql.connector import connect, Error
from bs4 import BeautifulSoup
import datetime 
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

global temp1, temp2, waga, AcceX, AcceY, AcceZ, RotX, RotY, RotZ, query2

def do_pliku():
    connection = polaczenie()
    
    if(connection!=Null):
        select_query = "SELECT temperature, AdditionalTemperature, Weight, AccelerationX, AccelerationY, AccelerationZ, RotationX, RotationY, RotationZ FROM Measurements ORDER BY Date"
        query1 = execute_read_query(connection, select_query)[-1]
        query2 = execute_read_query(connection, select_query)[-2]
         
        connection.close()
         
        #Temperatura wewnatrz - temp1
        temp1 = str(query1[0])
        
        #Temperatura na zewnatrz - temp2
        temp2 = str(query1[1])
        
        #Waga
        waga = str(query1[2])
        
        #Przyspieszenia
        AcceX = str(query1[3])
        AcceY = str(query1[4])
        AcceZ = str(query1[5])
        
        #Rotacja
        RotX = str(query1[6])
        RotY = str(query1[7])
        RotZ = str(query1[8])
    
    else:
        
        temp1 = "0"
        temp2 = "0"
        waga = "0"
        AcceX = "0"
        AcceY = "0"
        AcceZ = "0"
        RotX = "0"
        RotY = "0"
        RotZ = "0"
            
do_pliku()

#Ostatni zapis
myfileLAST = open("DaneZBazyLAST.txt", "w")
myfileLAST.write("" + temp1 + "\n" + temp2 + "\n" + waga + "\n" + AcceX + "\n" + AcceY + "\n" + AcceZ + "\n" + RotX + "\n" +  RotY + "\n" +  RotZ + "")
myfileLAST.close()


#Przedostatni zapis
#Temperatura wewnatrz - temp1
temp1 = str(query2[0])
        
#Temperatura na zewnatrz - temp2
temp2 = str(query2[1])
        
#Waga
waga = str(query2[2])
        
#Przyspieszenia
AcceX = str(query2[3])
AcceY = str(query2[4])
AcceZ = str(query2[5])
        
#Rotacja
RotX = str(query2[6])
RotY = str(query2[7])
RotZ = str(query2[8])

myfilePRE = open("DaneZBazyPRE.txt", "w")
myfilePRE.write("" + temp1 + "\n" + temp2 + "\n" + waga + "\n" + AcceX + "\n" + AcceY + "\n" + AcceZ + "\n" + RotX + "\n" +  RotY + "\n" +  RotZ + "")
myfilePRE.close()