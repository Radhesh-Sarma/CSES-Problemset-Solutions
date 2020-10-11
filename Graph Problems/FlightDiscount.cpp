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
  const int INF=1e9+7;
  const int N=1e5+5;
 
  int n,m;
  int dist1[N],dist2[N];
  vector<pair<int, int>> g1[N];
  vector<pair<int, int>> g2[N];
 
  void dijkstra(int src,int dest,int dist[N],vector<pair<int,int>> g[N]){
    //although no need of end point here
       memset(dist,0x3f,sizeof(dist1));
       dist[src] = 0;
       //max pq declaration
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       pq.push({0,src});
      while(!pq.empty())
      {
        auto x = pq.top();
        pq.pop();
        if(x.first >  dist[x.second])
          continue;
        for(auto it: g[x.second])
        {
          if(dist[it.s] > dist[x.s] + it.f)
          {
           dist[it.s] = it.f + dist[x.s];
           pq.push({dist[it.s],it.s});            
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
        int u,v,w;
       cin>>n>>m;
       /* Flight Discount question *
        needed to do dijkstra from both front and end
        question just talks about unidirectional edges though! */
       while(m--)
       {
        cin>>u>>v>>w;
        g1[u].push_back({w,v});
        g2[v].push_back({w,u});
       }
        
        dijkstra(1,n,dist1,g1);
        dijkstra(n,1,dist2,g2);
        int ans = 1e18;
        for(int i = 1 ; i<=n;i++)
        {
          for(auto x:g1[i])
          {
            
            ans = min(ans,dist1[i] + dist2[x.s] + (x.f)/2);
            //trace6(i,x.s,dist1[i],dist2[x.s],x.f,ans);
          }
        }
        cout<<ans;
           
   
       return 0;
    }