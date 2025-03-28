#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    int score;
    struct Student* next; // 포인터로 연결 리스트 형태로 학생들 저장
};

void inputStudent(struct Student* s) {
    printf("학생의 정보를 입력하세요 (이름 학번 점수) : ");
    // scanf_s에서 문자열을 입력받을 때 버퍼 크기를 지정
    scanf_s("%s %d %d", s->name, (unsigned)_countof(s->name), &s->id, &s->score);
}

void searchStudent(struct Student* head, int searchId) {
    struct Student* current = head;
    while (current != NULL) {
        if (current->id == searchId) {
            printf("%s %d %d\n", current->name, current->id, current->score);
            return;
        }
        current = current->next;
    }
    printf("해당 학번의 학생이 없습니다.\n");
}

int main() {
    int numOfStudents, i;
    struct Student* head = NULL, * temp = NULL, * last = NULL;

    // 학생 수 입력
    printf("몇명의 학생 정보를 입력하시나요? ");
    scanf_s("%d", &numOfStudents);

    // 학생 정보 입력
    for (i = 0; i < numOfStudents; i++) {
        temp = (struct Student*)malloc(sizeof(struct Student));
        inputStudent(temp);

        // 연결 리스트에 추가
        if (head == NULL) {
            head = temp;
            last = temp;
        }
        else {
            last->next = temp;
            last = temp;
        }
        temp->next = NULL; // 끝을 NULL로 설정
    }

    // 학번 검색
    int searchId;
    while (1) {
        printf("학번을 입력하세요(0이면 종료) ? ");
        scanf_s("%d", &searchId);

        if (searchId == 0) {
            break; // 종료 조건
        }
        searchStudent(head, searchId);
    }

    // 메모리 해제
    temp = head;
    while (temp != NULL) {
        struct Student* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
