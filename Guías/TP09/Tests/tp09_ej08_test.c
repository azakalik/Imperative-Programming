#include <stdio.h>
#include <assert.h>


int main(void) {

  for(int i=0; i < 100; i++)
     assert(ackermann(0, i)==i+1);

  assert(ackermann(3,0)==5);
  assert(ackermann(3,2)==29);

  printf("Wait for it...\n");

  assert(ackermann(4,1)==65533);

  printf ("Legendary!\n");
  return 0;
}