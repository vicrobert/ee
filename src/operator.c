//
// Created by 杨钧博 on 2023/12/25.
//
#include "operator.h"
#include "token.h"
#include <string.h>
#include <math.h>

func_tbl_entry_t op_func_tbl[FUNC_TBL_SIZE] = {
        {OP_NULL, NULL}, //PADDING
        {OP_ADD, calc_add},
        {OP_MINUS, calc_minus},
        {OP_MULT, calc_mult},
        {OP_DIV, calc_div},
        {OP_REMMAIND, calc_remaind},
        {OP_LBRAC, NULL},
        {OP_RBRAC, NULL},
        {OP_POWER, calc_power},
        /** 9-20 reserved for extending **/
        {OP_SIN, calc_sin},
        {OP_COS, calc_cos},
        {OP_TAN, calc_tan},
        {OP_CTAN, calc_ctan},
        /** 9-20 end **/
        {OP_NULL, NULL}, //PADDING
        {OP_NULL, NULL}, //PADDING
        {OP_NULL, NULL}, //PADDING
        {OP_NULL, NULL}, //PADDING
        {OP_NULL, NULL}, //PADDING
        {OP_NULL, NULL}, //PADDING
        {OP_NULL, NULL}, //PADDING
        {OP_LN, calc_ln},
        {OP_LOG2, calc_log2},
        {OP_LOG10, calc_log10},
        {OP_FACTOR, calc_factor},
        {OP_SINH, calc_sinh},
        {OP_COSH, calc_cosh},
        {OP_TANH, calc_tanh},
        {OP_ASIN, calc_asin},
        {OP_ACOS, calc_acos},
        {OP_ATAN, calc_atan},
        {OP_EXP, calc_exp},
        {OP_SQRT, calc_sqrt},
        {OP_CEIL, calc_ceil},
        {OP_FLOOR, calc_floor},
        {OP_FABS, calc_fabs},
        {OP_TGAMMA, calc_tgamma}
};


token_t op_token_tbl[OP_TBL_SIZE] = {0};
void init_op_token_tbl() {
    // op code
    op_token_tbl['+'].op_code = OP_ADD;
    op_token_tbl['+'].token_type = BIN_OP;
    op_token_tbl['+'].op_prior = 1;
    op_token_tbl['+'].lexeme[0] = '+';
    op_token_tbl['+'].lex_len = 1;
    op_token_tbl['-'].op_code = OP_MINUS;
    op_token_tbl['-'].token_type = BIN_OP;
    op_token_tbl['-'].op_prior = 1;
    op_token_tbl['-'].lexeme[0] = '-';
    op_token_tbl['-'].lex_len = 1;
    op_token_tbl['*'].op_code = OP_MULT;
    op_token_tbl['*'].token_type = BIN_OP;
    op_token_tbl['*'].op_prior = 2;
    op_token_tbl['*'].lexeme[0] = '*';
    op_token_tbl['*'].lex_len = 1;
    op_token_tbl['/'].op_code = OP_DIV;
    op_token_tbl['/'].token_type = BIN_OP;
    op_token_tbl['/'].op_prior = 2;
    op_token_tbl['/'].lexeme[0] = '/';
    op_token_tbl['/'].lex_len = 1;
    op_token_tbl['%'].op_code = OP_REMMAIND;
    op_token_tbl['%'].token_type = BIN_OP;
    op_token_tbl['%'].op_prior = 2;
    op_token_tbl['%'].lexeme[0] = '%';
    op_token_tbl['%'].lex_len = 1;
    op_token_tbl['('].op_code = OP_LBRAC;
    op_token_tbl['('].token_type = OP;
    op_token_tbl['('].op_prior = 0;
    op_token_tbl['('].lexeme[0] = '(';
    op_token_tbl['('].lex_len = 1;
    op_token_tbl[')'].op_code = OP_RBRAC;
    op_token_tbl[')'].token_type = OP;
    op_token_tbl[')'].op_prior = 0;
    op_token_tbl[')'].lexeme[0] = ')';
    op_token_tbl[')'].lex_len = 1;
    op_token_tbl['^'].op_code = OP_POWER;
    op_token_tbl['^'].token_type = BIN_OP;
    op_token_tbl['^'].op_prior = 2;
    op_token_tbl['^'].lexeme[0] = '^';
    op_token_tbl['^'].lex_len = 1;
    op_token_tbl['!'].op_code = OP_FACTOR;
    op_token_tbl['!'].token_type = UN_OP;
    op_token_tbl['!'].op_prior = 2;
    op_token_tbl['!'].lexeme[0] = '!';
    op_token_tbl['!'].lex_len = 1;
    //from pos 256 to start high-level function
    //sin
    op_token_tbl[256].op_code = OP_SIN;
    op_token_tbl[256].token_type = UN_OP;
    op_token_tbl[256].op_prior = 1;
    op_token_tbl[256].lex_len = 3;
    //cos
    op_token_tbl[257].op_code = OP_COS;
    op_token_tbl[257].token_type = UN_OP;
    op_token_tbl[257].op_prior = 1;
    op_token_tbl[257].lex_len = 3;
    //tan
    op_token_tbl[258].op_code = OP_TAN;
    op_token_tbl[258].token_type = UN_OP;
    op_token_tbl[258].op_prior = 1;
    op_token_tbl[258].lex_len = 3;
    //ctan
    op_token_tbl[259].op_code = OP_CTAN;
    op_token_tbl[259].token_type = UN_OP;
    op_token_tbl[259].op_prior = 1;
    op_token_tbl[259].lex_len = 4;
    //loge
    op_token_tbl[267].op_code = OP_LN;
    op_token_tbl[267].token_type = UN_OP;
    op_token_tbl[267].op_prior = 1;
    op_token_tbl[267].lex_len = 2;
    //log2
    op_token_tbl[268].op_code = OP_LOG2;
    op_token_tbl[268].token_type = UN_OP;
    op_token_tbl[268].op_prior = 1;
    op_token_tbl[268].lex_len = 4;
    //log10
    op_token_tbl[269].op_code = OP_LOG10;
    op_token_tbl[269].token_type = UN_OP;
    op_token_tbl[269].op_prior = 1;
    op_token_tbl[269].lex_len = 5;
    //sinh
    op_token_tbl[270].op_code = OP_SINH;
    op_token_tbl[270].token_type = UN_OP;
    op_token_tbl[270].op_prior = 1;
    op_token_tbl[270].lex_len = 4;
    //cosh
    op_token_tbl[271].op_code = OP_COSH;
    op_token_tbl[271].token_type = UN_OP;
    op_token_tbl[271].op_prior = 1;
    op_token_tbl[271].lex_len = 4;
    //tanh
    op_token_tbl[272].op_code = OP_TANH;
    op_token_tbl[272].token_type = UN_OP;
    op_token_tbl[272].op_prior = 1;
    op_token_tbl[272].lex_len = 4;
    //asin
    op_token_tbl[273].op_code = OP_ASIN;
    op_token_tbl[273].token_type = UN_OP;
    op_token_tbl[273].op_prior = 1;
    op_token_tbl[273].lex_len = 6;
    //acos
    op_token_tbl[274].op_code = OP_ACOS;
    op_token_tbl[274].token_type = UN_OP;
    op_token_tbl[274].op_prior = 1;
    op_token_tbl[274].lex_len = 6;
    //atan
    op_token_tbl[275].op_code = OP_ATAN;
    op_token_tbl[275].token_type = UN_OP;
    op_token_tbl[275].op_prior = 1;
    op_token_tbl[275].lex_len = 6;
    //exp
    op_token_tbl[276].op_code = OP_EXP;
    op_token_tbl[276].token_type = UN_OP;
    op_token_tbl[276].op_prior = 1;
    op_token_tbl[276].lex_len = 3;
    //sqrt
    op_token_tbl[277].op_code = OP_SQRT;
    op_token_tbl[277].token_type = UN_OP;
    op_token_tbl[277].op_prior = 1;
    op_token_tbl[277].lex_len = 4;
    //ceil
    op_token_tbl[278].op_code = OP_CEIL;
    op_token_tbl[278].token_type = UN_OP;
    op_token_tbl[278].op_prior = 1;
    op_token_tbl[278].lex_len = 4;
    //floor
    op_token_tbl[279].op_code = OP_FLOOR;
    op_token_tbl[279].token_type = UN_OP;
    op_token_tbl[279].op_prior = 1;
    op_token_tbl[279].lex_len = 5;
    //fabs
    op_token_tbl[280].op_code = OP_FABS;
    op_token_tbl[280].token_type = UN_OP;
    op_token_tbl[280].op_prior = 1;
    op_token_tbl[280].lex_len = 3;
    //tgamma
    op_token_tbl[281].op_code = OP_TGAMMA;
    op_token_tbl[281].token_type = UN_OP;
    op_token_tbl[281].op_prior = 1;
    op_token_tbl[281].lex_len = 5;
    //copy lexme
    strncpy(op_token_tbl[256].lexeme, "sin", op_token_tbl[256].lex_len);
    strncpy(op_token_tbl[257].lexeme, "cos", op_token_tbl[257].lex_len);
    strncpy(op_token_tbl[258].lexeme, "tan", op_token_tbl[258].lex_len);
    strncpy(op_token_tbl[259].lexeme, "ctan", op_token_tbl[259].lex_len);
    strncpy(op_token_tbl[267].lexeme, "ln", op_token_tbl[267].lex_len);
    strncpy(op_token_tbl[268].lexeme, "log2", op_token_tbl[268].lex_len);
    strncpy(op_token_tbl[269].lexeme, "log10", op_token_tbl[269].lex_len);
    strncpy(op_token_tbl[270].lexeme, "sinh", op_token_tbl[270].lex_len);
    strncpy(op_token_tbl[271].lexeme, "cosh", op_token_tbl[271].lex_len);
    strncpy(op_token_tbl[272].lexeme, "tanh", op_token_tbl[272].lex_len);
    strncpy(op_token_tbl[273].lexeme, "arcsin", op_token_tbl[273].lex_len);
    strncpy(op_token_tbl[274].lexeme, "arccos", op_token_tbl[274].lex_len);
    strncpy(op_token_tbl[275].lexeme, "arctan", op_token_tbl[275].lex_len);
    strncpy(op_token_tbl[276].lexeme, "exp", op_token_tbl[276].lex_len);
    strncpy(op_token_tbl[277].lexeme, "sqrt", op_token_tbl[277].lex_len);
    strncpy(op_token_tbl[278].lexeme, "ceil", op_token_tbl[278].lex_len);
    strncpy(op_token_tbl[279].lexeme, "floor", op_token_tbl[279].lex_len);
    strncpy(op_token_tbl[280].lexeme, "abs", op_token_tbl[280].lex_len);
    strncpy(op_token_tbl[281].lexeme, "gamma", op_token_tbl[281].lex_len);
}

token_t * map_op_token_tbl(char * lex) {
    int i;
    if (op_token_tbl[lex[0]].op_code != OP_NULL)
        return &op_token_tbl[lex[0]];
    for (i = 256; i < OP_TBL_SIZE; i ++) {
        if (strlen(lex) == op_token_tbl[i].lex_len 
            && !strcmp(lex, op_token_tbl[i].lexeme)) {
            return &op_token_tbl[i];
        }
    }
    return NULL;
}
#define UNUSED(x) ((x) == (x))

token_t * calc_add(token_t * dst, token_t * op1, token_t * op2) {
    set_token_value(dst, op1->value + op2->value);
    return dst;
}

token_t * calc_minus(token_t * dst, token_t * op1, token_t * op2) {
    set_token_value(dst, op1->value - op2->value);
    return dst;
}

token_t * calc_mult(token_t * dst, token_t * op1, token_t * op2) {
    set_token_value(dst, op1->value * op2->value);
    return dst;
}

token_t * calc_div(token_t * dst, token_t * op1, token_t * op2) {
    set_token_value(dst, op1->value / op2->value);
    return dst;
}

token_t * calc_remaind(token_t * dst, token_t * op1, token_t * op2) {
    set_token_value(dst, fmod(op1->value, op2->value));
    return dst;
}

token_t * calc_power(token_t * dst, token_t * op1, token_t * op2) {
    set_token_value(dst, pow(op1->value, op2->value));
    return dst;
}

// 三角函数
token_t * calc_sin(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op1);
    set_token_value(dst, sin(op1->value));
    return dst;
}

token_t * calc_cos(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, cos(op1->value));
    return dst;
}

token_t * calc_tan(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, tan(op1->value));
    return dst;
}

token_t * calc_ctan(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, 1 / tan(op1->value));
    return dst;
}

// e为底对数
token_t * calc_ln(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, log(op1->value));
    return dst;
}

// 2为底对数
token_t * calc_log2(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, log2(op1->value));
    return dst;
}

// 10为底对数
token_t * calc_log10(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, log10(op1->value));
    return dst;
}

//阶乘
token_t * calc_factor(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    double res = 1;
    for (int i = 2; i <= op1->value; i ++)
        res *= i;
    set_token_value(dst, res);
    return dst;
}

//双曲正弦
token_t * calc_sinh(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, sinh(op1->value));
    return dst;
}

//双曲函数
token_t * calc_cosh(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, cosh(op1->value));
    return dst;
}

//双曲正切
token_t * calc_tanh(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, tanh(op1->value));
    return dst;
}

//反正弦
token_t * calc_asin(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, asin(op1->value));
    return dst;
}

//反余弦
token_t * calc_acos(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, acos(op1->value));
    return dst;
}

//反正切
token_t * calc_atan(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, atan(op1->value));
    return dst;
}

//自然指数
token_t * calc_exp(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, exp(op1->value));
    return dst;
}

//算术平方根
token_t * calc_sqrt(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, sqrt(op1->value));
    return dst;
}

//天棚运算
token_t * calc_ceil(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, ceil(op1->value));
    return dst;
}

//地板运算
token_t * calc_floor(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, floor(op1->value));
    return dst;
}

//绝对值
token_t * calc_fabs(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, fabs(op1->value));
    return dst;
}

//伽马函数
token_t * calc_tgamma(token_t * dst, token_t * op1, token_t * op2) {
    UNUSED(op2);
    set_token_value(dst, tgamma(op1->value));
    return dst;
}
