using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct point {
    int x, y;
    int i;
} points[30000];
point p;

bool f(point& start, point& finish) {
    if (start.x * finish.y == start.y * finish.x && start.x * finish.x + start.y * finish.y >= 0)
        return start.x * start.x + start.y * start.y < finish.x* finish.x + finish.y * finish.y;
    return atan2(start.y, start.x) < atan2(finish.y, finish.x);
}

int main() {

    int n;
    cin >> n;//number of pumpkins (points)

    //input points
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> points[i].x >> points[i].y;
        points[i].i = i;
    }

    //change points relative to the first point
    for (int i = n - 1; i >= 0; i--) {
        points[i].x -= points[0].x, points[i].y -= points[0].y;
    }

    //sorting of points
    sort(points, points + n, f);

   //finding second point (start of way)
    int s = 0;
    for (int i = 0; i < n - 1; i++) {
        point p0 = points[0], p1 = points[i], p2 = points[i + 1];
        int d1x = p1.x - p0.x, d2y = p2.y - p0.y, d1y = p1.y - p0.y, d2x = p2.x - p0.x;
        int x = d1x * d2y - d1y * d2x, d = d1x * d2x + d1y * d2y;
        if (x < 0 || x == 0 && d < 0) { 
            s = i;
            break;
        }
    }

    cout << n << endl;
    cout << (points[0].i + 1) << endl;
    for (int i = 0; i < n - 1; i++)
        cout << (points[(s + i) % (n - 1) + 1].i + 1) << endl;

	return 0;
}



