#include <bits/stdc++.h>
using namespace std;
char str[1010],ans[1010];
int main()
{
    int T;
    cin>>T;
    while(T--)
	{
        int n,a,b,c;
        cin>>n;
		cin>>a>>b>>c;
		cin>>str;
        for(int i=0;i<1010;i++)
        	ans[i]=str[i];
        int cnt=0;
        for(int i=0;i<n;i++)
		{
            if(str[i]=='R')
			{
                if(b){b--;ans[i]='P';cnt++;}
                else ans[i]='1';
            }
            if(str[i]=='P')
			{
                if(c){c--;ans[i]='S';cnt++;}
                else ans[i]='1';
            }
            if(str[i]=='S')
			{
                if(a){a--;ans[i]='R';cnt++;}
                else ans[i]='1';
            }
        }
        if(cnt>=((n+1)/2))
		{
            for(int i=0;i<n;i++)
			{
                if(ans[i]=='1')
				{
                    if(a){a--;ans[i]='R';}
                    else if(b){b--;ans[i]='P';}
                    else {c--;ans[i]='S';}
                }
            }
            puts("YES");
            cout<<ans<<endl;
        }
        else
        	puts("NO");
    }
    return 0;
}