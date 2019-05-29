#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void countJewels(const string& J, const string& S) {
    map<char, int> stones;
    int answer = 0;
    for (auto x : S) {
        stones[x]++;
    }
    for (auto x : J) {
        if (stones.count(x) != 0) {
            answer += stones[x];
        }
    }
    cout << answer << endl;
}

int main() {
    string J, S;
    cout << "Please, enter J: ";
    cin >> J;
    cout << "Please, enter S: ";
    cin >> S;
    countJewels(J, S);
    return 0;
}