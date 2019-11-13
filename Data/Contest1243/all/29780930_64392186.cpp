#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const LL llinf=987654321987654321;
const int inf=987654321;
int q, n, num[60], re;
pii print[200];
char str1[100010], str2[100010];
set<int> num1[30], num2[30];
int main()
{
    scanf("%d", &q);
    for(int u=1; u<=q; u++){
        scanf("%d", &n);
        scanf("%s %s", str1+1, str2+1);
        int diffnum[2], diff=0, ans=1;
        diffnum[0]=1;
        diffnum[1]=1;
        for(int i=1; i<=n; i++){
            if(str1[i]!=str2[i]){
                diff++;
                if(diff==1)diffnum[0]=i;
                else diffnum[1]=i;
            }
        }
        if(diff==0){
            puts("Yes");
            continue;
        }
        if(diff==2&&str1[diffnum[0]]==str1[diffnum[1]]&&str2[diffnum[0]]==str2[diffnum[1]]){
            puts("Yes");
            continue;
        }
        puts("No");
    }
}
