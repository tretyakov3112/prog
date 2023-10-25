#include<iostream>

template <typename T>
class Array
{
public: 
    // Список операций:
    //
    Array() = default;

    explicit Array(size_t size, const T& value)
    {
        T* arr = new T[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = value;
        }
        m_size = size;
        m_data = arr;
    }
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    //
    Array(const Array & other)
    {
        if (&other != this)
        {
            m_size = other.m_size;
            T* data = new T[other.m_size];
            for (size_t i = 0; i < m_size; ++i) {
                data[i] = other.m_data[i];
            }
            m_data = data;
        }
    }
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    //
    Array(const Array && other)
    {
        std::swap(m_size, other.m_size);
        std::swap(m_data, other.m_data);
    }
    //   конструктор перемещения
    //
    ~Array()
    {
        // if (m_data != nullptr) delete[] m_data;
    }
    //   деструктор, если он вам необходим.
    //
    Array& operator=(const Array & other)
    {
        Array tmp(other);
        std::swap(tmp.m_size, m_size);
        std::swap(tmp.m_data, m_data);
        return *this;
    }
    //   оператор копирующего присваивания.
    //
    Array& operator=(Array && other)
    {
         if (&other != this)     // избегаем самоприсваивания
        {
            delete[] m_data;        // освобождаем память текущего объекта
            m_size = other.m_size;  
            m_data = other.m_data;  // копируем указатель из перемещаемого объекта в текущий
            other.m_data = nullptr; // сбрасываем значение указателя в перемещаемом объекте
            other.m_size = 0;
        }
        return *this; // возвращаем текущий объект
    }
    //   оператор перемещающего присваивания.
    //
    size_t size() const { return m_size; }
    //   возвращает размер массива (количество
    //                              элементов).
    //
    T& operator[](size_t idx)
    {
        return *(m_data + idx);
    }
    const T& operator[](size_t idx) const { return *(m_data + idx); }
    //   две версии оператора доступа по индексу.

    void print_arr() {
        for (size_t i = 0 ;i < m_size; ++i) {
        std::cout << m_data[i]<< ' ';
        }
        std::cout << '\n';
    }
private:
    unsigned m_size;
    T* m_data;
};


int main() {
Array<char> arr(5, 'a');
arr.print_arr();
Array<char> arr_1(arr);
arr_1.print_arr();
Array<char> arr_2;
arr_2 = arr_1;
arr_2.print_arr();
}