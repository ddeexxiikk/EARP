import subprocess
from mysql.connector import connect, Error
import datetime 
from time import sleep
from notify_run import Notify
nf = Notify()
#https://notify.run/c/40CiRtPlbZUFnkHg
#f = open('remote/tcp.txt','r')
#url = f.readline().split(':')
def polaczenie():
    
    try:
        connection = connect(
        #Tutaj trzeba wpisac HOSTA
            host='localhost',
            #host=url[1][2:],
            #port=url[2],
            user="ul",
            password="earp123",
            database="Dane"
        )
        return connection
    except Error as e:
        print(e)
        
def execute_query(connection, query):
    cursor = connection.cursor()
    try:
        cursor.execute(query)
        connection.commit()
        #print("Query executed successfully")
    except Error as e:
        print("The error " + str(e) + " occurred")

def push_alert(id, error, tresc):
    connection = polaczenie()
    
    if(connection!=None):
        inserting_error = "INSERT INTO Alerty ( id, error, tekst ) VALUES ( " + str(id) + ", " + str(error) + ", \"" + tresc + "\" )"
        execute_query(connection, inserting_error)
    
    connection.close()
    
def alert(id_ul,code,message):
    channel = 'admin'
    url = 'http://127.0.0.1:5030/admin'
    if id_ul == 1:
        channel = '40CiRtPlbZUFnkHg'
        url = 'https://notify.run/' + channel
    
    f = open('/home/pi/.config/notify-run', 'w')
    f.write("{\"endpoint\": \""+str(url)+"\"}")
    f.close()
    nf.send(message)
    push_alert(id_ul,code,message)

    
#alert(0,0,'localhost')


