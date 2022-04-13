module encoder42 (x,en,y);
    input   [3:0] x;
    input   en;
    output  [1:0] y;

    wire a = (~x[3]) & (~x[2]) & (x[1]) & (~x[0]) & en;
    wire b = (x[3]) & (~x[2]) & (~x[1]) & (~x[0]) & en;
    wire c = (~x[3]) & (x[2]) & (~x[1]) & (~x[0]) & en;
    wire d = (x[3]) & (~x[2]) & (~x[1]) & (~x[0]) & en;
    assign y[0] = a|b;
    assign y[1] = c|d;

endmodule
