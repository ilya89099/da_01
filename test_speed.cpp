#include <ctime>
#include <random>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <chrono>
using namespace std;

default_random_engine rng;

uint64_t my_random(uint64_t max) {
    uniform_int_distribution<unsigned long long> dist_ab(0, max);
    return dist_ab(rng);
}

int main() {
    vector<int> test_vector;
    list<int> test_list;
    for (int i = 0; i < 50000000; ++i) {
        int a = my_random(10000000);
        test_vector.push_back(a);
        test_list.push_back(a);
    }
    using std::chrono::steady_clock;
    steady_clock::time_point start = steady_clock::now();
    uint64_t sum = 0;
    for (int a : test_vector) {
        sum += a;
    }
    steady_clock::duration dur =  steady_clock::now() - start;
    std::cerr << "vector: " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << "ms\n";

    using std::chrono::steady_clock;
    start = steady_clock::now();
    uint64_t sum2 = 0;
    for (int a : test_list) {
        sum2 += a;
    }
    dur =  steady_clock::now() - start;
    std::cerr << "list: " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << "ms\n";
}