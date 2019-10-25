#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

bool isPartPalindrome(const string& s, int leftIndex, int rightIndex) {
    while (leftIndex < rightIndex) {
        if (s[leftIndex] != s[rightIndex]) {
            return false;
        }
        leftIndex++;
        rightIndex--;
    }
    return true;
}

bool validPalindrome(string s) {
    int strSize = s.size();
    if (strSize == 0) {
        return true;
    }

    int leftIndex = 0;
    int rightIndex = strSize - 1;
    while (leftIndex < rightIndex) {
        if (s[leftIndex] == s[rightIndex]) {
            leftIndex++;
            rightIndex--;
        } else if (isPartPalindrome(s, leftIndex + 1, rightIndex) ||
                   isPartPalindrome(s, leftIndex, rightIndex - 1))
            return true;
        else {
            return false;
        }
    }
    return true;
}

int main() {
    assert(validPalindrome("aba") == true);
    assert(validPalindrome("abca") == true);
    assert(validPalindrome("abcdecba") == true);
    assert(validPalindrome("eeee") == true);
    return 0;
}
