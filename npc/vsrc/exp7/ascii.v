module ps22ascii (
    input   [7:0] ps2,
    output reg [7:0] ascii
);

reg [7:0] i;
reg [7:0] data;
ps2_ROM p1(
    .R(1'b0),
    .addr(i),
    .data_out(data)
);

always_latch begin
    for (i=0;i<36;i=i+1) begin
        if (data == ps2) begin
            if (i < 8'd10)
                ascii = i + 8'd48;
            else
                ascii = i + 8'd87;
        end
    end
end

endmodule