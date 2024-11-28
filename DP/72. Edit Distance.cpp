#include<bits/stdc++.h>
using namespace std;

// TOP DOWN 500ms
class Solution {
public:
    int call (string & word1, string & word2 , int i , int j , vector<vector<int>> & dp)
        {
            int n = word1.size();
            int m = word2.size();
            if (i == n && j == m)
                return 0;
            if (i > n || j > m)
                return INT_MAX;

            if (dp[i][j] != -1)
                return dp[i][j];
            
            int ret = INT_MAX;

            if (word1[i] == word2[j])
                    ret = call(word1 , word2 , i + 1 , j + 1, dp);
            else
                {
                    int optn1 = INT_MAX , optn2 = INT_MAX , optn3 = INT_MAX;
                        optn1 = call(word1 , word2 , i + 1 , j , dp);
                        optn2 = call(word1 , word2 , i + 1 , j + 1 , dp);
                        optn3 = call(word1 , word2 , i , j + 1, dp);
                        
                    ret = min (optn1 , optn2);
                    ret = min (ret , optn3);
                    if (ret < INT_MAX)
                        ++ret;
                }

            return dp[i][j] = ret;

        }

    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp (502 , vector<int> (502 , -1 ));
        return call (word1 , word2, 0 , 0 ,dp);
        
    }
};



// TOP DOWN 3ms REASON IS ALLOCATION FITTING ONLYYYY
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int call(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        int n = word1.size();
        int m = word2.size();

        // Base cases
        if (i == n) return m - j; // Insert all remaining characters of word2
        if (j == m) return n - i; // Delete all remaining characters of word1

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            // Characters match, move both indices forward
            return dp[i][j] = call(word1, word2, i + 1, j + 1, dp);
        } else {
            // Characters don't match, try all operations:
            int insertOp = call(word1, word2, i, j + 1, dp);     // Insert
            int deleteOp = call(word1, word2, i + 1, j, dp);     // Delete
            int replaceOp = call(word1, word2, i + 1, j + 1, dp); // Replace

            // Take the minimum of the three and add 1 for the current operation
            return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return call(word1, word2, 0, 0, dp);
    }
};

// TOP DOWN 7ms
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        // Memoization table, initialized to -1
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(word1, word2, m, n, dp);
    }

private:
    int helper(const string& word1, const string& word2, int m, int n, vector<vector<int>>& dp) {
        // Base cases
        if (m == 0) return n; // If word1 is empty, insert all characters of word2
        if (n == 0) return m; // If word2 is empty, delete all characters of word1

        // If the subproblem is already solved, return the result
        if (dp[m][n] != -1) return dp[m][n];

        // If the current characters are the same, move to the next pair
        if (word1[m - 1] == word2[n - 1]) {
            dp[m][n] = helper(word1, word2, m - 1, n - 1, dp);
        } else {
            // Perform insert, delete, or replace operation and take the minimum
            int insertOp = helper(word1, word2, m, n - 1, dp);
            int deleteOp = helper(word1, word2, m - 1, n, dp);
            int replaceOp = helper(word1, word2, m - 1, n - 1, dp);
            dp[m][n] = 1 + min({insertOp, deleteOp, replaceOp});
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;
    string word1 = "horse";
    string word2 = "ros";
    cout << "Minimum operations: " << solution.minDistance(word1, word2) << endl;

    word1 = "intention";
    word2 = "execution";
    cout << "Minimum operations: " << solution.minDistance(word1, word2) << endl;

    return 0;
}
