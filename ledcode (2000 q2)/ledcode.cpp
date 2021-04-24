#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

map <int, char> my_map = {
    {123457, 'A'},
    {1234567, 'B'},
    {456, 'C'},
    {1580, 'D'},
    {12456, 'E'},
    {1249, 'F'},
    {12569, 'G'},
    {13457, 'H'},
    {37, 'I'},
    {3567, 'J'},
    {13459, 'K'},
    {156, 'L'},
    {12357, 'M'},
    {3579, 'N'},
    {123567, 'O'},
    {1458, 'P'},
    {12347, 'Q'},
    {123459, 'R'},
    {12467, 'S'},
    {278, 'T'},
    {13567, 'U'},
    {1379, 'V'},
    {135790, 'W'},
    {90, 'X'},
    {1347, 'Y'},
    {23456, 'Z'},
    {0, ' '},
};

int main() {
    ifstream inFile;
    ofstream outFile;
    string input, line;
    vector<string> lines_in, lines_out;
    map <int, char>::iterator itmap;
    int number_lines, number;

    inFile.open("ledcode.in");
    getline(inFile, line);
    number_lines = stoi(line);

    for (int i = 0; i < number_lines; i++) {
        getline(inFile, line);
        lines_in.push_back(line);
    }
    inFile.close();

    for (int i = 0; i < number_lines; i++) {
        string stringFinal, stringInicial = lines_in[i], number_digits;

        for (int j = 0; j < stringInicial.length(); j++) {
            char character = stringInicial[j];

            if ((character >= 65 && character <= 90) || character == 32) {
                stringFinal.push_back(character);
            }
            else {
                number_digits += character;
                number = stoi(number_digits);

                // Procura o número para ver se é algum LED
                itmap = my_map.find(number);
                if(itmap != my_map.end()) {
                    // Se for, adiciona a string final
                    stringFinal.push_back(itmap->second);
                    number_digits.clear();
                }
            }
        }

        lines_out.push_back(stringFinal);
    }

    
    outFile.open("ledcode.out");
    for (int i = 0; i < number_lines; i++) {
        outFile << "Phrase " << i + 1 << ": " << lines_out[i];

        if (i != number_lines - 1) {
            outFile << endl;
        }
    }
    outFile.close();
}