/**
* Author : Xiuchen
* Date : 2019-11-01-22.31.35
* Description : 597 Div2 C
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
//const int maxn=;
int t,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        if(__gcd(a,b)==1) printf("Finite\n");
        else printf("Infinite\n");
    }
    return 0;
}
