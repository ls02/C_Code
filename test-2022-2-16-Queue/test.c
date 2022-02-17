#include "Queue.h"

void TestQueue1(void)
{
	Queue q1;
	QueueInit(&q1);

	QueuePush(&q1, 0);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	QueuePush(&q1, 4);
	QueuePush(&q1, 5);

	printf("数据大小：%d", QueueSize(&q1));
	putchar('\n');

	while (!QueueEmpty(&q1))
	{
		printf("%d ", QueueFront(&q1));

		QueuePop(&q1);
	}
	putchar('\n');

	printf("数据大小：%d", QueueSize(&q1));

	QueueDestroy(&q1);
}

int main()
{
	TestQueue1();

	return 0;
}