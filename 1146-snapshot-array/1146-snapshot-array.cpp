class SnapshotArray {
public:
    vector<vector<pair<int, int>>> snaparr;
    int snap_id = 0;

    SnapshotArray(int length) {
        snaparr.resize(length);
    }

    void set(int index, int val) {
        snaparr[index].emplace_back(snap_id, val);
    }

    int snap() {
        snap_id++;
        return snap_id - 1;
    }

    int get(int index, int snap_id) {
        if (index >= 0 && index < snaparr.size()) {
            auto it = upper_bound(snaparr[index].begin(), snaparr[index].end(), make_pair(snap_id, INT_MAX));
            if (it != snaparr[index].begin())
                return prev(it)->second;
        }
        return 0;
    }
};
