module encoder42 (x,en,y);
    input   [3:0] x;
    input   en;
    output  [1:0] y;

    wire a = (~x[3]) & (~x[2]) & (x[1]) & (~x[0]) & en;
    wire b = (x[3]) & (~x[2]) & (~x[1]) & (~x[0]) & en;
    wire c = (~x[3]) & (x[2]) & (~x[1]) & (~x[0]) & en;
    wire d = (x[3]) & (~x[2]) & (~x[1]) & (~x[0]) & en;
    assign y[0] = a|b;
    assign y[1] = c|d;

endmodule

module encoder42p(x,en,y);
  input  [3:0] x;
  input  en;
  output reg [1:0]y;
  integer i;
  always @(x or en) begin
    if (en) begin
      y = 0;
      for( i = 0; i <= 3; i = i+1)
          if(x[i] == 1)  y = i[1:0];
    end
    else  y = 0;
  end
endmodule
