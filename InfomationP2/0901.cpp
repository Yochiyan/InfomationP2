#define _CRT_SECURE_NO_WARNINGS
# include<stdio.h>
# include<string.h>
#define NAME_LEN 64 //名前の文字数

/*学生を表す構造体*/
struct student {
	char name[NAME_LEN]; //名前
	int height;							 //身長
	double weight;				   //体重
	double shoessize;		   //靴のサイズ
};

int main(void) {
	struct student sanaka;
	strcpy(sanaka.name, "Sanaka");
	sanaka.height = 175;
	sanaka.weight = 62.5;
	sanaka.shoessize = 25.5;

	printf("名前: %s\n", sanaka.name);
	printf("身長: %dcm\n", sanaka.height);
	printf("体重: %.1fkg\n", sanaka.weight);
	printf("靴のサイズ: %.1fcm\n", sanaka.shoessize);

	return 0;
}
