#include <iostream>
#include <stdlib.h>
using namespace std;

int full_array[20];
int coutStones;
int result = 2000000;//maximum possible value

//function for finding the best result
int findresult (int firstHeap, int secondHeap, int x) {
if (x != coutStones) {
    findresult (firstHeap + full_array[x], secondHeap, x + 1);
    findresult (firstHeap, secondHeap + full_array[x], x + 1);}
else {if(result > abs(firstHeap - secondHeap)){
result = abs(firstHeap - secondHeap); }}
return 0;
}

int main () {
cin >> coutStones;
for (int i = 0; i < coutStones; i = i + 1){
cin>> full_array[i]; }
findresult(0, 0, 0);
cout<< result;
return 0;
}
