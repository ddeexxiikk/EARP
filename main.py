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
    
print(q2[2])

print("koniec odczytu")

class UL:
    #funkcje inita

    def zmianatempWEW(self, aTemperatura, aTemperatura2):
        self.TemperaturaWEW1 = aTemperatura
        self.TemperaturaWEW2 = aTemperatura2
    

    def zmianatempZEW(self, aTemperatura, aTemperatura2):
        self.TemperaturaZEW1 = aTemperatura
        self.TemperaturaZEW2 = aTemperatura2
    

    def zmianawagi(self, aWaga, aWaga2):
        self.Waga1 = aWaga
        self.Waga2 = aWaga2
    

    def zmianaprzyspieszeniaX(self, aAcceX, aAcceX2):
        self.AcceX1 = aAcceX
        self.AcceX2 = aAcceX2
    

    def zmianaprzyspieszeniaY(self, aAcceY, aAcceY2):
        self.AcceY1 = aAcceY
        self.AcceY2 = aAcceY2
    
   
    def zmianaprzyspieszeniaZ(self, aAcceZ, aAcceZ2):
        self.AcceZ1 = aAcceZ
        self.AcceZ2 = aAcceZ2
    
    
    def zmianarotaX(self, aRotX, aRotX2):
        self.RotX1 = aRotX
        self.RotX2 = aRotX2
    

    def zmianarotaY(self, aRotY, aRotY2):
        self.RotY1 = aRotY
        self.RotY2 = aRotY2
    

    def zmianarotaZ(self, aRotZ, aRotZ2):   
        self.RotZ1 = aRotZ
        self.RotZ2 = aRotZ2
    
    
    def zmianasounda(self, aSound):   
        self.Sound1 = aSound
    
    


    #bezuzyteczne funkcje
    def Zmiana_Temp(self,TempWEW, TempWEW2, TempZEW, TempZEW2):
        self.zmianatempWEW(TempWEW, TempWEW2)
        self.zmianatempZEW(TempZEW, TempZEW2) 
    def Zmiana_Wagi(self,waga, waga2):
        self.zmianawagi(waga, waga2)
    def Zmiana_Przyspieszen(self,AcceX, AcceY, AcceZ, AcceX2, AcceY2, AcceZ2):
        self.zmianaprzyspieszeniaX(AcceX, AcceX2)
        self.zmianaprzyspieszeniaY(AcceY, AcceY2)
        self.zmianaprzyspieszeniaZ(AcceZ, AcceZ2)
    def Zmiana_Rotacji(self,RotX, RotY, RotZ, RotX2, RotY2, RotZ2):
        self.zmianarotaX(RotX, RotX2)
        self.zmianarotaY(RotY, RotY2)
        self.zmianarotaZ(RotZ, RotZ2)
    def Zmiana_Sounda(self, Sound):
        self.zmianasounda(Sound)


    def __init__(self, TempWEW, TempWEW2, TempZEW, TempZEW2, waga, waga2, AcceX, AcceY, AcceZ, 
    AcceX2, AcceY2, AcceZ2, RotX, RotY, RotZ, RotX2, RotY2, RotZ2, Sound):
        self.Zmiana_Temp(self,TempWEW, TempWEW2, TempZEW, TempZEW2)
        self.Zmiana_Wagi(self,waga, waga2)
        self.Zmiana_Przyspieszen(self,AcceX, AcceY, AcceZ, AcceX2, AcceY2, AcceZ2)
        self.Zmiana_Rotacji(self,RotX, RotY, RotZ, RotX2, RotY2, RotZ2)
        self.Zmiana_Sounda(self,Sound)


    def Sprawdzenie_Temperatury_Wewnatrz(self):
        if(self.TemperaturaWEW1<0):
            return "Temperatura w Ulu jest ponizej 0\n"
        elif(abs(self.TemperaturaWEW2-self.TemperaturaWEW1)>=2):
            return "Temperatura w Ulu szybko sie obnizyla\n"
        else:
            return "OK"
    
    
    def Sprawdzenie_Wagi(self):  
        if((self.Waga1 > self.Waga2) and ((self.Waga1 - self.Waga2) >= 2000)):
            return "Ul zbyt szybko przybral na wadze!\n"
        elif((self.Waga2 > self.Waga1) and ((self.Waga2 - self.Waga1) <=2000) and ((self.Waga2-self.Waga1) > 200)):
            return "Ucieczka Roju z Ula\n"
        else:
            return "OK"
    

    def Sprawdzenie_Przesuniecia(self):
    # nastepna linijka do poprawienia, prawdziwi programisci nie pisza takich ifow
        if(((self.AcceX1>self.AcceX2)and((self.AcceX1-self.AcceX2)>10)) or ((self.AcceX2>self.AcceX1) and ((self.AcceX2-self.AcceX1)>10)) or ((self.AcceY1>self.AcceY2)and((self.AcceY1-self.AcceY2)>10)) or ((self.AcceY2>self.AcceY1)and((self.AcceY2-self.AcceY1)>10)) or ((self.AcceZ1>self.AcceZ2)and((self.AcceZ1-self.AcceZ2)>10)) or ((self.AcceZ2>self.AcceZ1)and((self.AcceZ2-self.AcceZ1)>10)) or ((self.RotX1>self.RotX2)and((self.RotX1-self.RotX2)>10)) or ((self.RotX2>self.RotX1)and((self.RotX2-self.RotX1)>10)) or ((self.RotY1>self.RotY2)and((self.RotY1-self.RotY2)>10)) or ((self.RotY2>self.RotY1)and((self.RotY2-self.RotY1)>10)) or ((self.RotZ1>self.RotZ2)and((self.RotZ1-self.RotZ2)>10)) or ((self.RotZ2>self.RotZ1)and((self.RotZ2-self.RotZ1)>10))):
            return "Ul sie poruszyl" 
        else:
            return "OK"
    

    def Sprawdzenie_Sounda(self):
        if(self.Sound1 < 10):
            return "Brak dzwieku w Ulu\n"
        else:
            return "OK"
    
    #Tutaj beda funkcje, ktore zwracaja nam tez stringi bazujące na metodach z sekcji private z odpowiednimi tekstami, ktore później wrzucamy do pliku
    def  Temperatura_Wewnatrz(self):
        return self.Sprawdzenie_Temperatury_Wewnatrz(self) 

    def  Waga_Ula(self):
        return self.Sprawdzenie_Wagi(self) 
    

    def  Przesuniecie_Ula(self):
        return self.Sprawdzenie_Przesuniecia(self) 

    def  Dzwiek_Ula(self):
        return self.Sprawdzenie_Sounda(self) 
    

    
        

