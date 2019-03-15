#include <iostream>

bool isdumplicate(const char str[], int beginIndex, int endIndex) {
    for (int i=beginIndex; i<endIndex; ++i) {
        if (str[i] == str[endIndex]) {
            return true;
        }
    }
    return false;
}

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

        if (!isdumplicate(str, beginIndex, i)) {
            std::swap(str[beginIndex], str[i]);
            permutation(str, beginIndex+1);
            std::swap(str[beginIndex], str[i]);
        }
    }
}

int main(int argc, char** argv) {
    char str[] = "122";
    permutation(str, 0);
    return 0;
}