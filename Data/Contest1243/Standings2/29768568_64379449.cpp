#include <bits/stdc++.h>
#define ls rt*2
#define rs rt*2+1
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int vis=0;
        char q1,q2,q3,q4;
        for(int i=0; i<n; i++)
            if(s1[i]!=s2[i])
            {
                if(vis==0)
                {
                    vis++;
                    q1=s1[i],q2=s2[i];
                }
                else
                {
                    vis++;
                    q3=s1[i],q4=s2[i];
                }
            }
        if(vis>2||vis==1)
            cout<<"NO"<<endl;
        else
        {
            if(vis==0)
            {
                 cout<<"YES"<<endl;
            }
            else if(q1==q3&&q2==q4)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
}
