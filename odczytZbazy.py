from mysql.connector import connect, Error
from bs4 import BeautifulSoup
import datetime 
import requests

def tcp():
    fil = open('/home/pi/remote/tcp.txt')                      
    return fil.readline()

global connection
connection=None

#Function which connect with database
def polaczenie():
    url = tcp().split(':')
    try:
        connection = connect(
            host='localhost',
            #port=url[2],
            user="ul",
            password="earp123",
            database="Dane"
        )
        return connection
    except Error:
        return None
    
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

temp1,temp2, waga, AcceX, AcceY, AcceZ, RotX, RotY, RotZ, waga, miesiac = "0", "0", "0", "0", "0", "0", "0", "0", "0", "0","0",


def do_pliku():
    connection = polaczenie()
    teraz = datetime.datetime.now()
    miesiac = str(teraz.month)
    
    if(connection!=None):
        select_query = "SELECT temperature, AdditionalTemperature, Weight, AccelerationX, AccelerationY, AccelerationZ, RotationX, RotationY, RotationZ FROM Measurements ORDER BY Date"
        query1 = execute_read_query(connection, select_query)[-1]
        query2 = execute_read_query(connection, select_query)[-2]
        
        #Takie cos do liczenia wagi ula w srodku miesiaca... do analizy po paru miesiacach
        select_queried = "SELECT Weight FROM Measurements WHERE (Month = " + str(miesiac) + " AND Day = 15 AND Hour = 19)"
        query3 = execute_read_query(connection, select_queried)[-1]
        waga = str(query3)
        #Tu sie konczy to cos
        
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
        
        return temp1, temp2, waga, AcceX, AcceY, AcceZ, RotX, RotY, RotZ, query2, miesiac
    
    else:
        print('brak polaczenia')
    
try:            
    temp1, temp2, waga, AcceX, AcceY, AcceZ, RotX, RotY, RotZ, query2, miesiac = do_pliku()
except Exception as e:
    print(e)
    print('Bati napraw to')
    
#Ostatni zapis
myfileLAST = open("DaneZBazyLAST.txt", "w")
myfileLAST.write("" + temp1 + "\n" + temp2 + "\n" + waga + "\n" + AcceX + "\n" + AcceY + "\n" + AcceZ + "\n" + RotX + "\n" +  RotY + "\n" +  RotZ + "")
myfileLAST.close()

myfile = open(str(miesiac) + "waga.txt", "w")
myfile.write(waga)
myfile.close()

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