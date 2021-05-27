// Number: 1396
// Name: Design Underground System
// Tags: design

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        d_usersStart[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string startName = d_usersStart[id].first;
        int startTime = d_usersStart[id].second;
        string path = createPath(startName, stationName);
        if (d_timeData.find(path) != d_timeData.end()) {
            d_timeData[path].first += t - startTime;
            d_timeData[path].second++;
        } else d_timeData[path] = make_pair(t - startTime, 1);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path = createPath(startStation, endStation);
        auto pathTime = d_timeData[path];
        return pathTime.first / pathTime.second;
    }
private:
    string createPath(const string& start, const string& end) {
        return start + " " + end;
    }
    
    unordered_map<int, pair<string, int>> d_usersStart;
    unordered_map<string, pair<double, double>> d_timeData;
};

