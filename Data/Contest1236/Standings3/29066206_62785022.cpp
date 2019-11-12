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


int main(int argc, char* argv[])
{
    int T;
    scanf("%d", &T);

    int t;
    for(t=0; t<T; t++) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        int cnt=MIN(b,c/2);
        b-=cnt;
        cnt +=MIN(a,b/2);

        printf("%d\n", cnt*3);
    }

    return 0;
}
