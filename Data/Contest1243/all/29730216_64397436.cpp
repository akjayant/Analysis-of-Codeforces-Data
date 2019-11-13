#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s1[100], s2[100];
int a[30];
int sum[110][2];
int main()
{
    int t, len;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<30; i++)
            a[i]=0;
        cin>>len;
        cin>>s1+1>>s2+1;
        for(int i=1; i<=len; i++)
        {
            a[s1[i]-'a']++;
            a[s2[i]-'a']++;
        }
        int flag=1;
        for(int i=0; i<30; i++)
            if(a[i]%2==1) flag=0;
        if(flag==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        int cnt=0;
        for(int i=1; i<=len; i++)
        {
            if(s1[i]!=s2[i])
            {
                int flag=0, id=0;
                for(int j=i+1; j<=len; j++)
                    if(s1[j]==s1[i])
                    {
                        flag=1;
                        id=j;
                        break;
                    }
                if(flag==1) sum[cnt][0]=id, sum[cnt][1]=i, cnt++, swap(s1[id], s2[i]);
                else
                {
                    for(int j=i+1; j<=len; j++)
                        if(s2[j]==s1[i])
                        {
                            sum[cnt][0]=i+1, sum[cnt][1]=j, cnt++, swap(s1[i+1], s2[j]);
                            sum[cnt][0]=i+1, sum[cnt][1]=i, cnt++, swap(s1[i+1], s2[i]);
                            break;
                        }
                }
            }
        }
        cout<<cnt<<"\n";
        for(int i=0; i<cnt; i++)
            cout<<sum[i][0]<<" "<<sum[i][1]<<"\n";
    }
    return 0;
}
