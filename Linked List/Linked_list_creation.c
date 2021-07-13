#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
} *first = NULL;

void Create()
{
	int A[100], i, n;

	printf("Enter no of nodes");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter node value : ");
		scanf("%d", &A[i]);
	}
	struct Node *t = NULL, *last = NULL;

	for (i = 0; i < n; i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		if (first == NULL)
		{
			first = last = t;
		}
		else
		{
			last->next = t;
			last = t;
		}
	}
}

void Display(struct Node *p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
int Count(struct Node *p)
{
	int l = 0;
	while (p != NULL)
	{
		p = p->next;
		l++;
	}
	return l;
}
void Insert(struct Node *p, int index, int x)
{
	struct Node *t;
	int i;
	if (index < 0 || index > Count(p))
	{
		return;
	}
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	if (index == 0)
	{

		t->next = first;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

void main()
{

	Create();

	Display(first);

	int y = Count(first);

	printf("No of nodes are %d\n", y);

	Insert(first, 3, 56);

	Display(first);
}
