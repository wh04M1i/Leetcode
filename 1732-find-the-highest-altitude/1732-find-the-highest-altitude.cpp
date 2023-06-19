class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> temp;
        int n = gain.size();
        temp.push_back(0);
        for(int i = 0; i < n; i++)
        {
            temp.push_back(temp[i] + gain[i]);
        }
        sort(temp.begin(), temp.end());
        return temp[n];
    }
};
