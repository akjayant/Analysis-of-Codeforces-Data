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
        int n,cnt=0;
        bool ans = true;
        string s,t;
        cin>>n;
        cin>>s>>t;
        int i1=-1,i2=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i] != t[i])
            {
                cnt++;
                if(cnt == 1)
                    i1 = i;
                else if(cnt == 2)
                    i2 = i;
            }
        }
        if(cnt == 2)
        {
            if(s[i1]!=s[i2] || t[i1]!=t[i2])
                ans = false;
        }
        else if(cnt ==0){
            ans = true;
        }
        else
        {
            ans = false;
        }
        
        if(ans)
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }
        
        
    }
    return 0;
}