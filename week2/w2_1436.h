// BOJ 1436번: 영화감독 숌 - GG(정답코드:???)
#include<bits/stdc++.h>
using namespace std; 
int n; 
int main() {
    cin >> n; 
    int i = 666; // 시작 조건
	// for(시작, 끝 조건, 증감 조건)
    for(;; i++){ // 무한 루프
        if(to_string(i).find("666") != string::npos) n--; 
        if(n == 0) break;
    }
    cout << i << "\n"; 
}