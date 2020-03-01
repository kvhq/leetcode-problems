// string

string defangIPaddr(string address) {
    string answer;
    for (const auto& x : address) {
        if (x != '.') {
            answer += x;
        } else {
            answer += "[.]";
        }
    }
    return answer;
}
