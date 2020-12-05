#include "../structs/medico.h"

void MedicoScreen();

int salvarMedico(Medico element);
ArrayDeMedicos recuperarMedicos();
void listarMedicos(ArrayDeMedicos a);
int verificarCRM(int crm);

void initArrayMedico(ArrayDeMedicos *a);
void insertArrayMedico(ArrayDeMedicos *a, Medico element);
void FreeArrayMedico(ArrayDeMedicos *a);