/* BOJ 10808번: 알파벳 개수

// 지금은 alphabet[26]을 main 함수의 지역 변수로 alphabet을 선언함. 
// 하지만 c++에서 전역 변수로 초기화 없이 선언하면 알아서 컴파일러가 0으로 초기화해주기 때문에
// 굳이 초기화해줄 필요 없고, 전역 변수로 선언하면 더 사용하기 편해지니까 전역 변수 선언 연습하기!

#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    string s;
	int alphabet[26] = { 0 };
	
	cin >> s;
	
	// 입력받은 s의 요소가 ASCII 코드 상의 숫자와 일치하면 1 증가
	for (int i = 0; i < s.size(); i++) {
		for (int j = 97; j <= 122; j++) {
			
			if (s[i] == j) {
				alphabet[j-97]++;
			}
			else continue;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}

    return 0;
}
*/
/* 정답 - 나랑 같은 로직으로 푸셨는데 더 코드가 간소화된 버전
#include<bits/stdc++.h>
using namespace std;  
typedef long long ll;  
string str; 
int cnt[26];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str; 
    for(char a : str){
    	cnt[a - 'a']++;
	}
	for(int i = 0; i < 26; i++) cout << cnt[i] << " ";
	 
	return 0; 
}
*/