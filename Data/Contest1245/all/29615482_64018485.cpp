#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double db;
const int mod =1e9+7;
const int maxn = 1e5+100;
const db eps = 1e-6;

char str[maxn];
LL fib[maxn];
vector<int > ve;
int main()
{
    scanf("%s", str);
    int len = strlen(str);
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i <= len+10; i++)
    {
        fib[i] = (fib[i-1]+fib[i-2])%mod;
    }
    int cntu = 0, cntn = 0;
    int flag = 1;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == 'u')
        {
            cntu++;
            if(cntn!=0)
            {
                ve.push_back(cntn);
                cntn = 0;
            }
        }
        else if(str[i] == 'n')
        {
            cntn++;
            if(cntu!=0)
            {
                ve.push_back(cntu);
                cntu = 0;
            }
        }
        else
        {
            if(str[i]=='m'||str[i]=='w')
            {
                flag  = 0;
                break;
            }
            else
            {
                if(cntu!=0)
                {
                    ve.push_back(cntu);
                    cntu = 0;
                }
                if(cntn != 0)
                {
                    ve.push_back(cntn);
                    cntn = 0;
                }
            }
        }
    }
    if(cntu!=0)
    {
        ve.push_back(cntu);
        cntu = 0;
    }
    if(cntn != 0)
    {
        ve.push_back(cntn);
        cntn = 0;
    }
    if(!flag)
    {
        printf("0\n");
    }
    else
    {
        LL ans = 1;
        int siz = ve.size();
        for(int i = 0; i < siz; i++)
        {
            ans = ans*fib[ve[i]+1]%mod;
        }
        printf("%lld\n", ans);
    }




    return 0;
}
