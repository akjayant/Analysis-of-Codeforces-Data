#include <bits/stdc++.h>
using namespace std;

const int N = 300;
vector<int> G[N+10];

int main(){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (i&1) G[j].push_back((i-1)*n+j);
            else G[n-j+1].push_back((i-1)*n+j);
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < n; ++j){
            printf("%d", G[i][j]);
            if (j < n-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}