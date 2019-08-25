#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_map>

using namespace std;

void split(const std::string& s, std::vector<std::string>& sv, const char delim) {
    sv.clear();
    std::istringstream iss(s);
    std::string temp;

    while (std::getline(iss, temp, delim)) {
        sv.push_back(temp);
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> strVec;
    string str;
    for (int i=0; i<n; ++i) {
        getline(cin, str);
        strVec.push_back(str);
    }
    vector<string> idVec;
    while (true) {
        int a, b;
        getline(cin, str);
        if (str.empty()) {
            break;
        }
        split(str, idVec, ' ');
        if (idVec.size()!=2) {
            continue;
        }
        a = stoi(idVec[0]);
        b = stoi(idVec[1]);
        a -= 1; b -= 1;
        if (a<0 || a>=n || b<0 || b>=n) {
            continue;
        }
        int i=0;
        for ( ; i<(int)(strVec[a].size()) && i<(int)(strVec[b].size()); ++i) {
            if (strVec[a][i] != strVec[b][i]) {
                break;
            }
        }
        printf("%d\n", i);
    }

    return 0;
}
