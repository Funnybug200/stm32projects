#define a PB3
#define b PB4
#define c PB5
#define d PB6
#define e PB7
#define y PB8
#define x PB9

bool monitor [8][5]={{1,0,0,0,1},
                     {0,1,1,1,0},
                     {0,0,1,0,0},
                     {0,1,0,1,0},
                     {0,1,1,1,0},
                     {1,0,0,0,1},
                     {1,1,1,1,1},
                     {1,1,1,1,1},};

char pins[7]={a,b,c,d,e,y,x};


void setup() {
 for(int i=0;i<7;i++){pinMode(pins[i],OUTPUT);}

 digitalWrite(y,0);
 digitalWrite(x,1);
 delay(1000);
 digitalWrite(x,0);

}

void loop() {
   for(int i=0;i<8;i++){
     for(int j=0;j<5;j++){
       digitalWrite(pins[j],!monitor[i][j]);
       
     }
     digitalWrite(y,1);
     delay(1);
     digitalWrite(y,0);
     delay(1);
   }
}
