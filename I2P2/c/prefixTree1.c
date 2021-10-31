#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXEXPR 256
char expr[MAXEXPR];
typedef enum
{
    VAR_A,  // 0
    VAR_B,  // 1
    VAR_C,  // 2
    VAR_D,  // 3
    OP_AND, // 5
    OP_OR,  // 5
    END     // 6
} TokenSet;
char sym[] = "ABCD&|";      // sym[0]=A,sym[1]=B...
TokenSet getNext(int reset) // get next var
{
    static int idx; // static int avilable in global every time you call idx the value retain the same
    TokenSet ret = END;
    int i;
    if (reset) // if 1 :true 0 :false
    {
        idx = 0;
        return END;
    }
    while (expr[idx] != '\0' && isspace(expr[idx])) // still have things to read skip /0
        idx++;
    if (expr[idx] == '\0') // nothing inside the array
    {
        return END;
    }
    else
    {
        for (i = 0; (size_t)i < strlen(sym); i++)
        {
            if (sym[i] == expr[idx])
                ret = i; // enum 0,1,2,3,4...
        }
        idx++;
        return ret; // match token
    }
}
int evaluate(int A, int B, int C, int D)
{
    TokenSet tok;
    tok = getNext(0);//find next char
    if (tok == END)
    {
        tok = getNext(1); // set index to 0
        return evaluate(A, B, C, D);
    }
    else if (tok == OP_AND || tok == OP_OR) // if tok == operator
    {
        int expr_val1, expr_val2;
        expr_val1 = evaluate(A, B, C, D); // 1 or 0
        expr_val2 = evaluate(A, B, C, D); // 1 or 0
        if (tok == OP_AND)
        {
            return (expr_val1 && expr_val2);
        }
        else// OP_OR
        {
            return (expr_val1 || expr_val2);
        }
    }
    else
    {
        switch (tok)
        {
        case VAR_A:
            return A;
        case VAR_B:
            return B;
        case VAR_C:
            return C;
        case VAR_D:
            return D;
        default:
            return -1;
        }
    }
}

int main()
{
    size_t len;
    int i;
    fgets(expr, sizeof(expr), stdin); // read not exceed limit sizeof(expr)
    len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n')
    {
        --len;
        expr[len] = '\0'; //把換行符號用、0替換
    }
    // 0 --> 0000
    // 1 --> 0001
    // 2 --> 0011...
    // 15 --> 1111
    // masking method if i & 8 >>3 (checking left unit if 1)
    for (i = 0; i < 16; i++) // 0-15
    {
        printf("%d%d%d%d: %d\n", (i & 8) >> 3, ｀(i & 4) >> 2, (i & 2) >> 1, i & 1,
               evaluate((i & 8) >> 3, (i & 4) >> 2, (i & 2) >> 1, i & 1));
    }
    return 0;
}
/*
if (tok==OP_AND) {
return (expr1 && expr2);
} else {
return (expr1 || expr2);
}
*/