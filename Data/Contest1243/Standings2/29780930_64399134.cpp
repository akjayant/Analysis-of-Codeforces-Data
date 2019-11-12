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
char str1[60], str2[60];
int get_count(char str[], int a, char c)
{
    int ans=0;
    for(int i=a; i<=n; i++)
        if(str[i]==c)ans++;
    return ans;
}
int get_first(char str[], int a, char c)
{
    int ans=0;
    for(int i=a; i<=n; i++)
        if(str[i]==c)return i;
    return -1;
}
int main()
{
    scanf("%d", &q);
    for(int u=1; u<=q; u++){
        re=0;
        scanf("%d", &n);
        memset(str1, 0, sizeof(str1));
        memset(str2, 0, sizeof(str2));
        scanf("%s %s", str1+1, str2+1);
        memset(num, 0, sizeof(num));
        for(int i=1; i<=n; i++){
            num[str1[i]-'a'+1]++;
            num[str2[i]-'a'+1]++;
        }
        bool flag=false;
        for(int i=1; i<=26; i++){
            if(num[i]%2)flag=true;
        }
        if(flag){
            puts("No");
            continue;
        }
        for(int i=1; i<=n; i++){
            if(str1[i]==str2[i])continue;
            if(get_first(str1, i+1, str1[i])!=-1){
                int temp=get_first(str1, i+1, str1[i]);
                print[++re]=mp(temp, i);
                swap(str1[temp], str2[i]);
                continue;
            }
            int temp=get_first(str2, i+1, str1[i]);
            print[++re]=mp(temp, temp);
            swap(str1[temp], str2[temp]);
            print[++re]=mp(temp, i);
            swap(str1[temp], str2[i]);
        }
        printf("Yes\n%d\n", re);
        for(int i=1; i<=re; i++){
            printf("%d %d\n", print[i].F, print[i].S);
        }
    }
}
