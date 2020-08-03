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

선분을 입력받는다
-> 그 선분의 함수를 찾는다
-> 상대방의 점과 가장 가까운 함수 내의 어느 한 점을 찾는다
-> 그 점이 상대방의 점과 겹치면 반대로 시행한다.
-> 그 점이 상대방의 점과 겹치지 않고 본인의 선분 위에 존재한다면 두 점간 거리를 구한다.
-> 그 점이 상대방의 점과 겹치지 않고 본인의 선부 위에 존재하지 않는다면 두 점간 거리와 선분의 제일 가까운점과의 거리를 구한 후 피타고라스 정리를 이용한다.
*/
