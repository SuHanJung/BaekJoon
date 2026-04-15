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

int sorting(char words[], int answer[], int n, int size) {
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
					if (compare(&words[answer[x] * 6], &words[answer[y] * 6]) == 1) {
						copied[(count * size) + time] = answer[x];
						x++;
					}
					else {
						if (compare(&words[answer[x] * 6], &words[answer[y] * 6]) == -1) {
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
					if (compare(&words[answer[x] * 6], &words[answer[y] * 6]) == 1) {
						copied[((n / size) * size) + time] = answer[x];
						x++;
					}
					else {
						if (compare(&words[answer[x] * 6], &words[answer[y] * 6]) == -1) {
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

int Jsorts(char words[], int answer[], int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		sorting(words, answer, n, cell * 2);
	}
	return 0;
}

int main() {
	int *answer, n = 0;
	char* logged, nu[6] = { 0 };
	scanf("%d", &n);
	answer = malloc(sizeof(int) * n);
	logged = malloc(sizeof(int) * 6 * n);
	*logged = 0;
	for (int time = 0; time < n; time++) answer[time] = time;
	for (int sc_time = 0; sc_time < n; sc_time++) {
		scanf("%s %s", &logged[sc_time * 6], nu);
	}
	Jsorts(logged, answer, n);
	for (int mini = n - 2, maxi = n - 1; mini >= 0;) {
		if (compare(&logged[answer[maxi] * 6],&logged[answer[mini] * 6]) != 0) {
			for (int prr = 0; prr < (maxi - mini) % 2;prr++) printf("%s\n", &logged[answer[maxi] * 6]);
			maxi = mini;
		}
		else {
			if (mini == 0) {
				for (int prr = 0; prr < (maxi - mini + 1) % 2;prr++) printf("%s\n", &logged[answer[maxi] * 6]);
                break;
            }
			else mini--;
		}
	}

	free(answer);
	free(logged);
	return 0;
}