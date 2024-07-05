#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
void decrypt(int size, int maximum, int index, string str) {

    int* count = new int[maximum];
    //filling with zeros
    for (int i = 0; i < maximum; i++) {
        count[i] = 0;
    }

    //to count values repeating 
    for (int i = 0; i < size; i++) {
        count[str[i]]++;

    }
    
    int sum = 0;
    for (int i = 0; i < maximum; i++) {
        sum += count[i];
        count[i] = sum - count[i];
    }
    //find true position
  
    int* t = new int[maximum];
    for (int i = 0; i < size; i++) {
        t[count[str[i]]] = i;
        count[str[i]]++;
   
    }
    //change values
    int j = t[index];
    char* result = new char[size];
    for (int i = 0; i < size; i++) {
        result[i] = str[j];
        j = t[j];
 
    }
   
    for (int i = 0; i < size; i++) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    string str;
    int i;
    cin >> i;
    cin >> str; 
    decrypt(str.size(), 1000000, i - 1, str);

    return 0;
	}



