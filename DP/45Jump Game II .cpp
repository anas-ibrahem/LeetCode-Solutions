class Solution {
public:
    int helper (int i ,vector<int>& nums , vector<int> & dp)
    {
        if (dp[i] != -1)
            return dp[i];
            
        int mn = INT_MAX;
        if (i > nums.size() - 1)
            return INT_MAX;
        if (i == nums.size() - 1)
            return 0;

        for (int j = 1 ; j <= nums[i] ; j++)
            mn = min(mn , helper(i + j , nums , dp) + 1 );

        return dp[i] = mn;

    }

    int jump(vector<int>& nums) {
        vector<int> dp(10000, -1);
        return helper(0 , nums , dp);
    }
};