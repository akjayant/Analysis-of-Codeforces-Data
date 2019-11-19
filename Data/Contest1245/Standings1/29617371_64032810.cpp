#include <bits/stdc++.h>

using namespace std;

const int N = 50;

long long d[N][2][2][2][2][2];//N - bits, same as l for a, same as r for a, same for b, add 1 to bit

long long l, r;

void prepare() {
	
}

long long get_bit(long long mask, int bit_id) {
	return (1LL << bit_id) & mask;
}

void read() {
	scanf("%lld %lld", &l, &r);
	l--, r++;	
}

void solve() {	
	bool l_zero = (l < 0 ? true : false);
	l = max(l, 0LL);
	memset(d, 0, sizeof(d));
	d[N - 1][1][1][1][1][0] = 1;
	long long answer = 0;
	for (int bit = N - 1; bit >= 0; bit--) {
		bool bit_l = (bool) get_bit(l, bit);
		bool bit_r = (bool) get_bit(r, bit);
//		fprintf(stderr, "bit_l = %d bit_r =%d\n", bit_l, bit_r);
		for (int same_al = 0; same_al <= 1; same_al++) {
			for (int same_ar = 0; same_ar <= 1; same_ar++) {
				for (int same_bl = 0; same_bl <= 1; same_bl++) {
					for (int same_br = 0; same_br <= 1; same_br++) {
						for (int add_one = 0; add_one <= 1; add_one++) {
							long long ways = d[bit][same_al][same_ar][same_bl][same_br][add_one];
							if (ways == 0) continue;							
							for (int bit_a = 0; bit_a <= 1; bit_a++) {
								for (int bit_b = 0; bit_b <= 1; bit_b++) {
									for (int new_add_one = 0; new_add_one <= 1; new_add_one++) {										
//										fprintf(stderr, "A bit = %d sal = %d sar = %d sbl = %d sbr = %d ao = %d nao = %d ba = %d bb = %d\n", bit, same_al, same_ar, same_bl, same_br, add_one, new_add_one, bit_a, bit_b);
										if ( (bit_a + bit_b) / 2 != add_one) continue;									
//										fprintf(stderr, "B bit = %d sal = %d sar = %d sbl = %d sbr = %d ao = %d nao = %d ba = %d bb = %d\n", bit, same_al, same_ar, same_bl, same_br, add_one, new_add_one, bit_a, bit_b);
										if (same_al && bit_l > bit_a) continue;
										if (same_ar && bit_r < bit_a) continue;
										if (same_bl && bit_l > bit_b) continue;
										if (same_br && bit_r < bit_b) continue;
//										fprintf(stderr, "C bit = %d sal = %d sar = %d sbl = %d sbr = %d ao = %d nao = %d ba = %d bb = %d\n", bit, same_al, same_ar, same_bl, same_br, add_one, new_add_one, bit_a, bit_b);

										int plus_value = (bit_a + bit_b + new_add_one) % 2;
										int xor_value = bit_a ^ bit_b;
										if (plus_value != xor_value) continue;
										

										int new_same_al = (same_al && bit_a == bit_l);
										int new_same_ar = (same_ar && bit_a == bit_r);
										int new_same_bl = (same_bl && bit_b == bit_l);
										int new_same_br = (same_br && bit_b == bit_r);										
										if (bit > 0) {
											d[bit - 1][new_same_al][new_same_ar][new_same_bl][new_same_br][new_add_one] += ways;											
										} else {
											if (new_same_al + new_same_ar + new_same_bl + new_same_br + new_add_one == 0) {
												answer += ways;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (l_zero) {		
		answer += (r - 1 + 1) * 2 - 1;
	}
	printf("%lld\n", answer);
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	prepare();
	int test;
	scanf("%d", &test);
	for (int t = 0; t < test; t++) {
		read();
		solve();
	}
		
	return 0;
}



