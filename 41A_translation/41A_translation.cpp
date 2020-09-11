#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool DEBUG = false;

ifstream fileStream;

istream &getInputStream()
{
    if (DEBUG) {
        string path = __FILE__;                             
        path = path.substr(0, 1 + path.find_last_of('/'));
        path += "input.txt";
        fileStream.open(path);
        return fileStream;
    }
    return cin;
}

void solve()
{
    istream &inputStream = getInputStream();

    // Your code goes here
    string berlandish, birlandish;
    inputStream >> berlandish >> birlandish;
    if (berlandish.size() != birlandish.size()) {
        cout << "NO" << endl;
        return;
    }

    int size = berlandish.size();
    for (int i(0); i < size; i++) {
        if (berlandish[i] != birlandish[size - i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(int argc, char *argv[])
{
    if (argc >= 2) {
        string debug(argv[1]);
        if (debug == "debug") {
            DEBUG = true;
        }
    }
    solve();
    return 0;
}

