from mysql.connector import connect, Error

def polaczenie():
    try:
        connection = connect(
        #Tutaj trzeba wpisac HOSTA
            host=" ",
            user="ul",
            password="earp123",
            database="Baza_EARP"
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
    
temp1 = "22.7" 
temp2 = "23.76" 
waga = "1261.22"
humi = "65"
AcceX = "10.7"
AcceY = "-0.34"
AcceZ = "-0.83"
RotX = "-0.19"
RotY = "-0.18"
RotZ = "0"

def do_pliku():
    connection = connection()
    
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
        RotX = str(query[7)
        RotY = str(query[8])
        RotZ = str(query[9])
        
        return temp1, temp2, waga, humi, AcceX, AcceY, AcceZ, RotX, RotY, RotZ

do_pliku()

myfile = open("daneZbazy.txt", "w")

myfile.write("" + temp1 + "\n" + temp2 + "\n" + waga + "\n" + humi + "\n" + AcceX + "\n" + AcceY + "\n" + AcceZ + "\n" + RotX + "\n" +  RotY + "\n" +  RotZ + "")

myfile.close()
