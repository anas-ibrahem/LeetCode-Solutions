class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
         vector<int> dp(amount + 1 , INT_MAX);
         sort(coins.begin() , coins.end());

         dp[0] = 0; 

         for (int i = 1 ; i <= amount ; i++ )
            {
                for (int & coin : coins)
                {
                    if (i - coin >= 0)
                    {
                        int optn = dp[i - coin];
                        if (optn != INT_MAX)
                            dp[i] = min(dp[i] , dp[i - coin] + 1);
                    }
                    else
                        break;
                }
            }


            if (dp[amount] == INT_MAX)
                return -1;
        return dp[amount] ;
        
    }
};