//
// Created by 杨钧博 on 2023/12/22.
//
#include "token.h"
#include "result.h"
#include "parser.h"
#include <stdio.h>
#include <string.h>

extern char infix_expr[EXPR_LEN_MAX];
extern void reset();
extern void calc();

void test() {
    reset();
    strcpy(infix_expr, "-(((1+4)^2+5)-(9)^(-1/2))");
    calc();

    reset();
    strcpy(infix_expr, "(-1+3)/2-4.32-(-1)");
    calc();

    reset();
    strcpy(infix_expr, "5*((-2+5)+21/3+((8-(-2))*2.5))");
    calc();

    reset();
    strcpy(infix_expr, "0-(-1-2)+3*4");
    calc();

    reset();
    strcpy(infix_expr, "-((3+2)*sin(3.141592654/2)+10+cos(3.141592654))");
    calc();
}

int main() {
    init_op_token_tbl();
    printf("Expression Evaluator 1.0\nBy YangJunbo(yangjunbo@360.cn) 12/22/23\n");
    while (1) {
        reset();
        printf(">>>");
//        scanf("%s", infix_expr);
        fgets(infix_expr, EXPR_LEN_MAX, stdin);
        if (!strcmp("quit\n", infix_expr)) break;
        if (!strcmp("test\n", infix_expr)) {
            test();
            continue;
        }
        calc();
    }

    return 0;
}
