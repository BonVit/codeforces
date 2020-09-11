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
    int n, x, tmp;
    inputStream >> n;
    bool levels[100] = { false };
    inputStream >> x;
    for (int i(0); i < x; i++) {
        inputStream >> tmp;
        levels[tmp - 1] = true;
    }
    inputStream >> x;
    for (int i(0); i < x; i++) {
        inputStream >> tmp;
        levels[tmp - 1] = true;
    }
    for (int i(0); i < n; i++) {
        if (!levels[i]) {
            cout << "Oh, my keyboard!" << endl;
            return;
        }
    }
    cout << "I become the guy." << endl;
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

