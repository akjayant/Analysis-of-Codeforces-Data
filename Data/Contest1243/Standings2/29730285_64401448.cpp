#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int a[maxn];
char s[maxn];
char h[maxn];
vector<char> v;

vector<pair<int,int>> p;
int main()
{
    int n;
    int t;
    cin>>t;
    while(t--)
    {
        p.clear();
        scanf("%d",&n);
        scanf("%s%s",s,h);
        v.clear();

        for(int i=0;i<n;i++)
        {
            if(s[i]!=h[i])
            {
                v.push_back(s[i]);
                v.push_back(h[i]);
            }
        }
        sort(v.begin(),v.end());
        int ok=1;
        int cnt=0;
        for(int i=0;i<v.size();i+=2)
        {
            if(v[i]!=v[i+1])
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            printf("Yes\n");
            for(int i=0;i<n;i++)
            {
                if(s[i]!=h[i])
                {
                    int ok=0;
                    for(int j=i+1;j<n;j++)
                    {
                        if(s[i]==s[j])
                        {
                            swap(s[j],h[i]);
                            p.push_back(make_pair(j,i));
                            ok=1;
                            break;
                        }
                    }
                    if(ok==0)
                    {
                        swap(s[i],h[i]);
                        p.push_back(make_pair(i,i));
                        for(int j=i+1;j<n;j++)
                        {
                            if(h[i]==h[j])
                            {
                                swap(s[i],h[j]);
                                p.push_back(make_pair(i,j));
                                ok=1;
                                break;
                            }
                        }
                    }
                }
            }
            printf("%d\n",p.size());
            for(int i=0;i<p.size();i++)
            {
                printf("%d %d\n",p[i].first+1,p[i].second+1);
            }

        }
        else
            printf("No\n");
    }


    return 0;
}