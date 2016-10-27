//This code is used to print and log data received by a brain eeg headset
//the hardware required is an eeg headset arduino mega and an ethernet shield
//to mount the SD card. signal quality,attention,meditation,delta, theta,
//low alpha,high alpha,low beta,high beta, low gamma, mid gamma. all these values are 
//logged in a file "data.txt" also these values are printed in Serial monitor.
//a p300 speller code with trainer is also included with this code. the trainer is 
//used for recording data for each alphabet and then the speller spells the letter 
//you think. for improving the code do add your inputs and optimize as much as possible.
//Coder- Tanmay Chakraborty //mail me at-tanmay.608@gmail.com

//function name trainer() void type
//function name spell() character type returns a character
//function name printletter() displays alphabet matrix


#include <Brain.h>
#include <SD.h>

Brain brain(Serial);
const int chipSelect = 4;
int signalquality;
String datastring,sensor,redatt,redmed,reddel, redthe,lowalp,highalp,lowbet,highbet, lowgam, midgam;

long int a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,f1,f2,g1,g2,h1,h2,i1,i2,j1,j2;   //A a1 highest a2 lowest
long int a3,a4,b3,b4,c3,c4,d3,d4,e3,e4,f3,f4,g3,g4,h3,h4,i3,i4,j3,j4;   //B
long int a5,a6,b5,b6,c5,c6,d5,d6,e5,e6,f5,f6,g5,g6,h5,h6,i5,i6,j5,j6;   //C
long int a7,a8,b7,b8,c7,c8,d7,d8,e7,e8,f7,f8,g7,g8,h7,h8,i7,i8,j7,j8;   //D
long int a9,a0,b9,b0,c9,c0,d9,d0,e9,e0,f9,f0,g9,g0,h9,h0,i9,i0,j9,j0;   //E
long int aa1,aa2,ba1,ba2,ca1,ca2,da1,da2,ea1,ea2,fa1,fa2,ga1,ga2,ha1,ha2,ia1,ia2,ja1,ja2;   //F
long int ab1,ab2,bb1,bb2,cb1,cb2,db1,db2,eb1,eb2,fb1,fb2,gb1,gb2,hb1,hb2,ib1,ib2,jb1,jb2;   //G
long int ac1,ac2,bc1,bc2,cc1,cc2,dc1,dc2,ec1,ec2,fc1,fc2,gc1,gc2,hc1,hc2,ic1,ic2,jc1,jc2;   //H
long int ad1,ad2,bd1,bd2,cd1,cd2,dd1,dd2,ed1,ed2,fd1,fd2,gd1,gd2,hd1,hd2,id1,id2,jd1,jd2;   //I
long int ae1,ae2,be1,be2,ce1,ce2,de1,de2,ee1,ee2,fe1,fe2,ge1,ge2,he1,he2,ie1,ie2,je1,je2;   //J
long int af1,af2,bf1,bf2,cf1,cf2,df1,df2,ef1,ef2,ff1,ff2,gf1,gf2,hf1,hf2,if1,if2,jf1,jf2;   //K
long int ag1,ag2,bg1,bg2,cg1,cg2,dg1,dg2,eg1,eg2,fg1,fg2,gg1,gg2,hg1,hg2,ig1,ig2,jg1,jg2;   //L
long int ah1,ah2,bh1,bh2,ch1,ch2,dh1,dh2,eh1,eh2,fh1,fh2,gh1,gh2,hh1,hh2,ih1,ih2,jh1,jh2;   //M
long int ai1,ai2,bi1,bi2,ci1,ci2,di1,di2,ei1,ei2,fi1,fi2,gi1,gi2,hi1,hi2,ii1,ii2,ji1,ji2;   //N
long int ak1,ak2,bk1,bk2,ck1,ck2,dk1,dk2,ek1,ek2,fk1,fk2,gk1,gk2,hk1,hk2,ik1,ik2,jk1,jk2;   //O
long int al1,al2,bl1,bl2,cl1,cl2,dl1,dl2,el1,el2,fl1,fl2,gl1,gl2,hl1,hl2,il1,il2,jl1,jl2;   //P
long int am1,am2,bm1,bm2,cm1,cm2,dm1,dm2,em1,em2,fm1,fm2,gm1,gm2,hm1,hm2,im1,im2,jm1,jm2;   //Q
long int an1,an2,bn1,bn2,cn1,cn2,dn1,dn2,en1,en2,fn1,fn2,gn1,gn2,hn1,hn2,in1,in2,jn1,jn2;   //R
long int ao1,ao2,bo1,bo2,co1,co2,do1,do2,eo1,eo2,fo1,fo2,go1,go2,ho1,ho2,io1,io2,jo1,jo2;   //S
long int ap1,ap2,bp1,bp2,cp1,cp2,dp1,dp2,ep1,ep2,fp1,fp2,gp1,gp2,hp1,hp2,ip1,ip2,jp1,jp2;   //T
long int aq1,aq2,bq1,bq2,cq1,cq2,dq1,dq2,eq1,eq2,fq1,fq2,gq1,gq2,hq1,hq2,iq1,iq2,jq1,jq2;   //U
long int ar1,ar2,br1,br2,cr1,cr2,dr1,dr2,er1,er2,fr1,fr2,gr1,gr2,hr1,hr2,ir1,ir2,jr1,jr2;   //V
long int as1,as2,bs1,bs2,cs1,cs2,ds1,ds2,es1,es2,fs1,fs2,gs1,gs2,hs1,hs2,is1,is2,js1,js2;   //W
long int at1,at2,bt1,bt2,ct1,ct2,dt1,dt2,et1,et2,ft1,ft2,gt1,gt2,ht1,ht2,it1,it2,jt1,jt2;   //X
long int au1,au2,bu1,bu2,cu1,cu2,du1,du2,eu1,eu2,fu1,fu2,gu1,gu2,hu1,hu2,iu1,iu2,ju1,ju2;  //Y
long int av1,av2,bv1,bv2,cv1,cv2,dv1,dv2,ev1,ev2,fv1,fv2,gv1,gv2,hv1,hv2,iv1,iv2,jv1,jv2;   //Z

long int A[11],B[11],C[11],D[11],E[11],F[11],G[11],H[11],I[11],J[11];


void setup(void) {

 
      Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
   Serial.println("Card failed, or not present");
    // don't do anything more:
   return;
   }
}
void loop() {


   if (brain.update()) 
   {
     if (brain.readSignalQuality() > 100) //checks signal quality of the connection
     {
       Serial.println("poor signal quality");
      }
 
// all values come in unsigned long int
//they have been type casted to string for storing it in a file
//raw data is coming in unsigned long int.
else 
{
 
 Serial.println("INITIAL SENSOR VALUES");
 for(int t=0;t<2;t++)
 {
 sensor=(String)brain.readSignalQuality();  //stores signal quality
 redatt=(String)brain.readAttention();   //stores attention value
 redmed=(String)brain.readMeditation();    //stores meditaiton value
 reddel=(String)brain.readDelta();       //stores delta value
 redthe=(String)brain.readTheta();  //stores theta value
 lowalp=(String)brain.readLowAlpha();  //stores low alpha value                
 highalp=(String)brain.readHighAlpha();   //stores high alpha value
 lowbet=(String)brain.readLowBeta();   //stores low beta value
 highbet=(String)brain.readHighBeta();  //stores high beta value
 lowgam=(String)brain.readLowGamma();   //stores low gamma value
 midgam=(String)brain.readMidGamma();  //stores mid gamma value
                
                Serial.print("signal quality :");
                Serial.print(brain.readSignalQuality());
                Serial.println(" ");
                Serial.print("Attention      :");   
                Serial.print(brain.readAttention());
                Serial. println(" ");
                Serial.  print("Meditation     :");
                Serial.print(brain.readMeditation());
                Serial.println(" ");
                Serial.print("Delta      : ");
                Serial.print(brain.readDelta());
                Serial.println(" ");
                Serial.print("Theta      : ");
                Serial.print(brain.readTheta());
                Serial.println(" ");
                Serial.print("Low Alpha  : ");
                Serial.print(brain.readLowAlpha());
                Serial.println(" ");
                Serial.print("High Alpha : ");
                Serial.print(brain.readHighAlpha());
                Serial.println(" ");
                Serial.print("Low Beta   : ");
                Serial.print(brain.readLowBeta());
                Serial.println(" ");
                Serial.print("High Beta  : ");
                Serial.println(brain.readHighBeta()); 
                Serial.println(" ");
                Serial.print("Low Gamma  : ");
                Serial.print(brain.readLowGamma());
                Serial.println(" ");
                Serial.print("Mid Gamma  : ");
                Serial.print(brain.readMidGamma());
                Serial.println(" ");
 }
 
          Serial.println("P 300 SPELLER USING ARDUINO... ");
          Serial.println("SELECT 1 FOR STARTING TRAINER... ");
          int select=0;
          if(Serial.available()>0)
          {
            select=Serial.read();
          }
          if(select==1)
          { 
            Serial.println("STARTING TRAINER... ");
            Serial.println("CONCENTRATE ON EACH LETTER DISPLAYED WHILE THE CODE RECORDS DATA... ");
            trainer();
          }
          Serial.println("SELECT 2 TO TRACE OUT THE ALPHABET ");
         // Serial.println("CONCENTRATE ON THE ALPHABET YOU WANT TO FIND USING THE SPELLER.. ");
           if(Serial.available()>0)
          {
            select=Serial.read();
          }
          String s="";
          if(select==2)
          { 
            Serial.println("STARTING SPELLER... ");
                printletter();
                s+=(String)spell();
                Serial.print("selected letter  : ");
                Serial.print(s);
                Serial.println(" ");
                Serial.println("SELECT 2 FOR TRACING THE NEXT ALPHABET.. ");
                
                
          }
                
  }
}
  datastring=datastring+"signal quality: "+sensor+" ,"+"Attention: "+redatt+","+"Medition: "+redmed+","+"Delta: "+reddel+","+"Theta: "+redthe+","+"LowAlpha: "+lowalp+","+"HighAlpha"+highalp+","+"LowBeta: "+lowbet+","+"HighBeta: "+highbet+","+"LowGamma: "+lowgam+","+"MidGamma: "+midgam;
  


 
 File dataFile = SD.open("data.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(datastring);
    dataFile.close();
   //  print to the serial port too:
    Serial.println(datastring);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}

void trainer()
{
Serial.println("A");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}

//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

a1=highest(A);
a2=lowest(A);
b1=highest(B);
b2=lowest(B );
c1=highest(C );
c2=lowest(C );
d1=highest(D );
d2=lowest(D );
e1=highest(E );
e2=lowest(E );
f1=highest(F );
f2=lowest(F );
g1=highest(G );
g2=lowest(G );
h1=highest(H );
h2=lowest(H );
i1=highest(I );
i2=lowest(I ); 
j1=highest(J );
j2=lowest(J );

Serial.println("B");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

a3=highest(A );
a4=lowest(A );
b3=highest(B );
b4=lowest(B );
c3=highest(C );
c4=lowest(C );
d3=highest(D );
d4=lowest(D );
e3=highest(E );
e4=lowest(E );
f3=highest(F );
f4=lowest(F );
g3=highest(G );
g4=lowest(G );
h3=highest(H );
h4=lowest(H );
i3=highest(I );
i4=lowest(I ); 
j3=highest(J );
j4=lowest(J );

Serial.println("C");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}


a5=highest(A );
a6=lowest(A );
b5=highest(B );
b6=lowest(B );
c5=highest(C );
c6=lowest(C );
d5=highest(D );
d6=lowest(D );
e5=highest(E );
e6=lowest(E );
f5=highest(F );
f6=lowest(F );
g5=highest(G );
g6=lowest(G );
h5=highest(H );
h6=lowest(H );
i5=highest(I );
i6=lowest(I ); 
j5=highest(J );
j6=lowest(J );

Serial.println("D");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}


a7=highest(A );
a8=lowest(A );
b7=highest(B );
b8=lowest(B );
c7=highest(C );
c8=lowest(C );
d7=highest(D );
d8=lowest(D );
e7=highest(E );
e8=lowest(E );
f7=highest(F );
f8=lowest(F );
g7=highest(G );
g8=lowest(G );
h7=highest(H );
h8=lowest(H );
i7=highest(I );
i8=lowest(I ); 
j7=highest(J );
j8=lowest(J );

Serial.println("E");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}

//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

a9=highest(A );
a0=lowest(A );
b9=highest(B );
b0=lowest(B );
c9=highest(C );
c0=lowest(C );
d9=highest(D );
d0=lowest(D );
e9=highest(E );
e0=lowest(E );
f9=highest(F );
f0=lowest(F );
g9=highest(G );
g0=lowest(G );
h9=highest(H );
h0=lowest(H );
i9=highest(I );
i0=lowest(I ); 
j9=highest(J );
j0=lowest(J );


Serial.println("F");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

aa1=highest(A );
aa2=lowest(A );
ba1=highest(B );
ba2=lowest(B );
ca1=highest(C );
ca2=lowest(C );
da1=highest(D );
da2=lowest(D );
ea1=highest(E );
ea2=lowest(E );
fa1=highest(F );
fa2=lowest(F );
ga1=highest(G );
ga2=lowest(G );
ha1=highest(H );
ha2=lowest(H );
ia1=highest(I );
ia2=lowest(I ); 
ja1=highest(J );
ja2=lowest(J );

Serial.println("G");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ab1=highest(A );
ab2=lowest(A );
bb1=highest(B );
bb2=lowest(B );
cb1=highest(C );
cb2=lowest(C );
db1=highest(D );
db2=lowest(D );
eb1=highest(E );
eb2=lowest(E );
fb1=highest(F );
fb2=lowest(F );
gb1=highest(G );
gb2=lowest(G );
hb1=highest(H );
hb2=lowest(H );
ib1=highest(I );
ib2=lowest(I ); 
jb1=highest(J );
jb2=lowest(J );

Serial.println("H");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ac1=highest(A );
ac2=lowest(A );
bc1=highest(B );
bc2=lowest(B );
cc1=highest(C );
cc2=lowest(C );
dc1=highest(D );
dc2=lowest(D );
ec1=highest(E );
ec2=lowest(E );
fc1=highest(F );
fc2=lowest(F );
gc1=highest(G );
gc2=lowest(G );
hc1=highest(H );
hc2=lowest(H );
ic1=highest(I );
ic2=lowest(I ); 
jc1=highest(J );
jc2=lowest(J );

Serial.println("I");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ad1=highest(A );
ad2=lowest(A );
bd1=highest(B );
bd2=lowest(B );
cd1=highest(C );
cd2=lowest(C );
dd1=highest(D );
dd2=lowest(D );
ed1=highest(E );
ed2=lowest(E );
fd1=highest(F );
fd2=lowest(F );
gd1=highest(G );
gd2=lowest(G );
hd1=highest(H );
hd2=lowest(H );
id1=highest(I );
id2=lowest(I ); 
jd1=highest(J );
jd2=lowest(J );

Serial.println("J");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ae1=highest(A );
ae2=lowest(A );
be1=highest(B );
be2=lowest(B );
ce1=highest(C );
ce2=lowest(C );
de1=highest(D );
de2=lowest(D );
ee1=highest(E );
ee2=lowest(E );
fe1=highest(F );
fe2=lowest(F );
ge1=highest(G );
ge2=lowest(G );
he1=highest(H );
he2=lowest(H );
ie1=highest(I );
ie2=lowest(I ); 
je1=highest(J );
je2=lowest(J );

Serial.println("K");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

af1=highest(A );
af2=lowest(A );
bf1=highest(B );
bf2=lowest(B );
cf1=highest(C );
cf2=lowest(C );
df1=highest(D );
df2=lowest(D );
ef1=highest(E );
ef2=lowest(E );
ff1=highest(F );
ff2=lowest(F );
gf1=highest(G );
gf2=lowest(G );
hf1=highest(H );
hf2=lowest(H );
if1=highest(I );
if2=lowest(I ); 
jf1=highest(J );
jf2=lowest(J );


Serial.println("L");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ag1=highest(A );
ag2=lowest(A );
bg1=highest(B );
bg2=lowest(B );
cg1=highest(C );
cg2=lowest(C );
dg1=highest(D );
dg2=lowest(D );
eg1=highest(E );
eg2=lowest(E );
fg1=highest(F );
fg2=lowest(F );
gg1=highest(G );
gg2=lowest(G );
hg1=highest(H );
hg2=lowest(H );
ig1=highest(I );
ig2=lowest(I ); 
jg1=highest(J );
jg2=lowest(J );

Serial.println("M");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ah1=highest(A );
ah2=lowest(A );
bh1=highest(B );
bh2=lowest(B );
ch1=highest(C );
ch2=lowest(C );
dh1=highest(D );
dh2=lowest(D );
eh1=highest(E );
eh2=lowest(E );
fh1=highest(F );
fh2=lowest(F );
gh1=highest(G );
gh2=lowest(G );
hh1=highest(H );
hh2=lowest(H );
ih1=highest(I );
ih2=lowest(I ); 
jh1=highest(J );
jh2=lowest(J );

Serial.println("N");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ai1=highest(A );
ai2=lowest(A );
bi1=highest(B );
bi2=lowest(B );
ci1=highest(C );
ci2=lowest(C );
di1=highest(D );
di2=lowest(D );
ei1=highest(E );
ei2=lowest(E );
fi1=highest(F );
fi2=lowest(F );
gi1=highest(G );
gi2=lowest(G );
hi1=highest(H );
hi2=lowest(H );
ii1=highest(I );
ii2=lowest(I ); 
ji1=highest(J );
ji2=lowest(J );

Serial.println("O");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ak1=highest(A );
ak2=lowest(A );
bk1=highest(B );
bk2=lowest(B );
ck1=highest(C );
ck2=lowest(C );
dk1=highest(D );
dk2=lowest(D );
ek1=highest(E );
ek2=lowest(E );
fk1=highest(F );
fk2=lowest(F );
gk1=highest(G );
gk2=lowest(G );
hk1=highest(H );
hk2=lowest(H );
ik1=highest(I );
ik2=lowest(I ); 
jk1=highest(J );
jk2=lowest(J );

Serial.println("P");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

al1=highest(A );
al2=lowest(A );
bl1=highest(B );
bl2=lowest(B );
cl1=highest(C );
cl2=lowest(C );
dl1=highest(D );
dl2=lowest(D );
el1=highest(E );
el2=lowest(E );
fl1=highest(F );
fl2=lowest(F );
gl1=highest(G );
gl2=lowest(G );
hl1=highest(H );
hl2=lowest(H );
il1=highest(I );
il2=lowest(I ); 
jl1=highest(J );
jl2=lowest(J );

Serial.println("Q");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]=brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]=brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

am1=highest(A );
am2=lowest(A );
bm1=highest(B );
bm2=lowest(B );
cm1=highest(C );
cm2=lowest(C );
dm1=highest(D );
dm2=lowest(D );
em1=highest(E );
em2=lowest(E );
fm1=highest(F );
fm2=lowest(F );
gm1=highest(G );
gm2=lowest(G );
hm1=highest(H );
hm2=lowest(H );
im1=highest(I );
im2=lowest(I ); 
jm1=highest(J );
jm2=lowest(J );

Serial.println("R");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

an1=highest(A );
an2=lowest(A );
bn1=highest(B );
bn2=lowest(B );
cn1=highest(C );
cn2=lowest(C );
dn1=highest(D );
dn2=lowest(D );
en1=highest(E );
en2=lowest(E );
fn1=highest(F );
fn2=lowest(F );
gn1=highest(G );
gn2=lowest(G );
hn1=highest(H );
hn2=lowest(H );
in1=highest(I );
in2=lowest(I ); 
jn1=highest(J );
jn2=lowest(J );

Serial.println("S");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ao1=highest(A );
ao2=lowest(A );
bo1=highest(B );
bo2=lowest(B );
co1=highest(C );
co2=lowest(C );
do1=highest(D );
do2=lowest(D );
eo1=highest(E );
eo2=lowest(E );
fo1=highest(F );
fo2=lowest(F );
go1=highest(G );
go2=lowest(G );
ho1=highest(H );
ho2=lowest(H );
io1=highest(I );
io2=lowest(I ); 
jo1=highest(J );
jo2=lowest(J );


Serial.println("T");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ap1=highest(A );
ap2=lowest(A );
bp1=highest(B );
bp2=lowest(B );
cp1=highest(C );
cp2=lowest(C );
dp1=highest(D );
dp2=lowest(D );
ep1=highest(E );
ep2=lowest(E );
fp1=highest(F );
fp2=lowest(F );
gp1=highest(G );
gp2=lowest(G );
hp1=highest(H );
hp2=lowest(H );
ip1=highest(I );
ip2=lowest(I ); 
jp1=highest(J );
jp2=lowest(J );

Serial.println("U");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

aq1=highest(A );
aq2=lowest(A );
bq1=highest(B );
bq2=lowest(B );
cq1=highest(C );
cq2=lowest(C );
dq1=highest(D );
dq2=lowest(D );
eq1=highest(E );
eq2=lowest(E );
fq1=highest(F );
fq2=lowest(F );
gq1=highest(G );
gq2=lowest(G );
hq1=highest(H );
hq2=lowest(H );
iq1=highest(I );
iq2=lowest(I ); 
jq1=highest(J );
jq2=lowest(J );

Serial.println("V");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ar1=highest(A );
ar2=lowest(A );
br1=highest(B );
br2=lowest(B );
cr1=highest(C );
cr2=lowest(C );
dr1=highest(D );
dr2=lowest(D );
er1=highest(E );
er2=lowest(E );
fr1=highest(F );
fr2=lowest(F );
gr1=highest(G );
gr2=lowest(G );
hr1=highest(H );
hr2=lowest(H );
ir1=highest(I );
ir2=lowest(I ); 
jr1=highest(J );
jr2=lowest(J );

Serial.println("W");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

as1=highest(A );
as2=lowest(A );
bs1=highest(B );
bs2=lowest(B );
cs1=highest(C );
cs2=lowest(C );
ds1=highest(D );
ds2=lowest(D );
es1=highest(E );
es2=lowest(E );
fs1=highest(F );
fs2=lowest(F );
gs1=highest(G );
gs2=lowest(G );
hs1=highest(H );
hs2=lowest(H );
is1=highest(I );
is2=lowest(I ); 
js1=highest(J );
js2=lowest(J );


Serial.println("X");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}


at1=highest(A );
at2=lowest(A );
bt1=highest(B );
bt2=lowest(B );
ct1=highest(C );
ct2=lowest(C );
dt1=highest(D );
dt2=lowest(D );
et1=highest(E );
et2=lowest(E );
ft1=highest(F );
ft2=lowest(F );
gt1=highest(G );
gt2=lowest(G );
ht1=highest(H );
ht2=lowest(H );
it1=highest(I );
it2=lowest(I ); 
jt1=highest(J );
jt2=lowest(J );

Serial.println("Y");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

au1=highest(A );
au2=lowest(A );
bu1=highest(B );
bu2=lowest(B );
cu1=highest(C );
cu2=lowest(C );
du1=highest(D );
du2=lowest(D );
eu1=highest(E );
eu2=lowest(E );
fu1=highest(F );
fu2=lowest(F );
gu1=highest(G );
gu2=lowest(G );
hu1=highest(H );
hu2=lowest(H );
iu1=highest(I );
iu2=lowest(I ); 
ju1=highest(J );
ju2=lowest(J );

Serial.println("Z");

for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  delay(100);
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

av1=highest(A );
av2=lowest(A );
bv1=highest(B );
bv2=lowest(B );
cv1=highest(C );
cv2=lowest(C );
dv1=highest(D );
dv2=lowest(D );
ev1=highest(E );
ev2=lowest(E );
fv1=highest(F );
fv2=lowest(F );
gv1=highest(G );
gv2=lowest(G );
hv1=highest(H );
hv2=lowest(H );
iv1=highest(I );
iv2=lowest(I ); 
jv1=highest(J );
jv2=lowest(J );

}

long int highest(long int *m)
{
  
  int largest=m;                        
  for(int i=0;i<10;i++)
  {
  if(m[i+1]>largest)
  largest=m[i+1];
  }
  //Serial.print(m[i]);
  return largest;
}

long int lowest(long int *m)                                                   
{
  int smallest=m;       
  for(int i=0;i<10;i++)
  {
  if(m[i+1]<smallest)
  smallest=m[i+1];
  }
  //Serial.print(m[i+1]);
  return smallest;
}

void printletter()
{

Serial.println("[ A ] [ B ] [ C ] [ D ] [ E ] [ F ]");
Serial.println("[ G ] [ H ] [ I ] [ J ] [ K ] [ L ]");
Serial.println("[ M ] [ N ] [ O ] [ P ] [ Q ] [ R ]");
Serial.println("[ S ] [ T ] [ U ] [ V ] [ W ] [ X ]");
Serial.println("[ Y ] [ Z ]");
Serial.println();
Serial.println("THINK ABOUT THE LETTER YOU WANT THE SPELLER TO FIND....");
Serial.println();


}

char spell()
{ 
  delay(100);
  long int atten=brain.readAttention();
  long int medi=brain.readMeditation();
  long int delta= brain.readDelta();
  long int theta= brain.readTheta();
  long int lowalpha= brain.readLowAlpha();
  long int highalpha= brain.readHighAlpha();
  long int lowbeta= brain.readLowBeta();
  long int highbeta= brain.readHighBeta();
  long int lowgamma= brain.readLowGamma();
  long int midgamma= brain.readMidGamma();
 //debugging statements 
//  Serial.print(atten);
//  Serial.print(medi);
//  Serial.print(delta);
//  Serial.print(theta);
//  Serial.print(lowalpha);
//  Serial.print(highalpha);
//  Serial.print(lowbeta);
//  Serial.print(highbeta);
//  Serial.print(lowgamma);
//  Serial.print(midgamma);  
  if (atten<=a1 && atten>=a2 && medi<=b1 && medi<=b2 && delta<=c1 && delta>=c2 && theta<=d1 && theta>=d2 && lowalpha<=e1 && lowalpha>=e2 && highalpha<=f1 && highalpha>=f2 && lowbeta<=g1 && lowbeta>=g2 && highbeta<=h1 && highbeta>=h2 && lowgamma<=i1 && lowgamma>=i2 && midgamma<=j1 && midgamma>=j2) 
  return 'A';
  
   else if (atten<=a3 && atten>=a4 && medi<=b3 && medi<=b4 && delta<=c3 && delta>=c4 && theta<=d3 && theta>=d4 && lowalpha<=e3 && lowalpha>=e4 && highalpha<=f3 && highalpha>=f4 && lowbeta<=g3 && lowbeta>=g4 && highbeta<=h3 && highbeta>=h4 && lowgamma<=i3 && lowgamma>=i4 && midgamma<=j3 && midgamma>=j4) 
  return 'B';
  
     else if (atten<=a5 && atten>=a6 && medi<=b5 && medi<=b6 && delta<=c5 && delta>=c6 && theta<=d5 && theta>=d6 && lowalpha<=e5 && lowalpha>=e6 && highalpha<=f5 && highalpha>=f6 && lowbeta<=g5 && lowbeta>=g6 && highbeta<=h5 && highbeta>=h6 && lowgamma<=i5 && lowgamma>=i6 && midgamma<=j5 && midgamma>=j6) 
  return 'C';
  
     else if (atten<=a7 && atten>=a8 && medi<=b7 && medi<=b8 && delta<=c7 && delta>=c8 && theta<=d7 && theta>=d8 && lowalpha<=e7 && lowalpha>=e8 && highalpha<=f7 && highalpha>=f8 && lowbeta<=g7 && lowbeta>=g8 && highbeta<=h7 && highbeta>=h8 && lowgamma<=i7 && lowgamma>=i8 && midgamma<=j7 && midgamma>=j8) 
  return 'D';
  
     else if (atten<=a9 && atten>=a0 && medi<=b9 && medi<=b0 && delta<=c9 && delta>=c0 && theta<=d9 && theta>=d0 && lowalpha<=e9 && lowalpha>=e0 && highalpha<=f9 && highalpha>=f0 && lowbeta<=g9 && lowbeta>=g0 && highbeta<=h9 && highbeta>=h0 && lowgamma<=i9 && lowgamma>=i0 && midgamma<=j9 && midgamma>=j0) 
  return 'E';
  
     else if (atten<=aa1 && atten>=aa2 && medi<=ba1 && medi<=ba2 && delta<=ca1 && delta>=ca2 && theta<=da1 && theta>=da2 && lowalpha<=ea1 && lowalpha>=ea2 && highalpha<=fa1 && highalpha>=fa2 && lowbeta<=ga1 && lowbeta>=ga2 && highbeta<=ha1 && highbeta>=ha2 && lowgamma<=ia1 && lowgamma>=ia2 && midgamma<=ja1 && midgamma>=ja2) 
  return 'F';
  
     else if (atten<=ab1 && atten>=ab2 && medi<=bb1 && medi<=bb2 && delta<=cb1 && delta>=cb2 && theta<=db1 && theta>=db2 && lowalpha<=eb1 && lowalpha>=eb2 && highalpha<=fb1 && highalpha>=fb2 && lowbeta<=gb1 && lowbeta>=gb2 && highbeta<=hb1 && highbeta>=hb2 && lowgamma<=ib1 && lowgamma>=ib2 && midgamma<=jb1 && midgamma>=jb2) 
  return 'G';
  
     else if (atten<=ac1 && atten>=ac2 && medi<=bc1 && medi<=bc2 && delta<=cc1 && delta>=cc2 && theta<=dc1 && theta>=dc2 && lowalpha<=ec1 && lowalpha>=ec2 && highalpha<=fc1 && highalpha>=fc2 && lowbeta<=gc1 && lowbeta>=gc2 && highbeta<=hc1 && highbeta>=hc2 && lowgamma<=ic1 && lowgamma>=ic2 && midgamma<=jc1 && midgamma>=jc2) 
  return 'H';
  
     else if (atten<=ad1 && atten>=ad2 && medi<=bd1 && medi<=bd2 && delta<=cd1 && delta>=cd2 && theta<=dd1 && theta>=dd2 && lowalpha<=ed1 && lowalpha>=ed2 && highalpha<=fd1 && highalpha>=fd2 && lowbeta<=gd1 && lowbeta>=gd2 && highbeta<=hd1 && highbeta>=hd2 && lowgamma<=id1 && lowgamma>=id2 && midgamma<=jd1 && midgamma>=jd2) 
  return 'I';
  
     else if (atten<=ae1 && atten>=ae2 && medi<=be1 && medi<=be2 && delta<=ce1 && delta>=ce2 && theta<=de1 && theta>=de2 && lowalpha<=ee1 && lowalpha>=ee2 && highalpha<=fe1 && highalpha>=fe2 && lowbeta<=ge1 && lowbeta>=ge2 && highbeta<=he1 && highbeta>=he2 && lowgamma<=ie1 && lowgamma>=ie2 && midgamma<=je1 && midgamma>=je2) 
  return 'J';
  
     else if (atten<=af1 && atten>=af2 && medi<=bf1 && medi<=bf2 && delta<=cf1 && delta>=cf2 && theta<=df1 && theta>=df2 && lowalpha<=ef1 && lowalpha>=ef2 && highalpha<=ff1 && highalpha>=ff2 && lowbeta<=gf1 && lowbeta>=gf2 && highbeta<=hf1 && highbeta>=hf2 && lowgamma<=if1 && lowgamma>=if2 && midgamma<=jf1 && midgamma>=jf2) 
  return 'K';
  
     else if (atten<=ag1 && atten>=ag2 && medi<=bg1 && medi<=bg2 && delta<=cg1 && delta>=cg2 && theta<=dg1 && theta>=dg2 && lowalpha<=eg1 && lowalpha>=eg2 && highalpha<=fg1 && highalpha>=fg2 && lowbeta<=gg1 && lowbeta>=gg2 && highbeta<=hg1 && highbeta>=hg2 && lowgamma<=ig1 && lowgamma>=ig2 && midgamma<=jg1 && midgamma>=jg2) 
  return 'L';
  
     else if (atten<=ah1 && atten>=ah2 && medi<=bh1 && medi<=bh2 && delta<=ch1 && delta>=ch2 && theta<=dh1 && theta>=dh2 && lowalpha<=eh1 && lowalpha>=eh2 && highalpha<=fh1 && highalpha>=fh2 && lowbeta<=gh1 && lowbeta>=gh2 && highbeta<=hh1 && highbeta>=hh2 && lowgamma<=ih1 && lowgamma>=ih2 && midgamma<=jh1 && midgamma>=jh2) 
  return 'M';
  
     else if (atten<=ai1 && atten>=ai2 && medi<=bi1 && medi<=bi2 && delta<=ci1 && delta>=ci2 && theta<=di1 && theta>=di2 && lowalpha<=ei1 && lowalpha>=ei2 && highalpha<=fi1 && highalpha>=fi2 && lowbeta<=gi1 && lowbeta>=gi2 && highbeta<=hi1 && highbeta>=hi2 && lowgamma<=ii1 && lowgamma>=ii2 && midgamma<=ji1 && midgamma>=ji2) 
  return 'N';
  
     else if (atten<=ak1 && atten>=ak2 && medi<=bk1 && medi<=bk2 && delta<=ck1 && delta>=ck2 && theta<=dk1 && theta>=dk2 && lowalpha<=ek1 && lowalpha>=ek2 && highalpha<=fk1 && highalpha>=fk2 && lowbeta<=gk1 && lowbeta>=gk2 && highbeta<=hk1 && highbeta>=hk2 && lowgamma<=ik1 && lowgamma>=ik2 && midgamma<=jk1 && midgamma>=jk2) 
  return 'O';
  
     else if (atten<=al1 && atten>=al2 && medi<=bl1 && medi<=bl2 && delta<=cl1 && delta>=cl2 && theta<=dl1 && theta>=dl2 && lowalpha<=el1 && lowalpha>=el2 && highalpha<=fl1 && highalpha>=fl2 && lowbeta<=gl1 && lowbeta>=gl2 && highbeta<=hl1 && highbeta>=hl2 && lowgamma<=il1 && lowgamma>=il2 && midgamma<=jl1 && midgamma>=jl2) 
  return 'P';
  
     else if (atten<=am1 && atten>=am2 && medi<=bm1 && medi<=bm2 && delta<=cm1 && delta>=cm2 && theta<=dm1 && theta>=dm2 && lowalpha<=em1 && lowalpha>=em2 && highalpha<=fm1 && highalpha>=fm2 && lowbeta<=gm1 && lowbeta>=gm2 && highbeta<=hm1 && highbeta>=hm2 && lowgamma<=im1 && lowgamma>=im2 && midgamma<=jm1 && midgamma>=jm2) 
  return 'Q';
  
     else if (atten<=an1 && atten>=an2 && medi<=bn1 && medi<=bn2 && delta<=cn1 && delta>=cn2 && theta<=dn1 && theta>=dn2 && lowalpha<=en1 && lowalpha>=en2 && highalpha<=fn1 && highalpha>=fn2 && lowbeta<=gn1 && lowbeta>=gn2 && highbeta<=hn1 && highbeta>=hn2 && lowgamma<=in1 && lowgamma>=in2 && midgamma<=jn1 && midgamma>=jn2) 
  return 'R';
  
     else if (atten<=ao1 && atten>=ao2 && medi<=bo1 && medi<=bo2 && delta<=co1 && delta>=co2 && theta<=do1 && theta>=do2 && lowalpha<=eo1 && lowalpha>=eo2 && highalpha<=fo1 && highalpha>=fo2 && lowbeta<=go1 && lowbeta>=go2 && highbeta<=ho1 && highbeta>=ho2 && lowgamma<=io1 && lowgamma>=io2 && midgamma<=jo1 && midgamma>=jo2) 
  return 'S';
  
     else if (atten<=ap1 && atten>=ap2 && medi<=bp1 && medi<=bp2 && delta<=cp1 && delta>=cp2 && theta<=dp1 && theta>=dp2 && lowalpha<=ep1 && lowalpha>=ep2 && highalpha<=fp1 && highalpha>=fp2 && lowbeta<=gp1 && lowbeta>=gp2 && highbeta<=hp1 && highbeta>=hp2 && lowgamma<=ip1 && lowgamma>=ip2 && midgamma<=jp1 && midgamma>=jp2) 
  return 'T';
  
     else if (atten<=aq1 && atten>=aq2 && medi<=bq1 && medi<=bq2 && delta<=cq1 && delta>=cq2 && theta<=dq1 && theta>=dq2 && lowalpha<=eq1 && lowalpha>=eq2 && highalpha<=fq1 && highalpha>=fq2 && lowbeta<=gq1 && lowbeta>=gq2 && highbeta<=hq1 && highbeta>=hq2 && lowgamma<=iq1 && lowgamma>=iq2 && midgamma<=jq1 && midgamma>=jq2) 
  return 'U';
  
     else if (atten<=ar1 && atten>=ar2 && medi<=br1 && medi<=br2 && delta<=cr1 && delta>=cr2 && theta<=dr1 && theta>=dr2 && lowalpha<=er1 && lowalpha>=er2 && highalpha<=fr1 && highalpha>=fr2 && lowbeta<=gr1 && lowbeta>=gr2 && highbeta<=hr1 && highbeta>=hr2 && lowgamma<=ir1 && lowgamma>=ir2 && midgamma<=jr1 && midgamma>=jr2) 
  return 'V';
  
     else if (atten<=as1 && atten>=as2 && medi<=bs1 && medi<=bs2 && delta<=cs1 && delta>=cs2 && theta<=ds1 && theta>=ds2 && lowalpha<=es1 && lowalpha>=es2 && highalpha<=fs1 && highalpha>=fs2 && lowbeta<=gs1 && lowbeta>=gs2 && highbeta<=hs1 && highbeta>=hs2 && lowgamma<=is1 && lowgamma>=is2 && midgamma<=js1 && midgamma>=js2) 
  return 'W';
  
     else if (atten<=at1 && atten>=at2 && medi<=bt1 && medi<=bt2 && delta<=ct1 && delta>=ct2 && theta<=dt1 && theta>=dt2 && lowalpha<=et1 && lowalpha>=et2 && highalpha<=ft1 && highalpha>=ft2 && lowbeta<=gt1 && lowbeta>=gt2 && highbeta<=ht1 && highbeta>=ht2 && lowgamma<=it1 && lowgamma>=it2 && midgamma<=jt1 && midgamma>=jt2) 
  return 'X';
  
     else if (atten<=au1 && atten>=au2 && medi<=bu1 && medi<=bu2 && delta<=cu1 && delta>=cu2 && theta<=du1 && theta>=du2 && lowalpha<=eu1 && lowalpha>=eu2 && highalpha<=fu1 && highalpha>=fu2 && lowbeta<=gu1 && lowbeta>=gu2 && highbeta<=hu1 && highbeta>=hu2 && lowgamma<=iu1 && lowgamma>=iu2 && midgamma<=ju1 && midgamma>=ju2) 
  return 'Y';
  
     else if (atten<=av1 && atten>=av2 && medi<=bv1 && medi<=bv2 && delta<=cv1 && delta>=cv2 && theta<=dv1 && theta>=dv2 && lowalpha<=ev1 && lowalpha>=ev2 && highalpha<=fv1 && highalpha>=fv2 && lowbeta<=gv1 && lowbeta>=gv2 && highbeta<=hv1 && highbeta>=hv2 && lowgamma<=iv1 && lowgamma>=iv2 && midgamma<=jv1 && midgamma>=jv2) 
  return 'Z';
  
}
