#include <iostream> 
#include <set> 
#include <vector>
 using namespace std;
int result = 0;
set<int> count(const set<int>& collection, int max_size) { int prev = 0;
set<int> single_elements; // контейнер с сортировкой одиночек
for(int curr : collection){
 
if (curr - prev > 2) result++; // Если как минимум два белых подряд res++
else if (curr - prev == 2) single_elements.insert(curr - 1); // Иначе добавляем в массив пустышек
prev = curr; // обновляем переменную
}
if (max_size - prev > 1) result++; // если последняя плохая стоит не крайней res++
else if (max_size - prev == 1) single_elements.insert(max_size); // Если предпоследней, то добавляем одиночку
return single_elements; // Теперь на выходе массив одиночек в конкретной строке/ряду
}

int main() {
int m, n, k, x, y;
cin >> m >> n >> k;
vector<set<int>> badX(m); // Динамический массив плохих дней х с сортировкой vector<set<int>> badY(n); // Динамический массив плохих дней у с сортировкой while(k--){
cin >> x >> y;
badX[x - 1].insert(y); // Массив х -> у
badY[y - 1].insert(x); // Массив y -> x

for(set<int>& badx : badX) badx = count(badx, n); // Подсчитываем количество полос по x 
for(set<int>& bady : badY) bady = count(bady, m); // Подсчитываем количество полос по у 
for (int i = 0; i < m; i++) for (int it : badX[i]) // Считаем клетки - одиночки
if (badY[it - 1].find(i + 1) != badY[it - 1].end()) result++;

cout << result << endl; // Выводим результат
return 0;
}

