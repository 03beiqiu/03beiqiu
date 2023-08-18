//#include<stdio.h>
//int my_strlen(char* arr)
//{
//    if (*arr != '\0')
//        return 1 + my_strlen(arr + 1);
//    else
//        return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//    int len = my_strlen(arr);
//    printf("len = % d \n", len);
//    return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//	int x = 10;
//	int y = 30;
//	int z = ADD(x, y);
//	printf("%d\n", z);
//	return 0;
//}
#include<stdio.h>
void squl(int x)
{
	if (x > 9)
	{
		squl(x/10);
	}
		printf("%d ",x%10);
}
int main()
{
	int num = 0;
	scanf_s("%d", &num);
	squl(num);
	return 0;
}