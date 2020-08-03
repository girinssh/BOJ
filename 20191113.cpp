#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> vc;
	vector<int>::iterator iter;
	vector<int> P;
	int count = 1;
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		vc.push_back(i + 1);
	}

	iter = vc.begin();
	for (int i = 0; i < n; i++) {
		for (; count < k; count++) {
			if (iter == vc.end())
				iter = vc.begin();
			iter++;
		}
		if (iter == vc.end())
			iter = vc.begin();
		P.push_back(*iter);
		iter++;
		count = 1;
		vc.erase(iter-1);
	}
	cout << "<";
	for (vector<int>::iterator p = P.begin(); p != P.end(); p++) {
		cout << *p;
		if (p + 1 != P.end())
			cout << ", ";
	}
	cout << ">";

	return 0;
}

//#include <iostream>
//#include <list>
//#include <vector>
//#include <iterator>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//	vector<int> vc;
//	vector<int>::iterator iter = vc.begin();
//
//	for (int i = 0; i < 50; i++) {
//		vc.push_back(rand() % 9);
//		cout << vc.back() << endl;
//	}
//	cout << endl;
//	sort(vc.begin(), vc.end());
//	for (iter = vc.begin(); iter != vc.end(); iter++) {
//		cout << *iter << endl;
//		//vc.pop_front();
//	}
//
//	vector<int>::iterator tempIter;
//	if(vc.end() != (iter = find(vc.begin(), vc.end(), 8)))
//		cout << *tempIter << endl;
//	else {
//		cout << "Nope" << endl;
//	}
//
//	// find_if() -> 특정한 함수의 기준을 만족하는 값을 가진 iter를 반환
//	return 0;
//}