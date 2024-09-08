#include <bits/stdc++.h> 

#define endl '\n'
#define vi vector<int> 
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){

    int n;
    cin >> n;

    int tb[n][n];

    for(int i=0; i < n; i++){
        for(int j=0; j <= i; j++){
            cin >> tb[i][j];
        }
    }   

    int i = 0; 
    int j = 0;

    for(int j = 0; j < n; j++){
        if(i >= j){
            i = tb[i][j] - 1;
        }
        else {
            i = tb[j][i] - 1;
        }
    }

    cout << i  + 1<< endl;


}