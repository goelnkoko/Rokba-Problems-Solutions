#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 100000000
#define ll long long


using namespace std;

int main() {

    Nkumbo

    int k, s;
    cin >> k >> s;

    int c = 0;

    for(int i=0; i <= k; i++){
        for(int j=0; j <= k; j++) {

            int z = s - (i+j);
            if(z >= 0 && z <= k)
                c++;
        }
    }    

    cout << c << endl;

    return 0;
}