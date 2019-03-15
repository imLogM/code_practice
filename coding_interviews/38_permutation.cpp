#include <iostream>

void permutation(char str[], int beginIndex) {
    if (str == nullptr) {return;}
    if (str[beginIndex] == '\0') {
        printf("%s\n", str);
        return;
    }

    for (int i=beginIndex; ; ++i) {
        if (str[i] == '\0') {
            break;
        }

        std::swap(str[beginIndex], str[i]);

        permutation(str, beginIndex+1);

        std::swap(str[beginIndex], str[i]);
    }
}

int main(int argc, char** argv) {
    char str[] = "abc";
    permutation(str, 0);
    return 0;
}