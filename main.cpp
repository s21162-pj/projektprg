#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <curses.h>
#include <fstream>
#include <algorithm>
using namespace std;

class User {

public:
    string username;
    string password;
    string iUsername;
    string iPassword;

string nazwap;
    // Funkcja Rejestracji
    void userRegisterDo()
    {

        ofstream usersFile ("dane.txt");

        if (	!usersFile.is_open())
        {
            usersFile.open("dane.txt");
        }

            usersFile << username << " " << password << endl;

            usersFile.close();
    }

    // Rejestracja
    void userRegister()
    {
        cout << "\n\n<<<<<<<<<<<<<<<<<<< ZAKUPKI.PL >>>>>>>>>>>>>>>>>>>\n" << endl;
        cout << "Witaj! Widzimy ze jestes tu pierwszy raz!\n\nZarejestruj sie!.\nWprowadz przyszla nazwe uzytkownika:\n";
        cin >> username;

        cout << "\nWprowadz twoje przyszle haslo:\n";
        cin >> password;

        userRegisterDo();
    }

    // Funkcja logowania
    void login()
    {
        cout << "\n\n<<<<<<<<<<<<<<<<<<< ZAKUPKI.PL >>>>>>>>>>>>>>>>>>>\n" << endl;
        cout << "Wprowadz nazwe uzytkownika:\n";
        cin >> iUsername;

        cout << "\nWprowadz haslo:\n";
        cin >> iPassword;

        string userAndPass = iUsername + " " + iPassword;
        int offset;
        string line;
        ifstream usersFile;
        usersFile.open ("dane.txt");

        if(usersFile.is_open())
        {
           bool found = false;
      if(usersFile.is_open()) {
          while(getline(usersFile,line) && !found) {
              if (line.compare(userAndPass) == 0) {
                  found = true;
              }
          }
	usersFile.close();
	if(found) {
            cout << "\n\n<<<<<<<<<<<<<<<<<<< ZAKUPKI.PL >>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n\nWitaj "<< iUsername <<"!"<<'\n';
	}
	else {
		cout << "\nBledny login lub haslo! Sprobuj ponownie!\n\n\n\n";
		login();
	}

            }

			usersFile.close();
        }

        else
            cout << "Unable to open dane.txt file." << endl;
    }

};
char wybor,cos;

// Główny program
int main() {






    User user1;
    ifstream usersFile("dane.txt");
    long begin, end;

    if (usersFile.good())
    {
        cout << "Masz juz konto! Zaloguj sie!\n\n";
    }

    else {
        user1.userRegister();
        cout << "\n\nUdalo Ci sie zalozyc konto! Zaloguj sie teraz!\n\n";
        user1.login();
        cout << "-------------------------------------------------" << endl<<endl;
    cout << "1. Przegladaj oferty" << endl;
    cout << "2. Dodaj oferte" << endl;
    cout << "3. Wyjdz" << endl;




    cin >> cos;
switch(cos)
    {
    case '1':{
  ifstream file("sell.txt");
  string linia;
  cout << "\n\n<<<<<<<<<<<<<<<<<<< OFERTY: >>>>>>>>>>>>>>>>>>>\n\n" << endl;
  while (getline(file, linia)) {

    cout << linia <<"pln" <<"\n\n";
  }
}
    break;

    case '2':
    {
        string item;
        int cena;
        cout << "Co sprzedajesz: "<<"  ";         cin>>item;
        cout << "Podaj cene: "<<"  ";    cin>>cena;


    fstream plik;
    plik.open("sell.txt",ios::out | ios::app);

    plik<<item<<"   "
    <<cena<<endl;



    plik.close();


    }



    break;

    case '3':
            exit(0);
    break;






}

    }

    if(usersFile.is_open())
    {
        begin = usersFile.tellg();
        usersFile.seekg (0, ios::end);

        end = usersFile.tellg();
        usersFile.close();

        if(begin == end)
        {
            user1.userRegister();

        }

        else
            {
                user1.login();


    cout << "-------------------------------------------------" << endl<<endl;
    cout << "1. Przegladaj oferty" << endl;
    cout << "2. Dodaj oferte" << endl;
    cout << "3. Wyjdz" << endl;


    cin >> wybor;



    switch(wybor)
    {
    case '1':{
  ifstream file("sell.txt");
  string linia;
  cout << "\n\n<<<<<<<<<<<<<<<<<<< OFERTY: >>>>>>>>>>>>>>>>>>>\n\n" << endl;
  while (getline(file, linia)) {

    cout << linia <<"pln" <<"\n\n";
  }
}
    break;

    case '2':
    {
        string item;
        int cena;
        cout << "Co sprzedajesz: "<<"  ";         cin>>item;
        cout << "Podaj cene: "<<"  ";    cin>>cena;


    fstream plik;
    plik.open("sell.txt",ios::out | ios::app);

    plik<<item<<"   "
    <<cena<<endl;



    plik.close();


    }



    break;

    case '3':
            exit(0);
    break;



default: cout<<"Nie ma takiej opcji w menu!";

    }
            }
    }

    getch();
}

