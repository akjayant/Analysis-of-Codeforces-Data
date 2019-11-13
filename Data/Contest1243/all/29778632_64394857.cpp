#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
char a[maxn],b[maxn];
vector<pair<int,int>>ans;
void init() {
    ans.clear();
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        init();
        int n;
        scanf("%d",&n);
        int sum=0;
        scanf("%s",a);
        scanf("%s",b);
        int cnt=5;
        while(cnt--) {
            for(int i=0; i<n; i++) {
                if(a[i]==b[i])
                    continue;
                else {
                    for(int j=i+1; j<n; j++) {
                        if(b[j]==b[i]&&b[j]!=a[j]) {
                            swap(a[i],b[j]);
                            ans.push_back(make_pair(i,j));
                            break;
                        }
                        if(a[j]==b[i]&&b[j]!=a[j]) {
                            ans.push_back(make_pair(j,j));
                            swap(a[j],b[j]);
                            swap(a[i],b[j]);
                            ans.push_back(make_pair(i,j));
                            break;
                        }
                    }
                }
            }
        }
        int flag=0;
        for(int i=0; i<n; i++) {
            if(a[i]!=b[i])
                flag=1;
        }
        if(flag==1)
            printf("NO\n");
        else {
            printf("YES\n");
            printf("%d\n",ans.size());
            for(int i=0; i<ans.size(); i++) {
                printf("%d %d\n",ans[i].first+1,ans[i].second+1);
            }
        }
    }
    return 0;
}
