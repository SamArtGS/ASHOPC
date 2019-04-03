#include "Estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
void agregarEmpleado(){
    FILE * fq = NULL;
    char * line2 = NULL;
    size_t len2 = 0;
    ssize_t read2;
    char auxiliares1[20],auxiliares2[20],auxiliares3[20],auxiliares4[20],auxiliares5[20],auxiliares6[20];
    fq = fopen("usuarios.txt", "a");
    printf("Ingrese el nombre del nuevo empleado: ");
    scanf("%s",auxiliares1);
    printf("Ingrese el apellido del nuevo empleado: ");
    scanf("%s",auxiliares2);
    printf("Ingrese el nombre de usuario: ");
    scanf("%s",auxiliares3);
    printf("Ingrese la contraseña: ");
    scanf("%s",auxiliares4);
    printf("Ingrese su ROL (1 letra): (A) Administrador  (V) Vendedor  (C)Comprador");
    scanf("%s",auxiliares5);
    printf("Ingrese el sueldo: ");
    scanf("%s",auxiliares6);
    fprintf(fq, "\n");
    fprintf(fq, "%s\n",auxiliares1);
    fprintf(fq, "%s\n",auxiliares2);
    fprintf(fq, "%s\n",auxiliares3);
    fprintf(fq, "%s\n",auxiliares4);
    fprintf(fq, "%s\n",auxiliares5);
    fprintf(fq, "%s\n",auxiliares6);
    fclose(fq);
}
void estadistics(){
    return;
}
void cambiarDatosEmp(Empleado *emp){
    FILE *fptr1, *fptr2;
        int lno, linectr = 0;
        char str[20],fname[20];        
        char nombreel[20];
        
        fptr1 = fopen("usuarios.txt", "r");
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
        int datoCambio=0;
        char datoNuevo[20];
        printf("Ingrese el nombreUser del empleado a cambiar: \n");
        scanf("%s",nombreel);
        //printf("%d\n",strcmp(emp[2].usuario,nombreel));
        printf("¿Qué dato desea cambiar? \n0) Nombre \n1) Apellido \n2) NombreUser \n3) contrasena \n4) Area\n5)Sueldo\n");
        scanf("%d",&datoCambio);
        printf("Ingrese el nuevo dato: ");
        scanf("%s",datoNuevo);


        for(int j=0;j<cantidadEmp;j++){
                int moderador = j%7;
                switch(moderador){
                case 0:
                if(moderador==datoCambio&&strcmp(emp[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                    fprintf(fptr2, "%s", emp[j/7].nombre);
                }
                break;
                case 1:
                if(moderador==datoCambio&&strcmp(emp[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                fprintf(fptr2, "%s", emp[j/7].apellido);
                }
                break;
                case 2:
                if(moderador==datoCambio&&strcmp(emp[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                fprintf(fptr2, "%s", emp[j/7].usuario);
                }
                break;
                case 3:
                if(moderador==datoCambio&&strcmp(emp[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                    fprintf(fptr2, "%s", emp[j/7].pass);
                }
                break;
                case 4:
                if(moderador==datoCambio&&strcmp(emp[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                fprintf(fptr2, "%s", emp[j/7].area);
                }
                break;
                case 5:
                if(moderador==datoCambio&&strcmp(emp[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                    fprintf(fptr2, "%s", emp[j/7].sueldo);
                }
                break;
                case 6:
                fprintf(fptr2,"\n");
                break;
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("usuarios.txt");
        rename("temp.txt", "usuarios.txt");
        getchar();
        return;
    return;
}

void cambiarDatosPro(Producto *pro){
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
        int datoCambio=0;
        char datoNuevo[20];
        printf("Ingrese el ID del producto a cambiar: \n");
        scanf("%s",nombreel);
        //printf("%d\n",strcmp(emp[2].usuario,nombreel));
        printf("¿Qué dato desea cambiar? \n0) Nombre \n1) Apellido \n2) NombreUser \n3) contrasena \n4) Area\n5)Sueldo\n");
        scanf("%d",&datoCambio);
        printf("Ingrese el nuevo dato: ");
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
                fprintf(fptr2, "%s", pro[j/7].precioCompra);
                }
                break;
                case 4:
                if(moderador==datoCambio&&strcmp(pro[j/7].idArticulo,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
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
void agregarProducto(){
    FILE * fq = NULL;
    char * line2 = NULL;
    size_t len2 = 0;
    ssize_t read2;
    char auxiliares1[20],auxiliares2[20],auxiliares3[20],auxiliares4[20],auxiliares5[20],auxiliares6[20];
    fq = fopen("productos.txt", "a");
    printf("Ingrese el id del nuevo producto: ");
    scanf("%s",auxiliares1);
    printf("Ingrese el nombre del nuevo producto: ");
    scanf("%s",auxiliares2);
    printf("Ingrese el precio de compra del producto: ");
    scanf("%s",auxiliares3);
    printf("Ingrese el precio de venta del producto: ");
    scanf("%s",auxiliares4);
    printf("Ingrese la cantidad de productos inicial: ");
    scanf("%s",auxiliares5);
    printf("Ingrese el departamento al que pertenece: ");
    scanf("%s",auxiliares6);
    fprintf(fq, "\n");
    fprintf(fq, "%s\n",auxiliares1);
    fprintf(fq, "%s\n",auxiliares2);
    fprintf(fq, "%s\n",auxiliares3);
    fprintf(fq, "%s\n",auxiliares4);
    fprintf(fq, "%s\n",auxiliares5);
    fprintf(fq, "%s\n",auxiliares6);
    fprintf(fq, "\n");
    fclose(fq);
    sleep(5000);
    return;
}

void eliminarProducto(Producto *prod){
        FILE *fptr1, *fptr2;
        int lno, linectr = 0;
        char str[20],fname[20];        
        char nombrePro[20];
        
        fptr1 = fopen("productos.txt", "r");
        if (fptr1==NULL){
                printf("NO se pudo abrir!!\n");      
        }
        fptr2 = fopen("temp.txt", "w");
        if (fptr2==NULL) {
                printf("Error en archivo aux");
                fclose(fptr1);
        }
        int Cantdproducto = 0;
        int ch;
        while(!feof(fptr1)){
            ch = fgetc(fptr1);
            if(ch == '\n'){
                Cantdproducto++;
        }
        }
        Cantdproducto++;
        printf("Ingrese el ID del producto a eliminar: \n");
        scanf("%s",nombrePro);
        printf("%d\n",strcmp(prod[2].idArticulo,nombrePro));
        for(int j=0;j<Cantdproducto;j++){
            if(strcmp(prod[j/7].idArticulo,nombrePro)!=10){
                int moderador = j%7;
                switch(moderador){
                case 0:
                fprintf(fptr2, "%s", prod[j/7].idArticulo);
                break;
                case 1:
                fprintf(fptr2, "%s", prod[j/7].nombre);
                break;
                case 2:
                fprintf(fptr2, "%s", prod[j/7].precioCompra);
                break;
                case 3:
                fprintf(fptr2, "%s", prod[j/7].precioVenta);
                break;
                case 4:
                fprintf(fptr2, "%s", prod[j/7].cantidad);
                break;
                case 5:
                fprintf(fptr2, "%s", prod[j/7].depto);
                break;
                case 6:
                fprintf(fptr2,"\n");
                break;
            }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("productos.txt");
        rename("temp.txt", "productos.txt");
        getchar();
        return;
}
void eliminaEmpleado(Empleado *emp){
        FILE *fptr1, *fptr2;
        int lno, linectr = 0;
        char str[20],fname[20];        
        char nombreel[20];
        
        fptr1 = fopen("usuarios.txt", "r");
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
        printf("Ingrese el nombreUser del empleado a eliminar: \n");
        scanf("%s",nombreel);
        printf("%d\n",strcmp(emp[2].usuario,nombreel));
        for(int j=0;j<cantidadEmp;j++){
            if(strcmp(emp[j/7].usuario,nombreel)!=10){
                int moderador = j%7;
                switch(moderador){
                case 0:
                fprintf(fptr2, "%s", emp[j/7].nombre);
                break;
                case 1:
                fprintf(fptr2, "%s", emp[j/7].apellido);
                break;
                case 2:
                fprintf(fptr2, "%s", emp[j/7].usuario);
                break;
                case 3:
                fprintf(fptr2, "%s", emp[j/7].pass);
                break;
                case 4:
                fprintf(fptr2, "%s", emp[j/7].area);
                break;
                case 5:
                fprintf(fptr2, "%s", emp[j/7].sueldo);
                break;
                case 6:
                fprintf(fptr2,"\n");
                break;
            }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("usuarios.txt");
        rename("temp.txt", "usuarios.txt");
        getchar();
        return;
}

