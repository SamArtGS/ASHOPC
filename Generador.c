#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
//ESTRUCTURAS REQUERIDAS
typedef struct {
    char nombre[20];
    char apellido[20];
    char usuario[20];
    char pass[20];
    char area[20];
    char sueldo[20];
}Empleado;

//Venta de empleado
typedef struct {
    char producto[10];
    int venta;
    char fecha[9];
}Ventas;

typedef struct{
    char idArticulo[20];
    char nombre[20];
    char precioCompra[20];
    char precioVenta[20];
    char cantidad[20];
    char depto[20];
}Producto;

typedef struct{
    char nombre[20];
    int cantidadProdTotal;
    char **productos;
    int MoneyTotalDepto;
}Departamento;
Empleado *lecturaUsuarios();
Producto *lecturaProducto();

//void ventaArticulo(Producto produ[],Empleado emp);
void agregarProducto();
void ventaArticulo(Producto *produ,Empleado emp);
void agregarEmpleado();
int acceso(Empleado *emp,int cak);
void eliminaEmpleado(Empleado *emp);
void eliminarProducto(Producto *prod);
void cambiarDatosEmp(Empleado *emp);
void cambiarDatosPro(Producto *pro);


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
            break;
            default:
            break;
        }
    }else {
        if(strcmp(emp[usuario].area, "V")==10){
            printf("\n\t0)Salir 1) Vender un producto \n\t 2)Checar ventas realizadas\n");
            scanf("%d",&opcion);
            switch(opcion){
            case 0:
            opcion=0;
            break;
            case 1:
            ventaArticulo(productos,emp[usuario]);
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
            agregarProducto();
            free(productos);
            productos = lecturaProducto();
            break;
            case 4:
            eliminarProducto(productos);
            productos = lecturaProducto();
            break;
            default:
            break;
        }
            //
        }else{
            printf("\n \t0)Salir 1) Comprar productos para la tienda \n \t 2) Inventario\n");
            scanf("%d",&opcion);
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
                if(moderador==datoCambio&&strcmp(pro[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                    fprintf(fptr2, "%s", pro[j/7].nombre);
                }
                break;
                case 1:
                if(moderador==datoCambio&&strcmp(pro[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                fprintf(fptr2, "%s", pro[j/7].apellido);
                }
                break;
                case 2:
                if(moderador==datoCambio&&strcmp(pro[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                fprintf(fptr2, "%s", pro[j/7].usuario);
                }
                break;
                case 3:
                if(moderador==datoCambio&&strcmp(pro[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                fprintf(fptr2, "%s", pro[j/7].pass);
                }
                break;
                case 4:
                if(moderador==datoCambio&&strcmp(pro[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                fprintf(fptr2, "%s", pro[j/7].area);
                }
                break;
                case 5:
                if(moderador==datoCambio&&strcmp(pro[j/7].usuario,nombreel)==10){
                    fprintf(fptr2, "%s", datoNuevo);
                }else{
                    fprintf(fptr2, "%s", pro[j/7].sueldo);
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
void compraArticulo(Producto *produ,Empleado emp){

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
                printf("  ID NO REGISTRADO  ");
            }
        }
    }

    printf("Le hemos generado su recibo: \n");
    FILE *fp;
    fp = fopen ("recibo.txt", "wr" );
    if (fp==NULL) {
        system("touch recibo.txt");
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

