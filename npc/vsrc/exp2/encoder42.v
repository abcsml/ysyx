module encoder42 (x,en,y);
    input   [3:0] x;
    input   en;
    output  [1:0] y;

    assign y[0] = (~x[3]) & (~x[2]) & (x[1]) & (~x[0]) & en;
    assign y[0] = (x[3]) & (~x[2]) & (~x[1]) & (~x[0]) & en;
    assign y[1] = (~x[3]) & (x[2]) & (~x[1]) & (~x[0]) & en;
    assign y[1] = (x[3]) & (~x[2]) & (~x[1]) & (~x[0]) & en;

endmodule
