#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

class UL
{
private:
    int TemperaturaWEW1, TemperaturaWEW2,
    TemperaturaZEW1, TemperaturaZEW2, 
    Waga1, Waga2,
    AcceX1, AcceX2,
    AcceY1, AcceY2, 
    AcceZ1, AcceZ2,
    RotX1, RotX2,
    RotY1, RotY2,
    RotZ1, RotZ2;

    void zmianatempWEW(int aTemperatura, int aTemperatura2)
    {
        TemperaturaWEW1 = aTemperatura;
        TemperaturaWEW2 = aTemperatura2;
    }

    void zmianatempZEW(int aTemperatura, int aTemperatura2)
    {
        TemperaturaZEW1 = aTemperatura;
        TemperaturaZEW2 = aTemperatura2;
    }

    void zmianawagi(int aWaga, int aWaga2)
    {
            Waga1 = aWaga;
            Waga2 = aWaga2;
    }

    void zmianaprzyspieszeniaX(float aAcceX, float aAcceX2)
    {
        AcceX1 = aAcceX;
        AcceX2 = aAcceX2;
    }

    void zmianaprzyspieszeniaY(float aAcceY, float aAcceY2)
    {
        AcceY1 = aAcceY;
        AcceY2 = aAcceY2;
    }
   
    void zmianaprzyspieszeniaZ(float aAcceZ, float aAcceZ2)
    {
        AcceZ1 = aAcceZ;
        AcceZ2 = aAcceZ2;
    }
    
    void zmianarotaX(float aRotX, float aRotX2)
    {
        RotX1 = aRotX;
        RotX2 = aRotX2;
    }

    void zmianarotaY(float aRotY, float aRotY2)
    {
        RotY1 = aRotY;
        RotY2 = aRotY2;
    }

    void zmianarotaZ(float aRotZ, float aRotZ2)
    {
        RotZ1 = aRotZ;
        RotZ2 = aRotZ2;
    }

    //Tutaj piszemy funkcje, które analizują te dane
    std::string Sprawdzenie_Temperatury_Wewnatrz()
    {   if(TemperaturaWEW1<0)
            return "Temperatura w Ulu jest ponizej 0\n";
        else if(abs(TemperaturaWEW2-TemperaturaWEW1)>=2)
            return "Temperatura w Ulu szybko sie obnizyla\n";
        else
            return "OK";
    }

    std::string Sprawdzenie_Wagi()
    {
        if((Waga1 > Waga2) && (Waga1 - Waga2) > 2)
            return "Ul zbyt szybko przybral na wadze!\n";
        else if((Waga2 > Waga1) && (Waga2 - Waga1) <=2 && (Waga2-Waga1) != 0)
            return "Ucieczka Roju z Ula\n";
        else
            return "OK";
    }

    std::string Sprawdzenie_Przesuniecia()
    {
        if(AcceX1 != AcceX2 || AcceY1 != AcceY2 || AcceZ1 != AcceZ2 || RotX1 != RotX2 || RotY1 != RotY2 || RotZ1 != RotZ2)
            return "Ul sie poruszyl";
        else
            return "OK";
    }

public:

    void Zmiana_Temp(int *aTempWEW, int *aTempWEW2, int *aTempZEW, int *aTempZEW2)
    {
        zmianatempWEW(*aTempWEW, *aTempWEW2);
        zmianatempZEW(*aTempZEW, *aTempZEW2);
    }

    void Zmiana_Wagi(int *awaga, int *awaga2)
    {
        zmianawagi(*awaga, *awaga2);
    }

    void Zmiana_Przyspieszen(int *aAcceX, int *aAcceY, int *aAcceZ, int *aAcceX2, int *aAcceY2, int *aAcceZ2)
    {
        zmianaprzyspieszeniaX(*aAcceX, *aAcceX2);
        zmianaprzyspieszeniaY(*aAcceY, *aAcceY2);
        zmianaprzyspieszeniaZ(*aAcceZ, *aAcceZ2);
    }

    void Zmiana_Rotacji(int *aRotX, int *aRotY, int *aRotZ, int *aRotX2, int *aRotY2, int *aRotZ2)
    {
        zmianarotaX(*aRotX, *aRotX2);
        zmianarotaY(*aRotY, *aRotY2);
        zmianarotaZ(*aRotZ, *aRotZ2);
    }

    //Tutaj beda funkcje, ktore zwracaja nam tez stringi bazujące na metodach z sekcji private z odpowiednimi tekstami, ktore później wrzucamy do pliku
    std::string Temperatura_Wewnatrz()
    {
        return Sprawdzenie_Temperatury_Wewnatrz();
    }

    std::string Waga_Ula()
    {
        return Sprawdzenie_Wagi();
    }

    std::string Przesuniecie_Ula()
    {
        return Sprawdzenie_Przesuniecia();
    }

};

int main()
{
    printf("%s\n","Początek main.cpp");
    std::fstream plikLAST;
    std::string wejscie;
    int TemperaturaWEW, TemperaturaZEW, Waga, AcceX, AcceY, AcceZ, RotX, RotY, RotZ, 
        TemperaturaWEW2, TemperaturaZEW2, Waga2, AcceX2, AcceY2, AcceZ2, RotX2, RotY2, RotZ2;
    
    plikLAST.open("DaneZBazyLAST.txt", std::ios::in);

    if(plikLAST.good() == false)
        exit(0);

    for(int i=0; i<9; i++)
    {
        std::getline(plikLAST, wejscie);
        if(i==0)
            TemperaturaWEW = stoi(wejscie);
        else if(i==1)
            TemperaturaZEW = stoi(wejscie);
        else if(i==2)
        {
            Waga = stoi(wejscie);
            Waga/=10;
        }
        else if(i==3)
            AcceX = stoi(wejscie);
        else if(i==4)
            AcceY = stoi(wejscie);
        else if(i==5)
            AcceZ = stoi(wejscie);
        else if(i==6)
            RotX = stoi(wejscie);
        else if(i==7)
            RotY = stoi(wejscie);
        else if(i==8)
            RotZ = stoi(wejscie);
    }
    
    std::fstream plikPRE;

    plikLAST.close();
    plikPRE.open("DaneZBazyPRE.txt", std::ios::in);

    if(plikPRE.good() == false)
        exit(0);

    for(int i=0; i<9; i++)
    {
        std::getline(plikPRE, wejscie);
        if(i==0)
            TemperaturaWEW2 = stoi(wejscie);
        else if(i==1)
            TemperaturaZEW2 = stoi(wejscie);
        else if(i==2)
            {
            Waga2 = stoi(wejscie);
            Waga2/=10;
        }
        else if(i==3)
            AcceX2 = stoi(wejscie);
        else if(i==4)
            AcceY2 = stoi(wejscie);
        else if(i==5)
            AcceZ2 = stoi(wejscie);
        else if(i==6)
            RotX2 = stoi(wejscie);
        else if(i==7)
            RotY2 = stoi(wejscie);
        else if(i==8)
            RotZ2 = stoi(wejscie);
    }

    plikPRE.close();

    UL ul;

    ul.Zmiana_Temp(&TemperaturaWEW, &TemperaturaWEW2, &TemperaturaZEW,&TemperaturaZEW2);
    ul.Zmiana_Wagi(&Waga, &Waga2);
    ul.Zmiana_Przyspieszen(&AcceX, &AcceY, &AcceZ, &AcceX2, &AcceY2, &AcceZ2);
    ul.Zmiana_Rotacji(&RotX, &RotY, &RotZ, &RotX2, &RotY2, &RotZ2);

    std::fstream plikZAPIS;
    plikZAPIS.open("KodyBledow.txt", std::ios::out | std::ios::trunc);
    
    if(plikZAPIS.good() == false)
        exit(0);

    if(ul.Temperatura_Wewnatrz() != "OK")
        plikZAPIS << ul.Temperatura_Wewnatrz();

    if(ul.Waga_Ula() != "OK")
        plikZAPIS << ul.Waga_Ula();

    if(ul.Przesuniecie_Ula()!="OK")
        plikZAPIS << ul.Przesuniecie_Ula();
    
    printf("%s\n","Koniec main.cpp");
    plikZAPIS.close();

    return 0;
}
