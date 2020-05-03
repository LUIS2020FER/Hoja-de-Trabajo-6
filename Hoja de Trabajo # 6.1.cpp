/ *
Realice un programa que, dado el peso, la altura, la edad y el género (M / F) de un grupo de N personas
que pertenecen a un departamento de la república, obtienen un promedio de peso, altura y edad de esta
población Los datos deben guardarse de forma ordenada por edad en un archivo de datos. Así mismo
el programa debe ser capaz de leer los datos del archivo y generar un informe con la media del peso, altura
y la edad.
* /
# include  < iostream >
# include  < string >
# include  < fstream >
# include  < regex >
# include  < iomanip >  
# include  < vector >

usando el  espacio de nombres  estándar ;

struct  personas {
  peso flotante ;
  altura del flotador ;
  int edad;
  cadena de genero;
};


nulo  pausar_pantalla () {
      // Pausa
    cadena vacía;
    cout << " \ n Presione cualquier tecla para continuar \ n " ;
    getline (cin, vacío);
};

anular  ordenar () {
  // Declaramos la estructura en una variable
  personas temp;

  // Creamos un vector para el almacenamiento del archivo
  vector <personas> registros;


    // Ordenamiento
  // Declaración del objeto para lectura de archivo
  ifstream db_read;
  db_read. abierto ( " control.txt " , ios :: in);
	
  while (db_read >> temp. peso >> temp. altura >> temp. edad >> temp. genero ) {
    // Agregamos al vector el contenido del archivo.
    registros. push_back (temp);
  };
  // cerramos archivo.
  db_read. cerrar ();
  // Hacemos el ordenamiento del contenido del archivo y el ingreso.
    
  // Ordenamiento de BUBBLESORT por edad
  for ( int i = 0 ; i <registros. size (); i ++) {
   for ( int j = i + 1 ; j <registros. size (); j ++)
   {
      // Comparamos la edad
      if (registros [j]. edad <registros [i]. edad ) {
         temp = registros [i];
         registros [i] = registros [j];
         registros [j] = temp;
      }
   }
  } 


    // remplazamos el archivo.
    ofstream db;
    db. abierto ( " control.txt " , ios :: out);
    
    for ( int i = 0 ; i <registros. size (); i ++) {
      db << registros [i]. peso << " \ t " << registros [i]. altura << " \ t " << registros [i]. edad << " \ t " << registros [i]. genero << endl;
    }
    db. cerrar ();
}

void  insert_data_db () {
	// declaracion de variables
  cadena de genero;
  // Declaramos la estructura de personas a la variable xy temp
	personas x;

  // Declaración del objeto para escribir en archivo
  ofstream db;
  

  // Ingreso de datos
	cout << " *** Control de peso, la altura, la edad y el género *** \ n *** En las Personas del departamento de Guatemala *** \ n " ;
	
  cout << " Indique peso de la persona:          " << endl;
 	cin >> x. pesos ;
	cin. claro ();
  
  cout << " Indique altura de la persona:          " << endl;
	cin >> x. altura ;
  cin. claro ();
	
  cout << " Indique edad de la persona:          " << endl;
	cin >> x. Edad ;
  // cin.clear ();
	cin. ignorar ();
  
  // Hacemos la validación del ingreso de la información de genero.
  bool validacion = falso ;
  while (validacion == false ) {
    cout << " Indique genero de la persona (m = Masculino, f = Feminino): " << endl;
    getline (cin, genero);    // obtenemos la variable

    // Realizamos la comparación
    if ((genero == " M " ) o (genero == " m " )) {
      X. genero = " M " ;
      validacion = verdadero ;
    } else  if ((genero == " F " ) o (genero == " f " )) {
      X. genero = " F " ;
      validacion = verdadero ;
    } más {
      cout << " Indico una opción invalida !!! \ n Vuelva a intentarlo .... \ n " ;
    }
  }   // Termina el While
  cin. claro ();

	// Inserción de datos a un archivo
	prueba {
		// Abrimos el archivo para insertar nuevo registro, o generamos un nuevo archivo
    db. abierto ( " control.txt " , ios :: aplicación);
    // Grabamos la linea del archivo.  
   
    // Graba registro de x
    db << x. peso << " \ t " << x. altura << " \ t " << x. edad << " \ t " << x. genero << endl;
		
    // Cerramos el archivo
    db. cerrar ();
	}

	captura (excepción X) {
		cout << " Error en la manipulación del archivo " << endl;
		
    // Esto es una pausa para ingresar enter
    cout << " Presione enter para continuar .... " << endl;
    

    pausar_pantalla ();
    sistema ( " cls " );
	}
  
  // Ordenamos al ingresar un nuevo registro en el archivo
  ordenar ();
}

void  leer_data_db () {
  // declaracion de variables y objetos
  personas x;

  int i = 0 ;
  float prom_peso, prom_altura, prom_edad;
	ifstream db;	
	
  prueba {
		db. abierto ( " control.txt " , ios :: in);	
    
    sistema ( " cls " );
		cout << " Datos del archivo: " << endl;
		cout << " Peso | " << "       Altura | " << "   Edad | " << "   Genero | " << endl;		
		while (db >> x. peso >> x. altura >> x. edad >> x. genero ) {
			cout << setw ( 5 ) << x. peso << " | " << setw ( 10 ) << x. altura << setw ( 9 ) << " | " << setw ( 3 ) << x. edad << setw ( 4 ) << " | " << setw ( 4 ) << x. genero << setw ( 5 ) << " El | " << endl;
      // Contamos las líneas de registro
      i ++;					
      
      // sumamos todos los campos para su promedio
			prom_edad + = x. Edad ;
      prom_altura + = x. altura ;
      prom_peso + = x. pesos ;
		}	
		db. cerrar ();	
    
    // Sacamos todos lo promedios
    prom_edad = prom_edad / i;
    prom_altura = prom_altura / i;
    prom_peso = prom_peso / i;
		
		cout << " Promedio de Peso: " << prom_peso << endl;
		cout << " Promedio de Altura: " << prom_altura << endl;
    cout << " Promedio de Edad: " << prom_edad << endl;
    cin. ignorar ();
    pausar_pantalla ();
	}
	captura (excepción y X) {
		cout << " Error en la manipulación del archivo " << endl;
		cout << " Error: " << X. what () << endl;
		pausar_pantalla ();
	}
};

nulo  mp () {
	int resp;
	hacer {
    // limpiamos pantalla
    sistema ( " cls " );
		cout << " -------------------------- " << " \ n " ;
		cout << " Menú principal " << " \ n " ;
		cout << " ------------------- " << " \ n " ;
		cout << " 1 - Ingresar registro " << " \ n " ;
		cout << " 2 - Reporte " << " \ n " ;
		cout << " 3 - Salir " << " \ n " ;
		cout << " -------------------------- " << " \ n " ;
		cout << " Seleccione su opción: " ;
		cin >> resp;
		si (resp == 1 ) {		
			  // limpiamos pantalla
 		  	  sistema ( " cls " );
			insert_data_db ();			
		}
		más  si (resp == 2 ) {		
      leer_data_db ();
		}
		más  si (resp == 3 )
			romper ;
		más 
			romper ;
		
	} while (resp! = 3 );	
}



int  main () {
  pf ();

devuelve  0 ;
};
