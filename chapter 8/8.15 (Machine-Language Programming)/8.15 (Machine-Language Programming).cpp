// 8.15 (Machine-Language Programming)

/*
a)
location    number  instruction
00          +1090   (read A)
            +2090   (load A to accumulator)
            +4120   (branch to end of program if A is negetive)
            +3091   (add SUM to accumulator)
            +2191   (store new SUM to 91)
            +4000   (repeat loop)
20          +1191   (display SUM)
21          +4300   (Halt)
90          +0000   (variable A)
91          +0000   (variable SUM)


b)
location    number  instruction
00          +4102   branch to location 02 if the counter is negetive
01          +4020   branch to location 20 (this happens if the counter has reached to zero and is not negative anymore)
02          +1094   input number
03          +2092   load sum
04          +3094   add input number
05          +2192   store new sum
06          +4000   branch to start point to repeat the loop

20          +2092   load sum
21          +3290   divide 7 into sum
22          +2193   store calculated average
23          +1193   display average
24          +4300   halt    

90          +0007   total numbers
91          -0007   upward counter
92          +0000   sum
93          +0000   average
94          +0000   input number
95          +0001   +1
96          -0001   -1


c)
location    number  instruction
00          +1090   input how many numbers are there
01          +1091   set first entered number as largest
02          +2090   load count to accumulator
03          +3193   subtract 1 from count
04          +2190   store (count - 1) in (count)
05          +2090   load count
06          +4230   branch to end if count is zero
07          +1092   enter new number
08          +2091   load largest to accumulator
09          +3192   subtract last input number from largest
10          +4120   if accumulator is negative (new number should be largest) branch to location 20
15          +4003   else branch to location 03 (to check next number)

20          +2092   load last input number to accumulator
21          +2191   store last input number to largest
22          +4003   branch to location 03 (to check next number)

30          +1191   print largest
31          +4300   halt

90          +0000   count
91          +0000   largest
92          +0000   input
93          +0001   +1
94          -0001   -1


*/