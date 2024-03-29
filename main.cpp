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
    RotZ1, RotZ2,
    Sound1;

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
    
    void zmianasounda(int aSound)
    {
        Sound1 = aSound;
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
        if((Waga1 > Waga2) && ((Waga1 - Waga2) >= 2000))
            return "Ul zbyt szybko przybral na wadze!\n";
        else if((Waga2 > Waga1) && ((Waga2 - Waga1) <=2000) && ((Waga2-Waga1) > 200))
            return "Ucieczka Roju z Ula\n";
        else
            return "OK";
    }

    std::string Sprawdzenie_Przesuniecia()
    {
        if(((AcceX1>AcceX2)&&((AcceX1-AcceX2)>10)) || ((AcceX2>AcceX1)&&((AcceX2-AcceX1)>10)) || ((AcceY1>AcceY2)&&((AcceY1-AcceY2)>10)) || ((AcceY2>AcceY1)&&((AcceY2-AcceY1)>10)) || ((AcceZ1>AcceZ2)&&((AcceZ1-AcceZ2)>10)) || ((AcceZ2>AcceZ1)&&((AcceZ2-AcceZ1)>10)) || ((RotX1>RotX2)&&((RotX1-RotX2)>10)) || ((RotX2>RotX1)&&((RotX2-RotX1)>10)) || ((RotY1>RotY2)&&((RotY1-RotY2)>10)) || ((RotY2>RotY1)&&((RotY2-RotY1)>10)) || ((RotZ1>RotZ2)&&((RotZ1-RotZ2)>10)) || ((RotZ2>RotZ1)&&((RotZ2-RotZ1)>10)))
            return "Ul sie poruszyl"; 
        else
            return "OK";
    }

    std::string Sprawdzenie_Sounda()
    {
        if(Sound1 < 10)
            return "Brak dzwieku w Ulu\n";
        else
            return "OK";
    }

public:

    UL(int *aTempWEW, int *aTempWEW2, int *aTempZEW, int *aTempZEW2, int *awaga, int *awaga2, int *aAcceX, int *aAcceY, int *aAcceZ, 
    int *aAcceX2, int *aAcceY2, int *aAcceZ2, int *aRotX, int *aRotY, int *aRotZ, int *aRotX2, int *aRotY2, int *aRotZ2, int *aSound)
    {
        Zmiana_Temp(*aTempWEW, *aTempWEW2, *aTempZEW, *aTempZEW2);
        Zmiana_Wagi(*awaga, *awaga2);
        Zmiana_Przyspieszen(*aAcceX, *aAcceY, *aAcceZ, *aAcceX2, *aAcceY2, *aAcceZ2);
        Zmiana_Rotacji(*aRotX, *aRotY, *aRotZ, *aRotX2, *aRotY2, *aRotZ2);
        Zmiana_Sounda(*aSound);
    }

    void Zmiana_Temp(int aTempWEW, int aTempWEW2, int aTempZEW, int aTempZEW2)
    {
        zmianatempWEW(aTempWEW, aTempWEW2);
        zmianatempZEW(aTempZEW, aTempZEW2);
    }

    void Zmiana_Wagi(int awaga, int awaga2)
    {
        zmianawagi(awaga, awaga2);
    }

    void Zmiana_Przyspieszen(int aAcceX, int aAcceY, int aAcceZ, int aAcceX2, int aAcceY2, int aAcceZ2)
    {
        zmianaprzyspieszeniaX(aAcceX, aAcceX2);
        zmianaprzyspieszeniaY(aAcceY, aAcceY2);
        zmianaprzyspieszeniaZ(aAcceZ, aAcceZ2);
    }

    void Zmiana_Rotacji(int aRotX, int aRotY, int aRotZ, int aRotX2, int aRotY2, int aRotZ2)
    {
        zmianarotaX(aRotX, aRotX2);
        zmianarotaY(aRotY, aRotY2);
        zmianarotaZ(aRotZ, aRotZ2);
    }
    
    void Zmiana_Sounda(int aSound)
    {
        zmianasounda(aSound);
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

    std::string Dzwiek_Ula()
    {
        return Sprawdzenie_Sounda();
    }
};

int main()
{
    std::cout << "Poczatek main.cpp" << std::endl;
    std::fstream plikLAST;
    std::string wejscie;
    int TemperaturaWEW, TemperaturaZEW, Waga, AcceX, AcceY, AcceZ, RotX, RotY, RotZ, Sound,
        TemperaturaWEW2, TemperaturaZEW2, Waga2, AcceX2, AcceY2, AcceZ2, RotX2, RotY2, RotZ2;
    
    plikLAST.open("/var/www/html/Analiza/DaneZBazyLAST.txt", std::ios::in);

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
            Waga = stoi(wejscie);
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
        else if(i==9)
            Sound = stoi(wejscie);
    }
    plikLAST.close();

    std::fstream plikPRE;
    plikPRE.open("/var/www/html/Analiza/DaneZBazyPRE.txt", std::ios::in);

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
            Waga2 = stoi(wejscie);
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

    std::fstream plikZAPIS;
    plikZAPIS.open("/var/www/html/Analiza/KodyBledow.txt", std::ios::out | std::ios::trunc);

    if( (TemperaturaWEW==0 && TemperaturaZEW==0 && Waga==0 && AcceX==0 && AcceY==0 && AcceZ==0 && RotX==0 && RotY==0 && RotZ==0 && Sound==0 &&
        TemperaturaWEW2==0 && TemperaturaZEW2==0 && Waga2==0 && AcceX2==0 && AcceY==0 && AcceZ2==0 && RotX2==0 && RotY2==0 && RotZ2==0) || 
        (TemperaturaWEW==0 && TemperaturaZEW==0 && Waga==0 && AcceX==0 && AcceY==0 && AcceZ==0 && RotX==0 && RotY==0 && RotZ==0 && Sound==0) )
    {
    plikZAPIS << "BLAD CZUJNIKOW\n";
    std::cout << "BLAD CZUJNIKOW" << std::endl;
    plikZAPIS.close();
    }
    else
    {
    UL ul(&TemperaturaWEW, &TemperaturaWEW2, &TemperaturaZEW,&TemperaturaZEW2, &Waga, &Waga2, &AcceX, &AcceY, &AcceZ, &AcceX2, &AcceY2, &AcceZ2,
    &RotX, &RotY, &RotZ, &RotX2, &RotY2, &RotZ2, &Sound);

    /*ul.Zmiana_Temp(&TemperaturaWEW, &TemperaturaWEW2, &TemperaturaZEW,&TemperaturaZEW2);
    ul.Zmiana_Wagi(&Waga, &Waga2);
    ul.Zmiana_Przyspieszen(&AcceX, &AcceY, &AcceZ, &AcceX2, &AcceY2, &AcceZ2);
    ul.Zmiana_Rotacji(&RotX, &RotY, &RotZ, &RotX2, &RotY2, &RotZ2);
    ul.Zmiana_Sounda(&Sound);*/

    std::fstream plikZAPIS;
    plikZAPIS.open("/var/www/html/Analiza/KodyBledow.txt", std::ios::out | std::ios::trunc);
    
        if(plikZAPIS.good() == false)
        {
            exit(0);
            std::cout << "Koniec main.cpp ale nieudany zapis" << std::endl;
        }
        else
        {
            if(ul.Temperatura_Wewnatrz() != "OK")
                plikZAPIS << ul.Temperatura_Wewnatrz();

            if(ul.Waga_Ula() != "OK")
                plikZAPIS << ul.Waga_Ula();

            if(ul.Przesuniecie_Ula()!="OK")
                plikZAPIS << ul.Przesuniecie_Ula();
        
            if(ul.Dzwiek_Ula()!="OK")
                plikZAPIS << ul.Dzwiek_Ula();
    
            plikZAPIS.close();
        }
    }

    std::cout << "Koniec main.cpp" << std::endl;
    
    return 0;
}
