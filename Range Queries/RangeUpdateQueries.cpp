#include <bits/stdc++.h>
using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define int long long
  #define endl "\n"
 
struct FenwickTree
{
    int n;
    vector<int> t;
    
    FenwickTree(int m)
    {
        n = m;
        t.resize(n+1,0);
    }
 
    void update(int idx, int x)
    {
        while(idx <= n)
            t[idx] += x, idx += idx & -idx;
    }
 
    int query(int idx)
    {
        int sum = 0;
        while(idx)
            sum += t[idx], idx -= idx & -idx;
        return sum; 
    }
 
    int query(int idx1,int idx2)
    {
        return query(idx2)-query(idx1-1);
    }
};
 
 
int32_t main()
{
 
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS
 
 
 
    int n,q;
    cin >> n >> q;
 
    FenwickTree f(n);
    vector<int> arr(n+1);
 
    for(int i = 1; i <= n; i++)
    {
         cin >> arr[i];   
    }
 
    while(q--)
    {
        int type;
        cin >> type;
 
        if(type == 1)
        {
            int a,b,u;
            cin >> a >> b >> u;
            f.update(a,u);
            f.update(b+1,-u);
        }
        else
        {
            int k;
            cin >> k;
            cout << arr[k] + f.query(k) << endl;
        }
    }
 
 
 
 
 
    return 0;
}