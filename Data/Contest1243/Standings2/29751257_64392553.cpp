//be name khoda
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int maxn = 100 * 1001;
const int mod = 1e9+7;

ll a[maxn], n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int q; cin>> q;
    while(q--)
    {
        cin>> n;
        string s, t; cin>> s >> t;
        vector<int> dif;
        for(int i = 0; i < n; i++)
            if(s[i] != t[i])
                dif.push_back(i);
        if(dif.size() == 0) {cout<< "Yes\n"; continue;}
        if(dif.size() != 2) {cout<< "No\n"; continue;}
        if(s[dif[0]] == s[dif[1]] && t[dif[0]] == t[dif[1]])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
