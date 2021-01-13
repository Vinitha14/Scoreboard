module cmos_or(a,b,y);
input a,b;
output y;
wire w,w1;
supply0 gnd;
supply1 vdd;

nmos(w1,gnd,b);
nmos(w1,gnd,a);

pmos(w,vdd,b);
pmos(w1,w,a);

nmos(y,gnd,w1);
pmos(y,vdd,w1);


endmodule
