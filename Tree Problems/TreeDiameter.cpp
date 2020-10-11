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
 
  
    
vector<vector<int>> g;
int n;
pair<int, int> bfs(int root){
    vector<int> dist(n+1, -1);
    dist[root] = 0;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int curr = q.front();
        for(auto it : g[curr]){
            if(dist[it] != -1){
                continue;
            }
            q.push(it);
            dist[it] = dist[curr] + 1;
        }
        q.pop();
    }
    int mx = INT_MIN, vertex = -1;
    for(int i=1 ; i<=n ; i++){
        if(mx < dist[i]){
            mx = dist[i];
            vertex = i;
        }
    }
    /*cout<<root<<endl;
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;*/
    return make_pair(mx, vertex);
}
int diameter(int root){
    pair<int, int> p1 = bfs(root), p2;
    //cout<<p1.f<<endl;
    p2 = bfs(p1.second);
    //cout<<p2.s<<"second farthest vertex\n";
    return p2.first;
}
int32_t main(){
   /* #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
    cin >> n;
    g.resize(n+1);
    for(int i=0, u, v ; i<n-1 ; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
// choosing arbitrary node to be 1.
    cout << diameter(1) ;
    return 0;
 }