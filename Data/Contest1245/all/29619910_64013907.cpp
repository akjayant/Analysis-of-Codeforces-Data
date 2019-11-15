#include<bits/stdc++.h>
using namespace std;
string s;
long long fuck[101000],mod=1000000007,ans=1;
bool fake=false;
int main()
{
    fuck[1]=1;
    fuck[2]=2;
    for(int i=3;i<=100000;i++)
        fuck[i]=(fuck[i-1]+fuck[i-2])%mod;
    cin>>s;
    int fucking=0;
    for(int i=0;i<s.size();)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            fake=true;
            break;
        }
        else if(s[i]=='n')
        {
            while(i<s.size()&&s[i]=='n')
            {
                fucking++;
                i++;
            }
        }
        else if(s[i]=='u')
        {
            while(i<s.size()&&s[i]=='u')
            {
                fucking++;
                i++;
            }
        }
        else
            i++;
        if(fucking)
        {
            ans=(ans*fuck[fucking])%mod;
            fucking=0;
        }
    }
    if(fake)
        cout<<"0";
    else
        cout<<ans;
}
