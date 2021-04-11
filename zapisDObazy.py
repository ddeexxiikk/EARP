import subprocess
from mysql.connector import connect, Error
import datetime
from time import sleep
from notify_run import Notify
#import requests

nf = Notify()

#Very important function which help in connecting to database
def tcp():
    fil = open('/home/pi/remote/tcp.txt')                      
    return fil.readline()

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
        connection = Null
        return connection
    
#Funkcja przekazuje dane do bazy
def execute_query(connection, query):
    cursor = connection.cursor()
