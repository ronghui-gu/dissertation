set terminal aqua font "CMU-Sans-Serif,22"
set termoption dashed

set style line 10 lt 2 lc rgb "gray" lw 1
set grid ytics  ls 10
set border 3
set tics out nomirror

set key right top box

set xrange [0.5:4.35]
set yrange [10:]
set xtic rotate by -45
set xtic scale 0
set ytic scale 1.2
set ytics ("" 10, "100" 100, "" 1000, "10^4" 10000, "" 100000, "10^6" 1000000, "" 1e7, "10^8" 1e8, "" 1e9)
set ylabel "cycles" offset 10
set logscale y
set xtics 10000
set size ratio .35

set style line 1 lt 1 lw 1 lc rgb "#44A2FF"
set style line 2 lt 1 lw 1 lc rgb "#FFE0B6"

plot 'mcertikos_pid.dat' using ($0-.02):2:2:2:(.10):xtic(1) with boxerrorbars\
     ls 1 fs solid border lc rgbcolor "black"\
      title "ring 3",\
'' using ($0+0.14):5:5:5:(.10) with boxerrorbars\
      ls 2 fs solid border lc rgbcolor "black"\
      title "ring 0"
