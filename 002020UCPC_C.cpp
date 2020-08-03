#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<int> vars; 
// 각 변수의 값들의 저장소로 쓰일 곳

vector<pair<int, int>> leaves; 
// 트리의 잎 부분 레벨과 아이디 저장

map<pair<int, int>, pair<int, int>> conditions; 
// <<레벨, 아이디>, <변수1, 변수2>>
// 변수1 == 변수2 인경우 아스키 값이면 변수의 값을 반환
// 0, 0 인 경우는 0을 반환
// 1, 1 인 경우는 1을 반환

// 변수1 != 변수2 인 경우, 문제에서 말하는 condition이 저장된 경우임
// 0, 1 이 저장된 경우 a 와 b를 비교하는 연산임

// 부모 노드로 갈때는 <level -1, id/2> 하면 됨

int maxLevel = 0;

int count(int level, int id) {
	auto cond = conditions[make_pair(level, id)];
	if (level != 0) {
		if (id % 2 == 0) {

		}
	}
	


	return 0;
}

// 내부 조건 찾는 부분
int findExp(string pExp, int qmIndex) {
	int q = 0;
	int c = 0;
	int i = 0;
	for (i = qmIndex; i < pExp.size(); i++) {
		if (pExp[i] == '?')
			q++;
		else if (pExp[i] == ':')
			c++;

		if (c > q)
			break;
	}
	return i;
}

// 문자열 파서
void func(string exp, int level, int id) {
	int questionMark = exp.find("?");
	auto index = make_pair(level, id);

	if (level > maxLevel) {
		maxLevel = level;
	}

	if (questionMark == string::npos) {
		if (isalpha(exp[0])) {
			conditions[index] = make_pair(exp[0], exp[0]);
		}
		else {
			conditions[index] = exp == "0" ? make_pair(0, 0) : make_pair(1, 1);
		}
		leaves.push_back(index);
	}
	else {
		string condition = exp.substr(0, questionMark);

		conditions[index] = make_pair(condition.front() - 'a', condition.back() - 'a');

		string exp1, exp2;

		int col = findExp(exp, questionMark + 1); // 콜론 위치

		exp1 = exp.substr(questionMark+1, col - questionMark - 1);
		exp2 = exp.substr(col + 1);

		// 디버그용 코드 // 내부 조건문 또는 값을 보기 위함
		//cout << exp1 << ' ' << exp2 << '\n';

		level += 1;
		func(exp1, level, id*2);
		func(exp2, level, id * 2 + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	vars = vector<int>(n);
	conditions = map<pair<int, int>, pair<int, int>>();
	string exp;
	cin >> exp;

	func(exp, 0, 0);

	// 디버그용 코드
	//for (auto leaf : leaves) {
	//	cout << leaf.first << ' ' << leaf.second << '\n';
	//}

	// 변수의 값이 따로 저장되지 않았다면 -1을 채워놓는다.
	fill(vars.begin(), vars.end(), -1);

	return 0;
}

/*
2
a==b?a:0
3
a==b?a==c?1:0:0

*/