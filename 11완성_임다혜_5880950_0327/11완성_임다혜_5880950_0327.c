#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    int score;
    struct Student* next; // �����ͷ� ���� ����Ʈ ���·� �л��� ����
};

void inputStudent(struct Student* s) {
    printf("�л��� ������ �Է��ϼ��� (�̸� �й� ����) : ");
    // scanf_s���� ���ڿ��� �Է¹��� �� ���� ũ�⸦ ����
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
    printf("�ش� �й��� �л��� �����ϴ�.\n");
}

int main() {
    int numOfStudents, i;
    struct Student* head = NULL, * temp = NULL, * last = NULL;

    // �л� �� �Է�
    printf("����� �л� ������ �Է��Ͻó���? ");
    scanf_s("%d", &numOfStudents);

    // �л� ���� �Է�
    for (i = 0; i < numOfStudents; i++) {
        temp = (struct Student*)malloc(sizeof(struct Student));
        inputStudent(temp);

        // ���� ����Ʈ�� �߰�
        if (head == NULL) {
            head = temp;
            last = temp;
        }
        else {
            last->next = temp;
            last = temp;
        }
        temp->next = NULL; // ���� NULL�� ����
    }

    // �й� �˻�
    int searchId;
    while (1) {
        printf("�й��� �Է��ϼ���(0�̸� ����) ? ");
        scanf_s("%d", &searchId);

        if (searchId == 0) {
            break; // ���� ����
        }
        searchStudent(head, searchId);
    }

    // �޸� ����
    temp = head;
    while (temp != NULL) {
        struct Student* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
