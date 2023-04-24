

#include <stdio.h>

float time1[100];
float dt;
float zeta[100];
float dz;
float d2z;

int main (){
    zeta[0]=0.9;
    dz = 0;
    time1[0]= 0;
    dt = 0.1;
    printf ("zeta   time    d2z    dz\n");
    for (int i=1;i<100;i++)
    {
        zeta[i] = zeta[i-1]+ dz*dt;
        time1[i] = i*dt;
        d2z = (1/(zeta[i]*zeta[i]*zeta[i])-1/(zeta[i]*zeta[i]));
        dz += d2z*dt;  
        printf ("%f   %f   %f  %f\n",zeta[i],time1[i],d2z,dz);
    }
    TCanvas *c1 = new TCanvas ("c1","c1");
    c1->DrawFrame(0,0,3.0,10.0);
    int n = 100;
    TGraph* gr = new TGraph(n,time1,zeta);
    gr->SetMarkerStyle(25);
    gr->Draw("Ac");
    return 0;
}

void hw1 (){
    main ();
}
    
