//////////////////////////////////////////////////////////
// Practica Final, por José María Pérez-Macías y      ////
// Alberto León Fernández.		Grupo:  lfp027.       ////
// Programa de Autobuses                             /////
//                                                     //
//////////////////////////////////////////////////////////
/*esta clase tiene como objetivo el acceso a las distintas
reservas realizadas, y su busqueda por los distintos campos
que son mas utiles. Asi son el nombre, apellido, destino y mes
*/
class CAccesoTfnos
{
  private:
    CListaTfnos *const pLista;
    int IndiceActual;
  public:
    CAccesoTfnos( CListaTfnos &x ):
      pLista( &x ), IndiceActual( 0 ) {}
    int Primero(Registro *);
    int Ultimo(Registro *);
    int Siguiente(Registro *);
    int Anterior(Registro *);
};

/*Accederemos a las distintas reservas mediante estas cuantro
funciones, que nos movieran por el array que hemos hecho a partir
de la clase reservas. De tal forma que usaremos los punteros para
apuntar al siguiente, anteerior, primero y ultimo elemento del array
segun como manipulemos el puntero*/


int CAccesoTfnos::Primero(Registro *pReg)
{
  if ( pLista->PrimerRegVacio == 0 )
    return 0;
  else
  {
    IndiceActual = 0;
    *pReg = pLista->Lista[0];
    return 1;
  }
}

// Último registro de la lista
int CAccesoTfnos::Ultimo(Registro *pReg)
{
  if ( pLista->PrimerRegVacio == 0 )
    return 0;
  else
  {
    IndiceActual = pLista->PrimerRegVacio-1;
    *pReg = pLista->Lista[IndiceActual];
    return 1;
  }
}

/* en las funciones miembro que se refieren al siguiente y al anterior
ponemos una sntencia condicional, puesto que si nos encontramos
en una determinada reserva y queremos ir al siguiente, cabe la posibilidad
que nos encontremos en la ultima reserva hecha, es entonces cuando no 
podriamos ver el siguiente elemento puesto que no existe. 
	Para ello tomamos como referencia el primer registro vacio, 
puesto que en esta variable almacenamos el Primer Registro que esta
vacio.
*/


int CAccesoTfnos::Siguiente(Registro *pReg)		// Siguiente registro de la lista
{
  if ( IndiceActual < pLista->PrimerRegVacio-1 )
  {
    IndiceActual++;
    *pReg = pLista->Lista[IndiceActual];
    return 1;						//Me devuelve en valor verdadero
									//de tal forma que indica que se
									//ha encntrado. Esto lo utiliza la
									//función visualizr

  }
  else
    return 0;
}


int CAccesoTfnos::Anterior(Registro *pReg)	// Anterior registro de la lista
{
  if ( IndiceActual > 0 )
  {
    IndiceActual--;
    *pReg = pLista->Lista[IndiceActual];
    return 1;
  }
  else
    return 0;
}


