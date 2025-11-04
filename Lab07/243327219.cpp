#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    int m;
    vector<vector<int>> table;

    int hashFunction(int key) {
        return key % m;
    }

public:
    HashTable(int size) {
    m = size;
    table.resize(size);
}

    void insertKey(int key) {
        int bucket = hashFunction(key);
        table[bucket].insert(table[bucket].begin(), key);
    }

    void searchKey(int key) {
        int bucket = hashFunction(key);
        for (int i = 0; i < table[bucket].size(); i++) {
            if (table[bucket][i] == key) {
                cout << key << ":FOUND_AT" << bucket << "," << i << ";" << endl;
                return;
            }
        }
        cout << key << ":NOT_FOUND;" << endl;
    }

    void deleteKey(int key) {
        int bucket = hashFunction(key);
        for (int i = 0; i < table[bucket].size(); i++) {
            if (table[bucket][i] == key) {
                table[bucket].erase(table[bucket].begin() + i);
                cout << key << ":DELETED;" << endl;
                return;
            }
        }
        cout << key << ":DELETE_FAILED;" << endl;
    }

    void outputTable() {
        for (int i = 0; i < m; i++) {
            cout << i << ":";
            for (int j = 0; j < table[i].size(); j++) {
                cout << table[i][j] << "->";
            }
            cout << ";" << endl;
        }
    }
};

int main() {
    int m;
    cin >> m;
    HashTable ht(m);

    char input;
    while (cin >> input) {
        if (input == 'i') {
            int key; cin >> key;
            ht.insertKey(key);
        } else if (input == 's') {
            int key; cin >> key;
            ht.searchKey(key);
        } else if (input == 'd') {
            int key; cin >> key;
            ht.deleteKey(key);
        } else if (input == 'o') {
            ht.outputTable();
        } else if (input == 'e') {
            break;
        }
    }
    return 0;
}
