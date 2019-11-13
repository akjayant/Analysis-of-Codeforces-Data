
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v;
long long poww[200005];
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    string s;
    a=1;b=1;
    poww[0]=1;
    for(i=1; i<150000; i++)
    {
        poww[i]=a;
        c=a;
        a+=b;
        b=c;
        a%=pi;
        b%=pi;
    }
    cin>>s;
    s.push_back('$');
    n=s.size();
    a=0;
    b=0;
    f=1;
    for(i=0; i<n; i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0;
            return 0;
        }
        if(s[i]=='n')
        {
            a++;
        }
        else
        {
            f*=poww[a];
            f%=pi;
            a=0;
        }
        if(s[i]=='u')
        {
            b++;
        }
        else
        {
            f*=poww[b];
            b=0;
            f%=pi;
        }
    }
    cout<<f<<'\n';
    //main();
    return 0;
}
