#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll MAXN = 2e2 + 10;
const ll mod = 998244353;
const ll inf = 1e18;
const ll mo = 1e9+7;

char s[MAXN];
char t[MAXN];
struct node
{
    int l,r;
} a[MAXN];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,tot = 0,ff = 1;
        cin>>n;
        map<char,int>mp;
        mp.clear();
        scanf("%s%s",s+1,t+1);
        for(int i=1; i<=n; i++)
        {
            mp[s[i]] ++;
            mp[t[i]] ++;
        }
        for(int i=0; i<26; i++)
        {
            if(mp['a' + i] & 1)
            {
                ff = 0;
                break;
            }
        }
        if(ff == 0)
            printf("No\n");
        else
        {
            for(int i=1; i<=n; i++)
            {
//                printf("%s\n",s+1);
//                printf("%s\n",t+1);
//                putchar(10);
                if(s[i] != t[i])
                {
                    int flag = 0;
                    for(int j=i+1; j<=n; j++)
                    {
                        if(t[j] == t[i])
                        {
                            flag = 1;
                            t[j] = s[i];
                            a[tot].l = i,a[tot].r = j;
                            tot ++;
                            break;
                        }
                    }
                    if(flag == 0)
                    {
//                        printf("t[i] = %c\n",t[i]);
                        for(int j=i+1; j<=n; j++)
                        {
                            if(s[j] == t[i])
                            {
//                                printf("j = %d\n",j);
                                a[tot].l = j,a[tot].r = j;
                                tot ++;
                                swap(s[j],t[j]);
                                t[j] = s[i];
                                a[tot].l = i,a[tot].r = j;
                                tot ++;
                                break;
                            }
                        }
                    }
                }
            }
            printf("Yes\n");
            printf("%d\n",tot);
            for(int i=0;i<tot;i++)
                printf("%d %d\n",a[i].l,a[i].r);
        }
    }
}
/*
5
4
accb
bacc
*/
