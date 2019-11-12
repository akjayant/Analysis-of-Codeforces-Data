#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int p[3];
int main ()
{
    int t,n,i,j;
    char a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>s1>>s2;
        p[0]=p[1]=-1;
        for(i=j=0;i<n&&j<3;i++)
            if(s1[i]!=s2[i])
                p[j++]=i;
        if(j%2||(j==2&&(s1[p[0]]!=s1[p[1]]||s2[p[0]]!=s2[p[1]])))
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}