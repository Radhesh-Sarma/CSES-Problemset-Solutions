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
    vector<int> cnt;
    vector<int> ans;
    int n;
  
    
   void dfs(int node, int parent) {
        for (int child: g[node])
            if (child != parent) {
                dfs(child, node);
                cnt[node] += cnt[child];
                ans[node] += ans[child] + cnt[child];
            }
    }
 
    void dfs2(int node, int parent) {
        for (int child: g[node])
            if (child != parent) {
                ans[child] = ans[node] - cnt[child] + (n - cnt[child]);
                dfs2(child, node);
            }
    }
   
    int32_t main()
    {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
    int x,y;
     cin>>n;
     
     
     for(int i=1;i<=n-1;i++)
     {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
     }
    
     //vis.resize(n+1,false);
     cnt.resize(n+1,1);
     ans.resize(n+1,0);
     dfs(1,-1);
     dfs2(1,-1);
     for(int i=1;i<=n;i++)
       cout<<ans[i]<<" ";
 
     
      return 0;
 }