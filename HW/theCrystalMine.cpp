#include <bits/stdc++.h>
using namespace std;


 vector<pair<int,int>>  dp;


int main()
{
    int N , M;
    cin >> N;
    vector<int> mines (N , 0);
    for (int & s : mines)
        cin >> s;

    cin >> M;
    vector<int> miners (M , 0);
        for (int & s : miners)
        cin >> s;

    sort(miners.begin() , miners.end());



    int maxMine = *max_element(mines.begin() , mines.end());
    dp = vector<pair<int,int>> (maxMine + 1 , { 0 , 0 });
    
    // rem , cost
    for (int mine = 0 ; mine <= maxMine ; mine++)
        {
            dp[mine].first = mine;
            dp[mine].second = 0;
            
            for (int & miner : miners)
                {
                    if (miner <= mine)
                        {
                            pair<int , int> optn = dp[mine - miner];
                            if (optn.first < dp[mine].first)
                                {
                                    dp[mine] = optn;
                                    dp[mine].second += 1;
                                }
                            if (optn.first == dp[mine].first && optn.second + 1 < dp[mine].second )
                                {
                                    dp[mine] = optn;
                                    dp[mine].second += 1;
                                }
                        }
                    else
                        break;

                }

        }


        for (int & mine : mines)
            {
                cout << dp[mine].first << " " << dp[mine].second << endl;

            }



    return 0;
}