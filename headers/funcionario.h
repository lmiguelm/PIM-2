#include "../structs/funcionario.h"

void FuncionarioScreen();

int salvarFuncionario(Funcionario element);
ArrayDeFuncionarios recuperarFuncionarios();
void listarFuncionarios(ArrayDeFuncionarios a);

void initArrayFuncionario(ArrayDeFuncionarios *a);
void insertArrayFuncionario(ArrayDeFuncionarios *a, Funcionario element);
void FreeArrayFuncionario(ArrayDeFuncionarios *a);