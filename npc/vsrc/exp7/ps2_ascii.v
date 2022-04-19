// `timescale 1ns/1ns

module ps2_ascii (
    input   clk,ps2_clk,ps2_data,
    output reg [7:0] num,
    output reg [7:0] ascii,
    output reg [7:0] sum
);
// parameter[1:0] S0 = 0, S1 = 1, S2 = 2 // S0:第一次接收，S1:第二次，S3:
// reg clrn;
wire [7:0] data;
wire ready,overflow;
// wire kbd_clk, kbd_data;
reg nextdata_n;
integer ifpress;
/* verilator lint_off UNOPTFLAT */
integer over;

ps2_keyboard p1(
    .clk(clk),
    .clrn(1'b1),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .data(data),
    .ready(ready),
    .nextdata_n(nextdata_n),
    .overflow(overflow)
);

ps22ascii p2(
    .ps2(num),
    .ascii(ascii)
);

initial begin
    nextdata_n = 0;
    ifpress = 0;
    over = 0;
end

always_latch @( ready ) begin
    // #20 nextdata_n =1'b0; #20 nextdata_n =1'b1;//read data
    nextdata_n = 1'b1;
    if (over == 1) begin
        over = 0;
        num = 8'h00;
        ifpress = 0;
    end
    else begin
        if (data == 8'hf0)
            over = 1;
        else begin
            if (ifpress == 0) begin
                num = data;
                ifpress = 1;
            end
            else begin
                if (data != num) begin
                    num = data;
                    sum = 8'hf1;
                end
            end
        end
    end
end

// always @(  )

endmodule
