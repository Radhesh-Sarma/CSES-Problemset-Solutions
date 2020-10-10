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
 
    int n; 
    cin >> n;
 
    vector<string> v(n);
 
    for(int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
 
 
    vector<vector<int>> dp(n,vector<int>(n,0));
 
    // dp[i][j] denotes the number of ways to reach i,j from 1,1 
    dp[0][0] = (v[0][0] == '.');
 
 
    for(int i = 1; i < n; i++)
    {
      if(v[i][0] == '*')dp[i][0] = 0;
      else dp[i][0] = dp[i-1][0];
 
      if(v[0][i] == '*')dp[0][i] = 0;
      else dp[0][i] = dp[0][i-1];
    }
 
 
    for(int i = 1; i < n; i++)
    {
      for(int j = 1; j < n; j++)
      {
        if(v[i][j] != '*')dp[i][j] = dp[i][j-1]%MOD + dp[i-1][j]%MOD;
        dp[i][j] %= MOD;
      }
    }
 
    cout << dp[n-1][n-1];
 
 
 
 
    return 0;
}