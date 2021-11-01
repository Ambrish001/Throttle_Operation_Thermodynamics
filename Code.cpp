#include <iostream>
#include<cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
  int i,j,k;
  double f, p, S;
  double p1, t1 ,xi, Tsat01[2], Tsat14[2], Tsat16[2];
  double Hsat01[2],Hsat14[2],Hsat16[2];
  double Temp01[25], Temp14[25], Temp16[25];
  double Ssat01[2],Ssat14[2],Ssat16[2];
  double Cp01[25], Cp14[25], Cp16[25];
  double H14[25], H16[25], H01[25];
  double S14[25], S16[25], S01[25];

  Tsat01[0]=272.64; Tsat14[0]=368.760; Tsat16[0]=375.611;
  Tsat01[1]= 272.64; Tsat14[1]=368.760; Tsat16[1]=375.611;
  Hsat01[0]=16770.1; Hsat14[0]=31450.9; Hsat16[0]=32665.2;
  Hsat01[1]= 39202.7; Hsat14[1]=46891.0; Hsat16[1]=47338.3;
  Ssat01[0]=218.485; Ssat14[0]=263.868; Ssat16[0]=267.065;
  Ssat01[1]= 300.764; Ssat14[1]=305.738; Ssat16[1]=306.130;

  ifstream read("cp01.txt");

  int x=23;
  for(i=1; i<=23; i++){
    read>>Cp01[i];
  }
  for(i=1; i<=23; i++){
    read>>Cp14[i];
  }
  for(i=1; i<=23; i++){
    read>>Cp16[i];
  }
  for(i=1; i<=23; i++){
    read>>Temp01[i];
  }
  for(i=1; i<=23; i++){
    read>>Temp14[i];
  }
  for(i=1; i<=23; i++){
    read>>Temp16[i];
  }

  read.close();

double I, h, sum;

// enthalpy storage for p = 0.1
H01[9] = Hsat01[0];
H01[10] = Hsat01[1];

for(k=1; k<9; k++){
  sum=0;
  for(i=k; i<9; i++){
        h=Temp01[i+1] - Temp01[i];
        sum=sum + (Cp01[i] + Cp01[i+1])*h/2;

      }
      H01[k] = H01[9] - sum;
  }

  for(k=11;k<=23;k++){
    sum=0;
    for(i=10; i<k; i++){
          h=Temp01[i+1] - Temp01[i];
          sum=sum + (Cp01[i] + Cp01[i+1])*h/2;
        }
        H01[k] = H01[10] + sum;
    }


// entropy storage for p = 0.1
    S01[9] = Ssat01[0];
    S01[10] = Ssat01[1];

    for(k=1; k<9; k++){
      sum=0;
      for(i=k; i<9; i++){
            h=Temp01[i+1] - Temp01[i];
            sum=sum + ((Cp01[i])/Temp01[i] + Cp01[i+1]/Temp01[i+1])*h/(2);

          }
          S01[k] = S01[9] - sum;
      }

      for(k=11;k<=23;k++){
        sum=0;
        for(i=10; i<k; i++){
              h=Temp01[i+1] - Temp01[i];
              sum=sum + (Cp01[i] + Cp01[i+1])*h/(2*Temp01[i]);
            }
            S01[k] = S01[10] + sum;
        }


  // enthalpy storage for p = 1.4
  H14[18] = Hsat14[0];
  H14[19] = Hsat14[1];

  for(k=1; k<18; k++){
    sum=0;
    for(i=k; i<18; i++){
          h=Temp14[i+1] - Temp14[i];
          sum=sum + (Cp14[i] + Cp14[i+1])*h/2;

        }
        H14[k] = H14[18] - sum;
    }

    for(k=20;k<=23;k++){
      sum=0;
      for(i=19; i<k; i++){
            h=Temp14[i+1] - Temp14[i];
            sum=sum + (Cp14[i] + Cp14[i+1])*h/2;
          }
          H14[k] = H14[19] + sum;
      }



// Entropy storage for p = 1.4
      S14[18] = Ssat14[0];
      S14[19] = Ssat14[1];

      for(k=1; k<18; k++){
        sum=0;
        for(i=k; i<18; i++){
              h=Temp14[i+1] - Temp14[i];
              sum=sum + ((Cp14[i])/Temp14[i] + Cp14[i+1]/Temp14[i+1])*h/(2);

            }
            S14[k] = S14[18] - sum;
        }

        for(k=20;k<=23;k++){
          sum=0;
          for(i=19; i<k; i++){
                h=Temp14[i+1] - Temp14[i];
                sum=sum + (Cp14[i] + Cp14[i+1])*h/(2*Temp14[i]);
              }
              S14[k] = S14[19] + sum;
          }



  // enthalpy storage for p = 1.6
      H16[19] = Hsat16[0];
      H16[20] = Hsat16[1];

      for(k=1; k<19; k++){
        sum=0;
        for(i=k; i<19; i++){
              h=Temp16[i+1] - Temp16[i];
              sum=sum + (Cp16[i] + Cp16[i+1])*h/2;

            }
            H16[k] = H16[19] - sum;
        }

        for(k=21;k<=23;k++){
          sum=0;
          for(i=20; i<k; i++){
                h=Temp16[i+1] - Temp16[i];
                sum=sum + (Cp16[i] + Cp16[i+1])*h/2;
              }
              H16[k] = H16[20] + sum;
          }



  // entropy storage for p = 1.6
          S16[19] = Ssat16[0];
          S16[20] = Ssat16[1];

          for(k=1; k<19; k++){
            sum=0;
            for(i=k; i<19; i++){
                  h=Temp16[i+1] - Temp16[i];
                  sum=sum + (Cp16[i] + Cp16[i+1])*h/(2*Temp16[i]);

                }
                S16[k] = S16[19] - sum;
            }

            for(k=21;k<=23;k++){
              sum=0;
              for(i=20; i<k; i++){
                    h=Temp16[i+1] - Temp16[i];
                    sum=sum + ((Cp16[i])/Temp16[i] + Cp16[i+1]/Temp16[i+1])*h/(2);
                  }
                  S16[k] = S16[20] + sum;
              }
              k=1;


              //Main Program
while (k==1)
{
  cout<<"Enter inlet pressure: ";
  cin>>p1;
  cout<<"\nEnter inlet temperature: ";
  cin>>t1;

  double H1, H2;
  if(p1==1.4){
    if(t1==Tsat14[1]){
      cout<<"\nEnter xi: ";
      cin>>xi;
      cout<<endl;
      H1= (1-xi)*Hsat14[0] + xi*Hsat14[1];
      cout<<"H1: "<<H1<<endl;
              }
    if(t1 < Tsat14[0]){

            f=0;
            for(i=1; i<=18; i++)
            {
              p=1;

              for(j=1;j<=18;j++){
                if(i!=j){
                  p = p*(t1 - Temp14[j])/(Temp14[i] - Temp14[j]);
                }
                else {
                  p = p*1;
                }

              }
              f=f+p*H14[i];
            }
            cout<<"H1:"<< f<< endl;
            H1=f;
    }
    if(t1 > Tsat14[1]){

            f=0;
            for(i=19; i<=23; i++)
            {
              p=1;

              for(j=19;j<=23;j++){
                if(i!=j){
                  p = p*(t1 - Temp14[j])/(Temp14[i] - Temp14[j]);
                }
                else {
                  p = p*1;
                }

              }
              f=f+p*H14[i];
            }
          cout<<"H1:"<< f<< endl;
            H1=f;
    }
    if(Hsat01[0]<H1  && H1<Hsat01[1]){
      cout<<"T2:"<<Tsat01[0]<<endl;
        cout<<"Quality: "<< (H1 - Hsat01[0])/(Hsat01[1] - Hsat01[0])<<endl;
    }

    if(H1 < Hsat01[0]) {  f=0;
        for(i=1; i<=9; i++)
        {
          p=1;

          for(j=1;j<=9;j++){
            if(i!=j){
              p = p*(H1 - H01[j])/(H01[i] - H01[j]);
            }
            else {
              p = p*1;
            }

          }
          f=f+p*Temp01[i];
        }
        cout<<"T2: "<< f<< endl;
    }

    if(H1 > Hsat01[1]) {  f=0;
        for(i=10; i<=23; i++)
        {
          p=1;

          for(j=10;j<=23;j++){
            if(i!=j){
              p = p*(H1 - H01[j])/(H01[i] - H01[j]);
            }
            else {
              p = p*1;
            }

          }
          f=f+p*Temp01[i];
        }

      cout<<"T2: "<< f<< endl;


    }
    if(H1<Hsat01[0]){
      cout<<" Outlet is super cooled liquid"<<endl;}
    else if(Hsat01[0]<H1 && H1<Hsat01[1]){
        cout<<" Liquid + Vapour"<<endl;}
    else if(Hsat01[1]<H1){
            cout<<"SUper heated vapour"<<endl;}




  }
  if(p1==1.6){
    if(t1==Tsat16[1]){
      cout<<"\nEnter xi: ";
      cin>>xi;
      cout<<endl;
      H1= (1-xi)*Hsat16[0] + xi*Hsat16[1];
      cout<<"H1: "<<H1<<endl;
              }
    if(t1 < Tsat16[0]){

            f=0;
            for(i=1; i<=19; i++)
            {
              p=1;

              for(j=1;j<=19;j++){
                if(i!=j){
                  p = p*(t1 - Temp16[j])/(Temp16[i] - Temp16[j]);
                }
                else {
                  p = p*1;
                }

              }
              f=f+p*H16[i];
            }
            cout<<"H1:"<< f<< endl;
            H1=f;
    }
    if(t1 > Tsat16[1]){

            f=0;
            for(i=20; i<=23; i++)
            {
              p=1;

              for(j=20;j<=23;j++){
                if(i!=j){
                  p = p*(t1 - Temp16[j])/(Temp16[i] - Temp16[j]);
                }
                else {
                  p = p*1;
                }

              }
              f=f+p*H16[i];
            }
          cout<<"H1:"<< f<< endl;
            H1=f;
    }
    if(Hsat01[0]<H1  && H1<Hsat01[1]){
      cout<<"T2:"<<Tsat01[0]<<endl;
        cout<<"Quality: "<< (H1 - Hsat01[0])/(Hsat01[1] - Hsat01[0])<<endl;
    }

    if(H1 < Hsat01[0]) {  f=0;
        for(i=1; i<=9; i++)
        {
          p=1;

          for(j=1;j<=9;j++){
            if(i!=j){
              p = p*(H1 - H01[j])/(H01[i] - H01[j]);
            }
            else {
              p = p*1;
            }

          }
          f=f+p*Temp01[i];
        }
        cout<<"T2: "<< f<< endl;
    }

    if(H1 > Hsat01[1]) {  f=0;
        for(i=10; i<=23; i++)
        {
          p=1;

          for(j=10;j<=23;j++){
            if(i!=j){
              p = p*(H1 - H01[j])/(H01[i] - H01[j]);
            }
            else {
              p = p*1;
            }

          }
          f=f+p*Temp01[i];
        }

      cout<<"T2: "<< f<< endl;


    }
    if(H1<Hsat01[0]){
      cout<<" Outlet is super cooled liquid"<<endl;}
    else if(Hsat01[0]<H1 && H1<Hsat01[1]){
        cout<<" Liquid + Vapour"<<endl;}
    else if(Hsat01[1]<H1){
            cout<<"SUper heated vapour"<<endl;}


  }
cout<<endl;
  if(p1==1.4){
    if(t1==Tsat14[1]){
      S= (1-xi)*Ssat14[0] + xi*Ssat14[1];
      cout<<"S: "<<S<<endl;
              }
    if(t1 < Tsat14[0]){

            f=0;
            for(i=1; i<=18; i++)
            {
              p=1;

              for(j=1;j<=18;j++){
                if(i!=j){
                  p = p*(t1 - Temp14[j])/(Temp14[i] - Temp14[j]);
                }
                else {
                  p = p*1;
                }

              }
              f=f+p*S14[i];
            }
            cout<<"S: "<< f<< endl;
            S=f;
    }
    if(t1 > Tsat14[1]){

            f=0;
            for(i=19; i<=23; i++)
            {
              p=1;

              for(j=19;j<=23;j++){
                if(i!=j){
                  p = p*(t1 - Temp14[j])/(Temp14[i] - Temp14[j]);
                }
                else {
                  p = p*1;
                }

              }
              f=f+p*S14[i];
            }
            cout<<"S: "<< f<< endl;
            S=f;
    }
    if(Ssat01[0]<S  && S<Ssat01[1]){
          cout<<"Quality: "<< (S - Ssat01[0])/(Ssat01[1] - Ssat01[0])<<endl;
        xi=(S - Ssat01[0])/(Ssat01[1] - Ssat01[0]);
        cout<< "H2: "<<(1-xi)*Hsat01[0] + xi*Hsat01[1]<<endl;
        H2=(1-xi)*Hsat01[0] + xi*Hsat01[1];
    }

    if(S < Ssat01[0]) {  f=0;
        for(i=1; i<=9; i++)
        {
          p=1;

          for(j=1;j<=9;j++){
            if(i!=j){
              p = p*(S - S01[j])/(S01[i] - S01[j]);
            }
            else {
              p = p*1;
            }

          }
          f=f+p*H01[i];
        }
        cout<<"H2: "<< f<< endl;
        H2=f;
    }

    if(S > Ssat01[1]) {  f=0;
        for(i=10; i<=23; i++)
        {
          p=1;

          for(j=10;j<=23;j++){
            if(i!=j){
              p = p*(S - S01[j])/(S01[i] - S01[j]);
            }
            else {
              p = p*1;
            }

          }
          f=f+p*H01[i];
        }

        cout<<"H2: "<< f<< endl;
        H2=f;


    }

    if(S<Ssat01[0]){
      cout<<" Outlet is super cooled liquid"<<endl;}
    else if(Ssat01[0]<S && S<Ssat01[1]){
        cout<<" Liquid + Vapour"<<endl;}
    else if(Ssat01[1]<S){
            cout<<"SUper heated vapour"<<endl;}




  }
  if(p1==1.6){
    if(t1==Tsat16[1]){
      S= (1-xi)*Ssat16[0] + xi*Ssat16[1];
      cout<<"S: "<<S<<endl;
              }
    if(t1 < Tsat16[0]){

            f=0;
            for(i=1; i<=19; i++)
            {
              p=1;

              for(j=1;j<=19;j++){
                if(i!=j){
                  p = p*(t1 - Temp16[j])/(Temp16[i] - Temp16[j]);
                }
                else {
                  p = p*1;
                }

              }
              f=f+p*S16[i];
            }
            cout<<"S: "<< f<< endl;
            S=f;
    }
    if(t1 > Tsat16[1]){

            f=0;
            for(i=20; i<=23; i++)
            {
              p=1;

              for(j=20;j<=23;j++){
                if(i!=j){
                  p = p*(t1 - Temp16[j])/(Temp16[i] - Temp16[j]);
                }
                else {
                  p = p*1;
                }

              }
              f=f+p*S16[i];
            }
            cout<<"S: "<< f<< endl;
            S=f;
    }
    if(Ssat01[0]<S  && S<Ssat01[1]){
          cout<<"Quality: "<< (S - Ssat01[0])/(Ssat01[1] - Ssat01[0])<<endl;
        xi=(S - Ssat01[0])/(Ssat01[1] - Ssat01[0]);
        cout<< "H2: "<<(1-xi)*Hsat01[0] + xi*Hsat01[1]<<endl;
        H2=(1-xi)*Hsat01[0] + xi*Hsat01[1];
    }

    if(S < Ssat01[0]) {  f=0;
        for(i=1; i<=9; i++)
        {
          p=1;

          for(j=1;j<=9;j++){
            if(i!=j){
              p = p*(S - S01[j])/(S01[i] - S01[j]);
            }
            else {
              p = p*1;
            }

          }
          f=f+p*H01[i];
        }
        cout<<"H2: "<< f<< endl;
        H2=f;
    }

    if(S > Ssat01[1]) {  f=0;
        for(i=10; i<=23; i++)
        {
          p=1;

          for(j=10;j<=23;j++){
            if(i!=j){
              p = p*(S - S01[j])/(S01[i] - S01[j]);
            }
            else {
              p = p*1;
            }

          }
          f=f+p*H01[i];
        }

        cout<<"H2: "<< f<< endl;
        H2=f;

  
    }

    if(S<Ssat01[0]){
      cout<<" Outlet is super cooled liquid"<<endl;}
    else if(Ssat01[0]<S && S<Ssat01[1]){
        cout<<" Liquid + Vapour"<<endl;}
    else if(Ssat01[1]<S){
            cout<<"SUper heated vapour"<<endl;}




  }
  cout<<" Max Work: "<<H2 - H1<<endl;
  cout<<"---------------------------------------------------------------------"<<endl;}




  return 0;
}
