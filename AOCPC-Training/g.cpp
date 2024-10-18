#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000
#define endl '\n' 
#define Pin ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int a[MAX], n, m;
char s[MAX], p[MAX];

void calcularLPS(string p) {
    m = p.length();
    int i = 0, j = -1;
    a[0] = -1;
    while (i < m) {
        while (j >= 0 && p[i] != p[j]) j = a[j];
        i++, j++;
        a[i] = j;
    }
}

vector<int> KMP(string s, string p) {
    m = p.length();
    n = s.length();
    vector<int> resp;
    int i = 0, j = 0;
    calcularLPS(p);
    while (i < n) {
        while (j >= 0 && s[i] != p[j]) j = a[j];
        i++, j++;
        if (j == m) {
            resp.push_back(i - m);
            j = a[j];
        }
    }
    return resp;
}

int main() {
    Pin

    #ifndef ONLINE_JUDGE
    freopen("grid.in", "r", stdin);
    freopen("grid.out", "w", stdout);
    #endif
    
    #ifdef ONLINE_JUDGE
    freopen("grid.in", "r", stdin);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m));
        vector<vector<bool>> used(n, vector<bool>(m, false));
  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        
        int x;
        cin >> x;
        string s;
        cin >> s;
        int wordLength = s.length();

        int totalOccurrences = 0;
        
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = 0; j < m; j++) {
                str += mat[i][j];
            }
            vector<int> vet = KMP(str, s);
            for (int c : vet) {
                bool canUse = true;
                for (int k = 0; k < wordLength; k++) {
                    if (used[i][c + k]) {
                        canUse = false;
                        break;
                    }
                }
                if (canUse) {
                    totalOccurrences++;
                    for (int k = 0; k < wordLength; k++) {
                        used[i][c + k] = true;
                    }
                }
            }
        }

        for (int j = 0; j < m; j++) {
            string str = "";
            for (int i = 0; i < n; i++) {
                str += mat[i][j];
            }
            vector<int> vet = KMP(str, s);
            for (int c : vet) {
                bool canUse = true;
                for (int k = 0; k < wordLength; k++) {
                    if (used[c + k][j]) {
                        canUse = false;
                        break;
                    }
                }
                if (canUse) {
                    totalOccurrences++;
                    for (int k = 0; k < wordLength; k++) {
                        used[c + k][j] = true;
                    }
                }
            }
        }
        cout << totalOccurrences << endl;
    }
    
    return 0;
}
