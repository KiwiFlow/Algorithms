#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI = 3.1415926;
int main(){
    double s; cin>>s;
    double r = sqrt(s/(4*PI));
    double L = (s-PI*r*r)/(PI*r);
    double h = sqrt(L*L-r*r);
    printf("%.6f",PI*r*r*h/3);
    return 0;
}
