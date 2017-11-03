#ifndef CLIENTE_H_INCLUDE
#define CLIENTE_H_INCLUDE

typedef struct {
        int id;
        char nombre[30];
        char apellido[30];
        char usuario[20];
        int pass[2][5];
        int eliminado;
} Usuario;

//Estructura de Persona (persiente)

typedef struct {
        int id;
        char apellido[30];
        int tipoCliente; 		/// Prioridad 1:embarazada, 2:jubilado y 3:persiente común
        int medioPago;		    /// 1:efectivo, 2:crédito y 3:todos
        int cantArticulos;		/// es el tiempo de ejecución
        int tiempoEspera;		/// es el tiempo de respuesta
        int tiempoProcesado;	/// es el tiempo que ya fue procesado en la línea de caja
        int eliminado;
} persona;

int reg_usuario (char nombarchi [], int num);
void mostrar(persona a);
int ultimaid(char nombarchi[]);
void mostrar_usuario (char nombarchi []);
void verpago(persona pers);
void dardebaja(char nombarchi []);
void verestado(persona pers);
void vercliente(persona pers);
void modificar_datos_usuario (char nombarchi []);
void cargapersona(char archivitopers[]);

#endif
