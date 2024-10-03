#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 1e6+7;
const int MOD = 1e9+7;
 
signed main(){
    
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<vi> dp(n+1, vi(m+1));

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(s1[i] == s2[j]){
                dp[i+1][j+1] = 1 + dp[i][j];
            } else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    string lcs;

    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            lcs.push_back(s1[i-1]);
            i--; 
            j--;
        } else if(dp[i][j-1] < dp[i-1][j]){
            i--;
        } else {
            j--;
        }
    }

    reverse(all(lcs));
 

    cout << lcs << endl;
}