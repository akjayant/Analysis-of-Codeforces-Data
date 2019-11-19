#include  <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 2000; // it doesn't actually have to be infinity or a big number

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

double dp[123][2];
int vis[123][2];
int id[12][12];
int to[123];

double f(int n, int t) {
	if(vis[n][t]) return dp[n][t];
	vis[n][t] = 1;
	dp[n][t] = 1e9;
	double s = 0;
	for(int i = 1; i <= 6; i++) {
		s += f(n + i, 0);
	}
	s += 6;
	s /= 6;
	if(t==1) {
		dp[n][t] = s;
	} else {
		dp[n][t] = min(to[n] == n ? 1000000000. : f(to[n], 1), s);
	} return dp[n][t];
}

int main(int argc, char const *argv[])
{
	/*vector<double> ans;
	int ret = gauss({
		{1.0/6, 1./6, 1./6, 1./6, -5./6, -1.},
		{1./6, 1./6, 1./6, -4./6, 0, -1.},
		{1./6, 1./6, -3./6, 0, 0, -1.},
		{1./6, -2./6, 0, 0, 0, -1.},
		{-1./6, 0, 0, 0, 0, -1.},
	}, ans);
	for(double x : ans) cout << x << endl;
	cout << ret << endl;*/
	// freopen("in", "r", stdin);
	cout << fixed << setprecision(8);
	{
		int cnt = 0;
		for(int i = 0; i < 10; i += 2) {
			for(int j = 0; j < 10; j++) {
				id[i][j] = cnt++;
			}
			for(int j = 9; j >= 0; j--) {
				id[i+1][j] = cnt++;
			}
		}
	}
	for(int i = 9; i >= 0; i--) {
		for(int j = 0; j < 10; j++) {
			int x; cin >> x;
			to[id[i][j]] = id[i+x][j];
		}
	}
	dp[99][0] = 0;
	dp[98][0] = dp[97][0] = dp[96][0] = dp[95][0] = dp[94][0] = 6;	
	for(int i = 0; i < 6; i++) {
		dp[99-i][1] = dp[99-i][0];
		vis[99-i][0] = vis[99-i][1] = 1;
	}
	cout << f(0, 0) << endl;
	return 0;
}