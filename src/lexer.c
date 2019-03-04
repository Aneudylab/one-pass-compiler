#include "global.h"

char lexbuf[BSIZE];
int  lineno = 1;
int  tokenval = NONE;

int lexan()                             // analizador léxico
{
    int t;
    while (1) {
        t = getchar();
        if (t == ' ' || t == '\t')
            ;                           // elimina los espacios en blanco
        else if (t == '\n')
            lineno = lineno + 1;
        else if (isdigit(t)) {          // t es un dígito
            ungetc(t, stdin);
            scanf("%d", &tokenval);
            return NUM;
        }
        else if (isalpha(t)) {          // t es una letra
            int p, b = 0;
            while (isalnum(t)) {        // t es alfanumérico
                lexbuf[b] = t;
                t = getchar();
                b = b + 1;
                if (b >= BSIZE)
                    error("compiler error");
            }
            lexbuf[b] = EOS;
            if (t != EOF)
                ungetc(t, stdin);
            p = lookup(lexbuf);
            if (p == 0)
                p = insert(lexbuf, ID);
            tokenval = p;
            return symtable[p].token;
        }
        else if (t == EOF)
            return DONE;
        else {
            tokenval = NONE;
            return t;
        }
    }
}
