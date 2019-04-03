#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "Estructuras.h"

void compraArticulo(Producto *pro ,Empleado emp){
    FILE *fptr1, *fptr2;
        int lno, linectr = 0;
        char str[20],fname[20];        
        char nombreel[20];
        
        fptr1 = fopen("productos.txt", "r");
        if (fptr1==NULL){
                printf("NO se pudo abrir!!\n");      
        }
        fptr2 = fopen("temp.txt", "w");
        if (fptr2==NULL) {
                printf("Error en archivo aux");
                fclose(fptr1);
        }
        int cantidadEmp = 0;
        int ch;
        while(!feof(fptr1)){
            ch = fgetc(fptr1);
            if(ch == '\n'){
                cantidadEmp++;
        }
        }
        cantidadEmp++;
        int datoCambio=4;
        char datoNuevo[20];
        printf("Ingrese el ID del producto a comprar: \n");
        scanf("%s",nombreel);
        //printf("%d\n",strcmp(emp[2].usuario,nombreel));
        //printf("¿Qué dato desea cambiar? \n0) Nombre \n1) Apellido \n2) NombreUser \n3) contrasena \n4) Area\n5)Sueldo\n");

        printf("Ingrese cuántos elementos comprará: ");
        scanf("%s",datoNuevo);
        for(int j=0;j<cantidadEmp;j++){
                int moderador = j%7;
                switch(moderador){
                case 0:
                if(moderador==datoCambio&&strcmp(pro[j/7].idArticulo,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                    fprintf(fptr2, "%s", pro[j/7].idArticulo);
                }
                break;
                case 1:
                if(moderador==datoCambio&&strcmp(pro[j/7].idArticulo,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                    fprintf(fptr2, "%s", pro[j/7].nombre);
                }
                break;
                case 2:
                if(moderador==datoCambio&&strcmp(pro[j/7].idArticulo,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                fprintf(fptr2, "%s", pro[j/7].precioCompra);
                }
                break;
                case 3:
                if(moderador==datoCambio&&strcmp(pro[j/7].idArticulo,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                    fprintf(fptr2, "%s", pro[j/7].precioVenta);
                }
                break;
                case 4:
                if(moderador==datoCambio&&strcmp(pro[j/7].idArticulo,nombreel)==10){
                    char chari[20];
                    sprintf(chari,"%d",(int)pro[j/7].cantidad + (int)datoNuevo);
                    fprintf(fptr2, "%s\n", chari);
                }else{
                    fprintf(fptr2, "%s", pro[j/7].cantidad);
                    
                }
                break;
                case 5:
                if(moderador==datoCambio&&strcmp(pro[j/7].idArticulo,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                    fprintf(fptr2, "%s", pro[j/7].depto);
                }
                break;
                case 6:
                fprintf(fptr2,"\n");
                break;
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("productos.txt");
        rename("temp.txt", "productos.txt");
        getchar();
        return;
}
void ventaArticulo(Producto *produ,Empleado emp){
    FILE * fq = NULL;
    char * line2 = NULL;
    fq = fopen("productos.txt", "r");
    int cps;
    int cantidadProd=0;
    while(!feof(fq)){
        cps = fgetc(fq);
        if(cps == '\n'){
            cantidadProd++;
        }
    }
    cantidadProd++;
    rewind(fq);
    char producto[11];
    int productoCan = 0;
    printf("-----------------\n");
    printf("\tVENTA DE PRODUCTO. \n");
    printf("--------------------\n");
    printf("\nProductos disponibles: \n");
    for(int i=0;i<cantidadProd/7;i++){
        if(produ[i].cantidad>0){
            printf("ID: %sNombre: %sPrecio: %s \n",produ[i].idArticulo,produ[i].nombre,produ[i].precioVenta);
        }
    }
    int productosCompra[30];
    int cantidads = 0;
    printf("Ingrese la cantidad de artículos que desea comprar: ");
    scanf("%d",&cantidads);
    int producs[cantidads];
    Producto *canasta = malloc(cantidads*sizeof(Producto));
    int conde=0;
    for(int p = 0;p<cantidads;p++){
        printf("Ingrese el ID del producto a comprar: ");
        scanf("%s",producto);
        printf("Ingrese la cantidad de productos de éste que quiera comprar: ");
        scanf("%d",&productoCan);
        for(int i=0;i<cantidadProd/7;i++){
            if(strcmp(produ[i].idArticulo, producto)==10){
                printf("%s \n",produ[i].cantidad);
                //producs[conde] = productoCan;
                canasta[conde] = produ[i];
                int aux = (int)produ[i].cantidad - productoCan;
                sprintf(produ[i].cantidad,"%d",aux);
                printf("%s \n",produ[i].cantidad);
                conde++;
            }else{
                printf("  ID PROD NO REGISTRADO  ");
            }
        }
    }





    printf("Le hemos generado su recibo: \n");
    FILE *fp;
    fp = fopen ("recibo.txt", "wr" );
    if (fp==NULL) {
        //fp = fopen ("recibo.txt", "wr");
        fputs ("Error al generar el recibo",stderr);
        return;
    }
    fprintf (fp, "\tTienda A Shop Retail\n");
    fprintf(fp, "\tAv. Proteco #33, Av. Tabasco 2000, Villahermosa, Tabasco.\n");
    fprintf(fp,"Empleado: %s",emp.nombre);
    fprintf(fp, "---------------\n\tRECIBO DE COMPRA\n---------------\n");
    int j,sub=0;
    for(j = 0; j < cantidads; j++){
        fprintf(fp, "%s - %s : $%s , Cantidad: %d   Sub: %d\n",canasta[j].idArticulo,canasta[j].nombre,canasta[j].precioVenta,producs[j],producs[j]);
        sub+=producs[j]*(int)canasta[j].precioVenta;
    }
    fprintf(fp, "\n\t TOTAL : $%d\n",sub);
    fprintf(fp, "\n\tA SHOP agradece su preferencia\n");
    fclose(fp);
    sleep(10);
}