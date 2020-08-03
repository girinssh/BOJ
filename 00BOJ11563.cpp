#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define first x
#define second y

typedef pair<double, double> Start, End;
typedef pair<Start, End> Line;

int main(void) {
	int n, m;

	vector<Line> sinchon, anam;
	vector<double> sL[3], aL[3];

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		double xs, ys, xe, ye;
		cin >> xs >> ys >> xe >> ye;

		Start ps = { xs, ys };
		End pe = { xe, ye };

		sL[i][0] = ye - ys;
		sL[i][1] = -(xe - xs);
		sL[i][2] = sL[i][1] * ys - sL[i][0] * xs;
		sinchon[i] = make_pair(ps, pe);

	}

	for (int i = 0; i < m; i++) {
		double xs, ys, xe, ye;
		cin >> xs >> ys >> xe >> ye;

		Start ps = { xs, ys };
		End pe = { xe, ye };

		aL[i][0] = ye - ys;
		aL[i][1] = -(xe - xs);
		aL[i][2] = sL[i][1] * ys - sL[i][0] * xs;

		anam[i] = make_pair(ps, pe);

	}

	for (int i = 0; i < n; i++) {
		Line l = sinchon[i];

	}
}

/*

������ �Է¹޴´�
-> �� ������ �Լ��� ã�´�
-> ������ ���� ���� ����� �Լ� ���� ��� �� ���� ã�´�
-> �� ���� ������ ���� ��ġ�� �ݴ�� �����Ѵ�.
-> �� ���� ������ ���� ��ġ�� �ʰ� ������ ���� ���� �����Ѵٸ� �� ���� �Ÿ��� ���Ѵ�.
-> �� ���� ������ ���� ��ġ�� �ʰ� ������ ���� ���� �������� �ʴ´ٸ� �� ���� �Ÿ��� ������ ���� ����������� �Ÿ��� ���� �� ��Ÿ��� ������ �̿��Ѵ�.
*/
