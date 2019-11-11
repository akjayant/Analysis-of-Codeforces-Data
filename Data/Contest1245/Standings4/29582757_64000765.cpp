#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
char all[100005];
bool have[100005];
long long DP[100005];
long long MOD=1e9+7;
long long F(long long here)
{
    if(all[here]=='\0') return 1;
    if(have[here]) return DP[here];
    have[here]=1;
    DP[here]=F(here+1);
    if(all[here]=='n'&&all[here+1]=='n'||all[here]=='u'&&all[here+1]=='u') DP[here]+=F(here+2);
    DP[here]%=MOD;
    return DP[here];
}
int main()
{
    long long ok=1,i;
    scanf("%s",all);
    for(i=0;all[i]!='\0';i++)
    {
        if(all[i]=='m'||all[i]=='w') ok=0;
    }
    if(ok)
    {
        printf("%lld\n",F(0));
    }
    else printf("0\n");
	return 0;
}
