module decoder24 (x,en,y);
    input   [1:0] x;
    input   en;
    output  [3:0] y;

    assign y[0] = (~x[0]) & en & (~x[1]);
    assign y[1] = (x[0]) & en & (~x[1]);
    assign y[2] = (~x[0]) & en & (x[1]);
    assign y[3] = (x[0]) & en & (x[1]);

endmodule
