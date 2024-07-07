#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

struct knot {
	vector <pair<int, int>> gaspipeline;	// contains destination and profit
	int profit;
	bool isFirst;
};

struct knot nodes[500];

int n, s, f;

int main() {
	int m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		nodes[a].gaspipeline.push_back({ b, c });
		nodes[a].isFirst = false;
	}

	scanf("%d %d", &s, &f);
	nodes[s].isFirst = true;

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k < nodes[j].gaspipeline.size(); ++k) {
				auto currPipeline = nodes[j].gaspipeline[k];
				if (!nodes[currPipeline.first].isFirst && (nodes[j].isFirst || nodes[j].profit != 0)) {
					nodes[currPipeline.first].profit = fmax(nodes[j].profit + currPipeline.second, nodes[currPipeline.first].profit);
				}
			}
		}
	}

	if (nodes[f].profit == 0) {
		printf("No solution");
	}
	else {
		printf("%d", nodes[f].profit);
	}

	return 0;
}




