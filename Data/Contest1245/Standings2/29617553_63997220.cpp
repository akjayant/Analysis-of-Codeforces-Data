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
int n, k;
int gcd(int a,int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

void work(){
    int T;scanf("%d", &T);
    while(T --){
    scanf("%d%d", &n, &k);
    if(gcd(n, k)==1)puts("Finite");
    else puts("Infinite");
    }
}

int main(){
    work();
}
