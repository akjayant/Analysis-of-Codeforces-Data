#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

char sn[11000];
char tn[11000];

int main()
{
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s%s",sn,tn);
        int num = 0;
        int a,b;
        for(i = 0;i<n;i++)
        {
            if(sn[i]!=tn[i])
            {
                num++;
                if(num == 3) goto w;
                if(num == 1) a = i;
                else b = i;
            }
        }
        if(num == 1) goto w;
        if(sn[a] == sn[b]&&tn[a] == tn[b])
        {
            cout<<"Yes"<<endl;
            continue;
        }
        w: cout<<"No"<<endl;
    }
    return 0;
}
