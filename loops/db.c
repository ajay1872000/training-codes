int dec_to_bin(int n){
	int r,i=1,s=0;
	while(n!=0){
		r=n%2;
		s=s+(r*i);
		i=i*10;
		n=n/2;}
	return s;}

