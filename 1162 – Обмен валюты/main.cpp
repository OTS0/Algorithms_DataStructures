#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct point_t {
	int A, B;
	double RAB, CAB;
};

vector<point_t> points;
int n, m, s;
double v;
double values[100];
bool isIncreasePossible();

int main() {

	int a, b;
	double rab, cab, rba, cba;
	scanf("%d %d %d %lf", &n, &m, &s, &v);
	values[s] = v;
	points.reserve(m);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d %lf %lf %lf %lf", &a, &b, &rab, &cab, &rba, &cba);
		points.push_back({ a, b, rab, cab });
		points.push_back({ b, a, rba, cba });
	}

	if (isIncreasePossible()) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	getchar();
	getchar();

	return 0;
}

bool isIncreasePossible() {

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < points.size(); ++j) {
			values[points[j].B] = fmax(values[points[j].B], (values[points[j].A] - points[j].CAB) * points[j].RAB);
		}
	}

	for (int i = 0; i < points.size(); ++i) {
		if ((values[points[i].A] - points[i].CAB) * points[i].RAB > values[points[i].B])
			return true;
	}

	return false;




