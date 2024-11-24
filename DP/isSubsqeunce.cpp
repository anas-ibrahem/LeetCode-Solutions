
class Solution {
public:
   bool isSubsequence(std::string s, std::string t) {
    int m = s.length(), n = t.length();

    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = true;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}
};


bool isSubsequence(std::string s, std::string t) {
    int m = s.length();
    int n = t.length();
    
    // Initialize DP table
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // If the length of the LCS is equal to the length of s, s is a subsequence of t
    return dp[m][n] == m;
}

