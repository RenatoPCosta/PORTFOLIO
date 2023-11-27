#include <stdio.h>
#include <windows.h>
float sb = 2000; //semibreve
float m;         //minima
float sm;        //seminima
float c;         //colcheia
/* C3 */
float C = 132; //DÓ
    float C_S = 137.544; //DÓ#
    float D_B = 142.56; //REb
float D = 148.5; // RÉ
    float D_S = 154.704; //RÉ#
    float E_B = 158.4; //MIb
float E = 165; //MI
float F = 175.956; // FÁ
    float F_S = 183.348; //FÁ#
    float G_B = 190.08; //SOLb
float G = 198; //SOL
    float G_S = 206.316; // SOL#
    float A_B = 211.200; // LÁb
float A = 220.044; //LÁ
    float A_S = 229.284; // LA#
    float B_B = 237.6; // SIb
float B = 247.5; // SI

void repeticao1(){
    system("TITLE NONA SINFONIA - BEETHOVEN");

}

int main()
{
    m = sb/2;
    sm = m/2;
    c = sm/2;

    Beep(B,c);
    Beep(A,c);
    Beep(B,sm);
    Beep(E,m);
    Sleep(c/4);
    Beep(C*2,c);
    Beep(B,c);
    Beep(C*2,sm);
    Beep(B,sm);
    Beep(A,m);




//**********************************************







/*
    Sleep();
    Beep(,);
    Beep(,);
    Beep(,);
    Beep(,);
*/
    return 0;
}
