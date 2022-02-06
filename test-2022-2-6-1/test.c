#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "String.h"
int a;

int main()
{
	printf("%d\n", a);
	struct weapon {
		string name;
		int id;
		int damage; //伤害
		int speed; //速度
		string attribute;//属性
		string refining;//炼化
	};
	struct weapon P1;
	P1.id = 10;
	InitString(&P1.name);
	PushBackStrString(&P1.name, "铁剑");
	P1.damage = 2;
	P1.speed = 2;
	InitString(&P1.attribute);
	PushBackStrString(&P1.attribute, "无");
	InitString(&P1.refining);
	PushBackStrString(&P1.refining, "钢剑");
	printf("id:%d\n名为:%s\n伤害%d\n速度:%d\n攻击属性:%s\n升级;%s\n", P1.id, P1.name.str, P1.damage, P1.speed, P1.attribute.str, P1.refining.str);

	struct weapon P2;
	P2.id = 11;
	InitString(&P2.name);
	PushBackStrString(&P2.name, "匕首");
	P2.damage = 1;
	P2.speed = 3;
	InitString(&P2.attribute);
	PushBackStrString(&P2.attribute, "无");
	printf("id:%d\n名为:%s\n伤害%d\n速度:%d\n攻击属性:%s\n", P2.id, P2.name.str, P2.damage, P2.speed, P2.attribute.str);

	struct weapon P3;
	P3.id = 12;
	InitString(&P3.name);
	PushBackStrString(&P3.name, "刀");
	P3.damage = 3;
	P3.speed = 2;
	InitString(&P3.attribute);
	PushBackStrString(&P3.attribute, "无");
	printf("id:%d\n名为:%s\n伤害%d\n速度:%d\n攻击属性:%s\n", P3.id, P3.name.str, P3.damage, P3.speed, P3.attribute.str);
	struct weapon P4;
	P4.id = 13;
	InitString(&P4.name);
	PushBackStrString(&P4.name, "斧头");
	P4.damage = 4;
	P4.speed = 1;
	InitString(&P4.attribute);
	PushBackStrString(&P4.attribute, "无");
	printf("id:%d\n名为:%s\n伤害%d\n速度:%d\n攻击属性:%s\n", P4.id, P4.name.str, P4.damage, P4.speed, P4.attribute.str);
	struct weapon P5;
	P5.id = 14;
	InitString(&P5.name);
	PushBackStrString(&P5.name, "西洋剑");
	P5.damage = 1;
	P5.speed = 4;
	InitString(&P5.attribute);
	PushBackStrString(&P5.attribute, "无");
	printf("id:%d\n名为:%s\n伤害%d\n速度:%d\n攻击属性:%s\n", P5.id, P5.name.str, P5.damage, P5.speed, P5.attribute.str);

	return 0;
}