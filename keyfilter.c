#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//definuji si maximalni delku seznamu adres (1 adresa max o 100 znacich a min 42 radku adres)
#define MAX_LEN (100 * 42) + 1

//vytvorim si funkci, ktera bude ziskavat hodnoty ze seznamu adres
void read_ad(char** str, int* len)
{
char adr[MAX_LEN];
char c;
int i = 0;
    while ((c = getchar()) != EOF)
        {
            
            adr[i] = c;
            i++;
        }
    *str = &adr[0];
    *len = i;
}


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Pocatecni pismena adresy nebyla zadana/nalezena\n");
        return 1;
    }
    char* adr;
    int len;
    read_ad(&adr, &len);
    int i = 0;
    //int l = 0;
    //char curr = adr[i];
    //int coloop = 0;
    while(i < MAX_LEN && i < len)
    {
        if (argv[1][i] != adr[i])
        {
            printf("not found ");
            break;            
        }
        else
        {   
            do
            {
                if (argv[1][i] != adr[i])
                {
                    printf("FOUND: %c", adr[i]);
                    break;           
                }
                else if (argv[1][i] == adr[i])
                {
                    i++;
                }
                
            } while (adr[i] != '\n' || adr[i] != '\0');
        }
       
       
        
        
        //printf("%c", adr[i]);
        
        i++;
        if (argv[1][i] != adr[i])
        {            
            break;            
        }
        
    }
    
    /*
    printf("\n");
    int k = 0;
    do
    {
        printf("%c", argv[1][k]);
        k++;
        
    }
    while (argv[1][k] != '\0');
    */

    return 0;
}