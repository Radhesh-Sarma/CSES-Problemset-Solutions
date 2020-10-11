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
  const int MOD=1e9+7;
  const int N=2e5+2;
 
  vector<vector<int>> g;
  vector<int> deg;
  vector<int> ans;
  int n;
  bool kahn()
  {
      queue<int> q;
      for(int i = 1; i <= n;i++)
        if(!deg[i]) q.push(i);
      while(!q.empty())
      {
        int tmp=q.front();
        q.pop();
        //deg[tmp]--;
        ans.pb(tmp);
        for(int x:g[tmp])
        {
          deg[x]--;
          if(deg[x]==0)
            q.push(x);
          //deg[x]--;
        }
      }
      return ans.size()==n;
  }
  int32_t main()
  {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
       int m,x,y;
       cin>>n>>m;
       g.resize(n+1);
       deg.resize(n+1,0);
       for (int i = 0; i < m; ++i)
       {
         cin>>x>>y;
         g[x].push_back(y);
         deg[y]++;
       }
       bool ok = kahn();
       if(ok)
       {
        for(auto x:ans)
          cout<<x<<" ";
 
       }
       else
        cout<<"IMPOSSIBLE";
    return 0;
  }