#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <algorithm>

using namespace std;

string login, haslo;
char wybor;

int main()
{
    for(;;)
{
    cout << "<<<<<<<<<<<<<<<<<<< ZAKUPKI.PL >>>>>>>>>>>>>>>>>>>" << endl;
    cout << "-------------------------------------------------" << endl<<endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "3. Przegladaj oferty" << endl;
    cout << "4. Wyjdz" << endl;
wybor=getch();
fstream logowanie;
            logowanie.open("logowanie.txt",ios::out | ios::app);
            logowanie<<login<<endl;
            logowanie<<haslo<<endl  ;



string przedmiot[1000];
int cena[1000];
int nr_linii=1;
int nr_aukcji=0;
    string linia;
fstream aukcje;
    aukcje.open("aukcje.txt",ios::in);
    if (aukcje.good()==false)
    {
        cout<<"Nie udalo sie otworzyc pliku!";
        exit(0);
    }
    while(getline(aukcje,linia))
    {
        switch(nr_linii)
        {
            case 1: przedmiot[nr_aukcji] = linia;                     break;
            case 2: cena[nr_aukcji] = linia;                      break;
        }

        if (nr_linii==2) {nr_linii=0; nr_aukcji++;}
        nr_linii++;
    }



 switch(wybor)
    {
    case '1':
            cout<<"<<<<<<<<<<<<<<<<<<<<< REJESTRACJA >>>>>>>>>>>>>>>>>>>"<<endl<<endl<<endl;
            cout << "Podaj swoj przyszly login:  " ;        cin>>login;
            cout << "Podaj swoje przyszle haslo:  " ;       cin>>haslo;
            cout << "Podaj nr konta bankowego(123456789):  " << endl;



            logowanie.close();

    break;

    case '2':
            cout<<"<<<<<<<<<<<<<<<<<<<<< LOGOWANIE >>>>>>>>>>>>>>>>>>>"<<endl<<endl<<endl;
            cout << "Login:  " << endl;
            cout << "Haslo:  " << endl;
    break;

    case '3':
            cout<<"<<<<<<<<<<<<<<<<<<<<< OFERTY >>>>>>>>>>>>>>>>>>>"<<endl<<endl<<endl;
            aukcje.close();

    break;

    case '4':
            exit(0);
    break;
    default: cout<<"Nie ma takiej opcji w menu!";
    }
    getchar();getchar();
    system("cls");
}
    return 0;
}
