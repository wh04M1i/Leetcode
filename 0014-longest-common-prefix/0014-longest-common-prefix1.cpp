#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }

        int n = strs[0].size();

        for (int i = 0; i < n; i++) {
            char ch = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};
