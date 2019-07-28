#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

void split(const std::string& s, std::vector<std::string>& sv, const char delim = ' ') {
    sv.clear();
    std::istringstream iss(s);
    std::string temp;

    while (std::getline(iss, temp, delim)) {
        sv.push_back(temp);
    }
}

void split01(const string& s, vector<string>& ret, const string delim)
{
    ret.clear();
    //记录每次分割的起始位置
    size_t last = 0;
    //记录匹配delim这个字符的下标
    size_t index=s.find_first_of(delim,last);
    //当=-1时表示查找不到
    while (index!=-1)
    {
        ret.push_back(s.substr(last,index-last));
        //记录下一次分割的起始位置
        last=index+1;
        index=s.find_first_of(delim,last);
    }
    //若最后一个分割符后面还有元素
    if (s.length()-last>0)
    {
        ret.push_back(s.substr(last));
    }
}

int main(){
//    int N;
//    cin>>N;
//    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string str;
    getline(cin, str);
    printf("%s\n", str.c_str());
    printf("======\n");

    vector<string> sv;
    split(str, sv, ' ');

    for (string s:sv) {
        printf("%s, ", s.c_str());
    }

    printf("\n======\n");

    split01(str, sv, " ");

    for (string s:sv) {
        printf("%s, ", s.c_str());
    }
    
    return 0;
}
