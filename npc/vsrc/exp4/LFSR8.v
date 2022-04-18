module LFSR8 (
    input   clk,
    input   load,
    input   reg [7:0] in,
    output  reg [7:0] out
);

// initial begin
//     out = in;
// end
always @(posedge clk)
    if (load == 1)
        out <= in;
    else
        out <= {out[4] ^ out[3] ^ out[2] ^ out[0],out[7:1]};
endmodule
