class Solution
{
public:
    // It's all about considering the worst case that the egg is at the last level to find it u will start
    // by throwin an egg at some level and rather it breaks and u go to the lower levels (subproblem with k - 1)
    // or to the upper levels with (subloblem with k )
    // but TO OPTIMIZE EVEN MORE U CAN BINARY SEARCH IT but how ???
    // notice that we can binary seach the minimum dividing as for sure

    int call(vector<vector<int>> &dp, int k, int n)
    {
        int &ret = dp[n][k];

        if (n == 1 || n == 0)
            return n; // only one needed
        if (k == 1)
            return n; // worst case n

        if (ret != -1)
            return ret;

        ret = INT_MAX;

        int lower = 1;
        int upper = n;

        // for (int mid = 1; mid <= n; mid++)
        // {
        //     int LL = call(dp, k - 1, mid - 1);
        //     int UU = call(dp, k, n - mid);

        //     int HERE = max(UU, LL);
        //     if (HERE < INT_MAX)
        //         HERE++;
            
        //     ret = min(ret, HERE);
        // }

        while (lower <= upper)
        {
            int mid = (lower + upper) / 2;

            int LL = call(dp, k - 1, mid - 1 );
            int UU = call(dp, k, n - mid);
            int HERE = max(UU, LL);
            if (HERE < INT_MAX)
                HERE++;

            if (LL < UU)
            {
                lower = mid + 1; // if LL is less than UU and our goal is to find the min of max then we need to balance them
                                // as possible then we add more range for the LL to balance as possible
            }
            else
            {
                upper = mid - 1;
            }

            ret = min(ret, HERE);
        }

        return ret;
    }

    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return call(dp, k, n);
    }
};