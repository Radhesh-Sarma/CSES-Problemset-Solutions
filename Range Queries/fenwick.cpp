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









    return 0;
}
