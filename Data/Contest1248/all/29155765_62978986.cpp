#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define x first
#define y second

using namespace std;

int main()
{
    //freopen("test.in","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        int n1,n2; cin>>n1;
        ll p1[2]={0,0}, p2[2]={0,0};
        for(int i=0;i<n1;i++)
        {
            int j; cin>>j;
            p1[j%2]++;
        }
        cin>>n2;
        for(int i=0;i<n2;i++)
        {
            int j; cin>>j;
            p2[j%2]++;
        }
        cout<<p1[0]*p2[0]+p1[1]*p2[1]<<'\n';
    }
}
