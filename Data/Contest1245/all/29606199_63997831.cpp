#pragma GCC optimize("O3")
#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////


int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b, a % b);
}
int T;
int i,j,k;
int main(){
    scanf("%d", &T);
    fornum(i,0,T){
        int a, b;
        scanf("%d%d", &a, &b);
        if(gcd(a,b)==1){
            printf("Finite\n");
        }else{
            printf("Infinite\n");
        }
    }
    return 0;
}