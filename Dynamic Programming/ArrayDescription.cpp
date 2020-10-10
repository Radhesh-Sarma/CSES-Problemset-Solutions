#include <bits/stdc++.h>
using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
  #define int long long 
  const int N = 100005;
  #define all(v) v.begin(),v.end()
  #define double long double
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
const int MOD = 1000000007;
const int INF = (1LL << 62) - 1;
 
int32_t main()
{
 
 
 
      // #ifndef ONLINE_JUDGE
      // freopen("input.txt", "r", stdin);
      // freopen("output.txt", "w", stdout);
      // #endif
 
 
 
    IOS 
 
 
    int n, m;
    cin >> n >> m;
 
 
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
 
    // dp[i][j] denotes the number of arrays from 
    // 1 to i such that ith value is j
 
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++)
    {
      cin >> v[i];
    }
 
 
    if(v[1] == 0)
    {
      for(int i = 1; i <= m; i++)dp[1][i] = 1;
    }
    else
    {
      dp[1][v[1]] = 1;
    }
 
  
    
 
 
 
    for(int i = 2; i <= n; i++)
    {
      if(v[i] != 0)
      {
        dp[i][v[i]] += dp[i-1][v[i]]%MOD + dp[i-1][v[i]-1]%MOD;
        if(v[i] + 1 <= m)dp[i][v[i]] += dp[i-1][v[i]+1]%MOD;
        dp[i][v[i]]%= MOD;
      }
      else
      {
 
        dp[i][m] += dp[i-1][m]%MOD + dp[i-1][m-1]%MOD;
        dp[i][m]%=MOD;
 
        for(int j = 1; j <= m-1; j++)
        {
          dp[i][j] += dp[i-1][j-1]%MOD + dp[i-1][j]%MOD + dp[i-1][j+1]%MOD;
          dp[i][j] %= MOD;
        }
      }
 
 
    }
 
 
 
 
  
 
 
    // for(int i = 1; i <= n; i++)
    // {
    //   cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << " " << dp[i][4] << endl;
    // }
 
    int ans = 0;
 
    if(v[n] == 0)
    {
      for(int i = 1; i <= m; i++)ans += dp[n][i]%MOD;
      ans %= MOD;
    }
    else ans = dp[n][v[n]]%MOD;
 
    cout << ans%MOD << endl;
 
 
    return 0;
}