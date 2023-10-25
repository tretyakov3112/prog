#include<iostream>

template <typename T>
class Array {
public: 
Array() = default;
explicit Array(size_t size, const T& value): size_(size) {
T* arr = new T[size];
for (size_t i = 0; i < size; ++i) {
arr[i] = value;
}
arr_ = arr;
}

Array(const Array& arr): size_(arr.size()) {
T* new_arr = new T[arr.size()];
for (size_t i = 0; i < size_; ++i) {
new_arr[i] = arr[i];
}
arr_ = new_arr;
}

Array(const Array && new_arr) {
std::swap(arr_, new_arr.arr_);
std::swap(arr_.size_, new_arr.size_);
}

~Array() {
delete [] arr_;
}

Array& operator=(const Array& new_arr) {
arr_ = new_arr.data();
size_ = new_arr.size();
return *this;
}

Array& operator=(Array && new_arr) {
return *this;
}

size_t size() {
return size_;
}

const size_t size() const {
return size_;
}

T* data() const {
return arr_;
}

T& operator[](size_t idx) {
return arr_[idx];
}

const T& operator[](size_t idx) const {
return arr_[idx];
}

void print_arr() {
for (size_t i = 0 ;i < size_; ++i) {
std::cout << arr_[i]<< ' ';
}
std::cout << '\n';
}
private:
size_t size_;
T* arr_;
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
