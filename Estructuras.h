#ifndef Estructuras_h
#define Estructuras_h
typedef struct {
    char nombre[20];
    char apellido[20];
    char usuario[20];
    char pass[20];
    char area[20];
    char sueldo[20];
}Empleado;

//Venta de empleado

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
#endif /* Header_h */