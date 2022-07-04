ifconfig -a | grep ether | grep -v media | tr -d '\t' | sed 's/ether //'
