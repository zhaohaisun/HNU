module sm(
    input clk,sm_en,
    output reg sm);

initial sm=1'b0;

always @(negedge clk) //下降沿
begin
    if(sm_en) sm<=~sm; //使能信号为1 取反
    else sm<=sm; //使能信号为0 保持
end
endmodule
