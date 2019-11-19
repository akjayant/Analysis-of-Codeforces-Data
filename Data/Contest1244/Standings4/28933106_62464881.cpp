
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;

int inf = 0x3f3f3f3f;
typedef long long ll;
ll linf = 0x3f3f3f3f3f3f3f3f;

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
	int a,b,c,d,k;
	scanf("%d%d%d%d%d", &a, &b,&c,&d,&k);
	int x = a/c+!!(a%c);
	int y = b/d+!!(b%d);
	if(x+y>k){
	    printf("-1\n");
	    continue;
	}
	printf("%d %d\n", x,y);
    }


    
    return 0;
}
