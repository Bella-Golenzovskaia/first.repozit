#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;


int main()
{
    ifstream file("str.txt");

    struct ElectricKettle {
        char brand[50];       // Фирма-производитель
        int power;           // Мощность (в ваттах)
        float volume;        // Объем (в литрах)
    };

    vector<ElectricKettle> myKettle;
    ElectricKettle kettles;

    if(!file.is_open())
    {
        cout << "no open" << endl;
        return 1;
    }

    while(!file.eof())
    {
        file >> kettles.brand >> kettles.power >> kettles.volume;
        myKettle.push_back(kettles);
    }
    file.close();
    myKettle.pop_back();

     string help_string(38, '_');
    //3 пункт
    cout << "|" << help_string << "|" << endl;
    cout << "|" << setw(12) << "Name"
         << "|" << setw(12) << "Power"
         << "|" << setw(12) << "Volume"
         << "|" << endl;
    cout << "|" << help_string << "|" << endl;
    for (auto kettle : myKettle) {
        cout << "|" << setw(12) << kettle.brand
             << "|" << setw(12) << kettle.power
             << "|" << setw(12) << kettle.volume
             << "|" << endl;
    }
    cout << "|" << help_string << "|" << endl;

    //4 пункт
    stringstream ss;
    for (const auto& kettle : myKettle) {
        ss << "Brand: " << kettle.brand << endl;
        ss << "Power: " << kettle.power << endl;
        ss << "Volume: " << kettle.volume << endl;
        ss << "\n" << endl;
    }

    //вывод строки ss для проверки
    string s2 = ss.str();
    cout << "\n" << s2 << endl;

    //5 пункт
    ofstream outputFile("kettle_output.txt", ios::binary);
    string str = ss.str();
    outputFile.write(str.c_str(), str.length());
    outputFile.close();

    return 0;
}
