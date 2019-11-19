#include<bits/stdc++.h>

using namespace std;
int L;
int num_segments(string& S) {
	int start = 0;
	int minV = 0;
	int curV = 0;
	for(int i = 0; i < L; i++) {
		if(S[i] == '(') {
			curV ++;
		}
		else {
			curV --;
		}
		if(curV < minV) {
			minV = min(minV, curV);
			start = i + 1;
		}
	}

	if(curV != 0) return 0;
	int seg = 0;
	int cur = 0;
	for(int i = start; i < L; i++) {

		if(S[i] == '(') {
			cur += 1;
		}
		else {
			cur -= 1;
		}
		if(cur == 0) seg ++;
	}
	for(int i = 0; i < start; i++) {
		if(S[i] == '(') {
			cur += 1;
		}
		else {
			cur -= 1;
		}
		if(cur == 0) seg ++;
	}
	return seg;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);/*
	string S = "()())(";
	L = S.size();
	cout << num_segments(S) << endl;*/

	cin >> L;
	string S; cin >> S;

	int s1 = 1, s2 = 1;
	int curBeauty = num_segments(S);
	for(int i = 0; i < L; i++) {
		for(int j = i; j < L; j++) {
			swap(S[i], S[j]);
			int count_segments = num_segments(S);
			if(count_segments > curBeauty) {
				curBeauty = count_segments;
				s1 = i + 1; s2 = j + 1;
			}
			swap(S[i], S[j]);
		}
	}
	cout << curBeauty << endl << s1 << " " << s2;

}


