// 2d dp

class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        int totalSquares = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    totalSquares += dp[i][j];
                }
            }
        }

        return totalSquares;
    }
};

// 3d dp

class Solution {
public:
    int m, n, ans;
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<vector<bool>>> dp = vector<vector<vector<bool>>>(m + 1, vector<vector<bool>>(n + 1, vector<bool>(min(m, n) + 1, 0)));
        int maxSize = min(n, m);
        for (int size = 1; size <= maxSize; size++) {
            for (int i = size - 1; i < m; i++) {
                for (int j = size - 1; j < n; j++) {
                    if (matrix[i][j]) {
                        if (size == 1) {
                            dp[i][j][size] = 1;
                            ans++;
                            continue;
                        }
                        bool yes = dp[i][j - 1][size - 1] && dp[i - 1][j][size - 1] &&dp[i - 1][j - 1][size - 1] ;
                        if (yes) {
                            dp[i][j][size] = 1;
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
