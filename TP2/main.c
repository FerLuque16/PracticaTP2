#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "ArrayEmployees.h"

#define CANT_EMPLOYEES 1000
#define CANT_SECTOR 4


int main()
{
    eEmployee emp[CANT_EMPLOYEES];
    int opc;
    int seguir=0;
    float salary;
    char letra;


    initEmployees(emp,CANT_EMPLOYEES);
    eSector sector [CANT_SECTOR] = {{1,"Contabilidad"},{2,"Sistemas"},{3, "RRHH"},{4, "Mantenimiento"}};
    do
    {
        system("cls");

        getInt(&opc,"1. Altas\n2. Modificar\n3. Baja\n4. Informar\n5. Salir\n","Opcion no valida",1,5);
        /*printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificar\n");
        printf("4. String\n");
        printf("5. Salir\n");*/


        //scanf("%d" ,&opc);

        switch(opc)
        {
            case 1:
                addEmployee(emp,CANT_EMPLOYEES,sector,CANT_SECTOR);

                    mostrar(emp,CANT_EMPLOYEES,sector,CANT_SECTOR);
                    system("pause");




                break;

            case 2:

                if(getFloat(&salary,"Ingrese salario\n","ERROR\n",1,100000)==0)
                {
                    printf("%.2f" ,salary);
                    system("pause");
                }


                break;

            case 3:
                if(getChar(&letra,"Ingrese una letra\n","ERROR\n",'a','e')==0)
                {
                    printf("%c\n" ,letra);
                    system("pause");
                }
                break;

            case 4:
                removeEmployee(emp,CANT_EMPLOYEES,sector,CANT_SECTOR);
                break;

            case 5:
                seguir=1;
                break;

            default:
                break;

        }

    }while(seguir!=1);
    return 0;
}

