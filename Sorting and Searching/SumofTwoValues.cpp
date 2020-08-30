#include <bits/stdc++.h>
using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"


int32_t main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS


    int n, x;
    cin >> n >> x;

    map<int,int> mp;

    for(int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        if(mp.find(x-y) != mp.end())
        {
            cout << i + 1 << " " << mp[x-y];
            return 0;
        }
        mp[y] = i + 1;
    }
 

    cout << "IMPOSSIBLE";





    return 0;
}
