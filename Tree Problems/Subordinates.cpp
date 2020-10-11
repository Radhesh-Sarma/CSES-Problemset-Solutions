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
  #define inf INT_MAX
  const int mod=1e9+7;
  const int N=2e5+2;
 
  vector<int> g[N];
 
  vector<int> ans;
  int dfs(int src)
  {
    if(g[src].size()==0)
    {
      ans[src]=0;
      return 0;
    }
    int child=0;
    for(auto x:g[src])
    {
        child+=1+dfs(x);
    }
   // cout<<src<<" "<<child<<endl;
    return ans[src]=child;
  }
 
 
  int32_t main()
  {
   /* #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
   IOS
   int n,x;
   cin>>n;
 
   for(int i=2;i<=n;i++)
   {
      cin>>x;
      g[x].push_back(i);
   }
   /*for(int i=1;i<=n;i++)
   {
    cout<<i<<": ";
    for(auto j:g[i])
      cout<<j<<" ";
    cout<<endl;
   }*/
   ans.clear();
   ans.resize(n+1,0);
   dfs(1);
   for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
   
 return 0;
 }