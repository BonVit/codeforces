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
    string s;
    inputStream >> s;

    int upperCaseCount = 0, lowerCaseCount = 0;
    for (int i(0); i < s.size(); i++) {
        if (islower(s[i])) {
            lowerCaseCount++;
        } else {
            upperCaseCount++;
        }
    }
    if (upperCaseCount > lowerCaseCount) {
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    } else {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    cout << s << endl;
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

