#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "main.h"

int main(int argc, char *argv[]) {
    void *handle;
    int (*add)(int, int), (*divi)(int, int), (*sub)(int, int), (*mul)(int, int);
    char *error;

    handle = dlopen("./libcal.so", RTLD_LAZY);
    if (!handle) {
        fputs(dlerror(), stderr);
        exit(1);
    }

    add = dlsym(handle, "add");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s", error);
        exit(1);
    }
    divi = dlsym(handle, "divi");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s", error);
        exit(1);
    }
    mul = dlsym(handle, "mul");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s", error);
        exit(1);
    }
    sub = dlsym(handle, "sub");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s", error);
        exit(1);
    }

   int num1, num2;
   if (argc < 3) {
       printf("사용법: %s <숫자1> <숫자2>\n", argv[0]);
       dlclose(handle);
   }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);

    printf("add(%d, %d) = %d\n", num1, num2, add(num1, num2));
    printf("sub(%d, %d) = %d\n", num1, num2, sub(num1, num2));
    printf("mul(%d, %d) = %d\n", num1, num2, mul(num1, num2));
    if (num2 != 0) {
        printf("divide(%d, %d) = %d\n", num1, num2, divi(num1, num2));
    } else {
        printf("0으로 나눌 수 없습니다.\n");
    }

    dlclose(handle);
}

