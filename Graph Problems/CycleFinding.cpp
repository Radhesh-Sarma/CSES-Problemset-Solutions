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
    const int N=2500;
  
  /* Cycle finding : Find a negative cycle in 'directed graph'
  Constraints suggest that Bellman Ford would be ideal,
  its TC is O(n*m)
  */
 
  
struct Edge {
    int a, b, cost;
};
 
int n, m;
vector<Edge> edges;
const int INF = 1000000000;
 
void solve()
{
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }
 
    if (x == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];
 
        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
 
        cout << "YES\n";
        for (int v : cycle)
            cout << v+1 << ' ';
        
    }
}
 
  int32_t main()
  {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
      cin>>n>>m; 
      int a,b,c;
      for(int i = 0;i<m;i++)
      {
        cin>>a>>b>>c;
        --a,--b;
         edges.push_back({a,b,c});
      }
      
      solve();
       return 0;
    }