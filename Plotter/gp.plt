set term qt 1 noraise

set grid

set xrange[-3:3]
set yrange[-3:3]
set zrange[-3:3]

set border lc rgb 'white'
set key tc rgb 'white'

set linetype 1 lc rgb 'white'
set linetype 2 lc rgb 'red'

splot "d.dat" using 1:2:3 w l lt 1,"d.dat" using 4:5:6 w l lt 2

pause 0.1
reread
