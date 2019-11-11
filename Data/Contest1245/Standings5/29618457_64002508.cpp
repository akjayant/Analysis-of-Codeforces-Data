#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        int x=__gcd(a,b);
        if(x==1)puts("Finite");
        else puts("Infinite");
    }
    return 0;
}