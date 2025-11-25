#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NAME_LEN 64

struct student {
	char name[NAME_LEN];
	int height;
	double weight;
	double shoesize;
};

int main(void)
{
	struct student students[3];
	int i; // 

	// 入力ループ
	for (i = 0; i < 3; i++) {
		printf("\n%d人目の名前を入力してください：", i + 1);
		scanf("%s", students[i].name);

		printf("%d人目の身長を入力してください(cm)：", i + 1);
		scanf("%d", &students[i].height);

		printf("%d人目の体重を入力してください(kg)：", i + 1);
		scanf("%lf", &students[i].weight);

		printf("%d人目の靴サイズを入力してください：", i + 1);
		scanf("%lf", &students[i].shoesize);
	}

	// 出力ループ
	printf("\n学生の情報：\n");
	for (i = 0; i < 3; i++) {
		printf("%d人目: %s, 身長: %d cm, 体重: %.2f kg, 靴サイズ: %.1f\n",
			i + 1,
			students[i].name,
			students[i].height,
			students[i].weight,
			students[i].shoesize
		);
	}

	return 0;
}
