#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)(1e7))
#define MAX_X ((int)(1e6 + 2))
#define pi (2.0*acos(0))
#define M ((ll)(1e9 + 7))
#define NN ((ll)(305))
#define N ((int)(1e6 + 5))
#define eps (0)
#define log 20


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;


typedef tree < ll,  null_type,  less < ll >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;


int dpp[105][105][105];

int call(int a , int b , int c)
{
    if(a<0 || b<0 || c<0) return -MAX;
    if(dpp[a][b][c]!=-1) return dpp[a][b][c];
    int ans = 0;
    ans = max(ans,call(a-1,b-2,c)+3);
    ans = max(ans,call(a,b-1,c-2)+3);

    return dpp[a][b][c] = ans;

}

int main()
{
    memset(dpp,-1,sizeof dpp);
    int t;
    scanf("%d",&t);
    while(t--){
        int a,  b , c;
        scanf("%d %d %d",&a,&b,&c);
        printf("%d\n",call(a,b,c));
    }
    return 0;
}
