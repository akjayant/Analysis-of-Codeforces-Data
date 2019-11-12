#include <bits/stdc++.h>
using namespace std;
int cnt[30];
struct Node{
    int a,b;
}t[110];
int main()
{
    int K;
    cin>>K;
    while(K--)
    {
        int n;
        string s1,s2;
        cin>>n>>s1>>s2;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']++;
        }
        bool flag=true;
        for(int i=0;i<26;i++)
            if(cnt[i]&1)
            {
                flag=false;
                break;
            }
        if(flag)
        {
            cout<<"Yes"<<endl;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(s1[i]==s2[i]) continue;
                bool f=false;
                for(int j=i+1;j<n;j++)
                    if(s1[j]==s1[i])
                    {
                        char temp=s2[i];
                        s2[i]=s1[j];
                        s1[j]=temp;
                        t[++cnt]={j,i};
                        f=true;
                        break;
                    }
                if(!f)
                {
                    for(int j=i+1;j<n;j++)
                        if(s2[j]==s1[i])
                        {
                            char temp=s2[j];
                            s2[j]=s1[j];
                            s1[j]=temp;
                            t[++cnt]={j,j};
                            temp=s2[i];
                            s2[i]=s1[j];
                            s1[j]=temp;
                            t[++cnt]={j,i};
                            break;
                        }
                }
            }
            cout<<cnt<<endl;
            for(int i=1;i<=cnt;i++)
            {
                cout<<t[i].a+1<<" "<<t[i].b+1<<endl;
            }
        }
        else cout<<"No"<<endl;
    }
    return 0;
}