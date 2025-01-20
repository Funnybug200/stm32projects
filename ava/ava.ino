#define a PB12
#define b PB13
#define c PB14
#define d PB15
#define e PB3
#define f PB4
#define g PB5
#define h PB8
#define x PB7
#define y PB9

int r=0;

char pins[10]={a,b,c,d,e,f,g,h,x,y};

void setup() {
  for(int i=0;i<8;i++){pinMode(pins[i],OUTPUT);}
  for(int j=8;j<10;j++){pinMode(pins[j],INPUT);}
    for(int k=0;k<8;k++){digitalWrite(pins[k],0);}


}

void loop() {
  digitalWrite(pins[r],0);

 if(digitalRead(x)&&r<7){r++;}
 if(digitalRead(y)&&r>0){r--;}
 
 digitalWrite(pins[r],1);
 delay(200);
 
 

}
