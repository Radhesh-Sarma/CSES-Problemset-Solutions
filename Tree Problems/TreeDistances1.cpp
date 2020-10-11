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
 
  //Tree Distances 1 question
  //Important concept of diameter put to use
  //maximum distance from any node, will be an end point of the Tree Diameter
  //dfs1 calculates the farthest point from a randomly assumed root    
  //dfs2 distances from the first end point of diameter to the others
  //dfs1 again recalculates the distances of all other nodes from second end of diamter
 
vector<int> g[N];
vector<int> d1(N,0);
vector<int> d2(N,0);
 
void dfs1(int i = 1, int p = -1, int d = 0) {
  d1[i] = d;
  for(auto j : g[i])
    if(j != p)
      dfs1(j, i, d + 1);
}
 
void dfs2(int i = 1, int p = -1, int d = 0) {
  d2[i] = d;
  for(auto j : g[i])
    if(j != p)
      dfs2(j, i, d + 1);
}
 
int32_t main() {
   /* #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs1();
  dfs2(max_element(all(d1)) - d1.begin());
  dfs1(max_element(all(d2)) - d2.begin());
  for(int i = 1; i <= n; i++) {
    cout << max(d1[i], d2[i]) << ' ';
  }
  cout << '\n';
}