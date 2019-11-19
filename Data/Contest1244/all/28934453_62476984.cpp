#include<bits/stdc++.h>
using namespace std;
int used[1024];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n,ans=0,c=0,c1,ans1=0,f=0,l=0,i;
        cin>>n;
        cin>>s;
        for(i=0;i<n;i++)
        {
            if(s[i]=='1'){c++;if(c==1)f=i+1;l=i+1;}
        }
        if(c==0)
        {
            cout<<n<<endl;
        }
        else
        cout<<max(max(l+n-l+1,2*l),max(f+n-f+1,2*(n-f+1)))<<endl;
    }
    return 0;
}
