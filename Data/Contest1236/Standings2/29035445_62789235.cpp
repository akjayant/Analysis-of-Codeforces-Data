#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int add(int a, int b){
    a += b;
    if(a >= M) a -= M;
    if(a < 0) a += M;
    return a;
}

int mul(int a, int b){
    return a * (long long)b % M;
}

int bin(int a, int b){
    int res = 1;
    while(b > 0){
        if(b % 2 == 0){
            a = mul(a, a);
            b /= 2;
        }
        else{
            res = mul(res, a);
            --b;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int k = bin(2, m);

    cout << bin(k - 1, n);
}
