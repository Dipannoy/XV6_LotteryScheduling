#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main() {
  int process_id;
  int x, y;
  int interval=10000;
  int firstPrime = 2;
 
  int p,q;
  int setNiceVal; 
  

  process_id = 0;
  y = 2;
  for ( x = 0; x < y; x++ ) {
    process_id = fork ();
     if (process_id > 0) {
      
      setNiceVal = setnice(process_id,20);
      if(setNiceVal == 20)
      {
         wait();     
      }
     
     
      }
      else{
	
        for(p=2;p<=30000000000;p++)
       {
          for(q=2;q<p;q++)
        {
           if(p%q == 0)
           {
              break;
           }

        }
        if(p == q && (p-firstPrime) >= interval)
        {
             printf(1,"Process No %d(Current Tickets - %d) printing prime number %d \n",getpid(),getpnice(), p );
             firstPrime = p;
         }

       }
    
	break;
      }
  }
  exit();
}
