#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        int t=__gcd(a,b);
        puts(t==1?"Finite":"Infinite");
    }
    return 0;
}
