#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int compare(char worda[], char wordb[]) {
	for (int count = 0;;count++) {
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

int sorting(char words[][52], int answer[], int n, int size) {
	int l = size / 2;
	int copied[20001] = { 0 };
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

int Jsorts(char words[][52], int answer[], int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		sorting(words, answer, n, cell * 2);
	}
	return 0;
}
int main() {
	int n = 0, answer[20001] = { 0 };
	char words[20001][52] = { 0 };
	scanf("%d", &n);
	for (int count = 0; count <= n; count++) answer[count] = count;
	for (int time = 0; time < n; time++) {
		scanf("%s", &words[time][1]);
		for (int length_check = 51; words[time][length_check] == 0; length_check--) {
			words[time][0] = length_check;
		}
	}

	Jsorts(words, answer, n);
for (int time = 0; time < n; time++) {
	if (answer[time] != answer[time + 1]) {
		if(compare(words[answer[time]], words[answer[time + 1]]) != 0){
		for (int count = 1; words[answer[time]][count] != 0; count++) {
			printf("%c", words[answer[time]][count]);
		}
		if( time + 1 != n) printf("\n");
	}
	}
}

	return 0;
}