#include "iostream"
#include "fstream"
#include "iomanip"

int main()
{
    std::ifstream f("input.txt");
    std::string str;
    while (!f.eof())
    {
        std::getline(f, str);
        for (int i = 0; i < 4; ++i) {
            if (str[i] != '\n') std::cout << str[i];
            else
            {
                std::cout << std::setw(4) << std::setfill('0') << std::endl;
                break;
            }
        }
        std::cout << std::endl;
    }
}