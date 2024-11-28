class Solution
{
public:
    bool valid(int size, const int &k)
    {
        // it will be valid if it can be divided into k + x(k-1) so cond -> size = k - 1 + 1 + x (k - 1 )
        // ->  ( size - 1 ) % ( k - 1) == 0 -> valid
        return (size - 1) % (k - 1) == 0;
    }

    int call(const vector<int> &prfSum, const int &k, vector<vector<int>> &dp, int start, int end)
    {
        int &ret = dp[start][end];
        if (ret != -1)
            return ret;
        // Define DP as the coes (answer)
        // to get cost to solve regardless of k for smaller than k as the cost to merge this subproblem should
        // actually be inf but for simpler soln we weill consioder them 0
        if (end - start + 1 < k)
            return ret = 0;

        ret = INT_MAX;

        // now its valid to solve this then we will rey every possilbe dividing costing and then we need to sum up all the
        // elemnts inside again note that it's better to use prefix sum here so we have the prfSum
        // 0 , 1 , 2 , 3 , 4 -> end = 5  , start = 0




        // This loop is the real magic note that for each call if we take one element and solve the rest or take k -1 or 2 (k - 1 ) ..... we will eventually have a k to solve which will fix every thing 
// this enusres that for ex n = 4 and k = 3 will result in value that describes not a subproblem but
// helping in the prev known valid problem with a vlue that descirbes the rescursive call to solve it 
        for (int mid = start; mid < end; mid += k - 1)
            ret = min(ret, call(prfSum, k, dp, start, mid) + call(prfSum, k, dp, mid + 1, end));

        if (valid (end - start + 1 , k))
            ret += prfSum[end + 1]  - prfSum[start];
        // 1 3 -> 1 , 4 - > prf[4] - prf[1]

        return ret;
    }

    int mergeStones(vector<int> &stones, int k)
    {
        if (!valid(stones.size() , k)) return -1;


        vector<int> prfSum(stones.size() + 1, 0);
        for (int i = 1; i < stones.size() + 1; ++i)
            prfSum[i] = prfSum[i - 1] + stones[i - 1];

        vector<vector<int>> dp(stones.size() + 1, vector<int>(stones.size() + 1, -1));
        int ans = call(prfSum, k, dp, 0, stones.size() - 1);
        if (ans == INT_MAX)
            ans = -1;

        return ans;
    }
};