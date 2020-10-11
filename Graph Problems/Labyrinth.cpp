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
 
 
  map<pair<int, int> , pair<int, int>> par;
  vector<vector<bool>> vis;
   int dx[4]={0,0,-1,+1};
  int dy[4]={-1,+1,0,0};
   int N,M;
   bool issafe(int x,int y)
   {
     if(x>=0 and y>=0 and x<N and y<M)
      return true;
    return false;
   }
 
 
   string path=""; bool flag=true;
   pair<int, int> en;
    //BFS karna hoga
   void relation(pair<int, int> a,pair<int, int> b)
   {                //now and previous is b
      //trace4(a.f,a.s,b.f,b.s);
      if(a.f - b.f ==1 and a.s==b.s)
        {path+='D';}//cout<<"added this D"<<endl;}
      else if(a.f - b.f ==-1 and a.s==b.s)
        {path+='U';}//ut<<"added this U"<<endl;}
      else if(a.f==b.f and a.s-b.s==1)
        {path+='R';}//cout<<"added this R"<<endl;}
      else if(a.s - b.s == -1 and a.f==b.f)
        {path+='L';}//cout<<"added this L"<<endl;}
   }
   void bfs(vector<string>& g,int sx,int sy)
   {
     queue<pair<int, int>> q;
     q.push({sx,sy});
     vis[sx][sy]=true;
     par[{sx,sy}]={-1,-1};
     while(!q.empty())
     {
       pair<int, int> tmp=q.front();
       vis[tmp.f][tmp.s]=true;
       q.pop();
       for(int i=0;i<4;i++)
       {
        int x1=tmp.f + dx[i];
        int y1=tmp.s + dy[i];
        if(issafe(x1,y1))
        {
          if(g[x1][y1]!='#' and !vis[x1][y1])
          {
            par[{x1,y1}]={tmp.f,tmp.s};
            q.push({x1,y1});
            vis[x1][y1]=true;
          }
          if(vis[en.f][en.s])
            return;
 
        }
       }
     }
   }
 
   
  
  int32_t main()
  {
   /* #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
       int n,m,y;
       cin>>n>>m;
       string x;
       vector<string> g(n);
       vis.resize(n,vector<bool> (m,false));
       for(int i=0;i<n;i++)
       {
        cin>>g[i];
       }
       pair<int, int> start;
       N=n,M=m;
       bool got=false,got2=false;
       for(int i=0;i<n;i++)
       {
         for(int j=0;j<m;j++)
         {
          if(g[i][j]=='A')
            {start.f=i,start.s=j; got=true;}
          if(g[i][j]=='B')
            {en.f=i,en.s=j; got2=true;}
          if(got && got2)
             break;
 
         }
       }
       bfs(g,start.f,start.s);
       
       if(vis[en.f][en.s])
       {
          cout<<"YES\n";
          //
          pair<int, int> tmp=en;
 
          while(tmp.f != -1 and tmp.s != -1)
          {
            //trace2(tmp.f,tmp.s);
            //cout<<path<<endl;
            relation(tmp,par[tmp]);
            tmp=par[tmp];
          }
 
          cout<<path.size()<<endl;
          reverse(path.begin(), path.end());
          cout<<path;
       }
       else
       {
        cout<<"NO";
       }
 
      return 0;
  }