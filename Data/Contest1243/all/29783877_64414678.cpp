#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

char s[N],t[N];

vector<int> x,y;
int n;
bool solve()
{
    x.clear();
    y.clear();
    for(int i=0;i<n;++i)
    {
        if(i==n-1)
            if(s[i]!=t[i])
                return false;
        if(s[i]==t[i])
            continue;
        int p=i+1;
        while(p<n&&s[p]!=s[i])
            ++p;
        if(s[i]==s[p])
        {
            swap(s[p],t[i]);
            x.push_back(p);
            y.push_back(i);
            continue;
        }

        p=i+1;
        while(p<n&&t[p]!=s[i])
            ++p;
        if(p==n)
            return false;
        swap(s[i+1],t[p]);
        swap(s[i+1],t[i]);
        x.push_back(i+1);
        y.push_back(p);
        x.push_back(i+1);
        y.push_back(i);
    }
    return true;
}

int main() {
    int k;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%s%s",&n,s,t);
        if(solve())
        {
            puts("Yes");
            printf("%d\n",x.size());
            for(int i=0;i<x.size();++i)
                printf("%d %d\n",x[i]+1,y[i]+1);
        }
        else puts("No");
    }
    return 0;
}
