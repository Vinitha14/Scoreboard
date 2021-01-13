module top;
reg [15:0]a;
reg [15:0]b;
wire [16:0]s;
Add cla_0(a,b,s);
initial
begin
a=8;
b=2;
end
initial
begin
$monitor("a=%d, b=%d, sum=%d",a,b,s);
$dumpfile("cla_adder1.vcd");
$dumpvars(0,top);
end
endmodule