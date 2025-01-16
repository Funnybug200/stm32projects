#define a  PB3
#define b  PB4
#define c  PB5
#define d  PB9
#define e  PB8
#define f  PB7
#define g  PB6
#define x PB0
char pins[8]={a,b,c,d,e,f,g,x};
int clocke[4]={1,2,3,4};
void show(int num){
  //if(num>9){return 0;}
  bool ss [10][7]={{1,1,1,1,1,1,0},
                   {0,1,1,0,0,0,0},
                   {1,1,0,1,1,0,1},
                   {1,1,1,1,0,0,1},
                   {0,1,1,0,0,1,1},
                   {1,0,1,1,0,1,1},
                   {1,0,1,1,1,1,1},
                   {1,1,1,0,0,0,0},
                   {1,1,1,1,1,1,1},
                   {1,1,1,1,0,1,1}};
        
   
   for(int i=0;i<7;i++){
    
    digitalWrite(pins[i],ss[num][i]);
    
    
   }
}
void next (){
  digitalWrite(x,1);
  delay(1);
  digitalWrite(x,0);
}
void setup() {
   for(int i=0;i<7;i++){
    pinMode(pins[i],OUTPUT);

  }
  pinMode(x,OUTPUT);
  digitalWrite(x,0);
}



void loop() {
 unsigned long currentMillis = millis();
 if((currentMillis % 100)==0){clocke[3]=clocke[3]+1;
   if(clocke[3]==10){clocke[3]=0;clocke[2]=clocke[2]+1;
      if(clocke[2]==6){clocke[2]=0;clocke[1]=clocke[1]+1;
        if(clocke[1]==10){clocke[1]=0;clocke[0]=clocke[0]+1;}}}
  
  }
 
   for(int i=0;i<4;i++){
     show(clocke[i]);
     next();
   }
   
}

