module FSM (
    input   w,
    input   reset,
    input   clk,
    output  z,
    output  [3:0] state
);
reg [3:0] s;

always @(posedge clk) begin
    if (reset) begin
        assign z = 0;
        s = 4'b0;
    end
    case (s)
        4'd0: assign state = w ? 4'd5 : 4'd1;
        4'd1: assign state = w ? 4'd5 : 4'd2;
        4'd2: assign state = w ? 4'd5 : 4'd3;
        4'd3: assign state = w ? 4'd5 : 4'd4;
        4'd4: assign state = w ? 4'd5 : 4'd5;
        4'd5: assign state = w ? 4'd6 : 4'd1;
        4'd6: assign state = w ? 4'd7 : 4'd1;
        4'd7: assign state = w ? 4'd8 : 4'd1;
        4'd8: assign state = w ? 4'd8 : 4'd1;
        // default: 
    endcase
end
case (state)
    4'd0: assign z = 0;
    4'd1: assign z = 0;
    4'd2: assign z = 0;
    4'd3: assign z = 0;
    4'd4: assign z = 1;
    4'd5: assign z = 0;
    4'd6: assign z = 0;
    4'd7: assign z = 0;
    4'd8: assign z = 1;
endcase
endmodule