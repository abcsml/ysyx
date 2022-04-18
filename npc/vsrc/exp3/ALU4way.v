module ALU4way (
    input   [3:0] a,
    input   [3:0] b,
    input   [2:0] sel,
    output reg [3:0] out,
    output reg cf,
    output reg of,
    output reg zf
);

wire [3:0] add;
wire [3:0] sub;
wire addcf;
wire addof;
wire addzf;
wire subcf;
wire subof;
wire subzf;
reg  cout;

adderNway #(4) a1(a,b,1'b0,add,addcf,addof,addzf);
adderNway #(4) a2(a,b,1'b1,sub,subcf,subof,subzf);
compareS4Way c1(a,b,cout);

always @(*) begin
    case (sel)
        3'b000: begin
            out = add;
            cf = addcf;
            of = addof;
            zf = addzf;
        end
        3'b001: begin
            out = sub;
            cf = subcf;
            of = subof;
            zf = subzf;
        end
        3'b010: out = ~a;
        3'b011: out = a&b;
        3'b100: out = a|b;
        3'b101: out = a^b;
        3'b110: out = {3'b0,cout};
        3'b111: out = a==b ? 4'b1 : 4'b0;
        default: out = add;
    endcase
    zf = ~(| out);
end
endmodule