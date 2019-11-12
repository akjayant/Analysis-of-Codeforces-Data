/**
Code by Nitin1184
**/
# include <bits/stdc++.h>
# define ll long long
# define pi 3.14159265358979323846
# define M 1000000007
# define pb push_back
# define mp make_pair
# define ff first
# define ss second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,min(a[i],n-i));
        cout<<ans<<endl;
    }
    return 0;
}