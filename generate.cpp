
#include <ctime>
#include <random>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

default_random_engine rng;

uint64_t my_random(uint64_t max) {
    uniform_int_distribution<unsigned long long> dist_ab(0, max);
    return dist_ab(rng);
}

int main(int argc, char** argv) {
    if (argc < 4) {
        return 1;
    }
    long long count = stoll(argv[1]);
    long long min_key = stoll(argv[2]);
    long long max_key = stoll(argv[3]);
    if (count != 0) {
        cout << setw(6) << setfill('0') << min_key << "\t" << my_random(numeric_limits<uint64_t>::max()) << "\n";
        count--;
    }
    if (count != 0) {
        cout << setw(6) << setfill('0') << max_key << "\t" << my_random(numeric_limits<uint64_t>::max()) << "\n";
        count--;
    }
    for (int i = 0; i < count; ++i) {
        cout << setw(6) << setfill('0') << my_random(max_key - min_key) + min_key << "\t" << my_random(numeric_limits<uint64_t>::max()) << "\n";
    }
}