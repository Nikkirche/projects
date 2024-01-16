i=1
res=0
N=500000
while (( $i < $N ))
do
    let "res+=(((-1)**i)*($1**(2*i+1)))/(2*i+1)"
    let "i+=1"
done