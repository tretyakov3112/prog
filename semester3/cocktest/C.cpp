#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    unordered_map<string, int> freq; // хэш-таблица для подсчета частоты встречаемости подстрок
    for (size_t i = 0; i + 10 <= s.size(); ++i) {
        string substr = s.substr(i, 10);
        if (++freq[substr] == 2) { // если подстрока уже встречалась, добавляем ее в ответ
            ans.push_back(substr);
        }
    }
    return ans;
}
