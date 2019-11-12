#include <bits/stdc++.h>
using namespace std;
static const int MAXN=26;
int cnt[MAXN+10];
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        string s1,s2;
        cin>>n>>s1>>s2;
        int pos1=-1,pos2=-1;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                cnt++;
                if(cnt==1) pos1=i;
                else if(cnt==2) pos2=i;
            }
            if(cnt>2)
            {
                cout<<"No"<<endl;
                break;
            }
        }
        if(cnt==1)
            cout<<"No"<<endl;
        else if(cnt==0)
        {
            
            cout<<"Yes"<<endl;
        }
        else if(cnt==2)
        {
            if(s1[pos1]==s1[pos2] && s2[pos1]==s2[pos2]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}