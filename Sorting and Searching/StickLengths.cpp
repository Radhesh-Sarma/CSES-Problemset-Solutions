#include <bits/stdc++.h>
using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
#define int long long 

int32_t main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS


    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    
    sort(v.begin(),v.end());
    int ans = 0;
    int median = v[n/2];

    for(int i = 0; i < n; i++)
    {
        ans += abs(median - v[i]);
    }

    cout << ans;


    return 0;
}
