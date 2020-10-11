#include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
  #define ll long long
  #define int long long
   #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
  
 const int INF = (1LL << 30) - 1;
 const int N=2e5+2;
 
//LCA using binary lifting
 //employinh sparse table
  vector<int> g[N];
  vector<vector<int>> lca;
  vector<int> level;
  vector<int> par;
  vector<bool> vis;
  int maxN,n;
 
  
  void bfs(int s)
  {
      
      queue<int> q;
      q.push(s);
      vis[s] = true;
      level[s]=1;
      par[s]=-1;
      while(q.size())
      {
          s = q.front(), q.pop();
          for(int v : g[s])
          {
              if(!vis[v])
              {
                //trace2(s,v);
                  vis[v]=true;
                  par[v]=s;
                  level[v]=1+level[s];
                  q.push(v);
              }
             
          }
      }
  }
 
  void dfs(int node,int par)
  {
    lca[node][0]=par;
    for(int child:g[node])
    {
 
        if(child!=par)
            dfs(child,node);
    }
  }
  int LCA(int a,int b)
  {
    if(level[a] > level[b]) swap(a,b);
    int d=level[b]-  level[a];
    //binary lift node B to the level of node A
    //trace3(d,a,b);
    while(d>0)
    {
        int i=log2(d);
        b=lca[b][i];
        d-=(1<<i);
    }
 
    if(a==b) return a;
 
    for(int i=maxN; i>=0 ; i--)
    {
        if(lca[a][i]!=-1 && (lca[a][i] != lca[b][i]))
        {
            a=lca[a][i];
            b=lca[b][i];
        }
    }
 
    return par[a];
  }
 
 
 int32_t main()
 {
     /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
    IOS
    int m,q,x,y;
    cin>>n>>q;
    maxN=log2(n);
    /*cout<<n<<" is n\n";
    cout<<maxN<<" is maxn\n";*/
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
   /* for(int i=1;i<=n;i++)
    {
        cout<<i<<": ";
        for(auto x:g[i])
            cout<<x<<" ";
        cout<<endl;
    }*/
    vis.resize(n+1,false);
    level.resize(n+1,0);
    par.resize(n+1,-1);
    bfs(1);
    //cout<<"here";
    lca.resize(n+1,vector<int> (maxN+1,-1));
    dfs(1,-1);
    for(int j=1;j<=maxN;j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(lca[i][j-1]!=-1)
                {
                    int par=lca[i][j-1];
                    lca[i][j]=lca[par][j-1];
                }
            }
        }
    /*for(int i=0;i<n+1;i++ )
    {
        for(int j=0;j<maxN+1;j++)
            cout<<lca[i][j]<<" ";
 
        cout<<endl;
    }*/
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
 
    
   return 0;
  }