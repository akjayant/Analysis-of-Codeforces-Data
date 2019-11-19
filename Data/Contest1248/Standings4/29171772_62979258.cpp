#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, m, q, p, odd, even;
int main(){
    cin >> t;
    while(t--){
        odd = even = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &p);
            if(p%2)
             ++odd;
            else
                ++even;
        }
        scanf("%d", &m);
        long long ans = 0;
        for(int i = 0; i < m; i++){
            scanf("%d", &q);
            if(q %2)
                ans += odd;
            else
                ans += even;
        }
        printf("%lld\n", ans);
    }
}