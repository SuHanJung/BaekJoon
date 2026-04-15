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

int sorting(char words[][21], int answer[], int n, int size) {
	int l = size / 2;
	int copied[1000000] = { 0 };
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
	return 0;
}

int Jsorts(char words[][21], int answer[], int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		sorting(words, answer, n, cell * 2);
	}
	return 0;
}


int main() {
	int a = 0, b[1000000] = {0}, c = 0;
	char st[1000000][21] = { 0 };
	scanf("%d %d", &a, &c);
	a += c;
	for (int time = 0; time < a; time++) {
		scanf("%s", st[time]);
		b[time] = time;
	}
	Jsorts(st, b, a);
	c = 0;
	for (int time = 1; time < a; time++) {
		if (compare(st[b[time]], st[b[time - 1]]) == 0) {
			c++;
		}
	}
	printf("%d\n", c);
	for (int time = 1; time < a; time++) {
		if (compare(st[b[time]], st[b[time - 1]]) == 0) {
			printf("%s\n", st[b[time]]);
		}
	}
	return 0;
}