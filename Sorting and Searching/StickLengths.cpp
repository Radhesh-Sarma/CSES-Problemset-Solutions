#include <bits/stdc++.h>
using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
#define int long long 


int cost(int c ,vector<int> &v)
{
    int ans = 0;

    for(int i = 0; i < v.size(); i++)
    {
        ans += abs(v[i]-c);
    }
    return ans;
}

int bs(vector<int> &v)
{
    sort(v.begin(),v.end());
    int low = v[0];
    int high = v[v.size()-1];

    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(cost(mid,v) <= cost(mid+1,v))
        {
           high = mid - 1;
        }
        else
        {
           low = mid + 1;
        }
    }

    return low;
}

int32_t main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS


    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    
    cout << cost(bs(v),v);



    return 0;
}
