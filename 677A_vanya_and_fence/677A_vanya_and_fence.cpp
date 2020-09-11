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
    int n, h;
    inputStream >> n >> h;
    int width = 0;
    for (int i(0); i < n; i++) {
        int fr;
        inputStream >> fr;
        if (fr > h) {
            width += 2;
        } else {
            width++;
        }
    }
    cout << width << endl;
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

