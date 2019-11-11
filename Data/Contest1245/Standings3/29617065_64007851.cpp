#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
char s[N];
int n,a,b,c;
int sp,ss,sr;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>a>>b>>c;
        sr=sp=ss=0;
        scanf("%s",s);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')sr++;
            if(s[i]=='S')ss++;
            if(s[i]=='P')sp++;
        }
        int tr=min(sr,b),ts=min(ss,a),tp=min(sp,c);
        int lr=b-tr,ls=a-ts,lp=c-tp;
        int ans = tr+ts+tp;
        if(ans>=(n+1)/2)
        {
            puts("YES");
            for(int i=0;i<n;i++)
            {
                if(s[i]=='R'){
                    if(tr){
                        putchar('P');
                        tr--;
                        //lr--;
                    }
                    else if(ls)
                    {
                        putchar('R');
                        ls--;
                    }
                    else
                    {
                        putchar('S');
                        lp--;
                    }
                }
                if(s[i]=='S'){
                    if(ts){
                        putchar('R');
                        ts--;
                    }
                    else if(lr) {
                        putchar('P');
                        lr--;
                    }
                    else {
                        putchar('S');
                        lp--;
                    }
                }
                if(s[i]=='P'){
                    if(tp){
                        putchar('S');
                        tp--;
                    }
                    else if(lr)
                    {
                        putchar('P');
                        lr--;
                    }
                    else
                    {
                        putchar('R');
                        ls--;
                    }
                }
            }
            puts("");
        }
        else puts("NO\n");
    }
    return 0;
}
