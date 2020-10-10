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
 
 
 
    IOS
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> dp(n+1,vector<int>(m+1,INF));
 
 
    for(int i = 1; i <= min(n,m); i++)
    {
      dp[i][i] = 0;
    }
 
 
    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j <= m; j++)
      {
        for(int k = 1; k<= j; k++)
        {
          dp[i][j] = min(dp[i][j],dp[i][k] + dp[i][j-k] + 1);
        }
 
        for(int k = 1; k<= i; k++)
        {
          dp[i][j] = min(dp[i][j],dp[k][j] + dp[i-k][j] + 1);
        }
      }
    }
 
 
    cout << dp[n][m];
 
 
 
 
 
 
 
 
 
 
 
    return 0;
}
