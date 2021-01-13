module fulladd(ua,va,wa,s,c);

input [31:0] ua;
input [31:0] va;
input [31:0] wa;

output [31:0] s;
output [31:0] c;

genvar k;
//CSA
 assign s[31]=1'b0;
 assign c[0]=1'b0;
generate
for(k=0;k<31;k=k+1)
begin :fulladd
//assign sum and carry
assign s[k]= ua[k] ^ va[k] ^ wa[k];
assign c[k+1] = (ua[k]&va[k]) | (va[k]&wa[k]) | (ua[k]&wa[k]);

end
endgenerate
endmodule

