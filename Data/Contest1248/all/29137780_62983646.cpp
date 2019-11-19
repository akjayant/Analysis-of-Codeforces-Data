// Created by sz
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    
    ll l1 = 0, l2 = 0;
    int mid = n/2;
    for (int i = 0; i < mid; i++){
        l1 += a[i];
    }
    for (int i = mid; i < n; i++){
        l2 += a[i];
    }
    cout << l1*l1 + l2 * l2 << "\n";
    
    
    
    return 0;
}
