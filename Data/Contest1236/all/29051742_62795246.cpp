#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int mod = (int)1e9 + 7;

ll ksm(ll x,ll y){
    ll res = 1;
    while(y){
        if(y%2){
            res = (res * x) % mod;
        }
        x = x * x % mod;
        y /= 2;
    }
    return res;
}

int ans[1000][1000];

int main()
{
    int n ;
    cin >> n;

    int cnt = 1;
    for(int j = 1;j<=n;j++){
        int id;
        if(j%2) id = 1;
        else id = n;

        while(id<=n && id){
            ans[id][j] = cnt++;
            if(j%2) id++;
            else id--;
        }

    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
