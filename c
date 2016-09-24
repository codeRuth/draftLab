gcc $1
if $? -ne 0 ; then
	echo "Check Errors"
else 
	./a.out
