#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Algoritmo de Cifra de Viginere.
A cifra de Vigenère é um método de encriptação
que usa um série de diferentes cifras de César
baseadas em letras de uma senha.
*/

static int nChar(char *plaintext)
{
    int cont = 0;
    for (; *plaintext; plaintext++)
        cont++;
    return cont;
}

void encode(char *plaintext, char *keyword)
{
    int i;
    int size = nChar(plaintext);
    int sizekey = nChar(keyword);
    int cont = 0;
    for (i = 0; i < size; i++)
    {
        printf("%c", plaintext[i] + keyword[cont] - 'A');
        if (cont == sizekey - 1)
            cont = 0;
        else
            cont++;
    }
}
int decode(char *plaintext, char *keyword)
{
    int i;
    int size = nChar(plaintext);
    int sizekey = nChar(keyword);
    int cont = 0;
    for (i = 0; i < size; i++)
    {
        printf("%c", plaintext[i] - keyword[cont] + 'A');
        if (cont == sizekey - 1)
            cont = 0;
        else
            cont++;
    }
}

int main()
{
    system("cls");
    encode("LOREM IPSUM DOLOR SIT AMET, CONSECTETUR ADIPISCING ELIT, SED DO EIUSMOD TEMPOR INCIDIDUNT UT LABORE ET DOLORE MAGNA ALIQUA.", "CIRCUS");
    puts("\n");
    decode("NWcGa2KXdWa2FW]Qf2UQe\"U_G\\=\"WaP[VEhWV]c\"UVKXZUW[PO1G`[V41UYV\"L`\"Y[W[^QX2VM^Rcd\"Q_E]VKLfPh2W\\1NUTQZV\"Yf\"L`NcdG(^C[`C(RN]cWI?", "CIRCUS");
    return 0;
}
