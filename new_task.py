#!/usr/bin/python

import os
import sys

template = """#include <iostream>
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
"""

def createNewTask(name):
    os.mkdir(name)
    open(f"{name}/input.txt", "w+").close()
    with open(f"{name}/{name}.cpp", 'w+') as f:
        print(template, file=f)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        raise SystemExit("Name is not specified")
    name = sys.argv[1]
    createNewTask(name)
