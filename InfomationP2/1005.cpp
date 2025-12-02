#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NAME_LEN 64 // 名前の文字数
#define DATA_NUM 3 // データ件数
//=== 学生を表す構造体 ===//
typedef struct student {
	char name[NAME_LEN]; // 名前
	int height; // 身長
	double weight; // 体重
} STUDENT;
// データの入力とファイルへの書き込み
void KinFwrite(STUDENT* stdata, int data_num, FILE* fp) {
	for (int i = 0; i < data_num; i++) {
		printf("氏名："); scanf("%s", stdata->name);
		printf("身長："); scanf("%d", &stdata->height);
		printf("体重："); scanf("%lf", &stdata->weight);
		fwrite(stdata, sizeof(STUDENT), 1, fp);
	}
}
// ファイルからデータを読み込む、読み込んだデータを画面に出力する
void FinDispout(STUDENT* stdata, int data_num, FILE* fp) {
	for (int i = 0; i < data_num; i++) {
		fread(stdata, sizeof(STUDENT), 1, fp);
		// 読み込んだデータを画面に出力する
		printf("氏名＝%s\n", stdata->name);
		printf("身長＝%d\n", stdata->height);
		printf("体重＝%.1f\n", stdata->weight);
	}
}
int main(void)
{
	STUDENT stdata;
	FILE* fp;
	// ファイルを開く（書き込みモード）
	fp = fopen("student.dat", "wb");
	if (fp == NULL) {
		printf("ファイルを開けませんでした。\n");
		return 1;
	}
	// データの入力とファイルへの書き込み
	KinFwrite(&stdata, DATA_NUM, fp);
	// ファイルを閉じる
	fclose(fp);
	// ファイルを開く（読み込みモード）
	fp = fopen("student.dat", "rb");
	if (fp == NULL) {
		printf("ファイルを開けませんでした。\n");
		return 1;
	}
	// ファイルからデータを読み込む、読み込んだデータを画面に出力する
	printf("ファイルから読み込んだデータ:\n");
	FinDispout(&stdata, DATA_NUM, fp);
	// ファイルを閉じる
	fclose(fp);
	return 0;
}