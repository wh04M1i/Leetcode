class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates)
    {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        long long cost = 0;   
 
        int count = 0;
        int low = 0;
        int high = costs.size()-1;

        while(count < k)
        {
            while( (pq1.size() < candidates) && (low <= high) )
            {
                pq1.push(costs[low]);
                low += 1;
            }

            while( (pq2.size() < candidates) && (high >= low) )
            {
                pq2.push(costs[high]);
                high -= 1;
            }

            int cost1 = (pq1.size() > 0) ? pq1.top() : INT_MAX;
            int cost2 = (pq2.size() > 0) ? pq2.top() : INT_MAX;

            if(cost1 <= cost2)
            {
                cost += cost1;
                pq1.pop();
            }
            else
            {
                cost += cost2;
                pq2.pop();
            }

            count += 1;
        }

        return cost;
    }
};