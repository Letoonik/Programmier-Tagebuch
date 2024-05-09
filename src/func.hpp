/* Letoonik © 2022
    Simpler Programmier-Tagestracker
    "Hast du heute schon programmiert?" */

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <conio.h>

using namespace std;

int menu(){
    int mode;
    cout << "Programmier-Tagebuch\n";
    cout << "----------------------------------\n";
    cout << "1. Neuer Eintrag verfassen\n";
    cout << "2. Letzer Eintrag loeschen\n";
    cout << "3. Tagebuch ansehen\n";
    cout << "4. Programm schliessen\n";
    cout << "----------------------------------\n";
    cout << "Auswahl: ";
    cin >> mode;
    return mode;
}

void deleteLastDiaryEntry() {

string line; 
vector<string> lines;
std::ifstream inputStream("hdhsp.txt");

while (getline(inputStream,line)) {
    lines.push_back(line);
}
inputStream.close();

std::fstream outputStream("hdhsp.txt", ios::out | ios::trunc);
if (outputStream.is_open())
{
    for (int i=0; i < lines.size()-2; i++)
    {
        outputStream << lines[i] << "\n";
    }
    outputStream.close();
}

}
void displayDiary()
{
    std::ifstream outputStream("hdhsp.txt");

    if (outputStream.is_open())
        std::cout << outputStream.rdbuf();
    system("pause");
    menu();
}
