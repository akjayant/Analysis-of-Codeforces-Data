#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

char s[505];
int a[505], b[505];
int sum[1005];
int que[1005];
int main() {
    int n; cin>>n;
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++) {
        if(s[i] == '(') a[i] = 1;
        else a[i] = -1;
        sum[i] = sum[i - 1] + a[i];
        b[i] = a[i];
    }
    if(sum[n] != 0 || n % 2 == 1) {
        //puts("?");
        puts("0");
        puts("1 1");
        return 0;
    }

    int ans = 0, ansl = 1, ansr = 1;
    int l = 0, r = 1;
    for(int i = n + 1; i <= n * 2; i++) {
        sum[i] = sum[i - 1] + a[i - n];
    }
    for(int i = 1; i <= n; i++) {
        while(l <= r && sum[i] < sum[que[r]]) r--;
        que[++r] = i;
    }
    //if(que[l] == 1) ans++;

    for(int k = n + 1; k <= n * 2; k++) {
        while(l <= r && k - que[l] + 1 > n) l++;
        while(l <= r && sum[k] < sum[que[r]]) r--;
        que[++r] = k;
        if(k - que[l] + 1 == n) ans++;
    }


    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(b[i] + b[j] != 0) continue;
            //cout << i << " " << j << " ";
            b[i] = -b[i];
            b[j] = -b[j];

            sum[0] = 0;
            for(int k = 1; k <= n; k++) {
                sum[k] = sum[k - 1];
                if(b[k] == 1) sum[k]++;
                else sum[k]--;
            }
            for(int k = n + 1; k <= n * 2; k++) {
                sum[k] = sum[k - 1];
                if(b[k - n] == 1) sum[k]++;
                else sum[k]--;
            }
            l = 1, r = 0;
            for(int k = 1; k <= n; k++) {
                while(l <= r && sum[k] < sum[que[r]]) r--;
                que[++r] = k;
            }

            int cnt = 0;
            for(int k = n + 1; k <= n * 2; k++) {
                while(l <= r && k - que[l] + 1 > n) l++;
                while(l <= r && sum[k] < sum[que[r]]) r--;
                que[++r] = k;
                if(k - que[l] + 1 == n) cnt++;
            }
            if(cnt > ans) {
                ans = cnt;
                ansl = i;
                ansr = j;
            }
            //cout << cnt << endl;
            b[i] = -b[i];
            b[j] = -b[j];
        }
    }
    printf("%d\n", ans);
    printf("%d %d\n", ansl, ansr);
    return 0;
}
