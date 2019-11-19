#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,a,b,c,d,x,y,t,q,s=0,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int P[n];
        long long sn1=0,sc1=0,sn2=0,sc2=0;
        for(int i=0; i<n; i++){cin>>P[i];if(P[i]%2==0)sn1++;else sc1++;}
        cin>>m;
        int Q[m];
        for(int i=0; i<m; i++){cin>>Q[i];if(Q[i]%2==0)sn2++;else sc2++;}
        cout<<sc1*sc2+sn1*sn2<<endl;
    }
}
