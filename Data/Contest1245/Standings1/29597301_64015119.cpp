#include <bits/stdc++.h>
#define int long long

using namespace std;

pair<int, int> gdz[10000];
int c[10000];
int k[10000];

int oj[100000];

int o(int w) {
    if (oj[w] == w)
        return w;
    return oj[w] = o(oj[w]);
}

void uni(int a, int b) {
    a = o(a);
    b = o(b);

    oj[a] = b;
}

vector<pair<int, pair<int, int> > > v;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        oj[i] = i;

    for(int i=0;i<n;i++)
        cin>>gdz[i].first>>gdz[i].second;
    for(int i=0;i<n;i++)
        cin>>c[i];
    for(int i=0;i<n;i++)
        cin>>k[i];

    for(int i=0;i<n;i++) {
        v.push_back({c[i], {0, i + 1}});
    }

    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++) {
        v.push_back({(k[i]+k[j])*(abs(gdz[i].first - gdz[j].first) + abs(gdz[i].second - gdz[j].second)), {i + 1, j + 1}});
    }

    sort(v.begin(), v.end());

    vector<pair<int, int> > res;
    vector<pair<int, int> > res2;

    int wyn = 0;
    for(auto &x : v) {
        if(o(x.second.first) != o(x.second.second)) {
            if(x.second.first == 0)
                res.push_back({x.second.first, x.second.second});
            else
                res2.push_back({x.second.first, x.second.second});

            wyn += x.first;
            uni(x.second.first, x.second.second);
        }
    }

    cout<<wyn<<endl;

    cout<<res.size()<<endl;
    for(auto x : res)
        cout<<x.second<<" ";
    cout<<endl;

    cout<<res2.size()<<endl;
    for(auto x : res2)
        cout<<x.first<<" "<<x.second<<"\n";






    return 0;
}