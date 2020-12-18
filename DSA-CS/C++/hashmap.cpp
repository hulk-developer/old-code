#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class HashTable {
public:
    vector<vector<pair<string, string>>> keyMap;
    int size = 0;

    HashTable(int s = 53) {
        vector<vector<pair<string, string>>> arr(s);
        keyMap = arr;
        size = s;
    }

    int _hash(string key) {
        const int UNIFORM_PRIME = 103;
        int total = 0;
        for (int i = 0; i < fmin(100, key.length()); i++) {
            int value = key[i];
            value -= 96;
            total = (total * UNIFORM_PRIME + value) % size;
        }
        return total;
    }

    void set(string key, string value) {
        int idx = _hash(key);
        auto p = make_pair(key, value);
        keyMap[idx].push_back(p);
    }

    string get(string key) {
        int idx = _hash(key);
        if (keyMap[idx].empty()) {
            return "No value found for the given key";
        }
        for (auto p: keyMap[idx]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return "No value found for the given key";
    }

};


int main() {
    HashTable ht(17);
    ht.set("shreyash", "sneha");
    ht.set("aayush", "ginni");
    cout << "Shreyash's girlfriend is " << ht.get("shreyash") << endl;
    cout << "Aayush's girlfriend is " << ht.get("aayush") << endl;
    return 0;
}