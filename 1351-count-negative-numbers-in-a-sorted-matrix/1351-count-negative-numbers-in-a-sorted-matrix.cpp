class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      int count=0;
      int m = grid.size();
      int n=grid[0].size();
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]<0)
                {count=count+(n-j);
                    break;}
            }
        }
        return count;
    }
};