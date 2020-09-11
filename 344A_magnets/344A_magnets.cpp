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
    inputStream >> n;

    int prev, current, groups = 1;
    inputStream >> prev;
    for (int i(1); i < n; i++) {
        int current;
        inputStream >> current;
        if (prev != current) {
            groups++;
            prev = current;
        }
    }

    cout << groups << endl;;
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

