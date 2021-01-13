`include "FullAdder.v"
`include "KPGW.v"

module Mult (m,n,p);
input n;
input [15:0] m;
output [15:0] p;

genvar b;
generate 
 for(b=0;b<=15;b=b+1)
  assign p[b] = n & m[b];
endgenerate

endmodule

/*module WalMul (M,N,P);

input [15:0] M;
input [15:0] N;
output [32:0] P;
wire [15:0] Z [31:0];

genvar j,i;
generate
for(j=0;j<=15;j=j+1)
for(i=0;i<=15;i=i+1)
begin : partial
 Mult t (M[i],N[j],[j:0]z[j+i]); 
end
endgenerate
*/

module WalMul (M,N,P);

input [15:0] M;
input [15:0] N;
output [32:0] P;

wire [31:0] Z [15:0];
wire [15:0] Y [15:0];

wire [31:0] a[9:0];
wire [31:0] s[5:0];
wire [31:0] d[3:0];
wire [31:0] f[3:0];
wire [31:0] j[1:0];
wire [31:0] l[1:0];

genvar g,h;
generate
for(g=0;g<=15;g=g+1)
begin:partial
Mult t (M,N[g],Y[g]);
end
endgenerate

for(h=0;h<=15;h=h+1)
begin
assign Z[h][h+15:h]=Y[h][15:0];
end
assign Z[0][31:16]=0;
for(h=1;h<=15;h=h+1)
begin
assign Z[h][31:16+h]=0;
assign Z[h][h-1:0]=0;
end


fulladd fulladd1(Z[0],Z[1],Z[2],a[0],a[1]);
fulladd fulladd4(Z[3],Z[4],Z[5],a[2],a[3]);
fulladd fulladd3(Z[6],Z[7],Z[8],a[4],a[5]);
fulladd fulladd2(Z[9],Z[10],Z[11],a[6],a[7]);
fulladd fulladd5(Z[12],Z[13],Z[14],a[8],a[9]);

fulladd fulladd8(a[0],a[1],a[2],s[0],s[1]);
fulladd fulladd7(a[3],a[4],a[5],s[2],s[3]);
fulladd fulladd6(a[6],a[7],a[8],s[4],s[5]);

fulladd fulladd9(s[0],s[1],s[2],d[0],d[1]);
fulladd fulladd10(s[3],s[4],s[5],d[2],d[3]);

fulladd fulladd11(d[0],d[1],d[2],f[0],f[1]);
fulladd fulladd12(d[3],a[9],Z[15],f[2],f[3]);

fulladd fulladd13(f[0],f[1],f[2],j[0],j[1]);

fulladd fulladd14(j[0],j[1],f[3],l[0],l[1]);

Add q(l[0],l[1],P);

endmodule
