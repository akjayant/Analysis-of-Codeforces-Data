#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,p1=-1,p2=-1,flag=1;
        string s1,s2;
        cin>>n>>s1>>s2;
        for (int i=0;i<n;i++)
        {
            if (s1[i]!=s2[i])
            {
                if (p1==-1) p1=i;
                else if (p2==-1) p2=i;
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        if (flag==0 || p1*p2<0)
        {
            cout<<"NO\n";
            continue;
        }
        if (s1[p1]==s1[p2] && s2[p1]==s2[p2]) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
