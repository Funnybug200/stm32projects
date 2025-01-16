#define a  PB0
#define b  PB1
#define c  PB4
#define d  PB5
#define e  PB6
#define f  PB7
#define g  PB9
#define x PB8
char pins[8]={a,b,c,d,e,f,g,x};
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

void setup() {
   for(int i=0;i<7;i++){
    pinMode(pins[i],OUTPUT);

  }
  pinMode(PB8,INPUT);
  show(0);
}


int count=0;
void loop() {
   
   if(digitalRead(PB8)==1){
     count++;
     if(count==10){count=0;}
     show(count);
     delay(500);
   }
  
  
}
