#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cmath>
#include<string>
#include<set>
#include<complex>
#include<cstdio>
#include<cstring>
#include<stack>
#include<iomanip>
#include<bitset>
#include<typeinfo>
#include<random>
#include<unordered_map>
#include<unordered_set>

using namespace std;

const int maxn = 3e2 + 10;

int n;
int a[maxn][maxn];

int main(){
    scanf("%d", &n);
    int cnt = n * n;
    for(int j = 1; j <= n; j++){
        if(j % 2== 0){
            for(int i = n; i >= 1; i--){
                a[i][j] = cnt;
                cnt--;
            }
            
        }
        else{
            for(int i = 1; i <= n; i++){
                a[i][j] = cnt;
                cnt--;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}