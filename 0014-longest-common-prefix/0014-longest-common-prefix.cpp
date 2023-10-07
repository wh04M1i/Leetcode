class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestprefix = "";
        int s = strs.size();

        if (s == 0)
            return longestprefix;

        if (s == 1)
            return strs[0];

        int n = strs[0].size();
        for (int i = 1; i <= n; i++) {
            string temp = strs[0].substr(0, i);

            for (int j = 1; j < s; j++) {
                if (i > strs[j].size() || temp != strs[j].substr(0, i)) {
                    return longestprefix;
                }
            }
            longestprefix = temp;
        }

        return longestprefix;
    }
};
