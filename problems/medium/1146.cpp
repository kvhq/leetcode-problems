// Number: 1146
// Name: Snapshot Array
// Tags: array

class SnapshotArray {
public:
    SnapshotArray(int length) {
        d_snap_id = 0;
    }
    
    void set(int index, int val) {
        if (d_versions.find(index) != d_versions.end()) {
            d_versions[index][d_snap_id] = val;
        } else {
            map<int, int> index_versions;
            index_versions[d_snap_id] = val;
            d_versions[index] = index_versions;
        }
    }
    
    int snap() {
        return d_snap_id++;
    }
    
    int get(int index, int snap_id) {
        if (d_versions.find(index) == d_versions.end()) return 0;
        if (d_versions[index].find(snap_id) != d_versions[index].end())
            return d_versions[index][snap_id];
        if (d_versions[index].begin()->first > snap_id) return 0;
        auto iter = d_versions[index].lower_bound(snap_id);
        return prev(iter)->second;
    }
private:
    int d_snap_id;
    unordered_map<int, map<int, int>> d_versions;
};

