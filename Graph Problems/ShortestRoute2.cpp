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
  const int N=505;
 
  int n,m,q;
  int dist[N][N];
  
  int32_t main()
  {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
       /* Shortest Route 2
       Find the length of shortest path between the asked vertices as queries
       Seeing the constraints this seems to be a n^3 problem, that is flloyd warshall
       smart move, didnt explicity initialise a graph here, the distance/weight matrix does it all
       */
      cin>>n>>m>>q;
       int x,y,w;
       memset(dist,0x3f,sizeof(dist));
       for(int i = 0;i<m;i++)
       {
        cin>>x>>y>>w;
        --x; --y;
        dist[x][y] =  min(dist[x][y],w);
        dist[y][x] =  min(dist[y][x],w);
       }
 
       
       for (int i = 0; i < n; ++i)
       {
          dist[i][i] = 0;
       }
       
       for (int k = 0; k < n; ++k)  //Outermost loop,serves as the intermediate point between all other pairs of i & j
       {
         /* code */
        for (int i = 0; i < n; ++i)
        {
          /* code */
          for (int j = 0;j < n; ++j)
          {
            /* code */
            dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
          }
        }
       }
       
       while(q--)
       {
        cin>>x>>y;
        --x; --y;
        if(dist[x][y] >= 1e18) {cout<<"-1"<<endl;continue;}
        cout<<dist[x][y]<<endl;
       }
 
       
       return 0;
    }