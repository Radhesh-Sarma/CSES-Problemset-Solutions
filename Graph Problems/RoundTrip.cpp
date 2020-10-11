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
  const int N=1e5+2;
 
  int n,m;
  vector<int> graph[N],ans;
  bool vis[N];
  int par[N];
   void dfs(int u,int pu =-1){
    par[u] =pu;
    vis[u] =true;
    for(int v: graph[u])
    {
      if(v==pu)
        continue;
      if(vis[v])
      {
        //already visited once, => cycle found, print it
        int u2=u;
        
        while(u ^ v) //xor with same element results in 0 & loop breaks
        {
            ans.pb(u);
            u=par[u];
        }
        ans.push_back(v);
        ans.push_back(u2);
        cout<<ans.size()<<endl;
        for(auto i:ans)
          cout<<i+1<<" ";
        exit(0);
      }
      else
        dfs(v,u);
    }
   }
 
  int32_t main()
  {
    // #ifndef ONLINE_JUDGE
    //    freopen("in.txt","r",stdin);
    //    freopen("out.txt","w",stdout);
    // #endif
       IOS
       /* Round trip 
       Find & print a round trip 
       Approach has to be a brute of dfs, break as soon as the same node found again
       */
       cin>>n>>m;
       int x,y;
       for(int i = 0;i<m;i++)
       {
        cin>>x>>y;
        --x; --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
       }
       for(int i = 0;i<n;i++)
       {
        if(!vis[i])
          dfs(i,-1);
       }
       cout<<"IMPOSSIBLE";
       return 0;
    }