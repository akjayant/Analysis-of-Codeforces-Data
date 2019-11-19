#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int a, b, n, p, d, w;
int indegree[100005];
LL color[3][100005];
int rec[100005];
int route[100005][3];
int visit[100005];


LL PaintPoint(int now, int pre, int pre_pre, int pre_pos){
    int c = 3 - pre - pre_pre;
    LL ret = color[c][now];
    for (int i=0; i < 2; i++){
        if (route[now][i] == -1) break;
        if (route[now][i] == pre_pos) continue;
        ret += PaintPoint(route[now][i], c, pre, now);
    }
    // cout<<now<<' '<<ret<<endl;

    return ret;
}

void GetAns(int now, int pre, int pre_pre){
    int c = 3 - pre - pre_pre;
    rec[now] = c;
    visit[now] = 1;
    for (int i=0;i<2; i++){
        if (route[now][i] == -1) break;
        if (visit[route[now][i]]) continue;
        GetAns(route[now][i], c, pre);
    }
}

LL min(LL a, LL b){
    if (a>b)
        return b;
    return a;
}

int main()
{
    scanf("%d",&n);
    memset(route, -1, sizeof(route));
    for (int i=0; i<3; i++){
        for (int j=0; j<n; j++){
            scanf("%I64d",&color[i][j]);
        }
    }
    int flag = 0;
    int stpos = -1;
    for (int i=1; i<n; i++){
        scanf("%d%d",&a, &b);
        a--;
        b--;
        route[a][indegree[a]] = b;
        route[b][indegree[b]] = a;
        indegree[a]++;
        indegree[b]++;
        if (indegree[a]==3 || indegree[b] == 3) flag = 1;
        if (indegree[a] == 2) stpos = a;
        if (indegree[b] == 2) stpos = b;
    }
    if (flag){
        cout<<-1<<endl;
        return 0;
    }
    // cout<<stpos<<endl;
    LL ans = -1;

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (i == j) continue;
            int k = 3-i-j;
            LL tmp = color[i][stpos] + PaintPoint(route[stpos][0], i, j, stpos) + PaintPoint(route[stpos][1], i, k, stpos);
            // cout<<i<<' '<<tmp<<endl<<endl;
            if (ans == -1) {
                ans = tmp;
                rec[stpos] = i;
                rec[route[stpos][0]] = k;
                rec[route[stpos][1]] = j;
            }
            if (tmp < ans){
                ans = tmp;
                rec[stpos] = i;
                rec[route[stpos][0]] = k;
                rec[route[stpos][1]] = j;
            }
        }
    }

    visit[stpos] = 1;
    GetAns(route[stpos][0], rec[stpos], rec[route[stpos][1]]);
    GetAns(route[stpos][1], rec[stpos], rec[route[stpos][0]]);
    cout<<ans<<endl;
    for (int i=0; i<n; i++){
        printf("%d ", rec[i]+1);
    }
    return 0;
}
