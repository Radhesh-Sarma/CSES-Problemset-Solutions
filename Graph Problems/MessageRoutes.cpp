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
 //is bipartite,CSES problem
  vector<int> par;
  vector<bool> vis;
  vector<vector<int>> g;
  void bfs(int s)
  {
     
      queue<int> q;
      q.push(s);
      par[s]=-1;
      vis[s] = true;
      
      while(q.size())
      {
          s = q.front(), q.pop();
          for(int v : g[s])
          {
             if(!vis[v])
              { vis[v]=true;
                par[v]=s;
                q.push(v);
              }
              
          }
      }
  }
  int32_t main()
  {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
       int n,m,x,y;
       cin>>n>>m;
       g.resize(n+1);
       vis.resize(n+1,false);
       par.resize(n+1,0);
       for(int i=1;i<=m;i++)
       {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
       }
       bfs(1);
       if(vis[n])
       {
        vector<int> ans;
        int x=n;
        while(x!=-1)
        {
          ans.push_back(x);
          x=par[x];
        }
        reverse(all(ans));
        cout<<ans.size()<<endl;
        for(auto x:ans)
          cout<<x<<" ";
       }
       else
       {
        cout<<"IMPOSSIBLE";
       }
       
      return 0;
    }