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

void show_banner() {
    printf("Expression Evaluator 1.0\nBy YangJunbo(yangjunbo@360.cn) 12/22/23\n");
}

void show_usage() {
    printf("Usage:\n\t-e \"<expression>\"\tExecute the expression presented.\n\t-v\t\t\tShow version.\n");
}

void exec_interact() {
    show_banner();
    while (1) {
        reset();
        printf(">>>");
        fgets(infix_expr, EXPR_LEN_MAX, stdin);
        if (!strcmp("quit\n", infix_expr)) break;
        if (!strcmp("test\n", infix_expr)) {
            test();
            continue;
        }
        calc();
    }
}

int deal_options(int argc, void **args) {
    if (argc == 1) {
        exec_interact();
    } else if (argc == 2) {
        if (!strcmp(args[1], "-v")) {
            show_banner();
            return 0;
        } else if (!strcmp(args[1], "-h")) {
            show_usage();
            return 0;
        }
    } else if (argc > 2) {
        for (int i = 1; i < argc - 1; i ++) {
            if (!strcmp(args[i], "-e")) {
                i ++;
                reset();
                strncpy(infix_expr, args[i], EXPR_LEN_MAX);
                calc();
                return 0;
            }
        }
        show_usage();
        return 0;
    } else {
        show_usage();
        return 0;
    }
}

int main(int argc, void **args) {
    init_op_token_tbl();

    return deal_options(argc, args);    
}
