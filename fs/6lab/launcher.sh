i=1

while (( $i < $1 ))
do
    ./algo.sh $i &
    wait
    let "i+=1"
done