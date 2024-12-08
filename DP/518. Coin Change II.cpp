class Solution {
public:

    int call (int amount , vector<int>& coins ,  vector<vector<int>> & dp , int i = 0)
    {

        if (amount == 0)
            return 1;

        if (amount < 0 || i >= (int)coins.size())
            return 0;

        int & ret = dp[i][amount];
        if (ret != -1)
            return ret;

        ret = 0;


        ret += call(amount , coins , dp , i + 1);
        ret += call(amount - coins[i] , coins , dp , i);



        return ret;

    }


    int change(int amount, vector<int>& coins) 
    {
         vector<vector<int>> dp( coins.size() + 1 , vector<int>(amount + 1 , -1));
         return call (amount , coins , dp );
    }
};
