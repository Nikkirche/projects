: > report2.log
i=1
N=21

while(( $i < $N ))
do
    echo $(time ./kostyl.sh $i) | sudo tee -a report2.log
    let "i+=1"
    let "j=0"
done