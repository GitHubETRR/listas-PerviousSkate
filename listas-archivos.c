#include <stdio.h>
#include <stdlib.h>

typedef struct producto{
    char *nombre;
    float precio;
    int cantidad;
    struct producto *siguiente;
}producto;

typedef producto *puntero_lista;

void crear_producto(puntero_lista *comienzo);
void imprimir_lista(puntero_lista comienzo);
void borrar_lista(puntero_lista *comienzo);
void imprimir_listaProductotxt (puntero_lista *comienzo);

FILE* archivo;

int main(){
    int opcion;
    puntero_lista comienzo=NULL;  
    
    do{
        printf("----------MENU----------\n");
        printf("1- Ingresar producto\n");
        printf("2- Ver lista de producto\n");
        printf("3- Salir\n");
        printf("------------------------\n");
        do{
            scanf("%d",&opcion);
        }while((opcion!=1) && (opcion!=2) && (opcion!=3));
        if(opcion==1)crear_producto(&comienzo);
        if(opcion==2)imprimir_lista(comienzo);
    }while(opcion!=3);
    imprimir_listaProductotxt(&comienzo);
    borrar_lista(&comienzo);    
    return 0;
}

void crear_producto (puntero_lista *comienzo){
    puntero_lista p= malloc (sizeof(producto));
    p->siguiente=NULL;
    
    printf("Ingrese el nombre del producto\n");
    char *nombre=(char *)malloc(10);
    scanf("\n%[^\n]%*c",nombre);
    p->nombre=nombre;
    printf("Ingrese el valor del producto\n");
    scanf("%f",&(p->precio));
    printf("Ingrese la cantidad de stock que hay\n");
    scanf("%d",&(p->cantidad));
    p->siguiente=*comienzo;
    *comienzo=p;
}

void imprimir_lista (puntero_lista comienzo){
    char* nombretxt="listaProductos.txt";//nombre del archivo
    if((archivo=fopen(nombretxt,"a+b"))==NULL){
        printf("\n\n***EL ARCHIVO %s NO SE PUDO ABRIR***\n",nombretxt);
    }else{
        while(comienzo!=NULL){
            printf("Nombre del producto: %s \n",comienzo->nombre);
            printf("Precio del producto: %f \n",comienzo->precio);
            printf("Stock del producto: %d \n\n",comienzo->cantidad);
            comienzo=comienzo->siguiente;
        }
    }
}

void borrar_lista (puntero_lista *comienzo){
    puntero_lista actual;
    while(*comienzo!=NULL){
        actual=*comienzo;
        *comienzo=(*comienzo)->siguiente;
        free(actual->nombre);
        free(actual);
    }
}

void imprimir_listaProductotxt (puntero_lista *comienzo){
    fprintf(archivo,"%s %f %d\n",(*comienzo)->nombre,(*comienzo)->precio,(*comienzo)->cantidad);
}