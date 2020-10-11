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
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
 //is bipartite,CSES problem
  vector<int> col;
  vector<bool> vis;
  vector<vector<int>> g;
  bool dfs(int s)
    {
      if(vis[s]) return true;
      else
      {
        vis[s] = true;
        if(col[s]==0)
        {
          col[s]=1;
        }
 
        //assign color to the childre
        for(auto i : g[s])
        {
             if(col[i]==0)
             {
               if(col[s]==1)
                 col[i]=2;
               else
                 col[i]=1;
             }
             else if(col[i]==col[s])
               return false;
        }
        //traverse the children and && their answers, to return
        bool ans=true;
        for(auto i:g[s])
        {
          if(!vis[i])
          {
            ans&=dfs(i);
          }
        }
        return ans;
      }
    }
  int32_t main()
  {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
       int n,m,x,y;
       cin>>n>>m;
       g.resize(n+1);
       vis.resize(n+1,false);
       col.resize(n+1,0);
       for(int i=1;i<=m;i++)
       {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
       }
       bool answer=true;
       for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
            answer&=dfs(i);
            }
        }
       if(answer)
       {
        for(int i=1;i<=n;i++)
          cout<<col[i]<<" ";
       }
       else
       {
        cout<<"IMPOSSIBLE";
       }
 
 
       
      return 0;
    }