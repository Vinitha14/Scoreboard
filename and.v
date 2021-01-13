module cmos_and(a,b,y);
input a,b;
output y;
wire w,w1;
supply0 gnd;
supply1 vdd;

nmos(w,gnd,b);
nmos(w1,w,a);
pmos(w1,vdd,b);
pmos(w1,vdd,a);
nmos(y,gnd,w1);
pmos(y,vdd,w1);

endmodule
