#include <bits/stdc++.h>
using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define int long long
  #define endl "\n"


int32_t main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS


    int n;
    cin >> n;
 
    vector<pair<int, int>> v(n);
 
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(),v.end());
 
    int time = 0, ans = 0;
 
    for(int i = 0; i < n; i++)
    {   
        time += v[i].first;
        ans += v[i].second - time;
    }
 
    cout << ans << endl;
 
 





    return 0;
}
