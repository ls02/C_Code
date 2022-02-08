#include <stdio.h>
#include <math.h>
#include <float.h>
#define EPS 0.0000001

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* curHead = head;
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    int sum = 0;
    int flags = 0;

    while (cur1 || cur2)
    {
        //计算和，如果cur1和cur2是空了，那么默认是0
        int val1 = cur1 ? cur1->val : 0;
        int val2 = cur2 ? cur2->val : 0;
        sum = val1 + val2 + flags;

        //根据是否为空进行不同方式的插入
        if (head)
        {
            curHead->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            curHead = curHead->next;
            curHead->next = NULL;
            //把个位赋值过去
            curHead->val = sum % 10;
        }
        else
        {
            head = (struct ListNode*)malloc(sizeof(struct ListNode));
            curHead = head;
            curHead->next = NULL;
            //把个位赋值过去
            curHead->val = sum % 10;
        }

        //统计进位
        flags = sum / 10;

        //cur1和cur2如果不为空就迭代
        if (cur1)
        {
            cur1 = cur1->next;
        }

        if (cur2)
        {
            cur2 = cur2->next;
        }
    }

    //检查进位符，如果还有说明需要进位
    if (flags)
    {
        curHead->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curHead = curHead->next;
        curHead->next = NULL;
        curHead->val = flags;
    }

    return head;
}

int main()
{
	double x = 1.0;
	double y = 0.9;

	//判断是否等于0使用自定义EPS
	if (fabs((x - y) - 0.1) < EPS && fabs((x - y)- 0.1) > -EPS)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	//判断是否相等使用自定义EPS
	if (fabs((x - y) - 0.1) < EPS)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	//判断是否等于0 DBL_EPSILON
	if (fabs((x - y) - 0.1) < DBL_EPSILON && fabs((x - y) - 0.1) > -DBL_EPSILON)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	//判断是否相等 DBL_EPSILON
	if (fabs((x - y) - 0.1) < DBL_EPSILON)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	return 0;
}

////#include <stdbool.h>
////bool a = 10;
//float b = 20.3f;
//_Bool c = 30;
//
//int main()
//{
//	//printf("%d\n", sizeof a);
//	printf("%d\n", sizeof c);
//default
//	return 0;
//}