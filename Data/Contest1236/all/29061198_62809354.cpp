#include <bits/stdc++.h>
using namespace std; typedef long long ll;
typedef vector<int> vi; typedef pair<int,int> pii;
const ll MOD = 1e9+7;

int n,m;
vector<vi> r,c;

void stepr(int x, int y, int ux, int dx, int ly, int ry, int l);

void stepu(int x, int y, int ux, int dx, int ly, int ry, int l) {
  //cout << 'U' << x << ' ' << y << endl;
  int nx = ux;
  auto it = lower_bound(c[y].begin(),c[y].end(),x);
  if (it != c[y].begin()) nx = (*(--it)) + 1;
  if (ux > nx) nx = ux;
  for (int ri=ux; ri<=nx-1; ++ri) if ((int)r[ri].size()+l != m) { cout << "No\n"; exit(0); }
  if (nx == x) return;
  stepr(nx,y,nx+1,dx,ly,ry,l+1);
}

void stepl(int x, int y, int ux, int dx, int ly, int ry, int l) {
  //cout << 'L' << x << ' ' << y << endl;
  int ny = ly;
  auto it = lower_bound(r[x].begin(),r[x].end(),y);
  if (it != r[x].begin()) ny = (*(--it)) + 1;
  if (ly > ny) ny = ly;
  for (int ci=ly; ci<=ny-1; ++ci) if ((int)c[ci].size()+l != n) { cout << "No\n"; exit(0); }
  if (ny == y) return;
  stepu(x,ny,ux,dx,ny+1,ry,l);
}

void stepd(int x, int y, int ux, int dx, int ly, int ry, int l) {
  //cout << 'D' << x << ' ' << y << endl;
  int nx = dx;
  auto it = upper_bound(c[y].begin(),c[y].end(),x);
  if (it != c[y].end()) nx = (*it) - 1;
  if (dx < nx) nx = dx;
  for (int ri=nx+1; ri<=dx; ++ri) if ((int)r[ri].size()+l != m) { cout << "No\n"; exit(0); }
  if (nx == x) return;
  stepl(nx,y,ux,nx-1,ly,ry,l+1);
}

void stepr(int x, int y, int ux, int dx, int ly, int ry, int l) {
  //cout << 'R' << x << ' ' << y << endl;
  int ny = ry;
  auto it = upper_bound(r[x].begin(),r[x].end(),y);
  if (it != r[x].end()) ny = (*it) - 1;
  if (ry < ny) ny = ry;
  for (int ci=ny+1; ci<=ry; ++ci) if ((int)c[ci].size()+l != n) { cout << "No\n"; exit(0); }
  if (ny == y) return;
  stepd(x,ny,ux,dx,ly,ny-1,l);
}

int main() { ios_base::sync_with_stdio(0);cin.tie(0);
	int k,x,y;
	cin >> n >> m >> k;
	r = vector<vi>(n); c = vector<vi>(m);
	for (int i=0; i<k; ++i) { cin >> x >> y; r[--x].push_back(--y); c[y].push_back(x); }
	for (int i=0; i<n; ++i) sort(r[i].begin(), r[i].end());
	for (int i=0; i<m; ++i) sort(c[i].begin(), c[i].end());
	if ((!r[0].empty() && r[0][0] == 1) || m == 1) {
	  int co = n;
	  if (!c[0].empty()) co = c[0][0];
	  if (co + k == n*m) cout << "Yes\n";
	  else cout << "No\n";
	  return 0;
	}
  stepr(0,0,1,n-1,0,m-1,0);
	cout << "Yes\n";
	return 0;
}