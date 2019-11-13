#include <bits/stdc++.h>

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
        int i1 = -1,i2 = -1;
        bool check = true;
        for(int i = 0;i<n;i++)
        {
            if(s1[i]!=s2[i]&&i1==-1)
            {
                i1 = i;
            }
            else if(s1[i]!=s2[i]&&i2==-1)
            {
                i2 = i;
            }
            else if(s1[i]!=s2[i])
            {
                check = false;
            }
        }
        if(!check||(i1!=-1&&i2==-1))
        {
            cout<<"No"<<endl;
            continue;
        }
        else if(i1==-1&&i2==-1)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            if(s1[i1]==s1[i2]&&s2[i1]==s2[i2])
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
