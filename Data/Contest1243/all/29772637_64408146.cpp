#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 10010
int K,N;
char s[MAX], t[MAX];
int cnt[26];
queue<int> qs,qt;

int main()
{
    scanf("%d",&K);
    for(int ii=0;ii<K;ii++)
    {
        scanf("%d",&N);
        scanf("%s",s);
        scanf("%s",t);
        for(int i=0; i<26; i++)cnt[i]=0;

        for(int i=0;i<N;i++)
        {
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        int w=0;
        for(int i=0;i<26;i++)
        {
            if(cnt[i]%2==1)
            {
                w=1;
                break;
            }
        }
        if(w==1)
        {
            printf("NO\n");
            continue;
        }

        printf("YES\n");

        int m=0;
        for(char c='a';c<='z';c++)
        {
            if(cnt[c-'a']==0)continue;

            int rec=0;
            char tmps, tmpt;
            int status=0;

            for(int i=0;i<N;i++)
            {
                tmps=s[i], tmpt=t[i];

                if(tmps==c && tmpt==c)continue;
                else if(tmps==c)
                {
                    if(status==0)rec=i,status=1;
                    else if(status==1)
                    {
                        qs.push(i), qt.push(rec);
                        swap(s[i], t[rec]);
                        status=0;
                        m++;
                    }
                    else if(status==2)
                    {
                        qs.push(i), qt.push(i);
                        qs.push(rec), qt.push(i);
                        swap(s[i],t[i]);
                        swap(s[rec],t[i]);
                        status=0;
                        m+=2;
                    }
                }
                else if(tmpt==c)
                {
                    if(status==0)rec=i,status=2;
                    else if(status==1)
                    {
                        qs.push(i), qt.push(i);
                        qs.push(i), qt.push(rec);
                        swap(s[i],t[i]);
                        swap(s[i],t[rec]);
                        status=0;
                        m+=2;
                    }
                    else if(status==2)
                    {
                        qs.push(rec), qt.push(i);
                        swap(s[rec], t[i]);
                        status=0;
                        m++;
                    }
                }
            }
        }

        printf("%d\n",m);
        while(!qs.empty())
        {
            printf("%d %d\n",qs.front()+1,qt.front()+1);
            qs.pop(), qt.pop();
        }
    }
    return 0;
}