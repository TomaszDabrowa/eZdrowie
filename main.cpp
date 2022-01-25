#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <winbase.h>
#include <sstream>
#include <unistd.h>

using namespace std;

//deklaracja zmiennych
float wzrost[4], waga[4], BMI[4];
string nazwa0, nazwa1, nazwa2, nazwa3, nazwa4,
       slownie_BMI1, slownie_BMI2, slownie_BMI3, slownie_BMI4, slownie_BMI5;
int wybor, ilosc_linii_profil1, ilosc_linii_profil2, ilosc_linii_profil3, ilosc_linii_profil4, ilosc_linii_profil5;
fstream zapis_profil1, zapis_profil2, zapis_profil3, zapis_profil4, zapis_profil5, nazwy_profili,
        readme, license, zapis_ilosci_wpisow, changelog_zapis,
        backup_ilosc_wpisow, backup_profil1, backup_profil2, backup_profil3, backup_profil4, backup_profil5,
        backup_info, version;
SYSTEMTIME st;
bool good(), eof(), close();



//deklaracja procedur
void menu(), informacje(), utworz_profil(), zaloguj_sie(),
     utworz_profil1(), utworz_profil2(), utworz_profil3(), utworz_profil4(), utworz_profil5(),
     profil1(), profil2(), profil3(), profil4(), profil5(),
     utworz_wpis_profil1(), utworz_wpis_profil2(), utworz_wpis_profil3(), utworz_wpis_profil4(), utworz_wpis_profil5(),
     rejestr_wpisow_profil1(), rejestr_wpisow_profil2(), rejestr_wpisow_profil3(), rejestr_wpisow_profil4(), rejestr_wpisow_profil5(),
     pobierz_nazwy(), opis_programu(), tresc_licencji(), pobranie_ilosci_wpisow(), changelog(), backup(),
     sprawdz_aktualizacje();

     //WAZNA INFORMACJA DO PÓZNIEJSZEGO EDYTOWANIA
     //kazda zmienna dotyczaca danego profilu jest numerowana odpowiednio 1, 2, 3, 4, 5.
     //wyjatkiem sa zmienne nazwa, wzrost, waga i BMI, ktore to sa numerowane odpowiednio 0, 1, 2, 3, 4.
     //KOLEJNA WAZNA INFORMACJA
     //zmienna ilosc_linii_profil1 itd. okresla ilosc wpisow w danym profilu, a nie linii w pliku profilu.

// OBSLUGA MENU GLÓWNEGO
int main()
{

  //przed glowna petla pobranie nazw profilow

  string operacyjny;
  zapis_profil1.open("profile/profil1.txt",ios::in);

  if(zapis_profil1.good() == true)  //Pobieranie nazw
  {
   getline(zapis_profil1,operacyjny);
   nazwa0 = operacyjny;

  }
  else { cout << "Blad! Wymagany plik usuniety."; Sleep(2000); exit(0);}
zapis_profil1.close();

    zapis_profil2.open("profile/profil2.txt",ios::in);

  if(zapis_profil2.good() == true)
  {
   getline(zapis_profil2,operacyjny);
   nazwa1 = operacyjny;


  }
  else { cout << "Blad! Wymagany plik usuniety."; Sleep(2000); exit(0);}
zapis_profil2.close();

    zapis_profil3.open("profile/profil3.txt",ios::in);

  if(zapis_profil3.good() == true)
  {
   getline(zapis_profil3,operacyjny);
   nazwa2 = operacyjny;

  }
  else { cout << "Blad! Wymagany plik usuniety."; Sleep(2000); exit(0);}
   zapis_profil3.close();

    zapis_profil4.open("profile/profil4.txt",ios::in);

  if(zapis_profil4.good() == true)
  {
   getline(zapis_profil4,operacyjny);
   nazwa3 = operacyjny;

  }
  else { cout << "Blad! Wymagany plik usuniety."; Sleep(2000); exit(0);}
zapis_profil4.close();

    zapis_profil5.open("profile/profil5.txt",ios::in);

  if(zapis_profil5.good() == true)
  {
   getline(zapis_profil5,operacyjny);
   nazwa4 = operacyjny;

  }
  else { cout << "Blad! Wymagany plik usuniety."; Sleep(2000); exit(0);}
   zapis_profil5.close();

  //Glowna petla
  do
  {
      system("cls");
      menu();
      if(wybor==1)
      {
          wybor = 0;
          utworz_profil();
      }
      if(wybor==2)
      {
          wybor = 0;
          zaloguj_sie();
      }
      if(wybor==3)
      {
          wybor = 0;
          informacje();
      }
      if(wybor==4)
      {
          wybor = 0;
          backup();
      }
      if(wybor==5)
      {
          wybor = 0;
          sprawdz_aktualizacje();
      }

  } while(wybor!=6);

   return 0;
}

//UKLAD GRAFICZNY MENU GLÓWNEGO
void menu()
{
     system("cls");
     cout << "---------eZdrowie---------";
     version.open("version.txt",ios::in);
     if(version.good())
     {
         string linia;
         getline(version,linia);
         cout << linia<< endl;
     }
     version.close();
     cout << " " << endl;
     cout << "Menu glowne" << endl;
     cout << "1. Utworz profil" << endl;
     cout << "2. Zaloguj sie" << endl;
     cout << "3. Informacje" << endl;
     cout << "4. Kopia zapasowa" << endl;
     cout << "5. Sprawdz aktualizacje" << endl;
     cout << "6. Zamknij program" << endl;
     cout << "Twoj wybor: ";
     cin >> wybor;
}

//STRONA Z INFORMACJAMI O PROGRAMIE
void informacje()
{
    do
    {
        system("cls");
        cout << "Informacje" << endl;
        cout << "----------" << endl;
        cout << "1. Opis programu" << endl;
        cout << "2. Tresc licencji" << endl;
        cout << "3. Opis aktualizacji" << endl;
        cout << "4. Powrot do menu glownego" << endl;
        cout << "Twoj wybor: "; cin >> wybor;

        if(wybor==1)
        {
            wybor = 0;
            opis_programu();
        }

        if(wybor==2)
        {
            wybor = 0;
            tresc_licencji();
        }

        if(wybor==3)
        {
            wybor = 0;
            changelog();
        }

    } while(wybor!=4); wybor = 0;
}

void opis_programu()
{
    system("cls");
    readme.open("readme.txt",ios::in);

    if(readme.good()==true)
    {
        string linia; //zmienna lokalna

        while(!readme.eof())
        {
            getline(readme,linia);
            cout << linia << endl;
        }
        readme.close();
    }
    else if(readme.good()==false)
        {
            system("cls");
            cout<<"Blad! Czy usunales jakis plik? Wcisnij ENTER, aby wyjsc.";
            getchar(); getchar(); exit(0);
        }
    cout << "Aby wrocic do menu, wcisnij ENTER."; getchar(); getchar();
}

void tresc_licencji()
{
    system("cls");
    license.open("license.txt",ios::in);

    if(license.good()==true)
    {
        cout << "===================" << endl;
        cout << " LICENCJA eZDROWIE" << endl;
        cout << "===================" << endl;
        string linia;

        while(!license.eof())
        {
            getline(license,linia);
            cout << linia << endl;
        }
        license.close();
    }
    else if(license.good()==false)
        {
            system("cls");
            cout<<"Blad! Czy nie usunales jakiegos pliku? Wcisnij Enter, aby zakonczyc.";
            getchar(); getchar(); exit(0);
        }


    cout << "Aby wrocic do menu, wcisnij ENTER."; getchar(); getchar();
}

//MENU WYBORU PROFILU
void zaloguj_sie()
{
    do
    {
    system("cls");

    cout << "Wybierz profil:" << endl;
    cout << "1. " << nazwa0 << endl;
    cout << "2. " << nazwa1 << endl;
    cout << "3. " << nazwa2 << endl;
    cout << "4. " << nazwa3 << endl;
    cout << "5. " << nazwa4 << endl;
    cout << "6. Powrot do menu glownego" << endl;
    cout << "Twoj wybor: "; cin >> wybor;

    if(wybor==1)
    {
        wybor = 0;
        profil1();
    }

    if(wybor==2)
    {
        wybor = 0;
        profil2();
    }

    if(wybor==3)
    {
        wybor = 0;
        profil3();
    }

    if(wybor==4)
    {
        wybor = 0;
        profil4();
    }

    if(wybor==5)
    {
        wybor = 0;
        profil5();
    }

    }while(wybor!=6);

}

void utworz_profil()
{
    do
    {
        system("cls");
        cout << "Wybierz wolne miejsce, w ktorym chcesz stworzyc profil. Tworz profile po kolei." << endl;
        cout << "Jezeli wybierzesz istniejacy, to zostanie on zastapiony, a istniejacy zapis usuniety" << endl;
        cout << "(chyba, ze zostala wykonana kopia zapasowa):" << endl;
        cout << "1. " << nazwa0 << endl;
        cout << "2. " << nazwa1 << endl;
        cout << "3. " << nazwa2 << endl;
        cout << "4. " << nazwa3 << endl;
        cout << "5. " << nazwa4 << endl;
        cout << "6. Wroc do menu glownego" << endl;
        cout << "Twoj wybor: "; cin >> wybor;

        if(wybor==1)
        {
            wybor = 0;
            utworz_profil1();
        }

        if(wybor==2)
        {
            wybor = 0;
            utworz_profil2();
        }

        if(wybor==3)
        {
            wybor = 0;
            utworz_profil3();
        }

        if(wybor==4)
        {
            wybor = 0;
            utworz_profil4();
        }

        if(wybor==5)
        {
            wybor = 0;
            utworz_profil5();
        }

    } while(wybor!=6);
}

void utworz_profil1()
{
    system("cls");
    cout << "Kreator tworzenia profilu pierwszego" << endl;
    cout << "------------------------------------" << endl;
    cout << "Podaj nazwe profilu: "; cin >> nazwa0;
    cout << "Profil utworzony. Wcisnij ENTER, aby wrocic do menu glownego.";

    //od razu zapis nazwy do pliku z zapisem profilu

    ilosc_linii_profil1 = 0;
    zapis_profil1.open("profile/profil1.txt",ios::out);
    zapis_profil1 << nazwa0 << endl;
    zapis_profil1.close();
    getchar(); getchar();
}

void utworz_profil2()
{
    system("cls");
    cout << "Kreator tworzenia profilu drugiego" << endl;
    cout << "------------------------------------" << endl;
    cout << "Podaj nazwe profilu: "; cin >> nazwa1;
    cout << "Profil utworzony. Wcisnij ENTER, aby wrocic do menu glownego.";

    //od razu zapis nazwy do pliku z zapisem profilu

    ilosc_linii_profil2 = 0;
    zapis_profil2.open("profile/profil2.txt",ios::out);
    zapis_profil2 << nazwa1 << endl;
    zapis_profil2.close();
    getchar(); getchar();
}

void utworz_profil3()
{
    system("cls");
    cout << "Kreator tworzenia profilu trzeciego" << endl;
    cout << "------------------------------------" << endl;
    cout << "Podaj nazwe profilu: "; cin >> nazwa2;
    cout << "Profil utworzony. Wcisnij ENTER, aby wrocic do menu glownego.";

    //od razu zapis nazwy do pliku z zapisem profilu

    ilosc_linii_profil1 = 0;
    zapis_profil3.open("profile/profil3.txt",ios::out);
    zapis_profil3 << nazwa2 << endl;
    zapis_profil3.close();
    getchar(); getchar();
}

void utworz_profil4()
{
    system("cls");
    cout << "Kreator tworzenia profilu czwartego" << endl;
    cout << "------------------------------------" << endl;
    cout << "Podaj nazwe profilu: "; cin >> nazwa3;
    cout << "Profil utworzony. Wcisnij ENTER, aby wrocic do menu glownego.";

    //od razu zapis nazwy do pliku z zapisem profilu

    ilosc_linii_profil4 = 0;
    zapis_profil4.open("profile/profil4.txt",ios::out);
    zapis_profil4 << nazwa3 << endl;
    zapis_profil4.close();
    getchar(); getchar();
}

void utworz_profil5()
{
    system("cls");
    cout << "Kreator tworzenia profilu piatego" << endl;
    cout << "------------------------------------" << endl;
    cout << "Podaj nazwe profilu: "; cin >> nazwa4;
    cout << "Profil utworzony. Wcisnij ENTER, aby wrocic do menu glownego.";

    //od razu zapis nazwy do pliku z zapisem profilu

    ilosc_linii_profil5 = 0;
    zapis_profil5.open("profile/profil5.txt",ios::out);
    zapis_profil5 << nazwa4 << endl;
    zapis_profil5.close();
    getchar(); getchar();
}

void profil1()
{
    do
    {
        system("cls");
        cout << "eZdrowie" << endl;
        cout << "Profil: " << nazwa0 << endl;
        cout << "1. Rejestr wpisow" << endl;
        cout << "2. Utworz wpis" << endl;
        cout << "3. Wyloguj sie" << endl;
        cout << "Twoj wybor: "; cin >> wybor;

        if(wybor==1)
        {
            wybor = 0;
            rejestr_wpisow_profil1();
        }

        if(wybor==2)
        {
            wybor = 0;
            utworz_wpis_profil1();
        }

    } while(wybor!=3); wybor = 0;
}

void utworz_wpis_profil1()
{
    system("cls");
    cout << "Podaj swoja wage w kg (zamiast przecinkow wstaw kropke): "; cin >> waga[0];
    cout << "Podaj swoj wzrost w m (zamiast przecinkow staw kropke): "; cin >> wzrost[0];

    BMI[0] = waga[0]/(wzrost[0]*wzrost[0]);

    if(BMI[0]<16)
    {
        slownie_BMI1 = "wyglodzenie";
    }

    if((BMI[0]>=16)&&(BMI[0]<=16.99))
    {
        slownie_BMI1 = "wychudzenie";
    }

    if((BMI[0]>=17)&&(BMI[0]<=18.49))
    {
        slownie_BMI1 = "niedowaga";
    }

    if((BMI[0]>=18.5)&&(BMI[0]<=24.99))
       {
           slownie_BMI1 = "waga prawidlowa";
       }

    if((BMI[0]>=25)&&(BMI[0]<=29.99))
        {
            slownie_BMI1 = "nadwaga";
        }

    if((BMI[0]>=30)&&(BMI[0]<=34.99))
    {
        slownie_BMI1 = "otylosc I stopnia";
    }

    if((BMI[0]>=35)&&(BMI[0]<=39.99))
    {
        slownie_BMI1 = "otylosc II stopnia";
    }

    if(BMI[0]>=40)
    {
        slownie_BMI1 = "otylosc III stopnia";
    }
    pobranie_ilosci_wpisow();


    GetLocalTime(&st);

    zapis_profil1.open("profile/profil1.txt",ios::out|ios::app);
    zapis_profil1 << "Masa: " << waga[0] << " kg" << endl;
    zapis_profil1 << "Wzrost: " << wzrost[0] << " m" << endl;
    zapis_profil1 << "BMI: " << BMI[0] << endl;
    zapis_profil1 << "Stan: " << slownie_BMI1 << endl;
    zapis_profil1 << "Data: " << st.wDay << "." << st.wMonth << "." << st.wYear << endl;
    zapis_profil1 << "Dzien tygodnia: " << st.wDayOfWeek << endl;
    zapis_profil1 << "----------------" << endl;
    zapis_profil1.close();

    ilosc_linii_profil1++;

    zapis_ilosci_wpisow.open("profile/ilosc_wpisow.txt",ios::out);
    zapis_ilosci_wpisow << ilosc_linii_profil1 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil2 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil3 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil4 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil5 ;
    zapis_ilosci_wpisow.close();

    cout << " " << endl;
    cout << "Wpis zostal zarejestrowany i wpisany." << endl;
    cout << "Wcisnij ENTER, aby zatwierdzic.";
    getchar(); getchar();
}

void rejestr_wpisow_profil1()
{
    system("cls");
    cout << "--------------" << endl;
    cout << "   eZdrowie" << endl;
    cout << "--------------" << endl;
    cout << "Rejestr wpisow" << endl;
    cout << "--------------" << endl;
    pobranie_ilosci_wpisow();


    string linia; //zmienne lokalne


    zapis_profil1.open("profile/profil1.txt",ios::in);

    if(zapis_profil1.good())
        {

     getline(zapis_profil1,linia);

     int i;
     for(i=0; i<=7*ilosc_linii_profil1 ; i++)
     {
         getline(zapis_profil1,linia);
         cout << linia << endl;
     }
     zapis_profil1.close();
      cout << "Wcisnij ENTER, aby wrocic do menu.";
    getchar(); getchar();
    }

    else {system("cls"); cout<<"Blad! Wazny plik usuniety! Wcisnij ENTER, by wyjsc."; getchar(); exit(0);}
}

void profil2()
{
    do
    {
        system("cls");
        cout << "eZdrowie" << endl;
        cout << "Profil: " << nazwa1 << endl;
        cout << "1. Rejestr wpisow" << endl;
        cout << "2. Utworz wpis" << endl;
        cout << "3. Wyloguj sie" << endl;
        cout << "Twoj wybor: "; cin >> wybor;

        if(wybor==1)
        {
            wybor = 0;
            rejestr_wpisow_profil2();
        }

        if(wybor==2)
        {
            wybor = 0;
            utworz_wpis_profil2();
        }

    } while(wybor!=3); wybor = 0;
}

void utworz_wpis_profil2()
{
    system("cls");
    cout << "Podaj swoja wage w kg (zamiast przecinkow wstaw kropke): "; cin >> waga[1];
    cout << "Podaj swoj wzrost w m (zamiast przecinkow staw kropke): "; cin >> wzrost[1];

    BMI[1] = waga[1]/(wzrost[1]*wzrost[1]);

    if(BMI[1]<16)
    {
        slownie_BMI2 = "wyglodzenie";
    }

    if((BMI[1]>=16)&&(BMI[1]<=16.99))
    {
        slownie_BMI2 = "wychudzenie";
    }

    if((BMI[1]>=17)&&(BMI[1]<=18.49))
    {
        slownie_BMI2 = "niedowaga";
    }

    if((BMI[1]>=18.5)&&(BMI[1]<=24.99))
       {
           slownie_BMI2 = "waga prawidlowa";
       }

    if((BMI[1]>=25)&&(BMI[1]<=29.99))
        {
            slownie_BMI2 = "nadwaga";
        }

    if((BMI[1]>=30)&&(BMI[1]<=34.99))
    {
        slownie_BMI2 = "otylosc I stopnia";
    }

    if((BMI[1]>=35)&&(BMI[1]<=39.99))
    {
        slownie_BMI2 = "otylosc II stopnia";
    }

    if(BMI[1]>=40)
    {
        slownie_BMI2 = "otylosc III stopnia";
    }
    pobranie_ilosci_wpisow();


    GetLocalTime(&st);

    zapis_profil2.open("profile/profil2.txt",ios::out|ios::app);
    zapis_profil2 << "Masa: " << waga[1] << " kg" << endl;
    zapis_profil2 << "Wzrost: " << wzrost[1] << " m" << endl;
    zapis_profil2 << "BMI: " << BMI[1] << endl;
    zapis_profil2 << "Stan: " << slownie_BMI2 << endl;
    zapis_profil2 << "Data: " << st.wDay << "." << st.wMonth << "." << st.wYear << endl;
    zapis_profil2 << "Dzien tygodnia: " << st.wDayOfWeek << endl;
    zapis_profil2 << "----------------" << endl;
    zapis_profil2.close();

    ilosc_linii_profil2++;

    zapis_ilosci_wpisow.open("ilosc_wpisow.txt",ios::out);
    zapis_ilosci_wpisow << ilosc_linii_profil1 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil2 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil3 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil4 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil5 ;
    zapis_ilosci_wpisow.close();

    cout << " " << endl;
    cout << "Wpis zostal zarejestrowany i wpisany." << endl;
    cout << "Wcisnij ENTER, aby zatwierdzic.";
    getchar(); getchar();
}

void rejestr_wpisow_profil2()
{
    system("cls");
    cout << "--------------" << endl;
    cout << "   eZdrowie" << endl;
    cout << "--------------" << endl;
    cout << "Rejestr wpisow" << endl;
    cout << "--------------" << endl;
    pobranie_ilosci_wpisow();


    string linia; //zmienne lokalne


    zapis_profil2.open("profile/profil2.txt",ios::in);

    if(zapis_profil2.good())
        {

     getline(zapis_profil2,linia);

     int i;
     for(i=0; i<=7*ilosc_linii_profil2 ; i++)
     {
         getline(zapis_profil2,linia);
         cout << linia << endl;
     }
     zapis_profil2.close();
      cout << "Wcisnij ENTER, aby wrocic do menu.";
    getchar(); getchar();
    }

    else {system("cls"); cout<<"Blad! Wazny plik usuniety! Wcisnij ENTER, by wyjsc."; getchar(); exit(0);}
}

void profil3()
{
    do
    {
        system("cls");
        cout << "eZdrowie" << endl;
        cout << "Profil: " << nazwa2 << endl;
        cout << "1. Rejestr wpisow" << endl;
        cout << "2. Utworz wpis" << endl;
        cout << "3. Wyloguj sie" << endl;
        cout << "Twoj wybor: "; cin >> wybor;

        if(wybor==1)
        {
            wybor = 0;
            rejestr_wpisow_profil3();
        }

        if(wybor==2)
        {
            wybor = 0;
            utworz_wpis_profil3();
        }

    } while(wybor!=3); wybor = 0;
}

void utworz_wpis_profil3()
{
    system("cls");
    cout << "Podaj swoja wage w kg (zamiast przecinkow wstaw kropke): "; cin >> waga[2];
    cout << "Podaj swoj wzrost w m (zamiast przecinkow staw kropke): "; cin >> wzrost[2];

    BMI[2] = waga[2]/(wzrost[2]*wzrost[2]);

    if(BMI[2]<16)
    {
        slownie_BMI3 = "wyglodzenie";
    }

    if((BMI[2]>=16)&&(BMI[2]<=16.99))
    {
        slownie_BMI3 = "wychudzenie";
    }

    if((BMI[2]>=17)&&(BMI[2]<=18.49))
    {
        slownie_BMI3 = "niedowaga";
    }

    if((BMI[2]>=18.5)&&(BMI[2]<=24.99))
       {
           slownie_BMI3 = "waga prawidlowa";
       }

    if((BMI[2]>=25)&&(BMI[2]<=29.99))
        {
            slownie_BMI3 = "nadwaga";
        }

    if((BMI[2]>=30)&&(BMI[2]<=34.99))
    {
        slownie_BMI3 = "otylosc I stopnia";
    }

    if((BMI[2]>=35)&&(BMI[2]<=39.99))
    {
        slownie_BMI3 = "otylosc II stopnia";
    }

    if(BMI[2]>=40)
    {
        slownie_BMI3 = "otylosc III stopnia";
    }
    pobranie_ilosci_wpisow();


    GetLocalTime(&st);

    zapis_profil3.open("profile/profil3.txt",ios::out|ios::app);
    zapis_profil3 << "Masa: " << waga[2] << " kg" << endl;
    zapis_profil3 << "Wzrost: " << wzrost[2] << " m" << endl;
    zapis_profil3 << "BMI: " << BMI[2] << endl;
    zapis_profil3 << "Stan: " << slownie_BMI3 << endl;
    zapis_profil3 << "Data: " << st.wDay << "." << st.wMonth << "." << st.wYear << endl;
    zapis_profil3 << "Dzien tygodnia: " << st.wDayOfWeek << endl;
    zapis_profil3 << "----------------" << endl;
    zapis_profil3.close();

    ilosc_linii_profil3++;

    zapis_ilosci_wpisow.open("profile/ilosc_wpisow.txt",ios::out);
    zapis_ilosci_wpisow << ilosc_linii_profil1 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil2 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil3 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil4 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil5 ;
    zapis_ilosci_wpisow.close();

    cout << " " << endl;
    cout << "Wpis zostal zarejestrowany i wpisany." << endl;
    cout << "Wcisnij ENTER, aby zatwierdzic.";
    getchar(); getchar();
}

void rejestr_wpisow_profil3()
{
    system("cls");
    cout << "--------------" << endl;
    cout << "   eZdrowie" << endl;
    cout << "--------------" << endl;
    cout << "Rejestr wpisow" << endl;
    cout << "--------------" << endl;
    pobranie_ilosci_wpisow();


    string linia; //zmienne lokalne


    zapis_profil3.open("profile/profil3.txt",ios::in);

    if(zapis_profil3.good())
        {

     getline(zapis_profil3,linia);

     int i;
     for(i=0; i<=7*ilosc_linii_profil3 ; i++)
     {
         getline(zapis_profil3,linia);
         cout << linia << endl;
     }
     zapis_profil3.close();
      cout << "Wcisnij ENTER, aby wrocic do menu.";
    getchar(); getchar();
    }

    else {system("cls"); cout<<"Blad! Wazny plik usuniety! Wcisnij ENTER, by wyjsc."; getchar(); exit(0);}
}

void profil4()
{
    do
    {
        system("cls");
        cout << "eZdrowie" << endl;
        cout << "Profil: " << nazwa3 << endl;
        cout << "1. Rejestr wpisow" << endl;
        cout << "2. Utworz wpis" << endl;
        cout << "3. Wyloguj sie" << endl;
        cout << "Twoj wybor: "; cin >> wybor;

        if(wybor==1)
        {
            wybor = 0;
            rejestr_wpisow_profil4();
        }

        if(wybor==2)
        {
            wybor = 0;
            utworz_wpis_profil4();
        }

    } while(wybor!=3); wybor = 0;
}

void utworz_wpis_profil4()
{
    system("cls");
    cout << "Podaj swoja wage w kg (zamiast przecinkow wstaw kropke): "; cin >> waga[3];
    cout << "Podaj swoj wzrost w m (zamiast przecinkow staw kropke): "; cin >> wzrost[3];

    BMI[3] = waga[3]/(wzrost[3]*wzrost[3]);

    if(BMI[3]<16)
    {
        slownie_BMI4 = "wyglodzenie";
    }

    if((BMI[3]>=16)&&(BMI[3]<=16.99))
    {
        slownie_BMI4 = "wychudzenie";
    }

    if((BMI[3]>=17)&&(BMI[3]<=18.49))
    {
        slownie_BMI4 = "niedowaga";
    }

    if((BMI[3]>=18.5)&&(BMI[3]<=24.99))
       {
           slownie_BMI4 = "waga prawidlowa";
       }

    if((BMI[3]>=25)&&(BMI[3]<=29.99))
        {
            slownie_BMI4 = "nadwaga";
        }

    if((BMI[3]>=30)&&(BMI[3]<=34.99))
    {
        slownie_BMI4 = "otylosc I stopnia";
    }

    if((BMI[3]>=35)&&(BMI[3]<=39.99))
    {
        slownie_BMI4 = "otylosc II stopnia";
    }

    if(BMI[3]>=40)
    {
        slownie_BMI4 = "otylosc III stopnia";
    }
    pobranie_ilosci_wpisow();


    GetLocalTime(&st);

    zapis_profil4.open("profile/profil4.txt",ios::out|ios::app);
    zapis_profil4 << "Masa: " << waga[3] << " kg" << endl;
    zapis_profil4 << "Wzrost: " << wzrost[3] << " m" << endl;
    zapis_profil4 << "BMI: " << BMI[3] << endl;
    zapis_profil4 << "Stan: " << slownie_BMI4 << endl;
    zapis_profil4 << "Data: " << st.wDay << "." << st.wMonth << "." << st.wYear << endl;
    zapis_profil4 << "Dzien tygodnia: " << st.wDayOfWeek << endl;
    zapis_profil4 << "----------------" << endl;
    zapis_profil4.close();

    ilosc_linii_profil4++;

    zapis_ilosci_wpisow.open("profile/ilosc_wpisow.txt",ios::out);
    zapis_ilosci_wpisow << ilosc_linii_profil1 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil2 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil3 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil4 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil5 ;
    zapis_ilosci_wpisow.close();

    cout << " " << endl;
    cout << "Wpis zostal zarejestrowany i wpisany." << endl;
    cout << "Wcisnij ENTER, aby zatwierdzic.";
    getchar(); getchar();
}

void rejestr_wpisow_profil4()
{
    system("cls");
    cout << "--------------" << endl;
    cout << "   eZdrowie" << endl;
    cout << "--------------" << endl;
    cout << "Rejestr wpisow" << endl;
    cout << "--------------" << endl;
    pobranie_ilosci_wpisow();


    string linia; //zmienne lokalne


    zapis_profil4.open("profile/profil4.txt",ios::in);

    if(zapis_profil4.good())
        {

     getline(zapis_profil4,linia);

     int i;
     for(i=0; i<=7*ilosc_linii_profil4 ; i++)
     {
         getline(zapis_profil4,linia);
         cout << linia << endl;
     }
     zapis_profil4.close();
      cout << "Wcisnij ENTER, aby wrocic do menu.";
    getchar(); getchar();
    }

    else {system("cls"); cout<<"Blad! Wazny plik usuniety! Wcisnij ENTER, by wyjsc."; getchar(); exit(0);}
}

void profil5()
{
    do
    {
        system("cls");
        cout << "eZdrowie" << endl;
        cout << "Profil: " << nazwa4 << endl;
        cout << "1. Rejestr wpisow" << endl;
        cout << "2. Utworz wpis" << endl;
        cout << "3. Wyloguj sie" << endl;
        cout << "Twoj wybor: "; cin >> wybor;

        if(wybor==1)
        {
            wybor = 0;
            rejestr_wpisow_profil5();
        }

        if(wybor==2)
        {
            wybor = 0;
            utworz_wpis_profil5();
        }

    } while(wybor!=3); wybor = 0;
}

void utworz_wpis_profil5()
{
    system("cls");
    cout << "Podaj swoja wage w kg (zamiast przecinkow wstaw kropke): "; cin >> waga[4];
    cout << "Podaj swoj wzrost w m (zamiast przecinkow staw kropke): "; cin >> wzrost[4];

    BMI[4] = waga[4]/(wzrost[4]*wzrost[4]);

    if(BMI[4]<16)
    {
        slownie_BMI5 = "wyglodzenie";
    }

    if((BMI[4]>=16)&&(BMI[4]<=16.99))
    {
        slownie_BMI5 = "wychudzenie";
    }

    if((BMI[4]>=17)&&(BMI[4]<=18.49))
    {
        slownie_BMI5 = "niedowaga";
    }

    if((BMI[4]>=18.5)&&(BMI[4]<=24.99))
       {
           slownie_BMI5 = "waga prawidlowa";
       }

    if((BMI[4]>=25)&&(BMI[4]<=29.99))
        {
            slownie_BMI5 = "nadwaga";
        }

    if((BMI[4]>=30)&&(BMI[4]<=34.99))
    {
        slownie_BMI5 = "otylosc I stopnia";
    }

    if((BMI[4]>=35)&&(BMI[4]<=39.99))
    {
        slownie_BMI5 = "otylosc II stopnia";
    }

    if(BMI[4]>=40)
    {
        slownie_BMI5 = "otylosc III stopnia";
    }
    pobranie_ilosci_wpisow();


    GetLocalTime(&st);

    zapis_profil5.open("profile/profil5.txt",ios::out|ios::app);
    zapis_profil5 << "Masa: " << waga[4] << " kg" << endl;
    zapis_profil5 << "Wzrost: " << wzrost[4] << " m" << endl;
    zapis_profil5 << "BMI: " << BMI[4] << endl;
    zapis_profil5 << "Stan: " << slownie_BMI5 << endl;
    zapis_profil5 << "Data: " << st.wDay << "." << st.wMonth << "." << st.wYear << endl;
    zapis_profil5 << "Dzien tygodnia: " << st.wDayOfWeek << endl;
    zapis_profil5 << "----------------" << endl;
    zapis_profil5.close();

    ilosc_linii_profil5++;

    zapis_ilosci_wpisow.open("profile/ilosc_wpisow.txt",ios::out);
    zapis_ilosci_wpisow << ilosc_linii_profil1 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil2 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil3 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil4 << endl;
    zapis_ilosci_wpisow << ilosc_linii_profil5 ;
    zapis_ilosci_wpisow.close();

    cout << " " << endl;
    cout << "Wpis zostal zarejestrowany i wpisany." << endl;
    cout << "Wcisnij ENTER, aby zatwierdzic.";
    getchar(); getchar();
}

void rejestr_wpisow_profil5()
{
    system("cls");
    cout << "--------------" << endl;
    cout << "   eZdrowie" << endl;
    cout << "--------------" << endl;
    cout << "Rejestr wpisow" << endl;
    cout << "--------------" << endl;
    pobranie_ilosci_wpisow();


    string linia; //zmienne lokalne


    zapis_profil5.open("profile/profil5.txt",ios::in);

    if(zapis_profil5.good())
        {

     getline(zapis_profil5,linia);

     int i;
     for(i=0; i<=7*ilosc_linii_profil5 ; i++)
     {
         getline(zapis_profil5,linia);
         cout << linia << endl;
     }
     zapis_profil5.close();
      cout << "Wcisnij ENTER, aby wrocic do menu.";
    getchar(); getchar();
    }

    else {system("cls"); cout<<"Blad! Wazny plik usuniety! Wcisnij ENTER, by wyjsc."; getchar(); exit(0);}
}

void pobranie_ilosci_wpisow()
{
    zapis_ilosci_wpisow.open("profile/ilosc_wpisow.txt",ios::in);

        string linia;
        stringstream s;
        getline(zapis_ilosci_wpisow,linia);
        s << linia;
        s >> ilosc_linii_profil1;
        getline(zapis_ilosci_wpisow,linia);
        s << linia;
        s >> ilosc_linii_profil2;
        getline(zapis_ilosci_wpisow,linia);
        s << linia;
        s >> ilosc_linii_profil3;
        getline(zapis_ilosci_wpisow,linia);
        s << linia;
        s >> ilosc_linii_profil4;
        getline(zapis_ilosci_wpisow,linia);
        s << linia;
        s >> ilosc_linii_profil5;
        zapis_ilosci_wpisow.close();

}

void changelog()
{
    system("cls");
    cout << "==============" << endl;
    cout << "   eZdrowie" << endl;
    cout << "==============" << endl;
    cout << "Opis zmian aktualizacji:" << endl;
    changelog_zapis.open("changelog.txt",ios::in);
    if(changelog_zapis.good())
    {
        string linia;
        while( !changelog_zapis.eof() )
        {
            getline(changelog_zapis,linia);
            cout << linia << endl;
        }
        changelog_zapis.close();
        cout << "Wcisnij ENTER, aby wrocic do menu. "; getchar(); getchar();
    }
    else {cout<<"Blad! Wazny plik usuniety. Kliknij Enter, aby wyjsc."; getchar(); getchar(); exit(0);}
}

void backup()
{
    system("cls");
    cout << "Czy chcesz wykonac kopie zapasowa danych wszystkich pieciu profilow?" << endl;
    cout << "1. Tak" << endl;
    cout << "2. Nie, wracam do menu glownego." << endl;
    cout << "Twoj wybor: "; cin >> wybor;

    if(wybor == 1)
    {
        string linia;
        pobranie_ilosci_wpisow();
        zapis_ilosci_wpisow.open("profil/ilosc_wpisow.txt",ios::in);
        backup_ilosc_wpisow.open("backup/ilosc_wpisow.txt",ios::out);
        if(zapis_ilosci_wpisow.good())
        {

            //kopiowanie pliku ilosc_wpisow.txt
            getline(zapis_ilosci_wpisow,linia);
            backup_ilosc_wpisow << linia << endl;
            getline(zapis_ilosci_wpisow,linia);
            backup_ilosc_wpisow << linia << endl;
            getline(zapis_ilosci_wpisow,linia);
            backup_ilosc_wpisow << linia << endl;
            getline(zapis_ilosci_wpisow,linia);
            backup_ilosc_wpisow << linia << endl;
            getline(zapis_ilosci_wpisow,linia);
            backup_ilosc_wpisow << linia ;

            zapis_ilosci_wpisow.close();
            backup_ilosc_wpisow.close();

        }

        backup_profil1.open("backup/profil1.txt",ios::out);
        zapis_profil1.open("profil1.txt",ios::out);

        if(zapis_profil1.good())
        {
           //kopia zapasowa profilu 1
           getline(zapis_profil1,linia);
           backup_profil1 << linia << endl;
           for(int i=0; i<=7*ilosc_linii_profil1 ; i++)
           {
               getline(zapis_profil1,linia);
               backup_profil1 << linia << endl;
           }


        }


        zapis_profil1.close();
        backup_profil1.close();

        backup_profil2.open("backup/profil2.txt",ios::out);
        zapis_profil2.open("profil2.txt",ios::out);

        if(zapis_profil2.good())
        {
           //kopia zapasowa profilu 2
           getline(zapis_profil2,linia);
           backup_profil2 << linia << endl;
           for(int i=0; i<=7*ilosc_linii_profil2 ; i++)
           {
               getline(zapis_profil2,linia);
               backup_profil2 << linia << endl;
           }

        }



        zapis_profil2.close();
        backup_profil2.close();

        backup_profil3.open("backup/profil3.txt",ios::out);
        zapis_profil3.open("profil3.txt",ios::out);

        if(zapis_profil3.good())
        {
           //kopia zapasowa profilu 3
           getline(zapis_profil3,linia);
           backup_profil3 << linia << endl;
           for(int i=0; i<=7*ilosc_linii_profil3 ; i++)
           {
               getline(zapis_profil3,linia);
               backup_profil3 << linia << endl;
           }

        }



        zapis_profil3.close();
        backup_profil3.close();

        backup_profil4.open("backup/profil4.txt",ios::out);
        zapis_profil4.open("profil4.txt",ios::out);

        if(zapis_profil4.good())
        {
           //kopia zapasowa profilu 4
           getline(zapis_profil4,linia);
           backup_profil4 << linia << endl;
           for(int i=0; i<=7*ilosc_linii_profil4 ; i++)
           {
               getline(zapis_profil4,linia);
               backup_profil4 << linia << endl;
           }

        }



        zapis_profil4.close();
        backup_profil4.close();

        backup_profil5.open("backup/profil5.txt",ios::out);
        zapis_profil5.open("profil5.txt",ios::out);

        if(zapis_profil5.good())
        {
           //kopia zapasowa profilu 5
           getline(zapis_profil5,linia);
           backup_profil5 << linia << endl;
           for(int i=0; i<=7*ilosc_linii_profil5 ; i++)
           {
               getline(zapis_profil5,linia);
               backup_profil5 << linia << endl;
           }

        }



        zapis_profil5.close();
        backup_profil5.close();

        backup_info.open("backup/informacje.txt",ios::out);
        backup_info << "Powyzsza kopia zapasowa zostala wykonana: " << endl;
        GetLocalTime(&st);
        backup_info <<st.wDay<<"."<<st.wMonth<<"."<<st.wYear<<endl;
        backup_info <<st.wHour<<":"<<st.wMinute<<":"<<st.wSecond;
        backup_info.close();

        system("cls");
        cout << "Kopia zapasowa zostala przeprowadzona pomyslnie." << endl;
        cout << "Zostala zapisana w folderze backup." << endl;
        cout << "Aby w razie utraty plikow przywrocic zapis z kopii zapasowej," << endl;
        cout << "nalezy przekopiowac zawartosc folderu backup do folderu profile w plikach aplikacji." << endl;
        cout << "Aby wrocic do menu glownego, wcisnij ENTER.";
        getchar(); getchar();

    }

}

void sprawdz_aktualizacje()
{
    system("cls");
    cout << "W obecnej wersji nie ma jeszcze takiej funkcji." << endl;
    cout << "Wcisnij ENTER, aby wrocic do poprzedniego menu.";
    getchar(); getchar();
}
