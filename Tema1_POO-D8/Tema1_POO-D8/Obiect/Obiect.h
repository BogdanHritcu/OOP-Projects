#pragma once

#include <iostream>
#include <string>

namespace poo
{
	class Obiect
	{
	private:
		void* m_StartPtr;
		int m_Size;

	public:
		Obiect(); //= delete;
		Obiect(int size);
		Obiect(const Obiect& obiect);
		~Obiect();

		//
		void read();
		void show();
		
		//
		int getSize();
		void shrink();

		//
		friend bool operator==(const Obiect& ob1, const Obiect& ob2);
		friend bool operator!=(const Obiect& ob1, const Obiect& ob2);
		friend bool operator<(const Obiect& ob1, const Obiect& ob2);
		friend bool operator>(const Obiect& ob1, const Obiect& ob2);
		friend bool operator<=(const Obiect& ob1, const Obiect& ob2);
		friend bool operator>=(const Obiect& ob1, const Obiect& ob2);

		//
		Obiect& operator=(const Obiect& obiect);
		friend std::istream& operator>>(std::istream& in, Obiect& ob);
		friend std::ostream& operator<<(std::ostream& out, const Obiect& ob);
	};
}