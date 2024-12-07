#include <stdio.h>
#include <string.h>

//3.se definen los limites para las variables que se crearan a lo largo del codigo, estas facilitan el manejo al momento de escribir el programa.
#define MAX_PRODUCTOS 50
#define MAX_TICKETS 100
#define MAX_LINEAS_TICKET 10

/*registros con los datos que se usaran dentro del programa.*/

//registro para representar el prodcuto.
typedef struct{
    char codigo[5]; //codigo del producto (3 letras y 1 numero), teniendo en cuenta "/0".
    char descripcion[31]; //caracteres maximos para la descripcion del producto (30).
    int stock;
    int stock_minimo;
    float precio_unidad;
    float descuento;
}Producto;

//registro para representar la linea del ticket.
typedef struct{
    char codigo_producto[5];
    char descripcion[31];
    int unidades_vendidas;
    float precio_unitario;
    float descuento_aplicado;
}LineaTicket;

//registro para representar el ticket de venta.
typedef struct{
    char codigo_ticket[];
    char fecha_hora[]; 
    LineaTicket lineas[MAX_LINEAS_TICKET] //2.es una estructura la cual es llamada dentro de otra estructura(registro), en donde se especifica con un arreglo para poder usarse en varios producto, sin esto no pudiera hacerse.
    float importeTotal;
    int num_lineas;
}Ticket;

//cada producto se le debe definir el limite, al igual que a los tickets.
Producto productos[MAX_PRODUCTOS]; //productos es un array perterneciente al registro "Productos", anteriormente definido. Tiene un limite para crear de 50.
Ticket tickets[MAX_TICKETS]; //tickets es un array perteneciente al registro "Ticket", anteriormente definido. Tiene un limite para crear de 100.
int num_productos = 0; //contador el cual maneja el numero de productos que ha creado el usuario.
int num_tickets = 0; //contador el cual maneja el numero de tickets que ha creado el usuario.

//definimos los modulos para la parte de productos.
void altaProducto();
void bajaProducto();
void modificarProducto();
void buscarProducto();

//definimos los modulos para la parte de los tickets.
void nuevoTicket();
void eliminarTicket();
void buscarTicket();
void comprobarTicket();

//se mostrara las opciones del menu y a su vez se llamaran a los modulos correspondientes.
int main(){

    int opcion;
    do{
    printf("               ╓═════════════════════════╖\n");
    printf("               ║       Comercio de       ║\n");
    printf("               ║        Dana  Meza       ║\n");
    printf("               ║            ,            ║\n");
    printf("               ║         Eva Ruiz        ║\n");
    printf("               ║            y            ║\n");
    printf("               ║       Keilyn Conde      ║\n");
    printf("               ╙═════════════════════════╜\n");
    printf("               ◌◌◌◌◌◌◌◌◌◌Opciones◌◌◌◌◌◌◌◌\n");
    printf("Introduzca el número 0 si desea salir.\n");
    printf("Introduzca el número 1 si desea realizar el alta de un producto.\n");
    printf("Introduzca el número 2 si desea dar de baja un producto: \n");
    printf("Introduzca el número 3 si desea realizar una modificación a un producto.\n");
    printf("Introduzca el número 4 si desea realizar la búsqueda de un producto.\n");
    printf("Introduzca el número 5 si desea crear un ticket nuevo. \n");
    printf("Introduzca el número 6 si desea eliminar un ticket. \n");
    printf("Introduzca el número 7 si desea buscar un ticket. \n");
    printf("Introduzca el número 8 si desea comprobar el stock. \n");
    printf("               ◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌◌\n");

    printf("¿Que desea hacer?: ");
    scanf(" %d", &opcion);

    //imprime el mensaje para el usuario y realiza el modulo correspondiente, dependiendo a la respuesta dada.
    switch (opcion) {
        case 0:
            printf("Saliendo del programa...\n");
            break;
        case 1:
            printf("Ha seleccionado dar de alta un producto.\n");
            altaProducto();
            break;
        case 2:
            printf("Ha seleccionado dar de baja un producto.\n");
            bajaProducto();
            break;
        case 3:
            printf("Ha seleccionado modificar un producto.\n");
            modificarProducto();
            break;
        case 4:
            printf("Ha seleccionado buscar un producto.\n");
            buscarProducto();
            break;
        case 5:
            printf("Ha seleccionado crear un ticket nuevo.\n");
            crearTicket();
            break;
        case 6:
            printf("Ha seleccionado eliminar un ticket.\n");
            eliminarTicket();
            break;
        case 7:
            printf("Ha seleccionado buscar un ticket.\n");
            buscarTicket();
            break;
        case 8:
            printf("Ha seleccionado comprobar el stock.\n");
            comprobarStock();
            break;
        default:
        printf("Opción inválida. Por favor, ingrese un número entre 0 y 8: ");
        while (getchar() != '\n'); //se encargda de limpiar el buffer manualmente(es una de las formas de limpiarlo), para que asi el scanf no tome al \n" como una varibale.
        break;

    }

    }while(opcion!=0);

    return 0;
}

void alta_producto(){
    if(num_productos>=MAX_PRODUCTOS){ //si se crearon el limite maximo de productos se sale del modulo y no realiza ninguna otra accion que haya dentro de este.
        printf("Haz superado el limite de productos.\n");
        return;
    }
    Producto nuevo_producto; //4.variable tipo estructura, ya que es parte de un registro.
    printf("Ingrese el codigo del producto (3 letras + 1 numero): ");
    scanf(" %s", nuevo_producto.codigo); 

    //se necesita un ciclo for para comprobar si el producto ya existe.
}

/*perdon por tantas notas, es q m da cosita q no se entienda esta shit o se me olvide algo uwu*/
