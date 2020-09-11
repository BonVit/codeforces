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
    int k, l, m, n, d;
    inputStream >> k >> l >> m >> n >> d;

    int notDamaged = 0;
    for (int i(1); i <= d; i++) {
        if (i % k != 0 &&
            i % l != 0 &&
            i % m != 0 &&
            i % n != 0) {
                notDamaged++; 
            }
    }
    cout << d - notDamaged << endl;

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

