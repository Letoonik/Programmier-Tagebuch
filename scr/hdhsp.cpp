/* Letoonik © 2022
    Simpler Programmier-Tagestracker
    "Hast du heute schon programmiert?" */

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "func.hpp"

using namespace std;

string answer;
string progLang;
string comment;
int valMenu;

std::time_t t = std::time(0); 
std::tm* now = std::localtime(&t); 

int main(){

valMenu = menu();
system("cls");

std::ofstream outfile;
outfile.open("hdhsp.txt", std::ios_base::app);

if (valMenu == 1) {

    cout << "Hast du heute schon programmiert?(y/n):";
    cin >> answer;
    if(answer == "y") {
        cout << "In welcher Programiersprache hast du programmiert?: ";
        cin >> progLang;
        cout << "Kommentar fur den heutigen Tag: ";
        cin.ignore();
        getline(cin >> ws, comment);
        outfile << now->tm_mday  << '.' << now->tm_mon + 1 << '.' << now->tm_year + 1900 << ": Programmiert mit " << progLang << "." << " " << "//" << comment << "\n\n";
        cout << "Gut gemacht ^_^\n";
        system("pause");
        system("cls");
        system("hdhsp.exe");
    }
    else if (answer == "n") {
        cout << "Nicht so gut, mach weiter >:( \n";
        outfile << now->tm_mday  << '.' << now->tm_mon + 1 << '.' << now->tm_year + 1900 << ": NICHT programmiert.\n\n";
        system("pause");
        system("cls");
        system("hdhsp.exe");
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
        system("cls");
        system("hdhsp.exe");
    }
}
else if(valMenu == 3) {
    displayDiary();
    system("pause");
    system("cls");
    system("hdhsp.exe");
}
else if(valMenu == 4) {
    return 0;
}
}
