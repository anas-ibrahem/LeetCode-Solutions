class Solution {
public:
  vector<vector<int>> dp;
  int n;
  int half;

    bool call (int i , int sum  , vector<int>& nums)
    {
        if (i >= n)
            return 0;


        if (sum == half)
            return true;

        if (sum > half)
            return false;

        if (dp[i][sum] != -1)
            return dp[i][sum] & 1;


        bool take = call(i + 1 , sum + nums[i] , nums);
        bool Ntake = call(i + 1 , sum  , nums) ;


        return dp[i][sum] = (take || Ntake);


    }


    bool canPartition(vector<int>& nums) {
        n = nums.size();
        for (int & s : nums)
            half += s;

        if (half & 1)
            return false;
        
        half /=2;
        
       dp =  vector<vector<int>> (n + 1 ,vector<int>(20001 , -1));


        return call(0 , 0 , nums);
        
    }
};