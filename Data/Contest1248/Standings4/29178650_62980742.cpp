//{Headers
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<string>
#include<algorithm>
#include<list>
#include<queue>
#include<deque>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<bitset>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair< int,int > pii;
#define mp(x,y) make_pair(x,y)
typedef long long ll;
//}

int main(void){
//    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M,t;
        ll ans=0;
        ll nOdd=0,nEven=0;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d",&t);
            if(t%2==1) nOdd++;
            else nEven++;
        }
        scanf("%d",&M);
        for(int i=0;i<M;i++){
            scanf("%d",&t);
            if(t%2==1) ans+=nOdd;
            else ans+=nEven;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

/*
3
3
1 3 2
2
0 3
1
1
1
1
1
2
1
1

3
1
0
*/
