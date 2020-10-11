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
  const int N=2e5+2;
 
  /*Planet Queries I
    Binary Lifting */
  int n,q,t[N][30]; /* t is sparse matrix for binary lifting,
   30 coz ceil[log2(MaxN)] her maxN is the number of queries n K, K depth ie 1e9 */
 
//switched the dimensions of table t just, from 30xN to Nx30, doesnt matter
 
  int32_t main()
  {
    /*#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif*/
       IOS
       cin>>n>>q;
       int x,k;
       for(int i = 0; i<n;i++)
       {
        cin>>t[i][0]; --t[i][0];
       }
       
    //preprocessing step of binary lifting of O(NlogN)
       for (int j = 1; j < 30; ++j)
       {
    for (int i = 0; i < n; ++i)
      {
       
          t[i][j] =  t[t[i][j-1]][j-1];
        }
       }
       
       while(q--)
       {
        cin>>x>>k;
        --x;
        
          for(int i = 0; i < 30; i++)
          {
           // trace3(i,(k>>i),(i&1));
            if(k&(1<<i))
              x = t[x][i];
          }
            cout<<x+1<<endl;
        }
       
        return 0;
  }