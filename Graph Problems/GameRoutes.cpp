#include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
  #define ll long long
  #define int long long
  #define double long double
  #define max(a,b) (a>b?a:b)
  #define min(a,b) (a<b?a:b)
  #define mp make_pair
  #define pb push_back
  #define inf INT_MAX
  #define f first
  #define s second
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
  #define all(v) v.begin(), v.end()
  #define mod INT_MAX 
  const int M=1e9+7;
  const int N=1e5+2;
  
  int dp[N];
  vector<int> adj[N];
  int n,m;
  bool vis[N];
 
  void dfs(int u){
    dp[u] = u==n-1?1:0;
    vis[u] =true;
    for(auto v: adj[u]){
      if(!vis[v])
      {
        dfs(v);
      }
      dp[u] = (dp[u]%M + dp[v]%M)%M;
 
    }
 
    
  }
    
  int32_t main()
  {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
      /* Game Routes: number of ways to reach from 1 to n in a directed graph
        DP on graphs */
       //dp[i] : number of ways to reach n from node i
       cin>>n>>m;
       int x,y;
       while(m--)
       {
        cin>>x>>y;
        --x,--y;
        adj[x].push_back(y);
      }
 
      dfs(0);
      cout<<dp[0];  
       
        return 0;
  }