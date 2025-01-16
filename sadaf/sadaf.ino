#define a  PB6
#define b  PB7
#define c  PB8
#define d  PB9
#define x  PB5

char pins[5]={a,b,c,d,x};

bool state[4]={0,0,0,0};
void setup() {
for(int i=0;i<4;i++){pinMode(pins[i],OUTPUT);}
pinMode(pins[4],INPUT);

}

void loop() {
 if(digitalRead(x)){
    if(state[3]){
      if(state[2]){
        if(state[1]){
          if(state[0]){
            for(int i=0;i<4;i++){state[i]=0;}
          }else{state[0]=1;state[1]=0;state[2]=0;state[3]=0;}
        }else{state[1]=1;state[2]=0;state[3]=0;}
      }else{state[2]=1;state[3]=0;}
    }else{state[3]=1;}
   delay(300);


 }else{delay(100);}
 for(int i=0;i<4;i++){digitalWrite(pins[i],state[i]);}
}
