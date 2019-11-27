#include "hotel.h"

namespace oop
{
	LocuriLibere::LocuriLibere()
	{
		incaperi = 0;
		camere = 0;
		apartamente = 0;
		restaurante = 0;
		sali_conf = 0;
		sali_scena = 0;
		sali_indiv = 0;
	}

	LocuriLibere::~LocuriLibere()
	{

	}

	Hotel::Hotel()
	{
		m_Rezervari = nullptr;
		m_NrRezervari = 0;

		m_Incaperi = nullptr;
		m_NrIncaperi = 0;
		
		m_Sali = nullptr;
		m_NrSali = 0;

		m_Restaurante = nullptr;
		m_NrRestaurante = 0;
	}

	Hotel::Hotel(const Hotel& hotel)
	{
		memcpy(m_LocuriLibere, hotel.m_LocuriLibere, 365);

		m_Rezervari = new Rezervare[hotel.m_NrRezervari];
		m_NrRezervari = hotel.m_NrRezervari;
		memcpy(m_Rezervari, hotel.m_Rezervari, m_NrRezervari * sizeof(Rezervare));

		m_NrIncaperi = hotel.m_NrIncaperi;
		m_Incaperi = new Incapere*[m_NrIncaperi];
		memcpy(m_Incaperi, hotel.m_Incaperi, m_NrIncaperi * sizeof(Incapere*));
		
		m_NrSali = hotel.m_NrSali;
		m_Sali = new Incapere*[m_NrSali];
		memcpy(m_Sali, hotel.m_Sali, m_NrSali * sizeof(Incapere*));

		m_NrRestaurante = hotel.m_NrRestaurante;
		m_Restaurante = new Incapere*[m_NrRestaurante];
		memcpy(m_Restaurante, hotel.m_Restaurante, m_NrRestaurante * sizeof(Incapere*));
	}

	Hotel& Hotel::operator=(const Hotel& hotel)
	{
		delete[] m_Rezervari;
		delete[] m_Incaperi;
		delete[] m_Sali;
		delete[] m_Restaurante;
		
		memcpy(m_LocuriLibere, hotel.m_LocuriLibere, 365);

		m_Rezervari = new Rezervare[hotel.m_NrRezervari];
		m_NrRezervari = hotel.m_NrRezervari;
		memcpy(m_Rezervari, hotel.m_Rezervari, m_NrRezervari * sizeof(Rezervare));

		m_NrIncaperi = hotel.m_NrIncaperi;
		m_Incaperi = new Incapere*[m_NrIncaperi];
		memcpy(m_Incaperi, hotel.m_Incaperi, m_NrIncaperi * sizeof(Incapere*));

		m_NrSali = hotel.m_NrSali;
		m_Sali = new Incapere*[m_NrSali];
		memcpy(m_Sali, hotel.m_Sali, m_NrSali * sizeof(Incapere*));

		m_NrRestaurante = hotel.m_NrRestaurante;
		m_Restaurante = new Incapere*[m_NrRestaurante];
		memcpy(m_Restaurante, hotel.m_Restaurante, m_NrRestaurante * sizeof(Incapere*));

		return *this;
	}

	Hotel::~Hotel()
	{
		eliminaIncaperi();
	}

	void Hotel::eliminaIncaperi()
	{
		int i;
		for (i = 0; i < m_NrIncaperi; i++)
		{
			delete m_Incaperi[i]; //sterge fiecare incapere in care se poate locui
		}
		delete[] m_Incaperi; //sterge vectorul de pointeri catre incaperile de locuit
		
		for (i = 0; i < m_NrSali; i++)
		{
			delete m_Sali[i]; //sterge fiecare sala de conferinta
		}
		delete[] m_Sali; //sterge vectorul de pointeri catre salile de conferinta

		for (i = 0; i < m_NrRestaurante; i++)
		{
			delete m_Restaurante[i]; //sterge fiecare restaurant
		}
		delete[] m_Restaurante; //sterge vectorul de pointeri catre restaurante

		/*
		for (i = 0; i < 365; i++) //seteaza locurile libere la 0 in toate incaperile
		{
			m_LocuriLibere[i].apartamente = 0;
			m_LocuriLibere[i].camere = 0;
			m_LocuriLibere[i].incaperi = 0;
			m_LocuriLibere[i].restaurante = 0;
			m_LocuriLibere[i].sali_conf = 0;
			m_LocuriLibere[i].sali_indiv = 0;
			m_LocuriLibere[i].sali_scena = 0;
		}
		*/
	}

	void Hotel::citireIncaperi(const std::string& nume_fisier)
	{
		std::ifstream fisier(nume_fisier);

		int tip;
		int nr_incaperi;
		int nr_locuri;
		int i;
		int proiector;

		if (fisier.is_open())
		{
			Incapere** temp;
			while (fisier >> tip)
			{
				 fisier >> nr_incaperi;

				switch (tip)
				{
				case TipIncapere::camera:
					fisier >> nr_locuri; //citeste cate locuri sunt intr-o camera

					temp = m_Incaperi; //retine vectorul de pointeri la incaperi
					m_Incaperi = new Incapere*[m_NrIncaperi + nr_incaperi]; //aloca un nou vectori de pointeri la incaperi suficient de mare
					if (temp != nullptr)
					{
						memcpy(m_Incaperi, temp, m_NrIncaperi * sizeof(Incapere*)); //copiaza vechiul vector de pointeri in cel nou
						delete[] temp; //sterge vechiul vector de pointeri
					}

					for (i = m_NrIncaperi; i < m_NrIncaperi + nr_incaperi; i++) //creaza noile incaperi
					{
						m_Incaperi[i] = new Camera(nr_locuri);
					}
					m_NrIncaperi += nr_incaperi; //actualizeaza dimensiunea vectorului de incaperi

					for (i = 0; i < 365; i++) //adauga numarul de locuri libere pentru fiecare zi
					{
						m_LocuriLibere[i].camere += nr_incaperi * nr_locuri;
						m_LocuriLibere[i].incaperi += nr_incaperi * nr_locuri;
					}

					break;

				case TipIncapere::apartament:
					fisier >> nr_locuri; //citeste cate locuri sunt intr-un apartament

					temp = m_Incaperi; //retine vectorul de pointeri la incaperi
					m_Incaperi = new Incapere*[m_NrIncaperi + nr_incaperi]; //aloca un nou vectori de pointeri la incaperi suficient de mare
					if (temp != nullptr)
					{
						memcpy(m_Incaperi, temp, m_NrIncaperi * sizeof(Incapere*)); //copiaza vechiul vector de pointeri in cel nou
						delete[] temp; //sterge vechiul vector de pointeri
					}

					for (i = m_NrIncaperi; i < m_NrIncaperi + nr_incaperi; i++) //creaza noile incaperi
					{
						m_Incaperi[i] = new Apartament(nr_locuri);
					}
					m_NrIncaperi += nr_incaperi; //actualizeaza dimensiunea vectorului de incaperi

					for (i = 0; i < 365; i++) //adauga numarul de locuri libere pentru fiecare zi
					{
						m_LocuriLibere[i].apartamente += nr_incaperi * nr_locuri;
						m_LocuriLibere[i].incaperi += nr_incaperi * nr_locuri;
					}

					break;

				case TipIncapere::restaurant:
					fisier >> nr_locuri; //citeste cate locuri sunt intr-un restaurant
					temp = m_Restaurante; //retine vectorul de pointeri la restaurante
					m_Restaurante = new Incapere*[m_NrRestaurante + nr_incaperi]; //aloca un nou vectori de pointeri la restaurante suficient de mare
					if (temp != nullptr)
					{
						memcpy(m_Restaurante, temp, m_NrRestaurante * sizeof(Incapere*)); //copiaza vechiul vector de pointeri in cel nou
						delete[] temp; //sterge vechiul vector de pointeri
					}

					for (i = m_NrRestaurante; i < m_NrRestaurante + nr_incaperi; i++) //creaza noile restaurante
					{
						m_Restaurante[i] = new Restaurant(nr_locuri);
					}
					m_NrRestaurante += nr_incaperi; //actualizeaza dimensiunea vectorului de restaurante

					for (i = 0; i < 365; i++) //adauga numarul de locuri libere pentru fiecare zi
					{
						m_LocuriLibere[i].restaurante += nr_incaperi * nr_locuri;
					}

					break;
					
				case TipIncapere::sala_individuala:
					int nr_mese;
					int locuri_masa;
					fisier >> nr_mese >> locuri_masa; //citeste informatiile despre mese
					fisier >> proiector; //citeste daca salile au proiector
					nr_locuri = nr_mese * locuri_masa;

					temp = m_Sali; //retine vectorul de pointeri la sali
					m_Sali = new Incapere*[m_NrSali + nr_incaperi]; //aloca un nou vectori de pointeri la sali suficient de mare
					if (temp != nullptr)
					{
						memcpy(m_Sali, temp, m_NrSali * sizeof(Incapere*)); //copiaza vechiul vector de pointeri in cel nou
						delete[] temp; //sterge vechiul vector de pointeri
					}

					for (i = m_NrSali; i < m_NrSali + nr_incaperi; i++) //creaza noile sali
					{
						m_Sali[i] = new SalaIndiv(nr_locuri, nr_mese, locuri_masa);

						try
						{
							SalaIndiv* temp = dynamic_cast<SalaIndiv*>(m_Sali[i]);
							temp->setProiector((bool)proiector);
						}
						catch (const std::exception& e)
						{
							std::cout << e.what() << std::endl; //afiseaza exceptia
							return; //iesi din functie
						}
					}
					m_NrSali += nr_incaperi; //actualizeaza dimensiunea vectorului de sali

					for (i = 0; i < 365; i++) //adauga numarul de locuri libere pentru fiecare zi
					{
						m_LocuriLibere[i].sali_conf += nr_incaperi * nr_locuri;
						m_LocuriLibere[i].sali_indiv += nr_incaperi * nr_locuri;
					}

					break;

				case TipIncapere::sala_scena:
					fisier >> nr_locuri; //citeste cate locuri sunt intr-o sala scena
					fisier >> proiector; //citeste daca salile au proiector

					temp = m_Sali; //retine vectorul de pointeri la sali
					m_Sali = new Incapere*[m_NrSali + nr_incaperi]; //aloca un nou vectori de pointeri la sali suficient de mare
					if (temp != nullptr)
					{
						memcpy(m_Sali, temp, m_NrSali * sizeof(Incapere*)); //copiaza vechiul vector de pointeri in cel nou
						delete[] temp; //sterge vechiul vector de pointeri
					}

					for (i = m_NrSali; i < m_NrSali + nr_incaperi; i++) //creaza noile sali
					{
						m_Sali[i] = new SalaScena(nr_locuri);
						
						try
						{
							SalaScena* temp = dynamic_cast<SalaScena*>(m_Sali[i]);
							temp->setProiector((bool)proiector);
						}
						catch (const std::exception& e)
						{
							std::cout << e.what() << std::endl;
							return;
						}
					}
					m_NrSali += nr_incaperi; //actualizeaza dimensiunea vectorului de sali

					for (i = 0; i < 365; i++) //adauga numarul de locuri libere pentru fiecare zi
					{
						m_LocuriLibere[i].sali_conf += nr_incaperi * nr_locuri;
						m_LocuriLibere[i].sali_scena += nr_incaperi * nr_locuri;
					}

					break;

				default:
					break;
				}
			}
			fisier.close();
		}
		else
		{
			std::cout << "Nu s-a putut deschide fisierul: " << nume_fisier << std::endl;
		}
	}

	int Hotel::getNrLocuriLibere(int zi, TipIncapere tip)
	{
		zi--;
		switch (tip)
		{
		case TipIncapere::incapere_locuit:
			return m_LocuriLibere[zi].incaperi;
			
		case TipIncapere::camera:
			return m_LocuriLibere[zi].camere;

		case TipIncapere::apartament:
			return m_LocuriLibere[zi].apartamente;

		case TipIncapere::restaurant:
			return m_LocuriLibere[zi].restaurante;

		case TipIncapere::sala_conferinta:
			return m_LocuriLibere[zi].sali_conf;

		case TipIncapere::sala_scena:
			return m_LocuriLibere[zi].sali_scena;

		case TipIncapere::sala_individuala:
			return m_LocuriLibere[zi].sali_indiv;

		default:
			return -1;
		}
	}

	void Hotel::acceptaCerere(const Cerere& cerere)
	{
		if (cerere.getTip() == TipCerere::rezervare)
		{
			int zi;
			int zi_sedere;
			int durata_sedere = cerere.getGrup()->getDurataSedere();

			int nr_participanti = cerere.getGrup()->getNrParticipanti();
			int ln_incaperi = nr_participanti;
			int ln_sali = nr_participanti;
			int ln_restaurante = 0;

			int i;
			for (i = 0; i < nr_participanti; i++)
			{
				ln_restaurante += (int)(cerere.getGrup()->getParticipanti() + i)->restaurant();
			}

			bool stop = false;

			for (zi = 0; zi < 365 && !stop; zi++)
			{
				stop = true;
				for (zi_sedere = zi; zi_sedere < zi + durata_sedere; zi_sedere++)
				{
					if (zi_sedere >= 365) //daca am trecut de sfarsitul anului
					{
						stop = true;
						std::cout << "Grupul nu poate fi cazat in acest an." << std::endl;
						break;
					}

					if (
						ln_incaperi > m_LocuriLibere[zi_sedere].incaperi || //nu sunt destule locuri pentru locuit       
						(
						(cerere.getTipSala() == TipIncapere::sala_individuala && ln_sali > m_LocuriLibere[zi_sedere].sali_indiv) || //nu sunt destule locuri in salaile
							(cerere.getTipSala() == TipIncapere::sala_scena && ln_sali > m_LocuriLibere[zi_sedere].sali_scena)  		//de conferinta de tipurile cerute
							)
						|| ln_restaurante > m_LocuriLibere[zi_sedere].restaurante //nu sunt destule locuri la restaurant
						)
					{
						stop = false;
						zi = zi_sedere;
						break;
					}
				}
			}

			int j;
			int k;
			int part = 0;
			zi--;
			bool disponibila;

			if (stop == true && zi + durata_sedere < 365) //daca s-a oprit cautarea pentru locuri disponibile si nu s-a trecut de sfarsitul anului
			{
				//adauga rezervarea
				Rezervare* temp = m_Rezervari; //memoreaza pointerul catre vechiul vector de rezervari
				m_Rezervari = new Rezervare[m_NrRezervari + 1]; //aloca un nou vector de rezervari
				memcpy(m_Rezervari, temp, m_NrRezervari); //copiaza vechiul vector de rezervari
				delete[] temp; //sterge vechiul vector de rezervari

				m_Rezervari[m_NrRezervari].setGrup(cerere.getGrup()); //grupul noii rezervari
				m_Rezervari[m_NrRezervari].setZiCazare(zi + 1); //ziua in care se cazeaza grupul
				m_Rezervari[m_NrRezervari].setDurataSedere(durata_sedere); //durata sederii grupului

				//aseaza participantii in camere
				for (i = 0; i < m_NrIncaperi && part < nr_participanti; i++) //parcurge incaperile cat timp mai sunt participanti de cazat
				{
					disponibila = true; //initial seteaza incaperea ca fiind disponibila
					for (j = zi; j < zi + durata_sedere && disponibila; j++) //verifica daca este disponibila in fiecare zi
					{
						disponibila = m_Incaperi[i]->disponibila(j); //daca incaperea nu este disponibila in una din zile, se trece la urmatoarea incapere 
					}

					if (disponibila) //daca incapere a ramas disponibila in toate zilele atunci se adauga participantii la camere
					{
						for (k = 0; k < m_Incaperi[i]->getNumarLocuri() && part < nr_participanti; k++) //pentru fiecare loc din incapere 
						{
							cerere.getGrup()->getParticipanti()[part].setIncapere(*m_Incaperi[i]); //adauga participantul curent in incapere
							part++; //treci la urmatorul participant
						}

						for (j = zi; j < zi + durata_sedere; j++) //seteaza incaperea ca fiind indisponibila pe tot parcursul sederii
						{
							m_Incaperi[i]->setDisponibila(j, false); //incaperea curenta (i) este setata ca indisponibila in ziua respectiva (j)
							m_LocuriLibere[j].incaperi -= m_Incaperi[i]->getNumarLocuri(); //scade numarul de locuri al incaperii (i) din numarul de locuri
																						   //disponibile din ziua respectiva (j)
							TipIncapere tip = m_Incaperi[i]->getTip();
							switch (tip)
							{
							case TipIncapere::camera:
								m_LocuriLibere[j].camere -= m_Incaperi[i]->getNumarLocuri(); //scade numarul de locuri disponibile de la camere
								break;

							case TipIncapere::apartament:
								m_LocuriLibere[j].apartamente -= m_Incaperi[i]->getNumarLocuri(); //scade numarul de locuri disponibile de la apartamente
								break;

							default:
								break;
							}
						}
					}
				}

				//rezerva salile de conferinta pentru grupuri
				for (i = 0; i < m_NrSali; i++) //parcurge incaperile cat timp mai sunt participanti de cazat
				{
					if (m_Sali[i]->getTip() == cerere.getTipSala()) //daca sala este de tipul cerut
					{
						disponibila = true; //initial seteaza sala ca fiind disponibila
						for (j = zi; j < zi + durata_sedere && disponibila; j++) //verifica daca este disponibila in fiecare zi
						{
							disponibila = m_Sali[i]->disponibila(j); //daca sala nu este disponibila in una din zile, se trece la urmatoarea incapere 
						}

						if (disponibila) //daca sala a ramas disponibila in toate zilele atunci se adauga la rezervare
						{
							m_Rezervari[m_NrRezervari].setSalaConf(m_Sali[i]); //adauga sala la rezervare

							for (j = zi; j < zi + durata_sedere; j++) //seteaza sala ca fiind indisponibila pe tot parcursul sederii
							{
								m_Sali[i]->setDisponibila(j, false); //sala curenta (i) este setata ca indisponibila in ziua respectiva (j)
								m_LocuriLibere[j].sali_conf -= m_Sali[i]->getNumarLocuri(); //scade numarul de locuri al salii (i) din numarul de locuri
																							//disponibile din ziua respectiva (j)
								TipIncapere tip = m_Sali[i]->getTip();
								switch (tip)
								{
								case TipIncapere::sala_scena:
									m_LocuriLibere[j].sali_scena -= m_Sali[i]->getNumarLocuri(); //scade numarul de locuri disponibile de la salile scena
									break;

								case TipIncapere::sala_individuala:
									m_LocuriLibere[j].sali_indiv -= m_Sali[i]->getNumarLocuri(); //scade numarul de locuri disponibile de la salile individuale
									break;

								default:
									break;
								}
							}

							break; //sala a fost gasita
						}
					}
					else
					{
						//treci la urmatoarea sala 
					}
				}

				m_NrRezervari++; //treci la urmatoarea rezervare
			}
		}
		else
		{
			Participant* participanti = cerere.getGrup()->getParticipanti();
			int nr_participanti = cerere.getGrup()->getNrParticipanti();
			int durata_sedere = 0;
			int zi_cazare = 0;
			int i;
			Incapere* sala_conf = nullptr;

			for (i = 0; i < m_NrRezervari; i++)
			{
				if (m_Rezervari[i].getGrup()->getID() == cerere.getGrup()->getID())
				{
					zi_cazare = m_Rezervari[i].getZiCazare();
					durata_sedere = m_Rezervari[i].getDurataSedere();
					sala_conf = m_Rezervari[i].getSalaConf();

					if (i < m_NrRezervari - 1)
					{
						memcpy(m_Rezervari + i, m_Rezervari + i + 1, (m_NrRezervari - i - 1) * sizeof(Rezervare));
					}

					m_NrRezervari--;
					break;
				}
			}
			
			int zi;

			//elibereaza camerele
			for (i = 0; i < nr_participanti; i++)
			{
				for (zi = zi_cazare; zi < zi_cazare + durata_sedere; zi++)
				{
					int tip = participanti[i].getIncapere()->getTip();

					switch (tip)
					{
					case TipIncapere::camera:
						if (participanti[i].getIncapere()->disponibila(zi) == false)
						{
							m_LocuriLibere[zi].camere += participanti[i].getIncapere()->getNumarLocuri();
							m_LocuriLibere[zi].incaperi += participanti[i].getIncapere()->getNumarLocuri();
						}
						break;

					case TipIncapere::apartament:
						if (participanti[i].getIncapere()->disponibila(zi) == false)
						{
							m_LocuriLibere[zi].apartamente += participanti[i].getIncapere()->getNumarLocuri();
							m_LocuriLibere[zi].incaperi += participanti[i].getIncapere()->getNumarLocuri();
						}
						break;

					default:
						break;
					}

					participanti[i].getIncapere()->setDisponibila(zi, true);

					m_LocuriLibere[zi].restaurante += (int)participanti[i].restaurant(); //elibereaza locurile de la restaurant
				}
			}

			//elibereaza sala de conferinta
			for (zi = zi_cazare; zi < zi_cazare + durata_sedere; zi++)
			{
				m_LocuriLibere[zi].sali_conf += sala_conf->getNumarLocuri();

				if (sala_conf->getTip() == TipIncapere::sala_individuala)
				{
					m_LocuriLibere[zi].sali_indiv += sala_conf->getNumarLocuri();
				}
				else if(sala_conf->getTip() == TipIncapere::sala_scena)
				{
					m_LocuriLibere[zi].sali_scena += sala_conf->getNumarLocuri();
				}
			}
		}
	}

	void Hotel::afisareRezervari(bool afisare_grupuri) const
	{
		int i;
		for (i = 0; i < m_NrRezervari; i++)
		{
			m_Rezervari[i].afiseaza(afisare_grupuri);
			std::cout << std::endl;
		}
	}

	void Hotel::afiseazaStructura() const
	{
		int i;

		std::cout << "INCAPERI PENTRU LOCUIT" << std::endl;
		for (i = 0; i < m_NrIncaperi; i++)
		{
			m_Incaperi[i]->afiseaza();
		}

		std::cout << "SALI DE CONFERINTA" << std::endl;
		for (i = 0; i < m_NrSali; i++)
		{
			m_Sali[i]->afiseaza();
		}

		std::cout << "RESTAURANTE" << std::endl;
		for (i = 0; i < m_NrRestaurante; i++)
		{
			m_Restaurante[i]->afiseaza();
		}
	}
}