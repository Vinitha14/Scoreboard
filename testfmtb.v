module top;
reg [15:0]a;
reg [15:0]b;
wire [32:0]s;
WalMul mi(a,b,s);
initial
begin
a=2;
b=4;
end
initial
begin
$monitor("a=%d, b=%d, sum=%d",a,b,s);
$dumpfile("wallace_mul.vcd");
$dumpvars(0,top);
end
endmodule