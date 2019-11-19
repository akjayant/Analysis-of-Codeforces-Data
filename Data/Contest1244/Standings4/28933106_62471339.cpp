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
	int n;
	char s[2000];
	scanf("%d%s", &n, s);
	char *a = strchr(s, '1');
	char *b = strrchr(s, '1');
	if(a){
	    printf("%d\n", max(b-s+1,n-(a-s))*2);
	}else{
	    printf("%d\n", n);
	}
    }
    
    return 0;
}
