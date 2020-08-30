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


    int n,m,k;

    cin >> n >> m >> k;

    vector<int> v1(n),v2(m);


    for(int i = 0; i < n; i++)cin >> v1[i];

    for(int i = 0; i < m; i++)cin >> v2[i];


    sort(v1.begin(),v1.end());

    sort(v2.begin(),v2.end());


    int ans = 0;

    int i = 0, j = 0;

    while(i < n and j < m)
    {
        while(j < m and v2[j] < v1[i] - k)j++;

        if(j < m  and v1[i] <= v2[j] + k and v1[i] >= v2[j]-k)
        {
            ans++;
            j++;
        }
        i++;
    }

    cout << ans;



    return 0;
}
