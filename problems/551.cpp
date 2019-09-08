bool checkRecord(string s) {
    int absentCounter = 0;
    int lateCounter = 0;
    for (const auto& x : s) {
        if (x == 'A') {
            absentCounter++;
            lateCounter = 0;
        }
        if (x == 'L') {
            lateCounter++;
        }
        if (x == 'P') {
            lateCounter = 0;
        }
        if (absentCounter > 1 || lateCounter > 2) {
            return false;
        }
    }
    return true;
}
