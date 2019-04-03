#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "Estructuras.h"
int acceso(Empleado *emp,int cak){
    system("clear");
    bool bandera = true;
    int usuario;
    do{
    char nombreusuario[20];
    char contrasena[20];
    system(" figlet BIENVENIDO");
    printf("\t\nIngrese su nombre de usuario: ");
    scanf("%[^\n]s",nombreusuario);
    getchar();
    printf("\n\tIngrese su contraseña: ");
    scanf("%[^\n]s",contrasena);
    getchar();
    int i;
    for(i=0;i<cak/7;i++){
        if(strcmp(emp[i].usuario,nombreusuario)==10&&strcmp(emp[i].pass,contrasena)==10){
            usuario = i;
            bandera = false;
            break;
        }else{
            printf("  INCORRECTO  ");
            system("clear");
        }
    }
    }while(bandera);
    return usuario;
}

Producto *lecturaProducto(){
    FILE * fq = NULL;
    char * line2 = NULL;
    size_t len2 = 0;
    ssize_t read2;
    fq = fopen("productos.txt", "r");
    int cps;
    int cantidadProd=0;
    while(!feof(fq)){
        cps = fgetc(fq);
        if(cps == '\n'){
            cantidadProd++;
        }
    }
    rewind(fq);
    int varApoyo2 = cantidadProd/7;
    Producto *productos = malloc(varApoyo2*sizeof(Producto));;
    int contador = 0;
    while ((read2 = getline(&line2, &len2, fq)) != -1) {
        int moderador2 = contador%7;
        switch(moderador2){
            case 0:
                strcpy(productos[contador/7].idArticulo,line2);
                //printf("ID Producto %s",productos[contador/7].idArticulo);
                break;
            case 1:
                strcpy(productos[contador/7].nombre,line2);
                //printf("Nombre Producto %s",productos[contador/7].nombre);
                break;
            case 2:
                strcpy(productos[contador/7].precioCompra,line2);
                //printf("Precio Compra: %s",productos[contador/7].precioCompra);
                break;
            case 3:
                strcpy(productos[contador/7].precioVenta,line2);
                //printf("Precio Venta: %s",productos[contador/7].precioVenta);
                break;
            case 4:
                strcpy(productos[contador/7].cantidad,line2);
                //printf("Cantidad %s",productos[contador/7].cantidad);
                break;
            case 5:
                strcpy(productos[contador/7].depto,line2);
                //printf("Departamento %s",productos[contador/7].depto);
                break;
            case 6:
                //printf("\n");
                break;
        }
        contador++;
    }
    fclose(fq);
    return productos;
}
Empleado* lecturaUsuarios(){
    FILE * fp = NULL;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int cantidadEmp=0;
    fp = fopen("usuarios.txt", "r");
    
    int conta = 0;
    int ch;

    while(!feof(fp)){
        ch = fgetc(fp);
        if(ch == '\n'){
            cantidadEmp++;
        }
    }
    cantidadEmp++;
    rewind(fp);
    int varApoyo1 = cantidadEmp/7;
    Empleado *emp = malloc(varApoyo1*sizeof(Empleado));
    while ((read = getline(&line, &len, fp)) != -1) {
        int moderador = conta%7;
        switch(moderador){
            case 0:
            strcpy(emp[conta/7].nombre,line);
            //printf("Nombre %s",emp[conta/7].nombre);
            break;
            case 1:
            strcpy(emp[conta/7].apellido,line);
            //printf("Apellido %s",emp[conta/7].apellido);
            break;
            case 2:
            strcpy(emp[conta/7].usuario,line);
            //printf("user %s",emp[conta/7].usuario);
            break;
            case 3:
            strcpy(emp[conta/7].pass,line);
            //printf("Contrasena %s",emp[conta/7].pass);
            break;
            case 4:
            strcpy(emp[conta/7].area,line);
            //printf("area %s",emp[conta/7].area);
            break;
            case 5:
            strcpy(emp[conta/7].sueldo,line);
            //printf("sueldo %s",emp[conta/7].sueldo);
            break;
            case 6:
            printf("\n");
            break;
        }
        conta++;
    }
    fclose(fp);
    return emp;
}
void estadistica(){
	FILE * fp = NULL;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int cantidadEmp=0;
    fp = fopen("usuarios.txt", "r");
    
    int conta = 0;
    int ch;

    while(!feof(fp)){
        ch = fgetc(fp);
        if(ch == '\n'){
            cantidadEmp++;
        }
    }
    cantidadEmp++;
    rewind(fp);
    int varApoyo1 = cantidadEmp/7;
    Empleado *emp = malloc(varApoyo1*sizeof(Empleado));
    while ((read = getline(&line, &len, fp)) != -1) {
        int moderador = conta%7;
        switch(moderador){
            case 0:
            strcpy(emp[conta/7].nombre,line);
            printf("Nombre %s",emp[conta/7].nombre);
            break;
            case 1:
            strcpy(emp[conta/7].apellido,line);
            printf("Apellido %s",emp[conta/7].apellido);
            break;
            case 2:
            strcpy(emp[conta/7].usuario,line);
            printf("user %s",emp[conta/7].usuario);
            break;
            case 3:
            strcpy(emp[conta/7].pass,line);
            printf("Contrasena %s",emp[conta/7].pass);
            break;
            case 4:
            strcpy(emp[conta/7].area,line);
            printf("area %s",emp[conta/7].area);
            break;
            case 5:
            strcpy(emp[conta/7].sueldo,line);
            printf("sueldo %s",emp[conta/7].sueldo);
            break;
            case 6:
            printf("\n");
            break;
        }
        conta++;
    }
    printf("\n PRESIONES UNA TECLA Y ENTER PARA CONTINUAR \n");
    char jeje[1];
    scanf("%s",jeje);
    fclose(fp);
}