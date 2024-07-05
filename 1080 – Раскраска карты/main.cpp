#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct node_t {
	bool checked;
	vector<int> edges;
	char color;

};
node_t nodes[99];
queue<int> q;
int n;
int get_next();
bool good();


int get_next() {
	int x;
	scanf("%d", &x);
	return x;
}
bool good() {
	q.push(1);
	nodes[1].checked = true;
	nodes[1].color = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (size_t i = 0; i < nodes[u].edges.size(); ++i) {
			int to = nodes[u].edges[i];
			if (!nodes[to].checked) {
				nodes[to].checked = true;
				nodes[to].color = nodes[u].color == 0 ? 1 : 0;
				q.push(to);
			}
			else if (nodes[to].color == nodes[u].color) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
//read data
		while ((x = get_next()) != 0) {
			nodes[i].edges.push_back(x);
			nodes[x].edges.push_back(i);
		}
	}
	if (n != 0 && good()) {
		for (int i = 1; i <= n; ++i) {
			printf("%d", nodes[i].color);
		}
		cout << "\n";
	}
	else {
		cout << "-1\n";
	}
}

