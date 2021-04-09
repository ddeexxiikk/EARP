#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

class UL
{
private:
    int TemperaturaWEW1, TemperaturaWEW2,
    TemperaturaZEW1, TemperaturaZEW2, 
    Wilgotnosc1, Wilgotnosc2, 
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

    void zmianawilgotnosci(int aWilgotnosc, int aWilgotnosc2)
    {
        Wilgotnosc1 = aWilgotnosc;
        Wilgotnosc2 = aWilgotnosc2;
    }

    void zmianaprzyspieszeniaX(int aAcceX, int aAcceX2)
    {
        AcceX1 = aAcceX;
        AcceX2 = aAcceX2;
    }

    void zmianaprzyspieszeniaY(int aAcceY, int aAcceY2)
    {
        AcceY1 = aAcceY;
        AcceY2 = aAcceY2;
    }
   
    void zmianaprzyspieszeniaZ(int aAcceZ, int aAcceZ2)
    {
        AcceZ1 = aAcceZ;
        AcceZ2 = aAcceZ2;
    }
    
    void zmianarotaX(int aRotX, int aRotX2)
    {
        RotX1 = aRotX;
        RotX2 = aRotX2;
    }

    void zmianarotaY(int aRotY, int aRotY2)
    {
        RotY1 = aRotY;
        RotY2 = aRotY2;
    }

    void zmianarotaZ(int aRotZ, int aRotZ2)
    {
        RotZ1 = aRotZ;
        RotZ2 = aRotZ2;
    }

    //Tutaj piszemy funkcje zwracajace chyba stringi, które analizują te dane - a teraz sprawdz public
    std::string Sprawdzenie_Temperatury_Wewnatrz()
    {   
        std::string wynik;
        if(abs(TemperaturaWEW2-TemperaturaWEW1)>=2)
            wynik = "Temperatura w Ulu szybko sie obnizyla\n";
        else
            wynik = "OK";

        return wynik;
    }

    std::string Sprawdzenie_Roznicy_Temperatur_W_Ulu()
    {
        std::string wynik;
        if(abs(TemperaturaZEW1-TemperaturaWEW1)>9)
            wynik = "Strasznie duza roznica temperatur pomiedzy Ulem a Otoczeniem\n";
        else
            wynik = "OK";

        return wynik;
    }

    std::string Sprawdzenie_Wagi()
    {
        std::string wynik;
        if(((Waga2-Waga1)>0)&&((Waga2-Waga1)<=2))
            wynik = "Ucieczka Roju z Ula\n";
        else if(((Waga2-Waga1)>0)&&((Waga2-Waga1)>2))
            wynik = "Ul zbyt szybko przybral na wadze!\n";
        else
            wynik = "OK";

        return wynik;
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

    void Zmiana_Wilgotnosci(int *aWilgotnosc, int *aWilgotnosc2)
    {
        zmianawilgotnosci(*aWilgotnosc, *aWilgotnosc2);
    }

    void Zmiana_Przyspieszen(int *aAcceX, int *aAcceY, int *aAcceZ, int* aAcceX2, int *aAcceY2, int *aAcceZ2)
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

    std::string Roznica_Temperatur()
    {
        return Sprawdzenie_Roznicy_Temperatur_W_Ulu();
    }

    std::string Waga_Ula()
    {
        return Sprawdzenie_Wagi();
    }

};

int main()
{
    //Program czeka 15 sekund, gdyby nastapilo opoznienie z zapisem do pliku w Pythonie
    Sleep(15000);

    std::fstream plikLAST;
    std::string wejscie;
    int TemperaturaWEW, TemperaturaZEW, Waga, Wilgotnosc, AcceX, AcceY, AcceZ, RotX, RotY, RotZ, 
        TemperaturaWEW2, TemperaturaZEW2, Waga2, Wilgotnosc2, AcceX2, AcceY2, AcceZ2, RotX2, RotY2, RotZ2;

    plikLAST.open("DaneZBazyLAST.txt", std::ios::in);

    if(plikLAST.good() == false)
        exit(0);

    for(int i=0; i<10; i++)
    {
        std::getline(plikLAST, wejscie);
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

    std::fstream plikPRE;

    plikLAST.close();
    plikPRE.open("DaneZBazyPRE.txt", std::ios::in);

    if(plikPRE.good() == false)
        exit(0);

    for(int i=0; i<10; i++)
    {
        std::getline(plikPRE, wejscie);
        if(i==0)
            TemperaturaWEW2 = stoi(wejscie);
        else if(i==1)
            TemperaturaZEW2 = stoi(wejscie);
        else if(i==2)
            Waga2 = stoi(wejscie);
        else if(i==3)
            Wilgotnosc2 = stoi(wejscie);
        else if(i==4)
            AcceX2 = stoi(wejscie);
        else if(i==5)
            AcceY2 = stoi(wejscie);
        else if(i==6)
            AcceZ2 = stoi(wejscie);
        else if(i==7)
            RotX2 = stoi(wejscie);
        else if(i==8)
            RotY2 = stoi(wejscie);
        else if(i==9)
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

    if(ul.Roznica_Temperatur() != "OK")
        plikZAPIS << ul.Roznica_Temperatur();
    
    if(ul.Waga_Ula() != "OK")
        plikZAPIS << ul.Waga_Ula();

    plikZAPIS.close();

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