#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

struct cable {
	int a, b, l;
};

bool compare(cable a, cable b) { // компаратор длины
	return a.l < b.l; // 
}

int main() {
	int n, m, a, b, l;
	cin >> n >> m; // считываем возможные подключения
	vector<cable> connect; vector<int> used_hubs(n, -1); vector<int> used_cables(m, 0);
	for (int i = 0; i < m; ++i) { // считываем все кабели в массив
		cin >> a >> b >> l; connect.push_back((cable) { a - 1, b - 1, l });
	}
	sort(connect.begin(), connect.end(), compare); // сортируем кабели по убыванию

	int netID = 0, max = 0, counter = 0;
	for (int i = 0; i < m; i++) { // проходимся по списку возможных соединений
		int& A = used_hubs[connect[i].a]; int& B = used_hubs[connect[i].b]; if (A != -1 and A == B) continue;

		else if (A == -1 and B == -1) { // проверяем возможность соединения (и соединяем)
			++netID; A = netID; B = A;
		}
		else if ((A != -1 and B == -1) or (A == -1 and B != -1)) {
			A = A + B + 1; B = A;
		}
		else {
			int minID, maxID; if (B > A) {
				minID = A; maxID = B;
			}
			else {
				minID = B; maxID = A;
			}
			for (int j = 0; j < n; j++) if (used_hubs[j] == maxID) used_hubs[j] = minID;
		}
		used_cables[i] = 1; max = connect[i].l;
		++counter;
	}
	cout << max << endl << counter << endl; // выводим количество требуемых кабелей
	for (int j = 0; j < m; j++) if (used_cables[j])
		cout << connect[j].a + 1 << " " << connect[j].b + 1 << endl; // выводим все соединения
	return 0;
}



