#include<bits/stdc++.h>
#define ll long long
#define zp push_back
#define zm make_pair
#define zl lower_bound
#define z1 first
#define z2 second
using namespace std;
int z(){int z;scanf("%d",&z);return z;}
ll Z(){ll Z;scanf("%I64d",&Z);return Z;}

const int M = 5e5+5;
int a[M], n, m, k;
int sta[M], top;
char c[M];

int main(){
    int t;t = z();
    while(t --){
        n = z();
        scanf("%s", c+1);
        int t = -1;
        for(int i=1;i<=n;i++){
            if(c[i]=='1'){
                int x = max(i, n+1-i);
                if(t<x) t = x;
            }
        }
        printf("%d\n", max(n, 2*t));
    }
}
