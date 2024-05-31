// BOJ 4949번: 균형잡힌 세상 - 반례 찾기 너무 힘들었음(!깔끔 풀이)
// 내가 너무 더럽게 풀어서 반례 찾기가 힘들었던듯. 강의에서는 반례 소리 1도 안하심
// 틀린 문제로 인식하자.
#include <iostream>
#include <stack>
using namespace std;
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(1) {
		getline(cin, s);
		if (s==".") break;
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			if (st.size() && st.top()=='(' && s[i]==')') st.pop();
			else if (st.size() && st.top()=='[' && s[i]==']') st.pop();
			else if (s[i]=='(' || s[i]=='[') st.push(s[i]);
			
			// 예외 처리: st 사이즈가 0인데 닫는 괄호일 때 no -> bool 함수로 구현해서 바로 false 리턴 때리는게 깔끔할듯
			else if (!st.size() && (s[i]==')'|| s[i]==']')) st.push(s[i]);
			else if (st.size() && st.top()=='[' && s[i]==')') st.push(s[i]);
			else if (st.size() && st.top()=='(' && s[i]==']') st.push(s[i]);
		}
		// 예외 처리:
		if (s[s.size()-1] != '.') st.push(' '); // 맨 마지막 글자가 온점이 아닌 경우 -> (")
		if (s.size() > 100) st.push(' '); 		// size가 100 넘는 경우 -> (")
		
		if (st.size()==0) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;
}

#include <bits/stdc++.h> 
using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);  
    while(true){
        string s; 
        getline(cin, s);  
        if(s == ".") break;
        stack<int> stk; 
        bool check = true;
        for(int i = 0; i < s.length(); i++){ 
            if(s[i] == ')'){ 
                if(stk.size() == 0 || stk.top() == '['){
                    check = false; 
                    break; 
                }else{
                    stk.pop();
                }
            }
            if(s[i] == ']'){
                if(stk.size() == 0 || stk.top() == '('){
                    check = false; 
                    break; 
                }else{
                    stk.pop();
                }
            } 
            if(s[i] == '(') stk.push(s[i]);
            if(s[i] == '[') stk.push(s[i]); 
        }  
        if(check && stk.size() == 0)  cout << "yes\n";
        else cout << "no\n";
    } 
    return 0;
} 