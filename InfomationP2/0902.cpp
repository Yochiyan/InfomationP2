#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
#define NAME_LEN 64

struct student {
	char name[NAME_LEN];
	int height;
	double weight;
	double shoesize;
};

int main(void)
{
	struct student takao = { "Takao", 170,53.6,26.7 };

	printf("氏名 = %s\n", takao.name);
	printf("身長 = %d\n", takao.height);
	printf("体重 = %.1f\n", takao.weight);
	printf("靴のサイズ = %.1f\n", takao.shoesize);
	return 0;
}
