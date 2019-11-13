#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
char s[55], t[55];
int freq[30];
typedef pair<int, int>pi;
queue<pi>q;
int main()
{
    int ts, n;
    scanf("%d", &ts);
    while(ts--)
    {
        scanf("%d %s %s", &n, s, t);
        memset(freq, 0,sizeof freq);
        for(int i=0; i<n; i++)
            freq[ s[i]-'a' ]++, freq[ t[i]-'a' ]++;
        bool flag= 1;
        for(int i=0; i<26 && flag; i++)
            if(freq[i]&1)flag= 0;
        if(flag)
        {
            for(int i=0; i<n; i++)
            {
                if(s[i]!=t[i])
                {
                    int ind= -1;
                    for(int j=i+1; j<n; j++)
                        if(s[j]!=t[j] && s[i]==s[j])
                        {
                            ind= j;
                            swap(t[i], s[j]);
                            q.push({j, i});
                            break;
                        }
                    if(ind==-1)
                    {
                        for(int j=i+1; j<n; j++)
                            if(s[j]!=t[j] && t[i]==t[j])
                            {
                                ind= j;
                                swap(t[j], s[i]);
                                q.push({i, j});
                                break;
                            }
                    }
                    if(ind==-1)
                    {
                        for(int j=i+1; j<n; j++)
                            if(t[j]!=s[j] && s[i]==t[j])
                            {
                                ind= 0;
                                swap(s[j], t[j]);
                                q.push({j, j});
                                swap(s[j],t[i]);
                                q.push({j, i});
                                break;
                            }
                    }
                    if(ind==-1)
                    {
                        for(int j=i+1; j<n; j++)
                            if(s[j]!=t[j] && t[i]==s[j])
                            {
                                ind= 0;
                                swap(s[j], t[j]);
                                q.push({j, j});
                                swap(s[i], t[j]);
                                q.push({i, j});
                                break;
                            }
                    }
                }
            }
            printf("Yes\n%d\n", q.size());
            while(!q.empty())
                printf("%d %d\n", q.front().xx+1, q.front().yy+1),q.pop();
        }else printf("No\n");
    }return 0;
}
