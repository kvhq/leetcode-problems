bool judgeCircle(string moves) {
    pair<int, int> coordinates;
    coordinates.first = 0;
    coordinates.second = 0;
    for (const auto& x : moves) {
        if (x == 'U')
            coordinates.second++;
        else if (x == 'D')
            coordinates.second--;
        else if (x == 'L')
            coordinates.first--;
        else if (x == 'R')
            coordinates.first++;
    }
    if (coordinates.first == 0 && coordinates.second == 0) {
        return true;
    }
    else {
        return false;
    }
}