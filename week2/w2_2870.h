// BOJ 2870번: 수학 숙제 - 100자리 수가 인식이 안됨 -1 으로 나옴. 
// 나머지는 잘 나옴
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
string word;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int a = 0; a < N; a++) {
		cin >> word;
		queue<char> q;
		for (int i = 0; i < word.size(); i++) {
			q.push(word[i]);
		} 
		string ss = "";
		while (q.size()) {
			char c = q.front();
			string s = string(1, c);
			if (c >= 65) {   // c: 문자
				q.pop();
				if (ss.size()) {
					v.push_back(atoi(ss.c_str()));
					ss = ""; // 초기화
				}
			} else {         // c: 숫자
				ss += s;
				if (q.size() == 1 && ss.size()) {
					v.push_back(atoi(ss.c_str()));
					ss = ""; // 초기화
				}
				q.pop();
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
/////////////////////////////
#include <bits/stdc++.h>
using namespace std;   
int n; 
vector<string> v; 
string s, ret;
void go(){   
	while(true){ // string에 front 사용 -> 첫번째 자리 0이면 그 수 삭제(erase)
		// 중요: 항상 front()와 같은 원소 참조 시 사이즈 있는지 체크 필수
		if(ret.size() && ret.front() == '0') ret.erase(ret.begin()); 
		else break;
	}
	// 결국 다 지워져서 사이즈가 0이면 ret에 0 저장 (Ex: 0000)
	if(ret.size() == 0) ret = "0"; 
	// 그렇지 않으면 그대로 v에 push_back되고, ret 초기화
	v.push_back(ret);
	ret = "";  
}
// Custom Operator 함수 적용
bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b; // 2순위: 사이즈 같으면 왼쪽 끝에서부터 아스키 값 비교
	return a.size() < b.size(); 		   // 1순위: 숫자 길이가 길면 당연히 더 큰 수
}
int main() {
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s; 
	 	ret = "";
		for(int j = 0; j < s.size(); j++){
			if(s[j] < 65)ret += s[j]; // 숫자이면 ret에 그대로 하나씩 저장
			else if(ret.size()) go(); // 문자이면 그전까지의 ret을 go()로 벡터 v에 저장
		}
		if(ret.size()) go(); 
	}
	sort(v.begin(), v.end(), cmp);
	for(string i : v)cout << i << "\n"; 
	return 0;
}