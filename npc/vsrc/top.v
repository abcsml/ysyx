module top (
    input clk,
    input rst,
    input [15:0] sw,
    input ps2_clk,
    input ps2_data,
    output [15:0] ledr,
    output VGA_CLK,
    output VGA_HSYNC,
    output VGA_VSYNC,
    output VGA_BLANK_N,
    output [7:0] VGA_R,
    output [7:0] VGA_G,
    output [7:0] VGA_B,
    output [7:0] seg0,
    output [7:0] seg1,
    output [7:0] seg2,
    output [7:0] seg3,
    output [7:0] seg4,
    output [7:0] seg5,
    output [7:0] seg6,
    output [7:0] seg7
);

// light led1(
//     .clk(clk),
//     .rst(rst),
//     .ledr(ledr)
// );

// mux4way2 m1(
//     .a(sw[9:2]),
//     .s(sw[1:0]),
//     .y(ledr[1:0])
// );
// endmodule

// encoder83p e1(
//     .x(sw[7:0]),
//     .en(sw[8]),
//     .y(ledr[2:0]),
//     .ind(ledr[4])
// );

// bcd7seg b1(
//     .b({1'b0,ledr[2:0]}),
//     .h(seg0[7:1])
// );

// ALU4way alu1(
//     .a(sw[7:4]),
//     .b(sw[3:0]),
//     .sel(sw[10:8]),
//     .out(ledr[3:0]),
//     .cf(ledr[4]),
//     .of(ledr[5]),
//     .zf(ledr[6])
// );

// LFSR8 l1(
//     .clk(sw[8]),
//     .load(sw[9]),
//     .in(sw[7:0]),
//     .out(ledr[7:0])
// );

// FSM f1(
//     .w(sw[1]),
//     .reset(sw[0]),
//     .clk(sw[15]),
//     .z(ledr[0]),
//     .state(ledr[7:4])
// );

wire [7:0] num;
wire [7:0] ascii;
wire [7:0] sum;
bcd7seg b1(
    .b(num[3:0]),
    .h(seg0[7:1])
);
bcd7seg b2(
    .b(num[7:4]),
    .h(seg1[7:1])
);
bcd7seg b3(
    .b(ascii[3:0]),
    .h(seg2[7:1])
);
bcd7seg b4(
    .b(ascii[7:4]),
    .h(seg3[7:1])
);
bcd7seg b5(
    .b(sum[3:0]),
    .h(seg4[7:1])
);
bcd7seg b6(
    .b(sum[7:4]),
    .h(seg5[7:1])
);
ps2_ascii p2(
    .clk(clk),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .num(num),
    .ascii(ascii),
    .sum(sum)
);

endmodule
