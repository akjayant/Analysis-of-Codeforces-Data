#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char str[1005];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>str+1;
        int mi = 1000010,ma = -1;
        for(int i = 1; i <= n; i++)
        {
            if(str[i]=='1'&&i > ma)
                ma = i;
            if(str[i]=='1'&&i < mi)
                mi = i;
        }
        if(mi > 1000000)
            cout<<n<<endl;
        else
        {
            int a = ma*2;
            int b = (n-mi+1)*2;
            cout<<max(a,b)<<endl;
        }
    }
    return 0;
}
