#include<stdio.h>
#include<stdlib.h>

#define N 10

struct Node *Insert(struct Node *root, int data);
void Scaner(struct Node *root);
int Search(struct Node *root,int data);

struct Node
{
	int data;
	struct Node *lchild;
	struct Node *rchild;
};

int main()
{
	struct Node *root;
	int data, i;
	int tree[N];

	printf("Please input some numbers:\n");
	for(i = 0;i < N;i++)
		scanf("%d",&tree[i]);

	root = NULL;
	for(i = 0;i < N;i++)
	{
		data = tree[i];
		root = Insert(root,data);
	}

	Scaner(root);
	printf("\n");

	printf("Please input one key:\n");
	scanf("%d",&data);
	if(Search(root,data))
		printf("²éÕÒ³É¹¦£¡\n");
	else
		printf("²éÕÒÊ§°Ü£¡\n");

	return 0;
}
//¹¹½¨¶þ²æÊ÷	µÝ¹é
struct Node *Insert(struct Node *root, int data)
{
	struct Node *s;
	
	s = (struct Node *)malloc(sizeof(struct Node));

	s->data = data;
	s->lchild = NULL;
	s->rchild = NULL;

	if(root == NULL)
		root = s;
	else
	{
		if(root->data == s->data)
			return root;
		else
		{
			if(s->data > root->data)
				root->rchild = Insert(root->rchild,s->data);
			else
				root->lchild = Insert(root->lchild,s->data);
		}
	}

	return root;
}
//¶þ²æÊ÷Êä³ö	µÝ¹é
void Scaner(struct Node *root)
{
	if(root == NULL)
		return;

	Scaner(root->lchild);
	printf("%d	",root->data);
	Scaner(root->rchild);
}
//¶þ²æÊ÷²éÕÒ	µÝ¹é
int Search(struct Node *root,int data)
{
	if(root == NULL)
		return 0;
	else
	{
		if(root->data == data)
			return 1;
		else if(root->data < data)
			return Search(root->rchild,data);
		else
			return Search(root->lchild,data);
	}
}