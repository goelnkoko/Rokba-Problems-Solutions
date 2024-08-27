#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 1000 + 20;

vector<int> p(MAX, -1);

string addLargeNumbers(const string& num1, const string& num2) {
    std::string result;
    int carry = 0, sum = 0;
    int n1 = num1.size(), n2 = num2.size();
    
    for (int i = 0; i < std::max(n1, n2); ++i) {
        int digit1 = i < n1 ? num1[n1 - 1 - i] - '0' : 0;
        int digit2 = i < n2 ? num2[n2 - 1 - i] - '0' : 0;
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }
    
    if (carry) {
        result.push_back(carry + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

string mini(const string& a, const string& b){
    if(a.size() < b.size()){
        return a;
    } else if(a.size() > b.size()){
        return b;
    } else {
        return min(a, b);
    }
}

int main(){

    int n; 
    cin >> n; 

    string s, s1, m, r;
    bool f = true;
    cin >> s;
    m = s;
    

    for(int i=1; i < s.size(); i++){
        if((s[i] == '0') || (s[i] != '0' && i >= n/2)){
            int h = 0;
            if(s[i] == '0') h = -1;

            string s2(s.begin()+i+h, s.end());
            if(s2[0] == '0') continue;
            string s1(s.begin(), s.begin()+i+h);
            
            r = addLargeNumbers(s1, s2);
            m = mini(m, r);

            if(s[i] != '0' && i > n/2+1) break;
        }
    }

    cout << m << endl;
}