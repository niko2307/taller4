#ifndef NODOQUAD_H
#define NODOQUAD_H
classNodoQuad{
  protected: 
punto dato; 
NodoQuad* hijoSupIzq;
NodoQuad* hijoSupDer; 
NodoQuad* hijoInfIzq; 
NodoQuad* hijoInfDer;
  public: 
NodoQuad();
NodoQuad(punto val); 
~NodoQuad();
punto obtenerDato(); 
voidfijarDato(punto val); 
NodoQuad* obtenerHijoSupIzq(); 
NodoQuad* obtenerHijoSupDer(); 
NodoQuad* obtenerHijoInfIzq(); 
NodoQuad* obtenerHijoInfDer(); 
void fijarHijoSupIzq(NodoQuad* sizq); 
void  fijarHijoSupDer(NodoQuad* sder); 
void fijarHijoInfIzq(NodoQuad* iizq);
void fijarHijoInfDer(NodoQuad* ider);
bool esHoja();
  
  
};
#endif // NODOQUAD.H
