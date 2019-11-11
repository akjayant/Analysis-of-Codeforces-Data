#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

char str[105];

int main(int argc, char* argv[])
{
    int T;
    scanf("%d", &T);

    int t;
    for(t=0; t<T; t++) {
        int n,a,b,c;
        scanf("%d%d%d%d", &n, &a,&b,&c);
        scanf("%s", str);

        vector<int> ans(n,-1);
        int i;
        int cnt=0;
        for(i=0; i<n; i++) {
            if(str[i]=='R') {
                if(b>0) {
                    ans[i]=1; b--; cnt++;
                }
            }
            else if(str[i]=='P') {
                if(c>0) {
                    ans[i]=2; c--; cnt++;
                }
            }
            else {
                if(a>0) {
                    ans[i]=0; a--; cnt++;
                }
            }
        }
        if(cnt>=(n+1)/2) {
            printf("YES\n");
            for(i=0; i<n; i++) {
                if(ans[i]<0) {
                    if(a) {
                        ans[i]=0; a--;
                    }
                    else if(b) {
                        ans[i]=1; b--;
                    }
                    else if(c) {
                        ans[i]=2; c--;
                    }
                    else {
                        assert(false);
                    }
                }
            }
            for(i=0; i<n; i++) {
                if(ans[i]==0) printf("R");
                else if(ans[i]==1) printf("P");
                else printf("S");
            }
            printf("\n");
        }
        else {
            printf("NO\n");
        }
    }



    return 0;
}

