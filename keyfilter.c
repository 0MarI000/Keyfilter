#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char adr[42][100];
char Enabled[100];          // Pripustne znaky pro dalsi hledani
char KeyInput[100];         //
char Result[100];           // Vysledek hledani - pouze v pripade jedine shody
int Count;                  // Pocet zaznamu v seznamu adres
int NextMatches;            // Pocet nasledujicich moznych shod


int Read_address(char** str, int* len)
{
char c;
int line = 0;
int position = 0;
    while ((c = getchar()) != EOF)
        {
            adr[line][position] = toupper(c);
            if (c == '\n')
            {
                line++;
                position = 0;
                Count ++;
            }
            else 
            position++;
            
        }
    *str = &adr[0][0];
    Count++;
    return 0;
    
}



int CheckEnabled( char c )
{
    bool result = false;

    for (int i = 0; i < 100; i++)
    {
        if (Enabled[i] == c)
        {
            NextMatches++;
            return true;
        }
        else
        {
            if (Enabled[i] == '\0')
            {
                Enabled[i] = c;
                NextMatches++;
                return false;
            }
        }
    }
    return result;
}



void GetEnabled( )
{
    char NextChar = '.';
    int InputLen = strlen(KeyInput);
    int NextPos = InputLen;
    int MatchCount;
    //int EnabledCount = 0;

    NextMatches = 0;
    for (int idx = 0; idx < Count; idx++)
    {
        MatchCount = 0;
        for (int pos = 0; pos < InputLen; pos++)
        {
            if (KeyInput[pos] == adr[idx][pos]) MatchCount++;
        }
        if (MatchCount == InputLen)
        {
            NextChar = adr[idx][NextPos];
            CheckEnabled(NextChar);
            strcpy(Result, adr[idx]);
        }
    }
}

int main(int argc, char** argv)
{
    char* adr;
    int len;
    Read_address(&adr, &len);
    strcpy(KeyInput, argv[1]);
    GetEnabled();

    switch (NextMatches)
    {
        case 0:     printf("Not Found");
                    break;
        case 1:     printf("Found: %s", Result);
                    break;
        default:    printf("Enabled: %s", Enabled);
    }
    return 0;
}