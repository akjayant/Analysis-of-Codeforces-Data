#include <cstdio>
#define MAX 10010
int K,N;
char s[MAX], t[MAX];

int main()
{
    scanf("%d",&K);
    for(int ii=0;ii<K;ii++)
    {
        scanf("%d",&N);
        scanf("%s",s);
        scanf("%s",t);

        int cnt=0,id[2];
        for(int i=0;i<N;i++)
        {
            if(s[i]!=t[i])id[cnt++]=i;
            if(cnt>2)break;
        }

        if(cnt==2 && s[id[0]]==s[id[1]] && t[id[0]]==t[id[1]])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}