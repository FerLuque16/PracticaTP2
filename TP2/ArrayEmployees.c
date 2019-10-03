#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayEmployees.h"

int initEmployees(eEmployee *emp, int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        emp[i].isEmpty=1;
    }

    return 0;
}

/** \brief add in a existing list of employees the values received as parameters in the first empty position
* \param emp eEmployee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addEmployee(eEmployee *emp, int len,eSector *auxSector, int lenSector)//, int id, char name[],char lastName[],float salary,int sector)

{
    int index;
    char rta;
    int retorno=-1;

    index=findEmptyPlace(emp,len);

    if(index!=-1)
    {
        emp[index].id=getRandomNumber(1,1000,1);
        getString(emp[index].name,"\nIngrese nombre: \n","\nERROR\n",1,51);
        getString(emp[index].lastName,"\nIngrese apellido : \n","\nERROR\n",1,51);
        getFloat(&emp[index].salary,"\nIngrese salario : \n","\nERROR\n",1,100000);
        system("cls");

        printSector(auxSector,lenSector);
        getInt(&emp[index].sector,"\nIngrese id del sector: \n","\nERROR\n",1,4);

        emp[index].id=getRandomNumber(1,1000,1);

        getChar(&rta,"\nIngrese s para confirmar el alta\n","\nERROR\n",'a','z');


        if(rta == 's' || rta == 'S')
        {
            emp[index].isEmpty=0;
            retorno=0;
        }
        else
        {
            printf("\nNo se ha dado de alta el empleado\n");
            system("pause");
        }

    }
    else
    {
           printf("\nNo hay mas espacio libre\n");
    }

    return retorno;
    }

int removeEmployee(eEmployee emp[],int len ,eSector sec[], int lenSec )
{
    char rta;
    int auxId,index,retorno=-1;

    /*printf("\nIngrese ID : ");
    scanf("%d" ,&auxId);*/

    getInt(&auxId,"\nIngrese ID del empleado: \n","\nERROR\n",1,1000);

    index=findEmployeeById(emp,len,auxId);

            if(index != -1)
            {
               /*mostrar(emp,len,sec,lenSec);
               system("pause");*/
               do
               {
                   system("cls");
                   /*printf("\n¿Desea dar de baja? Ingrese s o n");
                   setbuf(stdin,NULL);
                   scanf("%c" ,&rta);*/
                   getChar(&rta,"\n¿Confirma la baja del empleado? Ingrese s o n: \n","\nERROR\n",'n','s');
                   system("pause");

               }while(rta != 's' &&  rta != 'n');

               if(rta=='s')
                {
                    emp[index].isEmpty=1;
                    retorno=0;

                    //flag=1;
                }
               else
                {
                    printf("\nNo se ha dado de baja\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nNo se ha encontrado al empleado\n");
            }

    return retorno;

}

void modificar(eEmployee emp[],int len,eSector sec [], int lenSector)
{
    char rta;
    int auxId,i,index;
    int opcMod;

    sortEmployee(emp,len,1);
    mostrarTodos(emp,len,sec,lenSector);
    getInt(&auxId,"\nIngrese ID del empleado: ","\nERROR\n",1,1000);

   /* printf("\nIngrese ID del empleado: ");
    scanf("%d" ,&auxId);*/

    index=findEmployeeById(emp,len,auxId);

    for(i=0;i<len;i++)
    {
            if(index!=-1)
            {
               //mostrar(emp[i],sec,lenSector,0);
               //system("pause");

                printf("\n¿Desea modificar? Ingrese s o n: \n");
                scanf("%c" ,&rta);


               if(rta=='s')
                {
                    do
                    {
                        system("cls");
                        //printf(" 1. Seleccionar empleado.\n 1. Modificar nombre.\n 2. Modificar apellido.\n 3. Modificar salario.\n 4. Modificar sector.\n 5. Atras.");


                        getInt(&opcMod,"1. Modificar nombre.\n2. Modificar apellido.\n3. Modificar salario.\n4. Modificar sector.\n5. Atras.","OPCION NO VALIDA",1,5);

                        switch(opcMod)
                        {
                            case 1:
                                printf("\nIngrese nombre: \n");
                                setbuf(stdin,NULL);
                                scanf("%s",emp[i].name);
                                break;

                            case 2:
                                printf("\nIngrese apellido: \n");
                                setbuf(stdin,NULL);
                                scanf("%s",emp[i].lastName);
                                break;

                            case 3:
                                printf("\nIngrese salario: \n");
                                setbuf(stdin,NULL);
                                scanf("%f" ,&emp[i].salary);
                                break;


                            case 4:
                                /*printf("Ingrese sector: \n");
                                setbuf(stdin,NULL);*/
                                getInt(&emp[i].sector,"Ingrese sector: ","\nERROR\n",1,4);
                                break;

                            case 5:
                                opcMod=5;
                            default:
                                printf("\nOpcion no valida\n");

                        }
                    }while(opcMod!=5);
                }
               else
                {
                    printf("\nNo se ha modificado al empleado\n");
                    break;
                }
            }
            else
            {
                printf("\nNo se ha encontrado al empleado\n");
                system("pause");
            }
    }
}

void printSector(eSector sec[], int len)
{
    setbuf(stdin,NULL);
    int i;

        for(i=0;i<len;i++)
            {
                    printf("%d\t%s\n" ,sec[i].id,sec[i].desc);
            }
}

int findEmployeeById(eEmployee emp[], int len, int id)
{
    int i, index = -1;

    for(i=0; i<len; i++)
    {
        if(emp[i].id == id && emp[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int findEmptyPlace (eEmployee emp[], int len)
{
    int i, index=-1;

    for(i=0; i<len; i++)
    {
        if(emp[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}



void mostrar(eEmployee emp,eSector sec[], int lenSec, int formato)
{
    int i=0;
    char auxSec[51];

    for(i=0;i<lenSec;i++)
    {
        if(emp.sector==sec[i].id)
            {
                strcpy(auxSec,sec[i].desc);
                break;
            }

    }
        if(formato==0)
        {
            printf("%10d %20s %20s %20.2f %20s\n", emp.id, emp.name, emp.lastName, emp.salary, auxSec);
            system("pause");
        }

        else
        {
        printf("\nLegajo: %d | Nombre: %s | Apellido: %s | Salario: %.2f | Sector: %s\n", emp.id, emp.name, emp.lastName, emp.salary, auxSec);
        system("pause");
        }

}

void mostrarTodos(eEmployee emp[], int len, eSector sec[], int lenSector)
{
    int i, j;
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("%10s %20s %20s %20s %20s\n", "Legajo", "Nombre", "Apellido", "Salario", "Sector");
    for(j=0; j<lenSector; j++)
    {   //Separo por sectores a mis empleados.
        printf("--------------------------------------------------------------------------------------------------\n");
        for(i=0; i<lenSector; i++)
        {
            if(emp[i].sector == sec[j].id && emp[i].isEmpty == 0)
            {
                mostrar(emp[i], sec, lenSector,0);
            }
        }
    }
    printf("--------------------------------------------------------------------------------------------------\n\n");
}




void sortEmployee(eEmployee emp[], int len, int order)
{   //Utilizo el metodo de burbujeo para ordenar alfabeticamente en orden ascendente o descendente.
    int i, j;
    eEmployee auxEmp;
    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(order == 1) //Ascendente
            {
                if(strcmp(emp[i].lastName, emp[j].lastName) > 0)
                {
                    auxEmp = emp[i];
                    emp[i] = emp[j];
                    emp[j] = auxEmp;
                }
            }
            else{ //Descendente
                if(strcmp(emp[j].lastName, emp[i].lastName) > 0)
                {
                    auxEmp = emp[j];
                    emp[j] = emp[i];
                    emp[i] = auxEmp;
                }
            }
        }
    }
}

void calculateSalaryInfo(eEmployee emp[], int len)
{
    int i, employeeCounter = 0, employeeExceedCounter = 0;
    float salaryAcumulator = 0, average;
    for(i=0; i<len; i++)
    {
        if(emp[i].isEmpty == 0)
        {
            salaryAcumulator += emp[i].salary;
            employeeCounter++;
        }
    }
    average = salaryAcumulator / employeeCounter;
    for(i=0; i<len; i++)
    {
        if(emp[i].salary > average && emp[i].isEmpty == 0)
        {
            employeeExceedCounter++;
        }
    }
    printf("Total de salarios: $%.2f | Promedio de salarios: $%.2f | Empleados que superan el promedio: %d\n\n", salaryAcumulator, average, employeeExceedCounter);
    system("pause");
}


