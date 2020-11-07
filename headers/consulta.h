#include "../structs/consulta.h"

void ConsultaScreen();
void cadastrarConsulta();

int salvarConsulta(Consulta element);
ArrayDeConsultas recuperarConsultas();
int verificarHorario(int crm, Data data);

void initArrayConsulta(ArrayDeConsultas *a);
void inserArrayConsulta(ArrayDeConsultas *a, Consulta element);
void FreeArrayConsulta(ArrayDeConsultas *a);