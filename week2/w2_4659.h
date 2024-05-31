// BOJ 4659번: 비밀번호 발음하기 - 더뤼한 코드
#include <iostream>
using namespace std;
string input;
bool answer = true;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> input) {
		if (input == "end") break;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
				answer = true; 
				break;
			}
			else answer = false;
		}
		// 2글자 동일 문자 비교
		for (int i = 1; i < input.size(); i++) {
			if (input[i-1] == input[i]) {
				answer = false;
				if ((input[i-1] == 'e' && input[i] == 'e') || (input[i-1] == 'o' && input[i] == 'o')) answer = true;
			} 
		}
		// 3글자 비교
		for (int i = 2; i < input.size(); i++) {
			if ((input[i-2] == 'a' || input[i-2] == 'e' || input[i-2] == 'i' || input[i-2] == 'o' || input[i-2] == 'u') &&
				(input[i-1] == 'a' || input[i-1] == 'e' || input[i-1] == 'i' || input[i-1] == 'o' || input[i-1] == 'u') && 
				(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')) {
				answer = false;
			} else if (!(input[i-2] == 'a' || input[i-2] == 'e' || input[i-2] == 'i' || input[i-2] == 'o' || input[i-2] == 'u') &&
				!(input[i-1] == 'a' || input[i-1] == 'e' || input[i-1] == 'i' || input[i-1] == 'o' || input[i-1] == 'u') && 
				!(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')) {
				answer = false;
			}
		}
		if (answer) cout << "<" + input + ">" + " is acceptable." << "\n";
		else cout << "<" + input + ">" + " is not acceptable." << "\n";
	}
	return 0;
}
/////////////////////////////
#include <bits/stdc++.h>
using namespace std;  
string s; 
int lcnt, vcnt; 
bool isVowel(int idx){
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}
int main () { 
	while(true){
		cin >> s; 
		if(s == "end")break; 
		lcnt = vcnt = 0;
		bool flag = 0;
		bool is_include_v = 0;
		int prev = -1; // 이전 요소 쓰기 위해 미리 -1 초기화
		for(int i = 0; i < s.size(); i++){
			// idx에 s[i]가 아스키 정수값으로 저장
			int idx = s[i]; 
			
			// 모음 있을 때마다 lcnt++, vcnt는 0 초기화, is_include_v는 참
			if(isVowel(idx))lcnt++, vcnt = 0, is_include_v = 1; 
			
			// 자음 있을 때마다 lcnt는 0 초기화, vcnt++
			else vcnt++, lcnt = 0;
			
			// 자음이 3개거나 모음이 3개이면 flag: 1
			if(vcnt == 3 || lcnt == 3) flag = 1; 
			
			// 1번째 요소 이상이면서 + 이전 요소와 현재 요소가 같고 + 그 요소가 e, o가 아니면 flag: 1
			if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')){
				flag  = 1;
			} 
			prev = idx; // 이전 요소 저장 -> 나처럼 2개씩 비교해도 되지만 이렇게 하면 한 반복문 내에 같이 쓰일 수 있음
		}  
		if(is_include_v == 0) flag = 1; // 모음 없으면 flag: 1
		
		// flag: 1이면 not이고, 0이면 acceptable이다.
		if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	} 
	return 0;
}