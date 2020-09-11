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
    int n;
    string s;
    inputStream >> n >> s;
    int antonWon = 0, danikWon = 0;
    for (int i(0); i < n; i++) {
        if (s[i] == 'A') {
            antonWon++;
        } else {
            danikWon++;
        }
    }

    if (antonWon == danikWon) {
        cout << "Friendship" << endl;
        return;
    }

    if (antonWon > danikWon) {
        cout << "Anton" << endl;
        return;
    }

    cout << "Danik" << endl;
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

