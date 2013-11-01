//////////////////////////////////////////////////////////
// Practica Final, por José María Pérez-Macías y      ////
// Alberto León Fernández.		Grupo:  lfp027.       ////
// Programa de Autobuses                             /////
//                                                     //
//////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////// ///
//Esta clase nos sirve para hacer un modelo de                //
//almacenamiento de las fechas.                               //
//esta clase está implementada dentro de la clase CListaTfnos///
//como una variable de tipo público                           //
////////////////////////////////////////////////////////////////


#include <string.h>
#include <iostream.h>
class fecha
{
private:
	
	int m_dia, m_mes, m_diasemana;
	char nombredia[10];

public:

	//Encontramos muchas funciones miembro, declaradas en lÍnea,
	//para acceder a las variables privadas
	
	void escribemes(int mes){m_mes = mes;}
	void escribedia(int dia){m_dia = dia;}	
	void escribediasemana(int diasemana){m_diasemana = diasemana;}

	int leemes(){return m_mes;}
	int leedia(void){return (m_dia);}
	int leediasemana(){return m_diasemana;}

	char* leenombredia(){return nombredia;}
	
	

	//con esta funcion calculamos el día que correspode en el mes
	//En ella utilizamos strcpy para poder almacenar la cadena entera

	void calculodia()
	{
		m_diasemana = m_dia % 7;

		if (m_diasemana == 1)
			strcpy(nombredia, "Lunes");
		else if (m_diasemana == 2)
			strcpy(nombredia, "Martes");		
		else if (m_diasemana == 3)
			strcpy(nombredia, "Miercoles");
		else if (m_diasemana == 4)
			strcpy(nombredia, "Jueves");
		else if (m_diasemana == 5)			   
			strcpy(nombredia, "Viernes");
		else if (m_diasemana == 6)
			strcpy(nombredia, "Sabado");
		else
			strcpy(nombredia, "Domingo");
	}
};
