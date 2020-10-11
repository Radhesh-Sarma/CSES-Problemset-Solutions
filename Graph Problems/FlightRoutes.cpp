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
    #define pii pair<int, int>
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
  
void dijkstraKShortest(int s, int n, int k, vector<pair<int, int>> adj[], vector<vector<int>> &distance)
{
    int cnt = 0;
    distance.assign(n, vector<int>());  //stores the weights of 'shortest paths' ~ending~ at distance[i]
     vector<int> dist(n, 0); //temporary array, storing number of visits to a particular vertex
    priority_queue<pii, vector<pii>, greater<pair<int, int>>> pq;
    pq.push({0, s});  //Minimum Priority Queue of pairs, storing the {distance, vertex} pairs
    while (!pq.empty())
    {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if (dist[u] > k) continue;
        distance[u].push_back(d);
        if (u == n-1)
        {
            cnt++;
            if (cnt == k) break;
        }
        dist[u]++;
        for (auto &x : adj[u])
        {
            if (dist[x.first] > k) continue;
            pq.push({d + x.second, x.first});
        }
    }
}
 
/* Flight Routes 
Find k shortest paths from 1 to n in a directed graph!
Application of Dijkstra, with k paths 
Important observaion here is k is very small (k<10) &&
If you want to find k routes each vertex is visited atmax k times in k routes.
*/
 
  int32_t main()
  {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
        int n, m, k; 
        cin >> n >> m >> k;
        vector<pair<int, int>> adj[n+1];
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }
        vector<vector<int>> distance;  //stores the weights of 'shortest paths' ~ending~ at distance[i]
        dijkstraKShortest(1, n+1, k, adj, distance);
        for (auto &x : distance[n]) cout << x << " ";
        
       return 0;
    }