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

const int MAXN=1e5;
int L[MAXN];

int main(void){
//    freopen("in.txt","r",stdin);
    int N;
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++) scanf("%d",&L[i]);
        sort(L,L+N);
        int s=0,l=0;
        for(int i=0;i<N/2;i++) s+=L[i];
        for(int i=N/2;i<N;i++) l+=L[i];
        printf("%I64d\n",ll(s)*ll(s)+ll(l)*ll(l));
    }
    return 0;
}

/*
inputCopy
3
1 2 3
outputCopy
26
inputCopy
4
1 1 2 2
outputCopy
20
*/
