int bin_to_dec(int n){
	int r,i=1,s=0;
	while(n!=0){
		r=n%10;
		if(r>1)
			return -1;
		s=s+(r*i);
		i=i*2;
		n=n/10;}
	return s;}

