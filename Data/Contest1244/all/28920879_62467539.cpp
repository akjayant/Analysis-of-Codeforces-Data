#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string x;
        cin>>n>>x;
        int mx=n;
        for(int i=0;i<n;i++)
        {
            if(x[i]=='1')
            {
                mx=max(mx,(i+1)*2);
            }
        }
        for(int i=n-1;i>=0;i--)
        {   int o=n-i;
            if(x[i]=='1')
            {
                mx=max(mx,(o*2));
            }
        }
        cout<<mx<<endl;

    }

    return 0;
    }
//
