print('początek zapisu')
import subprocess
from mysql.connector import connect, Error
import datetime
from time import sleep
from notify_run import Notify

nf = Notify()

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
        connection = None
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
        
def push_alert(id, error, tresc):
    connection = polaczenie()
    
    if(connection!=None):
        inserting_error = "INSERT INTO Alerty ( id, error, tekst ) VALUES ( " + str(id) + ", " + str(error) + ", \"" + tresc + "\" )"
        execute_query(connection, inserting_error)
    
    connection.close()
    
def alert(id_ul,code,message):
    channel = 'admin'
    url = 'https://notify.run/mO3yfQmLdbxvMoIj'
    if id_ul == 1:
        channel = '40CiRtPlbZUFnkHg'
        url = 'https://notify.run/' + channel
    try:
        f = open('/root/.config/notify-run', 'w')
    except PermissionError:
        f = open('/home/pi/.config/notify-run', 'w')
    f.write("{\"endpoint\": \""+str(url)+"\"}")
    f.close()
    nf.send(message)
    push_alert(id_ul,code,message)

myfile = open("/var/www/html/Analiza/KodyBledow.txt", "r")

for x in myfile:
    alert(1, 5, str(x))
    
myfile.close()

print("Koniec Zapisu do Bazy Analizy")