#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        int a=-1, b=-1;
        for(int i=0; i<n; i++)
        {
            if(a==-1 && s[i]=='1')
            {
                a=i;
                b=i;
            }
            if(s[i]=='1') b=max(b, i);
        }
        int sum=0;
        if(a==-1 && b==-1) sum=n;
        else sum=max(2*(b+1), 2*(n-a));
        cout<<sum<<endl;
    }
    return 0;
}
