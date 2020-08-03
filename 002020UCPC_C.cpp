#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<int> vars; 
// �� ������ ������ ����ҷ� ���� ��

vector<pair<int, int>> leaves; 
// Ʈ���� �� �κ� ������ ���̵� ����

map<pair<int, int>, pair<int, int>> conditions; 
// <<����, ���̵�>, <����1, ����2>>
// ����1 == ����2 �ΰ�� �ƽ�Ű ���̸� ������ ���� ��ȯ
// 0, 0 �� ���� 0�� ��ȯ
// 1, 1 �� ���� 1�� ��ȯ

// ����1 != ����2 �� ���, �������� ���ϴ� condition�� ����� �����
// 0, 1 �� ����� ��� a �� b�� ���ϴ� ������

// �θ� ���� ������ <level -1, id/2> �ϸ� ��

int maxLevel = 0;

int count(int level, int id) {
	auto cond = conditions[make_pair(level, id)];
	if (level != 0) {
		if (id % 2 == 0) {

		}
	}
	


	return 0;
}

// ���� ���� ã�� �κ�
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

// ���ڿ� �ļ�
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

		int col = findExp(exp, questionMark + 1); // �ݷ� ��ġ

		exp1 = exp.substr(questionMark+1, col - questionMark - 1);
		exp2 = exp.substr(col + 1);

		// ����׿� �ڵ� // ���� ���ǹ� �Ǵ� ���� ���� ����
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

	// ����׿� �ڵ�
	//for (auto leaf : leaves) {
	//	cout << leaf.first << ' ' << leaf.second << '\n';
	//}

	// ������ ���� ���� ������� �ʾҴٸ� -1�� ä�����´�.
	fill(vars.begin(), vars.end(), -1);

	return 0;
}

/*
2
a==b?a:0
3
a==b?a==c?1:0:0

*/