#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NAME_LEN 64 //名前の文字数

/*学生を表す構造体*/
typedef struct student  {
	char	name[NAME_LEN]; //名前
	int	height;							 //身長
	double	weight;				   //体重
}STUDENT;

int main(void) 
{
	FILE * fp;
	if ((fp = fopen("student.txt", "w")) == NULL)
	printf("\aファイルをオープンできません\n");
	else {
		STUDENT stdata;

		printf("氏名：");	scanf("%s", stdata.name);
		printf("身長：");	scanf("%d", &stdata.height);
		printf("体重：");	scanf("%lf", &stdata.weight);
	

		fprintf(fp,"氏名：%s\n", stdata.name);
		fprintf(fp,"身長：%d\n", stdata.height);
		fprintf(fp,"体重：%.1f\n", stdata.weight);
		fclose(fp);
	}
	return 0;
}