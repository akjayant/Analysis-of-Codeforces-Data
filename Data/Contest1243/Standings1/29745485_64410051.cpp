#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#define fir first
#define sec second
using namespace std;
typedef pair<int,int> P;

int n;
string s1,s2;
int vis[30],v1[30],v2[30];
P ans[110];


void init() {
    for(int i=0;i<30;i++) vis[i]=v1[i]=v2[i]= 0;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        init();
        cin>>n>>s1>>s2;
        for(int i=0;i<n;i++) {
            vis[s1[i]-'a']++;
            v1[s1[i]-'a']++;
            vis[s2[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        int flag = 0;
        for(int i=0;i<30;i++) {
            if(vis[i]%2 == 0) continue;
            flag = 1; 
        }
        if(flag) printf("No\n");
        else {
            int sum = 0;
            for(int i=0;i<n;i++) {
                if(s1[i] != s2[i]) {
                    int pos = -1;
                    for(int j=i+1;j<n;j++) {
                        if(s1[i] == s1[j]) pos = j;
                    }
                    if(pos == -1) {
                        for(int j=i+1;j<n;j++) {
                            if(s2[j] == s1[i]) pos = j;
                        }
                        ans[sum++] = P(pos,pos);
                        swap(s1[pos],s2[pos]);
                    }
                    ans[sum++] = P(pos,i);
                    swap(s1[pos],s2[i]);
                }
            }
            printf("Yes\n%d\n",sum);
            for(int i=0;i<sum;i++) {
                printf("%d %d\n",ans[i].fir+1,ans[i].sec+1 );
            }
        }
    }
    return 0;
}