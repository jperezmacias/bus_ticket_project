//////////////////////////////////////////////////////////
// Practica Final, por José María Pérez-Macías y      ////
// Alberto León Fernández.		Grupo:  lfp027.       ////
// Programa de Autobuses                             /////
//                                                     //
//////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////
///Esta clase trata de los recursos gráficos del programa, como   ///
//Recuadros, líneas, limpiapantala, una función para esperar,etc  ///
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