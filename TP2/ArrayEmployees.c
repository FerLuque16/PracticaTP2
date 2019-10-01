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

void addEmployee(eEmployee *emp, int len,eSector *auxSector, int lenSector)//, int id, char name[],char lastName[],float salary,int sector)

{
    int i;

    for(i=0;i<len;i++)
    {


    if(emp[i].isEmpty==1)
        {
            getString(emp[i].name,"Ingrese nombre : ","ERROR",1,51);
            getString(emp[i].lastName,"Ingrese apellido : ","ERROR",1,51);
            getFloat(&emp[i].salary,"Ingrese salario : ","ERROR",1,100000);
            system("cls");

            showSector(auxSector,lenSector);
            getInt(&emp[i].sector,"Ingrese id del sector : ","ERROR",1,4);

            emp[i].isEmpty=0;
            emp[i].id=getRandomNumber(1,1000,1);

            break;
        }

    }









    }





    void showSector(eSector sec[], int len)
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

void removeEmployee(eEmployee emp[],int len ,eSector sec[], int lenSec )
{
    char rta;
    int auxId,index;

    /*printf("\nIngrese ID : ");
    scanf("%d" ,&auxId);*/
    mostrar(emp,len,sec,lenSec);
    getInt(&auxId,"Ingrese ID del empleado","ERROR",1,1000);

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
                   getChar(&rta,"¿Confirma la baja del empleado? Ingrese s o n","ERROR",'n','s');
                   system("pause");

               }while(rta != 's' &&  rta != 'n');

               if(rta=='s')
                {
                    emp[index].isEmpty=1;
                    //flag=1;
                }
               else
                {
                    printf("No se ha dado de baja");
                    system("pause");
                }
            }

}

void mostrar(eEmployee emp[],int len,eSector sec[], int lenSec)
{
    int i;
    char auxSec[51];

    while(i<lenSec)
    {
        if(emp[i].sector==sec[i].id)
            {
                strcpy(auxSec,sec[i].desc);
                break;
            }
        i++;
    }


        if(emp.isEmpty==0)
        {
        printf("\nLegajo: %d | Nombre: %s | Apellido: %s | Salario: %.2f | Sector: %s\n", emp.id, emp.name, emp.lastName, emp.salary, auxSec);
        }

}

