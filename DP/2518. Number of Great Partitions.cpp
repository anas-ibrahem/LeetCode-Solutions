#include <bits/stdc++.h>
using namespace std;
// Not Solved Yet
// 1 2 3 4
class Solution {
public:
    int sum;
    int ans;
    int n;
    vector<vector<int>> dp;
    void call (int i , int pathSum , vector<int>& nums, int & k)
    {

        if (dp[i][pathSum] != -1)
            {return;
            dp[i][pathSum]= 1;}

        if (i == n && pathSum >= k  && (sum - pathSum) >= k)
            {
                ans++;
                ans %= 1000000000 + 7;
            }

        if (i < n)
            {
                if (i != 0)
                call(i + 1 , pathSum , nums , k);
                call(i + 1 , pathSum + nums[i], nums , k);
            }

    }


    int countPartitions(vector<int>& nums, int k) {
        sum = 0 ;
        ans = 0;
        n = nums.size();
        for (int & s : nums)
            sum += s;

        dp = vector<vector<int>>(n + 1 , vector<int> (sum + 1 , -1)) ;
        call(0 , 0 ,nums , k);

        ans %= 1000000000 + 7;
        ans * 2 ;
        return ans %= 1000000000 + 7;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4};
    int k = 4;
    cout << s.countPartitions(nums , k);
}