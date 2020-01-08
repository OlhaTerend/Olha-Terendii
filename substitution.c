
//
//Get key
//validate key
//get plaintext
//encipher
//printciphertext
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define sizeStrNew 255
#define Qletter 26

int ValidateKey(char *Key);
void encipher(char *Key, char *Str, char *StrNew);

int main(int argc, char *argv[])
{
    string Str;
    char StrNew[sizeStrNew], ch;
    char Key[Qletter];
    int  i, Len, ik, sizeSk, il;
//    unsigned int kod;
//    unsigned short kk1;
//    int cont = 1;

    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int ra = ValidateKey(argv[1]);

    if (ra == 1)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    else
    {
        strcpy(Key, argv[1]);
    }

    Str = get_string("Enter string: "); //input our string
    Len = strlen(Str);

    encipher(Key, Str, StrNew);


    printf("plaintext:\t");
    for (i = 0; i < Len; ++i)
    {
        printf("%c", Str[i]);
    }
    printf("\nciphertext:\t");

    for (i = 0; i < Len; ++i)
    {
        printf("%c", StrNew[i]);
    }
    printf("\n");

    return 0;
}


int ValidateKey(char *Key)
{
    if (strlen(Key) != Qletter)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < Qletter; ++i)
        {
            if (!(isalpha(Key[i])))
            {
                return 1;
            }
            else //control unical
            {
                for (int l = 0; l < Qletter; ++l)
                {
                    Key[l]  = toupper(Key[l]);
                }
                for (int j = 0; j < i && j < Qletter; ++j)
                {
                    if (Key[i] == Key[j])
                    {
                        return 1;
                    }
                }
                for (int j1 = i + 1; j1 < Qletter; ++j1)
                {
                    if (Key[i] == Key[j1])
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void encipher(char *Key, char *Str, char *StrNew)
{
    int ind;
    int Len = strlen(Str);
    for (int i = 0; i < Len; ++i)
    {
        if (isalpha(Str[i]))
        {
            if (isupper(Str[i]))
            {
                ind =  Str[i] - 'A';
                StrNew[i] = Key[ind];
            }
            else
            {
                ind = toupper(Str[i]) - 'A';
                StrNew[i] = tolower(Key[ind]);
            }
        }
        else
        {
            StrNew[i] = Str[i];
        }
    }
}

