#include <map>
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map< string, string > personAndLocation;	// человек - деньги
unordered_map< string, long long > personAndCash;	// человек - местоположение
unordered_map< string, long long > cityAndCash;		// город - суммарное кол-во денег
map< long long, set<string> > cachAndCities;		// деньги - названия городов с такой суммой
map< string, long long > topCitiesResult;

//функция для добавления элемента
void addPerson(string personName, string location, long long cash) {
	personAndLocation[personName] = location;
	personAndCash[personName] = cash;
}

void changeLocation(string personName, string newLocation) {
	string oldLocation = personAndLocation[personName];
	long long oldCityCash = cityAndCash[oldLocation];

	// Предыдущее местоположение
	cachAndCities[oldCityCash].erase(oldLocation);
	if (cachAndCities[oldCityCash].size() == 0) {
		cachAndCities.erase(oldCityCash);
	}
	cityAndCash[oldLocation] -= personAndCash[personName];
	cachAndCities[cityAndCash[oldLocation]].insert(oldLocation);

	// Новое местоположение
	long long newCityCash = cityAndCash[newLocation];
	cachAndCities[newCityCash].erase(newLocation);
	if (cachAndCities[newCityCash].size() == 0) {
		cachAndCities.erase(newCityCash);
	}

	cityAndCash[newLocation] += personAndCash[personName];
	cachAndCities[cityAndCash[newLocation]].insert(newLocation);
	personAndLocation[personName] = newLocation;


}

string getTopCity() {
	map<long long, set<string> >::reverse_iterator it = cachAndCities.rbegin();

	if (it != cachAndCities.rend() && it->second.size() == 1)
		return *(it->second.begin());
	return "";
}

void increaseCityCash(string city, long long cash) {
	if (cityAndCash.find(city) != cityAndCash.end()) {
		cachAndCities[cityAndCash[city]].erase(city);

		if (cachAndCities[cityAndCash[city]].size() == 0) {
			cachAndCities.erase(cityAndCash[city]);
		}
	}
	cityAndCash[city] += cash;
	cachAndCities[cityAndCash[city]].insert(city);
}


int main() {
	long long personNumber;
	cin >> personNumber;
// считывание и заполнение объектов 
	for (long long i = 0; i < personNumber; i++) {
		string name, location;
		long long cash;
		cin >> name >> location >> cash;

		addPerson(name, location, cash);
		increaseCityCash(location, cash);
	}

	long long days, movements;
	cin >> days >> movements;
	long long prevDay = 0;

	for (long long i = 0; i < movements; i++) {
		long long day;
		string name, newLocation;
		cin >> day >> name >> newLocation;

		string top_city = getTopCity();
		if (top_city.length() != 0 && day - prevDay != 0) {
			topCitiesResult[top_city] += day - prevDay;
		}

		changeLocation(name, newLocation);
		prevDay = day;
	}

	if (days - prevDay != 0) {
		string top_city = getTopCity();

		if (top_city.length() != 0) {
			topCitiesResult[top_city] += days - prevDay;
		}
	}

	for (auto it = topCitiesResult.begin(); it != topCitiesResult.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	getchar();
	getchar();
	return 0;
}






