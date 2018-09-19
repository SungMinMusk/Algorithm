//https://www.acmicpc.net/problem/2346
#include<iostream>
using namespace std;
typedef struct node 
{
	int num;
	int jump;
	struct node * next;
	struct node * prev;
};
void ans(int n, node * start)
{
	node *p = start;
	cout << p->num << " ";
	p->prev->next = p->next;
	p->next->prev = p->prev;

	for (int i = 1; i < n; i++)
	{
		int size = p->jump;
		if (size > 0)
		{
			for (int j = 1; j <= size; j++)
				p = p->next;
		}
		else
		{
			for (int j = 1; j <= -1*size; j++)
				p = p->prev;
		}
		//제거
		p->prev->next = p->next;
		p->next->prev = p->prev;
		//출력
		cout << p->num << " ";
	}
}
int main()
{
	int n;
	cin >> n;
	node * head;
	node * pt;
	for (int i = 1; i <= n; i++)
	{
		node *no = (node *)malloc(sizeof(struct node));
		no->num = i;
		cin >> no->jump;
		if (i == 1)
		{
			head = no;
			pt = no;
		}
		else
		{
			pt->next = no;
			no->prev = pt;
			pt=no;
		}
	}
	pt->next = head;
	head->prev = pt;


	ans(n,head);
	return 0;
}
