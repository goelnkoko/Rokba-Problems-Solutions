#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 1000 + 20;
int n, par[N];

inline int ask(int a, int b) {
	cout << "? " << a + 1 << ' ' << b + 1 << endl;
	int x;
	cin >> x;
	x--;
	return x;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) par[i] = -1;

		for (int i = 1; i < n; i++) {
			int last = 0;
			do {
				int x = ask(i, last);
				if (x == i) break;
				last = x;
			} while(true);

			par[i] = last;
		}

		cout << "! ";
		for (int i = 1; i < n; i++) {
			cout << par[i] + 1 << ' ' << i + 1 << ' ';
		}
		cout << endl;
	}
}
