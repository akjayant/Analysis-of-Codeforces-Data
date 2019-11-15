#include<bits/stdc++.h>
#define ll long long
#define zp push_back
#define zm make_pair
#define zl lower_bound
#define z1 first
#define z2 second
using namespace std;
int z(){int z;scanf("%d",&z);return z;}
int Z(){long long Z;scanf("%I64d", &Z);return Z;}

const int M = 1e5+5;
int f[M];
const int mod = 1e9+7;
void inc(int&x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
int n;
char c[M];
void work(){
    scanf("%s", c+1);
    f[1] = 1, f[0] = 1;
    n = strlen(c+1);
    for(int i=1;i<=n;i++){
        if(c[i]=='m' || c[i]=='w'){
            puts("0");return ;
        }
    }
    for(int i=2;i<=n;i++){
        f[i] = f[i-1];
        if(c[i]=='u' && c[i-1]=='u') inc(f[i], f[i-2]);
        if(c[i]=='n' && c[i-1]=='n') inc(f[i], f[i-2]);
    }
    printf("%d\n", f[n]);
}

int main(){
    work();
}
