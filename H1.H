//////////////////////////////////////////////////////////
// Practica Final, por José María Pérez-Macías y      ////
// Alberto León Fernández.		Grupo:  lfp027.       ////
// Programa de Autobuses                             /////
//                                                     //
//////////////////////////////////////////////////////////



// Inclusion de la libreria necesaria para esta clase
#include <string.h>



const int MAX = 10;
class Registro
{
	
	// Funciones y variables definidas como public
public:  
	char nombre[20];
	char destino[20], apellido[20];
	int mes, dia, distancia, clase,	precio;
	bool vuelta;
	fecha unafecha;

	int leeclase(){return clase;}
	char* leedestino(){return destino;}
	int leedistancia(){return distancia;}
	int leeprecio(){return precio;}
	bool leevuelta(){return vuelta;}

};


//////////////////////////////////////////////////////////
// Clase lista de billetes                            ////
//////////////////////////////////////////////////////////


class CListaTfnos
{
  friend class CAccesoTfnos;
  private:
    Registro Lista[MAX];
    int PrimerRegVacio;
  public:
    CListaTfnos() { PrimerRegVacio = 0; }
    int AsignarReg( const Registro &NuevoReg );
    int Buscar(Registro *preg);
	int Buscar1(Registro *preg);
	void listado();
	 
	
};



int CListaTfnos::AsignarReg( const Registro &NuevoReg )
{
  if ( PrimerRegVacio < MAX )
  {
    Lista[PrimerRegVacio++] = NuevoReg;
    return 1; // operación satisfactoria
  }
  else
    return 0; // espacio agotado
}


///////////////////////////////////////////////////////////////////////////
// Búsqueda secuencial de datos en un array. Esta función Lo busca y     //
//  asigna el valor de la lista donde se ha encontrado al punteroo preg  //
// que luego en el cpp se va a hacer una copia de la variabla a la que   //
//apunta por el nombre reg                                               //
///////////////////////////////////////////////////////////////////////////

int CListaTfnos::Buscar( Registro *preg )
{
  for ( int i = 0; i < PrimerRegVacio; i++ )
    if ( strcmp(preg->nombre, Lista[i].nombre) == 0 )
    {
      *preg = Lista[i];
      return 1; // se encontró
    }
    return 0;   // no se encontró
}

/////////////////////////////////////////////////////////////////
/// Busca por el apellido									/////
/////////////////////////////////////////////////////////////////

int CListaTfnos::Buscar1( Registro *preg )
{
  for ( int i = 0; i < PrimerRegVacio; i++ )
    if ( strcmp(preg->apellido, Lista[i].apellido) == 0 )
    {
      *preg = Lista[i];
      return 1; // se encontró
    }
    return 0;   // no se encontró
}

////////////////////////////////////////////////////////////////////
//// Muestra un listado de los Clientes que han hecho la reserva  //
////////////////////////////////////////////////////////////////////


void CListaTfnos::listado()
{
	cout<<"\n\n\n*******LISTADO DE CLIENTES********\n\n\n";
	cout<<"[APELLIDO]\t\t[NOMBRE]\t\t[DESTINO]\n";
	for(int i=0;i < PrimerRegVacio;i++)
	cout<<Lista[i].apellido<<"\t\t"
		<<Lista[i].nombre<<"\t\t"<<Lista[i].destino<<"\t\n";



}


