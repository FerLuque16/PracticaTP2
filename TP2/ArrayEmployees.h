typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;

typedef struct
{
    int id;
    char desc[51];
}eSector;

int initEmployees(eEmployee *emp, int len);

void addEmployee(eEmployee *emp, int len, eSector *auxSector, int lenSector);
void removeEmployee(eEmployee emp[],int len ,eSector sec[], int lenSec );












void showSector(eSector sec[], int len);
void mostrar(eEmployee emp[],int len,eSector sec[], int lenSec);
