#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

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
    int year;
    inputStream >> year;

    for (year++;;year++) {
        int y = year;
        set<int> nums;
        int yearSize = 0;
        while (y > 0) {
            nums.insert(y % 10);
            y /= 10;
            yearSize++;
        }
        if (nums.size() == yearSize) {
            break;
        }
    }
    cout << year << endl;
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

