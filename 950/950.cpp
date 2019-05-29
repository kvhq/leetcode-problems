vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    deque<int> d;
    for (int i = deck.size() - 1; i >= 0; i--) {
        if (d.empty()) {
            d.push_back(deck[i]);
        }
        else if (d.size() == 1) {
            d.push_front(deck[i]);
        }
        else {
            int temp = d.back();
            d.pop_back();
            d.push_front(temp);
            d.push_front(deck[i]);
        }
    }
    for (int i = 0; i < d.size(); i++) {
        deck[i] = d[i];
    }
    return deck;
}