module adder_tb;

integer i;
integer j;
integer inputaluop;
integer k;
integer of;
integer z;
integer c;

// wire    [3:0] i;
// wire    [3:0] j;
// wire    [3:0] k;
// wire    c;
// wire    of;
// wire    z;
// wire    [3:0] inputa;
// wire    [3:0] inputb;
// wire    [3:0] inputaluop;

adderNway a1(
    .x(inputa),
    .y(inputb),
    .s(outputs),
    .c(outputc),
    .o(outputo),
    .z(outputz)
);

initial begin
for(i=-8;i<=7;i=i+1) //建议i和j可以是5位以上的带符号数
    for (j=-8;j<=7;j=j+1)
        begin
        inputa=i;
        inputb=j;  //设置两个输入
        inputaluop=4'b0000; //ALU的操作码
        k = 4'b0000 ;    //此处自行计算正确的输出，填入*处
        of= 1'b0 ;    //可分不同情况手工填写
        z = 1'b0 ;
        c = 1'b0 ;
        #20 check(k[3:0],of,c,z);
        end
end

task check;  //测试任务
input [3:0] results;  //ALU的结果预期正确输出
input resultof, resultc, resultz;  //ALU的预期溢出，进位，零位
begin
    if(outputs!=results)  //比较预期结果和测试单元输出的outputs
    begin               //出错时显示
        $display("Error:x=%h,y=%h,ctrl=%b,s should be %h, get %h", inputa, inputb, inputaluop, results, outputs);
    end
    //自行添加溢出，进位和零位的比较
end
endtask

endmodule
