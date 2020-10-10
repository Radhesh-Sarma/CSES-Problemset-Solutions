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
 
 
  
    int n;
    cin >> n;
 
    int k = n;
 
    n = n*(n+1)/2;
 
    if(n%2 != 0)
    {   
      cout << 0;
      return 0;
    }
 
 
 
    n/=2;
 
    k--;
 
 
 
    vector<int> dp(n+1,0);
 
    dp[0] = 1;
 
 
 
 
 
    for(int i = 1; i <= k; i++)
    {
      for(int j = n; j -i>=0;j--)
      {
          dp[j] += (dp[j-i])%MOD;
          dp[j]%=MOD;
         // trace4(j,i,j-i,dp[j-i]);
      }
    }
 
    dp[n]%=MOD;
 
    cout << (dp[n])%MOD;
 
 
 
 
 
    return 0;
}