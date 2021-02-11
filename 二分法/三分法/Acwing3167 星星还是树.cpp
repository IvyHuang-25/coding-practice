/*
题目地址：https://www.acwing.com/problem/content/description/3170/ 
*/

/*题目内容：
在二维平面上有 n 个点，第 i 个点的坐标为 (xi,yi)。

请你找出一个点，使得该点到这 n 个点的距离之和最小。

该点可以选择在平面中的任意位置，甚至与这 n 个点的位置重合。

输入格式
第一行包含一个整数 n。

接下来 n 行，每行包含两个整数 xi,yi，表示其中一个点的位置坐标。

输出格式
输出最小距离和，答案四舍五入取整。

数据范围
1≤n≤100,
0≤xi,yi≤10000
输入样例：
4
0 0
0 10000
10000 10000
10000 0
输出样例：
28284 
*/ 

/*题目解析：
解析地址：https://blog.csdn.net/mmk27_word/article/details/83473953
 
 1、三分套三分
 	若x固定的情况下，存在 z^2 = x^2 + y^2 二次函数的性质 
*/

#include<iostream>
#include<cmath>
using namespace std;

#define eps 1e-8
const int maxn = 110;

int n; //点数目
int x[maxn], y[maxn]; // 点的坐标 

double figure_distance(double x1, double y1){
	double distance = 0;
	for(int i=0; i<n; i++){
		distance += sqrt((x[i]-x1)*(x[i]-x1) + (y[i]-y1)*(y[i]-y1));
	}
	return distance;
}

// 固定 x 
double three_mid(double x1){
	// 针对 y 
	double l = 0, r = 10000;
	double ans;
	while((r-l) > eps){
		double mid1 = l + (r-l)/3;
		double mid2 = r - (r-l)/3;
		double dis1 = figure_distance(x1, mid1);
		double dis2 = figure_distance(x1, mid2);
		if(dis1 < dis2)	{
			r = mid2;
			ans = dis1;
		}
		else {
			l = mid1;
			ans = dis2;
		}
	}
	return ans;
}

int main(){
	// 输入数据
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
	}
	
	// 第一层三分
	double l = 0, r = 10000;
	double least_distance;
	while((r-l) > eps){
		double mid1 = l + (r-l)/3;
		double mid2 = r - (r-l)/3;
		// 第二层三分
		double dis1 = three_mid(mid1);
		double dis2 = three_mid(mid2);
		if(dis1 < dis2){
			r = mid2;
			least_distance = dis1;
		}
		else{
			l = mid1;
			least_distance = dis2;
		}
	}
	cout<<int(least_distance+0.5)<<endl;
	return 0;
} 


 
