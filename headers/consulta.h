#include "../structs/consulta.h"

void ConsultaScreen();
void cadastrarConsulta();

int salvarConsulta(Consulta element);
ArrayDeConsultas recuperarConsultas();
int verificarHorario(int crm, Data data);
int cancelarConsulta(int id);

void initArrayConsulta(ArrayDeConsultas *a);
void insertArrayConsulta(ArrayDeConsultas *a, Consulta element);
void FreeArrayConsulta(ArrayDeConsultas *a);