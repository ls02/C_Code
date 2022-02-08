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
        //����ͣ����cur1��cur2�ǿ��ˣ���ôĬ����0
        int val1 = cur1 ? cur1->val : 0;
        int val2 = cur2 ? cur2->val : 0;
        sum = val1 + val2 + flags;

        //�����Ƿ�Ϊ�ս��в�ͬ��ʽ�Ĳ���
        if (head)
        {
            curHead->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            curHead = curHead->next;
            curHead->next = NULL;
            //�Ѹ�λ��ֵ��ȥ
            curHead->val = sum % 10;
        }
        else
        {
            head = (struct ListNode*)malloc(sizeof(struct ListNode));
            curHead = head;
            curHead->next = NULL;
            //�Ѹ�λ��ֵ��ȥ
            curHead->val = sum % 10;
        }

        //ͳ�ƽ�λ
        flags = sum / 10;

        //cur1��cur2�����Ϊ�վ͵���
        if (cur1)
        {
            cur1 = cur1->next;
        }

        if (cur2)
        {
            cur2 = cur2->next;
        }
    }

    //����λ�����������˵����Ҫ��λ
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

	//�ж��Ƿ����0ʹ���Զ���EPS
	if (fabs((x - y) - 0.1) < EPS && fabs((x - y)- 0.1) > -EPS)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	//�ж��Ƿ����ʹ���Զ���EPS
	if (fabs((x - y) - 0.1) < EPS)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	//�ж��Ƿ����0 DBL_EPSILON
	if (fabs((x - y) - 0.1) < DBL_EPSILON && fabs((x - y) - 0.1) > -DBL_EPSILON)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	//�ж��Ƿ���� DBL_EPSILON
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