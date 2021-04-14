from mysql.connector import connect, Error
from notify_run import Notify
from subprocess import Popen, PIPE
from time import sleep
print('początek zapisu')
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
    #print("siema")
    channel = 'admin'
    url = 'https://notify.run/mO3yfQmLdbxvMoIj'
    if id_ul == 1:
        channel = '40CiRtPlbZUFnkHg'
        url = 'https://notify.run/' + channel
    
    try:
        #print("boi")
        f = open('/home/pi/.config/notify-run', 'w')
        #f = open('/root/.config/notify-run', 'w')
        
        print("good")
    except PermissionError as e:
        print("ja nawet nie",e)
        f = open('/home/pi/.config/notify-run', 'w')
    #print("zwracam honor notify")
    f.write("{\"endpoint\": \""+str(url)+"\"}")
    f.close()
    nf.send(message)
    push_alert(id_ul,code,message)
    '''
    try:
        #print(nf.info())
        #nf.send(message)
        #p = Popen(['/var/www/html/Analiza/notify-run','configure',url], stdin='y')
        cmd = "/var/www/html/Analiza/notify-run configure" + str(url)
        p = Popen(cmd, stdout=PIPE, stderr=PIPE, stdin=PIPE, shell=True)
        o = p.communicate(b"yes")[0]
        #p.stdin.write(b'yes')
        #sleep(3)
        #out = p.communicate('y')[0]
        #print(out)
        #subprocess.Popen(['echo','y'])
        
        p = Popen(['/var/www/html/Analiza/notify-run','send',str(message)])
        push_alert(id_ul,code,message)
    except Exception as e:
        print("eror",e)
    print("wyslano")
    '''
#alert(1,8,"noc")
myfile = open("/var/www/html/Analiza/KodyBledow.txt", "r")
#print("dzialaj plis
for x in myfile:
    alert(1, 5, str(x))
    #Nie dziala :( problem jet albo z wyslaniem alertu albo z plikeim
myfile.close()

print("Koniec Zapisu do Bazy Analizy")