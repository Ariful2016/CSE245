
#include <bits/stdc++.h>

using namespace std;
float calc;
int dt=0;
int n,m,s,t;
int tgti,tgtj,c=0,d=0;
int a[100];
//int k;
//int k;

// Structure of a point in 2D plane
struct Point
{
    int x, y;
};

// Utility function to find minimum of two double values
double min(double x, double y)
{
    return (x <= y)? x : y;
}

// A utility function to find distance between two points in a plane
double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y));
}

// A utility function to find cost of a triangle. The cost is considered
// as perimeter (sum of lengths of all edges) of the triangle
double cost(Point points[], int i, int j, int k)
{
    Point p1 = points[i], p2 = points[j], p3 = points[k];
    return dist(p1, p2) + dist(p2, p3) + dist(p3, p1);
}

// A recursive function to find minimum cost of polygon triangulation
// The polygon is represented by points[i..j].
float mTC(Point points[], int i, int j,float mm[][100])
{
   // There must be at least three points between i and j
   // (including i and j)

   if (mm[i][j]< 1001)
      return mm[i][j];

    else if (j<i+2)
       mm[i][j]=0;

   // Initialize result as infinite


   // Find minimum triangulation by considering all
   else {
        for (int k=i+1; k<j; k++)
         {
            calc=mTC(points, i, k,mm) + mTC(points, k, j,mm) +cost(points, i, k, j);
         dt=0,s=i,t=j,m=k;
         //int dt1=j;

          if(calc<mm[i][j])
           {
            dt++;
            mm[i][j]=calc; //d=k;
            //m=k;
            //s=i;
            //t=j;
           // dt++;
//            dt1++;

            }

//if(dt==0) cout<<s<<m<<t<<endl;

       //if(dt==j)


         }

         //cout<<s<<m<<t<<endl;

//cout<<s<<m<<t<<endl;

         }
         // cout<<s<<m<<t<<endl;

       return mm[i][j];
}

// Driver program to test above functions
int main()
{    int i,j;
    Point points[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    n = sizeof(points)/sizeof(points[0]);
    float mm[100][100];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          mm[i][j]=1001;

    tgti=0;
    tgtj=n-1;
    cout <<"Minimum Cost of triangulation =" <<mTC(points, 0, n-1,mm)<<endl;

    return 0;
}
