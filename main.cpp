#include <iostream>
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974
using namespace std;


struct Point {
int x;
int y;
int index;
double angle;
};

void distribute_points(Point points[], int left, int right) {
    int i = left;
    int j = right;
    double main = points[(left + right) / 2].angle;
     while(i <= j) {
        while (points[i].angle < main){ i++;}
        while (points[j].angle > main){j--;}
        if (i > j) {break;}
        Point glass=points[i];
        points[i]=points[j];
        points[j]=glass;
        i++;
        j--;
    }
    if (left < j) {distribute_points(points, left, j);}
    if (i < right) {distribute_points(points, i, right);}
}


int main()
{
    int r=0;
    int l=0;
    int n=0;//count of points
    cin>>n;
    Point points[n];
    int minimum[2];
        minimum[0]=10^6+1;
        minimum[1]=0;
    for (int i=0; i<n;i++){
        points[i].index=i+1;
        cin >> points[i].x >> points[i].y;
        if (points[i].y<minimum[0]|| points[i].y==minimum[0] && points[i].x<minimum[1])
        {
            minimum[0]=points[i].y;
            minimum[1]=i;
        }
        }
    if (minimum[1]!=0)
        {
        int x = points[0].x;
        int y = points[0].y;
        points[0].y=minimum[0];
        points[0].x=points[minimum[1]].x;
        points[minimum[1]].x=x;
        points[minimum[1]].y=y;
    }
    //finding angle
    for (int i=1; i<n;i++){
        if (points[i].x == points[0].x) {
                points[i].angle = PI / 2; }// perpendicular to x-axis
        else if (points[i].y == points[0].y) {
                points[i].angle = 0;} // perpendicular to y-axis
        else {
                points[i].angle = atan((double)(points[i].y - points[0].y) / (double)(points[i].x - points[0].x));}
        if (points[i].angle < 0) {
                points[i].angle = points[i].angle + 2 * PI;}
    }
    distribute_points(points, 1, n - 1);
    cout << points[0].index;
    cout<< points[n / 2].index;

}
