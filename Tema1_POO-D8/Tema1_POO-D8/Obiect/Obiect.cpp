#include "Obiect.h"

namespace poo
{
	Obiect::Obiect()
	{
		//obiect gol
		m_Size = 0;
		m_StartPtr = NULL;
	}

	Obiect::Obiect(int size)
	{
		if (size > 0) //aloca memorie doar pentru size > 0
		{
			m_Size = size;
			m_StartPtr = new char[m_Size](); //aloca memorie initializata cu 0
		}
		else //un obiect gol
		{
			m_Size = 0;
			m_StartPtr = NULL;
		}
	}

	Obiect::Obiect(const Obiect& obiect)
	{
		//delete[] m_StartPtr; //sterge informatia curenta
		m_Size = obiect.m_Size; //modifica dimenisiunea obiectului in care se copiaza

		if (m_Size > 0) //aloca memorie doar pentru size > 0
		{
			m_StartPtr = new char[m_Size]; //aloca memorie noua
			std::memcpy(m_StartPtr, obiect.m_StartPtr, obiect.m_Size); //copiaza informatia
		}
		else //obiectul copiat este gol si informatia curenta este pierduta
		{
			m_StartPtr = NULL;
			m_Size = 0;
		}

	}

	Obiect::~Obiect()
	{
		if (m_StartPtr) //daca adresa de inceput nu este NULL
		{
			delete[] m_StartPtr; //sterge memoria alocata obiectului
		}
	}

	void Obiect::read()
	{
		bool reading = true;
		bool command_processed = false;
		int end_byte = 1;
		
		std::string command = " ";

		int offset = 0;

		std::cout << "help - lista comenzilor" << std::endl;
		
		std::cin.ignore(1, '\n'); //ignora un return
		while (reading)
		{
			std::cout << "command:";
			std::getline(std::cin, command); //asteapta comanda

			if (!command_processed && command == "help")
			{
				std::cout << "help   - lista comenzilor" << std::endl;
				std::cout << "types  - lista tipurilor disponibile" << std::endl;
				std::cout << "<type> - tipul de date al elementului" << std::endl;
				std::cout << "*Exemplu: float*" << std::endl;
				std::cout << "stop	 - oprirea citirii" << std::endl;
				command_processed = true;
			}

			if (!command_processed && command == "types")
			{
				std::cout << "bool, char, int, float, double" << std::endl;
				command_processed = true;
			}

			if (!command_processed && command == "stop")
			{
				break; //opreste citirea
			}

			if (!command_processed && command == "bool")
			{
				int size = offset + sizeof(bool) + 1 + end_byte; //calculeaza dimensiunea necesara pentru adaugarea acestui element
				std::cout << "value:";
				if (size > m_Size)
				{
					void* temp = new char[size]; //aloca memorie suficienta
					memcpy(temp, m_StartPtr, m_Size); //copiaza informatiile in noul bloc de memorie
					delete m_StartPtr; //elibereaza vechiul bloc de memorie
					m_StartPtr = temp; //seteaza noua adresa de inceput
					m_Size = size; //seteaza noua dimensiune a obiectului
				}

				bool temp; //o variabila folosita pentru citirea valorii
				std::cin >> temp; //citeste valoarea
				*((char*)m_StartPtr + offset) = 'b'; //adauga un byte care specifica tipul de date care urmeaza
				offset += 1; //treci peste byte-ul care specifica tipul de date
				*(bool*)((char*)m_StartPtr + offset) = temp; //adauga noua valoare

				offset += sizeof(bool); //treci peste noua valoare
								
				command_processed = true; //considera comanda procesata
				std::cin.ignore(1, '\n'); //ignora un return
			}

			if (!command_processed && command == "char")
			{
				int size = offset + sizeof(char) + 1 + end_byte;
				std::cout << "value:";
				if (size > m_Size)
				{
					void* temp = new char[size]; //aloca memorie suficienta
					memcpy(temp, m_StartPtr, m_Size); //copiaza informatiile in noul bloc de memorie
					delete m_StartPtr; //elibereaza vechiul bloc de memorie
					m_StartPtr = temp; //seteaza noua adresa de inceput
					m_Size = size; //seteaza noua dimensiune a obiectului
				}
				char temp;
				std::cin >> temp;
				*((char*)m_StartPtr + offset) = 'c';
				offset += 1;
				*((char*)m_StartPtr + offset) = temp;

				offset += sizeof(char);
				
				command_processed = true;
				std::cin.ignore(1, '\n'); //ignora un return
			}

			if (!command_processed && command == "int")
			{
				int size = offset + sizeof(int) + 1 + end_byte;
				std::cout << "value:";
				if (size > m_Size)
				{
					void* temp = new char[size]; //aloca memorie suficienta
					memcpy(temp, m_StartPtr, m_Size); //copiaza informatiile in noul bloc de memorie
					delete m_StartPtr; //elibereaza vechiul bloc de memorie
					m_StartPtr = temp; //seteaza noua adresa de inceput
					m_Size = size; //seteaza noua dimensiune a obiectului
				}

				int temp;
				std::cin >> temp;
				*((char*)m_StartPtr + offset) = 'i';
				offset += 1;
				*(int*)((char*)m_StartPtr + offset) = temp;

				offset += sizeof(int);
				
				command_processed = true;
				std::cin.ignore(1, '\n'); //ignora un return
			}

			if (!command_processed && command == "float")
			{
				int size = offset + sizeof(float) + 1 + end_byte;
				std::cout << "value:";
				if (size > m_Size)
				{
					void* temp = new char[size]; //aloca memorie suficienta
					memcpy(temp, m_StartPtr, m_Size); //copiaza informatiile in noul bloc de memorie
					delete m_StartPtr; //elibereaza vechiul bloc de memorie
					m_StartPtr = temp; //seteaza noua adresa de inceput
					m_Size = size; //seteaza noua dimensiune a obiectului
				}

				float temp;
				std::cin >> temp;
				*((char*)m_StartPtr + offset) = 'f';
				offset += 1;
				*(float*)((char*)m_StartPtr + offset) = temp;

				offset += sizeof(float);
				
				command_processed = true;
				std::cin.ignore(1, '\n'); //ignora un return
			}

			if (!command_processed && command == "double")
			{
				int size = offset + sizeof(double) + 1 + end_byte;
				std::cout << "value:";
				if (size > m_Size)
				{
					void* temp = new char[size]; //aloca memorie suficienta
					memcpy(temp, m_StartPtr, m_Size); //copiaza informatiile in noul bloc de memorie
					delete m_StartPtr; //elibereaza vechiul bloc de memorie
					m_StartPtr = temp; //seteaza noua adresa de inceput
					m_Size = size; //seteaza noua dimensiune a obiectului
				}

				double temp;
				std::cin >> temp;
				*((char*)m_StartPtr + offset) = 'd';
				offset += 1;
				*(double*)((char*)m_StartPtr + offset) = temp;

				offset += sizeof(double);
				
				command_processed = true;
				std::cin.ignore(1, '\n'); //ignora un return
			}

			if (command_processed == false)
			{
				std::cout << "Invalid command!" << std::endl;
			}

			command_processed = false; //reseteaza comanda
		}

		if (m_Size > 0)
		{
			*((char*)m_StartPtr + offset) = NULL;
		}
	}

	void Obiect::show()
	{
		int offset = 0;
		char type = 1;

		if (m_StartPtr == NULL)
		{
			type = NULL;
		}

		while (type != NULL)
		{
			type = *((char*)m_StartPtr + offset);
			offset += 1;

			switch (type)
			{
			case 'b':
				std::cout << "bool:" << *(bool*)((char*)m_StartPtr + offset) << std::endl;
				offset += sizeof(bool);
				break;
				
			case 'c':
				std::cout << "char:" << *(char*)((char*)m_StartPtr + offset) << std::endl;
				offset += sizeof(char);
				break;
				
			case 'i':
				std::cout << "int:" << *(int*)((char*)m_StartPtr + offset) << std::endl;
				offset += sizeof(int);
				break;

			case 'f':
				std::cout << "float:" << *(float*)((char*)m_StartPtr + offset) << std::endl;
				offset += sizeof(float);
				break;

			case 'd':
				std::cout << "double:" << *(double*)((char*)m_StartPtr + offset) << std::endl;
				offset += sizeof(double);
				break;

			default:
				break;
			}
		}
	}
	
	int Obiect::getSize()
	{
		return m_Size;
	}

	void Obiect::shrink()
	{
		int offset = 0;
		char type = 1;

		if (m_StartPtr == NULL)
		{
			type = NULL;
		}

		while (type != NULL)
		{
			type = *((char*)m_StartPtr + offset);
			offset += 1;

			switch (type)
			{
			case 'b':
				offset += sizeof(bool);
				break;

			case 'c':
				offset += sizeof(char);
				break;

			case 'i':
				offset += sizeof(int);
				break;

			case 'f':
				offset += sizeof(float);
				break;

			case 'd':
				offset += sizeof(double);
				break;

			default:
				break;
			}
		}

		if(offset > 0 )
		{
			void* temp = new char[offset]; //aloca memorie suficienta
			memcpy(temp, m_StartPtr, offset); //copiaza informatiile in noul bloc de memorie
			delete m_StartPtr; //elibereaza vechiul bloc de memorie
			m_StartPtr = temp; //seteaza noua adresa de inceput
			m_Size = offset; //seteaza noua dimensiune a obiectului
		}
	}

	bool operator==(const Obiect& ob1, const Obiect& ob2)
	{
		//daca dimensiunile sunt egale, atunci compara fiecare byte pe intreaga dimensiune
		//returneaza true daca dimensiunile sunt egale si fiecare byte este egal
		//false pentru orice alt caz
		return ob1.m_Size == ob2.m_Size && std::memcmp(ob1.m_StartPtr, ob2.m_StartPtr, ob1.m_Size) == 0;
	}

	bool operator!=(const Obiect& ob1, const Obiect& ob2)
	{
		//returneaza true daca obiectele nu sunt egale (regulile de la operatorul ==)
		//returneaza false daca obiectele sunt egale (regulile de la operatorul ==)
		return !(ob1 == ob2);
	}

	bool operator<(const Obiect& ob1, const Obiect& ob2)
	{
		//compara fiecare byte pe dimensiunea mai mica dintre ob1 si ob2
		int value = std::memcmp(ob1.m_StartPtr, ob2.m_StartPtr, ob1.m_Size < ob2.m_Size ? ob1.m_Size : ob2.m_Size);

		//returneaza true daca este gasit un byte cu valoare mai mica in ob1 fata de ob2 sau daca fiecare byte
		//este egal si dimensiunea lui ob1 este mai mica decat cea a lui ob2
		//returneaza false in orice alt caz
		return value == -1 ? true : value == 0 ? ob1.m_Size < ob2.m_Size : false;
	}

	bool operator>(const Obiect& ob1, const Obiect& ob2)
	{
		//compara fiecare byte pe dimensiunea mai mica dintre ob1 si ob2
		int value = std::memcmp(ob1.m_StartPtr, ob2.m_StartPtr, ob1.m_Size < ob2.m_Size ? ob1.m_Size : ob2.m_Size);

		//returneaza true daca este gasit un byte cu valoare mai mare in ob1 fata de ob2 sau daca fiecare byte
		//este egal si dimensiunea lui ob1 este mai mare decat cea a lui ob2
		//returneaza false in orice alt caz
		return value == 1 ? true : value == 0 ? ob1.m_Size > ob2.m_Size : false;
	}

	bool operator<=(const Obiect& ob1, const Obiect& ob2)
	{
		//compara fiecare byte pe dimensiunea mai mica dintre ob1 si ob2
		int value = std::memcmp(ob1.m_StartPtr, ob2.m_StartPtr, ob1.m_Size < ob2.m_Size ? ob1.m_Size : ob2.m_Size);

		//returneaza true daca este gasit un byte cu valoare mai mica in ob1 fata de ob2 sau daca fiecare byte
		//este egal si dimensiunea lui ob1 este mai mica sau egala fata de cea a lui ob2
		//returneaza false in orice alt caz
		return value == -1 ? true : value == 0 ? ob1.m_Size <= ob2.m_Size : false;
	}

	bool operator>=(const Obiect& ob1, const Obiect& ob2)
	{
		//compara fiecare byte pe dimensiunea mai mica dintre ob1 si ob2
		int value = std::memcmp(ob1.m_StartPtr, ob2.m_StartPtr, ob1.m_Size < ob2.m_Size ? ob1.m_Size : ob2.m_Size);

		//returneaza true daca este gasit un byte cu valoare mai mare in ob1 fata de ob2 sau daca fiecare byte
		//este egal si dimensiunea lui ob1 este mai mare sau egala fata de cea a lui ob2
		//returneaza false in orice alt caz
		return value == 1 ? true : value == 0 ? ob1.m_Size >= ob2.m_Size : false;
	}

	Obiect& Obiect::operator=(const Obiect& obiect)
	{
		delete[] m_StartPtr; //sterge informatia curenta
		m_Size = obiect.m_Size; //modifica dimenisiunea obiectului in care se copiaza

		if (m_Size > 0) //aloca memorie doar pentru size > 0
		{
			m_StartPtr = new char[m_Size]; //aloca memorie noua
			std::memcpy(m_StartPtr, obiect.m_StartPtr, obiect.m_Size); //copiaza informatia
		}
		else //obiectul copiat este gol si informatia curenta este pierduta
		{
			m_StartPtr = NULL;
			m_Size = 0;
		}

		return *this;
	}

	std::istream& operator>>(std::istream& in, Obiect& ob)
	{
		bool reading = true;
		bool command_processed = false;
		int end_byte = 1;

		std::string command = " ";

		int offset = 0;

		std::cout << "help - lista comenzilor" << std::endl;
		
		in.ignore(1, '\n'); //ignora un return
		while (reading)
		{
			std::cout << "command:";
			std::getline(in, command); //asteapta comanda

			if (!command_processed && command == "help")
			{
				std::cout << "help   - lista comenzilor" << std::endl;
				std::cout << "types  - lista tipurilor disponibile" << std::endl;
				std::cout << "<type> - tipul de date al elementului" << std::endl;
				std::cout << "*Exemplu: float*" << std::endl;
				std::cout << "stop	 - oprirea citirii" << std::endl;
				command_processed = true;
			}

			if (!command_processed && command == "types")
			{
				std::cout << "bool, char, int, float, double" << std::endl;
				command_processed = true;
			}

			if (!command_processed && command == "stop")
			{
				break;
			}

			if (!command_processed && command == "bool")
			{
				int size = offset + sizeof(bool) + 1 + end_byte;
				std::cout << "value:";
				if (size > ob.m_Size)
				{

					void* temp = new char[size]; //aloca memorie suficienta
					memcpy(temp, ob.m_StartPtr, ob.m_Size); //copiaza informatiile in noul bloc de memorie
					delete ob.m_StartPtr; //elibereaza vechiul bloc de memorie
					ob.m_StartPtr = temp; //seteaza noua adresa de inceput
					ob.m_Size = size; //seteaza noua dimensiune a obiectului
				}
				
				bool temp;
				in >> temp;
				*((char*)ob.m_StartPtr + offset) = 'b';
				offset += 1;
				*(bool*)((char*)ob.m_StartPtr + offset) = temp;

				offset += sizeof(bool);
				
				command_processed = true;
				in.ignore(1, '\n'); //ignora un return
			}

			if (!command_processed && command == "char")
			{
				int size = offset + sizeof(char) + 1 + end_byte;
				std::cout << "value:";
				if (size > ob.m_Size)
				{

					void* temp = new char[size]; //aloca memorie suficienta
					memcpy(temp, ob.m_StartPtr, ob.m_Size); //copiaza informatiile in noul bloc de memorie
					delete ob.m_StartPtr; //elibereaza vechiul bloc de memorie
					ob.m_StartPtr = temp; //seteaza noua adresa de inceput
					ob.m_Size = size; //seteaza noua dimensiune a obiectului
				}

				char temp;
				in >> temp;
				*((char*)ob.m_StartPtr + offset) = 'c';
				offset += 1;
				*((char*)ob.m_StartPtr + offset) = temp;

				offset += sizeof(char);
				
				command_processed = true;
				in.ignore(1, '\n'); //ignora un return
			}

			if (!command_processed && command == "int")
			{
				int size = offset + sizeof(int) + 1 + end_byte;
				std::cout << "value:";
				if (size > ob.m_Size)
				{

					void* temp = new char[size]; //aloca memorie suficienta
					memcpy(temp, ob.m_StartPtr, ob.m_Size); //copiaza informatiile in noul bloc de memorie
					delete ob.m_StartPtr; //elibereaza vechiul bloc de memorie
					ob.m_StartPtr = temp; //seteaza noua adresa de inceput
					ob.m_Size = size; //seteaza noua dimensiune a obiectului
				}

				int temp;
				in >> temp;
				*((char*)ob.m_StartPtr + offset) = 'i';
				offset += 1;
				*(int*)((char*)ob.m_StartPtr + offset) = temp;

				offset += sizeof(int);

				command_processed = true;
				in.ignore(1, '\n'); //ignora un return
			}

			if (!command_processed && command == "float")
			{
				int size = offset + sizeof(float) + 1 + end_byte;
				std::cout << "value:";
				if (size > ob.m_Size)
				{

					void* temp = new char[size]; //aloca memorie suficienta
					memcpy(temp, ob.m_StartPtr, ob.m_Size); //copiaza informatiile in noul bloc de memorie
					delete ob.m_StartPtr; //elibereaza vechiul bloc de memorie
					ob.m_StartPtr = temp; //seteaza noua adresa de inceput
					ob.m_Size = size; //seteaza noua dimensiune a obiectului
				}

				float temp;
				in >> temp;
				*((char*)ob.m_StartPtr + offset) = 'f';
				offset += 1;
				*(float*)((char*)ob.m_StartPtr + offset) = temp;

				offset += sizeof(float);
			
				command_processed = true;
				in.ignore(1, '\n'); //ignora un return
			}

			if (!command_processed && command == "double")
			{
				int size = offset + sizeof(double) + 1 + end_byte;
				std::cout << "value:";
				if (size > ob.m_Size)
				{

					void* temp = new char[size]; //aloca memorie suficienta
					memcpy(temp, ob.m_StartPtr, ob.m_Size); //copiaza informatiile in noul bloc de memorie
					delete ob.m_StartPtr; //elibereaza vechiul bloc de memorie
					ob.m_StartPtr = temp; //seteaza noua adresa de inceput
					ob.m_Size = size; //seteaza noua dimensiune a obiectului
				}

				double temp;
				in >> temp;
				*((char*)ob.m_StartPtr + offset) = 'd';
				offset += 1;
				*(double*)((char*)ob.m_StartPtr + offset) = temp;

				offset += sizeof(double);
				
				command_processed = true;
				in.ignore(1, '\n'); //ignora un return
			}

			if (command_processed == false)
			{
				std::cout << "Invalid command!" << std::endl;
			}
		
			command_processed = false; //reseteaza comanda
		}

		if (ob.m_Size > 0)
		{
			*((char*)ob.m_StartPtr + offset) = NULL;
		}

		return in;
	}

	std::ostream& operator<<(std::ostream& out, const Obiect& ob)
	{
		int offset = 0;
		char type = 1;

		if (ob.m_StartPtr == NULL)
		{
			type = NULL;
		}

		while (type != NULL)
		{
			type = *((char*)ob.m_StartPtr + offset);
			offset += 1;

			switch (type)
			{
			case 'b':
				out << "bool:" << *(bool*)((char*)ob.m_StartPtr + offset) << std::endl;
				offset += sizeof(bool);
				break;

			case 'c':
				out << "char:" << *(char*)((char*)ob.m_StartPtr + offset) << std::endl;
				offset += sizeof(char);
				break;

			case 'i':
				out << "int:" << *(int*)((char*)ob.m_StartPtr + offset) << std::endl;
				offset += sizeof(int);
				break;

			case 'f':
				out << "float:" << *(float*)((char*)ob.m_StartPtr + offset) << std::endl;
				offset += sizeof(float);
				break;

			case 'd':
				out << "double:" << *(double*)((char*)ob.m_StartPtr + offset) << std::endl;
				offset += sizeof(double);
				break;

			default:
				break;
			}
		}

		return out;
	}
}