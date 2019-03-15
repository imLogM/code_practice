#include <iostream>
#include <vector>

void combination(char str[], int beginIndex) {
    if (str == nullptr) {return;}
    static std::vector<char> result;

    if (str[beginIndex] == '\0') {
        for (int i=0; i<result.size(); ++i) {
            printf("%c", result[i]);
        }
        printf("\n");
        return;
    }

    result.push_back(str[beginIndex]);
    combination(str, beginIndex+1);
    result.pop_back();
    combination(str, beginIndex+1);
}

int main(int argc, char** argv) {
    char str[] = "abc";
    combination(str, 0);
    return 0;
}