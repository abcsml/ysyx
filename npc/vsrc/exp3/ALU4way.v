module ALU4way (
    input   [3:0] a,
    input   [3:0] b,
    input   [2:0] sel,
    output reg [3:0] out,
    output  cf,
    output  of,
    output  zf
);

wire [3:0] add;
wire [3:0] sub;

adderNway #(4) a1(a,b,add,cf,of,zf);
adderNway #(4) a2(a,{b[3],(~b[2:0])+3'b001},sub,cf,of,zf);

    always @(*) begin
        case (sel)
            3'b000: out = add;
            3'b001: out = sub;
            3'b010: out = ~a;
            3'b011: out = a&b;
            3'b100: out = a|b;
            3'b101: out = a^b;
            3'b110: out = a<b ? 4'b1 : 4'b0;
            3'b111: out = a==b ? 4'b1 : 4'b0;
            default: out = add;
        endcase
    end
endmodule