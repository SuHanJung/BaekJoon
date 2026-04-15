#include <stdio.h>
#include <malloc.h>

int clean(int arr[], int len, int size) {

	int answer[1001];	int l = size / 2;

	for (int count = 0; size * (count + 1) <= len; count++) {

		for (int starta = size * count, startb = size * count + l, timea = 0, timeb = 0; timea + timeb < size;) {

			if (timea == l) {

				answer[starta + timea + timeb] = arr[startb + timeb];

				timeb++;

			}

			else {

				if (timeb == l) {

					answer[starta + timea + timeb] = arr[starta + timea];

					timea++;

				}

				else {

					if (arr[starta + timea] > arr[startb + timeb]) {

						answer[starta + timea + timeb] = arr[startb + timeb];

						timeb++;

					}

					else {

						answer[starta + timea + timeb] = arr[starta + timea];

						timea++;

					}

				}

			}

		}

	}

	if (len % size > l) {

		for (int starta = (len / size) * size, startb = (len / size) * size + l, timea = 0, timeb = 0; timea + timeb < len % size;) {

			if (timea == l) {

				answer[starta + timea + timeb] = arr[startb + timeb];

				timeb++;

			}

			else {

				if (timeb == len % l) {

					answer[starta + timea + timeb] = arr[starta + timea];

					timea++;

				}

				else {

					if (arr[starta + timea] > arr[startb + timeb]) {

						answer[starta + timea + timeb] = arr[startb + timeb];

						timeb++;

					}

					else {

						answer[starta + timea + timeb] = arr[starta + timea];

						timea++;

					}

				}

			}

		}

	}

	else {

		for (int count = (len / size) * size; count < len; count++) {

			answer[count] = arr[count];

		}

	}

	for (int k = 0; k < len; k++) {

		arr[k] = answer[k];

	}

	return 0;

}

int Jsort(int input[], int n) {

	for (int size = 1; n > size;) {

		size *= 2;

		clean(input, n, size);

	}

	return 0;

}
int main() {
	int N = 0, M = 0, V = 0, map[1001][1001] = { 0 }, st[10001] = { 0 }, now = 0, visit[1001] = { 0 };
	scanf("%d %d %d", &N, &M, &V);
	for (int t = 0, a = 0, b =0; t < M; t++) {
		scanf("%d %d", &a, &b);
		map[a][++map[a][0]] = b;
		map[b][++map[b][0]] = a;
	}
	for (int t = 1; t <= N; t++) {
		Jsort(&map[t][1], map[t][0]);
	}
	visit[0] = 2;
	for (st[++st[0]] = V;st[0] > 0;) {
		now = st[st[0]];
		if (visit[now] == 0) {
			visit[now]++;
            if(now != V) printf(" ");
			printf("%d", now);
			st[0]--;
			for (int t = map[now][0]; t > 0; t--) {
				if (visit[map[now][t]] == 0) {
					st[++st[0]] = map[now][t];
				}
			}
		}
		else st[st[0]--] = 0;
	}
	printf("\n");
    st[0] = 1;
    st[1] = V;
for (int t = 1; t <= st[0]; t++) {
	now = st[t];
	if (visit[now] == 1) {
        if(now != V) printf(" ");
		printf("%d", now);
		visit[now]++;
		for (int tt = 1; tt <= map[now][0]; tt++) {
			if (visit[map[now][tt]] == 1) st[++st[0]] = map[now][tt];
		}
	}
}
	return 0;
}