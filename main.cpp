#include <iostream>
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

public:

    void Zmiana_TEMP(int atempWEW, int atempZEW)
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

};

int main()
{
    
    return 0;
}
