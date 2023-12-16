#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

using std::vector;
using std::unordered_map;
using std::cout;

class RandomizedSet {
  private:
    vector<int> arr;
    unordered_map<int, int> valToIndex; // хэш-таблица для быстрого доступа к индексу элемента по его значению
  public:
    RandomizedSet() = default;

    bool insert(int val) {
        if (valToIndex.count(val)) { // проверяем, есть ли уже такой элемент в хэш-таблице
            return false;
        }
        arr.push_back(val);
        valToIndex[val] = arr.size() - 1; // добавляем значение и его индекс в хэш-таблицу
        return true;
    }

    bool remove(int val) {
        if (!valToIndex.count(val)) { // проверяем, есть ли такой элемент в хэш-таблице
            return false;
        }
        int index = valToIndex[val];
        valToIndex[arr.back()] = index; // обновляем индекс последнего элемента
        std::swap(arr[index], arr.back()); // переставляем удаляемый элемент в конец вектора
        arr.pop_back(); // удаляем последний элемент
        valToIndex.erase(val); // удаляем элемент из хэш-таблицы
        return true;
    }

    int getRandom() {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(0, arr.size() - 1);
        auto random_int = uni(rng);
        return arr[random_int];
    }
};
