#include<bits/stdc++.h>
using namespace std;
 // assume a modification : you cannot jump to certian steps, they are blocked // jumps steps <= k 
class Solution {
public:
    int f(int n)
    {
       int prev=1;
       int prev2=1;
       int curr;
       for(int i=2;i<=n;i++)
       {
         curr=prev+prev2;
         prev2=prev;
         prev=curr;
       }
       if(n<=1)curr=1;
       return curr;

    }
    int climbStairs(int n) {
        return f(n);
    }
};

int main()
{
    int n;
    cin>>n;

    Solution obj;
    cout<<obj.climbStairs(n);

    return 0;
}
