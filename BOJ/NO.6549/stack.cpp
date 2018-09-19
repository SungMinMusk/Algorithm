/*
	문제 : https://www.acmicpc.net/problem/6549
	풀이 : 스택에 건물의 (높이,위치)를 푸쉬
		단, 현재 스택의 top에 있는 건물의 높이보다 지금 넣을 건물의 높이가 낮다면
		top에 있는 건물의 높이를 가지는 사각형은 더 이상 존재 안함
		따라서 그 넓이와 result의 넓이를 비교하여 큰 값을 result로 삼음
		오른쪽 끝점 = 현재 넣으려는 건물의 위치 -1;
		왼쪽 끝점 = top 바로 아래에 있는 건물의 위치;
		넓이 = (right - left) * height
*/
#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector>
#include<stack>
using namespace std;
long long height[100005];
long long res = 0;
int main()
{
	while (1)
	{
		//초기화
		for (int i = 0; i < 100005; i++)
			height[i] = 0;
		res = 0;
		//입력과 종료 조건
		int n;
		cin >> n;
		if (n == 0) return 0;
		
		for (int i = 0; i < n; i++)
			scanf("%d", &height[i]);


		height[n] = -1; // 마지막 건물
		stack <pair<long long, long long >> st; //height,index
		st.push(make_pair(-1, -1)); // 제일 앞에 음수를 넣음


		for (int i = 0; i <= n; i++)
		{	//스택이 차있거나(스택의 top.height = -1)
			//스택의 top의 높이가 현재 push될 건물의 높이보다 높다면 top의 높이는 더이상 넓이를 넓히지 못함
			while (st.top().first > height[i] && st.top().first != -1)
			{
				int right = i-1; //top높이를 가지는 사각형의 가장 오른쪽 끝점
				long long h = st.top().first;
				st.pop();
				int left = st.top().second; //top높이를 가지는 사각형의 가장 왼쪽끝점
				res = max(res, (right - left) * h); //넓이의 max를 result에 대입
			}
			st.push(make_pair(height[i],i));
		}
		//결과 출력
		cout << res<<'\n';
	}
	return 0;
}
