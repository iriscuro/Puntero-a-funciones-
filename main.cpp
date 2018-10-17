#include <iostream>

using namespace std;

void swapl(int *a,int *b){
    int tem=*a;
    *a=*b;
    *b=tem;
}

bool ordAS(int a,int b){
    return a>b;
}
bool ordDesc(int a, int b){
    return a<b;
}
int len(int *arr){
    int *tem=arr;
    while(*arr!='\0'){
        arr++;
    }
    return arr-tem;
}
/*
void orD(int *arr){
    int t=0;
    t=len(arr);
    for(int i=0;i<t;i++){
        for(int j=0;j<t-i-1;j++){
            if(ordAs(arr[j],arr[j+1]))
                swapl(&arr[j],&arr[j+1]);
        }
        }}
        */
// con puntero a funcion

void orD(int *arr,int n ,bool (*fp)(int, int )){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if((*fp)(arr[j],arr[j+1]))
                swapl(&arr[j],&arr[j+1]);
        }
        }}


void printL(int *arr,int n ){
    //int t=0;
    //t=len(arr);
    for(int i=0;i<n;i++){
        cout <<arr[i]<< " ";
    }
}
//----------------------<<<<<<<*>>>>>>>>>
int *funcion(){
    int x=5;
    return &x;//esto es invalido porque la el valor de x en valido solo en la funcion
}
int *funcion1(int x){
    x=5;
    return &x;
}
int *funcio2(){
    int *ptr= new int;// re
    *ptr=5;
    return ptr;
}
//di¿reccion de memoria de un entero
int main()
{

    /*
    int firefly[]={64,34,25,12,22,11,75};
    int n=sizeof(firefly)/sizeof(firefly[0]);//tamaño del array
    // puedo ingresar n afuncion como un parametro
    //---------------<<<*<<<<<<<<<<
    bool (*fp)(int,int);
    fp=ordAS;
    orD(firefly,n,fp);
    //-------------<<<<*<<<<<<<<<<
    // orD(firefly,n,ordAs);
    printL(firefly,n);
    cout <<endl;
    */
//-----------------------------------------------------------------
    /*
    int *ptr=funcion();
    cout << *ptr<<endl;//5
    */

/*
    int x =5;
    int *ptr=funcion1(&x);
    cout << *ptr<<endl; // ERROR
*/
//-------------------------------------------------------------------
    /*
    int *pt=funcion2();//PUNTA A LA DIRCCION DE MEMORIA RESERVADA
    cout << *pt<<endl;
    delete pt;
    //retorna 5 por que hay un espacio de memoria
    //revisar
    */
    //---------------------------------------------
    /*
    int *pt;
    for(int i=0;i<10;i++){// si 10 sea un numero mayor la maquina se cuelga
        pt=funcion();
        cout <<*pt<<endl;
        delete pt;// elimina cada direccion de memoria reservada
    }
   //delete pt;//elimina la ultima dirccion de memoria
   */
   //-----------------<<<<<<<*>>>>>>>>-----------------
   int r;
   // un arreglo es en realidad en el fondo un puntero
   cin >> r;//ingresa por tecldo el tamaño del nuevo array
   int *pt=new int[r];
   for(int i=0;i<r;i++){
        cin >> pt[i];
    }
    printL(pt,r);
    delete[] pt;

    //--------------<<<<<<<<<<*>>>>>>>>>>>-------------------
    int l;
    int *clean=new int[l];
    cout <<" Tamanio del array : "<<endl;
    cin>>l;
    for(int i=0;i<l;i++){
        cin >> clean[i];
    }
    bool (*fp)(int,int);
    fp=ordAS;
    orD(clean,l,fp);
    printL(clean,l);
    delete[] pt;
    return 0;
}
