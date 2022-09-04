/* Letoonik © 2022
    Simpler Programmier-Tagestracker
    "Hast du heute schon programmiert?" */

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "func.hpp"

using namespace std;

int main(){
    string answer;
    string progLang;
    int valMenu;
    string comment;

    std::ofstream outfile;
    outfile.open("hdhsp.txt", std::ios_base::app); //öffnet "hdhsp.txt",falls nicht vorhanden, wird die Datei erstellt
    
    std::time_t t = std::time(0); // Fragt jetzige Unix-Zeit ab
    std::tm* now = std::localtime(&t); //Konvertiert Zeit
do {
valMenu = menu();
if (valMenu == 1) {
    system("cls");
    cout << "Hast du heute schon programmiert?(y/n):";
    cin >> answer;

if(answer == "y") {
        cout << "In welcher Programiersprache hast du programmiert?: ";
        cin >> progLang;
        cout << "Kommentar fur den heutigen Tag: ";
        cin.ignore();
        getline(cin >> ws, comment);
        outfile << now->tm_mday  << '.' << now->tm_mon + 1 << '.' << now->tm_year + 1900 << ": Programmiert mit " << progLang << "." << " " << "//" << comment << "\n\n"; //Speichert Zeit und Programiertag + Programmiersprache + Kommentar ab 
        cout << "Gut gemacht ^_^\n";
        system("pause");
        system("cls");
    }

    else if (answer == "n") {
        cout << "Nicht so gut, mach weiter >:( \n";
        outfile << now->tm_mday  << '.' << now->tm_mon + 1 << '.' << now->tm_year + 1900 << ": NICHT programmiert.\n\n"; //dat gleiche wie oben, nur das man eben nicht programmiert hat
        system("pause");
        system("cls");
    } 
    }

    else if(valMenu == 2) {
        system("cls");
        string sure;
        cout << "Bist du dir sicher, dass du den letzten Eintrag loeschen willst?(y/n):";
        cin >> sure;
        if(sure == "y") {
        deleteLastDiaryEntry();
        system("cls");
        cout << "Letzter Eintrag wurde geloescht!\n";
        system("pause");
        system("cls");
        }
    }
    else if(valMenu == 3) {
        system("cls");
        displayDiary();
        system("pause");
        system("cls");
    }

    
    else if(valMenu == 4) {
        break;
    }
    else {
        system("cls");
        cout << "Falsche Eingabe!\n";
        system("cls");
    }
}
while(true);
}