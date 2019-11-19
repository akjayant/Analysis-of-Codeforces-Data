#include <bits/stdc++.h>
using namespace std;
long long Read() {
	long long num=0;
	char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) {
		num=(num<<3)+(num<<1)+ch-'0';
		ch=getchar();
	}
	return num;
}
char buf[1005];
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d",&n);
		scanf("%s",buf);
		int L=-1,R=-1;
		for (int i=0; i<n; ++i) {
			if (buf[i]=='1') {
				L=i;
				break;
			}
		}
		for (int i=n-1; i>=0; --i) {
			if (buf[i]=='1') {
				R=i;
				break;
			}
		}
		if (L==-1&&R==-1) cout<<n<<endl;
		else if (L==-1||R==-1) {
			cout<<max((L+1)*2,(n-R)*2)<<endl;
		} else if (L==R) {
			cout<<max(n+1,max((L+1)*2,(n-R)*2))<<endl;
		}
		else {
			int s1=n+2;
			int s2=(R+1)*2;
			int s3=(n-L)*2;
			int s4=(R-L+1)*2+L;
			int s5=(R-L+1)*2+n-R-1;
			cout<<max(s1,max(s2,max(s3,max(s4,s5))))<<endl;
		}
	}
	return 0;
}
