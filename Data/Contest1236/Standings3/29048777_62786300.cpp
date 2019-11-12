#include<bits/stdc++.h>

using namespace std;
void testt()
{
    int a,b,c,s=0;
    cin>>a>>b>>c;
    if(c/2>b)
    {
        s+=3*b;
        cout<<s<<'\n';
        return ;
    }
    else
    {
        s+=3*(c/2);
        b-=c/2;
    }
    if(b/2>a)
        s+=3*a;
    else
        s+=3*(b/2);
    cout<<s<<'\n';
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        testt();
    return 0;
}
