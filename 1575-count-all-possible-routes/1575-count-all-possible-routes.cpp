class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int MOD = 1e9 + 7;
        int n = locations.size();

        // Create a memoization table
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(fuel + 1, vector<int>(n, -1)));

        return dfs(locations, start, finish, fuel, memo, MOD);
    }

    int dfs(vector<int>& locations, int curCity, int finish, int fuel, vector<vector<vector<int>>>& memo, int MOD) {
        if (fuel < 0) {
            // Out of fuel, return 0
            return 0;
        }

        if (memo[curCity][fuel][finish] != -1) {
            // Return the result if already calculated
            return memo[curCity][fuel][finish];
        }

        int totalCount = 0;

        if (curCity == finish) {
            // Reached the destination city
            totalCount = 1;
        }

        // Iterate over all possible next cities
        for (int nextCity = 0; nextCity < locations.size(); nextCity++) {
            if (nextCity != curCity) {
                // Calculate the fuel required to move from the current city to the next city
                int fuelRequired = abs(locations[curCity] - locations[nextCity]);

                // Recurse on the next city with the remaining fuel
                totalCount = (totalCount + dfs(locations, nextCity, finish, fuel - fuelRequired, memo, MOD)) % MOD;
            }
        }

        // Store the result in the memoization table
        memo[curCity][fuel][finish] = totalCount;

        return totalCount;
    }
};
