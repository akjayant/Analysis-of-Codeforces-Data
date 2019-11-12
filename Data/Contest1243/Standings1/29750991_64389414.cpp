#include<bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=50+10;
char s[N],t[N];
int bs[26],bt[26];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        mset(bt,0);
        mset(bs,0);
        for(int i=1; i<=n; ++i)
            bt[t[i]-'a']++,bs[s[i]-'a']++;
        bool ok=true;
        for(int i=0; i<26; ++i)
        {
            if((bt[i]+bs[i])%2==1)
            {
                ok=false;
                break;
            }
        }
        if(!ok)
        {
            printf("No\n");
            continue;
        }
        vector<pair<int,int> > op;
        for(int i=1; i<=n; ++i)
        {
            if(s[i]==t[i]) continue;
            int id=-1;
            for(int j=i+1; j<=n; ++j)
            {
                if(t[j]==s[i])
                {
                    id=j;
                    break;
                }
            }
            if(id!=-1)
            {
                op.push_back(make_pair(i+1,id));
                swap(s[i+1],t[id]);
                op.push_back(make_pair(i+1,i));
                swap(s[i+1],t[i]);
            }
            else{
                for(int j=i+1;j<=n;++j)
                {
                    if(s[j]==s[i])
                    {
                        id=j;
                        break;
                    }
                }
                swap(s[id],t[i]);
                op.push_back(make_pair(id,i));
            }


        }
        printf("Yes\n");
        printf("%d\n",int(op.size()));
        for(pair<int,int> p:op)
        {
            printf("%d %d\n",p.first,p.second);
        }
//        printf("s:%s,t:%s\n",s+1,t+1);
    }
}
