#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fr first
#define sc second


int cnt[100];

char ch[100],s[100];

vector < pair < int,int > > vec;


int main()
{
    int test,t,i,j,k,a,b,c,x,y,z,n;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        scanf("%s%s", ch, s);
        for(i=0;i<n;i++)
        {
            a=ch[i]-'a';
            b=s[i]-'a';
            cnt[a]++;
            cnt[b]++;
        }
        z=0;
        for(i=0;i<26;i++)
        {
            if(cnt[i]%2==1)
            {
                z=1;
            }
            cnt[i]=0;
        }
        if(z)
        {
            printf("No\n");
            continue;
        }
        for(i=0;i<n;i++)
        {
            if(ch[i]==s[i])
            {
                continue;
            }
            z=0;
            for(j=i+1;j<n;j++)
            {
                if(ch[i]==ch[j])
                {
                    vec.pb(mp(j,i));
                    swap(s[i],ch[j]);
                    z=1;
                    break;
                }
            }
            if(z)
                continue;
            for(j=i+1;j<n;j++)
            {
                if(s[j]==ch[i])
                {
                    vec.pb(mp(i+1,j));
                    swap(ch[i+1],s[j]);
                    vec.pb(mp(i+1,i));
                    swap(ch[i+1],s[i]);
                    break;
                }
            }
        }
        printf("Yes\n");
        z=vec.size();
        printf("%d\n",z);
        for(i=0;i<z;i++)
        {
            printf("%d %d\n",vec[i].fr+1,vec[i].sc+1);
        }
        vec.clear();

    }
}
