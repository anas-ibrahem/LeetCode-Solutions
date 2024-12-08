class Solution {
public:
vector<vector<int>> dp;


int call (vector<int> & L , int i , int j , int start2search , int end2search)
{
    if (end2search < start2search)
        return 0;

    int & ret = dp[start2search][end2search];
    if (ret != -1)  
        return ret;

    int initCost = j - i + 1;
    int addcost = INT_MAX;
    for (int k = start2search  ; k <= end2search ; ++k)
        {
            if (L[k] <= j)
                {

                    int first = call(L , i , L[k] - 1 , start2search , k - 1);
                    int second = call(L , L[k] , j , k + 1 , end2search);
                    addcost = min(first + second , addcost);
                }
            else 
                break;
    
        }

        if (addcost == INT_MAX)
            return ret = 0;

        return ret = addcost + initCost;

}

    int minCost(int n, vector<int>& cuts) {
        int M = cuts.size();
        sort(cuts.begin() , cuts.end());
        dp = vector<vector<int>> (M  + 1 , vector<int> (M + 1 , -1));
        return call (cuts , 0 , n-1 , 0 , cuts.size() - 1);
    }


};