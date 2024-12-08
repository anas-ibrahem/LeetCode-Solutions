#include <bits/stdc++.h>
using namespace std;


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


int main()
{
    int N , M;
    cin >>  N >> M;

    if (M == 0)
        {cout << 0;
        return 0;}

    vector<int> L (M , 0);
    dp = vector<vector<int>> (M + 10 , vector<int> (M + 10 , -1));
    for (int & s : L)
        cin >> s;


    cout << call (L , 0 , N - 1 , 0 , L.size() - 1);


    return 0;
}