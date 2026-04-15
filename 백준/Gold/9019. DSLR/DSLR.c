#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned short str[10000] = { 0 };

unsigned short D(unsigned short mem) {
	unsigned short val = mem;
	val *= 2;
	val %= 10000;
	return val;
}

unsigned short S(unsigned short mem) {
	if (mem == 0) return 9999;
	unsigned short val = mem;
	val--;
	return val;
}
unsigned short L(unsigned short mem) {
	unsigned short val = mem;
	val %= 1000;
	val *= 10;
	val += mem / 1000;
	return val;
}

unsigned short R(unsigned short mem) {
	unsigned short val = mem;
	val /= 10;
	val += (mem % 10) * 1000;
	return val;
}

unsigned short ans(unsigned short ob) {
	if (str[ob] == ob) return 0;
	ans(str[ob] % 10000);
	switch (str[ob] / 10000) {
	case 1:
		printf("D");
		break;
	case 2:
		printf("S");
		break;
	case 3:
		printf("L");
		break;
	case 4:
		printf("R");
		break;
	}
	return 0;
}

int main() {
	unsigned short T = 0, in = 0, ob = 0, q[10000] = { 0 }, d = 0, s = 0, l = 0, r = 0;
	scanf("%hu", &T);
	for (int t = 0; t < 10000; t++)str[t] = -1;
	for (; T > 0; T--) {
		scanf("%hu %hu", &in, &ob);
		str[in] = in;
		q[0] = 1;
		q[1] = in;
		for (unsigned short t = 1; str[ob] == 65535; t++) {
			d = D(q[t]);
			s = S(q[t]);
			l = L(q[t]);
			r = R(q[t]);
			if (str[d] == 65535) {
				str[d] = q[t] + 10000;
				q[0]++;
				q[q[0]] = d;
			}
			if (str[s] == 65535) {
				str[s] = q[t] + 20000;
				q[0]++;
				q[q[0]] = s;
			}
			if (str[l] == 65535) {
				str[l] = q[t] + 30000;
				q[0]++;
				q[q[0]] = l;
			}
			if (str[r] == 65535) {
				str[r] = q[t] + 40000;
				q[0]++;
				q[q[0]] = r;
			}
		}
		ans(ob);
		printf("\n");
		in = 0;
		ob = 0;
		for (unsigned short t = 0; t < 10000; t++) {
			str[t] = -1;
		}
		for (short t = q[0]; t >= 0; t--) {
			q[t] = 0;
		}
	}
	return 0;
}