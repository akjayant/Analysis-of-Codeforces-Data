#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pcc pair<char,char>
using namespace std;
const int maxn=1e4+7;
char s[maxn],t[maxn];
vector<pcc>ve;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        scanf("%s %s",t+1,s+1);
        for(int i=1;i<=n;i++){
            if(s[i]!=t[i])ve.push_back({s[i],t[i]});
        }
        if(ve.size()==0){
            printf("Yes\n");
            ve.clear();
            continue;
        }
        if(ve.size()==2){
            //swap(ve[0].first,ve[0].second);
            if(ve[0]==ve[1]){
                printf("Yes\n");
                ve.clear();
                continue;
            }
        }
        printf("No\n");
        ve.clear();
    }
    return 0;
}
