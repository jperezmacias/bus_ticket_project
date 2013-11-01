// PROG0406.CPP - Clases amigas
#include "cpp1.cpp"
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
//#include "billete.h" // incluye la clase CListaTfnos
//#include "caccestf.h" // incluye la clase CAccesoTfnos
#include "pantalla.h"
#include "fecha.h"

// Prototipos de funciones

int eliminar(Registro &NuevoReg, CListaTfnos &);
void menuprincipal(Registro &, fecha &, Registro &, CListaTfnos &);
void menu( int & );
void ayuda();
void guardareserva(Registro &NuevoReg, fecha &, Registro &, CListaTfnos &);
void menureservas(Registro &NuevoReg, fecha &lafecha, Registro &, CListaTfnos &);
int aumento(int, int);
int descuento(int, int, Registro &NuevoReg);
int nuevareserva(Registro &NuevoReg, fecha &lafecha, CListaTfnos &, Registro &);
int precio(int, Registro &NuevoReg);		   
void cuando(Registro &NuevoReg,fecha &lafecha);
void destino(Registro &NuevoReg, CListaTfnos &);
void guardardisco(CListaTfnos &Trabajo);
int visualizar( CListaTfnos &, fecha &, Registro & );
void menubuscar();
void inicializar(CListaTfnos &);
void visualbillete(Registro &, fecha &);


int main()
{

CListaTfnos Trabajo;
Registro NuevoReg, reg;
fecha lafecha(0,0);

//inicializar(Trabajo);
//visualbillete(NuevoReg, lafecha);
menuprincipal(NuevoReg, lafecha, reg, Trabajo);

return 0;

}

void menuprincipal(Registro &NuevoReg, fecha &lafecha, Registro &reg, CListaTfnos &Trabajo)
{
	int opcion;

do
  {
    menu( opcion );
    system( "cls" );
    switch ( opcion )
    {
      case 1:
       menureservas(NuevoReg, lafecha, reg, Trabajo);
        break;
      case 2:
		  ayuda();        
        break;
      //case 3:
      ///  visualizar( Trabajo );
      //  break;
      case 3:
        break;
    }
    cout << "\nPulse Entrar para continuar ";
    cin.get();
  }
  while ( 1 );
}

void menu( int &op )
{
  system( "cls" );
  cout	<< "\t\t|   Pulse la opción deseada                      |\n"
		<< "\t\t|                                                |\n"
		<< "\t\t|      (1) Reservas.                             |\n"
		<< "\t\t|      (2) Ayuda.                                |\n"
		<< "\t\t|      (3) Salir del programa.                   |\n";

 
  cin >> op; cin.ignore();
}




// Visualizar lista de teléfonos
int visualizar( CListaTfnos &lista, fecha &lafecha, Registro &Nuevoreg )
{
  //Registro registro;
  CAccesoTfnos Ver( lista );
  Registro registro;
  int vr;
  visualbillete(registro, lafecha);

  cout << "Pulse 'P' para ver primero, 'U' último\n"
       << "      'A' anterior,         'S' siguiente\n"
       << "Otro carácter para finalizar\n\n";
  char car = cin.get(); cin.ignore();
  while ( car == 'p' || car == 'u' || car == 'a' || car == 's' )
  {
    if ( car == 'P' )
      vr = Ver.Primero( &registro );
    else if ( car == 'U' )
      vr = Ver.Ultimo( &registro );
    else if ( car == 'S' )
      vr = Ver.Siguiente( &registro );
    else if ( car == 'A' )
      vr = Ver.Anterior( &registro );
    else
      return 0;
    if ( vr )
     cout<<"Visualizando Billete";
		visualbillete(registro, lafecha);
	//	cout << registro.nombre << ", " << registro.tfno << endl;
    car = cin.get(); cin.ignore();
  }
  return 0;
}
void menubuscar(CListaTfnos &Trabajo, Registro & Xreg)
{
	Registro reg;
	pantalla *lapantalla = new pantalla();
	//int pclase=0, pdia=0, pmes=0; 
	//char* pdestino, 
	  char a='D';
	
while ((a=='D')||(a=='C')||(a == 'S')||(a == 'M'))
	{ 
		lapantalla->bordesup();

		cout << "\t\t|    ELIJA EL TIPO DE BUSQUEDA                   |\n"
			 << "\t\t|     (D) Buscar por nombre                      |\n"
			 << "\t\t|     (C) Buscar por apellido                    |\n"
			 << "\t\t|     (S) Buscar por destinos                    |\n"
			 << "\t\t|     (M)                                        |\n";

		lapantalla->bordeinf();

		cin >> a;

		//lapantalla->limpiapantalla();

		if ((a=='D')||(a=='C')||(a=='S')||(a=='M'))
		{
			if (a=='D')
			{	
				Trabajo.listado();
				cout << " Escriba el Nombre: ";
				char nombre[20];
				cin>>nombre;
				strcpy(reg.nombre, nombre);
				//cin.getline ( reg.nombre, 20, '\n' );cin.ignore();
				
        if ( (Trabajo.Buscar( &reg )) )
          cout << reg.nombre<<reg.destino;//<< ", " << reg.destino << endl;
        else
          cout << "No se encuentra\n";
			}

			else if (a=='C')
			{
			cout << " Escriba el Apellido: ";
				char apellido[20];
				cin>>apellido;
				cout<<apellido;
				strcpy(reg.apellido, apellido);
				
							

        if ( (Trabajo.Buscar1( &reg )) )
		{          cout << " Escriba el Nombre: ";
				char nombre[20];
				cin>>nombre;
				cout<<nombre;
				strcpy(reg.nombre, nombre);
				cout << reg.nombre << ", " << reg.tfno << endl;
        }
		else
          cout << "No se encuentra\n";	
			}

			else if (a=='S')
			{	
				cout << " Escriba el Nombre: ";
        cin.getline ( reg.nombre, 20, '\n' );
        if ( (Trabajo.Buscar( &reg )) )
          cout << reg.nombre << ", " << reg.tfno << endl;
        else
          cout << "No se encuentra\n";	
			}

			else if (a=='M')
			{	
				cout << " Escriba el Nombre: ";
        cin.getline ( reg.nombre, 20, '\n' );
        if ( (Trabajo.Buscar( &reg )) )
          cout << reg.nombre << ", " << reg.tfno << endl;
        else
          cout << "No se encuentra\n";	
			}

		//lapantalla->limpiapantalla();

		break;
		}
		
		//lapantalla->limpiapantalla();
	}
delete lapantalla;
}






void destino(Registro &NuevoReg, CListaTfnos &Trabajo)
{

	
pantalla *lapantalla = new pantalla();

char a='M';

while(true)
	{
		lapantalla->limpiapantalla();
		lapantalla->bordesup();

		cout << "\t\t|   Elija el destino:                            |\n"
		     << "\t\t|                                                |\n"
		     << "\t\t|    (M) Madrid.                                 |\n"
		     << "\t\t|    (B) Barcelona.                              |\n"
		     << "\t\t|    (P) Palencia.                               |\n";
		   	 
		lapantalla->bordeinf();
									  
		cin >> a;
		
		if ((a=='M')||(a=='B')||(a='P'))
		{
			if (a=='M')
			{	
				strcpy(NuevoReg.destino, "Madrid");
				NuevoReg.distancia=200;
				
			}

			else if (a=='B')
			{	
				strcpy(NuevoReg.destino, "Barcelona");
				NuevoReg.distancia=600;
			
			}

			else if (a=='P')
			{	
				strcpy(NuevoReg.destino, "Palencia");
				NuevoReg.distancia=50;	
			}
		break;
		}
	}	
delete lapantalla;
}


int nuevareserva(Registro &NuevoReg, fecha &lafecha, CListaTfnos &Trabajo, Registro &reg)
{ 	
	int distancia, coste, diasemana, coste_total, oferta, recargo;
	
	destino(NuevoReg, Trabajo);
			
	distancia = NuevoReg.leedistancia();
	
	coste = precio(distancia, NuevoReg);
	
	cuando(NuevoReg, lafecha);
			
	diasemana = lafecha.leediasemana();
	
	recargo = aumento(diasemana, coste);
	
	oferta = descuento(coste, distancia, NuevoReg);
	
	coste_total = coste + oferta + recargo;

	if (NuevoReg.leevuelta()==true)
		coste_total = coste_total * 2;
	
	NuevoReg.precio=coste_total;
	
	
	//visualizar(Trabajo);
	guardareserva(NuevoReg, lafecha, reg, Trabajo);



	return 0;
}

void cuando(Registro &NuevoReg, fecha &lafecha)
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
	lafecha.escribedia(dia_s);
	lafecha.escribemes(mes_s);
	
	//NuevoReg.diadia_s);
	//mes_s);

	lapantalla->limpiapantalla();
	lapantalla->bordesup();

	cout << "\t\t|   Quiere billete de vuelta?                    |\n"
		 << "\t\t|                                                |\n"
	     << "\t\t|     (S/N)                                      |\n";
		 
	lapantalla->bordeinf();
	
	cin >> a;

	if (a=='S')
	{
		NuevoReg.vuelta=true;	 		

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
				
		lafecha.calculodia();
	}	
	delete lapantalla;
}
		   
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
			 << "\t\t|    (P) Primera Clase.                          |\n"
			 << "\t\t|    (T) Clase Turista.                          |\n";
			 
		lapantalla->bordeinf();

		cin >> b;
	
		if ((b=='P')||(b=='T'))
		{	
			if (b=='P')
			{	coste = distancia *15;
				clase = 1;	}	   	
			else if (b=='T')
			{	coste = distancia *8;
				clase =2;	}
		break;
		}
	}

	NuevoReg.clase=clase;
	delete lapantalla;
	return coste;
}	
	
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

int descuento(int coste, int distancia, Registro &elbillete)
{
	int oferta, oferta1, oferta2, a = (distancia / 100);
	 
	if (a>=1)
		oferta1 = coste * 2 * a / 100;
	else 
		oferta1 = 0;
								  		
	if (elbillete.leevuelta()==true)
		oferta2 = coste * 15 / 100;
	else 
		oferta2 = 0;
		oferta = oferta1 + oferta2;
	
	return -oferta;
}

void menureservas(Registro &NuevoReg, fecha &lafecha, Registro & reg, CListaTfnos &Trabajo)
{
	pantalla *lapantalla = new pantalla();
	char a='N';

while ((a=='N')||(a=='E')||(a=='M')||(a=='R')||(a=='B')||/*(a=='C')||*/(a=='V'))
	{	
		lapantalla->bordesup();

		cout << "\t\t|   Elija una opcion del menu:                   |\n"
			 << "\t\t|                                                |\n"
			 << "\t\t|     (N) Nueva reserva.                         |\n"
			 <<	"\t\t|     (E) Eliminar reserva.                      |\n" 
			 <<	"\t\t|     (M) Modificar reserva.                     |\n" 
			 <<	"\t\t|     (R) Reservas hechas hasta el momento       |\n" 
//			 <<	"\t\t|     (P) Personas que han hecho reservas.       |\n"
  			 << "\t\t|     (B) Buscar.                                |\n"
			 << "\t\t|     (V) Volver al menu principal.              |\n";
			 
		lapantalla->bordeinf();
		
		cin >> a;
	
		if (a=='N')
			nuevareserva(NuevoReg, lafecha, Trabajo, reg);
		else if (a=='E')
			eliminar(NuevoReg, Trabajo);
		else if (a=='M')
			//modificar(NuevoReg, lafecha);
			cout<<"**";
			else if (a=='R')
			visualizar(Trabajo, lafecha, NuevoReg);
			else if (a=='B')
			menubuscar(Trabajo, reg);
			
		else if (a=='V')
			break;
	}
delete lapantalla;			
}


void ayuda()
{
	pantalla *lapantalla = new pantalla();
	char ch;
	ifstream ayuda("Ayuda.txt", ios::app);
													
	while (ayuda.get(ch))
		cout << ch;
	ayuda.close();

	lapantalla->espera();
	lapantalla->limpiapantalla();
	delete lapantalla;
}


int eliminar(Registro &NuevoReg, CListaTfnos &Trabajo)
{
	pantalla *lapantalla = new pantalla();
	int z=0, i=1; 

	lapantalla->limpiapantalla();
	lapantalla->bordesup();

	//cout << "\t\t|   Introduce el numero de la reserva a eliminar.|\n";

	lapantalla->bordeinf();
	
	cin >> z;
	fstream archivo;
	archivo.open("reservas.txt", ios::in | ios::out);
	archivo.seekg(0, ios::beg);		
	archivo.write((char*) &Trabajo/*[i]*/, sizeof CListaTfnos);	
	archivo.close();
	lapantalla->limpiapantalla();
	delete lapantalla;

	return 0;
}

void inicializar(CListaTfnos &Trabajo)
{
	cout<<"!!!ACTIVE EL BLOQUEO DE MAYUSCULAS!!!\n";
	cout<<"Pulse una tecla para continuar";
	cin.get();
	fstream archivo;
	archivo.open("reservas.txt", ios::in | ios::out);
	archivo.seekg(0, ios::beg);		
	archivo.read((char*) &Trabajo, sizeof CListaTfnos);	
	archivo.close();
}

void guardardisco(CListaTfnos &Trabajo)
{
  
	pantalla *lapantalla = new pantalla();


	lapantalla->bordesup();
cout<<"GUARDANDO RESERVA.......\n";
	//cout << "\t\t|   Introduce el numero de la reserva a eliminar.|\n";

	lapantalla->bordeinf();
	
	
	fstream archivo;
	archivo.open("reservas.txt", ios::in | ios::out);
	archivo.seekg(0, ios::beg);		
	archivo.write((char*) &Trabajo, sizeof CListaTfnos);	
	archivo.close();
	lapantalla->limpiapantalla();
	delete lapantalla;

	
}
void guardareserva(Registro &NuevoReg, fecha &lafecha, Registro &reg, CListaTfnos &Trabajo)
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
		
		char nombre[20], apellido[20];	
		cout << " Por favor, escriba su nombre:\n ";
			
		cin>>nombre;
        strcpy (NuevoReg.nombre, nombre);
			
		cout << " Por favor, escriba su  primer apellido:\n";
		cin>>apellido;
        strcpy (NuevoReg.apellido, apellido);
		Trabajo.AsignarReg(NuevoReg);
		visualbillete(NuevoReg, lafecha);
		 
		//guardardisco(Trabajo);
		}			
		else if(v=='N')
			menuprincipal(NuevoReg, lafecha, reg, Trabajo);
		
	
		delete lapantalla;
}	

void visualbillete(Registro &res, fecha &lafecha)
{
	cout
	<<"Resevado a nombre de:" <<res.nombre<<" "<<res.apellido
	<<"\nCon destino a:" <<res.destino
	<< "\nClase: " << res.clase
	<< "\nDestino: " << res.destino
	<< "\nDistancia a recorrer :" << res.distancia << "Km."
	<< "\nDia de Salida: " << lafecha.leedia()
	<< " " //<< res.unafecha.nombredia
	<< "\nMes de Salida: " << lafecha.leemes()
	<< "\nTarifa a pagar: " << res.precio << " pts.\n\n";

}	

