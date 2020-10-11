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
  #define mod INT_MAX 
  const int MOD=1e9+7;
  const int N=2e5+2;
 
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
    int q,x,y;
     cin>>n>>q;
     maxN=log2(n);
     
     for(int i=1;i<=n-1;i++)
     {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
     }
    
     vis.resize(n+1,false);
     level.resize(n+1,1);
     par.resize(n+1,-1);
      bfs(1);
     lca.resize(n+1,vector<int> (maxN+1,-1));  //LCA's SPARSE TABLE
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
      for(int i=1;i<=q;i++)
      {
        cin>>x>>y;
        int t=LCA(x,y);
        cout<<level[x]+level[y]-2*level[t]<<endl;
      }
      return 0;
 }