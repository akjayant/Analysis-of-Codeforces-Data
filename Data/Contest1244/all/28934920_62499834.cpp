
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = int64_t;



int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n,k; cin >> n>>k;
    vector<int> arr(n);
    rep(i,n) cin >> arr[i];
    map<int,int> occs;
    rep(i,n) ++occs[arr[i]];
    vector<pair<int,int>> nums;
    for(auto p : occs) nums.push_back(p);
    int front = 0;
    int back = nums.size()-1;
    while(back-front>=1) {
        int low = nums[front].second < nums[back].second;
        if(low) {
            auto& p0 = nums[front];
            auto& p1 = nums[front+1];
            auto diff = p1.first - p0.first;
            auto ops = min<ll>(diff,k/p0.second);
            if(ops==0) break;
            k-=ops*p0.second;
            p0.first += ops;
            if(p0.first==p1.first) {
                p1.second += p0.second;
                front++;
            }
        } else {
            auto& p0 = nums[back];
            auto& p1 = nums[back-1];
            auto diff = p0.first - p1.first;
            auto ops = min<ll>(diff,k/p0.second);
            if(ops==0) break;
            k-=ops*p0.second;
            p0.first -= ops;
            if(p0.first==p1.first) {
                p1.second += p0.second;
                back--;
            }
        }
    }

    cout  << nums[back].first - nums[front].first << endl;

    return 0;
}

