#include <iostream>
#include <cstdint>
using namespace std;

void remove_duon (int* const a, int* const b, char const * const msg) {
	(*a)--; (*b)--; cout << msg << '-' << endl;
}

int main() {
	int A, B, C, D, E, F, G, H;
	cin >> A >> B >> C >> D >> E >> F >> G >> H;

	if ((E + D + B + G) - (A + C + F + H) != 0) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	while (E + D + B + G > 0) {

		if (E > 0) {
			if (A > 0) remove_duon(&E, &A, "EA");
			else if (F > 0) remove_duon(&E, &F, "EF");
			else if (H > 0)  remove_duon(&E, &H, "EH");
			else if (C > 0) { E--; C--; cout << "FB+" << endl << "EF-" << endl << "CB-" << endl; }
		}
		if (D > 0) {
			if (A > 0) remove_duon(&D, &A, "DA");
			else if (C > 0) remove_duon(&D, &C, "DC");
			else if (H > 0) remove_duon(&D, &H, "DH");
			else if (F > 0) { D--; F--; cout << "EA+" << endl << "FE-" << endl << "DA-" << endl; }
		}
		if (B > 0) {
			if (A > 0) remove_duon(&B, &A, "BA");
			else if (C > 0) remove_duon(&B, &C, "BC");
			else if (F > 0) remove_duon(&B, &F, "BF");
			else if (H > 0) { B--; H--; cout << "EA+" << endl << "BA-" << endl << "EH-" << endl; }
		}
		if (G > 0) {
			if (H > 0) remove_duon(&G, &H, "GH");
			else if (C > 0) remove_duon(&G, &C, "GC");
			else if (F > 0) remove_duon(&G, &F, "GF");
			else if (A > 0) { G--; A--; cout << "FB+" << endl << "GF-" << endl << "AB-" << endl; }
		}
	}

	return 0;
}


