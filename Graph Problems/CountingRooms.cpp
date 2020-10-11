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
 
  string s[N]; //This will serve as our input graph
  /*Notice William Lin mostly uses array for fast access, with keyword array in C++  array ar<ll,2> instead of the pair data-structure */
  int n,m;
 
  bool isroom(int i,int j)
   {return i>=0&&i<n && j>=0 && j<m && s[i][j]=='.';}
 
  void dfs(int i,int j){
    s[i][j] = '#'; //marking it as visited by making a wall
    if(isroom(i-1,j))
      dfs(i-1,j);
    if(isroom(i+1,j))
      dfs(i+1,j);
    if(isroom(i,j-1))
      dfs(i,j-1);
    if(isroom(i,j+1))
      dfs(i,j+1);
  }
 
  int32_t main()
  {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
       /* Counting rooms
       The way question is framed, i got confused and wondered how will i ensure every room is completely surrounded by walls.
       But it turns out we were simply expected to find the number of connected components */
       cin>>n>>m;
       int ans = 0;
      for (int i = 0; i < n; ++i)
      {
        /* code */
        cin>>s[i];
      }
 
      for(int i = 0;i<n;i++)
      {
        for(int j = 0;j<m;j++)
        {
          if(isroom(i,j))
          {
            dfs(i,j);
            ans++;
          }
        }
      }
      cout<<ans;
       return 0;
     }