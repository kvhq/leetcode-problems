string defangIPaddr(string address) {
    string defangedIP = "";
    for (const auto& x : address) {
        if (x != '.') {
            defangedIP.push_back(x);
        }
        else {
            defangedIP.push_back('[');
            defangedIP.push_back('.');
            defangedIP.push_back(']');
        }
    }
    return defangedIP;
}
