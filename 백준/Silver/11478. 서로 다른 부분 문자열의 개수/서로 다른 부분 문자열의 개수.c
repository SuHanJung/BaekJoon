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

int sorting(char words[][1001], int answer[], int n, int size) {
	int l = size / 2;
	int copied[1000] = { 0 };
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

int Jsorts(char words[][1001], int answer[], int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		sorting(words, answer, n, cell * 2);
	}
	return 0;
}

int main() {
	char input[1001] = { 0 }, comp[1001][1001] = { 0 };
	int n = 0, pr = 0, ans[1000] = { 0 };
	scanf("%s", input);
    if(input[0] == 0){
        printf("0");
        return 0;
    }
    if(input[1] == 0){
        printf("1");
        return 0;
    }
    for (; input[n] != 0; n++);
	pr = (n * (n + 1)) / 2;
	for (int le = 1; le <= n; le++) {
		for (int time = 0; time <= n - le; time++) ans[time] = time;
		for (int wordn = 0; wordn <= n - le; wordn++) {
			for (int digi = 0; digi < le; digi++) comp[wordn][digi] = input[wordn + digi];
		}
		Jsorts(comp, ans, n - le + 1);
		for (int time = 0; time < n - le; time++) {
			if (compare(comp[ans[time]], comp[ans[time + 1]]) == 0) pr--;
		}
	}
	printf("%d", pr);
	return 0;
}