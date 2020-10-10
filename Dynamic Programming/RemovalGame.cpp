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
 
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    // dp[i][j] denotes the difference of scores 
    // of first and second player if both of them play optimally
 
    vector<int> arr(n+1);
    int sum = 0;
 
    for(int i = 1; i <= n; i++)
    {
      cin >> arr[i];
      sum += arr[i];
    }
 
 
    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j + i-1 <= n; j++)
      {
        
 
        int l = j;
        int r = j + i-1;
  
 
 
        if(l == r)dp[l][l] = arr[l];
        else dp[l][r] = max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
        
      }
    }
 
 
 
   cout << (sum + dp[1][n])/2 << endl;
 
 
 
 
    return 0;
}