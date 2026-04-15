#include <stdio.h>
#include <stdlib.h>

int main() {
	int x = 0, y = 0, z = 0, left = 0, arr[1100000][2] = { 0 }, arrst = 0, arrend = 0, input[105][105][105] = { 0 };
	scanf("%d %d %d", &x, &y, &z);
	for (int ttt = 0; ttt <= z + 1; ttt++) {
		for (int t = 0; t < x + 2; t++) {
			input[t][0][ttt] = -1;
			input[t][y + 1][ttt] = -1;
		}
		for (int t = 0; t < y + 2; t++) {
			input[0][t][ttt] = -1;
			input[x + 1][t][ttt] = -1;
		}
	}
	for (int t = 0; t <= x; t++) {
		for (int tt = 0; tt <= y; tt++) {
			input[t][tt][0] = -1;
			input[t][tt][z + 1] = -1;
		}
	}
	for (int floor = 1; floor <= z; floor++) {
		for (int t = 1; t <= y; t++) {
			for (int tt = 1; tt <= x; tt++) {
				scanf("%d", &input[tt][t][floor]);
				if (input[tt][t][floor] == 0) left++;
				else if (input[tt][t][floor] == 1) {
					arr[arrend][0] = floor * 1000000 + 1000 * tt + t;
					arr[arrend][1] = 1;
					arrend++;
				}
			}
		}
	}
	if (left == 0) {
		printf("0");
		return 0;
	}
	for (int ch = left, instx = 0, insty = 0, instz = 0; left != 0 && arr[arrst][0] != 0;) {
		instx = (arr[arrst][0] / 1000) % 1000;
		insty = arr[arrst][0] % 1000;
		instz = arr[arrst][0] / 1000000;
		arrst++;
		if (input[instx + 1][insty][instz] == 0) {
			input[instx + 1][insty][instz] = 1;
			arr[arrend][0] = instz * 1000000 + (instx + 1) * 1000 + insty;
			arr[arrend][1] = arr[arrst - 1][1] + 1;
			left--;
			arrend++;
		}
		if (input[instx - 1][insty][instz] == 0) {
			input[instx - 1][insty][instz] = 1;
			arr[arrend][0] = instz * 1000000 + (instx - 1) * 1000 + insty;
			arr[arrend][1] = arr[arrst - 1][1] + 1;
			left--;
			arrend++;
		}
		if (input[instx][insty + 1][instz] == 0) {
			input[instx][insty + 1][instz] = 1;
			arr[arrend][0] = instz * 1000000 + instx * 1000 + insty + 1;
			arr[arrend][1] = arr[arrst - 1][1] + 1;
			left--;
			arrend++;
		}
		if (input[instx][insty - 1][instz] == 0) {
			input[instx][insty - 1][instz] = 1;
			arr[arrend][0] = instz * 1000000 + instx * 1000 + insty - 1;
			arr[arrend][1] = arr[arrst - 1][1] + 1;
			left--;
			arrend++;
		}
		if (input[instx][insty][instz + 1] == 0) {
			input[instx][insty][instz + 1] = 1;
			arr[arrend][0] = (instz + 1) * 1000000 + instx * 1000 + insty;
			arr[arrend][1] = arr[arrst - 1][1] + 1;
			left--;
			arrend++;
		}
		if (input[instx][insty][instz - 1] == 0) {
			input[instx][insty][instz - 1] = 1;
			arr[arrend][0] = (instz - 1) * 1000000 + instx * 1000 + insty;
			arr[arrend][1] = arr[arrst - 1][1] + 1;
			left--;
			arrend++;
		}
	}
	if (left == 0) printf("%d", arr[arrst - 1][1]);
	else printf("-1");
	return 0;
}