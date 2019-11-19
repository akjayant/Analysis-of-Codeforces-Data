#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vl vector<ll>


using namespace std;

int main() 
{
    int a;
    cin >> a;
    vector<pll> ans;
    for(int i = 0;i < a;i++)
    {
        int b, c, d, k, l;
        cin >> b >> c >> d >> k >> l;
        
        if((b + d - 1) / d + (c + k - 1) / k > l)
            ans.push_back(make_pair(-1, -1));
        else
            ans.push_back(make_pair((b + d - 1) / d, (c + k - 1) / k));
    }
    
    for(int i = 0;i < ans.size();i++)
        if(ans[i].first != -1)
            cout << ans[i].first << ' ' << ans[i].second << endl;
        else
            cout << -1 << endl;
}