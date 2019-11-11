#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define pb push_back
#define dubug(x) cout<<"***"<<(x)<<endl
typedef long long ll;
typedef unsigned long long ULL;
using namespace std;
const int maxn = 1e6+7;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;


int R,P,S;
char a[maxn];
char b[maxn];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        scanf("%d %d %d", &R, &P,&S);
        scanf("%s",a+1);
        for(int i = 1; i <= n; i++){
            b[i]='$';
            if(a[i]=='R'){
                if(P){b[i]='P';P--;}
            }
            if(a[i]=='P'){
                if(S){b[i]='S';S--;}
            }
            if(a[i]=='S'){
                if(R){b[i]='R';R--;}
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(b[i]=='$'){
                if(P){b[i]='P';P--;}
                else if(S){b[i]='S';S--;}
                else {b[i]='R';R--;}
            }
            else ans++;
        }b[n+1]=0;
        if(ans>=(n+1)/2){
            printf("YES\n");
            printf("%s\n",b+1);
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
/*

*/
