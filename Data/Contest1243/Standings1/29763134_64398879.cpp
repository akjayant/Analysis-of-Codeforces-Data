#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long

char sn[11000];
char tn[11000];
void swap(char &a,char &b)
{
    char t = a;
    a = b;
    b = t;
}
int sp[1100][2];

int main()
{
    int t,i,j,k;
    //cin>>t;
    //while(t--)
    {
        ll n;
        cin>>n;
        int tmp = sqrt(n+1);
        int num = 0;
        ll ans = -1;
        for(i = 2;i<=tmp;i++)
        {
            if(n%i == 0)
            {
                num++;
                ans = i;
                while(n%i == 0) n/=i;
            }
        }
        if(n!=1)
        {
            num++;
            ans = n;
        }
        if(num == 1) cout<<ans<<endl;
        else cout<<1<<endl;

    }
    return 0;
}
