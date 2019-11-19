#include <bits/stdc++.h>
using namespace std;
int q,a,b,c,d,k,n;
string s;
int main()
{
    cin>>q;
    while(q--)
    {
        cin>>n;
        cin>>s;
        int f=-1,l=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(f==-1)
                    f=i;
                l=i;
            }
        }
        if(f==-1)
            cout<<n<<"\n";
        else 
            cout<<max(2*(l+1),2*(n-f))<<"\n";
    }
}
