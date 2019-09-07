#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

string reverseStr(string s, int k) {
    int stringLength = s.length();
    if (stringLength <= k) {
        for (int i = 0; i <= (stringLength - 1) / 2; i++) {
            swap(s[i], s[stringLength - 1 - i]);
        }
        return s;
    }
    int startPosition = 0;
    int endPosition = k - 1;
    int delta = k / 2;
    while (startPosition < stringLength) {
        if (endPosition > stringLength - 1) {
            delta = (stringLength - startPosition) / 2;
            endPosition = stringLength - 1;
        }
        for (int i = 0; i < delta; i++) {
            swap(s[startPosition + i], s[endPosition - i]);
        }
        startPosition += 2*k;
        endPosition += 2*k;
    }
    return s;
}

int main() {
    string s = "qtjhajghgnbbgtmhxfnoyluejwkpyuamjsxwupdkemwxklxbeouawmdxgksoaewegsmtosgmaqsakngsguscmnmujqdfaixvwbsi";
    reverseStr(s, 44);
    cout << s << endl;
    return 0;
}