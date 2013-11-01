//////////////////////////////////////////////////////////
// Practica Final, por Jos� Mar�a P�rez-Mac�as y      ////
// Alberto Le�n Fern�ndez.		Grupo:  lfp027.       ////
// Programa de Autobuses                             /////
//                                                     //
//////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////
///Esta clase trata de los recursos gr�ficos del programa, como   ///
//Recuadros, l�neas, limpiapantala, una funci�n para esperar,etc  ///
/////////////////////////////////////////////////////////////////////

#include <iostream.h>

class pantalla
{
public:
	void espera();
	void limpiapantalla();
	void encuadrado();
	void bordesup();
	void bordeinf();
	void lateral();
	void centrado();
	pantalla(){}
	~pantalla(){}
};

void pantalla::encuadrado()
{
	int encuadre;
	for (encuadre=0; encuadre<80; encuadre++)
	{	cout << "*";	}
}
	
void pantalla::espera()
{
	cout << "Pulsa una tecla para continuar \n ";
	cin.ignore();
	cin.get();
}

void pantalla::limpiapantalla()
{
	for (int nuevalinea=0; nuevalinea<25; nuevalinea++)
	{	cout << "\n";	}
}

void pantalla::bordesup()
{
	cout << "\t\t ________________________________________________ \n"
		 << "\t\t|                                                |\n";
}

void pantalla::bordeinf()
{
	cout << "\t\t|________________________________________________|\n";
}
void pantalla::lateral()
{
cout << "\t\t|                                                |\n";
}
void pantalla::centrado()
{
	cout << "\t\t ";
}