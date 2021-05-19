from mysql.connector import connect, Error
import datetime 

global connection
connection=None

#Function which connect with database
def polaczenie():
    try:
        connection = connect(
            host='localhost',
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

def do_pliku():
    connection = polaczenie()
    teraz = datetime.datetime.now()
    miesiac = int(teraz.month)
    dzien = int(teraz.day)
    godzina = int(teraz.hour)
    minuta = int(teraz.minute)
    
    if(connection!=None):
        select_query = "SELECT Temperature, AdditionalTemperature, Weight, AccelerationX, AccelerationY, AccelerationZ, RotationX, RotationY, RotationZ, Sound, Date, Time FROM Measurements ORDER BY Datetime DESC LIMIT 2"
        query1 = execute_read_query(connection, select_query)[0]
        query2 = execute_read_query(connection, select_query)[1]
        
        #Takie cos do liczenia wagi ula w srodku miesiaca... do analizy po paru miesiacach
        if(dzien==15 and godzina==19 and minuta>5 and minuta<10):
            select_queried = "SELECT Weight FROM Measurements WHERE (Month = " + str(miesiac) + " AND Day = 15 AND Hour = 19)"
            try:
                query3 = execute_read_query(connection, select_queried)[-1]
                waga = str(query3)
                
                myfile = open("/var/www/html/Analiza/"+ str(miesiac) + "waga.txt", "w")
                myfile.write(waga)
                myfile.close()
            except: 
                print("Nie ma jeszcze 15 dnia " + str(miesiac) + " miesiaca")
        #Tu sie konczy to cos
        
        connection.close()
        
    return query1, query2
    else:
        print('brak polaczenia')
    
try:            
    q1, q2 = do_pliku()
except Exception as e:
    print("Bati napraw: " + str(e))
    
print(waga)

print("koniec odczytu")

class UL:
    
    def __init__(self, TempWEW, TempWEW2, TempZEW, TempZEW2, waga, waga2, AcceX, AcceY, AcceZ, 
    AcceX2, AcceY2, AcceZ2, RotX, RotY, RotZ, RotX2, RotY2, RotZ2, Sound):
        Zmiana_Temp(TempWEW, TempWEW2, TempZEW, TempZEW2)
        Zmiana_Wagi(waga, waga2)
        Zmiana_Przyspieszen(AcceX, AcceY, AcceZ, AcceX2, AcceY2, AcceZ2)
        Zmiana_Rotacji(RotX, RotY, RotZ, RotX2, RotY2, RotZ2)
        Zmiana_Sounda(Sound)
    
        

