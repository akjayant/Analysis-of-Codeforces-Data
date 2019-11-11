#include <iostream>
#include <string>
#include <map>
using namespace std;
map <char, int> chuyen;
int d[3];
int test;
int n, a, b, c;
string s, kq;
int dem;
string p = "RPS";

void xuli(){
	cout << "YES" << endl;
	for (int i = 0; i < n; i++){
		if (kq[i] != '#') { 
			cout << kq[i];
			continue;
		}
		if (d[0] > 0){
			d[0]--;
			cout << p[0];
			continue;
		}
		if (d[1] > 0){
			d[1]--;
			cout << p[1];
			continue;
		}
		if (d[2] > 0){
			d[2]--;
			cout << p[2];
			continue;
		}
	}
	cout << endl;
}

void khoitao(){
	dem = 0;
	kq.clear();
	for (int i = 1; i <= n; i++)
		kq.push_back('#');

	for (int i = 0; i < n; i++)
	{
		int chuyen = d[s[i]];
		if (d[chuyen]>0)
		{
			kq[i] = p[chuyen];
			dem++;
			d[chuyen]--;
		}
	}
}

int main()
{
	cin >> test;
	d['R'] = 1;
	d['S'] = 0;
	d['P'] = 2;
	while (test--)
	{
		cin >> n;
		cin >> d[0] >> d[1] >> d[2];
		s.clear();
		cin >> s;
		khoitao();
		if (dem < (n + 1) / 2){
			cout << "NO" << endl;
			continue;
		}
		xuli();
	}
}