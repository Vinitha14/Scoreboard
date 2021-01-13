module andtb();
reg a1,b1;
wire out;
initial begin
$dumpfile("andtest.vcd");
$dumpvars(0,andtb);
$display("in1,in2,out");
$monitor("%b,%b,%b",a1,b1,out);
#20 a1=0;b1=1;
#20 $finish;
end
cmos_and n(.a(a1),.b(b1),.y(out));
endmodule