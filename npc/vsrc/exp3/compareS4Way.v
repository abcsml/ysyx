module compareS4Way (
    input   [3:0] a,
    input   [3:0] b,
    output  out
);
reg t;

always @(*) begin
    if (a[3] ^ b[3])
        t = a[3] == 1;
    else if (a[3] == 1)
        t = a>b;
    else
        t = a<b;
end
assign out = t;
endmodule