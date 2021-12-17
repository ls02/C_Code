#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}

	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	if (!cur)
	{
		printf("malloc fail\n");
		
		exit(-1);
	}
	cur->_data = a[*pi];
	(*pi)++;

	cur->_left = BinaryTreeCreate(a, n, pi);
	cur->_right = BinaryTreeCreate(a, n, pi);

	return cur;
}

// 二叉树
void BinaryTreeDestory(BTNode** root)
{
	if (!*root)
	{
		return;
	}

	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);

	free(*root);
	*root = NULL;
	
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	return !root ? 0 : BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (!root)
	{
		return 0;
	}

	if (!root->_left && !root->_right)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (!root)
	{
		return 0;
	}

	if (k)
	{
		return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
	}

	return 1;
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (!root)
	{
		return NULL;
	}

	if (root->_data == x)
	{
		return root;
	}

	BTNode* left = BinaryTreeFind(root->_left, x);

	if (left)
	{
		return left;
	}

	BTNode* right = BinaryTreeFind(root->_right, x);

	if (right)
	{
		return right;
	}

	return NULL;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");

		return;
	}

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");

		return;
	}

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");

		return;
	}

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;

	QueueInit(&q);

	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->_data);

		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}

		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}

	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (!front)
		{
			break;
		}

		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			return false;
		}
	}

	QueueDestroy(&q);

	return true;
}


BTNode* BinarrTreeBuy(BTDataType x)
{
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));

	if (!cur)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	cur->_data = x;
	cur->_left = NULL;
	cur->_right = NULL;

	return cur;
}

void Test1()
{
	BTNode* A = BinarrTreeBuy('A');
	BTNode* B = BinarrTreeBuy('B');
	BTNode* C = BinarrTreeBuy('C');
	BTNode* D = BinarrTreeBuy('D');
	BTNode* E = BinarrTreeBuy('E');
	BTNode* F = BinarrTreeBuy('F');
	BTNode* G = BinarrTreeBuy('G');

	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = G;
	C->_left = E;
	C->_right = F;

	BinaryTreePostOrder(A);
	putchar('\n\n');

	printf("第k层的节点个数：%d\n\n", BinaryTreeLevelKSize(A, 3));

	printf("二叉树的节点个数:%d\n\n", BinaryTreeSize(A));

	printf("叶子节点个数:%d\n\n", BinaryTreeLeafSize(A));

	printf("%p\n%p\n", BinaryTreeFind(A, 'C'), BinaryTreeFind(A, 'P'));
	putchar('\n\n');

	BinaryTreeLevelOrder(A);

	putchar('\n\n');

	printf("%d ", BinaryTreeComplete(A));

	BinaryTreeDestory(&A);

}

void Test2()
{
	char arr[] = "ABD##E#H##CF##G##";
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
		
	BTNode* root = BinaryTreeCreate(arr, size, &i);

	BinaryTreePrevOrder(root);
}

int main()
{
	Test2();

	return 0;
}