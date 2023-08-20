#include <stdio.h>
#include <string.h>
struct Student {
	int stuID;
	char name[10];
	int achievement;
}stu1;
int main()
{
	stu1.stuID = 211010101;
	strcpy(stu1.name, "lisi");
	stu1.achievement = 90;
	printf("%d %s %d", stu1.stuID, stu1.name, stu1.achievement);
	return 0;
}
