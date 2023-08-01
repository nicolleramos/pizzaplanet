#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

int main() {
	
	const std::string corAmarela = "\x1b[33m";
	const std::string corPadrao = "\x1b[0m";
	
	const int numeroDeSabores{5};
	const std::string saborPadrao = "Calabresa";
	
	std::string pedidos[numeroDeSabores] = {"Margherita", "Quatro Queijos", "Portuguesa", "Pepperoni", "Frango com Catupiry"};
	
	std::ifstream arquivo("logoPizza.txt");

    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::cout << linha << '\n';
        }
        arquivo.close();
        
        std::cout << '\n';
    }
    
    std::cout << "|*| Temos " << numeroDeSabores << " sabores disponiveis:" << '\n';
	for (int i=0; i < numeroDeSabores; i++) {
		std::cout << i+1 << ". " << corAmarela << pedidos[i] << corPadrao << '\n';
	}
	
	int escolha;
	std::cout << "Sua escolha aqui (1 a " << numeroDeSabores << "):-------> ";
	std::cin >> escolha;
	
	if(escolha >= 1 && escolha <= numeroDeSabores) {
		std::string saborEscolhido = pedidos[escolha-1];
		
		std::cout << "Voce escolheu a pizza de " << corAmarela << saborEscolhido << corPadrao << "! " << '\n';
	} else {
		std::cout << "Por favor, escolha uma opcao valida." << '\n';
	}
		
	return 0;
}
