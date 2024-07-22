//
// Created by 杨钧博 on 2023/12/22.
//
#include "token.h"
#include "result.h"
#include "parser.h"
#include <stdio.h>
#include <string.h>

void test() {
    ee_parser_reset();
    ee_parser_setexpr("-(((1+4)^2+5)-(9)^(-1/2))");
    calc();

    ee_parser_reset();
    ee_parser_setexpr("(-1+3)/2-4.32-(-1)");
    calc();

    ee_parser_reset();
    ee_parser_setexpr("5*((-2+5)+21/3+((8-(-2))*2.5))");
    calc();

    ee_parser_reset();
    ee_parser_setexpr("0-(-1-2)+3*4");
    calc();

    ee_parser_reset();
    ee_parser_setexpr("-((3+2)*sin(3.141592654/2)+10+cos(3.141592654))");
    calc();
}

void show_banner() {
    printf("Expression Evaluator 1.0\nBy YangJunbo(yangjunbo@360.cn) 12/22/23\n");
}

void show_usage() {
    printf("Usage:\n\t[-e <'expression'>] | ...\tExecute the expression presented.\n\t[-v]\t\t\t\tShow version.\n\t[-h]\t\t\t\tShow help.\n");
}

void exec_interact() {
    show_banner();
    while (1) {
        ee_parser_reset();
        printf(">>>");
        ee_parser_stdin();
        if (!strcmp("quit\n", ee_parser_expr_seq())) break;
        if (!strcmp("test\n", ee_parser_expr_seq())) {
            test();
            continue;
        }
        calc();
    }
}

int run_options(int argc, void **args) {
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
                ee_parser_reset();
                ee_parser_setexpr(args[i]);
                calc();
            }
        }
        return 0;
    } else {
        show_usage();
        return 0;
    }
}

int main(int argc, void **args) {
    init_op_token_tbl();
    ee_init_parser();

    int ret = run_options(argc, args);
    ee_uninit_parser();
    return ret;
}
