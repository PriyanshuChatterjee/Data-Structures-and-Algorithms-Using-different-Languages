class Solution {
public:
    int mps(vector<vector<int>>& grid,int r,int c,vector<vector<int>>& dp)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=grid[i][j];
                else if(i==0)
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                else if(j==0)
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                else
                    dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[r-1][c-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,0));
        return mps(grid,r,c,dp);
    }
};