set terminal aqua font "CMU-Sans-Serif,22"
set termoption dashed

set style line 10 lt 2 lc rgb "gray" lw 1
set grid y2tics  ls 10
set border 9

set style line 1 lt 1 lw 1 lc rgb "#44A2FF"
set style line 2 lt 1 lw 1 lc rgb "#FFE0B6"

unset ytics
set xtics scale 0
unset x2tics
set ytics scale 0
set ytics format ""
set y2tics rotate # by 45

set xtic rotate by -270 ( "pipe" 4.5, "bcopy (libc)" 7.5 )

set key box left

set y2tics out ("0" 0, "2" 2, "4" 4, "6" 6, "GB/s" 8)


set yrange [0:8]
set xrange [ -23:9.5 ]
set boxwidth .3
set style fill solid border -1

# set label "Deleting 10,000 files" at graph .05, .5 rotate 

plot "-" using 1:2 title "Ubuntu on CTOS" with boxes ls 1 fs solid border lc rgbcolor "black", \
     "-"  using 1:2 title "Ubuntu on bare metal" with boxes  ls 2 fs solid border lc rgbcolor "black"

4 2.82
7 5.92
e
5 2.45
8 7.99
e
 


