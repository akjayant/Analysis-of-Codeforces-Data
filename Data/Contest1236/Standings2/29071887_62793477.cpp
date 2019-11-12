#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1)
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> ans[n + 1];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for(int i = 1; i <= n; i++){
        pq.push({0, i});
    }
    for(int i = n * n - 1; i >= 0; i--){
        pair<int, int> x = pq.top();
        pq.pop();
        ans[x.second].push_back(i + 1);
        x.first += i;
        pq.push(x);
    }
    for(int i = 1; i <= n; i++){
        for(auto it : ans[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
