#include<bits/stdc++.h>
#define M 100001
#define MAX 1000000000000000
#define mod 1000000007
#define ss second
#define ff first
#define ll long long int
#define pb push_back
#define ld double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<int>());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,min(i+1,a[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}