//////////////////////////////////////////////////////////
// Practica Final, por José María Pérez-Macías y      ////
// Alberto León Fernández.		Grupo:  lfp027.       ////
// Programa de Autobuses                             /////
//                                                     //
//////////////////////////////////////////////////////////


//**************************************************************//
//Inclusion de las librerias	y ficheros de cabecera			//
//	que nos van a ser necesarios								//
//**************************************************************//



#include <fstream.h>	//Definiciones básicas entrada/salida C++
#include <iostream.h>	
#include <stdlib.h>		//Librería estándar de funciones generales
#include "fecha.h"		//Definicíón de la clase fecha
#include "H1.h"			//Definiciones de la clase billete y estacion1
#include "H2.h"			//Definicines de la clase que accede a el billete
#include "pantalla.h"	//Definiciones para manejar las proiedades de la pantalla


//Prototipos de funciones que se utilizan a lo largo del *.cpp
// Prototipos de funciones sin retorno de valor/////

void menubuscar(CListaTfnos &Trabajo, Registro & Xreg);
void visualbillete(Registro &res);
void menu( int & );
void guardardisco(CListaTfnos &Trabajo);
void inicializar(CListaTfnos &);
void ayuda();
void cuando(Registro &NuevoReg);
void destino(Registro &NuevoReg, CListaTfnos &);
void guardareserva(Registro &NuevoReg,Registro &, CListaTfnos &);

// Prototipos de funciones con retorno de valor

int visualizar( CListaTfnos &);
int aumento(int, int);
int descuento(int, int, Registro &NuevoReg);
int nuevareserva(Registro &NuevoReg, CListaTfnos &, Registro &);
int precio(int, Registro &NuevoReg);		   


/////////////////////////////////////////////////////////////////////
// Funcion principal, retorna el valor int 0 del sistema operativo///
/////////////////////////////////////////////////////////////////////

int main()
{

// Declaracion de objetos 
  
  CListaTfnos Trabajo;			//objeto para manejar los billetes de la estacion
  Registro NuevoReg, reg;		//objeto que representa un bilete
								//el objeto reg lo utilizamos para hacer una copia 
								//en el de el billete que queremos ver


  //se trata del menu principal del programa. Usa la funcion system() contenida en
  //la librería stdlib.h que está en el directorio de los includes
  
  int opcion;
  inicializar(Trabajo);	
  do
  {
    menu( opcion );
    system( "cls" );
    switch ( opcion )
    {
      case 1:										//opcion nueva reserva
        nuevareserva(NuevoReg, Trabajo, reg);
			
		 break;
      case 2:
	     ayuda();									//ayuda interactiva
		 break;
      case 3:
        visualizar( Trabajo );						//interfaz de navegacion
        break;
      case 4:
		  menubuscar(Trabajo, NuevoReg);			//búsqueda por campos
		  break;
	  case 5:										//Salida del programa
        return 0;
    }
    cout << "\nPulse Entrar para continuar ";
    cin.get();
  }
  while ( 1 );										//el bucle se repite mientras
													//nos devuelva un valor 1 (TRUE)

}

////////////////////////////////////////////////////////////////////////////////////
// Funcion del menu principal, (sin retorno) Se trata simplemente del uso del cout//
//tiene un parámetro que es pasado por referencia, y ésta es llamada op           //
////////////////////////////////////////////////////////////////////////////////////


void menu( int &op )
{
	pantalla *lapantalla = new pantalla();			//uso de la clase pantalla
													//mas adelante comentada
	system( "cls" );
	cout<<"\n";
	lapantalla->bordesup();

		cout << "\t\t|    ////////MENU PRINCIPAL///////               |\n"
			 << "\t\t|                                                |\n"
			 << "\t\t|     (1) Nueva Reserva                          |\n"
			 << "\t\t|     (2) Ayuda                                  |\n"
			 << "\t\t|     (3) Visualizacion de billetes              |\n"
			 << "\t\t|     (4) Busqueda / Listados                    |\n"
			 << "\t\t|     (5) SALIDA                                 |\n"
			 << "\t\t|                                                |\n"
			 << "\t\t|     *******ELIJA UNA OPCION*******             |\n";
		lapantalla->bordeinf();
		cin >> op; cin.ignore();
		delete lapantalla;

}
///////////////////////////////////////////////////////////////////////////////
//Función que visualiza los distintos billetes, por un interfaz de navegación//  
//La función hace uso de la clase CAcceslista, que es la que maneja todo el  //
//interfaz de navegacion, todo ello mediante punteros.                       //
//pasamos por referencia El objeto Trabajo                                   //
///////////////////////////////////////////////////////////////////////////////

int visualizar( CListaTfnos &lista )
{
	pantalla *lapantalla = new pantalla();

	Registro registro;					//Creamos un objeto tipo registro para poder
										//grabar ahí lo que los punteros de la clase
										//acceso lista apunten
	CAccesoTfnos Ver( lista );

	
	int vr;
	lapantalla->bordesup();
	lapantalla->lateral();
	lapantalla->centrado();cout<<"NAVEGACION  ACTIVADA\n";
	lapantalla->lateral();
	lapantalla->bordeinf();
	cout<<"\n\n[1 - Primero]	[2 - Ultimo]	[3 - Anterior]	[4 - Siguiente]";
	
  cout << "\n\n\t\t\tPulse una opcion u\n"
       << "Otro caracter para finalizar\n\n";
  
//MENU DE NAVEGACION. en el usamos las funciones mienbro de la clase CAccesoList



  char car = cin.get(); cin.ignore();
  while ( car == '1' || car == '2' || car == '3' || car == '4' )
  {
    if ( car == '1' )
      vr = Ver.Primero( &registro );
    else if ( car == '2' )
      vr = Ver.Ultimo( &registro );
    else if ( car == '4' )
      vr = Ver.Siguiente( &registro );
    else if ( car == '3' )
      vr = Ver.Anterior( &registro );
    else
      return 0;
    if ( vr )					//Si el valor de vr es 1/0 se muestra el billete o no,
								//según se haya encontrad o no.
	{
		visualbillete(registro);
		cout<<"\n\n[1 - Primero]	[2 - Ultimo]	[3 - Anterior]	[4 - Siguiente]";
		cout<<"\n\no bien pulse otra tecla para salir de la navegacion";
	}
	else
		cout<<"NO HAY MAS!!!!!!\n\nINTRODUCE OTRA OPCION O PULSA CUALQUIER OTRA\nPARA SALIR\n";
		car = cin.get(); cin.ignore();
  }
  delete lapantalla;					//Borramos el puntero pantalla
  return 0;
}

/////////////////////////////////////////////////////////////////////////////
// Funcion nuevareserva: Es la función troncal a la hora de hacer reservas///
//y del funcionamiento del programa,Va llamando a todas las funciones      //
//relacionadas necesarias para hacer todos los cálculos de reservas        //
// con la creacion de nuevas reservas de billetes                          //
/////////////////////////////////////////////////////////////////////////////

int nuevareserva(Registro &NuevoReg, CListaTfnos &Trabajo, Registro &reg)
{ 	
									
	int distancia, coste, diasemana,    // Declaracion de variables locales
		coste_total, oferta, recargo;
	
	
	destino(NuevoReg, Trabajo);			// Llamada a funciones y asignacion de
										//valores de distintas variables
			
	distancia = NuevoReg.leedistancia();	//lee la distancia para luego
											//utilizarlo en el precio
	
	coste = precio(distancia, NuevoReg);
	
	cuando(NuevoReg);
			
	diasemana = NuevoReg.unafecha.leediasemana();
	
	recargo = aumento(diasemana, coste);
	
	oferta = descuento(coste, distancia, NuevoReg);
	
	coste_total = coste + oferta + recargo;

	if (NuevoReg.leevuelta()==true)
		coste_total = coste_total * 2;
	
	NuevoReg.precio=coste_total;
	
	
	guardareserva(NuevoReg, reg, Trabajo);			//guarda la reserva hecha a
													//petición del usuario
	


	return 0;
}

//////////////////////////////////////////////////////////////////////
// Funcion cuando: proporciona la entrada del dia y mes de salida,  //
// la posibilidad de billete de vuelta, el dia  y mes de vuelta     //
//////////////////////////////////////////////////////////////////////

void cuando(Registro &NuevoReg)
{
	pantalla *lapantalla = new pantalla();
	
	int dia_s, mes_s, dia_ano_s = 0, dia_l, mes_l;
	char a;

	lapantalla->limpiapantalla();
	lapantalla->bordesup();

	cout << "\t\t|   Introduzca el dia de salida                  |\n";
		 
	lapantalla->bordeinf();
	
	cin >> dia_s;
	
	lapantalla->limpiapantalla();
	lapantalla->bordesup();
	
	cout << "\t\t|   Introduzca el mes de salida                  |\n";

	lapantalla->bordeinf();
	
	cin >> mes_s;
	NuevoReg.dia=dia_s;
	NuevoReg.mes=mes_s;
	NuevoReg.unafecha.escribedia(dia_s);
	NuevoReg.unafecha.escribemes(mes_s);
	
	lapantalla->limpiapantalla();
	lapantalla->bordesup();

// Posibilidad de billete de vuelta
// ////////////////////////////////

	cout << "\t\t|   Quiere billete de vuelta?                    |\n"
		 << "\t\t|                                                |\n"
	     << "\t\t|     (S/N)                                      |\n";
		 
	lapantalla->bordeinf();
	
	cin >> a;



	
		
	if (a=='S')								//En el caso afirmativo pregunta
											//Por el dia y mes de llgada

	{
		NuevoReg.vuelta=true;	 			//fijamos la variable booleana
											//a verdadero puesto que se ha
											//elegido que quiere vuelta

		
		lapantalla->limpiapantalla();
		lapantalla->bordesup();
		cout << "\t\t|   Introduzca el dia de llegada                 |\n";
		lapantalla->bordeinf();

		cin >> dia_l;

		lapantalla->limpiapantalla();
		lapantalla->bordesup();
		cout << "\t\t|   Introduzca numero del mes de llegada         |\n";
		lapantalla->bordeinf();
		
		cin >> mes_l;
				
		NuevoReg.unafecha.calculodia();			//calculo del dia: funcion miembro
												//de la clase fecha
	}	
	delete lapantalla;
}

////////////////////////////////////////////////////////////////////
//Funcion precio: da la opcion de la clase en que viajar        ////
// y calcula el precio del billete con relacion al destino      ////
// y a la clase elegidos 										////
////////////////////////////////////////////////////////////////////
		   
int precio(int distancia, Registro &NuevoReg)
{	
	pantalla *lapantalla = new pantalla();
	int coste, clase;
	char b='P';

while(true)		
	{	
		lapantalla->limpiapantalla();
		lapantalla->bordesup();

		cout << "\t\t|   Que clase prefiere?                          |\n"
		     << "\t\t|                                                |\n"
			 << "\t\t|    (1) Primera Clase.                          |\n"
			 << "\t\t|    (2) Clase Turista.                          |\n";
			 
		lapantalla->bordeinf();

		cin >> b;
	
		if ((b=='1')||(b=='2'))
		{	
			if (b=='1')
			{	coste = distancia *15;
				clase = 1;	}	   	
			else if (b=='2')
			{	coste = distancia *8;
				clase =2;	}
		break;
		}
	}

	NuevoReg.clase=clase;
	delete lapantalla;
	return coste;
}
///////////////////////////////////////////////////////////////
// Halla el aumento de precio del billete segun el dia de la //
//semana en que se va a viajar.                              //
///////////////////////////////////////////////////////////////	
	
	
int aumento(int dia_semana, int coste)
{
	int recargo;

	if (dia_semana == 6)
		recargo = (coste * 12/100);
	
	else if (dia_semana == 5)
		recargo = (coste * 7/100);

	else 
		recargo = 0;
	
	return recargo;
}

/////////////////////////////////////////////////////////////////////////
// Funcion descuento: halla los descuentos correspondientes a comprar  //
// billete de ida y vuelta y descuento por kilometros                  //
/////////////////////////////////////////////////////////////////////////

int descuento(int coste, int distancia, Registro &elbillete)
{
	int oferta,oferta1,oferta2,a=(distancia/100);	 // Halla la posibilidad de 
													//descuento por 
													// cantidad de kilometros 
													//recorridos
	if (a>=1)
		oferta1 = coste * 2 * a / 100;
	else 
		oferta1 = 0;
		
								  		
	if (elbillete.leevuelta()==true)
		oferta2 = coste * 15 / 100;
	else 
		oferta2 = 0;
		oferta = oferta1 + oferta2;		// Valor total del descuento

	
	return -oferta;						//retorna la oferta en valor negativo
										//puesto que es una rebaja sobre el
										//precio

}

////////////////////////////////////////////////////////////////////////
/// La opción de guardar la resrva: ello implica introduci un nombre, //
/// Añadir al registro y guardarlo en el disco                       ///
////////////////////////////////////////////////////////////////////////

void guardareserva(Registro &NuevoReg, Registro &reg, CListaTfnos &Trabajo)
{
		pantalla *lapantalla = new pantalla();
		lapantalla->limpiapantalla();
		lapantalla->bordesup();

		cout << "\t\t|   Desea guardar la reserva?                    |\n"
			 << "\t\t|                                                |\n"
			 << "\t\t|     (S/N)                                      |\n";
			 
		lapantalla->bordeinf();
		char v;
		cin >> v;
		
		if (v=='S')
		{
		// DECLARAMOS UNA VARIABLE TIPO CHAR LLAMADA BASURA, PARA LIMPIAR LA 
		//MEMORIA INTERMEDIA DEL BUFFER QUE SON LOS VALORES '\n' '\0'
		//MEDIANTE CIN.GETLINE CONSEGUIMOS LIBERAR ESA ZONA DE LA MEMORIA

		char basura[2];	
		cin.getline(basura, 2);
		
		cout <<"Por favor, escriba su nombre:\n";
		cin.get(NuevoReg.nombre,20,'\n');
		cin.getline(basura, 2);		
		
		cout << " Por favor, escriba su apellido:\n";
		cin.getline (NuevoReg.apellido,20,'\n');
	
		
		//Mediante esta opcion conseguimos añadir un registro a nuestro índice
		//////////////////////////////////////////////////////////////////////

		if ( !Trabajo.AsignarReg( NuevoReg ) )
          cout << "Imposible añadir: lista llena\n";
		
		
		//  Guardamos la informacion en el archivo Reservas.txt mediante la
		//  funcion guardardisco, definida mas adelante
		///////////////////////////////////////////////////////////////////
		
		
		guardardisco(Trabajo);
		
		cout<<"Pulse una tecla para visualizar el billete";
		cin.get();							//Nos visualiz el billete que
											//hemos resrvado

		
		visualbillete(NuevoReg);
		
		}
		
		else if(v=='N')
			cout<<"VOLVIENDO AL MENU PRINCIPAL";
	
		delete lapantalla;
}


//////////////////////////////////////////////////////////////////////////
// Funcion destino: daal usuario las opciones de destino posibles      ///
// y le permite decidir entre ellas, guardando en cada caso el nombre  ///
// y la distancia del destino                                          ///
//////////////////////////////////////////////////////////////////////////

void destino(Registro &NuevoReg, CListaTfnos &Trabajo)// Paso de parametro mediante referencia

{

pantalla *lapantalla = new pantalla();

char a='M';

while(true)
	{
		lapantalla->limpiapantalla();
		lapantalla->bordesup();

		cout << "\t\t|   Elija el destino:                            |\n"
		     << "\t\t|                                                |\n"
		     << "\t\t|    (1) Madrid.                                 |\n"
		     << "\t\t|    (2) Barcelona.                              |\n"
		     << "\t\t|    (3) Palencia.                               |\n";
		   	 
		lapantalla->bordeinf();
									  
		cin >> a;
		if ((a=='1')||(a=='2')||(a='3'))		//Copiamos la ciudad que se ha
												//elejido, y así asigna también
												//la distancia
												
		{
			if (a=='1')
			{	
				strcpy(NuevoReg.destino, "Madrid");
				NuevoReg.distancia=200;
				
			}

			else if (a=='2')
			{	
				strcpy(NuevoReg.destino, "Barcelona");
				NuevoReg.distancia=600;
			
			}

			else if (a=='3')
			{	
				strcpy(NuevoReg.destino, "Palencia");
				NuevoReg.distancia=50;	
			}
		break;
		}
	}	
delete lapantalla;
}


//////////////////////////////////////////////////////////////////////////
/// Visualiza los datos que hemos almacenado en el billete accediendo   //
/// a los datos miembro de la clase                                     //
//////////////////////////////////////////////////////////////////////////


void visualbillete(Registro &res)
{
	pantalla *lapantalla = new pantalla();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	lapantalla->bordesup();
	
	lapantalla->centrado();
	cout<<"Resevado a nombre de:" <<res.nombre<<" "<<res.apellido<<"\n";
	
	lapantalla->centrado();
	cout<<"Con destino a:" <<res.destino<<"\n";
	
	lapantalla->centrado();
	cout<< "Clase: " << res.clase<<"\n";
	
	lapantalla->centrado();
	cout<< "Destino: " << res.destino<<"\n";
	
	lapantalla->centrado();
	cout<< "Distancia a recorrer :" << res.distancia << "Km."<<"\n";

	lapantalla->centrado();
	cout<< "Dia de Salida: " << res.unafecha.leedia()<<"\n";
	cout<< " "; //<< res.unafecha.nombredia;
	
	lapantalla->centrado();
	cout<< "Mes de Salida: " << res.unafecha.leemes()<<"\n";
	
	lapantalla->centrado();
	cout<< "Tarifa a pagar: " << res.precio << " pts.\n\n";
	
	lapantalla->bordeinf();
	delete lapantalla;
}

/////////////////////////////////////////////////////////////
// Funcion ayuda: permite leer el archivo de ayuda        ///
/////////////////////////////////////////////////////////////

void ayuda() 
{
	pantalla *lapantalla = new pantalla();

	
	char ch;					// Declaracion de  variable tipo char
	
	
	ifstream ayuda("Ayuda.txt", ios::app);		// Apaertura del archivo 
						
while (ayuda.get(ch))							// Bucle para la lectura del archivo
{cout << ch;}
	
	
	ayuda.close();								// Cierre del archivo
	
	
	
	delete lapantalla;							// Liberacion de la memoria asociada al puntero 
}

////////////////////////////////////////////////////////////////////////////////
// Funcion inicializar: abre el archivo donde se guardan los billetes        ///
// y lo lee, guardandolo en memoria, también nos avisa de la necesidad de    ///
/// activar el bloqueo de mayúsculas para el buen funcionamiento del programa///
////////////////////////////////////////////////////////////////////////////////

void inicializar(CListaTfnos &Trabajo) // Paso de parametro mediante referencia
{
	
	pantalla *lapantalla = new pantalla();

	
	lapantalla->limpiapantalla();
	lapantalla->bordesup();

	// ADVERTENCIA PARA EL BUEN FUNCIONAMIENTO DEL PROGRAMA
	cout << "\t\t|     !!!ACTIVE EL BLOQUEO DE MAYUSCULAS!!!      |\n"
		 << "\t\t|                                                |\n" 
		 << "\t\t|    Pulse una INTRO o RETURN para continuar     |\n";

	
	lapantalla->bordeinf();

	
	cin.get();							// Espera
	
	fstream archivo;


	/////////////////////////
	// Apertura del archivo
	
	archivo.open("reservas.txt", ios::in | ios::out);
	archivo.seekg(0, ios::beg);		
	
	////////////////////////
	// Lecturo del archivo

	archivo.read((char*) &Trabajo, sizeof CListaTfnos);	
	
	
	archivo.close();		// Cierre del archivo
	
	delete lapantalla;
}

////////////////////////////////////////////////////////////////
// Funcion guardardisco: guarda las reservas en el archivo   ///
////////////////////////////////////////////////////////////////

void guardardisco(CListaTfnos &Trabajo) // Paso de parametro mediante referencia
{
	
  	pantalla *lapantalla = new pantalla();

	// llamada a las funciones de la clase pantalla
	
	lapantalla->bordesup();

	// Salida por pantalla
	cout << "\t\t|       GUARDANDO RESERVA.......                 |\n";
	
	lapantalla->bordeinf();
	


	fstream archivo;

	////////////////////////
	// Apertura del archivo
	
	archivo.open("reservas.txt", ios::in | ios::out);
	archivo.seekg(0, ios::beg);
	
	archivo.write((char*) &Trabajo, sizeof CListaTfnos);	
	archivo.close();
	
	delete lapantalla;
}

///////////////////////////////////////////////////////////////////
/// Menu buscar: en el motramos una serie de opciones de búsqueda//
///////////////////////////////////////////////////////////////////


void menubuscar(CListaTfnos &Trabajo, Registro & Xreg)
{
	Registro reg;
	pantalla *lapantalla = new pantalla();
	
	  char a='D';
	
while ((a=='D')||(a=='C')||(a == 'S')||(a == 'M'))
	{ 
		lapantalla->bordesup();

		cout << "\t\t|    ELIJA EL TIPO DE BUSQUEDA                   |\n"
			 << "\t\t|     (1) Buscar por nombre                      |\n"
			 << "\t\t|     (2) Buscar por apellido                    |\n"
			 << "\t\t|     (3) Listado de clientes                    |\n"
			 << "\t\t|     (4) Listado por destinos                   |\n";

		lapantalla->bordeinf();

		cin >> a;
		char vaciabuffer[2];
		

		if ((a=='1')||(a=='2')||(a=='3')||(a=='4'))
		{
			if (a=='1')
			{	
				cout << "Introduzca el Nombre: ";
				cin.getline(vaciabuffer, 2, '\n');
				cin.getline ( reg.nombre, 20, '\n' );
        if ( (Trabajo.Buscar( &reg )) )
          visualbillete(reg);
	
        else
          cout << "No se encuentra\n";	
			}

			else if (a=='2')
			{
				Trabajo.listado();
				cin.getline ( vaciabuffer,2, '\n' );
				cout << " Introduzca el Apellido: ";
				
				cin.getline ( reg.apellido, 20 , '\n' );
				
					if ( (Trabajo.Buscar1( &reg )) )
					visualbillete(reg);
					else
					cout << "No se encuentra\n";
			}

			else if (a=='3')
			{	
				Trabajo.listado();
					
			}

			else if (a=='4')
			{	
			cout<<"**** REVISAR LA LISTA DE DESTINOS *****";
			
			}

		

		break;
		}
		
	
	}
delete lapantalla;
}


/*void eliminar(CListaTfnos &trabajo)
{


				
				cin.getline ( vaciabuffer,2, '\n' );
				cout << " Introduzca el Apellido de la reserva a eliminar: ";
				
				cin.getline ( reg.apellido, 20 , '\n' );
				
					if ( (Trabajo.Buscar1( &reg )) )
					visualbillete(reg);
					cout<<"?Seguro que desea eliminarla?";

char a='D';
	
while ((a=='S')||(a=='N'))
	{ 
		lapantalla->bordesup();

		cout << "\t\t|    ?Seguro que desea eliminarla?               |\n"
			 << "\t\t|                                                |\n";
			 		lapantalla->bordeinf();

		cin >> a;
		char vaciabuffer[2];
		

		if ((a=='S')||(a=='N'))
		{
			if (a=='1')
			{	
				
			}

			else if (a=='2')
			{break;}
		
	
	}
				


}*/