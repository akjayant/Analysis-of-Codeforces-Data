#include<bits/stdc++.h>

using namespace std;
const int maxnn=60;
typedef long long ll;
int a[maxnn];
char s[maxnn];
char t[maxnn];
 int n;
int cx[26];
struct dy{
int x,y;
};
vector<dy> que;
int cnt=0;
int text(int x)
{
    for (int i=x;i<n;i++){
        if(s[i]==s[x-1]){
            swap(s[i],t[x-1]);
            que.push_back(dy{i+1,x});
            cnt++;
            return 1;
        }
        if(t[i]==s[x-1]){
            swap(s[i],t[i]);
            que.push_back(dy{i+1,i+1});
            swap(t[x-1],s[i]);
            que.push_back(dy{i+1,x});
            cnt+=2;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        que.clear();
        memset(cx,0,sizeof(cx));
        scanf("%d",&n);
        scanf("%s",s);
        scanf("%s",t);
        for(int i=0;i<n;i++)
        {
            cx[s[i]-'a']++;
            cx[t[i]-'a']++;
        }
        int flag=0;
        cnt=0;
        for (int i=0;i<n;i++){
            if(s[i]!=t[i]){
                if(!text(i+1)){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        printf("%d\n",cnt);
        for(int i=0;i<que.size();i++)
        {
            printf("%d %d\n",que[i].x,que[i].y);

        }
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int,int> f[120];
int n,cnt;
string a,b;
int text(int x)
{
    for (int i=x;i<n;i++){
        if(a[i]==a[x-1]){
            swap(a[i],b[x-1]);
            f[cnt].first=i+1;
            f[cnt++].second=x;
            return 1;
        }
        if(b[i]==a[x-1]){
            swap(a[i],b[i]);
            f[cnt].first=i+1;
            f[cnt++].second=i+1;
            swap(b[x-1],a[i]);
            f[cnt].first=i+1;
            f[cnt++].second=x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        cin >> n;
        cin >> a >> b;
        cnt=0;
        int flag=0;
        for (int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(!text(i+1)){
                    flag=1;
                    break;
                }
            }
        }
        if(flag) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << cnt << endl;
            for (int i=0;i<cnt;i++){
                cout << f[i].first << " " << f[i].second << endl;
            }
        }
    }
    return 0;
}
*/
