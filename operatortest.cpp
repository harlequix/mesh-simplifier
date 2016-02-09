#include "Vertex.h"
#include <iostream>


int main(int argc, char const *argv[]){
  Vertex vertex_a(2,2,2);
  Vertex vertex_b(2,2,2);
  Vertex vertex_c(0,0,0);
  double resultDotProduct=vertex_a * vertex_b;
  Vertex resultScalar=vertex_a * 2.0;
  std::cout << "(2,2,2)*(2,2,2)="<< resultDotProduct << std::endl;
  std::cout << "(2,2,2)* 2.0=" << "(" << resultScalar.x << "," << resultScalar.y << "," << resultScalar.z << ")" << std::endl;
  Vertex resultScalarZero=vertex_a * 0;
  std::cout << "(2,2,2)* 0=" << "(" << resultScalarZero.x << "," << resultScalarZero.y << "," << resultScalarZero.z << ")" << std::endl;
  double resultDotProductZero=vertex_a * vertex_c;
  std::cout << "(2,2,2)*(0,0,0)="<< resultDotProductZero << std::endl;

  return 0;
}