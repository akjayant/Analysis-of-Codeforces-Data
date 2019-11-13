#include <bits/stdc++.h>
#define ls rt*2
#define rs rt*2+1
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
char q1[100],q2[100];
int id[100],id2[100];
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
//        char q1,q2,q3,q4;
        int num[30]= {0};
        for(int i=0; i<n; i++)
            if(s1[i]!=s2[i])
            {
                q1[++vis]=s1[i];
                id[vis]=i;
                q2[vis]=s2[i];
//                id2[vis]=i;
                num[s1[i]-'a']++,num[s2[i]-'a']++;
            }
        int mm=0;
        for(int i=0; i<26; i++)
            if(num[i]%2)
                mm=1;
        if(mm==1)
            cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;
            int ans[1000][3];
            int num1=0;
            for(int i=1; i<=vis; i++)
            {
                if(q1[i]==q2[i])
                    continue;
                for(int j=i+1; j<=vis; j++)
                {
                    if(q1[i]==q1[j])
                    {
                        ans[++num1][0]=id[j];
                        ans[num1][1]=id[i];
                        swap(q1[j],q2[i]);
                        break;
                    }
                }
                if(q1[i]==q2[i])
                    continue;
                for(int j=i+1; j<=vis; j++)
                {
                    if(q1[i]==q2[j])
                    {
                        ans[++num1][0]=id[i+1];
                        ans[num1][1]=id[j];
                        swap(q1[i+1],q2[j]);
                        ans[++num1][0]=id[i+1];
                        ans[num1][1]=id[i];
                        swap(q1[i+1],q2[i]);
                        break;
                    }
                }
            }
            cout<<num1<<endl;
            for(int i=1;i<=num1;i++)
                cout<<ans[i][0]+1<<" "<<ans[i][1]+1<<endl;
        }

    }
}
