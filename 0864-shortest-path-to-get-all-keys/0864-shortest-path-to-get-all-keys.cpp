class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int allKeys = 0;
        int startX = -1, startY = -1;

        // Find the starting position and count the number of keys
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                } else if (islower(grid[i][j])) {
                    allKeys |= 1 << (grid[i][j] - 'a');
                }
            }
        }

        // Define the four possible directions: up, down, left, right
        vector<int> directions = {-1, 0, 1, 0, -1};

        // Create a queue to store the states (x, y, collectedKeys)
        queue<vector<int>> q;
        q.push({startX, startY, 0});
        
        // Create a visited set to avoid revisiting the same state
        unordered_set<string> visited;

        // Perform BFS
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            
            // Explore all states at the current level
            while (size--) {
                vector<int> state = q.front();
                q.pop();

                int x = state[0];
                int y = state[1];
                int collectedKeys = state[2];
                
                // Check if all keys have been collected
                if (collectedKeys == allKeys)
                    return steps;

                // Generate unique key for the state
                string key = to_string(x) + "-" + to_string(y) + "-" + to_string(collectedKeys);

                // Skip if the state has already been visited
                if (visited.count(key))
                    continue;

                // Mark the state as visited
                visited.insert(key);

                // Explore all four directions
                for (int i = 0; i < 4; i++) {
                    int nx = x + directions[i];
                    int ny = y + directions[i + 1];

                    // Skip if the next position is outside the grid
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    char cell = grid[nx][ny];

                    // Skip if the next position is a wall
                    if (cell == '#')
                        continue;

                    int nextCollectedKeys = collectedKeys;

                    // If the next position is a key, update the collectedKeys
                    if (islower(cell))
                        nextCollectedKeys |= 1 << (cell - 'a');

                    // If the next position is a lock and we don't have the corresponding key, skip
                    if (isupper(cell) && !(collectedKeys & (1 << (cell - 'A'))))
                        continue;

                    // Add the next state to the queue
                    q.push({nx, ny, nextCollectedKeys});
                }
            }

            // Increment the number of steps
            steps++;
        }

        return -1; // No path found
    }
};