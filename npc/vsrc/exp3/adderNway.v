module adderNway #(n = 8) (
    input   [n-1:0] x,
    input   [n-1:0] y,
    output  [n-1:0] s,
    output  c,
    output  o,
    output  z
);
    assign {c,s} = x + y;
    assign o = ~(x[n-1] ^ y[n-1]) & (s[n-1] ^ x[n-1]);
    assign z = ~(| s);
endmodule

module adder4way (
    input   [3:0] x,
    input   [3:0] y,
    output  [3:0] s,
    output  c,
    output  o,
    output  z
);
    adderNway #(4) a1(x,y,s,c,o,z);
endmodule