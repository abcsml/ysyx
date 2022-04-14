module adderNway #(n = 8) (
    input   [n-1:0] x,
    input   [n-1:0] y,
    input   sel,    // add or sub
    output  [n-1:0] s,
    output  c,
    output  o,
    output  z
);
    wire [n-1:0] t;
    assign t = {n{sel}}^y;
    assign {c,s} = x + t + {{(n-1){1'b0}}, sel};
    assign o = (~(x[n-1] ^ t[n-1])) & (s[n-1] ^ x[n-1]);
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
    adderNway #(4) a1(x,y,1'b0,s,c,o,z);
endmodule