#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


void cargapersona()
{
    char opcion;
    char archivitopers[] = {"datos_persona"};
    int ultiid=0;
    do
    {   system("cls");
        printf("\t\t\t<<< Menu Cliente >>>");
        printf("\nINGRESE OPCION");
        printf("\n1- Cargar cliente");
        printf("\n2- Mostrar Cliente");
        printf("\n3- Dar de Baja");
        printf("\n4- Modificar Datos");
        printf("\n\n\n ESC para volver atras.");
        opcion=getch();
        switch ( opcion )
        {
            case 49:
                    ultiid=ultimaid(archivitopers);
                    reg_usuario (archivitopers,ultiid);
                    break;
            case 50:
                    mostrar_usuario(archivitopers);
                    break;
            case 51:
                    dardebaja(archivitopers);
                    break;
            case 52:
                    modificar_datos_usuario (archivitopers);
                    break;
        } ///switch principal
    }while ( opcion != 27 );  ///FIN DEL DO-WHILE

}
int reg_usuario (char nombarchi [],int num)
{  system("cls");
   char control = 's';
   FILE* fichero ;
   persona pers;
    fichero=fopen(nombarchi,"ab");
    if(fichero==NULL)
    {
        fichero=fopen(nombarchi,"wb");
    }
    if(fichero!=NULL)
    {
         pers.id=num+1;
         printf("\n Su id es: %d",pers.id);
         printf ("\n Ingrese Apellido: ");
         fflush(stdin);
         gets (pers.apellido);
         printf ("\n Ingrese Tipo de cliente (1 Embarazada) (2 Jubilado) (3 Normal): ");
         fflush(stdin);
         scanf("%i",&pers.tipoCliente);
         while (pers.tipoCliente < 1 || pers.tipoCliente > 3)
         {
            printf ("Ingrese un tipo valido: ");
            fflush(stdin);
            scanf("%i",&pers.tipoCliente);
         }
         printf ("\n Medio de pago (1 Efectivo) (2 Tarjeta) (3 Todos): ");
         fflush(stdin);
         scanf("%i",&pers.medioPago);
         while (pers.medioPago < 1 || pers.medioPago > 3)
         {
            printf ("Ingrese un medio de pago valido: ");
            fflush(stdin);
            scanf("%i",&pers.medioPago);
         }
         printf("\n Ingrese cantida de articulos: ");
         scanf("%i",&pers.cantArticulos);
         pers.tiempoEspera=0;
         pers.tiempoProcesado=0;
         pers.eliminado=0;
         fwrite (&pers, sizeof (persona), 1, fichero);
    }
         fclose(fichero);
}
int ultimaid(char nombarchi[])
{
    int elementos=0;
    FILE *archi;
    archi=fopen(nombarchi,"rb");
    if(archi!=NULL)
    {
        fseek(archi,0,2);
        elementos=ftell(archi)/sizeof (persona);
    }
    fclose(archi);
    return elementos;
}
void mostrar_usuario (char nombarchi [])
{  system("cls");
   FILE* puntero_atxt;
   persona pers;
   puntero_atxt = fopen(nombarchi,"r+b");
   if (puntero_atxt == NULL)
   {
      printf ("\n ERROR AL LEER EL FICHERO");
      printf ("\n EL MISMO NO EXISTE");
   }
   else
   {

      while(fread(&pers, sizeof(persona), 1, puntero_atxt)>0) //recorro el fichero hasta que llege al final de las estructuras
      {
            if(pers.eliminado==0)
            {
                mostrar(pers);
            }
      }
      fclose(puntero_atxt);
      getch();
   }
}
void mostrar(persona pers)
{
         printf ("\n\n");
         printf ("\n ID DE USUARIO :  %i", pers.id);
         printf ("\n Apellido: %s",pers.apellido);
         vercliente(pers);
         verpago(pers);
         printf ("\n CANTIDAD DE ARTICULOS :  %d", pers.cantArticulos);
         printf ("\n TIEMPO DE ESPERA :  %d", pers.tiempoEspera);
         printf ("\n TIEMPO DE PROCESADO :  %d", pers.tiempoProcesado);
         verestado(pers);
         printf("\n\n\n Esc para volver atras.");
}
void vercliente(persona pers)
{
    if(pers.tipoCliente==1)
    {
        printf("\n TIPO CLIENTE: EMBARAZADA.");
    }
    if(pers.tipoCliente==2)
    {
        printf("\n TIPO CLIENTE: JUBILADO.");
    }
    if(pers.tipoCliente==3)
    {
        printf("\n TIPO CLIENTE: COMUN.");
    }
}
void verpago(persona pers)
{
    if(pers.medioPago==1)
    {
        printf("\n MEDIO DE PAGO: EFECTIVO.");
    }
    if(pers.medioPago==2)
    {
        printf("\n MEDIO DE PAGO: CREDITO.");
    }
    if(pers.medioPago==3)
    {
        printf("\n MEDIO DE PAGO: TODOS.");
    }
}
void verestado(persona pers)
{
    if(pers.eliminado==0)
    {
        printf("\n LA PERSONA ESTA ACTIVA.");
    }
    if(pers.eliminado==1)
    {
        printf("\n LA PERSONA ESTA INACTIVA.");
    }
}
void dardebaja(char nombarchi [])
{   system("cls");
    int idaux=0;
    int selec;
    char resultadopers;
    FILE* fichero ;
    fichero=fopen(nombarchi,"r+b");
    persona pers ; /// creo un nuevo persiente de la estructura persiente
    printf( "\n ¿Que id queres Modificar?: " );
    scanf( "%i", &idaux);
    selec=idaux;
    ///Cambia valor de eliminado en el archivo persientes
    resultadopers = fseek(fichero,sizeof(persona)*(idaux-1),0);
    fread(&pers, sizeof (persona), 1, fichero);
    if (!resultadopers)
    {
        fseek(fichero,sizeof(persona)*(idaux-1),0);
        pers.eliminado=1;
        fwrite (&pers, sizeof (persona), 1, fichero);
    }
    fclose (fichero);
}
void modificar_datos_usuario (char nombarchi [])
{   system("cls");
    int idaux=0,datonuevoint;
    char datonuevo [30],resultado,opcion;
    FILE* puntero_afile;
    persona pers;
    puntero_afile = fopen(nombarchi, "r+b");
    printf( "\n ¿Que id estas buscando?: " );
	scanf( "%i", &idaux);
	resultado = fseek(puntero_afile,sizeof(persona)*(idaux-1),0);
	fread(&pers, sizeof (persona), 1, puntero_afile);
    if (!resultado)
    {
        system("CLS");
        printf ("Estos son tus datos: \n");
        mostrar(pers);
        do
        {
            printf("\n\n");
            printf ("\n (1)APELLIDO");
            printf ("\n (2)TIPO DE CLIENTE");
            printf ("\n (3)MEDIO DE PAGO");
            printf ("\n (4)CANTIDAD DE ARTICULOS");
            printf ("\n (0)SALIR");
            printf( "\n\Introduzca opci%cn : ", 162);
            fflush(stdin);
            opcion=getch();
            switch ( opcion )
            {
                case 49:
                    fseek(puntero_afile,sizeof(persona)*(idaux-1),0);
                    printf("\n Ingrese su nuevo apellido: ");
                    fflush(stdin);
                    gets (datonuevo);
                    strcpy (pers.apellido, datonuevo);
                    fwrite (&pers, sizeof (persona), 1, puntero_afile);
                break;
                case 50:
                    fseek(puntero_afile,sizeof(persona)*(idaux-1),0);
                    printf("\n Ingrese su nuevo tipo de cliente: ");
                    fflush(stdin);
                    scanf("%i",&datonuevoint);
                    while (datonuevoint < 1 || datonuevoint > 3)
                    {
                        printf ("Ingrese un tipo valido: ");
                        fflush(stdin);
                        scanf("%i",&datonuevoint);
                    }
                    pers.tipoCliente=datonuevoint;
                    fwrite (&pers, sizeof (persona), 1, puntero_afile);
                break;
                case 51:
                    fseek(puntero_afile,sizeof(persona)*(idaux-1),0);
                    printf("\n Ingrese su nuevo medio de pago: ");
                    fflush(stdin);
                    scanf("%i",&datonuevo);
                    while (datonuevoint < 1 || datonuevoint > 3)
                    {
                        printf ("Ingrese un medio de pago valido: ");
                        fflush(stdin);
                        scanf("%i",&datonuevoint);
                    }
                    pers.medioPago=datonuevoint;
                    fwrite (&pers, sizeof (persona), 1, puntero_afile);
                break;
                case 52:
                    fseek(puntero_afile,sizeof(persona)*(idaux-1),0);
                    printf("\n Ingrese su nueva cantidad de articulos: ");
                    fflush(stdin);
                    scanf("%i",&datonuevoint);
                    pers.cantArticulos=datonuevoint;
                    fwrite (&pers, sizeof (persona), 1, puntero_afile);
                break;
            }
        }while (opcion !=48);
    }
    fclose (puntero_afile);
}
