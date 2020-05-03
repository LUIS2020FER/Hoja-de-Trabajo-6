/ *
EJERCICIO # 1
En una libreria se encuentran 4 modelos diferentes de cuadernos, con los siguientes precios:
„H Modelo # 1 ¡V Q10.00
„H Modelo # 2 ¡V Q15.00
„H Modelo # 3 ¡V Q18.50
„H Modelo # 4 ¡V Q25.00
Por otra parte, tiene información sobre las ventas realizadas durante los últimos 30 días, estos
movimientos se deben de guardar en un archivo de la siguiente forma:
DIA1, MOD, CANT
DIA2, MOD, CANT
.
.
.
DIA30, MODELO, CANTIDAD
DIAi = Variable que representa el día que se efectúa la venta i (1 - 30)
MOD = Variable que representa el codigo de Modelo que se vendio. (1 ¡V 4)
CANT = Variable que representa la cantidad de unidades vendidas.
El programa debe ser capaz de:
„H Modificar el número de unidades vendidas, solicitando al usuario el día y el codigo de articulo
(modificación del archivo)
„H Eliminación de un día específico de venta (modificación del archivo)
„H Calcular el total recaudado por modelo en los 30 dias.
„H Calcular cual fue el modelo que se vendio mas en los 30 dias
* /
# include  < iostream >
# include  < string >
# include  < fstream >
# include  < regex >
# include  < iomanip >
# include  < vector >
# include  < algoritmo >

usando el  espacio de nombres  estándar ;

struct  cuadernos {
  descripcion de cuerdas;
  precio de flotación ;
  int cantidad;
} cuaderno [ 4 ];

struct  lectura {
  int dia;
  int modelo;
  int cantidad;
};

vector <lectura> registro;


nulo  pausar_pantalla () {
      // Pausa
    sistema ( " pausa " );
    cout << " \ n Presione cualquier tecla para continuar \ n " ;
}


void  iniciar_variables () {
  // lista de Cuadernos
  cuaderno [ 0 ] = { " Modelo # 1 " , 10 , 0 };
  cuaderno [ 1 ] = { " Modelo # 2 " , 15 , 0 };
  cuaderno [ 2 ] = { " Modelo # 3 " , 18.50 , 0 };
  cuaderno [ 3 ] = { " Modelo # 4 " , 25 , 0 };
  // Limpio el vector de registro
  registro. claro ();
};

anular  ingresar () {
  int dia, modelo, cantidad;
  control de bool = falso ;
  
  while (control == falso ) {
  cout << " Ingrese el dia de la venta: " ;
  cin >> dia;
    // comprometimos si el dia esta en los parametros 1 al 31
    if (dia> = 1  y dia <= 31 ) {
      control = verdadero ;
    } más {
      control = falso ;
    }
  }
  control = falso ;
  
  while (control == falso ) {
    cout << " Ingrese el modelo del cuaderno: " ;
    cin >> modelo;
    modelo = modelo- 1 ;
    
    // comparamos el modelo si este en el rango de la lista
    if (modelo> = 0  y modelo <= 3 ) {
      control = verdadero ;
    } más {
      cout << " El modelo ingresado no es valido, intente de nuevo " << endl;
      control = falso ;
    }
  }
  
    cout << " Ingrese la cantidad de ventas del cuaderno: " ;
    cin >> cantidad;
    
  ofstream archivo;
  prueba {
    archivo. abierto ( " archivo.txt " , ios :: aplicación);

    archivo << dia << " , " << modelo + 1 << " , " << cantidad << endl;

    archivo. cerrar ();
  } captura (excepción X) {
		cout << " Error en la manipulación del archivo " << endl;
		
    // Esto es una pausa para ingresar enter
    cout << " Presione enter para continuar .... " << endl;
  
    pausar_pantalla ();
    sistema ( " cls " );
	};
}

vacío  leer_archivo_a_memoria () {
  lectura x;
  ifstream archivo; // Creamos el objeto
  entrada de cadena;
  prueba {
    archivo. abierto ( " archivo.txt " , ios :: in);

    while (! archivo. eof ()) {
      getline (archivo, input, ' , ' ); // Obtengo el primer string
			X. dia = atoi (input. c_str ()); // Lo convierto en integer
      getline (archivo, input, ' , ' );
			X. modelo = atoi (input. c_str ());
      getline (archivo, input, ' \ n ' );
			X. cantidad = atoi (input. c_str ());
      
      // Lo almacenamos en un vector;
      if (x. dia ! = 0  y x. modelo ! = 0  y x. cantidad ! = 0 ) {
        registro. push_back (x);
      }
      
    }
    
    // cierro el archivo.
    archivo. cerrar ();
  }
  captura (excepción X) {
    cout << " Error en la manipulación del archivo " << endl;
    pausar_pantalla ();
    sistema ( " cls " );
  }
};

void  mostrar () {
  sistema ( " cls " );
  registro. claro ();
  leer_archivo_a_memoria ();
  cout << " Día " << " \ t " << " Modelo " << " \ t " << " Cantidad " << endl;
  cout << " ------------------------------ " << endl;
  for ( int i = 0 ; i <registro. size (); i ++) {
    cout << registro [i]. dia   << setw ( 8 ) << registro [i]. modelo << setw ( 10 ) << registro [i]. cantidad << " \ n " ;
  }
  cin. ignorar ();
  pausar_pantalla ();


};



vacío  memoria_a_archivo () {
  ofstream archivo;
  archivo. abierto ( " archivo.txt " , ios :: out);

  // pasamos de la memoria al archivo.
  for ( int i = 0 ; i <registro. size (); i ++) {
    // Si es distinto de 0 en el archivo no lo graba
    if (registro [i]. dia ! = 0  y registro [i]. modelo ! = 0  y registro [i]. cantidad ! = 0 ) {
      archivo << registro [i]. dia << " , " << registro [i]. modelo << " , " << registro [i]. cantidad << " \ n " ;
    }
    
  }

  // Cerrramos el archivo.
  archivo. cerrar ();
}

 calculo vacío () {
  registro. claro ();
  int modelo1, modelo2, modelo3, modelo0;
  flotante total1, total2, total3, total0;
  leer_archivo_a_memoria ();
  
  int modelo;
  
  // Contamos cuantos modelos se vendieron en total
  for ( int i = 0 ; i <registro. size (); i ++) {
    modelo = registro [i]. modelo - 1 ;
    cuaderno [modelo]. cantidad + = registro [i]. cantidad ;
  }

  flotante total = 0 ;
  para ( int i = 0 ; i < 4 ; i ++) {
    total = ((cuaderno [i]. precio * cuaderno [i]. cantidad ));
    cout << " Total recaudado por " << cuaderno [i]. descripcion << " es de: Q. " << total << " \ n " ;
  }

  int mayor;
  if (cuaderno [ 0 ]. cantidad > cuaderno [ 1 ]. cantidad  y cuaderno [ 0 ]. cantidad > cuaderno [ 2 ]. cantidad  y cuaderno [ 0 ]. cantidad > cuaderno [ 3 ]. cantidad ) {
    mayor = 0 ;
  } más  si  
    (cuaderno [ 1 ]. cantidad > cuaderno [ 2 ]. cantidad  y cuaderno [ 1 ]. cantidad > cuaderno [ 3 ]. cantidad  y cuaderno [ 1 ]. cantidad > cuaderno [ 0 ]. cantidad ) {
    mayor = 1 ;
  }
    si no si  
    (cuaderno [ 2 ]. cantidad > cuaderno [ 3 ]. cantidad  y cuaderno [ 2 ]. cantidad > cuaderno [ 0 ]. cantidad  y cuaderno [ 2 ]. cantidad > cuaderno [ 1 ]. cantidad ) {
    mayor = 2 ;
  } más {
    mayor = 3 ;
  }

  cout << " El modelo mas vendidco es: " << cuaderno [mayor]. descripcion << " \ n " ;
      cout << " Con la cantidad de: " << cuaderno [mayor]. cantidad << " Unidades vendidas " << " \ n " ;

}

void  modificar () {
  mostrar ();
  int dia, modelo, cantidad;
  cout << " Ingrese el dia: " ;
  cin >> dia;
  cout << " Ingrese modelo: " ;
  cin >> modelo;
  cout << " Ingrese la nueva cantidad: " ;
  cin >> cantidad;
  
  posición int = 0 ;
  bool encontrado = falso ;
  
  for ( int i = 0 ; i <registro. size (); i ++) {
    if (registro [i]. dia == dia y registro [i]. modelo == modelo) {
      posición = i;
      encontrado = verdadero ;
    } más {
      encontrado = falso ;
    }

  }
  
  if (encontrado) {
    registro [posición]. cantidad = cantidad; // Eliminamos el
  } más {
    cout << " Ingreso un dato incorrecto " << endl;
    pausar_pantalla ();
  }
  // registro de la memoria.
  memoria_a_archivo ();
  mostrar ();
  volver ;
};

void  eliminar () {
  mostrar ();
  int dia, modelo;
  cout << " Ingrese el dia: " ;
  cin >> dia;
  cout << " Ingrese modelo: " ;
  cin >> modelo;
  bool encontrado = falso ;
  posición int = 0 ;
  
  for ( int i = 0 ; i <registro. size (); i ++) {
    if (registro [i]. dia == dia y registro [i]. modelo == modelo) {
      posición = i;
      encontrado = verdadero ;
    } más {
      encontrado = falso ;
    }

  }
  
  if (encontrado) {
    registro. borrar (registro. begin () + position); // Eliminamos el
  } más {
    cout << " Ingreso un dato incorrecto " << endl;
    pausar_pantalla ();
  }
  // registro de la memoria.
  memoria_a_archivo ();
  mostrar ();
  volver ;
};

nulo  mp () {
	int selec;
	hacer {
    // limpiamos pantalla
    sistema ( " cls " );
		cout << " -------------------------- " << " \ n " ;
		cout << " Menú principal " << " \ n " ;
		cout << " ------------------- " << " \ n " ;
		cout << " 1 - Ingresar registro " << " \ n " ;
		cout << " 2 - Reporte " << " \ n " ;
    	cout << " 3 - Modificar " << " \ n " ;
		cout << " 4 - Eliminar " << " \ n " ;
  		cout << " 5 - Salir " << " \ n " ;
		cout << " -------------------------- " << " \ n " ;
		cout << " Seleccione su opción: " ;
		cin >> selec;
		if (selec == 1 ) {		
			  // limpiamos pantalla
      		sistema ( " cls " );
			ingresar ();			
		}
		otra cosa  si (Selec == 2 ) {
			mostrar ();
      		calculo ();
      		pausar_pantalla ();
		}
    	más  si (Selec == 3 ) {		
  		 	modificar ();
		}
    	más  si (Selec == 4 ) {		
      		eliminar ();
		}
		otra cosa  si (Selec == 5 )
			romper ;
		más 
			romper ;
		
	} while (selec! = 5 );	
};


int  main () {
  iniciar_variables ();
  pf ();
  devuelve  0 ;
};
