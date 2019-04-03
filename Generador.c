#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "funcionesVarias.h"
#include "funcionesEmp.h"
#include "funcionesAdmin.h"
//ESTRUCTURAS REQUERIDAS



int main(int argc, char **argv){
    //DEPARTAMENTOS DISPONIBLES
    
    Departamento *deptosD = malloc(7*sizeof(Departamento));
    strcpy(deptosD[0].nombre,"Comida");
    strcpy(deptosD[1].nombre,"Ropa");
    strcpy(deptosD[2].nombre,"Licores");
    strcpy(deptosD[3].nombre,"LaSantaBiblia");
    strcpy(deptosD[4].nombre,"Papeleria");
    strcpy(deptosD[5].nombre,"Lavanderia");
    strcpy(deptosD[6].nombre,"Extra");



    int salir=1;
    do{
    //ARCHIVO DE USUARIOS ASIGNARLOS A LOS ARRAYS
    Empleado *emp = lecturaUsuarios();
    //APERTURA DE LOS ARCHIVOS PRODUCTOS
    Producto *productos = lecturaProducto();
    

    //Para hacer la asignación de productos por departamentos y recuento general.
    FILE * fq = NULL;
    char * line2 = NULL;
    fq = fopen("usuarios.txt", "r");
    int cps;
    int cak=0;
    while(!feof(fq)){
        cps = fgetc(fq);
        if(cps == '\n'){
            cak++;
        }
    }
    cak++;
    rewind(fq);
    printf("%d\n",cak);
    //Bloque de pruebas
    int opcion = 0;
    do{
    int usuario = acceso(emp,cak);
    printf("ACCEDISTE!\n");
    system("clear");
    system("figlet A - SHOP");
    char tipo;
    if(strcmp(emp[usuario].area,"A") == 10){
        printf("\n\t0)Salir \n\t1) Agregar un usuario \n\t2) Eliminar un usuario \n\t3) Modificar Usuario\n\t4) Agregar tipo de producto \n\t5) Eliminar tipo de producto \n\t6)Modificar producto\n\t 7)Ver estadísticas\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 0:
            opcion=0;
            break;
            case 1:
            agregarEmpleado();
            free(emp);
            emp = lecturaUsuarios();
            break;
            case 2:
            fclose(fq);
            eliminaEmpleado(emp);
            free(emp);
            emp = lecturaUsuarios();
            break;
            case 3:
            cambiarDatosEmp(emp);
            free(emp);
            emp = lecturaUsuarios();
            break;
            case 4:
            agregarProducto();
            free(productos);
            productos = lecturaProducto();
            break;
            case 5:
            eliminarProducto(productos);
            free(productos);
            productos = lecturaProducto();
            break;
            case 6:
            cambiarDatosPro(productos);
            free(productos);
            productos = lecturaProducto();
            break;
            case 7:
            printf("La empresa gasta %d en empleados. \n",dineroEmp());
            printf("La empresa tiene %d en productos. \n",dineroProductos());
            estadistica();
            break;
            default:
            break;
        }
    }else {
        if(strcmp(emp[usuario].area, "V")==10){
            printf("\n\t0)Salir 1) Vender un producto \n\t 2) Inventario\n");
            scanf("%d",&opcion);
            switch(opcion){
            case 0:
            opcion=0;
            break;
            case 1:
            ventaArticulo(productos,emp[usuario]);
            free(productos);
            productos = lecturaProducto();
            break;
            case 2:
            estadistica();
            default:
            break;
        }
            //
        }else{
            printf("\n \t0)Salir 1) Comprar productos para la tienda \n \t 2) Inventario\n");
            scanf("%d",&opcion);
            switch(opcion){
            case 0:
            opcion=0;
            break;
            case 1:
            compraArticulo(productos,emp[usuario]);
            free(productos);
            productos = lecturaProducto();
            break;
            case 2:
            estadistica();
            default:
            break;
        }
        }
    }
    }while(opcion!=0);
    printf("¿Desea salir? 0) SÍ  OTRA COSA NÚMERO: NO\n");
    scanf("%d",&salir);
    getchar();
    fclose(fq);
    //free(fq);
    }while(salir!=0);
    return 0;
}

