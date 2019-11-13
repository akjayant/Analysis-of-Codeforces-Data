#include<bits/stdc++.h>
#define pr(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define Toggle(n,i) (n^(1<<i))
#define Check(n,i) (n&(1<<i))
#define Set(n,i) (n|(1<<i))
#define Reset(n,i) (n&(~(1<<i)))
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define me(arr,val) memset(arr,val,sizeof arr)
#define inf 10e8
#define infl LLONG_MAX
#define mod 1000000007
#define f first
#define s second
#define  g(t,a)  (get<a>(t))
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//int dx[]={+1,-1,0,0};//vertical horizontal
//int dy[]={0,0,+1,-1};//vertical horizontal
//int dx[]={+1,+1,-1,-1,+2,-2,+2,-2};//knights move
//int dy[]={+2,-2,+2,-2,+1,+1,-1,-1};//knights move
//int dx[]={+1,-1,0,0,+1,+1,-1,-1};//vertical horizontal diagonal
//int dy[]={0,0,+1,-1,-1,+1,+1,-1};//vertical horizontal diagonal
using namespace std;
using namespace __gnu_pbds;
/*typedef tree<int, null_type,less<int>, rb_tree_tag,
             tree_order_statistics_node_update>indexed_set;
for set use above*/
typedef tree<pair<int,int>, null_type,less_equal<pair<int, int>>, rb_tree_tag,
tree_order_statistics_node_update> indexed_multiset;


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        char str1[n+5],str2[n+5];
        scanf("%s%s",str1,str2);
        int cnt=0,flag=1;
        char str1_f,str2_f,str1_s,str2_s;
        for(int i=0;i<n;++i)
        {
            if(str1[i]!=str2[i])
            {
                ++cnt;
                if(cnt==1)
                {
                    str1_f=str1[i];
                    str2_f=str2[i];
                }
                else if(cnt==2)
                {
                    str1_s=str1[i];
                    str2_s=str2[i];
                }
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag&&str1_f==str1_s&&str2_f==str2_s)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}



