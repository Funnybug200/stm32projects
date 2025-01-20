#define a  PB3
#define b  PB4
#define c  PB5
#define d  PB6
#define e  PB7
#define f  PB8
#define g  PB9
#define x  PA0
char pins[7]={a,b,c,d,e,f,g};
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
    
    digitalWrite(pins[i],ss[9-num][i]);
    
    
   }
}

void setup() {
   for(int i=0;i<7;i++){
    pinMode(pins[i],OUTPUT);

  }
  pinMode(PA0,INPUT);
}

void loop() {
  show(analogRead(x)/109);

}
