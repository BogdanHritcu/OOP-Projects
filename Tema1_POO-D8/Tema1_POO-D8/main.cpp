#include "Stiva/Stiva.h"
#include "Utilitare/Utilitare.h"

int main()
{
	poo::Stiva stiva1, stiva2;

	//citire
	std::cout << "Se citeste Stiva1:" << std::endl;
	std::cin >> stiva1;
	std::cout << "Stiva1:" << std::endl;
	std::cout << stiva1;

	//inversare
	poo::invert_stack(stiva1);
	std::cout << "Stiva1 inversata o data:" << std::endl;
	std::cout << stiva1;

	//inversare
	poo::invert_stack(stiva1);
	std::cout << "Stiva1 inversata inca o data:" << std::endl;
	std::cout << stiva1;

	//copiere
	poo::copy_stack(stiva2, stiva1);
	std::cout << "Stiva2 dupa copiere:" << std::endl;
	std::cout << stiva2;

	//golire
	poo::empty_stack(stiva1);
	std::cout << "Stiva1 dupa golire:" << std::endl;
	std::cout << stiva1;

	system("pause");
	
	return 0;
}