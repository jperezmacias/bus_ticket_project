//////////////////////////////////////////////////////////
// Practica Final, por Jos� Mar�a P�rez-Mac�as y      ////
// Alberto Le�n Fern�ndez.		Grupo:  lfp027.       ////
// Programa de Autobuses                             /////
//                                                     //
//////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////// ///
//Esta clase nos sirve para hacer un modelo de                //
//almacenamiento de las fechas.                               //
//esta clase est� implementada dentro de la clase CListaTfnos///
//como una variable de tipo p�blico                           //
////////////////////////////////////////////////////////////////


#include <string.h>
#include <iostream.h>
class fecha
{
private:
	
	int m_dia, m_mes, m_diasemana;
	char nombredia[10];

public:

	//Encontramos muchas funciones miembro, declaradas en l�nea,
	//para acceder a las variables privadas
	
	void escribemes(int mes){m_mes = mes;}
	void escribedia(int dia){m_dia = dia;}	
	void escribediasemana(int diasemana){m_diasemana = diasemana;}

	int leemes(){return m_mes;}
	int leedia(void){return (m_dia);}
	int leediasemana(){return m_diasemana;}

	char* leenombredia(){return nombredia;}
	
	

	//con esta funcion calculamos el d�a que correspode en el mes
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
