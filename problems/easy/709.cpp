// string

string toLowerCase(string str) {
    for (auto& x : str) {
        if (x >= 'A' && x <= 'Z') x += 32;
    }
    return str;
}
