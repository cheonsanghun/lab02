#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int midscore;
    int finalscore;
    struct Student* left;
    struct Student* right;
} Student;

Student* insertStudent(Student* root, const char* name, int midscore, int finalscore) {
    if (root == NULL) {
        Student* newStudent = (Student*)malloc(sizeof(Student));
        strcpy(newStudent->name, name);
        newStudent->midscore = midscore;
        newStudent->finalscore = finalscore;
        newStudent->left = NULL;
        newStudent->right = NULL;
        return newStudent;
    }

    if (midscore < root->midscore) {
        root->left = insertStudent(root->left, name, midscore, finalscore);
    } else if (midscore > root->midscore) {
        root->right = insertStudent(root->right, name, midscore, finalscore);
    }

    return root;
}

void search_midscore(Student* root, int midscore) {
    if (root == NULL) {
        return;
    }

    if (midscore < root->midscore) {
        search_midscore(root->left, midscore);
    } else if (midscore > root->midscore) {
        search_midscore(root->right, midscore);
    } else {
        printf("이름: %s, mid Score: %d, final score: %d\n", root->name, root->midscore, root->finalscore);
        
        search_midscore(root->right, midscore);
    }
}

void freeTree(Student* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int numStudents;
    printf("학생 수를 입력하세요: ");
    scanf("%d", &numStudents);

    Student* root = NULL;

    for (int i = 0; i < numStudents; i++) {
        char name[50];
        int midscore, finalscore;

        printf("학생 이름을 입력하세요: ");
        scanf("%s", name);
        printf("중간 점수를 입력하세요: ");
        scanf("%d", &midscore);
        printf("기말 점수를 입력하세요: ");
        scanf("%d", &finalscore);

        root = insertStudent(root, name, midscore, finalscore);
    }

    int searchmidscore;
    printf("검색할 중간 점수를 입력하세요: ");
    scanf("%d", &searchmidscore);
    search_midscore(root, searchmidscore);

    freeTree(root);

    return 0;
}

