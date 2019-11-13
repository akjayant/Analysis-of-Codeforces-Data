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
        int f[55]={};
        for(int i=0;i<n;++i)
        {
            ++f[str1[i]-'a'];
            ++f[str2[i]-'a'];
        }
        int flag=1;
        for(int i=0;i<26;++i)
        {
            if(f[i]%2)
            {
                flag=0;
                break;
            }
        }
        if(!flag)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
            vector<pair<int,int> >swaps;
            for(int i=0;i<n;++i)
            {
                if(str1[i]==str2[i])
                {
                    continue;
                }
                else
                {
                    char c=str1[i];
                    int Find=0;
                    for(int j=i+1;j<n;++j)
                    {
                        if(str1[j]==c)
                        {
                            swap(str1[j],str2[i]);
                            swaps.push_back({j+1,i+1});
                            Find=1;
                            break;
                        }
                    }
                    if(!Find)
                    {
                        c=str2[i];
                        for(int j=i+1;j<n;++j)
                        {
                            if(str2[j]==c)
                            {
                                swap(str1[i],str2[j]);
                                swaps.push_back({i+1,j+1});
                                Find=1;
                                break;
                            }
                        }
                    }
                    if(!Find)
                    {
                        swap(str1[i],str2[i]);
                        swaps.push_back({i+1,i+1});
                        char c=str2[i];
                        for(int j=i+1;j<n;++j)
                        {
                            if(str2[j]==c)
                            {
                                swap(str1[i],str2[j]);
                                swaps.push_back({i+1,j+1});
                                break;
                            }
                        }
                    }
                }
            }
            printf("%d\n",swaps.size());
            for(int i=0;i<swaps.size();++i)
            {
                printf("%d %d\n",swaps[i].f,swaps[i].s);
            }
        }
    }
    return 0;
}

