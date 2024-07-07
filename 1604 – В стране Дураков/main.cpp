#define INT_MIN (-INT_MAX-1)
#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
using namespace std;

typedef struct {
	int count;//count of number
	int index;//for answer and index of number
} sign;


int main() {
	int k;
	cin >> k;

	int min = INT_MAX;//unreal min number for us
	int max = INT_MIN;//unreal max number for us
	int index_min = -1;
	int index_max = -1;
	sign* signs = new sign[k];

	for (int i = 0; i < k; i++) {
		cin >> signs[i].count;
		signs[i].index = i + 1;
		if (signs[i].count >= max) {
			max = signs[i].count;
			index_max = i;
		}
		if (signs[i].count < min) {
			min = signs[i].count;
			index_min = i;
		}
	}

	while (index_min != index_max && min != INT_MAX) {
		printf("%i %i ", signs[index_max].index, signs[index_min].index);
		signs[index_max].count--;
		signs[index_min].count--;
		max = INT_MIN;
		min = INT_MAX;
		for (int i = 0; i < k; i++) {
			if (signs[i].count != 0 && signs[i].count >= max) {
				max = signs[i].count;
				index_max = i;
			}
			if (signs[i].count != 0 && signs[i].count < min) {
				min = signs[i].count;
				index_min = i;
			}
		}
	}
	for (int i = 0; i < max; i++) {
		printf("%i ", signs[index_max].index);
	}
	return 0;
}





