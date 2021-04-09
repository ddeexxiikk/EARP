import subprocess
from mysql.connector import connect, Error
import datetime 
from time import sleep
from notify_run import Notify

nf = Notify()

#Very important function which help in connecting to database
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
    url = 'http://127.0.0.1:5030/admin'
    if id_ul == 1:
        channel = '40CiRtPlbZUFnkHg'
        url = 'https://notify.run/' + channel
    
    f = open('/home/pi/.config/notify-run', 'w')
    f.write("{\"endpoint\": \""+str(url)+"\"}")
    f.close()
    nf.send(message)
    push_alert(id_ul,code,message)

myfile = open("KodyBledow.txt", "r")

for x in myfile:
    tresc = myfile.readline()
    alert(1, 5, str(tresc))

myfile.close()
