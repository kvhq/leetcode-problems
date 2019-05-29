#include <string>

string toLowerCase(string str) {
    string myStr = str;
    for (auto i = 0; i < myStr.length(); ++i) {
        if (myStr[i] >= 'A' && myStr[i] <= 'Z') {
            myStr[i] += 32;
        }
    }
    return myStr;
}