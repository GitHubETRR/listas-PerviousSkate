#include <stdio.h>

int main()
{
    FILE* fichero;
    char ch[20];
    char chF;
    fichero = fopen("Productos.txt", "w+");
    fputs("Hola\n",fichero);
    while((ch[20]=getchar())!= '\n')
        putc(ch[20],fichero);
    rewind(fichero);
    while((chF=fgetc(fichero))!= EOF && chF != '\n');
    fgets(ch,20,fichero);
    printf("%s",ch);
    fclose(fichero);
    return 0;
}
