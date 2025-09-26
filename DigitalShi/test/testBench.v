`include "test.v"
`timescale 1ns/1ps//first one time unit, second one resolution


module testBench;
    reg A_tb;
    reg B_tb;
    reg Ci_tb;
    wire Co_tb;
    wire So_tb;




    sumadorOneBit sob(A_tb, B_tb,Ci_tb,Co_tb,So_tb);

/*     
    sumdaorOneBit  suma(
        .A(A_tb),
        .B(B_tb),
        .Cin(Ci_tb),
        .Co(Co_tb),
        .So(So_tb));
 */
    initial begin 
        A_tb = 1'b0;
        B_tb = 1'b0;
        Ci_tb = 1'b0;

        #10; //simulates 10 units of time
        A_tb = 1'b1;
        B_tb = 1'b0;
        Ci_tb = 1'b0;

        #10; //simulates 10 units of time
        A_tb = 1'b0;
        B_tb = 1'b1;
        Ci_tb = 1'b0;

        #10; //simulates 10 units of time
        A_tb = 1'b1;
        B_tb = 1'b1;
        Ci_tb = 1'b0;

        #10; //simulates 10 units of time
        A_tb = 1'b0;
        B_tb = 1'b0;
        Ci_tb = 1'b1;

        #10; //simulates 10 units of time                        

        A_tb = 1'b1;
        B_tb = 1'b0;
        Ci_tb = 1'b1;

        #10; //simulates 10 units of time


        A_tb = 1'b0;
        B_tb = 1'b1;
        Ci_tb = 1'b1;

        #10; //simulates 10 units of time

        A_tb = 1'b1;
        B_tb = 1'b1;
        Ci_tb = 1'b1;

    end



    initial begin
        $dumpfile("tb_simulation.vcd");
        //$dumpvars(-1, testBench);//jerarquía, no tiene sentido caja de más arriba? okok
        $dumpvars(0, testBench);//jerarquía, no tiene sentido caja de más arriba? okok
        # 3000 $finish;
    end
endmodule