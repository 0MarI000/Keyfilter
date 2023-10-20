#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Moc malo argumentu! \n");
        return 1;
    }
    int i = 0;
    int c;

    printf("Zadejte znak k vyfiltrování: \n");
    c = getchar();
    while (argv[1][i] != '\0'){
        if (argv[1][i] != c){
            putchar(argv[1][i]);
        }
        i++;
    }
    printf("\n");
    return 0;
}