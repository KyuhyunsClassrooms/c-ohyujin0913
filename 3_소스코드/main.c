#include <stdio.h>
#include <string.h>

// 영상 정보 구조체
struct Video {
    char name[30];
    char type[20];
    int length;
    char date[12];
    float rate;
};

struct Video list[100];
int num = 0;

// 함수 선언
void add();
void show();
void search();
void avg();

int main() {
    int choice;
    printf("--- Video Manager ---\n");

    while (1) {
        printf("\n1. Add  2. Show  3. Search  4. Avg  0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if(choice==1) add();
        else if(choice==2) show();
        else if(choice==3) search();
        else if(choice==4) avg();
        else if(choice==0){ printf("Exit\n"); break;}
        else printf("Wrong choice\n");
    }
    return 0;
}

// 영상 등록 (scanf만 사용)
void add() {
    if(num>=100){ printf("Full\n"); return;}

    printf("Name (no space): ");
    scanf("%s", list[num].name);
    printf("Type (no space): ");
    scanf("%s", list[num].type);
    printf("Length(min): ");
    scanf("%d", &list[num].length);
    printf("Date(YYYY-MM-DD): ");
    scanf("%s", list[num].date);
    printf("Rate(1~5): ");
    scanf("%f", &list[num].rate);

    num++;
    printf("Added!\n");
}

// 영상 목록 보기
void show() {
    if(num==0){ printf("No videos\n"); return;}
    for(int i=0;i<num;i++){
        printf("번호: %d\n", i+1);
        printf("이름: %s\n", list[i].name);
        printf("종류: %s\n", list[i].type);
        printf("길이: %d분\n", list[i].length);
        printf("날짜: %s\n", list[i].date);
        printf("평점: %.1f\n", list[i].rate);
        printf("----------------------\n");
    }
}

// 영상 검색 (scanf만 사용)
void search() {
    if(num==0){ printf("No videos\n"); return;}
    char n[30];
    printf("Search name: ");
    scanf("%s", n);

    for(int i=0;i<num;i++){
        if(strcmp(list[i].name, n)==0){
            printf("이름: %s\n", list[i].name);
            printf("종류: %s\n", list[i].type);
            printf("길이: %d분\n", list[i].length);
            printf("날짜: %s\n", list[i].date);
            printf("평점: %.1f\n", list[i].rate);
            return;
        }
    }
    printf("Not found\n");
}

// 평균 평점
void avg() {
    if(num==0){ printf("No videos\n"); return;}
    float sum=0;
    for(int i=0;i<num;i++) sum+=list[i].rate;
    printf("Avg rate: %.2f\n",sum/num)
}
