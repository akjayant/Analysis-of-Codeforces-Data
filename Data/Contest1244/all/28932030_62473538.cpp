// by Balloons
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;
int n;
char s[10005];
int main(){
    int te;scanf("%d",&te);
    while(te --){
        scanf("%d",&n);scanf("%s",s+1);
        int x=1,y=1,ans=0,as=0;
        for(int i=1;i<=n;i++){
            if(s[i] == '1'){
                as = max(as,2*(n-i+1));
                as = max(as,2*i);
                as = max(as,n);
                ans += 2;
                x^=1;++y;
            }else ++ans, ++y;
        }
        printf("%d\n",max(ans,as));
    }
	
	return 0;
}
