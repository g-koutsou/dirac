#include <stdlib.h>
#include <assert.h>
#include <defs.h>

lattice *
new_lattice(int dims[ND]) 
{
  lattice *ptr = malloc(sizeof(lattice));
  for(int i=0; i<ND; i++)
    ptr->dims[i] = dims[i];

  int vol = 1;
  for(int i=0; i<ND; i++)
    vol *= dims[i];

  assert((ptr->nn = malloc(sizeof(int)*2*ND*vol))!=NULL);
  for(int t=0; t<dims[0]; t++)
    for(int z=0; z<dims[1]; z++)
      for(int y=0; y<dims[2]; y++)
	for(int x=0; x<dims[3]; x++)
	  for(int d=0; d<ND; d++) {
	    int idx0[] = {t,z,y,x};
	    int idx1[] = {t,z,y,x};
	    int v = idx0[3] + dims[3]*(idx0[2] + dims[2]*(idx0[1] + dims[1]*idx0[0]));

	    idx0[d] = (idx0[d] + 1) % dims[d];
	    int n0 = idx0[3] + dims[3]*(idx0[2] + dims[2]*(idx0[1] + dims[1]*idx0[0]));
	    ptr->nn[v][d] = n0;

	    idx1[d] = (dims[d] + idx1[d] - 1) % dims[d];
	    int n1 = idx1[3] + dims[3]*(idx1[2] + dims[2]*(idx1[1] + dims[1]*idx1[0]));
	    ptr->nn[v][ND+d] = n1;
	  }
	
	  
  return ptr;
}

void
del_lattice(lattice *lat)
{
  free(lat);
  return;
}
