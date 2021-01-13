`include "RDM.v"
module KGP (input A1,A0,output S,B1,B0);

assign B1=A1&A0;
assign B0=A1|A0;
assign S=A1^A0;
endmodule

module Add (A,B,S);
input [15:0] A;
input [15:0] B;

output [16:0] S;

wire [16:0] K1;
wire [16:0] K0;

wire [16:0] Q1;
wire [16:0] Q0;

wire [16:0] out;
wire [16:0] Y;

KGP kgp0(A[0],B[0],out[0],K1[1],K0[1]);
KGP kgp1(A[1],B[1],out[1],K1[2],K0[2]);
KGP kgp2(A[2],B[2],out[2],K1[3],K0[3]);
KGP kgp3(A[3],B[3],out[3],K1[4],K0[4]);
KGP kgp4(A[4],B[4],out[4],K1[5],K0[5]);
KGP kgp5(A[5],B[5],out[5],K1[6],K0[6]);
KGP kgp6(A[6],B[6],out[6],K1[7],K0[7]);
KGP kgp7(A[7],B[7],out[7],K1[8],K0[8]);
KGP kgp8(A[8],B[8],out[8],K1[9],K0[9]);
KGP kgp9(A[9],B[9],out[9],K1[10],K0[10]);
KGP kgp10(A[10],B[10],out[10],K1[11],K0[11]);
KGP kgp11(A[11],B[11],out[11],K1[12],K0[12]);
KGP kgp12(A[12],B[12],out[12],K1[13],K0[13]);
KGP kgp13(A[13],B[13],out[13],K1[14],K0[14]);
KGP kgp14(A[14],B[14],out[14],K1[15],K0[15]);
KGP kgp15(A[15],B[15],out[15],K1[16],K0[16]);

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

assign S[16]=1'b0 ^ 1'b0 ^ (Q1[16] &Q0[16]);

endmodule
