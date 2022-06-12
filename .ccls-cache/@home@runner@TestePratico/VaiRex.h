#include <iostream>

using namespace std;

class VaiRex{
	
	private:
    string nome = "Vai Rex";
		float distancia = 1.7; 
		int caesPequenosSemana = 15, caesGrandesSemana = 50;
		int caesPequenosFDS = 20, caesGrandesFDS = 55;

  public:
    int valorTotal(string diaDaSemana, int caesPequenos, int caesGrandes){
      int valorTotalVR;
      
      if(diaDaSemana == "Sábado" || diaDaSemana == "Domingo"){
        valorTotalVR = (caesPequenos*this->caesPequenosFDS) + (caesGrandes*this->caesGrandesFDS);
      }else{
        valorTotalVR = (caesPequenos*this->caesPequenosSemana) + (caesGrandes*this->caesGrandesSemana);
      }
      
      return valorTotalVR;
    }
  
      float getDistancia(){
        return this->distancia;
      }
      string getNome(){
        return this->nome;
      }
	
};
