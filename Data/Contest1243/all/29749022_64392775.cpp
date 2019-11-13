/*
    Mbak Rose Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int cnt[26];
int main()
{
    int n,i,j,k,x,y,ans,m,q,curr,temp;
    int tc;
    cin >> tc;
    while(tc--)
    {
        scanf("%d",&n);
        memset(cnt, 0, sizeof(cnt));
        string a,b;
        cin >> a >> b;
        for(i=0;i<n;i++)
        {
            cnt[a[i]-'a']++;
            cnt[b[i]-'a']++;
        }
        bool can = 1;
        for(i=0;i<26;i++)
        {
            if(cnt[i] % 2 == 1) can = 0;
        }
        if(!can)
        {
            printf("No\n");
            continue;
        }
        vector<pair<int,int> > vi;
        for(i=0;i<n;i++)
        {
            if(a[i] == b[i]) continue;
            char cari = a[i];
            int idx = -1;
            for(j=i;j<n;j++)
            {
                if(cari == b[j])
                {
                    idx = j;
                    break;
                }
            }
            if(idx != -1)
            {
                vi.push_back({n-1, idx});
                swap(a[n-1], b[idx]);
                vi.push_back({n-1, i});
                swap(a[n-1], b[i]);
                continue;
            }
            for(j=i+1;j<n;j++)
            {
                if(cari == a[j])
                {
                    idx = j;
                    break;
                }
            }
            vi.push_back({idx, i});
            swap(a[idx], b[i]);
        }
        int sz = vi.size();
        printf("Yes\n%d\n",sz);
        for(auto x : vi)
            printf("%d %d\n", x.first+1, x.second+1);
    }
    return 0;
}
