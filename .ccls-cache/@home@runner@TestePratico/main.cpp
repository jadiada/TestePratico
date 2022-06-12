#include <iostream>
#include "MeuCaninoFeliz.h"
#include "VaiRex.h"
#include "ChowChawgas.h"

using namespace std;

bool verificarFDS(bool fds, string diaDaSemana){
  if(diaDaSemana == "Sábado" || diaDaSemana == "Domingo"){
    fds = true;
  }else{
    fds = false;
  }
  return fds;
}

int main() {
  
  //Variáveis
  char separador;
  int dia, mes, ano;
  int digitoAno, valorSeculo, caesPequenos, caesGrandes, melhorValor;
  int valorTotalCC, valorTotalMCF, valorTotalVR;
  string melhorCanil;
  bool fds;

  //Entradas
  cout << "Insira a data dos banhos:" << endl;
  cin >> dia >> separador >> mes >> separador >> ano;
  cout << "Insira a quantidade de cães pequenos:" << endl;
  cin >> caesPequenos;
  cout << "Insira a quantidade de cães grandes:" << endl;
  cin >> caesGrandes;

  //Operações para determinar dia da semana-------------------------------------------------//
    //Separação dos dois últimos dígitos do ano
  if(to_string(ano).length() == 4){
    digitoAno = ano%100;
  }else if(to_string(ano).length() == 2){
    digitoAno = ano;
  }
    //Valores fixos necessários à fórmula de determinação do dia da semana
  int meses[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
  string dias[] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
  if(1900 <= ano && ano <= 1999){
    valorSeculo = 0;
  }else if(2000 <= ano && ano <= 2099){
    valorSeculo = 6;
  }
    //Cálculo com os valores anteriores + valores fixos
  int soma = digitoAno + (digitoAno/4) + dia + meses[mes - 1] + valorSeculo;
  int diaNaString = soma%7;
  string diaDaSemana = dias[diaNaString];
  //-----------------------------------------------------------------------------------------//

  //Instanciando objetos das classes dos canis----------------------------------------------//
  ChowChawgas* chow = new ChowChawgas();
  MeuCaninoFeliz* canino = new MeuCaninoFeliz();
  VaiRex* rex = new VaiRex();

  valorTotalCC = chow->valorTotal(diaDaSemana, caesPequenos, caesGrandes);
  valorTotalMCF = canino->valorTotal(diaDaSemana, caesPequenos, caesGrandes);
  valorTotalVR = rex->valorTotal(diaDaSemana, caesPequenos, caesGrandes);
  //-----------------------------------------------------------------------------------------//

  //Comparando valores e resolvendo empates com comparação das distâncias-------------------//
  melhorValor = min(valorTotalCC, min(valorTotalMCF, valorTotalVR));
    //Em caso de empate:
  if(valorTotalCC == valorTotalMCF && valorTotalCC == melhorValor){
    melhorCanil = (chow->getDistancia() < canino->getDistancia()) ? chow->getNome() : canino->getNome();
  }else if(valorTotalMCF == valorTotalVR && valorTotalMCF == melhorValor){
    melhorCanil = (canino->getDistancia() < rex->getDistancia()) ? canino->getNome() : rex->getNome();
  }else if(valorTotalVR == valorTotalCC && valorTotalVR == melhorValor){
    melhorCanil = (rex->getDistancia() < chow->getDistancia()) ? rex->getNome() : chow->getNome();
  }else{//Caso não haja empate
    melhorCanil = (valorTotalCC == melhorValor) ? chow->getNome() : ((valorTotalMCF == melhorValor) ? canino->getNome() : rex->getNome());
  }
  //-----------------------------------------------------------------------------------------//

  //Saída
  cout << "O melhor canil na data fornecida é o " << melhorCanil << ". Valor total dos banhos: R$" << melhorValor << ",00." << endl;
  
}
