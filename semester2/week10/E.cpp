#include <iostream>
#include <cstring>

int banan(std::string s1, std::string s2) {
    int len1 = sizeof(s1);
    int len2 = sizeof(s2);
    std::cout << len1;
    return 0;
}

int main() {
    std::string s1;
    std::string s2;
    std::cin >> s1 >> s2;
    banan(s1, s2);
}