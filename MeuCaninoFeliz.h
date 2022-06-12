#include <iostream>

using namespace std;

class MeuCaninoFeliz{
	
	private:
    string nome = "Meu Canino Feliz";
		float distancia = 2; 
		int caesPequenosSemana = 20, caesGrandesSemana = 40;
		int caesPequenosFDS = 24, caesGrandesFDS = 48;

  public:
    int valorTotal(string diaDaSemana, int caesPequenos, int caesGrandes){
      int valorTotalMCF;
      
      if(diaDaSemana == "Sábado" || diaDaSemana == "Domingo"){
        valorTotalMCF = (caesPequenos*this->caesPequenosFDS) + (caesGrandes*this->caesGrandesFDS);
      }else{
        valorTotalMCF = (caesPequenos*this->caesPequenosSemana) + (caesGrandes*this->caesGrandesSemana);
      }
      
      return valorTotalMCF;
    }

    float getDistancia(){
      return this->distancia;
    }
    string getNome(){
      return this->nome;
    }
};
