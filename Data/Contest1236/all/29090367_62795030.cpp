#include <bits/stdc++.h>

using namespace std;

int num[301][301];

int main(){
    int n;
    cin >> n;
    int cnt = 1;
    for(int i = 1; i <= n; ++i) {
        if(i&1) {
            for(int j = 1; j <= n; ++j) {
                num[j][i] = cnt++;
            }
        } else {
            for(int j = n; j >= 1; --j) {
                num[j][i] = cnt++;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            printf("%d", num[i][j]);
            if(j != n) {printf(" ");}
        }
        puts("");
    }
    return 0;
}
