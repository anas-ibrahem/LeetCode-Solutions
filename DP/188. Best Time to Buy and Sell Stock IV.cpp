#include <bits/stdc++.h>
using namespace std;

// Bottom up 3d
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // DP table: dp[day][transactions][holding]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        // Initialize base cases
        for (int j = 0; j <= k; ++j) {
            dp[0][j][0] = 0;               // Day 0, no stock, no profit
            dp[0][j][1] = -prices[0];      // Day 0, holding stock (buy on first day)
        }
        
        // Fill DP table iteratively
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) { // Transactions start at 1
                // Not holding: Max of selling today or skipping
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);

                // Holding: Max of buying today or continuing to hold
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        // Final answer: Maximum profit with k transactions and not holding any stock
        return dp[n - 1][k][0];
    }
};

// top down 3d
class Solution {
public:
    int dp[101][1001][2]; // Memoization table: [t][day][holding]

    int helper(int t, int i, int holding, vector<int>& prices) {
        // Base cases
        if (t == 0 || i >= prices.size()) return 0; // No transactions left or no more days

        // Check memoization table
        if (dp[t][i][holding] != -1) return dp[t][i][holding];

        int doNothing = helper(t, i + 1, holding, prices); // Skip this day

        if (holding) {
            // Sell the stock
            int sell = prices[i] + helper(t - 1, i + 1, 0, prices);
            dp[t][i][holding] = max(doNothing, sell);
        } else {
            // Buy the stock
            int buy = -prices[i] + helper(t, i + 1, 1, prices);
            dp[t][i][holding] = max(doNothing, buy);
        }

        return dp[t][i][holding];
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp)); // Initialize memoization table with -1
        return helper(k, 0, 0, prices); // Start with 0 transactions used, day 0, not holding any stock
    }
};


// bottom up 2d
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int t = 1; t <= k; t++) {
            int POCKET = -prices[0];
            for (int d = 1; d < n; d++) {
                dp[t][d] = max(dp[t][d - 1], prices[d] + POCKET);
                POCKET = max(POCKET, dp[t - 1][d] - prices[d]);
            }
        }

        return dp[k][n - 1];
    }
};


//top down 2d (BAD and HARD TO OPTIMIZE)
class Solution {
public:
    vector<vector<int>> memo; // Memoization table

    int helper(int t, int d, vector<int>& prices) {
        if (t == 0 || d < 0) return 0; // Base case: no transactions or no days left

        if (memo[t][d] != -1) return memo[t][d]; // Use cached result if available

        // Option 1: Skip day `d`
        int doNothing = helper(t, d - 1, prices);

        // Option 2: Make a transaction and sell on day `d`
        int maxDiff = INT_MIN;
        for (int p = 0; p < d; p++) { // Try buying on all previous days
            maxDiff = max(maxDiff, prices[d] - prices[p] + helper(t - 1, p, prices));
        }

        // Store the result in the memo table
        return memo[t][d] = max(doNothing, maxDiff);
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        memo.assign(k + 1, vector<int>(n, -1)); // Initialize memo table with -1
        return helper(k, n - 1, prices); // Start from `k` transactions and last day
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        
    }
};