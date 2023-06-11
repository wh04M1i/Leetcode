class SnapshotArray {
public:
  std::vector<std::map<int, int>> snapshots; // vector of maps to store snapshots
    int currentSnap; // current snapshot id
    

    SnapshotArray(int length) {
        snapshots.resize(length);
        currentSnap = 0;
    }
    
    void set(int index, int val) {
        snapshots[index][currentSnap] = val; // set the value in the current snapshot
    }
    
    int snap() {
        currentSnap++; // increment the current snapshot id
        return currentSnap - 1; // return the previous snapshot id
    }
    
    int get(int index, int snap_id) {
        auto it = snapshots[index].upper_bound(snap_id); // find the first snapshot after the given snap_id
        if (it == snapshots[index].begin()) {
            return 0; // no previous snapshots
        }
        it--; // move to the previous snapshot
        return it->second; // return the value at the previous snapshot
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */