#include <iostream>

using namespace std;

class ChowChawgas{
	
	private:
    string nome = "ChowChawgas";
		float distancia = 0.8; 
		int caesPequenosSemana = 30, caesGrandesSemana = 45;
		int caesPequenosFDS = 30, caesGrandesFDS = 45;

  public:
    int valorTotal(string diaDaSemana, int caesPequenos, int caesGrandes){
      int valorTotalCC;
      
      if(diaDaSemana == "Sábado" || diaDaSemana == "Domingo"){
        valorTotalCC = (caesPequenos*this->caesPequenosFDS) + (caesGrandes*this->caesGrandesFDS);
      }else{
        valorTotalCC = (caesPequenos*this->caesPequenosSemana) + (caesGrandes*this->caesGrandesSemana);
      }
      
      return valorTotalCC;
    }
  
    float getDistancia(){
      return this->distancia;
    }
    string getNome(){
      return this->nome;
    }
};
