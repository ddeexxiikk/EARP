#include <iostream>
#include <fstream>
#include <cstdlib>
class UL
{
private:
    int TemperaturaWEW1, TemperaturaWEW2,
    TemperaturaZEW1, TemperaturaZEW2, 
    Wilgotnosc1, Wilgotnosc2, 
    Waga1, Waga2, Waga3, 
    AcceX1, AcceX2,
    AcceY1, AcceY2, 
    AcceZ1, AcceZ2,
    RotX1, RotX2,
    RotY1, RotY2,
    RotZ1, RotZ2;

    //Trzeba obmyslic jak przy starcie programu przechowywac stare wartosci 'maybe jakies wskaznik do pamieci RAM' ale to musze poczytac o czasu zycia zmiennych i jak go wydluzyc
    void zmianatempWEW(int atemperatura)
    {
        TemperaturaWEW2 = TemperaturaWEW1;
        TemperaturaWEW1 = atemperatura;
    }

    //Trzeba obmyslic jak przy starcie programu przechowywac stare wartosci 'maybe jakies wskaznik do pamieci RAM' ale to musze poczytac o czasu zycia zmiennych i jak go wydluzyc
    void zmianatempZEW(int atemperatura)
    {
        TemperaturaZEW2 = TemperaturaZEW1;
        TemperaturaZEW1 = atemperatura;
    }

    //Trzeba obmyslic jak przy starcie programu przechowywac stare wartosci 'maybe jakies wskaznik do pamieci RAM' ale to musze poczytac o czasu zycia zmiennych i jak go wydluzyc
    void zmianawagi(int awaga)
    {
        if(awaga>=0)
        {
            Waga3 = Waga2;
            Waga2 = Waga1;
            Waga1= awaga;
        }
    }

    //Trzeba obmyslic jak przy starcie programu przechowywac stare wartosci 'maybe jakies wskaznik do pamieci RAM' ale to musze poczytac o czasu zycia zmiennych i jak go wydluzyc
    void zmianaprzyspieszeniaX(int aAcceX)
    {
        AcceX2 = AcceX1;
        AcceX1 = aAcceX;
    }

    //Trzeba obmyslic jak przy starcie programu przechowywac stare wartosci 'maybe jakies wskaznik do pamieci RAM' ale to musze poczytac o czasu zycia zmiennych i jak go wydluzyc
    void zmianaprzyspieszeniaY(int aAcceY)
    {
        AcceY2 = AcceY1;
        AcceY1 = aAcceY;
    }

    //Trzeba obmyslic jak przy starcie programu przechowywac stare wartosci 'maybe jakies wskaznik do pamieci RAM' ale to musze poczytac o czasu zycia zmiennych i jak go wydluzyc
    void zmianaprzyspieszeniaZ(int aAcceZ)
    {
        AcceZ2 = AcceZ1;
        AcceZ1 = aAcceZ;
    }

    //Trzeba obmyslic jak przy starcie programu przechowywac stare wartosci 'maybe jakies wskaznik do pamieci RAM' ale to musze poczytac o czasu zycia zmiennych i jak go wydluzyc
    void zmianarotaX(int aRotX)
    {
        RotX2 = RotX2;
        RotX1 = aRotX;
    }

    //Trzeba obmyslic jak przy starcie programu przechowywac stare wartosci 'maybe jakies wskaznik do pamieci RAM' ale to musze poczytac o czasu zycia zmiennych i jak go wydluzyc
    void zmianarotaY(int aRotY)
    {
        RotY2 = RotY2;
        RotY1 = aRotY;
    }

    //Trzeba obmyslic jak przy starcie programu przechowywac stare wartosci 'maybe jakies wskaznik do pamieci RAM' ale to musze poczytac o czasu zycia zmiennych i jak go wydluzyc
    void zmianarotaZ(int aRotZ)
    {
        RotZ2 = RotZ2;
        RotZ1 = aRotZ;
    }

    //Tutaj piszemy funkcje, które analizują te dane - a teraz sprawdz public

public:

    void Zmiana_Temp(int atempWEW, int atempZEW)
    {
        zmianatempWEW(atempWEW);
        zmianatempZEW(atempZEW);
    }

    void Zmiana_Wagi(int awaga)
    {
        zmianawagi(awaga);
    }

    void Zmiana_Przyspieszen(int aAcceX, int aAcceY, int aAcceZ)
    {
        zmianaprzyspieszeniaX(aAcceX);
        zmianaprzyspieszeniaY(aAcceY);
        zmianaprzyspieszeniaZ(aAcceZ);
    }

    void Zmiana_Rotacji(int aRotX, int aRotY, int aRotZ)
    {
        zmianarotaX(aRotX);
        zmianarotaY(aRotY);
        zmianarotaZ(aRotZ);
    }

    //Tutaj beda funkcje, ktore zwracaja nam stringi z odpowiednimi tekstami, ktore później wrzucam do bazy
};

//Troche funkcje musze przerobic ale WESELE nie poczeka xd
int main()
{
    std::fstream plikLAST, plikPRE;
    std::string wejscie;
    int TemperaturaWEW, TemperaturaZEW, Waga, Wilgotnosc, AcceX, AcceY, AcceZ, RotX, RotY, RotZ;

    plik.open("daneZbazy.txt", std::ios::in);

    if(plik.good() == false)
    {
        exit(0);
    }

    for(int i=0; i<10; i++)
    {
        std::getline(plik, wejscie);
        if(i==0)
            TemperaturaWEW = stoi(wejscie);
        else if(i==1)
            TemperaturaZEW = stoi(wejscie);
        else if(i==2)
            Waga = stoi(wejscie);
        else if(i==3)
            Wilgotnosc = stoi(wejscie);
        else if(i==4)
            AcceX = stoi(wejscie);
        else if(i==5)
            AcceY = stoi(wejscie);
        else if(i==6)
            AcceZ = stoi(wejscie);
        else if(i==7)
            RotX = stoi(wejscie);
        else if(i==8)
            RotY = stoi(wejscie);
        else if(i==9)
            RotZ = stoi(wejscie);
    }

    UL ul;

    ul.Zmiana_Temp(TemperaturaWEW, TemperaturaZEW);
    ul.Zmiana_Wagi(Waga);
    ul.Zmiana_Przyspieszen(AcceX, AcceY, AcceZ);
    ul.Zmiana_Rotacji(RotX, RotY, RotZ);

    return 0;
}

/* Tutaj jest wyjasnione co znaczy, ktora linia w pliku daneZbazy.txt
22.7 - TempWEW
23.76 - TempZEW
1261.22 - Waga
65 - Wilgotnosc
10.7 - AccelerationX
-0.34 - AccelerationY
-0.83 - AccelerationZ
-0.19 - RotationX
-0.18 - RotationY
0 - RotationZ
*/