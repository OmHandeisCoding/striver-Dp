#include<bits/stdc++.h>
using namespace std;
int fib_tab(int n,vector<int>&dp2)
{
  
    for(int i=2;i<=n;i++)
    {
        dp2[i]=dp2[i-1]+dp2[i-2];
        
    }
    return dp2[n];
}

int fib_memo(int n,vector<int>&dp)
{
    if(n<=1)return n;

    if(dp[n]!=-1)return dp[n];

    return dp[n]=fib_memo(n-1,dp)+fib_memo(n-2,dp);
   
}
//space optimized
int fib_best(int n)
{
  int prev=1;
  int prev2=0;
  int curr;
  for(int i=2;i<=n;i++)
    {
      curr=prev+prev2;
      prev2=prev;
      prev=curr;
    }

  return curr;
}


int main()
{
    //0 1 1 2 3 5 8 . . . 
    //0 1 2 3 4 5 6

    int n;
    cin>>n;

    vector<int>dp(n+1,-1);
    dp[0]=0,dp[1]=1;
    vector<int>dp2(n+1,-1);
    dp2[0]=0,dp2[1]=1;

    cout<<fib_memo(n,dp)<<endl;
    cout<<fib_tab(n,dp2)<<endl;
    
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" "<<dp2[i]<<endl;
    }

    return 0;
}
