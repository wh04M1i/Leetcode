#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
        // Create an adjacency list to represent the graph
        std::unordered_map<int, std::vector<std::pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];
            graph[a].push_back({b, prob});
            graph[b].push_back({a, prob});
        }
        
        // Create a priority queue to store nodes based on their probabilities
        std::priority_queue<std::pair<double, int>> pq;
        
        // Create a vector to store the maximum probabilities of reaching each node
        std::vector<double> maxProbs(n, 0.0);
        
        // Start node has a probability of 1.0
        maxProbs[start] = 1.0;
        pq.push({1.0, start});
        
        while (!pq.empty()) {
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            // Skip if the current probability is smaller than the maximum probability
            if (currProb < maxProbs[currNode]) {
                continue;
            }
            
            // Traverse the neighbors of the current node
            for (const auto& neighbor : graph[currNode]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                double newProb = currProb * edgeProb;
                
                // Update the maximum probability if a higher probability is found
                if (newProb > maxProbs[nextNode]) {
                    maxProbs[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }
        
        // Return the maximum probability of reaching the end node
        return maxProbs[end];
    }
};
