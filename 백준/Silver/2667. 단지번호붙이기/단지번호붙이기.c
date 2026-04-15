#include <stdio.h>

int clean(int arr[], int len, int size) {

	int answer[1000];	int l = size / 2;

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

    int N = 0, in[26][26] = {0}, q[1000] = {0}, st[1000] = {0}, ans[1000] = {0};

    scanf("%d", &N);

    for(int y = 0; y < N;y++){

    for (int x = 0; x < N;x++){

        scanf("%1d", &in[y][x]);

        if (in[y][x] == 1) {

            st[0]++;

            st[st[0]] = x * 100 + y;

            }

        }

    }

    for(int t = 1, x = 0, y = 0;t <= st[0];t++){

        x = st[t] / 100;

        y = st[t] % 100;

        if(in[y][x] == 1){

            ans[0]++;

            q[0] = 1;

            q[1] = st[t];

            for(int tt = 1, instx = 0, insty = 0; tt <= q[0];tt++){

            ans[ans[0]]++;

                instx = q[tt] /100;

                insty = q[tt] % 100;

                in[insty][instx] = 0;

                if(instx > 0 && in[insty][instx - 1] == 1){

                in[insty][instx - 1] = 0;

                q[0]++;

                q[q[0]] = (instx - 1) * 100 + insty;

                }

                if(instx < N - 1 && in[insty][instx + 1] == 1){

                in[insty][instx + 1] = 0;

                q[0]++;

                q[q[0]] = (instx + 1) * 100 + insty;

                }

                if(insty > 0 && in[insty - 1][instx] == 1){

                in[insty - 1][instx] = 0;

                q[0]++;

                q[q[0]] = instx * 100 + insty - 1;

                }

                if(insty < N - 1 && in[insty + 1][instx] == 1){

                in[insty + 1][instx] = 0;

                q[0]++;

                q[q[0]] = instx * 100 + insty + 1;

                }

            }

        }

    }

	printf("%d\n", ans[0]);

    Jsort(&ans[1], ans[0]);

    for(int t = 1; t <= ans[0];t++) printf("%d\n", ans[t]);

	return 0;

}