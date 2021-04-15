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

temp1, temp2, waga, AcceX, AcceY, AcceZ, RotX, RotY, RotZ, waga, miesiac, sound, query2, data, godzina = "0", "0", "0", "0", "0", "0", "0", "0", "0", "0","0", "0", "0000000000", "0", "0"

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
        
        #Dzwiek
        sound = str(query1[9])
        
        #Data i godzina
        data = str(query1[10])
        godzina = str(query1[11])
        
        return temp1, temp2, waga, AcceX, AcceY, AcceZ, RotX, RotY, RotZ, sound, data, godzina, query2, miesiac,
    
    else:
        print('brak polaczenia')
    
try:            
    temp1, temp2, waga, AcceX, AcceY, AcceZ, RotX, RotY, RotZ, sound, data, godzina, query2, miesiac = do_pliku()
except Exception as e:
    print("Bati napraw: " + str())
    
print(waga)   
#Ostatni zapis
myfileLAST = open("/var/www/html/Analiza/DaneZBazyLAST.txt", "w")
myfileLAST.write("" + temp1 + "\n" + temp2 + "\n" + waga + "\n" + AcceX + "\n" + AcceY + "\n" + AcceZ + "\n" + RotX + "\n" +  RotY + "\n" +  RotZ + "\n" + sound + "\n" + data + "\n" + godzina + "")
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

#Dzwiek
sound = str(query2[9])
        
#Data i godzina
data = str(query2[10])
godzina = str(query2[11])

myfilePRE = open("/var/www/html/Analiza/DaneZBazyPRE.txt", "w")
myfilePRE.write("" + temp1 + "\n" + temp2 + "\n" + waga + "\n" + AcceX + "\n" + AcceY + "\n" + AcceZ + "\n" + RotX + "\n" +  RotY + "\n" +  RotZ + "\n" + sound + "\n" + data + "\n" + godzina + "")
myfilePRE.close()
print("koniec odczytu")


