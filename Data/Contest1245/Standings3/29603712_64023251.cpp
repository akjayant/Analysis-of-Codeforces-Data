#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef long long int ll;
typedef pair<int,int> pi;
typedef unsigned long long int ull;

ll lsone(ll p){return(p & -p);}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main(){
    std::ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n, x[2010], y[2010], c[2010], s[2010], l[2010], k[2010], ans, mincost, rs, wirecost;
    cin >> n;
    vi ans1;
    vector<pair<int, int>> ans2;
    for (int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    for (int i=0;i<n;i++){
        cin >> c[i];
    }
    for (int i=0;i<n;i++){
        cin >> k[i];
        s[i] = i;
        l[i] = 0;
    }
    ans = 0;
    for (int i=0;i<n;i++){
        mincost = 1e9 + 7;
        rs = -1;
        for (int j=0;j<n;j++){
            if (l[j] == 0 && c[j] < mincost){
                mincost = c[j];
                rs = j;
            }
        }
        ans += c[rs];
        l[rs] = 1;
        if (s[rs] == rs){
            ans1.push_back(rs);
        }
        else{
            ans2.push_back({s[rs], rs});
        }
        for (int j=0;j<n;j++){
            if (l[j] == 0){
                wirecost = (k[rs] + k[j]) * (abs(x[rs] - x[j]) + abs(y[rs] - y[j]));
                if (wirecost < c[j]){
                    c[j] = wirecost;
                    s[j] = rs;
                }
            }
        }
    }
    cout << ans << endl << ans1.size() << endl;
    for (int i=0;i<ans1.size();i++){
        cout << ans1[i] + 1 << " ";
    }
    cout << endl << ans2.size() << endl;
    for (int i=0;i<ans2.size();i++){
        cout << ans2[i].first + 1 << " " << ans2[i].second + 1 << endl;
    }
}
