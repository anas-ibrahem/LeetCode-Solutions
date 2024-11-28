class Solution {
public:
    vector<vector<int>> dp;

    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (s[i] == s[j]) && isPalindrome(s, i + 1, j - 1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        int maxLen = 0;
        pair<int, int> sol = {0, 0};

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j) && (j - i + 1 > maxLen)) {
                    maxLen = j - i + 1;
                    sol = {i, j};
                }
            }
        }

        return s.substr(sol.first, sol.second - sol.first + 1);
    }
};
