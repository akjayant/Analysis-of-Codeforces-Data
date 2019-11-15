#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define zak ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 1e3 + 5, M = 1e5 + 5, mod = 1e9 + 7;

int main(){
    zak
    int n;
    scanf("%d", &n);
    vector <int> out[n];
    int now = 1, mov = 1, cnt = n * n, ptr = 0;
    while(cnt--){
//        cout << ptr << " " << now << " ";
        out[ptr].push_back(now++);
        ptr += mov;
//        cout << ptr << " " << now << "\n";
        if(ptr == n){
            ptr--;
            mov = -1;
        }
        if(ptr == -1){
            ptr++;
            mov = 1;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j : out[i]){
            printf("%d ", j);
        }
        puts("");
    }
}
