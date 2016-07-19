set terminal aqua font "CMU-Sans-Serif,22"
set termoption dashed

set style line 10 lt 2 lc rgb "gray" lw 1
set grid ytics  ls 10
set border 3
set tics out nomirror

set key left top box at 0.9, 2.9e8

set xrange [0.5:5.75]
set yrange [0:3e8]
set xtic rotate by -45
set xtics scale 0
set ytics ("0" 0, "" 5e7, "10^8" 1e8, "" 1.5e8, "2*10^8" 2.0e8, "" 2.5e8, "3*10^8" 3e8, "" 3.5e8)
set size ratio .35
set ylabel "cycles" offset 12

set style line 1 lt 1 lw 1 lc rgb "#44A2FF"
set style line 2 lt 1 lw 1 lc rgb "#FFE0B6"

plot 'mcertikos_cswitch.dat' using ($0-.02):2:3:4:(.15):xtic(1) with boxerrorbars\
     ls 1 fs solid border lc rgbcolor "black"\
      title "ring 3",\
'' using ($0+0.22):5:6:7:(.15) with boxerrorbars\
      ls 2 fs solid border lc rgbcolor "black"\
      title "ring 0"
