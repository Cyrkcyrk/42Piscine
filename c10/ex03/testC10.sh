arg='-C'
tool='hexdump'

./$tool $arg $* 1> outputU.txt 2> outputUerror.txt
./$tool $arg $* 1> outputUall.txt 2>&1
$tool $arg $* 1> outputO.txt 2> outputOerror.txt
$tool $arg $* 1> outputOall.txt 2>&1
echo -------------
echo Diff sortie N
echo -------------
diff outputO.txt outputU.txt
echo -------------
echo Diff sortie E
echo -------------
diff outputOerror.txt outputUerror.txt
echo -------------
echo Diff sortie A
echo -------------
diff outputOall.txt outputUall.txt
#rm output*.txt