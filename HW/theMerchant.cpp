#include <bits/stdc++.h>
using namespace std;





int main()
{
    int  m , a , b;
    cin >> m >> a >> b;
    vector<int> sol {0 , 0 , m};

    for (int BS = m / b ; BS >= 0 ; --BS)
    {
        int M = m - BS * b;
        int AS = M / a;
        int rem = M - AS * a;

        if (rem < sol[2])
            sol = {AS , BS , rem};

    }


       for (int & D : sol)
        cout << D << " ";
    

    return 0;
}