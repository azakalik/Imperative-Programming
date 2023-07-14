#include <stdio.h>
#include <assert.h>

int main(void) {
  int v[] = {1, 2, 3, 4, 5, -5};

  assert(sumaVec(v,0)==0);
  assert(sumaVec(v,1)==1);
  assert(sumaVec(v,2)==3);
  assert(sumaVec(v,3)==6);
  assert(sumaVec(v,4)==10);
  assert(sumaVec(v,5)==15);
  assert(sumaVec(v,6)==10);

  printf ("OK!\n");
  return 0;
}