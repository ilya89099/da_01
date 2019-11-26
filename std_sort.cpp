#include <iostream>
#include <iomanip>
#include <algorithm>
#include <chrono>

template <typename T>
class TVector {
public:
    TVector() = default;

    TVector(size_t newSize)
            : data(new T[newSize]), size(newSize), capacity(newSize) {}

    TVector(size_t newSize, T defaultVal)
            : data(new T[newSize]), size(newSize), capacity(newSize) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = defaultVal;
        }
    }

    TVector(const TVector& other)
            : data(new T[other.size]), size(other.size), capacity(other.size){
        std::copy(other.begin(), other.end(), data);
    }

    TVector(TVector&& other)
            : data(other.data), size(other.size), capacity(other.capacity){
        other.data = nullptr;
    }

    ~TVector() {
        delete[] data;
    }

    T& operator[] (size_t index) {
        return data[index];
    }

    const T& operator[] (size_t index) const {
        return data[index];
    }

    void PushBack(const T& elem) {
        if (size == capacity) {
            size_t newCap = capacity == 0 ? 1 : capacity * 2;
            T* temp = new T[newCap];
            std::copy(begin(), end(), temp);
            delete[] data;
            data = temp;
            capacity = newCap;
        }
        data[size] = elem;
        size++;
    }

    //begin и end будут с маленькой буквы, потому что иначе не будет работать range-based for
    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }

    const T* begin() const {
        return data;
    }

    const T* end() const {
        return data + size;
    }

    TVector& operator=(const TVector& other) {
        if (&other == this) {
            return *this;
        }
        if (other.size <= capacity) {
            std::copy(other.begin(), other.end(), begin());
            size = other.size_;
        } else {
            TVector<T> tmp(other);
            std::swap(tmp.data, data);
            std::swap(tmp.size, size);
            std::swap(tmp.capacity, capacity);
        }
        return *this;
    }

    TVector& operator = (TVector&& other) {
        if (&other == this) {
            return *this;
        }
        delete[] data;
        data = other.data;
        other.data = nullptr;
        size = other.size;
        other.size = 0;
        capacity = other.capacity;
        other.capacity = 0;
        return *this;
    }

    void ShrinkToFit() {
        if (size < capacity) {
            capacity = size;
            T* temp = new T[size];
            std::copy(begin(), end(), temp);
            delete[] data;
            data = temp;
        }
    }

    size_t Size() const {
        return size;
    }

private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};

struct TSortType {
    int key;// почтовый индекс
    uint64_t value;
};

bool operator < (TSortType lhs, TSortType rhs) {
    return lhs.key < rhs.key;
}


std::istream& operator >> (std::istream& is, TSortType& elem) {
    return is >> elem.key >> elem.value;
}

std::ostream& operator << (std::ostream& is, TSortType& elem) {
    return is << std::setw(6) << std::setfill('0') << elem.key << '\t' << elem.value;
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    TVector<TSortType> inputVector;
    TSortType temp;
    int maxKey = -1;
    int minKey = 1000000;
    while(std::cin >> temp) {
        inputVector.PushBack(temp);
        if (temp.key > maxKey) {
            maxKey = temp.key;
        }
        if (temp.key < minKey) {
            minKey = temp.key;
        }
    }

    inputVector.ShrinkToFit();
    using std::chrono::steady_clock;
    steady_clock::time_point start = steady_clock::now();
    std::sort(inputVector.begin(), inputVector.end());
    for (TSortType i : inputVector) {
        std::cout << i << "\n";
    }
    steady_clock::duration dur =  steady_clock::now() - start;
    std::cerr << "Std_sort_time: " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << "ms\n";
    return 0;
}