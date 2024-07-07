#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
using namespace std;
#define WIDTH 10 // длине общего префикса
struct vertex {
	int cost, id; // Скорость передачи и ID
};
bool operator < (const vertex& v1, const vertex& v2) { return v1.cost > v2.cost; } // Сравнение двух точек связи
int matchPrefix(int64_t num1, int64_t num2) { // Подсчет длинны общего перфикса
	int count = 0;
	while (num1 != num2) { num1 /= WIDTH; num2 /= WIDTH; count++; }
	return WIDTH - count;
}
int main() {
	int N, times[WIDTH]; // Количество вариаций скорости передачи
	cin >> N; // Считываем количество точек связи
	for (int& time : times) cin >> time; // Сохранение вариаций скорости передачи
	vector<int64_t> prefix(N); // В int не помещается
	map<int64_t, int> numbers; // Массив связей всех со всеми
	priority_queue<vertex> queue; // Очередь на проверку значений
	for (int i = 0; i < N; i++) { // Заполняем массив точек связи и их префиксов
		cin >> prefix[i]; numbers[prefix[i]] = i;
	}
	queue.push({ 0, 0 });
	vector<vertex> visited(N, { -1, -1 }); // Уже проверенные ID
	while (!queue.empty()) { // Очередь проверки
		auto curr = queue.top(); queue.pop(); 
// Забираем элемент начала очереди
		if (curr.id == N - 1) break; 
// Выходим, если это последний ID из существующих
		multiset<vertex> vertices; 
// Массив точек с сортировкой
		int64_t x = prefix[curr.id], new_x, pw, pw2;
			for (int j = 0; j < WIDTH; j++) { // Ищем замены
				pw = (int64_t)pow(10, j); int r = x / pw % 10; 
// Берем j элемент префикса
				for (int k = 0; k < 10; k++) { 
// В цикле меняем один элемеент префикса
					new_x = x - r * pw + k * pw; 
// Рассчитываем новый элемент перебирая варианты от 1 до 10
						auto it = numbers.find(new_x); 
// Ищем этот элемент среди существующих префиксов
						if (it != numbers.end() and x != new_x) 
// Если такой элемент есть ине совпадает с тем что был
							vertices.insert({ times[matchPrefix(x, new_x)], it->second }); 
// Добавляем этот элемент со значением скорости передачи
				}
				for (int d = j + 1; d < WIDTH; d++) { 
// Ищем перестановки пары чисел
					pw2 = (int64_t)pow(10, d); int r2 = x / pw2 % 10; 
// Второй элемент, который будем менять с первым
						new_x = x - r * pw + r2 * pw - r2 * pw2 + r * pw2; 

// Рассчитываем новый префикс



					auto it = numbers.find(new_x); 
// Ищем этот элемент среди существующих префиксов
						if (it != numbers.end() && x != new_x) 
// Если такой элемент есть ине совпадает с тем что был
							vertices.insert({ times[matchPrefix(x, new_x)], it->second }); 
// Добавляем этот элемент со значением скорости передачи
				}
			}
		for (auto next : vertices) {
			int new_cost = curr.cost + next.cost; 
// Рассчитываем время отправки на сл этапе
			if (visited[next.id].cost == -1 or visited[next.id].cost > new_cost) {
 // Если точка еще не посещена или до нее дольше идет сигнал
					queue.push({ new_cost, next.id }); 
// Ставим новую точку
				visited[next.id].cost = new_cost;
 // Обновляем минимальное время связи
				visited[next.id].id = curr.id;
 // Обновляем точку, от которой минимальное время связи
			}
		}
	}
	cout << visited[N - 1].cost << endl; 
// Выводим время посещения последней точки (если нет связи, то - 1 из дефолтного значения)
	if (visited[N - 1].cost == -1) return 0; 
// Шлём всё если нет связи
	list<int> way = { N - 1 }; 
// Карта сигнала
	int curr = N - 1; 
// Текущий элемент - точка назначения сигнала
	while (curr != 0) {
 // Пока не дойдем до последней точки
		way.push_front(visited[curr].id);
 // Добаляем элемент
		curr = visited[curr].id;
 // Следующий элемент
	}
	cout << way.size() << endl;
 // Выводим количество точек, через которые прошли
	for (int x : way) cout << x + 1 << " "; // Выводим маршрутную карту сигнала
	return 0;}

