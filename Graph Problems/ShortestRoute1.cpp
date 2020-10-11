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
  vector<pair<int,int>> graph[N];
  vector<int> ans;
  int d[N];
 
  
 
  
 
  int32_t main()
  {
    // #ifndef ONLINE_JUDGE
    //    freopen("in.txt","r",stdin);
    //    freopen("out.txt","w",stdout);
    // #endif
       IOS
       /* Shortest Route I
       Find shortest path length from city 1 to all others
       Seeing the constraints this becomes a straight dijkstra's problem
       */
       cin>>n>>m;
       int x,y,w;
       for(int i = 0;i<m;i++)
       {
        cin>>x>>y>>w;
        --x; --y;
        graph[x].push_back({w,y});
        
       }
        int src = 0;
        memset(d,0x3f,sizeof(d));
    d[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(pq.size()){
      auto t = pq.top();
      pq.pop();
      if(t.f > d[t.s])
          continue;
      for(auto v: graph[t.s])
      {
        //trace2(t.s,v.s);
        if(d[v.s] > d[t.s] + v.f )
         {
          d[v.s] = d[t.s] + v.f;
          pq.push({d[v.s],v.s});
        }
      }
    }
       for(int i = 0;i<n;i++)
        cout<<d[i]<<" ";
 
       
       return 0;
    }