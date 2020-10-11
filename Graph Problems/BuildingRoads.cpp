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
  #define all(v) v.begin(), v.end()
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
 
  vector<vector<int>> g;
  vector<bool> vis;
 
  void dfs(int x)
  {
    if(vis[x]) return;
      vis[x]=true;
      for(auto i: g[x])
        if(!vis[i])
          dfs(i);
 
  }
  int32_t main()
  {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
       int n,m,x,v;
       cin>>n>>m;
       g.resize(n+1);
       vis.resize(n+1,false);
       for(int i = 1; i <= m ; i++)
       {
        cin>>x>>v;
        g[x].push_back(v);
        g[v].push_back(x);
       }
       vector<int> components;
       for(int i=1;i<=n;i++)
       {
        if(vis[i]) continue;
        components.push_back(i);
        dfs(i);
       }
       cout<<components.size()-1<<endl;
       for(int i=1;i<components.size();i++)
        cout<<components[i-1]<<" "<<components[i]<<endl;
 
      return 0;
  }