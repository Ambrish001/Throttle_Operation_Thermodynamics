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
