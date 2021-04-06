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
    
#Funkcja niedokonczona bo ja musze ogarnac zapis do pliku w pythonie
def do_pliku():
    connection = connection()
    
    if(connection!=Null):
        select_query = "SELECT temperature, AdditionalTemperature, Weight, Humidity, AccelerationX, AccelerationY, AccelerationZ, RotationX, RotationY, RotationZ FROM Measurements"
         query = execute_read_query(connection, select_query)[-1]
         
         connection.close()
         