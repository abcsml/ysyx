module encoder42 (x,en,y);
    input   [3:0] x;
    input   en;
    output  [1:0] y;

    assign a = (~x[3]) & (~x[2]) & (x[1]) & (~x[0]) & en;
    assign b = (x[3]) & (~x[2]) & (~x[1]) & (~x[0]) & en;
    assign c = (~x[3]) & (x[2]) & (~x[1]) & (~x[0]) & en;
    assign d = (x[3]) & (~x[2]) & (~x[1]) & (~x[0]) & en;
    assign y[0] = a|b;
    assign y[1] = c|d;

endmodule
