#include <stdio.h>
#include <windows.h>
float BPM;
float sb, m, sm, c; //semibreve //minima //seminima //colcheia
/* C3 */
const float C = 130.8128; //DÓ
    const float Cs_Db = 138.5913; //DÓ# //REb
const float D = 146.8324; // RÉ
    const float Ds_Eb = 155.5635; //RÉ# //MIb
const float E = 164.8138; //MI
const float F = 174.6141; // FÁ
    const float Fs_Gb = 184.9972; //FÁ# //SOLb
const float G = 195.9977; //SOL
    const float Gs_Ab = 207.6523; // SOL# // LÁb
const float A = 220; //LÁ
    const float As_Bb = 233.0819; // LA# // SIb
const float B = 246.9417; // SI

int main(){
    BPM;//inserir BPM  ex: em 120 bpm a semi-breve tem 2000 milissegundos
    sb =  BPM/60;
    m = sb/2;
    sm = m/2;
    c = sm/2;

    return 0;
}

/*
    Beep(,);
    Beep(,*);
    Beep(,/);
    pause();

    void repeticao1(){
    }
*/

