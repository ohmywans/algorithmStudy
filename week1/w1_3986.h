// BOJ 3986번: 좋은 단어
#include<bits/stdc++.h> 
using namespace std;  
int n, ret; 
string s; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s; 
		stack<char> stk; // for문을 돌면서 매번 빈 스택이 필요해서 s를 받을때마다 선언되도록!
		for(char a : s){
			if(stk.size() && stk.top() == a)stk.pop();
			else stk.push(a); 
		} 
		if(stk.size() == 0)ret++;
	}
	cout << ret << "\n"; 
}
