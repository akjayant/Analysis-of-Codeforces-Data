#include <bits/stdc++.h>

using namespace std;

#define MAX 300005
#define ll long long

string ans;

void add(int idx)
{
    if(idx == 0) ans += 'R';
    else if(idx == 1) ans += 'S';
    else ans += 'P';
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int n;
        scanf("%d", &n);
        int cur[3];
        scanf("%d %d %d", &cur[0], &cur[2], &cur[1]);
        string str;
        cin >> str;
        int cnt[n+1][3];
        memset(cnt, 0, sizeof cnt);
        int need[n];
        ans = "";
        for(int i=0; i<n; i++){
            if(str[i] == 'R'){
                cnt[i][2]++;
                need[i] = 2;
            }
            else if(str[i] == 'P'){
                cnt[i][1]++;
                need[i] = 1;
            }
            else {
                cnt[i][0]++;
                need[i] = 0;
            }
        }
        for(int i=0; i<3; i++){
            int temp = 0;
            for(int j=n-1; j>=0; j--){
                temp += cnt[j][i];
                cnt[j][i] = temp;
            }
        }
        int win = 0;
        ans = "";
        for(int i=0; i<n; i++){
            int wh = need[i];
            if(cur[wh] != 0){
                win++;
                cur[wh]--;
                add(wh);
            }
            else {
                bool done = false;
                for(int j=0; j<3; j++){
                    if(cur[j] == 0) continue;
                    int needed = cnt[i+1][j];
                    int ava = cur[j];
                    if(ava > needed){
                        done = true;
                        cur[j]--;
                        add(j);
                        break;
                    }
                }
                if(done == false){
                    for(int j=0; j<3; j++){
                        if(cur[j] == 0) continue;
                        cur[j]--;
                        add(j);
                        break;
                    }
                }
            }
        }
        if(win >= (n+1)/2){
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}