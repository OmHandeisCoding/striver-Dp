class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
       int rows =  obstacleGrid.size();
       int cols = obstacleGrid[0].size();

       vector<vector<int>>dp = obstacleGrid;

       for(int i=0;i<rows;i++)
       {
           for(int j=0;j<cols;j++)
           {
               if(dp[i][j]==1)
               {
                   dp[i][j]=-1;
               }      
           }
       }
       //yaha se yaha aane ka ek hi rasta hai . . . [0][0]ki bat kr ra 
       if(dp[0][0]!=-1)dp[0][0]=1;
       for(int i=1;i<rows;i++)
       {
           if(dp[i][0]!=-1)
           {
              dp[i][0]=dp[i-1][0];
           }
           else
           {
             dp[i][0]=0;
           }
       }

       for(int i=1;i<cols;i++)
       {
            if(dp[0][i]!=-1)
           {
              dp[0][i]=dp[0][i-1];
           }
           else
           {
             dp[0][i]=0;
           }
       }

       for(int i=1;i<rows;i++)
       {
           for(int j=1;j<cols;j++)
           {
               if(dp[i][j]!=-1)
               {
                   dp[i][j]=dp[i-1][j]+dp[i][j-1];
               }   
               else
               {
                   dp[i][j]=0; 
               }       
           }
       }
     
      return dp[rows-1][cols-1]<=0?0:dp[rows-1][cols-1];
    }
};
