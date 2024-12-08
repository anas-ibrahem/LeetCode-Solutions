// TODO NOT SOLVED


// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:

//     int m;
//     int n ;
//     int solve(int i , int j , vector<vector<int>>& dp , vector<vector<int>>& grid)
//     {
//         int ans = INT_MAX;
//         if (j + 1 < n )
//             ans = min(ans , dp[i][j+1]);
//         if (i + 1 < m  )
//             ans = min(ans , dp[i + 1][j]);

//         return ans + grid[i][j];
//     }



//     int minimumObstacles(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         vector<vector<int>> dp (m + 1 , vector<int> (n + 1 , INT_MAX));
//         dp[m - 1][n - 1] = grid[m - 1][n - 1];


//         for (int i = m - 2 ; i >= 0 ; i--)
//             {
//                 int j = n - 1;
//                 int ii = i;

//                 while (ii <= m - 1 && j >= 0)
//                 {
//                     int call = solve(ii , j , dp , grid);
//                     dp[ii][j] = call;
//                     ii++;
//                     j--;
//                 }
//             }


//         for (int j = n - 2 ; j >= 0 ; j--)
//             {
//                 int i = 0;
//                 int jj = j;
//                 while (i <= m - 1 && jj >= 0)
//                 {
//                     int call;
//                     dp[i][jj] =  call = solve(i , jj , dp , grid);
//                     i++;
//                     jj--;
//                 }
//             }

//         return dp[0][0];
//     }
// };


// int main()
// {
//     Solution s;
//     vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
//     cout << s.minimumObstacles(grid);
// }



 #include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m;
    int n ;
    int solve(int i , int j , vector<vector<int>>& dp , vector<vector<int>>& grid)
    {

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int ans = INT_MAX;
        // consider right , left , up , down
        if (j + 1 < n )  // right
            ans = min(ans , solve(i , j + 1 , dp , grid));
        if (i + 1 < m  ) // down
            ans = min(ans , solve(i + 1 , j , dp , grid));
        if (i - 1 >= 0) // up
            ans = min(ans , solve(i - 1 , j , dp , grid));
        if (j - 1 >= 0) // left
            ans = min(ans , solve(i , j - 1 , dp , grid));

        return dp[i][j] = ans + grid[i][j];
    }



    int minimumObstacles(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp (m + 1 , vector<int> (n + 1 , INT_MAX));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];


        return solve(0 , 0 , dp , grid);
    }
};


int main()
{
    Solution s;
    vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout << s.minimumObstacles(grid);
}



