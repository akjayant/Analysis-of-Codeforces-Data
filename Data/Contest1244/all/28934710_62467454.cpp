#include <bits/stdc++.h>
#define DIM 1007
#define INF 1000000007
using namespace std;
long long t,n;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        s = '#' + s;
        long long k = 0,lft = -1,rght = -1;
        for(int i = 1; i <= n; ++i)
        {
            k+=(s[i]=='1');
            if(s[i]=='1')
            {
                rght = i;
                if(lft==-1)
                    lft = i;
            }
        }
        if(k==0)
        {
            cout<<n<<endl;;
            continue;
        }
        cout<<max(n+k,max(rght*2,(n-lft+1)*2))<<endl;


    }

    return 0;
}
