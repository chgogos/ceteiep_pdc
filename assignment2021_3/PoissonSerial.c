// Serial code for 1D Poisson equation 

// Include libraries
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// number of sections
#define GRIDSIZE 20

// Equation parameters
double a=1.0; // Diffusion coefficient
double dt=0.0001; // Time discretization step
double dx=0.02; // Space discretization step

// Residual to stop iterations
double residual = 1e-7;

//Count iterations
int count=0;

// unorm (use initially a large value)
// Norm of the difference between u (at time t-1) and unew (at time t)
double unorm =1000;

// A single time step
// u: temperatures at the internal spatial points at time instants t-1 
// unew: temperatures at the internal spatial points at time instants t
// points: number of internal spatial sections
double poisson_discrete(float *u, float *unew, int points){

  // Discrete time equation parameter
  // F is dimensionless and lumps the key physical parameters in the problem
  double F=dt*a/(dx*dx);

  // Calculate one timestep. Calculate unew at time step t (new) for section i
  // from u at time step t-1, of current section (i) and of
  // neighboring sections i-1 and i+1
  for( int i=1; i <= points; i++){
    unew[i] = (1-2*F)*u[i] +F*u[i-1] + F*u[i+1];
  }
 
  // Calculate square of norm of the difference 
  // between u and unew
  // To be returned from the function    
  unorm = 0.0;
  for( int i = 1;i <= points; i++){
    float diff = unew[i]-u[i];
    unorm +=diff*diff;
  }
 
  // Overwrite u with unew, preparing for next iteration
    for( int i = 1;i <= points;i++){
      u[i] = unew[i];
    }
 
  return unorm;
}


int main(int argc, char** argv) {

  // The heat energy vectors
  // We also reserve space for the 2 boundary conditions at both ends
  float u[GRIDSIZE+2], unew[GRIDSIZE+2];
  
  int i;
 
  // Initialize u to 0 
  for(i=0; i <= GRIDSIZE+1; i++) {
    u[i] = 0.0;
  }

  // Set boundary conditions for the leftmost (position 0) 
  // and rightmost (position GRIDSIZE+1) sections
  u[0] = 10.0;
  u[GRIDSIZE+1]=5.0;
 
  // Run iterations until equilibrium is reached and changes are minimal
  while(sqrt(unorm) > sqrt(residual)){
    unorm = poisson_discrete(u, unew, GRIDSIZE);
    count++;
    printf("Iteration: %d, Residue: %g\n", count, unorm);
  }
 
  printf("\n");
  printf("Completed with residue %g\n", unorm);

  // Plotting histogram
  printf("\n\nPlot solution data\n");
  for (i = 0; i <= GRIDSIZE+1; i++){
    double count = u[i];
    printf("%3d |", i);
    for (int j = 0; j < count; j++)
    {
        printf("%c", (char)254u);
        // printf("\u2500");
    }
    printf(" %lf",u[i]);
    printf("\n");
  }

}
