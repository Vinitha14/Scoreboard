`include "RDMW.v"
module KPG (input A1,A0,output S,B1,B0);

assign B1=A1&A0;
assign B0=A1|A0;
assign S=A1^A0;
endmodule

module Add (A,B,S);
input [31:0] A;
input [31:0] B;

output [32:0] S;

wire [32:0] K1;
wire [32:0] K0;

wire [32:0] Q1;
wire [32:0] Q0;

wire [32:0] out;
wire [32:0] Y;

KPG kgp0(A[0],B[0],out[0],K1[1],K0[1]);
KPG kgp1(A[1],B[1],out[1],K1[2],K0[2]);
KPG kgp2(A[2],B[2],out[2],K1[3],K0[3]);
KPG kgp3(A[3],B[3],out[3],K1[4],K0[4]);
KPG kgp4(A[4],B[4],out[4],K1[5],K0[5]);
KPG kgp5(A[5],B[5],out[5],K1[6],K0[6]);
KPG kgp6(A[6],B[6],out[6],K1[7],K0[7]);
KPG kgp7(A[7],B[7],out[7],K1[8],K0[8]);
KPG kgp8(A[8],B[8],out[8],K1[9],K0[9]);
KPG kgp9(A[9],B[9],out[9],K1[10],K0[10]);
KPG kgp10(A[10],B[10],out[10],K1[11],K0[11]);
KPG kgp11(A[11],B[11],out[11],K1[12],K0[12]);
KPG kgp12(A[12],B[12],out[12],K1[13],K0[13]);
KPG kgp13(A[13],B[13],out[13],K1[14],K0[14]);
KPG kgp14(A[14],B[14],out[14],K1[15],K0[15]);
KPG kgp15(A[15],B[15],out[15],K1[16],K0[16]);
KPG kgp16(A[16],B[16],out[16],K1[17],K0[17]);
KPG kgp17(A[17],B[17],out[17],K1[18],K0[18]);
KPG kgp19(A[18],B[18],out[18],K1[19],K0[19]);
KPG kgp20(A[19],B[19],out[19],K1[20],K0[20]);
KPG kgp21(A[20],B[20],out[20],K1[21],K0[21]);
KPG kgp22(A[21],B[21],out[21],K1[22],K0[22]);
KPG kgp23(A[22],B[22],out[22],K1[23],K0[23]);
KPG kgp24(A[23],B[23],out[23],K1[24],K0[24]);
KPG kgp25(A[24],B[24],out[24],K1[25],K0[25]);
KPG kgp26(A[25],B[25],out[25],K1[26],K0[26]);
KPG kgp27(A[26],B[26],out[26],K1[27],K0[27]);
KPG kgp28(A[27],B[27],out[27],K1[28],K0[28]);
KPG kgp29(A[28],B[28],out[28],K1[29],K0[29]);
KPG kgp30(A[29],B[29],out[29],K1[30],K0[30]);
KPG kgp31(A[30],B[30],out[30],K1[31],K0[31]);
KPG kgp32(A[31],B[31],out[31],K1[32],K0[32]);

assign K1[0]=0;
assign K0[0]=0;

Rec_D rdm0 (K1,K0,Q1,Q0);

assign Y[0]=Q0[0]&Q1[0];
assign S[0]=out[0]^Y[0];
assign Y[1]=Q0[1]&Q1[1];
assign S[1]=out[1]^Y[1];
assign Y[2]=Q0[2]&Q1[2];
assign S[2]=out[2]^Y[2];
assign Y[3]=Q0[3]&Q1[3];
assign S[3]=out[3]^Y[3];
assign Y[4]=Q0[4]&Q1[4];
assign S[4]=out[4]^Y[4];
assign Y[5]=Q0[5]&Q1[5];
assign S[5]=out[5]^Y[5];
assign Y[6]=Q0[6]&Q1[6];
assign S[6]=out[6]^Y[6];
assign Y[7]=Q0[7]&Q1[7];
assign S[7]=out[7]^Y[7];
assign Y[8]=Q0[8]&Q1[8];
assign S[8]=out[8]^Y[8];
assign Y[9]=Q0[9]&Q1[9];
assign S[9]=out[9]^Y[9];
assign Y[10]=Q0[10]&Q1[10];
assign S[10]=out[10]^Y[10];
assign Y[11]=Q0[11]&Q1[11];
assign S[11]=out[11]^Y[11];
assign Y[12]=Q0[12]&Q1[12];
assign S[12]=out[12]^Y[12];
assign Y[13]=Q0[13]&Q1[13];
assign S[13]=out[13]^Y[13];
assign Y[14]=Q0[14]&Q1[14];
assign S[14]=out[14]^Y[14];
assign Y[15]=Q0[15]&Q1[15];
assign S[15]=out[15]^Y[15];
assign Y[16]=Q0[16]&Q1[16];
assign S[16]=out[16]^Y[16];
assign Y[17]=Q0[17]&Q1[17];
assign S[17]=out[17]^Y[17];
assign Y[18]=Q0[18]&Q1[18];
assign S[18]=out[18]^Y[18];
assign Y[19]=Q0[19]&Q1[19];
assign S[19]=out[19]^Y[19];
assign Y[20]=Q0[20]&Q1[20];
assign S[20]=out[20]^Y[20];
assign Y[21]=Q0[21]&Q1[21];
assign S[21]=out[21]^Y[21];
assign Y[22]=Q0[22]&Q1[22];
assign S[22]=out[22]^Y[22];
assign Y[23]=Q0[23]&Q1[23];
assign S[23]=out[23]^Y[23];
assign Y[24]=Q0[24]&Q1[24];
assign S[24]=out[24]^Y[24];
assign Y[25]=Q0[25]&Q1[25];
assign S[25]=out[25]^Y[25];
assign Y[26]=Q0[26]&Q1[26];
assign S[26]=out[26]^Y[26];
assign Y[27]=Q0[27]&Q1[27];
assign S[27]=out[27]^Y[27];
assign Y[28]=Q0[28]&Q1[28];
assign S[28]=out[28]^Y[28];
assign Y[29]=Q0[29]&Q1[29];
assign S[29]=out[29]^Y[29];
assign Y[30]=Q0[30]&Q1[30];
assign S[30]=out[30]^Y[30];
assign Y[31]=Q0[31]&Q1[31];
assign S[31]=out[31]^Y[31];

assign S[32]=1'b0 ^ 1'b0 ^ (Q1[32] &Q0[32]);

endmodule
