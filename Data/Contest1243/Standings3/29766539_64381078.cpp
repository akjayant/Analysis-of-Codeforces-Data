#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = pow(10,9)+7;

int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int flag=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i])
                continue;
            else
            {
                flag=i;
                break;
            }
        }
        if(flag==-1)
            cout<<"Yes"<<endl;
        else
        {
            char a=s[flag];
            char b=t[flag];
            int flag2=-1;
            for(int i=flag+1;i<n;i++)
            {
                if(s[i]!=t[i])
                {
                    if(flag2==-1)
                        flag2=i;
                    else
                        flag2=-2;
                }
                
            }
            if(flag2==-2)
                cout<<"No"<<endl;
            else
            {
                t[flag]=s[flag2];
                s[flag2]=b;
                if(s==t)
                    cout<<"Yes"<<endl;
                else
                    cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
