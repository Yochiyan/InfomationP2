#define DATA_NUM 3 //データ件数
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NAME_LEN 64

typedef struct student {
    char name[NAME_LEN];
    int height;
    double weight;
} STUDENT;

int main(void)
{
    FILE* fp;
    STUDENT stdata;

 
    if ((fp = fopen("student.txt", "w")) == NULL) {
        printf("ファイルをオープンできません\n");
        return 1;
    }
    for (int i = 0; i < DATA_NUM; i++) {
        printf("氏名：");
        scanf("%s", stdata.name);

        printf("身長：");
        scanf("%d", &stdata.height);

        printf("体重：");
        scanf("%lf", &stdata.weight);

        /* 赤字（固定文字列）付きでファイルに書き込む */
        fprintf(fp, "氏名＝%s\n", stdata.name);
        fprintf(fp, "身長＝%d\n", stdata.height);
        fprintf(fp, "体重＝%lf\n", stdata.weight);
    }
    fclose(fp);

    /*--- (2) rモードで開き直し → fscanf → printf ---*/
    if ((fp = fopen("student.txt", "r")) == NULL) {
        printf("ファイルを再オープンできません\n");
        return 1;
    }
    printf("\nファイルから読み取ったデータ： \n");
    STUDENT readst;
    for (int i = 0; i < DATA_NUM; i++) {
        /* 赤字部分を含めて完全一致させる */
        fscanf(fp, "氏名＝%s\n", readst.name);
        fscanf(fp, "身長＝%d\n", &readst.height);
        fscanf(fp, "体重＝%lf\n", &readst.weight);



        /* 読み取った内容を画面へ表示 */
      
        printf("氏名：%s\n", readst.name);
        printf("身長：%d\n", readst.height);
        printf("体重：%.1f\n", readst.weight);
    }
    
    fclose(fp);
    return 0;
}
