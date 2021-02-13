/*
题目地址： https://www.acwing.com/problem/content/900/
*/ 

/* 题目内容：
给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。

        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
输入格式
第一行包含整数n，表示数字三角形的层数。

接下来n行，每行包含若干整数，其中第 i 行表示数字三角形第 i 层包含的整数。

输出格式
输出一个整数，表示最大的路径数字和。

数据范围
1≤n≤500,
?10000≤三角形中的整数≤10000
输入样例：
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
输出样例：
30
*/


#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 510;
int triangle[maxn][maxn];
int dis[maxn][maxn];

int main(){
	int n;
	cin>>n;
	
	// 输入三角形
	int tmp;
	for(int i=1; i<=n; i++){
		// 在每一层，有i个数
		for(int j=1; j<=i; j++){
			cin>>tmp;
			triangle[i][j] = tmp;	
		} 
	}
	
	// 初始化 
	// 从最后一层开始
	for(int m=1; m<=n; m++){
		dis[n][m] = triangle[n][m];
	}
	// 从倒数第二层到第一层
	for(int i=n-1; i>=1; i--){
		for(int j=1; j<=i; j++){
			dis[i][j] = triangle[i][j] + max(dis[i+1][j], dis[i+1][j+1]);
		}
	}
	
	/*
	// 输出distance
	for(int i=1; i<=n; i++){
		// 在每一层，有i个数
		for(int j=1; j<=i; j++){
			cout<<dis[i][j]<<" ";	
		}
		cout<<endl;
	}*/
	
	cout<<dis[1][1]<<endl;
	return 0;
}

