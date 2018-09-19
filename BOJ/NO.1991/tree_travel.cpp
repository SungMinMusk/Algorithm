//https://www.acmicpc.net/problem/1991
#include<iostream>
using namespace std;

typedef struct tree
{
	int left;
	int right;
}node;
tree t[30];

void preorder(int root)
{
	cout << (char)(root + 65) ;
	if (t[root].left != '.' - 65)
		preorder(t[root].left);
	if (t[root].right != '.' - 65)
		preorder(t[root].right);
}
void inorder(int root)
{
	if (t[root].left != '.' - 65)
		inorder(t[root].left);
	cout << (char)(root + 65);
	if (t[root].right != '.' - 65)
		inorder(t[root].right);
}
void postorder(int root)
{
	if (t[root].left != '.' - 65)
		postorder(t[root].left);
	if (t[root].right != '.' - 65)
		postorder(t[root].right);
	cout << (char)(root + 65);
}
int main()
{
	int n;
	int root;
	//입력
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char tmp1,tmp2,tmp3;
		cin >> tmp1>>tmp2>>tmp3;
		//root 노드
		if (i == 0) root = tmp1-65;

		t[tmp1 - 65].left = tmp2-65;
		t[tmp1 - 65].right = tmp3-65;
	}
	//출력
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	
	return 0;
}
