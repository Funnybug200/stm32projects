#include <dht11.h>
#define DHT11PIN PB9

dht11 DHT11;

void  setup()
{
  
  pinMode(PB4,OUTPUT);
  pinMode(PB3,OUTPUT);
}

void loop()
{
  

   int chk = DHT11.read(DHT11PIN);



 if( DHT11.temperature==10){
   digitalWrite(PB3,1);
   digitalWrite(PB4,0);
 }else{digitalWrite(PB3,0);
       digitalWrite(PB4,1);}

   delay(10);


}
