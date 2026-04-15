#include <stdio.h>

int compare(long long int a,long long int b) {

	if (a > b) return b;	else return a;

}

int G_(long long int a,long long int b) {

	long long int G = 1, prime = 2, aa = a, bb = b;

	for (; compare(aa, bb) >= prime; prime++) {

		for (; ((aa % prime == 0) && (bb % prime == 0));) {

			G *= prime;

			aa /= prime;

			bb /= prime;

		}

	}

	return G;

}

int main() {

	long long int M = 0, N = 0, x = 0, L = 0, y = 0, T = 0, ans = 1;

	scanf("%lld", &T);

	for (; T > 0; T--) {

		scanf("%lld %lld %lld %lld", &M, &N, &x, &y);

		if (x == M) x = 0;

		if (y == N) y = 0;

        L = M * N / G_(M, N);

		ans = x;

		for (;; ans+=M) {

			if (ans % N == y) {

				break;

                }

            if (L < ans){

                ans = -1;

                break;

            }

		}  

        if (ans == 0) ans = L;

		printf("%lld\n", ans);

	}

	return 0;

}