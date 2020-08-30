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


    set<int> s;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
    	int x;
    	cin >> x;
    	s.insert(x);

    }

    cout << s.size();






    return 0;
}
