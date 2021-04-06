#include <iostream>

/* Jak chcesz to odkomentuj
using namespace std;
bo ja staram się jak najmniej uzywac ale jak wolisz uzywac to ja nie mam problemu*/

class UL
{
private:
    int TemperaturaWEW1, TemperaturaWEW2,
    TemperaturaZEW1, TemperaturaZEW2, 
    Wilgotnosc1, Wilgotnosc2, 
    Waga1, Waga2, Waga3,
    Opady, 
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
        if(waga>=0)
        {
            Waga3 = Waga2;
            Waga2 = Waga1;
            Waga 1= awaga;
        }
    }

    void zmianaprzyspieszeniaX(int aAcceX)
    {
        AcceX2 = AcceX1;
        AcceX1 = aAcceX;
    }

    void zmianaprzyspieszeniaY(int aAcceY)
    {
        AcceY2 = AcceY1;
        AcceY1 = aAcceY;
    }

    void zmianaprzyspieszeniaZ(int aAcceZ)
    {
        AcceZ2 = AcceZ1;
        AcceZ1 = aAcceZ;
    }

    /*Trzeba dorobic procedury zmiany rotacjiX...Y...Z
    Zarowno w 'public' jak i w 'private'*/

public:

    void Zmiana_TEMP(int atempWEW, int atempZEW)
    {
        ZmianaTempWEW(atempWEW);
        ZmianaTempZEW(atempZEW);

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

    /*Trzeba dorobic procedury zmiany rotacjiX...Y...Z
    Zarowno w 'public' jak i w 'private'*/
    
    //Pewien test - nie przejmuj sie ta linijka
};

int main()
{
    
    return 0;
}
