void parseEmail(string& email) {
    bool flag = false;
    bool plusFlag = false;
    string localname;
    string domain;
    for (auto& c : email) {
        if (c == '@') {
            flag = true;
        }
        else if (c == '.') {
            if (flag) {
                domain += c;
            }
        }
        else if (c == '+') {
            if (flag) {
                domain += c;
            }
            else {
                plusFlag = true;
            }
        }
        else if (flag) {
            domain += c;
        }
        else if (!plusFlag) {
            localname += c;
        }
    }
    localname += '@';
    localname += domain;
    email = localname;
}

int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> simplifiedEmails;
    for (auto& x : emails) {
        parseEmail(x);
        simplifiedEmails.insert(x);
    }
    return simplifiedEmails.size();
}