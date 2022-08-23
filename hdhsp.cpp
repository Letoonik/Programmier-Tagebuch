/* Letoonik © 2022
    Simpler Programmier-Tagestracker
    "Hast du heute schon programmiert?" */

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main(){
  
    string answer;
    std::ofstream outfile;
    outfile.open("hdhsp.txt", std::ios_base::app); //Öffnet "hdhsp.txt",falls nicht vorhanden, wird die Datei erstellt
    
    std::time_t t = std::time(0); //Fragt jetzige Unix-Zeit ab
    std::tm* now = std::localtime(&t); //Konvertiert Zeit
    
    cout << "Hast du heute schon programmiert?(y/n):";
    cin >> answer;

    if(answer == "y") {
        outfile << now->tm_mday  << '.' << now->tm_mon + 1 << '.' << now->tm_year + 1900 << ": Programmiert\n\n"; //Speichert Zeit und Programiertag ab 
        cout << "Gut gemacht ^_^\n";
        system("pause");
    }

    else if (answer == "n") {
        cout << "Nicht so gut, mach weiter >:( \n";
        outfile << now->tm_mday  << '.' << now->tm_mon + 1 << '.' << now->tm_year + 1900 << ": NICHT Programmiert\n\n"; //Dat gleiche wie oben, nur das man eben nicht programmiert hat
        system("pause");
    } 
}
