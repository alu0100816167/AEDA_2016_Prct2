#include "complejo.hpp"

complejo::complejo(void):
r(),
i(),
m()
{}

complejo::complejo(double n):
r(n),
i(0)
{}

complejo::complejo(double re, double im):
r(re),
i(im)
{
  m = r*r+i*i;
}

complejo::complejo(const complejo& n) 
{
  *this = n;
}


complejo::~complejo(void){}

double complejo::get_r(void) const
{
  return r;
}

double complejo::get_i(void) const
{
  return i;
}

double complejo::get_m(void) const
{
  return m;
}

complejo& complejo::operator=(const complejo& a)
{
  i = a.get_i();
  r = a.get_r();
  
  return *this;
}

complejo& complejo::operator=(int n)
{
  r= -1;
  i= i;
  
  return *this;
}

complejo& complejo::operator=(const string a)
{
  size_t found = a.find("+");
  
  string b,c;
  b.resize(found);
  c.resize((a.size() - found)-2);
  for(unsigned int k=0;k<found;k++) {
  
   b[k] = a[k];
  }
  for(unsigned int j=0;j<c.size();j++) {
  
    c[j] = a[j+1+found];
  }
  
  r = atof(b.c_str());
  i = atof(c.c_str());
}





//Aritméticos
complejo operator+(const complejo& a, const complejo& b)
{
  return complejo(a.get_r() + b.get_r(), a.get_i() + b.get_i());
}

complejo operator-(const complejo& a, const complejo& b)
{ 
  return complejo(a.get_r() - b.get_r(), a.get_i() - b.get_i());
}

complejo operator*(const complejo& a, const complejo& b)
{
  if(b.get_i() == 0)
  {
    return complejo((a.get_r() * b.get_r()), a.get_i() * b.get_r()); //complejo((a.get_r() * b.get_r()), a.get_i() );
  }
  else
  return complejo((a.get_r() * b.get_r()) - (a.get_i() * a.get_i()), a.get_r()*b.get_i() + a.get_i()*b.get_r());//(a + bi) * (c + di) = (ac − bd) + (ad + bc)i
}

complejo operator/(const complejo& a, const complejo& b)
{
  return complejo((a.get_r()*b.get_r() + a.get_i()*b.get_i())/(b.get_r()*b.get_r()+b.get_i()*b.get_i()), (a.get_i()*b.get_r()-a.get_r()*b.get_i())/(b.get_r()*b.get_r()+b.get_i()*b.get_i()));
}

//comparación
bool operator==(const complejo& a, const complejo& b)
{
  return(fabs(((a.get_m()-b.get_m()))) < EPSILON ? true:false);
}

bool operator!=(const complejo& a, const complejo& b)
{
  return(a==b ? false:true);
}

bool operator<(const complejo& a, const complejo& b)
{
  return((a.get_m()-b.get_m()) < -EPSILON ? true:false);
}

bool operator>(const complejo& a, const complejo& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const complejo& a, const complejo& b)
{
  return(a>b ? false:true);
}

bool operator>=(const complejo& a, const complejo& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const complejo& a)
{
  os << "(" << a.get_r() << "+" << a.get_i() << "i)";
  return os;
}

istream& operator>>(istream& is, complejo& a)
{
  double re, im;
  //cout << "Parte real:";
  is >> re;
  
  //cout << "Parte imaginaria:";
  is >> im;
  cout << endl;
  
  a = complejo(re, im);
  return is;
}
