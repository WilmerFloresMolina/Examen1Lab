#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h> 

using std::cin;
using std::cout;
using std::endl;

void matriz (char** m);
void liberar_Memoria(char** m);
void llenado (char** m);
void Imprimir (char** m);
void jugador1 (char** m ,int x ,int y , int a , int b);
void jugador2 (char** m ,int x ,int y , int a , int b);

bool jugando = true;
int jugador =1;

int main(int argc, char const *argv[]){
	 char** m = new char*[7];//lol
     int a=0,b=0,c=0,d=0;
	 matriz (m);
	 llenado(m);
	 
	 while(jugando){

	 if ((a>=0 &&a<=6)&&(b>=0 &&b<=6)&&(c>=0 &&c<=6)&&(d>=0 &&d<=6)){
	 	if(jugador==1){
	 		cout<< "Jugador1"<<endl;
	 		Imprimir (m);
	 		jugador=2;
	 		cout << "Ingrese la fila inicial: "<<endl;
	 		cin >> a;
	 		cout << "Ingrese la columna inicial: "<<endl;
	 		cin >> b;
	 		cout << "Ingrese la fila FINAL: "<<endl;
	 		cin >> c;
	 		cout << "Ingrese la columna FINAL: "<<endl;
	 		cin >> d;
	 		if ((a>=0 &&a<=6)&&(b>=0 &&b<=6)&&(c>=0 &&c<=6)&&(d>=0 &&d<=6)){
	 			jugador1 (m,a,b,c,d);
	 		}else{
	 			cout<< "Fuera de rango :( "<<endl;
	 		}

	 	}
	 	if(jugador==2){
	 		cout<< "Jugador2"<<endl;
	 		Imprimir (m);
	 		jugador=1;
	 		cout << "Ingrese la fila inicial: "<<endl;
	 		cin >> a;
	 		cout << "Ingrese la columna inicial: "<<endl;
	 		cin >> b;
	 		cout << "Ingrese la fila FINAL: "<<endl;
	 		cin >> c;
	 		cout << "Ingrese la columna FINAL: "<<endl;
	 		cin >> d;
	 		if ((a>=0 &&a<=6)&&(b>=0 &&b<=6)&&(c>=0 &&c<=6)&&(d>=0 &&d<=6)){
	 			jugador2 (m,a,b,c,d);
	 		}else{
	 			cout<< "Fuera de rango :( "<<endl;
	 		}

	 	
	 	}
	 	int contador777 =0;
	 for(int i =0; i<7;i++){
	    for(int j =0 ;j<7 ;j++){
		  if (m[i][j] != '0'){
		  		contador777++;
		  }
	    }
	   
	}	

	if (49<=contador777){
		cout<< "Gano El jugador "<<jugador <<" :)" <<endl;
		jugando = false;
	}


	 	int cont ;
	 	cout << "desea salir del juego ingrese 1?"<<endl;
	 	cin >> cont;
	 	if (cont==1){
	 		jugando = false;
	 	}
	 	
	 
	 
	
	 }
	}
	 liberar_Memoria(m);
	
	return 0;
}

void matriz (char** m){

	for (int i =0; i<7 ;i++){
		m[i]=new char[7];
        }
	

	
}

void liberar_Memoria(char** m){
  
		
	for(int i =0 ; i <7 ;i++){
	   delete[] m[i];

	}

delete[] m;

}

void llenado (char** m){
	for(int i =0; i<7;i++){
	    for(int j =0 ;j<7 ;j++){
		m[i][j]='0';
	    }
	   
	}	

	m[0][3]='1';
	m[6][3]='1';
	m[3][0]='2';
	m[3][6]='2';
		


}

void Imprimir (char** m){
	cout<< "    0    1    2    3    4    5    6"<<endl;
	for(int i =0; i<7;i++){
		cout <<i<< " ";
	    for(int j =0 ;j<7 ;j++){

			cout << "[ "<< m[i][j] <<" ]";
	    }
	    cout << endl;
	}	
}

void jugador1 (char** m ,int x ,int y , int a , int b){
	int g=0,h=0;
	g = abs(x-a);
	h = abs(y-b);
	cout <<g<<endl;
	cout << h<<endl;
    
	if(g<=2 && h<=2){
		if((g==2 && h ==0)||(g==0 && h ==2)){


			if (m[x][y]=='1'&&m[a][b]!='2'){
				if((y-b)==-2){
            		m[a][b-1]='1';
            		m[a][b]='1';
			
		   			}
		    	if ((y-b)== 2&&m[a][b]!='2'){
		    		m[a][b+1]='1';
            		m[a][b]='1';
		    	}
				if((x-a)==-2&&m[a][b]!='2'){
            		m[a-1][b]='1';
            		m[a][b]='1';
			
		   		}
		    	if ((x-a)== 2&&m[a][b]!='2'){
		    		m[a+1][b]='1';
            		m[a][b]='1';
		    	}

		    }else{//
				cout << "Perdio turno :("<<endl;
		   		cout <<(y-b)<<endl;


        }
		   
           
	}
		if (m[a][b]=='2'){
		m[a][b]='1';
		cout<< "se Comio una pieza del jugador 2 :)"<<endl;
		
		
	}
	

	m[a][b]='1';
	}else{//
		cout<< "no se puede mover mas de 2 espacios"<<endl;
	}
    


}

void jugador2 (char** m ,int x ,int y , int a , int b){
	int g=0,h=0;
	g = abs(x-a);
	h = abs(y-b);
	cout <<g<<endl;
	cout << h<<endl;
    
	if(g<=2 && h<=2){
		if((g==2 && h ==0)||(g==0 && h ==2)){


			if (m[x][y]=='2'&&m[a][b]!='1'){
				if((y-b)==-2){
            		m[a][b-1]='2';
            		m[a][b]='2';
			
		   			}
		    	if ((y-b)== 2&&m[a][b]!='1'){
		    		m[a][b+1]='2';
            		m[a][b]='2';
		    	}
				if((x-a)==-2&&m[a][b]!='1'){
            		m[a-1][b]='2';
            		m[a][b]='2';
			
		   		}
		    	if ((x-a)== 2&&m[a][b]!='2'){
		    		m[a+1][b]='2';
            		m[a][b]='2';
		    	}

		    }else{//
				cout << "Perdio turno :("<<endl;
		   		cout <<(y-b)<<endl;


        }
		   
           
	}
		if (m[a][b]=='1'){
		m[a][b]='2';
		cout<< "se Comio una pieza del jugador 1 :)"<<endl;
		
		
	}
	

	m[a][b]='2';
	}else{//
		cout<< "no se puede mover mas de 2 espacios"<<endl;
	}
    


}



