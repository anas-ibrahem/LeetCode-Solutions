#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int helper(string & s , string & p , int i , int j , vector<vector<int>> & dp)
    {   
        int n = s.size();
        int m = p.size();

        if (i >= n && j >= m)
            return 1;
        if (j >= m) // only 2nd string finished -> false
            return 0;
        if (i < n && j < m && dp[i][j] != -1)
            return dp[i][j];

        int ret = 0;


        if (j + 1 < m && p[j + 1] == '*')
            {
            ret += helper(s , p , i , j + 2 , dp);
            if (i < n && (s[i] == p[j] || p[j] == '.') && !ret)
                ret += helper(s , p , i + 1, j , dp);
            }

        else if (i < n && (s[i] == p[j] || p[j] == '.'))
            ret += helper(s , p , i + 1 , j + 1 , dp);


        if (i < n && j < m )
            dp[i][j] = ret;

        return ret;
    }
    



    bool isMatch(string s, string p) 
    {
        vector<vector<int>> dp (111 , vector<int> (111 , -1));
        return helper (s , p , 0 , 0, dp) == 1;
    }
};

int main()
{
    Solution s;
    cout << s.isMatch("aa" , "a*a*") << endl;
    return 0;
}
