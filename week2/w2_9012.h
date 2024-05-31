// BOJ 9012번: 괄호 - 성공
/*
내가 한 것: 안되는 경우도 끝까지 push로 입력받고 마지막 사이즈로 판단
스승님: 안되면 바로 false 리턴으로 메모리 줄임 (스승님처럼 bool 함수 구축해보는 연습!)
*/
#include <iostream>
#include <stack>
using namespace std;
int T;
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> s;
		stack<char> st;
		for (int j = 0; j < s.size(); j++) {
			if (st.size() && s[j] == ')' && st.top() != s[j]) {
				st.pop();
			} else st.push(s[j]);
		}
		if (st.size()==0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
//
#include <bits/stdc++.h>
using namespace std;
int n;  
string s; 
bool check(string s){
	stack<char> stk; 
	for(char c : s){
		if(c == '(')stk.push(c); 
		else{
			if(!stk.empty()) stk.pop(); 
			else return false; 
		}
	}
	return stk.empty();
}
int main() {
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s; 
		if(check(s)) cout << "YES\n"; 
		else cout << "NO\n";
	}  
	return 0;
} 