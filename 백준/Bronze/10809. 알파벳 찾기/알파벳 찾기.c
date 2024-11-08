int main() {
	char n;
	int s[26], t;
	for (t = 0; t < 26; t++)s[t] = -1;
	for (t = 0, n = getchar(); n >= 'a'; n = getchar(), t++)if (s[n - 'a'] == -1) s[n - 'a'] = t;
	for (t = 0; t < 26; t++) printf("%d ", s[t]);
}