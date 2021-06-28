// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Time O(n^2)
// Space O(N^2)
class Solution {
public:
    int maxProfit(int K, vector<int>& arr) {
        int n = arr.size();
        int dp[n+1][K+1][2];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--)
        {
            for(int k=1;k<=K;k++)
            {
                // purchasing
                dp[i][k][0] = max(dp[i+1][k][0],dp[i+1][k][1]-arr[i]);
                // selling
                dp[i][k][1] = max(dp[i+1][k][1],dp[i+1][k-1][0]+arr[i]);
                // cout<<dp[i][k][0]<<" "<<dp[i][k][1]<<"   ";
            }
            // cout<<"\n";
        }
        return dp[0][K][0];
    }
};