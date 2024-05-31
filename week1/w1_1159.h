/* BOJ 1159번: 농구 경기
// 정답 코드와 정확히 일치하는 로직이지만, 코드의 간소화를 위해 아래 달아둠

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// N에 선수 인원 수 입력 받고 vector에 이름 등록하기
	int N;
	cin >> N;
	vector<string> LastName(N);
	for (int i = 0; i < N; i++) {
		cin >> LastName[i];
	}
	
	// 알파벳 배열 List는 0으로 초기화 후, index가 0 = a에 매칭됨, ... 해당하는 인덱스에 값이 1씩 증가
	string Player = "";
	int List[26] = { 0 };
	for (int i = 0; i < N; i++) {
		Player = LastName[i];
		List[(int)Player[0] - 97]++;
	}
	
	// 값이 5이상인 값이 있으면 index + 97로 다시 char형으로 변환 후 string에 하나씩 넣기. sort 필요 없음
	char word;
	string answer = "";
	for (int i = 0; i < 26; i++) {
		if (List[i] >= 5) {
			word = (char)(i + 97);
			answer += word;
		}
	}
	
	// answer 크기가 0이면 항복, 아니면 삽입된 문자열 출력
	if (answer.size() == 0) {
		cout << "PREDAJA" << '\n';
		return 0;
	}
	else cout << answer << '\n';
	
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std; 
int n, cnt[26]; 
string s, ret; 
int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        cnt[s[0] - 'a']++;
    }
    for(int i = 0; i < 26; i++)if(cnt[i] >= 5) ret+=  i + 'a'; 
    if(ret.size()) cout << ret << "\n"; 
    else cout << "PREDAJA" << "\n";
}
*/