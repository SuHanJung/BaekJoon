#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(char worda[], char wordb[]) {
	for (int count = 0;; count++) {
		if (worda[count] == wordb[count]) {
			if (worda[count] == 0) {
				return 0;
			}
		}
		else {
			if (worda[count] > wordb[count]) return -1;
			else return 1;
		}
	}
}

int sorting(char words[][501], int answer[], int n, int size) {
	int l = size / 2;
	int *copied;
	copied = malloc(sizeof(int) * n);
	for (int count = 0; (count + 1) * size <= n; count++) {
		for (int time = 0, x = count * size, y = count * size + l; time < size; time++) {
			if (x == count * size + l) {
				copied[(count * size) + time] = answer[y];
				y++;
			}
			else {
				if (y == (count + 1) * size) {
					copied[(count * size) + time] = answer[x];
					x++;
				}
				else {
					if (compare(words[answer[x]], words[answer[y]]) == 1) {
						copied[(count * size) + time] = answer[x];
						x++;
					}
					else {
						if (compare(words[answer[x]], words[answer[y]]) == -1) {
							copied[(count * size) + time] = answer[y];
							y++;
						}
						else {
							copied[(count * size) + time] = answer[x];
							copied[(count * size) + time + 1] = answer[x];
							x++;
							y++;
							time++;
						}
					}
				}
			}
		}
	}
	if (n % size > l) {
		for (int time = 0, x = (n / size) * size, y = ((n / size) * size) + l; time < n % size; time++) {
			if (x == ((n / size) * size) + l) {
				copied[((n / size) * size) + time] = answer[y];
				y++;
			}
			else {
				if (y == n) {
					copied[((n / size) * size) + time] = answer[x];
					x++;
				}
				else {
					if (compare(words[answer[x]], words[answer[y]]) == 1) {
						copied[((n / size) * size) + time] = answer[x];
						x++;
					}
					else {
						if (compare(words[answer[x]], words[answer[y]]) == -1) {
							copied[((n / size) * size) + time] = answer[y];
							y++;
						}
						else {
							copied[((n / size) * size) + time] = answer[x];
							copied[((n / size) * size) + time + 1] = answer[x];
							x++;
							y++;
							time++;
						}
					}
				}
			}
		}
	}
	else {
		for (int count = (n / size) * size; count < n; count++) {
			copied[count] = answer[count];
		}
	}

	for (int count = 0; count < n; count++) {
		answer[count] = copied[count];
	}
	free(copied);
	return 0;
}

int Jsorts(char words[][501], int answer[], int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		sorting(words, answer, n, cell * 2);
	}
	return 0;
}

int main() {
	int inm = 0, inn = 0, * answer, tot = 0;
	char words[10000][501] = { 0 }, nword[501] = { 0 };
	scanf("%d %d", &inn, &inm);
	answer = malloc(sizeof(int) * inn);
	for (int time = 0; time < inn; time++) {
		answer[time] = time;
	}
	for (int time = 0; time < inn; time++) {
		scanf("%s", &words[time]);
	}
	Jsorts(words, answer, inn);
	for (int maxin, minin, time = 0; time < inm; time++) {
		scanf("%s", nword);
		maxin = inn - 1;
		minin = 0;
		for (int mid;;) {
			mid = (maxin + minin) / 2;
			if (compare(words[answer[mid]], nword) == 0) {
				tot++;
				break;
			}
			else {
				if (maxin - minin < 2) {
					if ((compare(words[answer[maxin]], nword) != 0) && (compare(words[answer[minin]], nword) != 0)) break;
					else {
						tot++;
						break;
					}
				}
				if (compare(words[answer[mid]], nword) == 1) {
					minin = mid;
				}
				else {
					maxin = mid;
				}
			}
		}
	}
	printf("%d", tot);
	return 0;
}