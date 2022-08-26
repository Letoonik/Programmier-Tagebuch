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

    std::ofstream outfile;
    outfile.open("hdhsp.txt", std::ios_base::app); //öffnet "hdhsp.txt",falls nicht vorhanden, wird die Datei erstellt
    
    std::time_t t = std::time(0); // Fragt jetzige Unix-Zeit ab
    std::tm* now = std::localtime(&t); //Konvertiert Zeit


valMenu = menu();
system("cls");
if (valMenu == 1) {
    
    cout << "Hast du heute schon programmiert?(y/n):";
    cin >> answer;

if(answer == "y") {
        cout << "In welcher Programiersprache hast du programmiert?: ";
        cin >> progLang;
        outfile << now->tm_mday  << '.' << now->tm_mon + 1 << '.' << now->tm_year + 1900 << ": Programmiert mit " << progLang <<".\n\n"; //Speichert Zeit und Programiertag + Programmiersprache ab 
        cout << "Gut gemacht ^_^\n";
        system("pause");
    }

    else if (answer == "n") {
        cout << "Nicht so gut, mach weiter >:( \n";
        outfile << now->tm_mday  << '.' << now->tm_mon + 1 << '.' << now->tm_year + 1900 << ": NICHT programmiert.\n\n"; //dat gleiche wie oben, nur das man eben nicht programmiert hat
        system("pause");
    } 
    }

    else if(valMenu == 2) {
        string sure;
        cout << "Bist du dir sicher, dass du den letzten Eintrag loeschen willst?(y/n):";
        cin >> sure;
        if(sure == "y") {
        deleteLastDiaryEntry();
        system("cls");
        cout << "Letzter Eintrag wurde geloescht!\n";
        system("pause");
        }
    }
}