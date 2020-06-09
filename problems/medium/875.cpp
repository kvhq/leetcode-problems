// Number: 875
// Name: Koko Eating Bananas
// Tags: Binary search

int minEatingSpeed(vector<int>& piles, int H) {
    int pilesMax = 1000000000;
    int minSpeed = 1;
    while (minSpeed < pilesMax) {
        int mid = minSpeed + (pilesMax - minSpeed) / 2;
        if (!checkPossible(piles, H, mid))
            minSpeed = mid + 1;
        else pilesMax = mid;
    }
    return minSpeed;
}

bool checkPossible(vector<int>& piles, int H, int K) {
    int time = 0;
    for (const auto& p : piles) {
        time += p / K;
        if (p % K != 0) time += 1;
    }
    return time <= H;
}

