
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main() {
  int process_id;
  int x, y;
  int setNiceVal;
  int rev;
  int num;
  int firstPalindrome = 11;
  int interval = 5000;
  int q;
  int factorCount;




  process_id = 0;
  y=2;
  for ( x = 0; x < y; x++ ) {
    process_id = fork ();

    if (process_id > 0) {

      setNiceVal = setnice(process_id,40);
      if(setNiceVal == 40)
      {

      wait();
      }
      }
      else{

      for(int i = 11; i<30000000000; i++)
    {
      num = i;
        rev = 0;
      factorCount = 0;

       while (num != 0) {
        

        rev = rev * 10 + (num%10);
        num /= 10;
      }

        for(q=2;q<=i/2;q++)
        {
           if(i%q == 0)
           {
              factorCount++;
           }

        }

    if (i == rev && factorCount>0 && (i-firstPalindrome) >= interval){
       printf(1,"Process No %d(Current Tickets - %d) printing palindrome composite number %d(Number of Factors - %d)  \n",getpid(),getpnice(), i, factorCount );
         firstPalindrome = i;
    }



}
        break;
      }
  }
  exit();
}






